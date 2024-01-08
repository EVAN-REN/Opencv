#include <opencv2/opencv.hpp>
#include <iostream>
#include <unistd.h>

using namespace cv;
using namespace std;

int main(){
    // 图像放缩
    // resize(输入图像，输出图像，输出尺寸，水平放缩，垂直放缩，插值方法)
    // 插值方法：用于确定图像放缩时如何估算新像素值
    // INTER_NEAREST 使用离目标像素最近的一个或多个像素的值，计算速度最快
    // INTER_LINEAR 使用目标像素周围的四个原始像素的值，通过加权平均来计算（默认方法）
    // INTER_CUBIC 使用目标像素周围16个原始像素的值，通过三次多项式计算
    // INTER_AREA 使用像素区域的像素值，适用于缩小图像

    // namedWindow("zoomin", WINDOW_AUTOSIZE);
    // namedWindow("zoomout", WINDOW_AUTOSIZE);
    // Mat img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/blackboard.jpg", COLOR_GRAY2BGR);
    // Mat zoomin, zoomout;
    // int h = img.rows;
    // int w = img.cols;
    // cout << h << w << endl;
    // resize(img, zoomin, Size(), 0.5, 0.5, INTER_LINEAR);
    // imshow("zoomin", zoomin);
    // resize(img, zoomout, Size(w * 1.2, h * 1.2), 0, 0, INTER_LINEAR);
    // imshow("zoomout", zoomout);

    // waitKey(0);


/*--------------------------------------*/
    //图像翻转和旋转

    Mat img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/blackboard.jpg");
    Mat dst1, dst2, M;
    // 第三个参数，>0沿水平方向翻转，=0沿垂直方向翻转，<0同时沿水平和垂直方向翻转
    flip(img, dst1, 0);
    flip(img, dst1, -1);
    flip(img, dst1, 1);
    imshow("flip", dst1);

    // warpAffine用于进行仿生变换的函数，包括平移、旋转、缩放、错切等
    // (输入图像，输出图像，2x3变换矩阵，输出图像尺寸，插值方法，边界模式，边界模式为BORDER_CONSTAN时填充边界常数值)
    int w = img.cols;
    int h = img.rows;
    // 得到变换矩阵(中心位置，旋转角度，放缩大小)
    M = getRotationMatrix2D(Point2f(w / 2, h / 2), 45, 1.0);
    // 计算旋转后的图像大小
    // 得到旋转角度
    double cos = M.at<double>(0,0);
    double sin = M.at<double>(0,1);
    // 计算新的长宽
    int nw = cos * w + sin * h;
    int nh = sin * w + cos * h;
    // 更新新的中心点
    M.at<double>(0,2) += (nw / 2 - w / 2);
    M.at<double>(1,2) += (nh / 2 - h / 2);
    warpAffine(img, dst2, M, Size(nw, nh), INTER_LINEAR, 0, Scalar(255, 0, 0));
    imshow("rotate", dst2);

    waitKey(0);


    return 0;
}