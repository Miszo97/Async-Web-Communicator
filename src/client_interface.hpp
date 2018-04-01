/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 6:50 PM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: client_interface.hpp
 * @Last modified by:   miszo97
 * @Last modified time: March 20, 2018 6:45 PM
 */



#ifndef client_interface_HPP
#define client_interface_HPP

#include <string>
#include <vector>
#include "safeQueue.hpp"
#include "safeVector.hpp"
#include "messages_section.hpp"
#include "write_section.hpp"

class client_interface{

public:
  client_interface(safeVector<std::string>&, safeQueue<std::string>&);

void display();
void start();
void getInput();

template<typename T>
void setName(T&& _name){
  name = std::forward<T>(_name);
}

private:
std::vector<std::string> messages_to_display;
safeVector<std::string>& incoming_data;
safeQueue<std::string>& outgoing_data;
Write_section write_section;
Messages_section messages_section;
size_t displayed_messagess_so_far;
std::string name;




};



#endif
