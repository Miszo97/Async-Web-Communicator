/**
 * @Author: Artur <miszo97>
 * @Date:   March 17, 2018 5:46 AM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: main.cpp
 * @Last modified by:   miszo97
 * @Last modified time: March 20, 2018 12:38 AM
 */

 #include "AWC.hpp"
 #include <iostream>
 #include "free_functions.hpp"

int main(int argc, char const *argv[]) {
  // let it start

switch (argc)
{
  case 1 : printUsage(); exit(1);
  case 2 : printUsage(); exit(1);
  case 3 : if(std::strcmp("server",argv[1])) {printUsage(); exit(1);} break;
  case 4 : if(std::strcmp("client",argv[1])) {printUsage(); exit(1);} break;
  default:
  printUsage(); exit(1);
  break;
}

  try{

    AWC awc;
    awc.start(argv);

  } catch (...) {

    std::cerr << "/* error message */" << '\n';

  }

  return 0;
}
