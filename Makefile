# @Author: Artur <miszo97>
# @Date:   March 17, 2018 5:46 AM
# @Email:  artsspe@gmail.com
# @Project: Async-Web-Communicator
# @Filename: Makefile
# @Last modified by:   miszo97
# @Last modified time: March 20, 2018 12:46 AM

BOOST_DIR_INC := -I/Users/miszo97/Documents/Programming/boost_1_66_0
COMPILER := g++
WARNINGS := -Wall

all:
		$(COMPILER) $(WARNINGS) $(BOOST_DIR_INC) src/main.cpp src/interface.cpp src/safeQueue.cpp src/safeVector.cpp src/AWC.cpp -o awc.exe
test: test1.o
		$(COMPILER) $(WARNINGS) $(BOOST_DIR_INC) test1.o -o test.exe
test1.o: tests/test1.cpp
		$(COMPILER) -c $(BOOST_DIR_INC) tests/test1.cpp
clean:
	rm *.o
