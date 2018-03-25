# @Author: Artur <miszo97>
# @Date:   March 17, 2018 5:46 AM
# @Email:  artsspe@gmail.com
# @Project: Async-Web-Communicator
# @Filename: Makefile
# @Last modified by:   miszo97
# @Last modified time: March 23, 2018 10:11 PM

BOOST_DIR_INC := -I/Users/miszo97/Documents/Programming/boost_1_66_0
COMPILER := g++
WARNINGS := -Wall
STD := -std=c++14
PATH_TO_LIBS := -L/Users/miszo97/Documents/Programming/Other_stuff/boost_1_65_0/stage/lib
LIBS := -lboost_system

all: main.o AWC.o interface.o safeQueue.o safeVector.o connection.o connection_server_side.o connection_client_side.o
		$(COMPILER) $(WARNINGS) $(BOOST_DIR_INC) $(PATH_TO_LIBS) $(LIBS) main.o AWC.o interface.o safeVector.o safeQueue.o connection.o connection_server_side.o connection_client_side.o -o awc.exe
debug: main.o AWC.o interface.o safeQueue.o safeVector.o connection.o connection_server_side.o connection_client_side.o
		$(COMPILER) -O3 $(WARNINGS) $(BOOST_DIR_INC) $(PATH_TO_LIBS) $(LIBS) main.o AWC.o interface.o safeVector.o safeQueue.o connection.o connection_server_side.o connection_client_side.o -o awc.exe
release: main.o AWC.o interface.o safeQueue.o safeVector.o connection.o connection_server_side.o connection_client_side.o
		$(COMPILER) -O1 $(WARNINGS) $(BOOST_DIR_INC) $(PATH_TO_LIBS) $(LIBS) main.o AWC.o interface.o safeVector.o safeQueue.o connection.o connection_server_side.o connection_client_side.o -o awc.exe

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
connection_server_side.o: src/connection_server_side.cpp
	$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/connection_server_side.cpp
connection_client_side.o: src/connection_client_side.cpp
	$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/connection_client_side.cpp


#tests
test: test1.o
		$(COMPILER) $(WARNINGS) $(BOOST_DIR_INC) test1.o -o test.exe
test1.o: tests/test1.cpp
		$(COMPILER) $(STD) -c $(BOOST_DIR_INC) tests/test1.cpp
#tests

clean:
	rm *.o
