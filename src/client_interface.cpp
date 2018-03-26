/*
 * @Author: Artur 
 * @Date: 2018-03-26 00:44:26 
 * @Last Modified by: Artur
 * @Last Modified time: 2018-03-26 00:50:00
 */

 #include "client_interface.hpp"
 #include <iostream>
 #include "safeQueue.hpp"
 #include "safeVector.hpp"
 #include <thread>
 #include <chrono>

 void client_interface::start() {
     std::thread t1(&client_interface::getInput, this);
   while (1) {
     display();
     std::this_thread::sleep_for(std::chrono::seconds(3));
   }
     t1.join();
 }

 client_interface::client_interface(safeVector<std::string>& _incoming_data, safeQueue<std::string>& _outgoing_data) :
 incoming_data(_incoming_data),
 outgoing_data(_outgoing_data)
 {}

 void client_interface::getInput(){
   while(1){
   std::string input;
   std::getline(std::cin, input);
   std::cerr<<"pushing input"<<"\n";
   outgoing_data.push(input);
   incoming_data.push_back(std::string("ME :")+input);
   }
 }
 void client_interface::display(){
     if(incoming_data.size() != 0)
     for(auto&& message : incoming_data)
      std::cout<<"client_interface displays –> "<< message << std::endl;
 }
