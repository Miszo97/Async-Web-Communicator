/**
 * @Author: Artur <miszo97>
 * @Date:   March 21, 2018 8:21 AM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: connection_client_side_client_side.cpp
 * @Last modified by:   miszo97
 * @Last modified time: March 24, 2018 1:51 AM
 */

#include "safeQueue.hpp"
#include "safeVector.hpp"
#include "connection_client_side.hpp"

connection_client_side::connection_client_side(io_context& _io, safeQueue<std::string>& _outgoing_data, safeVector<std::string>& _incoming_data) :
started(true),
io(_io),
socket(_io),
incoming_data(_incoming_data),
outgoing_data(_outgoing_data)
{
  outgoing_data.push("Hi I'am your client!");
outgoing_data.push("Hi, please sleep with me!");
outgoing_data.push("Hi, please sleep with me my prince!");
  outgoing_data.push("Hi I'am your client my prince!");
}


void connection_client_side::start(ip::tcp::endpoint ep) {


  auto ptr_to_this = shared_from_this();

  auto on_connect = [ptr_to_this, this](const boost::system::error_code &ec) {
    if (!ec) {
      std::cout << "Connected!" << '\n';
      wait_for_write();
      do_read();
    } else
      std::cout << "Not connected!" << '\n';
  };

  socket.async_connect(ep, on_connect);

}
void connection_client_side::wait_for_write(){

  if(outgoing_data.size() == 0){
    //std::cerr << "outgoing_data.size() == 0" << '\n';
    io.post([this](){this->wait_for_write();});
  }
  else
      do_write();

}
std::shared_ptr<connection_client_side>
connection_client_side::start(ip::tcp::endpoint ep, io_context& _io, safeQueue<std::string>& outgoing_data, safeVector<std::string>& incoming_data) {
  auto _new = std::make_shared<connection_client_side>(_io, outgoing_data, incoming_data);
  _new->start(ep);
  return _new;
}
ip::tcp::socket& connection_client_side::sock(){
  return socket;
}

void connection_client_side::stop() {}
void connection_client_side::do_write() {

    std::cerr << "do_write() execution" << '\n';
    auto on_write = [this](const boost::system::error_code& ec, size_t bytes)
    {
      std::cerr << "on_write execution, bytes: " <<bytes<< '\n';
      assert(!ec);
      if(!ec)
      wait_for_write();
    };

    auto front = outgoing_data.pop(); 
    std::strcpy(write, front.data());
    async_write(socket, buffer(write, max_size), on_write);

}
void connection_client_side::do_read() {

  std::cerr << "do_read() execution" << '\n';
  auto ptr_to_this = shared_from_this();

  auto on_read =
  [ptr_to_this, this]
  (const boost::system::error_code& ec, size_t bytes)
  {
    std::cerr << "on_read execution" << '\n';
    std::cerr << "Error code is "<<ec.message() << '\n';

    assert(!ec);
     if(!ec || ec != boost::asio::error::eof)
     incoming_data.push_back(std::string(read));
     do_read();
  };

  async_read(socket, buffer(read, max_size), on_read);

}
