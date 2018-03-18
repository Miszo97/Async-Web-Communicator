/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 10:21 PM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: test1.cpp
 * @Last modified by:   miszo97
 * @Last modified time: March 19, 2018 12:42 AM
 */



#define BOOST_TEST_MODULE module_test
#include <boost/test/included/unit_test.hpp>
#include "AWC.hpp"

BOOST_AUTO_TEST_SUITE( AWC testing )

BOOST_AUTO_TEST_CASE( test_case1 )
{
  AWC 
  BOOST_TEST_WARN( sizeof(int) < 4U );
}

BOOST_AUTO_TEST_CASE( test_case2 )
{
  BOOST_TEST_REQUIRE( 1 == 2 );
  BOOST_FAIL( "Should never reach this line" );
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE( test_suite2 )

BOOST_AUTO_TEST_CASE( test_case3 )
{
  BOOST_TEST( true );
}

BOOST_AUTO_TEST_CASE( test_case4 )
{
  BOOST_TEST( false );
}

BOOST_AUTO_TEST_SUITE_END()
