# @Author: Artur <miszo97>
# @Date:   March 17, 2018 5:46 AM
# @Email:  artsspe@gmail.com
# @Project: Async-Web-Communicator
# @Filename: Makefile
# @Last modified by:   miszo97
# @Last modified time: March 18, 2018 10:52 PM

all:
		g++ src/main.cpp src/AWC.cpp -o exec
test:
		g++ tests/test1.cpp -I/Users/miszo97/Documents/Programming/boost_1_66_0 -o test
