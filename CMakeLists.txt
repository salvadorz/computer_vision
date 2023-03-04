cmake_minimum_required(VERSION 3.0.0)
project(opencv_starter)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()


if (WIN32)
    set(OpenCV_DIR "C:/opencv/4.6.0/build/install")
endif (WIN32)

# Create an output dir in PROJECT_SOURCE_DIR
set(OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/${CMAKE_BUILD_TYPE})
file(MAKE_DIRECTORY ${OUTPUT_DIRECTORY})

find_package(OpenCV 4 REQUIRED)

if(NOT OpenCV_FOUND)
  message(FATAL_ERROR "OpenCV not found!!")
endif()

add_executable(opencv_starter main.cpp)
target_link_libraries(opencv_starter ${OpenCV_LIBS})
