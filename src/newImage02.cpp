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

    颜色转换：cvtColor(原始图像,目标图像,颜色空间转换标志,目标图像通道数)
    */

    // Mat img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/blackboard.jpg");
    // Mat img32;
    // //0-255转换为0-1
    // img.convertTo(img32, CV_32F, 1 / 255.0, 0);
    // imshow("img", img);

    // // 转换颜色到HSV
    // Mat HSV, HSV32;
    // cvtColor(img, HSV, COLOR_BGR2HSV);
    // imshow("HSV", HSV);
    // cvtColor(img32, HSV32, COLOR_BGR2HSV);

    // // 转换颜色到GRAY,两种方式带入计算灰度图的通道的系数不同
    // Mat gray0, gray1;
    // cvtColor(img, gray0, COLOR_BGR2GRAY);
    // imshow("gray", gray0);
    // cvtColor(img, gray1, COLOR_RGB2GRAY);

    // waitKey(0);

/*--------------------------------------*/
    //图像色彩转换，并过滤图片
    // 图像过滤 inRange(原图像，范围下界，范围上届，输出图像) 二值图像，在范围内的输出255，不再范围内的输出0

    // Mat img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/greenScreen.jpg");
    // Mat hsv, mask;
    // cvtColor(img, hsv, COLOR_BGR2HSV);
    // //在hsv颜色表示中，这个范围内为绿色，提取此范围（因为hsv只有一个是控制颜色的）
    // inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), mask);
    // // imshow("mask", mask);

    // // 换一个红色背景
    // Mat redback = Mat::zeros(img.size(), img.type());
    // redback = Scalar(40, 40, 200);
    // // 将掩膜反转(此时区域内为白色，区域外为黑色)
    // bitwise_not(mask, mask);
    // // 拷贝到红底中，添加mask，只将mask中非0的区域对应的img图像拷贝过去
    // img.copyTo(redback, mask);
    // imshow("redback", redback);

    // waitKey(0);


/*--------------------------------------*/
    //多通道分离和并

    // Mat img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/blackboard.jpg");
    // Mat img32;
    // img.convertTo(img32, CV_32F, 1 / 255.0, 0);

    // Mat gray0, gray1;
    // cvtColor(img, gray0, COLOR_BGR2GRAY);
    // cvtColor(img, gray1, COLOR_RGB2GRAY);

    // //将通道分离
    // Mat imgs[3];
    // split(img, imgs);

    // Mat img0, img1, img2;
    // img0 = imgs[0];
    // img1 = imgs[1];
    // img2 = imgs[2];

    // imshow("split", img0);

    // //将通道合并
    // Mat img_M;
    // merge(imgs, 3, img_M);

    // //查看单一通道的颜色
    // Mat zero = Mat::zeros(Size(img.cols, img.rows), CV_8U);
    // vector<Mat> imgsV;
    // imgsV.push_back(img0);
    // imgsV.push_back(zero);
    // imgsV.push_back(zero);

    // Mat imgVM;
    // merge(imgsV, imgVM);
    // imshow("single", imgVM);

    // waitKey(0);

/*--------------------------------------*/
    //图像通道混合

    // // mixChannels(输入图像数组，输入图像通道数，输出图像数组，输出图像通道数，通道映射关系数组，通道映射关系数组的个数)
    // Mat img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/blackboard.jpg");
    // int from_to[] = {0, 2, 1, 1, 2, 0};
    // Mat dst = Mat::zeros(img.size(), img.type());
    // mixChannels(&img, 1, &dst, 1, from_to, 3);

    // imshow("mix channels", dst);
    // waitKey(0);

/*--------------------------------------*/
    //图像像素比较和统计

    // Mat A;
    // Mat B;
    // Mat Min, Max;
    // //图像比较，可以多通道，对应通道比较，找出小的像素，组合成为Min
    // min(A, B, Min);
    // max(A, B, Max);

    // Mat img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/blackboard.jpg");
    // Mat gray;
    // cvtColor(img, gray, COLOR_BGR2GRAY);
    // //最小最大值参数
    // double minVal, maxVal;
    // //最小最大值坐标
    // Point minLoc, maxLoc;
    // //图像像素最大值和最小值的寻找，只能是单通道图 ,最后一个参数还可以加入掩码矩阵在指定范围内运算（查找是行扫描，找全局第一个最小最大值）
    // minMaxLoc(gray, &minVal, &maxVal, &minLoc, &maxLoc);
    // cout << "minval:" << minVal << ",location:" << minLoc.x << "," << minLoc.y << endl;
    // cout << "maxval:" << maxVal << ",location:" << maxLoc.x << "," << maxLoc.y << endl;

    // //均值和标准差
    // Mat mean, stddev;
    // //mean是均值，stddev是标准差，最后一个参数可以加入mask来计算指定区域内
    // meanStdDev(img, mean, stddev);
    // cout << "means:" << mean << endl;
    // cout << "stddevs:" << stddev << endl;

/*--------------------------------------*/
    //像素逻辑运算规则
    //将十进制转换为8位二进制，再对应与或非运算

    // Mat a = (Mat_<uchar>(1,2) << 0, 5);
    // Mat b = (Mat_<uchar>(1,2) << 0, 6);
    // Mat Xor, Or, Not, And;

    // //最后一个参数可加入mask模版，任何一张图灰度化之后可以当作mask
    // bitwise_not(a, Not);
    // cout << "not a:" << endl << Not << endl;
    // bitwise_and(a, b, And);
    // cout << "a and b:" << endl << And << endl;
    // bitwise_or(a, b, Or);
    // cout << "a or b:" << endl << Or << endl;
    // bitwise_xor(a, b, Xor);
    // cout << "a xor b:" << endl << Xor << endl;


/*--------------------------------------*/
    //像素归一化
    // normalize(输入数组，输出数组，乘法因子/下限，加法因子/上限，归一化类型，输出数据类型（默认-1和输入相同），掩码数组)
    // 归一化类型:所有数组缩放到[0,1]范围内
    // NORM_INF dst = src/max(abs(src))
    // NORM_L1  dst = src/sum(abs(src))
    // NORM_L2  dst = src/sqrt(sum(src^2))
    // NORM_MINMAX  缩放在[a,b]范围  dst = a+(b-a)*(src-min(src))/(max(src)-min(src))

    // Mat img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/blackboard.jpg");
    // Mat dst;
    // cout << img.type() << endl;
    // // 转换为浮点数类型
    // img.convertTo(img, CV_32F);
    // cout << img.type() << endl;
    // // 归一化
    // normalize(img, dst, 0, 1.0, NORM_MINMAX);
    // cout << dst.type() << endl;





    
    return 0;
}