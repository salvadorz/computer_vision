#include <iostream>

#include "histogram_img.hpp"
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
  int ret = EXIT_SUCCESS;
  std::cout << "Hello Lenna" << std::endl;
  std::string str_img = "../../img/lenna.jpg";
  cv::Mat mat_srcImg = cv::imread(str_img, cv::IMREAD_UNCHANGED);
  volatile int lvl = 3;

  for(int i = lvl; i >= 0; --i){
    std::cout << "Hello from for" << std::endl;
  }

  if (mat_srcImg.data) {

    cv::Mat mat_imHSV;
    std::vector<cv::Mat> rgb_planes;
    cv::split(mat_srcImg, rgb_planes); // Separates the image into 3 planes (R,G,B)

    cv::cvtColor(mat_srcImg, mat_imHSV, cv::COLOR_BGR2HSV);
    std::vector<cv::Mat> hsv_planes;
    cv::split(mat_imHSV,
              hsv_planes); // Separates the image into 3 planes (R,G,B)

    cv::namedWindow("Lenna Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Lenna Image", mat_srcImg);

    cv::namedWindow("Lenna HSV", cv::WINDOW_AUTOSIZE);
    cv::imshow("Lenna HSV", mat_imHSV);
    cv::waitKey(1500);

    cv::namedWindow("Lenna H", cv::WINDOW_AUTOSIZE);
    cv::imshow("Lenna H", hsv_planes[0]);

    cv::namedWindow("Lenna S", cv::WINDOW_AUTOSIZE);
    cv::imshow("Lenna S", hsv_planes[1]);

    cv::namedWindow("Lenna V", cv::WINDOW_AUTOSIZE);
    cv::imshow("Lenna V", hsv_planes[2]);
  } else
    ret = EXIT_FAILURE;

  cv::waitKey(5000);

  return ret;
}