/*
 * @Author: Artur 
 * @Date: 2018-03-26 02:46:23 
 * @Last Modified by: Artur
 * @Last Modified time: 2018-03-26 02:54:21
 */


#include "connection_server_side.hpp"
#include "safeQueue.hpp"
#include "safeVector.hpp"
// #define _cerr_on

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

bool connection_server_side::is_the_new_message_the_same_that_received()
{
  auto candidate = exchange_data[new_message_index];
  auto sender = candidate.substr(0, candidate.find_first_of(":"));

  if (sender == peer_name)
    return true;
  return false;
};

void connection_server_side::wait_for_write()
{

#ifdef _cerr_on
  std::cerr << "cconnection_server_side::wait_for_write()"
            << "\n";
#endif
  //std::this_thread::sleep_for(std::chrono::seconds(1));

  if (exchange_data.size() <= new_message_index)
  {
    io.post([this]() { this->wait_for_write(); });
  }
  else if(is_the_new_message_the_same_that_received())
  {
    new_message_index++;
    io.post([this]() { this->wait_for_write(); });
  } else
  {
    do_write();
  }
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
  
  //std::this_thread::sleep_for(std::chrono::seconds(1));

    #ifdef _cerr_on
    std::cerr << "on_read execution" << '\n';
    //std::cout << new_message_index << " () " << exchange_data.size() << '\n';
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
      new_message_index++;

      
      wait_for_write();
    };

    auto last = exchange_data[new_message_index];
    std::strcpy(write , last.data());
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
     if(!ec){
     std::string received = read;

     peer_name = received.substr(0, received.find_first_of(":"));
     exchange_data.push_back(received);
     }

     do_read();
  };

  async_read(socket, buffer(read, max_size), on_read);

}
