#include <opencv2/opencv.hpp>
#include <iostream>
#include <unistd.h>

using namespace cv;
using namespace std;

int main(){
    //图像颜色模型
    /*
    rgb:红绿蓝（数据类型有8U(0-255),float(0-1),double(0-1)）
    数据类型转换:a.convertTo(转换mat,转换后数据类型,缩放系数,平移系数)
    HSV:色度，饱和度，亮度
    GRAY:灰度图，rgb模型转换为灰度图的关系（不可逆）：Gray = R * 0.3 + G * 0.59 + B * 0.11
    */



    return 0;
}