/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 6:50 PM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: interface.hpp
 * @Last modified by:   miszo97
 * @Last modified time: March 19, 2018 2:18 AM
 */



#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <string>
#include <vector>

class Interface{

public:
void display();
void start();

private:
std::vector<std::string> messages_to_display;


};

#endif
