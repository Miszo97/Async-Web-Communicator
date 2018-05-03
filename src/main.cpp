#include "AWC.hpp"
#include <iostream>
#include <boost/log/trivial.hpp>
#include "free_functions.hpp"
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;

#if 0

//[ example_tutorial_file_simple
void init()
{
    logging::add_file_log("sample.log");

    logging::core::get()->set_filter
    (
        logging::trivial::severity >= logging::trivial::info
    );
}
//]

// We need this due to this bug: https://svn.boost.org/trac/boost/ticket/4416
//[ example_tutorial_file_advanced_no_callouts
void init()
{
    logging::add_file_log
    (
        keywords::file_name = "sample_%N.log",
        keywords::rotation_size = 10 * 1024 * 1024,
        keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
        keywords::format = "[%TimeStamp%]: %Message%"
    );

    logging::core::get()->set_filter
    (
        logging::trivial::severity >= logging::trivial::info
    );
}
//]

#else

//[ example_tutorial_file_advanced
void init()
{
    logging::add_file_log
            (
                    keywords::file_name = "sample_%N.log",                                        /*< file name pattern >*/
                    keywords::rotation_size = 10 * 1024 * 1024,                                   /*< rotate files every 10 MiB... >*/
                    keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0), /*< ...or at midnight >*/
                    keywords::format = "[%TimeStamp%]: %Message%"                                 /*< log record format >*/
            );


}
//]

#endif


int main(int argc, char const *argv[]) {
  // let it start


    init();
    logging::add_common_attributes();



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

    BOOST_LOG_TRIVIAL(info) << "Starting the application";

    awc.start(argv);

  } catch (...) {

    std::cerr << "/* error message */" << '\n';

  }

  return 0;
}
