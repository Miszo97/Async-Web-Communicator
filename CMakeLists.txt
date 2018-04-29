cmake_minimum_required(VERSION 3.10)
project(AWC)

set(MY_SOURCE_DIR "/Users/artur/CLionProjects/Async-Web-Communicator/src")

set(CMAKE_CXX_STANDARD 14)
set(Boost_INCLUDE_DIR "/usr/local/boost_1_67_0/")
set (CMAKE_CXX_FLAGS "-lncurses -L/usr/local/boost_1_67_0/stage/lib -lboost_system -lboost_coroutine")

include_directories( ${MY_SOURCE_DIR}/src )



find_package(Boost)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif()


add_library(section OBJECT ${MY_SOURCE_DIR}/section.cpp)
add_library(main OBJECT ${MY_SOURCE_DIR}/main.cpp)
add_library(messages_section OBJECT ${MY_SOURCE_DIR}/messages_section.cpp)
add_library(write_section OBJECT ${MY_SOURCE_DIR}/write_section.cpp)
add_library(AWC OBJECT ${MY_SOURCE_DIR}/AWC.cpp)
add_library(client_interface OBJECT ${MY_SOURCE_DIR}/client_interface.cpp)
add_library(server_interface OBJECT ${MY_SOURCE_DIR}/server_interface.cpp)
add_library(safeVector OBJECT ${MY_SOURCE_DIR}/safeVector.cpp)
add_library(safeQueue OBJECT ${MY_SOURCE_DIR}/safeQueue.cpp)
add_library(connection_server_side OBJECT ${MY_SOURCE_DIR}/connection_server_side.cpp)
add_library(connection_client_side OBJECT ${MY_SOURCE_DIR}/connection_client_side)
add_library(free_functions OBJECT ${MY_SOURCE_DIR}/free_functions.cpp)

add_executable(program $<TARGET_OBJECTS:main> $<TARGET_OBJECTS:section> $<TARGET_OBJECTS:messages_section> $<TARGET_OBJECTS:write_section> $<TARGET_OBJECTS:AWC> $<TARGET_OBJECTS:client_interface>
        $<TARGET_OBJECTS:connection_server_side> $<TARGET_OBJECTS:connection_client_side> $<TARGET_OBJECTS:free_functions> $<TARGET_OBJECTS:safeQueue> $<TARGET_OBJECTS:safeVector>
        $<TARGET_OBJECTS:server_interface>)









#main.o: src/main.cpp
#$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/main.cpp
#section.o: src/section.cpp
#$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/section.cpp
#messages_section.o: src/messages_section.cpp
#$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/messages_section.cpp
#write_section.o: src/write_section.cpp
#$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/write_section.cpp
#AWC.o: src/AWC.cpp
#$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/AWC.cpp
#interface.o: src/interface.cpp
#$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/interface.cpp
#client_interface.o: src/client_interface.cpp
#$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/client_interface.cpp
#server_interface.o: src/server_interface.cpp
#$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/server_interface.cpp
#safeVector.o: src/safeVector.cpp
#$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/safeVector.cpp
#safeQueue.o: src/safeQueue.cpp
#$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/safeQueue.cpp
#connection.o: src/connection.cpp
#$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/connection.cpp
#connection_server_side.o: src/connection_server_side.cpp
#$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/connection_server_side.cpp
#connection_client_side.o: src/connection_client_side.cpp
#$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/connection_client_side.cpp
#free_functions.o: src/free_functions.cpp
#$(COMPILER) $(STD) $(WARNINGS) -c $(BOOST_DIR_INC) src/free_functions.cpp