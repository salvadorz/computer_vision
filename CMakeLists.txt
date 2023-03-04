cmake_minimum_required(VERSION 3.0.0)
project(opencv_starter)


find_package(OpenCV 4 REQUIRED)

if(NOT OpenCV_FOUND)
  message(FATAL_ERROR "OpenCV not found!!")
endif()

add_executable(opencv_starter main.cpp)
target_link_libraries(opencv_starter ${OpenCV_LIBS})
