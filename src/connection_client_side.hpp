/**
 * @Author: Artur <miszo97>
 * @Date:   March 21, 2018 8:20 AM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: connection_client_side.h
 * @Last modified by:   miszo97
 * @Last modified time: March 24, 2018 2:09 AM
 */
 #ifndef connection_client_side_HPP
 #define connection_client_side_HPP

 #include <iostream>
 #include <boost/asio.hpp>
 #include "safeQueue.hpp"
 #include "safeVector.hpp"

 using namespace boost::asio;
 class connection_client_side : public std::enable_shared_from_this<connection_client_side>
 {
 public:
   typedef std::shared_ptr<connection_client_side> ptr;
   connection_client_side(io_context&, safeQueue<std::string>&, safeVector<std::string>&);

   void start(ip::tcp::endpoint);
   static ptr start(ip::tcp::endpoint, io_context&, safeQueue<std::string>&, safeVector<std::string>&);
   void stop();
   void do_write();
   void do_read();
   void wait_for_write();
   ip::tcp::socket& sock();



 private:
   io_context& io;
   ip::tcp::socket socket;
   enum { max_size = 32768 };
   char write[max_size];
   char read[max_size];
   bool started;
   int written_messages = 0;
   safeQueue<std::string>& outgoing_data;
   safeVector<std::string>& incoming_data;

 };

 #endif
