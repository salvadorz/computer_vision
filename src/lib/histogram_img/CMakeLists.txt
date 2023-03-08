add_library(histogram_img SHARED histogram_img.cpp)
target_link_libraries(histogram_img ${OpenCV_LIBS})