/*
 * @Author: Artur 
 * @Date: 2018-03-26 00:44:26 
 * @Last Modified by: Artur
 * @Last Modified time: 2018-03-28 01:58:02
 */

#include "server_interface.hpp"
#include <iostream>
#include "safeQueue.hpp"
#include "safeVector.hpp"
#include <assert.h>
#include <thread>
#include <chrono>
#include <ncurses.h>

void server_interface::start()
{
  int rows, cols;
  initscr();
  refresh();
  getmaxyx(stdscr, rows, cols); //terminal size
  double ratio = 0.75;          //ratio of section sizes

  //creating messages and write sections
  messages_section.createWindow(rows * ratio, cols, 0, 0);
  write_section.createWindow(rows * (1 - ratio), cols, rows * ratio, 0);

  std::thread t1(&server_interface::getInput, this);
  while (1)
  {
    display();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  t1.join();
  endwin();
}

server_interface::server_interface(safeVector<std::string> &_exchange_data) : exchange_data(_exchange_data),
                                                                              messages_section(),
                                                                              write_section(),
                                                                              displayed_messagess_so_far(0)
{
}

void server_interface::getInput()
{

  char data_to_send[512];
  while (1)
  {
    WINDOW *write_sec = write_section.getWindow();
    mvwgetstr(write_sec, 1, 1, data_to_send);
    exchange_data.push_back(data_to_send);
    wclear(write_sec);
    box(write_sec,1,1);
  }
}
void server_interface::display()
{
  //Don't borrow if there is no any message.
  if (displayed_messagess_so_far == 0)
    if (!exchange_data.size())
      return;

  WINDOW *msg_sec_ptr = messages_section.getWindow();

  std::vector<std::string>::iterator it;

  if (displayed_messagess_so_far >= messages_section.max_displayed)
    it = std::prev(exchange_data.end(), messages_section.max_displayed); //start from -max_displayed preciding end.
  else
    it = exchange_data.begin();

  displayed_messagess_so_far = 0; //reset counter
  int y_offset = 1;

  for (; it != exchange_data.end(); ++it)
  {
    mvwprintw(msg_sec_ptr,y_offset, 1, "%s\n", it->data());
    ++displayed_messagess_so_far;
    y_offset++;
  }

  wrefresh(msg_sec_ptr);
  wclear(msg_sec_ptr);
  box(msg_sec_ptr,1,1);


}
