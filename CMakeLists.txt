cmake_minimum_required(VERSION 3.0.0)
project(opencv_starter)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()


if (WIN32)
    set(OpenCV_DIR "C:/opencv/4.6.0/build/install")
endif (WIN32)

find_package(OpenCV 4 REQUIRED)

if(OpenCV_FOUND)
  # Create an output dir in PROJECT_SOURCE_DIR
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/${CMAKE_BUILD_TYPE}/bin)
else()
  message(FATAL_ERROR "OpenCV not found!!")
endif()

add_subdirectory("src")
