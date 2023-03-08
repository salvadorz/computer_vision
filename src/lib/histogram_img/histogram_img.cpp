
#include "histogram_img.hpp"

#include <opencv2/opencv.hpp>

cv::Mat Histogram_Img(const cv::Mat& mat_Img, const int width, const int height){
    cv::Mat mat_histImage(height,width, CV_8UC3, cv::Scalar(0,0,0));

    if (mat_Img.data) {
        std::vector<cv::Mat> rgb_planes;
        cv::split(mat_Img, rgb_planes); //Separates the image into 3 planes (R,G,B)

        unsigned int int_histSz = 256;
        // Ranges RGB
        float range[] = {0, 256};
        const float* histRange = {range};

        bool uniform = true;
        bool accumulate = false;

        cv::Mat r_hist, g_hist, b_hist;

        //Calculate the histogram 
        //calcHist(const cv::Mat *images, int nimages, const int *channels, cv::InputArray mask, cv::SparseMat &hist, int dims, const int *histSize, const float **ranges, bool uniform = true, bool accumulate = false)
        //mask=Mat() so is a empty mask. 
        cv::calcHist(&rgb_planes[0], 1, 0, cv::Mat(), b_hist, 1 ,&int_histSz, &histRange, uniform, accumulate);
        cv::calcHist(&rgb_planes[1], 1, 0, cv::Mat(), g_hist, 1 ,&int_histSz, &histRange, uniform, accumulate);
        cv::calcHist(&rgb_planes[2], 1, 0, cv::Mat(), r_hist, 1 ,&int_histSz, &histRange, uniform, accumulate);

        const int bin_w = cvRound((double)width / height);

        cv::normalize(r_hist, r_hist, 0, mat_histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
        cv::normalize(g_hist, g_hist, 0, mat_histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
        cv::normalize(b_hist, b_hist, 0, mat_histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );

        for (size_t i = 1; i < int_histSz; ++i) {
            cv::line(mat_histImage, 
                cv::Point(bin_w*(i-1), height - cvRound(b_hist.at<float>(i-1))),
                cv::Point(bin_w*(i)  , height - cvRound(b_hist.at<float>(i))),
                cv::Scalar(255,0,0),2, 8, 0);

            cv::line(mat_histImage,
                cv::Point(bin_w*(i-1), height - cvRound(g_hist.at<float>(i-1))),
                cv::Point(bin_w*(i)  , height - cvRound(g_hist.at<float>(i))),
                cv::Scalar(0,255,0),2, 8, 0);

            cv::line(mat_histImage,
                cv::Point(bin_w*(i-1), height - cvRound(r_hist.at<float>(i-1))),
                cv::Point(bin_w*(i),   height - cvRound(r_hist.at<float>(i))),
                cv::Scalar(0,0,255),2, 8, 0);
        }
    }
    return mat_histImage;

}