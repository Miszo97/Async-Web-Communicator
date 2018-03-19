# @Author: Artur <miszo97>
# @Date:   March 17, 2018 5:46 AM
# @Email:  artsspe@gmail.com
# @Project: Async-Web-Communicator
# @Filename: Makefile
# @Last modified by:   miszo97
# @Last modified time: March 19, 2018 2:36 AM

BOOST_DIR := -I/Users/miszo97/Documents/Programming/boost_1_66_0
COMPILER := g++ #/usr/local/Cellar/gcc/7.3.0/bin/g++-7

all:
		$(COMPILER) $(BOOST_DIR) src/main.cpp src/interface.cpp src/safeQueue.cpp src/safeVector.cpp src/AWC.cpp -o exec
test:
		$(COMPILER) $(BOOST_DIR) tests/test1.cpp -o
