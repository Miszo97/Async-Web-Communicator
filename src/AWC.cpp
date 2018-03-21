/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 12:18 AM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: AWC.cpp
 * @Last modified by:   miszo97
 * @Last modified time: March 21, 2018 8:55 PM
 */

 #include "AWC.hpp"
 #include <iostream>
 #include <cstring>
 #include <chrono>
 #include <thread>
 #include <boost/bind.hpp>
 #include <boost/asio.hpp>
 #include "connection.hpp"

  using namespace boost::asio;

 AWC::AWC() : interface(incoming_data, outgoing_data)
 {}

 void AWC::runServer() {

   io_context io;
   ip::tcp::socket socket(io);
   ip::tcp::endpoint ep(ip::tcp::v4(), 4777);
   ip::tcp::acceptor acc(io, ep);
   auto accept_handler = [](const boost::system::error_code& ec)
   {if(!ec) std::cout << "Connection established!" << '\n'; else std::cout << "Connection failed!" << '\n';};
   acc.async_accept(socket, accept_handler);
   io.run();

   for(;;){
   std::cout << "running server" << '\n';
   std::this_thread::sleep_for(std::chrono::seconds(1));
   }

 }
 void AWC::runClient() {
   io_context io;
   ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 4777);
   std::shared_ptr<connection> new_connection = connection::start(ep, io);
   io.run();
   for(;;){
   std::cout << "running client" << '\n';
   std::this_thread::sleep_for(std::chrono::seconds(1));
   }

 }

 void AWC::start(const char * mode) {

   std::thread interface_thread(boost::bind(&Interface::start, &interface));
   if (std::string(mode) == "server") {
     this->runServer();
   } else if(std::string(mode) == "client") {
     this->runClient();
   }

   interface_thread.join();


 }
