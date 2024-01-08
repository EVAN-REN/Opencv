#include <opencv2/opencv.hpp>
#include <iostream>
#include <unistd.h>

using namespace cv;
using namespace std;

int main(){
    //掩膜操作实现图像对比度调整
    // I(i,j) = 5 * I(i,j) - [I(i-1,j) + I(i+1,j) + I(i,j+1) + I(i,j-1)]
    // 饱和转换模版函数：确保rgb值范围在0-255之间 saturate_cast<uchar>()
    // Mat img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/blackboard.jpg");

    // if(!img.data){
    //     cout << "could not load image" << endl;
    //     return -1;
    // }
    // namedWindow("image", WINDOW_AUTOSIZE);
    // imshow("image", img);

    // //掩膜操作后图像
    // Mat dst = Mat(img.size(), img.type());
    // //图像宽度，通道是列展开的
    // int cols = img.cols * img.channels();
    // int offsetx = img.channels();
    // //图像高度
    // int rows = img.rows;
    // for(int row = 1; row < rows - 1; row++){
    //     //提取上下的行指针
    //     const uchar* current = img.ptr<uchar>(row);
    //     const uchar* previous = img.ptr<uchar>(row - 1);
    //     const uchar* next = img.ptr<uchar>(row + 1);
    //     //行结果
    //     uchar* output = dst.ptr<uchar>(row);
    //     //变化每一通道的左右列
    //     for(int col = offsetx; col < cols; col++){
    //         // 饱和转换
    //         output[col] = saturate_cast<uchar>(5 * current[col] - (current[col - offsetx] + current[col + offsetx] + previous[col] + next[col]));
    //     }
    // }

    // double t = getTickCount();
    // //将上操作替换成掩膜操作
    // //膜矩阵
    // Mat mask = (Mat_<char>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    // // 掩膜操作
    // filter2D(img, dst, img.depth(), mask);
    // double timeconsume = (getTickCount() - t) / getTickFrequency();
    // cout << "time consume " << timeconsume << endl;

    // namedWindow("contrast image demo", WINDOW_AUTOSIZE);
    // imshow("contrast image demo", dst);

    // waitKey(0);

/*--------------------------------------*/
    //图像反相
    Mat img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/blackboard.jpg");
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);

    int w = img.cols;
    int h = img.rows;
    int dim = img.channels();
    // int dim = gray.channels();

    // for(int row = 0; row < h; row++){
    //     for(int col = 0; col < w; col++){
    //         if(dim == 1){ // 灰度图
    //             int pv = img.at<uchar>(row, col);
    //             img.at<uchar>(row, col) = 255 - pv;
    //         }else if(dim == 3){ // 彩色图
    //             Vec3b bgr = img.at<Vec3b>(row, col);
    //             img.at<Vec3b>(row, col)[0] = 255 - bgr[0];
    //             img.at<Vec3b>(row, col)[1] = 255 - bgr[1];
    //             img.at<Vec3b>(row, col)[2] = 255 - bgr[2];
    //         }
    //     }
    // }
    //用指针获取
    for(int row = 0; row < h; row++){
        uchar* current_row = img.ptr<uchar>(row);
        for(int col = 0; col < w; col++){
            if(dim == 1){ // 灰度图
                *current_row++ = 255 - *current_row;
            }else if(dim == 3){ // 彩色图
                *current_row++ = 255 - *current_row;
                *current_row++ = 255 - *current_row;
                *current_row++ = 255 - *current_row;
            }
        }
    }
    
    imshow("show", img);
    waitKey(0);


    return 0;
}