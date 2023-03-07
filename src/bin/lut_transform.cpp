#include <iostream>

#include <opencv2/opencv.hpp>

template<typename Callable>
void transform_function (cv::Mat& mat_tf,Callable f)//std::function<uchar(int)> f
{
    for (int i = 0; i < mat_tf.cols; ++i)
    {
        mat_tf.at<uchar>(i) = f(i);
    }
    
}

int main( int argc, char** argv )
{
    int ret = EXIT_SUCCESS;
    std::cout << "Hello Lenna" << std::endl;
    std::string str_img = "../../img/lenna.jpg";
    cv::Mat mat_Image = cv::imread(str_img);
    std::vector<cv::Mat> lut_transform;
    std::vector<cv::Mat> Img_transform;
    
    for (size_t i = 0; i < 3u; ++i)
    {
        lut_transform.push_back(cv::Mat(1,256,CV_8U));
        Img_transform.push_back(mat_Image.clone());
    }
    
    transform_function(lut_transform[0], [](const int x) -> uchar { return 255 - x; } );
    transform_function(lut_transform[1], [](const int x) -> uchar { return pow((float)x * 255,(1/2.0)); } );
    transform_function(lut_transform[2], [](const int x) -> uchar { return pow((float)x, 3.0) / (255*255); } );

    cv::LUT(mat_Image, lut_transform[0], Img_transform[0]);
    cv::LUT(mat_Image, lut_transform[1], Img_transform[1]);
    cv::LUT(mat_Image, lut_transform[2], Img_transform[2]);

    if (mat_Image.data) {
        
        cv::namedWindow("Lenna Image", cv::WINDOW_AUTOSIZE);
        cv::imshow("Lenna Image", mat_Image);

        cv::namedWindow("Lenna Inv", cv::WINDOW_AUTOSIZE);
        cv::imshow("Lenna Inv", Img_transform[0]);

        cv::namedWindow("Lenna Sqr", cv::WINDOW_AUTOSIZE);
        cv::imshow("Lenna Sqr", Img_transform[1]);

        cv::namedWindow("Lenna Cubic", cv::WINDOW_AUTOSIZE);
        cv::imshow("Lenna Cubic", Img_transform[2]);
    }
    else
        ret = EXIT_FAILURE;

    cv::waitKey(0);

    return ret;
}