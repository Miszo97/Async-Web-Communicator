/**
 * @Author: Artur <miszo97>
 * @Date:   March 21, 2018 8:20 AM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: connection.h
 * @Last modified by:   miszo97
 * @Last modified time: March 21, 2018 8:41 PM
 */

 #include <iostream>
 #include <boost/asio.hpp>
 using namespace boost::asio;
 class connection : public std::enable_shared_from_this<connection>
 {
 public:
   typedef std::shared_ptr<connection> ptr;
   connection(io_context&);

   void start(ip::tcp::endpoint);
   static ptr start(ip::tcp::endpoint, io_context&);
   void stop();
   void do_write();
   void do_read();
   void on_connect(const boost::system::error_code&);
   void on_read(const boost::system::error_code&);
   void on_write(const boost::system::error_code&);


 private:
   io_context& io;
   ip::tcp::socket socket;
   enum { max_size = 1024 };
   char write[max_size];
   char read[max_size];
   bool started;


 };
