/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 12:18 AM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: AWC.cpp
 * @Last modified by:   miszo97
 * @Last modified time: March 24, 2018 2:04 AM
 */

 #include "AWC.hpp"
 #include <iostream>
 #include <cstring>
 #include <chrono>
 #include <thread>
 #include <boost/bind.hpp>
 
 #include <boost/asio.hpp>
 #include "connection_client_side.hpp"
 #include "connection_server_side.hpp"

  using namespace boost::asio;

 AWC::AWC() : s_interface(exchange_data),
 c_interface(incoming_data, outgoing_data)
 {}

 void AWC::runServer() {

   io_context io;
   ip::tcp::socket socket(io);
   ip::tcp::endpoint ep(ip::tcp::v4(), 4777);
   ip::tcp::acceptor acc(io, ep);
   std::shared_ptr<connection_server_side> new_connection = connection_server_side::start(ep, io, outgoing_data, exchange_data, "client");
   auto accept_handler = [new_connection](const boost::system::error_code &ec) {
     if (!ec){
       //std::cout << "Connection established!" << '\n';
       new_connection->start();
     }
     else;
       //std::cout << "Connection failed!" << '\n';
   };
   acc.async_accept(new_connection->sock(), accept_handler);

   io.run();

   for (;;)
   {
     //std::cout << "running server" << '\n';
     std::this_thread::sleep_for(std::chrono::seconds(1));
   }
 }
 void AWC::runClient(const char* destination_ip) {
   io_context io;
   //std::cout<<"Making connection to server with ip"<<destination_ip<<std::endl;
   ip::tcp::endpoint ep(ip::address::from_string(destination_ip), 4777);
   std::shared_ptr<connection_client_side> new_connection = connection_client_side::start(ep, io, outgoing_data, incoming_data);
   io.run();
   for(;;){
   //std::cout << "running client" << '\n';
   std::this_thread::sleep_for(std::chrono::seconds(1));
   
   }

 }

 void AWC::start(char const* argv[]) {

   const char* mode = argv[1];
   if (std::string(mode) == "server") {
   std::thread server_interface_thread(boost::bind(&server_interface::start, &s_interface));
     this->runServer();
   server_interface_thread.join();
   } else if(std::string(mode) == "client") {
   std::thread client_interface_thread(boost::bind(&client_interface::start, &c_interface));
     this->runClient(argv[2]);
   client_interface_thread.join();
   }



 }
