/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 6:54 PM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: interface.cpp
 * @Last modified by:   miszo97
 * @Last modified time: March 20, 2018 6:47 PM
 */

 #include "interface.hpp"
 #include <iostream>
 #include "safeQueue.hpp"
 #include "safeVector.hpp"
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

 Interface::Interface(safeVector<std::string>& _incoming_data, safeQueue<std::string>& _outgoing_data) :
 incoming_data(_incoming_data),
 outgoing_data(_outgoing_data)
 {}
