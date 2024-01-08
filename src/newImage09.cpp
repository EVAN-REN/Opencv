#include <iostream>
#include <opencv2/opencv.hpp>
#include <unistd.h>

using namespace cv;
using namespace std;

int main(){
    Mat img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/face.jpg");

    //图像卷积

    // Mat dst;
    // // 函数用于对图像进行平均模糊（均值滤波）。平均模糊是一种基本的图像平滑技术，它通过计算图像中每个像素周围邻域的平均值来模糊图像，从而降低图像的噪声并模糊图像的细节。
    // // (输入图像，输出图像，模糊核大小(可以支持水平或垂直一维模糊)，核中心点(-1,-1表示中心)，边界模式)
    // blur(img, dst, Size(31,31), Point(-1, -1));
    // imshow("blur", dst);
    // waitKey(0);


/*--------------------------------------*/
    // 高斯模糊
    // 使用的模糊核是越靠近中心，占比越大

    // Mat dst;
    // // (输入图像，输出图像，高斯核大小(当设置为0时，方法能从标准差反算核大小)，高斯核在x方向上的标准差(决定滤波的强度)，在y上的标准差，边界模式)
    // GaussianBlur(img, dst, Size(11,11), 15);
    // imshow("GaussianBlur", dst);
    // waitKey(0);


/*--------------------------------------*/
    // 高斯双边模糊
    // 既考虑空间相似性，离模糊核中心越大权重越大，也考虑rgb颜色相似性，差异越大权重越小

    Mat dst;
    // (输入图像，输出图像，滤波器直径，颜色空间标准差，空间坐标标准差，边界模式)
    bilateralFilter(img, dst, 0, 90, 5);
    imshow("bilateralFilter", dst);
    waitKey(0);

    return 0;
}