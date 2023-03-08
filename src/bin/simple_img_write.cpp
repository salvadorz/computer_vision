#include <iostream>

#include <opencv2/opencv.hpp>

int main( int argc, char** argv )
{
    int ret = EXIT_SUCCESS;
    std::cout << "Hello Lenna" << std::endl;
    std::string str_img = "../../img/lenna.jpg";
    cv::Mat mat_Image = cv::imread(str_img);
    if (mat_Image.data) {
        for (int i = mat_Image.rows / 4; i < 3*mat_Image.rows / 4; ++i)
            for (int j = mat_Image.cols / 4; j < 3*mat_Image.cols / 4; ++j){
                mat_Image.at<cv::Vec3b>(cv::Point(i,j)) = cv::Vec3b((i*j)%255,((255-j)*i)%255,(i+j)%255);
            }
        cv::namedWindow("Lenna Image", cv::WINDOW_AUTOSIZE);
        cv::imshow("Lenna Image", mat_Image);
    }
    else
        ret = EXIT_FAILURE;

    cv::waitKey(0);

    return ret;
}