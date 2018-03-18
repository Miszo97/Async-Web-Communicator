/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 12:18 AM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: AWC.cpp
 * @Last modified by:   miszo97
 * @Last modified time: March 19, 2018 12:28 AM
 */

 #include "AWC.hpp"
 #include <iostream>
 #include <cstring>
 #include <chrono>
 #include <thread>

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

   if (std::strcmp(mode, "client")) {
     std::cout << "server" << '\n';
     runServer();
   } else{
     std::cout << "client" << '\n';
     runClient();
   }


 }
