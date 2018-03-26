/*
 * @Author: Artur 
 * @Date: 2018-03-26 00:44:26 
 * @Last Modified by: Artur
 * @Last Modified time: 2018-03-26 00:50:00
 */

 #include "interface.hpp"
 #include <iostream>
 #include "safeQueue.hpp"
 #include "safeVector.hpp"
 #include <thread>
 #include <chrono>

 void Interface::start() {
     std::thread t1(&Interface::getInput, this);
   while (1) {
     display();
     std::this_thread::sleep_for(std::chrono::seconds(3));
   }
     t1.join();
 }

 Interface::Interface(safeVector<std::string>& _incoming_data, safeQueue<std::string>& _outgoing_data, safeVector<std::string>& _exchange_data) :
 incoming_data(_incoming_data),
 outgoing_data(_outgoing_data),
 exchange_data(_exchange_data)
 {}

 void Interface::getInput(){
   while(1){
   std::string input;
   std::getline(std::cin, input);
   std::cerr<<"pushing input"<<"\n";
   exchange_data.push_back(input);
   outgoing_data.push(input);
   }
 }
 void Interface::display(){
     if(exchange_data.size() != 0)
     for(auto&& message : exchange_data)
      std::cout<<"Interface displays –> "<< message << std::endl;
 }
