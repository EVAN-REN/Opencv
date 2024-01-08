#include <opencv2/opencv.hpp>
#include <iostream>
#include <unistd.h>
#include <random>

using namespace cv;
using namespace std;

int main(){
    //颜色表变化

    // // opencv提供的颜色风格
    // int colormap[] = {
    //     cv::COLORMAP_AUTUMN,
    //     cv::COLORMAP_BONE,
    //     cv::COLORMAP_JET,
    //     cv::COLORMAP_WINTER,
    //     cv::COLORMAP_RAINBOW,
    //     cv::COLORMAP_OCEAN,
    //     cv::COLORMAP_SUMMER,
    //     cv::COLORMAP_SPRING,
    //     cv::COLORMAP_COOL,
    //     cv::COLORMAP_HSV,
    //     cv::COLORMAP_PINK,
    //     cv::COLORMAP_HOT,
    //     cv::COLORMAP_PARULA,
    //     cv::COLORMAP_MAGMA,
    //     cv::COLORMAP_INFERNO,
    //     cv::COLORMAP_PLASMA,
    //     cv::COLORMAP_VIRIDIS,
    //     cv::COLORMAP_CIVIDIS,
    //     cv::COLORMAP_TWILIGHT,
    //     cv::COLORMAP_TWILIGHT_SHIFTED,
    //     cv::COLORMAP_TURBO,
    //     cv::COLORMAP_DEEPGREEN
    // };

    // Mat img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/blackboard.jpg");
    // Mat dst;
    // int index = 0;
    // while(true){
    //     int c = waitKey(500);
    //     if(c == 27){
    //         break;
    //     }
    //     applyColorMap(img, dst, colormap[index % 22]);
    //     index++;
    //     imshow("colormap", dst);
    // }

/*--------------------------------------*/
    //图形绘制
    
    // //矩形 rectangle(要绘制的图，矩形左上角，矩形高和宽，颜色，厚度/填充，线的类型，偏移量)
    // Mat img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/threshold.jpg");
    // Mat m1 = Mat::zeros(img.size(), img.type());
    // // Rect r;
    // // r.x = 50;
    // // r.y = 50;
    // // r.height = 100;
    // // r.width = 100;
    // rectangle(m1, Rect(500, 500, 1500, 1500), Scalar(255, 255, 0), -1, LINE_4);

    // //圆 circle(绘制图像，圆心，半径，颜色，厚度/填充，线的类型，偏移量)
    // circle(m1, Point(1000, 2000), 500, Scalar(255, 0, 0), -1, LINE_8);

    // //线 line(绘制图像，起始顶点，结束顶点，颜色，厚度，线的类型，偏移量)
    // line(m1, Point(500, 500), Point(2000, 2000), Scalar(0, 0, 255), 50, LINE_8);

    // // 椭圆 circle(绘制图像，椭圆参数，颜色，厚度/填充，线的类型，偏移量)
    // RotatedRect rrt;
    // rrt.center = Point(1000, 1000);
    // //椭圆两个轴的长度
    // rrt.size = Size(500, 1000);
    // //椭圆旋转角度
    // rrt.angle = 90.0;
    // ellipse(m1, rrt, Scalar(0, 255, 255), -1, LINE_8);

    // Mat dst;
    // addWeighted(img, 0.7, m1, 0.3, 0, dst);
    // imshow("addweight", dst);

    // waitKey(0);


/*--------------------------------------*/
    // 图形随机绘制

    // 生成随机数种子
    // random_device rd;
    // 通过种子生成一个确定性序列
    // mt19937 eng(rd());
    // 生成一个证书均匀分布器
    // uniform_int_distribution<> uniform(1, 6);
    // int x = uniform(eng);

    // Mat canvas = Mat::zeros(Size(512, 512), CV_8UC3);
    // int w = canvas.cols;
    // int h = canvas.rows;
    // //生成随机数
    // RNG rng(12345);
    // while(true){
    //     int c = waitKey(100);
    //     if(c == 27){
    //         break;
    //     }
    //     int x1 = rng.uniform(0, w);
    //     int y1 = rng.uniform(0, h);
    //     int x2 = rng.uniform(0, w);
    //     int y2 = rng.uniform(0, h);
    //     int b = rng.uniform(0, 255);
    //     int g = rng.uniform(0, 255);
    //     int r = rng.uniform(0, 255);
    //     line(canvas, Point(x1, y1), Point(x2, y2), Scalar(b, g, r), 3, LINE_8);
    //     // 清空画布
    //     // canvas = Scalar(0, 0, 0);
    //     imshow("random", canvas);
    // }
    

/*--------------------------------------*/
    // 多边形绘制和填充

    Mat canvas = Mat::zeros(Size(512, 512), CV_8UC3);
    vector<Point> points;
    points.push_back(Point(100, 100));
    points.push_back(Point(350, 100));
    points.push_back(Point(450, 280));
    points.push_back(Point(320, 450));
    points.push_back(Point(80, 400));
    // 绘制多边形  polylines(画布，点集，闭包，颜色，线粗，线类型，偏移量 )，线粗不能用-1填充
    polylines(canvas, points, true, Scalar(0, 0, 255), 2, LINE_8);
    // 填充多边形
    fillPoly(canvas, points, Scalar(255, 0, 0), LINE_8);
    // 绘制轮廓，可以绘制多个多边形，第三个参数是绘制的多边形的索引，-1代表绘制所有，第五个参数可以用-1代表填充
    vector<vector<Point>> contours;
    contours.push_back(points);
    drawContours(canvas, contours,  -1, Scalar(0, 255, 0), -1, LINE_8);
    imshow("polygon", canvas);

    waitKey(0);


    return 0;
}
