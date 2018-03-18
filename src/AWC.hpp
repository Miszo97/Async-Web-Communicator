/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 12:18 AM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: AWC.hpp
 * @Last modified by:   miszo97
 * @Last modified time: March 19, 2018 12:23 AM
 */

 #ifndef AWC_HPP
 #define AWC_HPP
 #include "safeQueue.hpp"
 #include "safeVector.hpp"
 #include "interface.hpp"

 class AWC{

 public:
   void runServer();
   void runClient();
   void start(const char*);

 private:
   safeQueue<std::string> outgoing_data;
   safeVector<std::string> incoming_data;
   Interface interface;




 };

 #endif
