/**
 * @Author: Artur <miszo97>
 * @Date:   March 17, 2018 5:46 AM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: main.cpp
 * @Last modified by:   miszo97
 * @Last modified time: March 18, 2018 12:33 AM
 */

 #include "AWC.hpp"
 #include <iostream>

int main(int argc, char const *argv[]) {
  // let it start

  try{

    AWC awc;
    awc.start();

  } catch (...) {

    std::cerr << "/* error message */" << '\n';

  }

  return 0;
}
