/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 12:18 AM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: AWC.hpp
 * @Last modified by:   miszo97
 * @Last modified time: March 20, 2018 6:43 PM
 */

 #ifndef AWC_HPP
 #define AWC_HPP
 #include "safeQueue.hpp"
 #include "safeVector.hpp"
 #include "interface.hpp"

 class AWC{

 public:
   AWC();
   void runServer();
   void runClient();
   void start(const char*);

 private:
   safeQueue<std::string> outgoing_data;
   safeVector<std::string> incoming_data;
   Interface interface;




 };

 #endif
