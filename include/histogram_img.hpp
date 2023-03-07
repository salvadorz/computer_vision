/*
 * @histogram_img.hpp
 *
 * @version: 1.0
 * @Author:  Salvador Z
 * @brief:   Generates an Histogram Image of each Component (B,G,R)
 */

#ifndef HISTOGRAM_IMG_HPP_
#define HISTOGRAM_IMG_HPP_

#include <opencv2/core/mat.hpp>

/// @brief Receives a 
/// @param mat_Img to calculate the histogram and returns and image with
/// @param width and
/// @param height to be displayed
/// @return 
cv::Mat Histogram_Img(const cv::Mat& mat_Img, const int width, const int height);

#endif // HISTOGRAM_IMG_HPP_