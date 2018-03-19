/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 10:21 PM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: test1.cpp
 * @Last modified by:   miszo97
 * @Last modified time: March 20, 2018 12:36 AM
 */



#define BOOST_TEST_MODULE module_test
#include <boost/test/included/unit_test.hpp>
#include "../src/AWC.hpp"
#include "../src/interface.hpp"
#include "../src/safeVector.hpp"

namespace utf = boost::unit_test;

BOOST_AUTO_TEST_SUITE( AWC_class_testing )

BOOST_AUTO_TEST_CASE( test_case1 )
{
  AWC awc;
}

BOOST_AUTO_TEST_SUITE_END( )

BOOST_AUTO_TEST_SUITE( safe_vector )

BOOST_AUTO_TEST_CASE( safe_vector_methods,
*utf::description("testing push_back, size, operator[]")
*utf::label("methods_relation"))
{
  safeVector<int> v;
  BOOST_CHECK_EQUAL(0, v.size());
  v.push_back(4);
  BOOST_CHECK_EQUAL(1, v.size());


}


BOOST_AUTO_TEST_SUITE_END()
