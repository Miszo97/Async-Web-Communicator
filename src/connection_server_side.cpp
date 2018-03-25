/**
 * @Author: Artur <miszo97>
 * @Date:   March 21, 2018 8:21 AM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: connection_server_side.cpp
 * @Last modified by:   miszo97
 * @Last modified time: March 24, 2018 2:17 AM
 */

#include "connection_server_side.hpp"
#include "safeQueue.hpp"
#include "safeVector.hpp"
#define _cerr_on

connection_server_side::connection_server_side(
    io_context &_io, safeQueue<std::string> &_outgoing_data,
    safeVector<std::string> &_exchange_data, std::string _peer_name)
    : started(true), io(_io), socket(_io), exchange_data(_exchange_data),
      outgoing_data(_outgoing_data), peer_name(_peer_name) 

      {}

void connection_server_side::start() {

      #ifdef _cerr_on
      std::cerr<<"connection_server_side::start"<<"\n";
      #endif

      wait_for_write();
      do_read();
  
}
void connection_server_side::wait_for_write(){

      #ifdef _cerr_on
      std::cerr<<"cconnection_server_side::wait_for_write()"<<"\n";
      #endif
std::this_thread::sleep_for(std::chrono::seconds(1));
  if(exchange_data.size() <= written_messages){
    //std::cerr << "outgoing_data.size() == 0" << '\n';
    io.post([this](){this->wait_for_write();});
  }
  else
      do_write();

}
std::shared_ptr<connection_server_side>
connection_server_side::start(ip::tcp::endpoint ep, io_context& _io, safeQueue<std::string>& outgoing_data, safeVector<std::string>& exchange_data, std::string peer_name) {
  auto _new = std::make_shared<connection_server_side>(_io, outgoing_data, exchange_data, peer_name);
  return _new;

}
ip::tcp::socket& connection_server_side::sock(){
  
  return socket;
}

void connection_server_side::stop() {}
void connection_server_side::do_write() {
  
  std::this_thread::sleep_for(std::chrono::seconds(1));

    #ifdef _cerr_on
    std::cerr << "on_read execution" << '\n';
    std::cout << written_messages << " () " << exchange_data.size() << '\n';
    std::cerr << "do_write() execution" << '\n';
    #endif

    auto on_write = [this](const boost::system::error_code& ec, size_t bytes)
    {
      #ifdef _cerr_on
      std::cerr << "on_write execution" << '\n';
      std::cerr << "Error code is: " << ec.message() << "\n";
      #endif
      assert(!ec);
      if(!ec)     
      written_messages++;

      
      wait_for_write();
    };

   // auto last = exchange_data[written_messages];
    std::strcpy(write , "Something!");
    async_write(socket, buffer(write, max_size), on_write);

}
void connection_server_side::do_read() {

  #ifdef _cerr_on
  std::cerr << "do_read() execution" << '\n';
  std::cerr << "exchange size: " <<exchange_data.size()<< '\n';
  #endif

  auto ptr_to_this = shared_from_this();
  auto on_read =
  [ptr_to_this, this]
  (const boost::system::error_code& ec, size_t bytes)
  {
    #ifdef _cerr_on
    std::cerr << "on_read execution" << '\n';
    std::cerr << "Error code is: " << ec.message() << "\n";
    #endif

    assert(!ec);
     if(!ec)
     exchange_data.push_back(std::string(peer_name)+std::string("|")+std::string(read));
     do_read();
  };

  async_read(socket, buffer(read, max_size), on_read);

}
