#include <opencv2/opencv.hpp>
#include <iostream>
#include <unistd.h>

using namespace cv;
using namespace std;

int main(){
    Mat img = imread("/Users/ren/Documents/GitHub/Opencv/image/new/g1.jpg");
    

    Mat hsv, mask1, mask2;
    cvtColor(img, hsv, COLOR_RGB2HSV);
    inRange(hsv, Scalar(100, 43, 46), Scalar(124, 255, 255), mask1);
    inRange(hsv, Scalar(0, 0, 0), Scalar(180, 255, 46), mask2);

    Mat back = imread("/Users/ren/Documents/GitHub/Opencv/image/new/beach.png");
    resize(back, back, img.size(), 0, 0, INTER_LINEAR);
    // bitwise_not(mask, mask);
    imshow("test", mask1);
    imshow("test2", mask2);
    mask1 = mask1 + mask2;
    threshold(mask1, mask1, 120, 255, THRESH_BINARY);
    img.copyTo(back, mask1);

    imshow("new", back);

    waitKey(0);
    return 0;
}