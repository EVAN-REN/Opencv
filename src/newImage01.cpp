#include <opencv2/opencv.hpp>
#include <iostream>
#include <unistd.h>

using namespace cv;
using namespace std;

int main(){
    //图像加载

    // //以彩色读取
    // Mat img;
    // img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/blackboard.jpg", IMREAD_COLOR);
    // //以灰色读取
    // Mat gray = imread("/Users/ren/Documents/GitHub/Opencv/image/original/blackboard.jpg", IMREAD_GRAYSCALE);

    // //创建可变化窗口
    // namedWindow("img", WINDOW_AUTOSIZE);
    // //创建自适应窗口
    // namedWindow("gray", WINDOW_NORMAL);

    // // 显示图片
    // imshow("img", img);
    // imshow("gray", gray);

    // //定义压缩形式
    // // vector<int> compression_params;
    // // compression_params.push_back(IMWRITE_PNG_COMPRESSION);
    // // compression_params.push_back(9);

    // //保存图像,采用默认值
    // imwrite("/Users/ren/Documents/GitHub/Opencv/image/new/newpic01.jpg", img);

    // //等待推退出
    // cv::waitKey(0);

/*--------------------------------------*/
    //视频加载/摄像头调用

    // //获取视频
    // VideoCapture video;
    // //获取视频文件
    // // video.open("/Users/ren/Documents/GitHub/Opencv/video/car.mp4");
    // //获取摄像头
    // video.open(0);
    // if(!video.isOpened()){
    //     cout << "please cheak the resource of video or camera" << endl;
    //     return -1;
    // }

    // //获取视频帧率
    // cout << "FPS:" << video.get(CAP_PROP_FPS) << endl;;
    // // 获取视频宽度
    // cout << "width:" << video.get(CAP_PROP_FRAME_WIDTH) << endl;;

    // // 播放视频
    // while(1){
    //     Mat frame;
    //     video >> frame;
    //     if(frame.empty()){
    //         break;
    //     }
    //     imshow("video", frame);

    //     //控制视频播放时的关闭
    //     uchar c = waitKey(1000 / video.get(CAP_PROP_FPS));
    //     if(c == 'q'){
    //         break;
    //     }
    // }

/*--------------------------------------*/
    //视频图像保存

    VideoCapture video(0);
    if(!video.isOpened()){
        cout << "camera error" << endl;
        return -1;
    }

    Mat img;
    video >> img;
    if(img.empty()){
        cout << "can't get image" << endl;
        return -1;
    }

    //判断相机是否为彩色
    bool isColor = (img.type() == CV_8UC3);

    VideoWriter writer;
    //选择视频编码格式
    // int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
    int codec = VideoWriter::fourcc('H', '2', '6', '4');

    //设置视频频率
    double fps = 25.0;

    //保存视频名称
    string filename = "/Users/ren/Documents/GitHub/Opencv/video/camera01.mp4";
    //创建保存视频文件的视频流
    writer.open(filename, codec, fps, img.size(), isColor);

    //判断视频流创建是否成功
    if(!writer.isOpened()){
        cout << "fail to open video file, cheak the input" << endl;
        return -1;
    }

    while(1){
        //检测是否执行完毕
        if(!video.read(img)){
            cout << "camera is unlink or video is finished" << endl;
            break;
        }
        //将图像写入视频流
        // writer << img;
        writer.write(img);

        //展示图像
        imshow("camera", img);
        char c = waitKey(50);
        //按ESC按键退出视频保存
        if(c == 27){
            break;
        }
    }
    //退出程序时自动关闭视频流,默认也会关闭
    video.release();
    writer.release();


    return 0;
}