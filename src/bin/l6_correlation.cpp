#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"

/*CV_TM_SQDIFF(_NORMED), CV_TM_CCORR(_NORMED), CV_TM_CCOEFF(_NORMED) */
constexpr short method_max{6};

int main()
{
    int ret = EXIT_SUCCESS;

    std::string str_image = "../../img/base_brd.tif";
    std::string str_model = "../../img/model.tif";
    std::string methods_map[method_max] = {
        "SQDIFF",
        "SQDIFF_NORMED",
        "CCORR",
        "CCORR_NORMED",
        "CCOEFF",
        "CCOEFF_NORMED"};

    cv::Mat mat_Image = cv::imread(str_image);
    cv::Mat mat_Model = cv::imread(str_model);

    if (mat_Image.data && mat_Model.data)
    {
        cv::Mat mat_Method_Img[method_max];
        int iwdth;
        int ihght;

        // Reserve memory for each method
        iwdth = mat_Image.cols - mat_Model.cols + 1;
        ihght = mat_Image.rows - mat_Model.rows + 1;

        for (int i = 0; i < method_max; ++i)
            mat_Method_Img[i].create(ihght, iwdth, CV_32SC1);

        // Correlation
        for (int i = 0; i < method_max; ++i)
        {
            cv::matchTemplate(mat_Image, mat_Model, mat_Method_Img[i], i);
            cv::normalize(mat_Method_Img[i], mat_Method_Img[i], 1, 0, cv::NORM_MINMAX);
        }
        cv::namedWindow("Model", cv::WINDOW_AUTOSIZE);
        cv::imshow("Model", mat_Model);

        cv::namedWindow("Image", cv::WINDOW_AUTOSIZE);
        cv::imshow("Image", mat_Image);

        for (int i = 0; i < method_max; ++i)
        {
            cv::namedWindow(methods_map[i], cv::WINDOW_AUTOSIZE);
            cv::imshow(methods_map[i], mat_Method_Img[i]);
            cv::waitKey(3000);
        }
    }
    else
        ret = EXIT_FAILURE;

    cv::waitKey(0);

    return ret;
}