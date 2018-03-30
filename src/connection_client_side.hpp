/*
 * @Author: Artur 
 * @Date: 2018-03-26 02:46:11 
 * @Last Modified by:   Artur 
 * @Last Modified time: 2018-03-26 02:46:11 
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
   int new_message_index = 0;
   safeQueue<std::string>& outgoing_data;
   safeVector<std::string>& incoming_data;

 };

 #endif
