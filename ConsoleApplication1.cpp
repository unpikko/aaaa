//#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    //cv::Mat img = cv::imread("aaa.png", -1);
    //cv::Mat img = cv::imread("aaa.png", -1);
    cv::Mat img = cv::imread("aaa.png",  -1);
    if (img.empty()) {
        return -1;
    }

    int Y = img.rows;
    int X = img.cols;
    int x, y;
    int B, G, R, P;
    for (y = 0; y < Y; y++) {
        for (x = 0; x < X; x++) {
            B = img.at < cv::Vec3b>(y, x)[0];
            G = img.at < cv::Vec3b>(y, x)[1];
            R = img.at < cv::Vec3b>(y, x)[2];
            P = (B + G + R) / 3;
            int p = P;

            if (P > 100 && P < 130) p = 255;
            if (P > 90) p = 255;
            img.at<cv::Vec3b>(y, x)[0] = p;
            img.at<cv::Vec3b>(y, x)[1] = p;
            img.at<cv::Vec3b>(y, x)[2] = p;

        }
    }


    cv::imwrite("aaa2.png", img);

    cv::namedWindow("Example", cv::WINDOW_AUTOSIZE);
    cv::imshow("Example", img);
    cv::waitKey(0);
    cv::destroyWindow("Example");
    return 0;
}
