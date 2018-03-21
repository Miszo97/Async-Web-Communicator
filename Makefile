# @Author: Artur <miszo97>
# @Date:   March 17, 2018 5:46 AM
# @Email:  artsspe@gmail.com
# @Project: Async-Web-Communicator
# @Filename: Makefile
# @Last modified by:   miszo97
# @Last modified time: March 21, 2018 8:47 PM

BOOST_DIR_INC := -I/Users/miszo97/Documents/Programming/boost_1_66_0
COMPILER := g++
WARNINGS := -Wall
STD := -std=c++14
PATH_TO_LIBS := -L/Users/miszo97/Documents/Programming/Other_stuff/boost_1_65_0/stage/lib
LIBS := -lboost_system

all: main.o AWC.o interface.o safeQueue.o safeVector.o connection.o
		$(COMPILER) $(WARNINGS) $(BOOST_DIR_INC) $(PATH_TO_LIBS) $(LIBS) main.o AWC.o interface.o safeVector.o safeQueue.o connection.o -o awc.exe
debug: main.o AWC.o interface.o safeQueue.o safeVector.o connection.o
		$(COMPILER) -O3 $(WARNINGS) $(BOOST_DIR_INC) $(PATH_TO_LIBS) $(LIBS) main.o AWC.o interface.o safeVector.o safeQueue.o connection.o -o awc.exe
release: main.o AWC.o interface.o safeQueue.o safeVector.o connection.o
		$(COMPILER) -O1 $(WARNINGS) $(BOOST_DIR_INC) $(PATH_TO_LIBS) $(LIBS) main.o AWC.o interface.o safeVector.o safeQueue.o connection.o -o awc.exe

main.o: src/main.cpp
	$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/main.cpp
AWC.o: src/AWC.cpp
	$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/AWC.cpp
interface.o: src/interface.cpp
	$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/interface.cpp
safeVector.o: src/safeVector.cpp
	$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/safeVector.cpp
safeQueue.o: src/safeQueue.cpp
	$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/safeQueue.cpp
connection.o: src/connection.cpp
	$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/connection.cpp


#tests
test: test1.o
		$(COMPILER) $(WARNINGS) $(BOOST_DIR_INC) test1.o -o test.exe
test1.o: tests/test1.cpp
		$(COMPILER) $(STD) -c $(BOOST_DIR_INC) tests/test1.cpp
#tests

clean:
	rm *.o
