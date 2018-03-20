/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 12:18 AM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: AWC.cpp
 * @Last modified by:   miszo97
 * @Last modified time: March 20, 2018 6:44 PM
 */

 #include "AWC.hpp"
 #include <iostream>
 #include <cstring>
 #include <chrono>
 #include <thread>
 #include <boost/bind.hpp>

 AWC::AWC() : interface(incoming_data, outgoing_data)
 {}

 void AWC::runServer() {

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
   this->runClient();
   interface_thread.join();


 }
