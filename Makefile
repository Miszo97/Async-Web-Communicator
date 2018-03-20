# @Author: Artur <miszo97>
# @Date:   March 17, 2018 5:46 AM
# @Email:  artsspe@gmail.com
# @Project: Async-Web-Communicator
# @Filename: Makefile
# @Last modified by:   miszo97
# @Last modified time: March 20, 2018 6:02 PM

BOOST_DIR_INC := -I/Users/miszo97/Documents/Programming/boost_1_66_0
COMPILER := g++
WARNINGS := -Wall

all: main.o AWC.o interface.o safeQueue.o safeVector.o
		$(COMPILER) $(WARNINGS) $(BOOST_DIR_INC) main.o AWC.o interface.o safeVector.o safeQueue.o -o awc.exe
debug: main.o AWC.o interface.o safeQueue.o safeVector.o
		$(COMPILER) -O3 $(WARNINGS) $(BOOST_DIR_INC) main.o AWC.o interface.o safeVector.o safeQueue.o -o awc.exe
release: main.o AWC.o interface.o safeQueue.o safeVector.o
		$(COMPILER) -O1 $(WARNINGS) $(BOOST_DIR_INC) main.o AWC.o interface.o safeVector.o safeQueue.o -o awc.exe

main.o: src/main.cpp
	$(COMPILER) $(WARNINGS) -c $(BOOST_DIR_INC) src/main.cpp
AWC.o: src/AWC.cpp
	$(COMPILER) $(WARNINGS) -c $(BOOST_DIR_INC) src/AWC.cpp
interface.o: src/interface.cpp
	$(COMPILER) $(WARNINGS) -c $(BOOST_DIR_INC) src/interface.cpp
safeVector.o: src/safeVector.cpp
	$(COMPILER) $(WARNINGS) -c $(BOOST_DIR_INC) src/safeVector.cpp
safeQueue.o: src/safeQueue.cpp
	$(COMPILER) $(WARNINGS) -c $(BOOST_DIR_INC) src/safeQueue.cpp

#tests
test: test1.o
		$(COMPILER) $(WARNINGS) $(BOOST_DIR_INC) test1.o -o test.exe
test1.o: tests/test1.cpp
		$(COMPILER) -c $(BOOST_DIR_INC) tests/test1.cpp
#tests

clean:
	rm *.o
