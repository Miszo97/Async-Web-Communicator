/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 5:58 PM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: safeQueue.hpp
 * @Last modified by:   miszo97
 * @Last modified time: March 20, 2018 6:25 PM
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


private:
  std::mutex mutex;
  std::queue<std::string> q;



};

template <typename T>
void safeQueue<T>::push(const T& val){
  std::lock_guard<std::mutex> lg(mutex);
  q.push(val);
}


#endif
