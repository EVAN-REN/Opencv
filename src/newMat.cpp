#include <opencv2/opencv.hpp>
#include <iostream>
#include <unistd.h>

using namespace cv;
using namespace std;

int main(){
    // Mat类的创建

    // //利用长宽高定义,8uc1代表8位无符号数通道1
    // Mat a(3, 3, CV_8UC1);

    // //类用矩阵size定义
    // Mat b(Size(4, 4), CV_8UC1);

    // //创建时给每个通道赋值
    // Mat c0(5, 5, CV_8UC1, Scalar(4, 5, 6));
    // Mat c1(5, 5, CV_8UC2, Scalar(4, 5, 6));
    // Mat c2(5, 5, CV_8UC3, Scalar(4, 5, 6));

    // //枚举法赋值
    // Mat d = (cv::Mat_<int>(1, 5) << 1, 2, 3, 4, 5);

    // //创建一个对角矩阵
    // Mat e = Mat::diag(d);

    // //截取某一矩阵中部分，这里截取行为3-4，列3-4
    // Mat f = Mat(e, Range(2, 4), Range(2, 4));

    // cout << c0 << endl;
    // cout << c1 << endl;
    // cout << c2 << endl;
    // cout << d << endl;
    // cout << e << endl;
    // cout << f << endl;

/*--------------------------------------*/
    // Mat类中数据的提取

    // Mat a = (cv::Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);

    // Mat c0(5, 5, CV_8UC1, Scalar(4, 5, 6));
    // Mat c1(5, 5, CV_8UC2, Scalar(4, 5, 6));
    // Mat c2(5, 5, CV_8UC3, Scalar(4, 5, 6));

    // cout << a.at<int>(0, 0) << endl;
    // //2b代表双通道uchar类型
    // Vec2b vc = c1.at<Vec2b>(0, 1);
    // cout << vc << endl;
    // cout << (int)vc[0] << endl;
    // cout << (double)(*(c2.data + c2.step[0] * 2 + c2.step[1] * 2 + 3)) << endl;;
    // cout << vc[1] << endl;

/*--------------------------------------*/
    //矩阵的四则运算

    Mat a = (cv::Mat_<int>(3,3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
    Mat b = (cv::Mat_<int>(3,3) << 1, 2, 3, 7, 8, 9, 4, 5, 6);
    Mat c = (cv::Mat_<double>(3,3) << 1.0, 2.1, 3.2, 4.0, 5.1, 6.2, 2, 2, 2);
    Mat d = (cv::Mat_<double>(3,3) << 1.0, 2.1, 3.2, 4.0, 5.1, 6.2, 2, 2, 2);

    cout << "两个矩阵的和=" << endl << a + b << endl;
    cout << "两个矩阵的差=" << endl << c - d << endl;
    cout << "矩阵数乘=" << endl << 2 * a << endl;
    cout << "矩阵数除=" << endl << d / 2.0 << endl;
    cout << "矩阵减数=" << endl << a - 1 << endl;

    cout << "两矩阵相乘=" << endl << c * d << endl;
    cout << "矩阵内积=" << endl << a.dot(b) << endl;
    cout << "矩阵对应位相乘=" << endl << a.mul(b) << endl;

    cout << "两个矩阵最小值=" << endl << min(a, b) << endl;

    return 0;
}