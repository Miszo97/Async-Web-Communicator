/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 5:58 PM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: safeQueue.hpp
 * @Last modified by:   miszo97
 * @Last modified time: March 22, 2018 4:48 PM
 */

 #ifndef SAFE_QUEUE_HPP
 #define SAFE_QUEUE_HPP

 #include <mutex>
 #include <queue>
 #include <string>


template <typename T>
class safeQueue{
public:
  void push(const T&);
  size_t size();
  T pop();



private:
  std::mutex mutex;
  std::queue<std::string> q;



};

template <typename T>
void safeQueue<T>::push(const T& val){
  std::lock_guard<std::mutex> lg(mutex);
  q.push(val);
}

template <typename T>
T safeQueue<T>::pop()
{
  std::lock_guard<std::mutex> lg(mutex);
  T front = std::move(q.front());
  q.pop();
  return front;
}

template <typename T>
size_t safeQueue<T>::size(){
  std::lock_guard<std::mutex> lg(mutex);
  return q.size();
}



#endif
