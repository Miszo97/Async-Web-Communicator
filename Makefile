# /*
#  * @Author: Artur 
#  * @Date: 2018-03-29 23:59:49 
#  * @Last Modified by: Artur
#  * @Last Modified time: 2018-03-30 00:00:16
#  */

COMPILER := clang++
WARNINGS := -Wall
STD := -std=c++14

BOOST_DIR_INC := -I/Users/miszo97/Documents/Programming/boost_1_66_0
PATH_TO_LIBS := -L/Users/miszo97/Documents/Programming/Other_stuff/boost_1_65_0/stage/lib
LIBS := -lboost_system -lncurses -pthread -lboost_log_setup -lboost_log -lboost_date_time -lboost_thread -lboost_filesystem

all: main.o messages_section.o write_section.o section.o AWC.o server_interface.o client_interface.o safeQueue.o safeVector.o  connection_server_side.o connection_client_side.o free_functions.o 
		$(COMPILER) $(WARNINGS) $(BOOST_DIR_INC) $(PATH_TO_LIBS) $(LIBS) main.o messages_section.o write_section.o section.o AWC.o server_interface.o client_interface.o safeVector.o safeQueue.o  connection_server_side.o connection_client_side.o  free_functions.o -o awc.exe
debug: main.o messages_section.o write_section.o section.o AWC.o server_interface.o client_interface.o safeQueue.o safeVector.o  connection_server_side.o connection_client_side.o free_functions.o 
		$(COMPILER) -g -O3 $(WARNINGS) $(BOOST_DIR_INC) $(PATH_TO_LIBS) $(LIBS) main.o messages_section.o write_section.o section.o AWC.o server_interface.o client_interface.o safeVector.o safeQueue.o  connection_server_side.o connection_client_side.o  free_functions.o -o awc.exe
release: main.o messages_section.o write_section.o section.o AWC.o server_interface.o client_interface.o safeQueue.o safeVector.o  connection_server_side.o connection_client_side.o free_functions.o 
		$(COMPILER) -O1 $(WARNINGS) $(BOOST_DIR_INC) $(PATH_TO_LIBS) $(LIBS) main.o messages_section.o write_section.o section.o AWC.o server_interface.o client_interface.o safeVector.o safeQueue.o  connection_server_side.o connection_client_side.o  free_functions.o -o awc.exe

main.o: src/main.cpp
	$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/main.cpp
section.o: src/section.cpp
	$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/section.cpp
messages_section.o: src/messages_section.cpp
	$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/messages_section.cpp
write_section.o: src/write_section.cpp
	$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/write_section.cpp
AWC.o: src/AWC.cpp
	$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/AWC.cpp
interface.o: src/interface.cpp
	$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/interface.cpp
client_interface.o: src/client_interface.cpp
	$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/client_interface.cpp
server_interface.o: src/server_interface.cpp
	$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/server_interface.cpp
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
free_functions.o: src/free_functions.cpp
	$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/free_functions.cpp


#tests
test: test1.o
		$(COMPILER) $(WARNINGS) $(BOOST_DIR_INC) test1.o -o test.exe
test1.o: tests/test1.cpp
		$(COMPILER) $(STD) -c $(BOOST_DIR_INC) tests/test1.cpp
#tests

clean:
	rm *.o
