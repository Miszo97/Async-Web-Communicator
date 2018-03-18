# @Author: Artur <miszo97>
# @Date:   March 17, 2018 5:46 AM
# @Email:  artsspe@gmail.com
# @Project: Async-Web-Communicator
# @Filename: Makefile
# @Last modified by:   miszo97
# @Last modified time: March 19, 2018 12:36 AM

all:
		g++ src/main.cpp src/interface.cpp src/safeQueue.cpp src/safeVector.cpp src/AWC.cpp -o exec
test:
		g++ tests/test1.cpp -I/Users/miszo97/Documents/Programming/boost_1_66_0 -o test
