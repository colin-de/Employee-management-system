cmake_minimum_required(VERSION 3.1)
project(EMPLOYEE_MANAGEMENT_SYSTEM)

# list all the headers of the module
set(MODULE_HEADERS boss.h employee.h worker.h manager.h workerManager.h)

# list all the code files of the module
set(MODULE_SOURCES boss.cpp employee.cpp worker.cpp manager.cpp workerManager.cpp)

# build the module library
set(LIBRARY_NAME libWORKER)
add_library(${LIBRARY_NAME} ${MODULE_HEADERS} ${MODULE_SOURCES})
add_library(lib::${LIBRARY_NAME} ALIAS ${LIBRARY_NAME})

target_include_directories(${LIBRARY_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

# require C++11
target_compile_features(${LIBRARY_NAME} PUBLIC cxx_std_11)
set_target_properties(${LIBRARY_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# we also add a executable
set(EXECUTABLE_NAME WorkerManager)
add_executable(${EXECUTABLE_NAME} workerManager.cpp)
target_link_libraries(${EXECUTABLE_NAME} lib::${LIBRARY_NAME})

# this adds many warnings to your build. They usually help you find some bugs
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
    target_compile_options( ${EXECUTABLE_NAME} PUBLIC -Wall -Wextra -Wconversion -pedantic -Wfatal-errors)
    target_compile_options( ${LIBRARY_NAME} PUBLIC -Wall -Wextra -Wconversion -pedantic -Wfatal-errors)
endif()
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_options( ${LIBRARY_NAME} PUBLIC /W3 /WX )
    target_compile_options( ${EXECUTABLE_NAME} PUBLIC /W3 /WX )
endif()
