/**
 * @Author: Artur <miszo97>
 * @Date:   March 18, 2018 5:58 PM
 * @Email:  artsspe@gmail.com
 * @Project: Async-Web-Communicator
 * @Filename: safeQueue.hpp
 * @Last modified by:   miszo97
 * @Last modified time: March 18, 2018 6:53 PM
 */

 #ifndef SAFE_QUEUE_HPP
 #define SAFE_QUEUE_HPP

 #include <mutex>
 #include <queue>


template <typename T>
class safeQueue{
public:
  void push();


private:
  std::mutex m;



};

#endif
