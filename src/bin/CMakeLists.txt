add_executable(simple_image_show simple_image.cpp)
target_link_libraries(simple_image_show ${OpenCV_LIBS})

add_executable(simple_image_write simple_img_write.cpp)
target_link_libraries(simple_image_write ${OpenCV_LIBS})

add_executable(histogram_display histogram_display.cpp)
target_link_libraries(histogram_display histogram_img ${OpenCV_LIBS})

add_executable(lut_transform lut_transform.cpp)
target_link_libraries(lut_transform ${OpenCV_LIBS})

add_executable(l4_hsv_color_space l4_color_space_hsv.cpp)
target_link_libraries(l4_hsv_color_space ${OpenCV_LIBS})

add_executable(l5_convolution l5_convolution.cpp)
target_link_libraries(l5_convolution ${OpenCV_LIBS})

add_executable(l6_correlation l6_correlation.cpp)
target_link_libraries(l6_correlation ${OpenCV_LIBS})