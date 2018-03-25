/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 5:50 PM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: safeVector.hpp
 * @Last modified by:   miszo97
 * @Last modified time: March 20, 2018 12:29 AM
 */



#ifndef SAFE_VECTOR_HPP
#define SAFE_VECTOR_HPP
#include <mutex>
#include <vector>

template <typename T>
class safeVector {

public:
  void push_back(const T&);
  T& back();
  T& operator[](size_t);
  const T& operator[](size_t) const;
  typename std::vector<T>::iterator begin();
  typename std::vector<T>::iterator end();
  size_t size();


private:
  std::mutex mutex;
  std::vector<T> v;




};

template <typename T>
void safeVector<T>::push_back(const T& val){
  std::lock_guard<std::mutex> lg(mutex);
  v.push_back(val);
}

template<typename T>
typename std::vector<T>::iterator safeVector<T>::begin(){
  return v.begin();
}

template<typename T>
typename std::vector<T>::iterator safeVector<T>::end(){
  return v.end();
}

template <typename T>
T& safeVector<T>::back()
{
  return v.back();
}

template <typename T>
T& safeVector<T>::operator[](size_t index) {
  std::lock_guard<std::mutex> lg(mutex);
  return v[index];
}
template <typename T>

const T& safeVector<T>::operator[](size_t index) const {
  std::lock_guard<std::mutex> lg(mutex);
  return v[index];
}

template <typename T>
size_t safeVector<T>::size(){
  std::lock_guard<std::mutex> lg(mutex);
  return v.size();
}


#endif
