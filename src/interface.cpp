/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 6:54 PM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: interface.cpp
 * @Last modified by:   miszo97
 * @Last modified time: March 19, 2018 2:51 AM
 */

 #include "interface.hpp"
 #include <iostream>
 #include <thread>
 #include <chrono>

 void Interface::start() {
   while (1) {

     for(;;){
     std::cout << "interface working" << '\n';
     std::this_thread::sleep_for(std::chrono::seconds(3));
     }

   }
 }
