/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 5:50 PM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: safeVector.hpp
 * @Last modified by:   miszo97
 * @Last modified time: March 18, 2018 6:06 PM
 */



#ifndef SAFE_VECTOR_HPP
#define SAFE_VECTOR_HPP
#include <mutex>
#include <vector>

template <typename T>
class safeVector {

public:
  void push_back();


private:
  std::mutex mutex;
  std::vector<T> v;




};

#endif
