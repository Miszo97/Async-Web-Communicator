/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 12:18 AM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: AWC.cpp
 * @Last modified by:   miszo97
 * @Last modified time: March 20, 2018 8:50 PM
 */

 #include "AWC.hpp"
 #include <iostream>
 #include <cstring>
 #include <chrono>
 #include <thread>
 #include <boost/bind.hpp>
 #include <boost/asio.hpp>

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

   for(;;){
   std::cout << "running client" << '\n';
   std::this_thread::sleep_for(std::chrono::seconds(1));
   }

 }

 void AWC::start(const char * mode) {

   std::thread interface_thread(boost::bind(&Interface::start, &interface));
   this->runServer();
   interface_thread.join();


 }
