#include <iostream>

#include <opencv2/opencv.hpp>
#include "histogram_img.hpp"

int main( int argc, char** argv )
{
    int ret = EXIT_SUCCESS;
    std::cout << "Hello Lenna" << std::endl;
    std::string str_img = "../../img/lenna.jpg";
    cv::Mat mat_srcImg = cv::imread(str_img, cv::IMREAD_UNCHANGED);

    if (mat_srcImg.data) {
        
        cv::Mat mat_histImage = Histogram_Img(mat_srcImg, 512, 400);

        cv::namedWindow("Lenna Image", cv::WINDOW_AUTOSIZE);
        cv::imshow("Lenna Image", mat_srcImg);

        cv::namedWindow("Histogram", cv::WINDOW_AUTOSIZE);
        cv::imshow("Histogram", mat_histImage);
    }
    else
        ret = EXIT_FAILURE;

    cv::waitKey(0);

    return ret;
}