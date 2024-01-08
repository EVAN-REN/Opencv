#include <opencv2/opencv.hpp>
#include <iostream>
#include <unistd.h>

using namespace cv;
using namespace std;

int main(){
    //固定阈值二值化
    /*
    threshold(原图像,二值化后图像,二值化阈值,二值化过程的最大值,图像二值化方法)
    自适应阈值二值化:adaptiveThreshold(原图像（只支持灰度图）,处理后图像,二值化最大值,自适应确定阈值的方法,二值化方法,自适应确定阈值领域大小,从平均值或加权平均值中减去的常数)
    */

    // Mat img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/blackboard.jpg");
    // if(img.empty()){
    //     cout << "fail to load picture" << endl;
    //     return -1;
    // }

    // Mat gray;
    // cvtColor(img, gray, COLOR_BGR2GRAY);
    // Mat img_B, img_B_V, gray_B, gray_B_V, gray_T, gray_T_V, gray_TRUNC;

    // //彩色图像二值化,BINATY是大于阈值为max,小于阈值为min,BINARY_INV是大于阈值为min,小于阈值为max
    // threshold(img, img_B, 125, 255, THRESH_BINARY);
    // threshold(img, img_B_V, 125, 255, THRESH_BINARY_INV);
    // imshow("img_B", img_B);
    // imshow("img_B_V", img_B_V);

    // //灰度图BINARY二值化
    // threshold(gray, gray_B, 125, 255, THRESH_BINARY);
    // threshold(gray, gray_B_V, 125, 255, THRESH_BINARY_INV);
    // imshow("gray_B", gray_B);
    // imshow("gray_B_V", gray_B_V);

    // //灰度图像TOZERO变化,TOZERO是大于阈值不变,小于阈值为min,TOZERO_INV是大于阈值为min,小于阈值不变
    // threshold(gray, gray_T, 125, 255, THRESH_TOZERO);
    // threshold(gray, gray_T_V, 125, 255, THRESH_TOZERO_INV);
    // imshow("gray_T", gray_T);
    // imshow("gray_T_V", gray_T_V);

    // //灰度图像TOZERO变化,TRUNC是大于阈值为阈值，小于阈值不变
    // threshold(gray, gray_TRUNC, 125, 255, THRESH_TRUNC);
    // imshow("gray_TRUNC", gray_TRUNC);

    //灰度图像大津法,和和三角形法二值化
    Mat img_Thr = imread("/Users/ren/Documents/GitHub/Opencv/image/original/threshold.jpg", IMREAD_GRAYSCALE);
    Mat img_Thr_0, img_Thr_T;
    threshold(img_Thr, img_Thr_0, 100, 255, THRESH_BINARY | THRESH_OTSU);
    threshold(img_Thr, img_Thr_T, 120, 255, THRESH_BINARY | THRESH_TRIANGLE);
    imshow("img_Thr", img_Thr);
    imshow("img_Thr_0", img_Thr_0);
    imshow("img_Thr_T", img_Thr_T);

    //自使用阈值二值化(均值法和高斯法)
    Mat adaptive_mean, adaptive_gauss;

    adaptiveThreshold(img_Thr, adaptive_mean, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 55, 0);
    adaptiveThreshold(img_Thr, adaptive_gauss, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 55, 0);
    imshow("adaptive_mean", adaptive_mean);
    imshow("adaptive_gauss", adaptive_gauss);

    waitKey(0);

    return 0;
}