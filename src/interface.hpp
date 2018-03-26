/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 6:50 PM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: interface.hpp
 * @Last modified by:   miszo97
 * @Last modified time: March 20, 2018 6:45 PM
 */



#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <string>
#include <vector>
#include "safeQueue.hpp"
#include "safeVector.hpp"

class Interface{

public:
  Interface(safeVector<std::string>&, safeQueue<std::string>&, safeVector<std::string>&);

void display();
void start();
void getInput();

private:
std::vector<std::string> messages_to_display;
safeVector<std::string>& incoming_data;
safeVector<std::string>& exchange_data;
safeQueue<std::string>& outgoing_data;



};

#endif
