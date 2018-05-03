/*
 * @Author: Artur
 * @Date: 2018-03-26 00:44:26
 * @Last modified by:   miszo97
 * @Last modified time: March 27, 2018 2:59 PM
 */

#include "client_interface.hpp"
#include <iostream>
#include "safeQueue.hpp"
#include "safeVector.hpp"
#include <thread>
#include <chrono>
#include <ncurses.h>
#include <boost/log/trivial.hpp>

#undef timeout(delay)

void client_interface::start()
{
  int rows, cols; //of terminal
  initscr();
  refresh();

  getmaxyx(stdscr, rows, cols); //getting terminal sizes
  double ratio = 0.75;          //ratio of section sizes

  messages_section.createWindow(rows * ratio, cols, 0, 0);
  write_section.createWindow(rows * (1 - ratio), cols, rows * ratio, 0);
  curs_set(0);

  std::thread t1(&client_interface::getInput, this);
  while (1)
  {
    display();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  t1.join();
  endwin();
}

client_interface::client_interface(safeVector<std::string> &_incoming_data, safeQueue<std::string> &_outgoing_data) : incoming_data(_incoming_data),
                                                                                                                      outgoing_data(_outgoing_data),
                                                                                                                      displayed_messagess_so_far(0)
{}

void client_interface::getInput()
{
  char data_to_send[512];
  while (1)
  {
    
    //get input from write section
    WINDOW *write_sec = write_section.getWindow();
    mvwgetstr(write_sec, 1, 2, data_to_send);

    //prepare message to sent
    std::string message(std::string(my_name)+": "+std::string(data_to_send));

    #ifdef LOGS
        BOOST_LOG_TRIVIAL(trace) << "CI|getInput: " << message;
    #endif

    //put message
    outgoing_data.push(message);
    incoming_data.push_back(message);

    //clear and redraw section
    wclear(write_sec);
    box(write_sec,1,1);

  }
}



void client_interface::display()
{
 //Don't borrow if there is no any message.
  if (displayed_messagess_so_far == 0)
    if (!incoming_data.size())
      return;

  WINDOW *msg_sec_win = messages_section.getWindow();

  std::vector<std::string>::iterator it;

  if (displayed_messagess_so_far >= messages_section.max_displayed)
    it = std::prev(incoming_data.end(), messages_section.max_displayed); //start iterate from -max_displayed preciding end.
  else
    it = incoming_data.begin();

  displayed_messagess_so_far = 0; //reset counter
  int y_offset = 1;

  for (; it != incoming_data.end(); ++it)
  {
    mvwprintw(msg_sec_win,y_offset, 1, "%s\n", it->data());
    ++displayed_messagess_so_far;
    y_offset++;
  }

  //draw, clear, redraw msg section
  wrefresh(msg_sec_win);
  wclear(msg_sec_win);
  box(msg_sec_win,1,1);
}
