/*
 * @Author: Artur 
 * @Date: 2018-03-26 00:44:26 
 * @Last Modified by: Artur
 * @Last Modified time: 2018-03-26 00:50:00
 */

 #include "server_interface.hpp"
 #include <iostream>
 #include "safeQueue.hpp"
 #include "safeVector.hpp"
 #include <thread>
 #include <chrono>

 void server_interface::start() {
     std::thread t1(&server_interface::getInput, this);
   while (1) {
     display();
     std::this_thread::sleep_for(std::chrono::seconds(3));
   }
     t1.join();
 }

 server_interface::server_interface(safeVector<std::string>& _exchange_data) :
 exchange_data(_exchange_data)
 {}

 void server_interface::getInput(){
   while(1){
   std::string input;
   std::getline(std::cin, input);
   std::cerr<<"pushing input"<<"\n";
   exchange_data.push_back(std::string("server|")+input);
   }
 }
 void server_interface::display(){
     if(exchange_data.size() != 0)
     for(auto&& message : exchange_data)
      std::cout<<"server_interface displays –> "<< message << std::endl;
 }
