/*
 * @Author: Artur 
 * @Date: 2018-04-01 23:48:01 
 * @Last Modified by: Artur
 * @Last Modified time: 2018-04-02 00:40:17
 */

#include <chrono>
#include <thread>
#include <cstring>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>
#include "AWC.hpp"
#include "connection_client_side.hpp"
#include "connection_server_side.hpp"

using namespace boost::asio;

AWC::AWC() : s_interface(exchange_data),
             c_interface(incoming_data, outgoing_data)
{
}

void AWC::start_listen(boost::asio::yield_context yield)
{
  ip::tcp::socket socket(io);
  ip::tcp::endpoint ep(ip::tcp::v4(), 4777);
  ip::tcp::acceptor acc(io, ep);
  try
  {
    for (;;)
    {
      std::shared_ptr<connection_server_side> new_connection = connection_server_side::start(ep, io, outgoing_data, exchange_data, "client");
      acc.async_accept(new_connection->sock(), yield);
      new_connection->start();
    }
  }
  catch (const std::exception &ex)
  {
    std::cerr << "What?" << ex.what() << std::endl;
  }
}

void AWC::runServer()
{
  boost::asio::spawn(io, [this](boost::asio::yield_context yield) { this->start_listen(yield); });
  io.run();
}
void AWC::runClient(const char *destination_ip)
{
  io_context io;
  ip::tcp::endpoint ep(ip::address::from_string(destination_ip), 4777);
  std::shared_ptr<connection_client_side> new_connection = connection_client_side::start(ep, io, outgoing_data, incoming_data);
  io.run();
}

void AWC::start(char const *argv[])
{

  const char *mode = argv[1];

  if(!std::strcmp(mode,"server")) 
  {
    auto my_name = argv[2];
    s_interface.setName(my_name);
    std::thread server_interface_thread(boost::bind(&server_interface::start, &s_interface));
    this->runServer();
    server_interface_thread.join();
  }
  else if(!std::strcmp(mode,"client")) 
  {
    auto my_name = argv[3];
    c_interface.setName(my_name);
    std::thread client_interface_thread(boost::bind(&client_interface::start, &c_interface));
    this->runClient(argv[2]);
    client_interface_thread.join();
  }
}
