add_executable(simple_image_show simple_image.cpp)
target_link_libraries(simple_image_show ${OpenCV_LIBS})

add_executable(simple_image_write simple_img_write.cpp)
target_link_libraries(simple_image_write ${OpenCV_LIBS})

add_executable(histogram_display histogram_display.cpp)
target_link_libraries(histogram_display histogram_img ${OpenCV_LIBS})

add_executable(lut_transform lut_transform.cpp)
target_link_libraries(lut_transform ${OpenCV_LIBS})