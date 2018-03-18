/**
 * @Author: Artur <miszo97>
 * @Date:   March 17, 2018 5:46 AM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: main.cpp
 * @Last modified by:   miszo97
 * @Last modified time: March 19, 2018 12:31 AM
 */

 #include "AWC.hpp"
 #include <iostream>

int main(int argc, char const *argv[]) {
  // let it start

  if(argc != 2)
  return 1;

  try{

    AWC awc;
    awc.start(argv[1]);

  } catch (...) {

    std::cerr << "/* error message */" << '\n';

  }

  return 0;
}
