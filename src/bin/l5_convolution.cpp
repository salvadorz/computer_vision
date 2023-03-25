#include <iostream>

#include <opencv2/opencv.hpp>

int main(int argc, char **argv)
{
    int ret = EXIT_SUCCESS;
    std::cout << "Hello Lenna" << std::endl;
    std::string str_img = "../../img/lenna.jpg";
    cv::Mat mat_Image = cv::imread(str_img);

    if (mat_Image.data)
    {
        cv::Mat mat_Convoluted;
        cv::Mat mat_Kernel;

        mat_Kernel = cv::Mat::ones(5, 5, CV_32F) / (float)(5 * 5);
        cv::filter2D(mat_Image, mat_Convoluted, -1, mat_Kernel, cv::Point(-1, -1), 0, cv::BORDER_DEFAULT);
        cv::namedWindow("Lenna Image", cv::WINDOW_AUTOSIZE);
        cv::imshow("Lenna Image", mat_Image);

        cv::namedWindow("Lenna Conv Image", cv::WINDOW_AUTOSIZE);
        cv::imshow("Lenna Conv Image", mat_Convoluted);
    }
    else
        ret = EXIT_FAILURE;

    cv::waitKey(0);

    return ret;
}