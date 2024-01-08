#include <opencv2/opencv.hpp>
#include <iostream>
#include <unistd.h>

using namespace cv;
using namespace std;

int main(){
    Mat img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/blackboard.jpg");

    //图像一维直方图

    // // 三通道分离
    // vector<Mat> bgr_plane;
    // split(img, bgr_plane);
    // // 定义参数变量
    // const int channels[1] = {0};
    // const int bins[1] = {256};
    // float hranges[2] = {0,255};
    // const float* ranges[1] = {hranges};
    // Mat b_hist;
    // Mat g_hist;
    // Mat r_hist;
    // // 计算Blue, Green, Red通道的直方图
    // // 用于计算图像直方图的函数 calcHist(图像数组，图像数量，通道索引的数组，掩码图像，输出直方图，直方图维度，每个维度bin数，每个维度像素值范围，是否保证每个bin宽度相同，是否累计直方图)
    // // 得到的结果是一个一维数组或矩阵，记录每个像素的分布个数
    // calcHist(&bgr_plane[0], 1, 0, Mat(), b_hist, 1, bins, ranges);
    // calcHist(&bgr_plane[1], 1, 0, Mat(), g_hist, 1, bins, ranges);
    // calcHist(&bgr_plane[2], 1, 0, Mat(), r_hist, 1, bins, ranges);
    // // 显示直方图
    // int hist_w = 512;
    // int hist_h = 400;
    // // 四舍五入,每个像素在直方图上占的宽度
    // int bin_w = cvRound((double)hist_w / bins[0]);
    // // 生成画布
    // Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
    // // 归一化直方图数据，计算每个分布像素按比例归一化到画布高度上
    // normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    // normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    // normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    // // 绘制直方图曲线
    // for(int i = 1; i < bins[0]; i++){
    //     line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))), Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 2, LINE_8, 0);
    //     line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))), Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 2, LINE_8, 0);
    //     line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))), Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 2, LINE_8, 0);
    // }
    // // 显示直方图
    // namedWindow("Histogram", WINDOW_AUTOSIZE);
    // imshow("Histogram", histImage);

    // waitKey(0);


/*--------------------------------------*/
    //二维直方图
    
    // Mat hsv, hs_hist;
    // // 转换为hsv颜色,h和s共同控制颜色，h处于0-180，s处于0-255
    // cvtColor(img, hsv, COLOR_BGR2HSV);
    // // 代表h的每个bin整合了30个像素,s也是
    // int hbins = 30, sbins = 32;
    // // 每个维度像素数
    // int hist_bins[] = {hbins, sbins};
    // float h_range[] = {0, 180};
    // float s_range[] = {0, 256};
    // // 每个维度像素值范围
    // const float* hs_range[] = {h_range, s_range};
    // // 通道索引的数组
    // int hs_channel[] = {0, 1};
    // // 计算直方图数据
    // calcHist(&hsv, 1, hs_channel, Mat(), hs_hist, 2, hist_bins, hs_range, true, false);
    // double maxVal = 0;
    // // 找到最大值
    // minMaxLoc(hs_hist, 0, &maxVal, 0, 0);
    // // 每个bin的宽度
    // int scale = 10;
    // // 画布
    // Mat hist2d_image = Mat::zeros(sbins * scale, hbins * scale, CV_8UC3);
    // for(int h = 0; h < hbins; h++){
    //     for(int s = 0; s < sbins; s++){
    //         float binVal = hs_hist.at<float>(h,s);
    //         // 转换为颜色来代表个数的大小
    //         int intensity = cvRound(binVal * 255 / maxVal);
    //         // 绘制二维直方图
    //         rectangle(hist2d_image, Point(h * scale, s * scale), Point((h + 1) * scale -1, (s + 1) * scale -1), Scalar::all(intensity), -1);
    //     }
    // }
    // imshow("H-S Histogram", hist2d_image);

    // waitKey(0);


/*--------------------------------------*/
    // 直方图均衡化
    // 将直方图分成几段，求出每一段的累积分布，将原本对应的每段重新映射成总值与对应累积分布的乘积

    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    Mat dst;
    // 直方图均衡化，只能用于单通道
    equalizeHist(gray, dst);
    imshow("equalization", dst);

    waitKey(0);
    return 0;
}