/**
 * @Author: Artur <miszo97>
 * @Date:   March 21, 2018 8:21 AM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: connection.cpp
 * @Last modified by:   miszo97
 * @Last modified time: March 21, 2018 10:16 PM
 */

#include "connection.hpp"

connection::connection(io_context& _io) : started(true), io(_io), socket(_io)
{

}

void connection::start(ip::tcp::endpoint ep) {

  auto ptr_to_this = shared_from_this();
  auto on_connect = [ptr_to_this](const boost::system::error_code& ec)
  { std::cout << (!ec?  "Connected" : "Not connected") << '\n';};

  socket.async_connect(ep, on_connect);



}
std::shared_ptr<connection>
connection::start(ip::tcp::endpoint ep, io_context& _io) {
  auto _new = std::make_shared<connection>(_io);
  _new->start(ep);
  return _new;

}

void connection::stop() {}
void connection::do_write() {}
void connection::do_read() {}
void connection::on_connect(const boost::system::error_code& ec) {}
void connection::on_read(const boost::system::error_code& ec) {}
void connection::on_write(const boost::system::error_code& ec) {}
