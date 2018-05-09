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

///
/// \tparam T The type of the stored elements.
/// \brief Thread-safe wrapper to managing Vector.
template <typename T>
class safeVector {

public:


  safeVector(const safeVector<T>&)  = delete;
  safeVector(safeVector<T>&&)  = delete;
  safeVector& operator=(const safeVector<T>&)= delete;
  safeVector& operator=(safeVector<T>&&)= delete;

  safeVector() = default;


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

/// This function allows user to put new element (r-value, l-value) to underlying vector via it's push_back() function. Additionally this function wrapper
/// locks the mutex to provide thread-safe operation.
/// \tparam T The type of the stored elements.
/// \param val Value to be pushed on the end of the underlying vector.
template <typename T>
void safeVector<T>::push_back(const T& val){
  std::lock_guard<std::mutex> lg(mutex);
  v.push_back(val);
}

///
/// \tparam T The type of the stored elements.
/// \return
template<typename T>
typename std::vector<T>::iterator safeVector<T>::begin(){
  return v.begin();
}

///
/// \tparam T The type of the stored elements.
/// \return
template<typename T>
typename std::vector<T>::iterator safeVector<T>::end(){
  return v.end();
}

///
/// \tparam T The type of the stored elements.
/// \return
template <typename T>
T& safeVector<T>::back()
{
  return v.back();
}

/// Operator[] to retrieve a stored value. Note: This function DOES NOT check whether a index is valid i.e if index points actual variable.
/// If index exceeds range it throws exception std::out_of_range.
/// \tparam T The type of the stored elements.
/// \param index Valid index of element.
/// \return Reference to stored value of given index.
template <typename T>
T& safeVector<T>::operator[](size_t index) {
  std::lock_guard<std::mutex> lg(mutex);
  return v[index];
}
template <typename T>

/// Overloaded operator[] to const return.
/// \tparam T The type of the stored elements.
/// \param index
/// \return Const reference to stored value of given index.
const T& safeVector<T>::operator[](size_t index) const {
  std::lock_guard<std::mutex> lg(mutex);
  return v[index];
}

///
/// \tparam T The type of the stored elements.
/// \return The actual size of underlying vector.
template <typename T>
size_t safeVector<T>::size(){
  std::lock_guard<std::mutex> lg(mutex);
  return v.size();
}


#endif
