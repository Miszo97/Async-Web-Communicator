/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 12:18 AM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: AWC.hpp
 * @Last modified by:   miszo97
 * @Last modified time: March 23, 2018 6:06 PM
 */

#ifndef AWC_HPP
#define AWC_HPP
#include "safeQueue.hpp"
#include "safeVector.hpp"
#include "client_interface.hpp"
#include "server_interface.hpp"
#include <boost/asio/spawn.hpp>

class AWC
{

public:
  AWC();
  void runServer();
  void runClient(const char *);
  void start(char const *argv[]);

  enum class mode
  {
    server,
    client
  };

private:
  void start_listen(boost::asio::yield_context);
  safeVector<std::string> exchange_data; //used by server only
  safeQueue<std::string> outgoing_data;
  safeVector<std::string> incoming_data;
  client_interface c_interface;
  server_interface s_interface;
  std::string peer_name;
  boost::asio::io_context io;
};

#endif
