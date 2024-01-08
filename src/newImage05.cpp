#include <opencv2/opencv.hpp>
#include <iostream>
#include <unistd.h>

using namespace cv;
using namespace std;

// Mat img, dst, m;
// int lightness = 50;
// void on_track1(int newValue, void* userdata){
//     //回调函数，增加数值，提高亮度
//     m = Scalar(lightness, lightness, lightness);
//     dst = img + m;
//     imshow("lightness change", dst);
// }

void on_track2(int newValue, void* image){
    //得到的空指针类型转换为mat指针类并取出地址中的data
    Mat img = *(Mat*)image;
    Mat m = Mat::zeros(img.size(), img.type());
    Mat dst;
    if(newValue > 100){
        int l = newValue - 100;
        m = Scalar(l, l, l);
        dst = img + m;
    }else{
        int l = 100 - newValue;
        m = Scalar(l, l, l);
        dst = img - m;
    }
    imshow("lightness change", dst);
}

void on_lightness(int newValue, void* image){
    Mat img = *(Mat*)image;
    Mat m = Mat::zeros(img.size(), img.type());
    Mat dst;
    //增加权重 addWeighted(图1，占比，图2，占比，偏移值，目标图像)
    //这里图二不占比例
    addWeighted(img, 1.0, m, 0, (newValue - 100), dst);
    imshow("change", dst);
}

void on_contrast(int newValue, void* image){
    Mat img = *(Mat*)image;
    Mat m = Mat::zeros(img.size(), img.type());
    Mat dst;
    double contrast = newValue / 100.0;
    addWeighted(img, contrast, m, 0, 0, dst);
    imshow("change", dst);
}

int main(){
    //滚动条trackbar

    // img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/blackboard.jpg");
    // namedWindow("lightness change", WINDOW_AUTOSIZE);
    // dst = Mat::zeros(img.size(), img.type());
    // m = Mat::zeros(img.size(), img.type());
    // int max_value = 100;
    // //滚动条创建(滚动条名字，窗口名，滚动条数值地址，滚动条最大值，当滚动条发生改变时回调函数)
    // createTrackbar("Value Bar", "lightness change", &lightness, max_value, on_track1);
    // on_track1(50, 0);

    // waitKey(0);

/*--------------------------------------*/
    //优化滚动条,使其可以变亮或变暗，并不是用全局变量

    // Mat img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/blackboard.jpg");
    // namedWindow("lightness change", WINDOW_AUTOSIZE);
    // int max_value = 200;
    // int lightness = 100;
    // //回调函数后面传入图像指针地址并转换为空指针类型
    // createTrackbar("Value Bar", "lightness change", &lightness, max_value, on_track2, (void*)(&img));
    // on_track2(100, &img);

    // waitKey(0);

/*--------------------------------------*/
    //添加对比度

    Mat img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/blackboard.jpg");
    namedWindow("change", WINDOW_AUTOSIZE);
    int max_value = 200;
    int lightness = 100;
    int contrast = 100;
    createTrackbar("Value Bar", "change", &lightness, max_value, on_lightness, (void*)(&img));
    createTrackbar("Contrast Bar", "change", &contrast, 200, on_contrast, (void*)(&img));
    on_lightness(100, &img);

    waitKey(0);

    return 0;
}