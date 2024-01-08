#include <opencv2/opencv.hpp>
#include <iostream>
#include <unistd.h>

using namespace cv;
using namespace std;

// 鼠标事件回调函数
Point sp(-1, -1);
Point ep(-1, -1);
Mat orignal;
// (鼠标事件，事件发生的x轴，事件发生的y轴，额外的标志信息，用户定义数据指针)
static void on_draw(int event, int x, int y, int flags, void *userdata){
    Mat img = *(Mat *)userdata;
    if(event == EVENT_LBUTTONDOWN){
        sp.x = x;
        sp.y = y;
        cout << "start point:" << sp << endl;
    }else if(event ==EVENT_LBUTTONUP){
        ep.x = x;
        ep.y = y;
        cout << "end point:" << ep << endl;
        int dx = ep.x - sp.x;
        int dy = ep.y - sp.y;
        if(dx > 0 && dy > 0){
            Rect box(sp.x, sp.y, dx, dy);
            rectangle(img, box, Scalar(255, 0, 0), 3, LINE_8);
            imshow("mouse draw", img);
            // 截取
            imshow("ROI area", img(box));
            // reset
            sp.x = -1;
            sp.y = -1;
        }
    }else if(event ==EVENT_MOUSEMOVE){
        if(sp.x > 0 && sp.y > 0){
            ep.x = x;
            ep.y = y;
            cout << "end point:" << ep << endl;
            int dx = ep.x - sp.x;
            int dy = ep.y - sp.y;
            if(dx > 0 && dy > 0){
                Rect box(sp.x, sp.y, dx, dy);
                orignal.copyTo(img);
                rectangle(img, box, Scalar(255, 0, 0), 3, LINE_8);
                imshow("mouse draw", img);
            }
        }
    }
}

int main(){
    //图像加载

    // //以彩色读取
    // Mat img;
    // img = imread("/Users/ren/Documents/GitHub/Opencv/image/original/blackboard.jpg", IMREAD_COLOR);
    // //以灰色读取
    // Mat gray = imread("/Users/ren/Documents/GitHub/Opencv/image/original/blackboard.jpg", IMREAD_GRAYSCALE);

    // //创建可变化窗口
    // namedWindow("img", WINDOW_AUTOSIZE);
    // resizeWindow("img", 640, 480);
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
    // //删除窗口
    // destroyAllWindows()

/*--------------------------------------*/
    //视频加载/摄像头调用

    // //获取视频
    // VideoCapture video;
    // // //获取视频文件
    // // video.open("/Users/ren/Documents/GitHub/Opencv/video/car.mp4");
    // // //长宽/总帧数/fps/编码格式
    // // int frame_width = video.get(CAP_PROP_FRAME_WIDTH);
    // // int frame_height = video.get(CAP_PROP_FRAME_HEIGHT);
    // // int count = video.get(CAP_PROP_FRAME_COUNT);
    // // int fps = video.get(CAP_PROP_FPS);
    // // video.get(CAP_PROP_FOURCC);
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

    // VideoCapture video(0);
    // if(!video.isOpened()){
    //     cout << "camera error" << endl;
    //     return -1;
    // }

    // Mat img;
    // video >> img;
    // if(img.empty()){
    //     cout << "can't get image" << endl;
    //     return -1;
    // }

    // //判断相机是否为彩色
    // bool isColor = (img.type() == CV_8UC3);

    // VideoWriter writer;
    // //选择视频编码格式
    // // int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
    // int codec = VideoWriter::fourcc('H', '2', '6', '4');

    // //设置视频频率
    // double fps = 25.0;

    // //保存视频名称
    // string filename = "/Users/ren/Documents/GitHub/Opencv/video/camera01.mp4";
    // //创建保存视频文件的视频流
    // writer.open(filename, codec, fps, img.size(), isColor);

    // //判断视频流创建是否成功
    // if(!writer.isOpened()){
    //     cout << "fail to open video file, cheak the input" << endl;
    //     return -1;
    // }

    // while(1){
    //     //检测是否执行完毕
    //     if(!video.read(img)){
    //         cout << "camera is unlink or video is finished" << endl;
    //         break;
    //     }
    //     //将图像写入视频流
    //     // writer << img;
    //     writer.write(img);

    //     //展示图像
    //     imshow("camera", img);
    //     char c = waitKey(50);
    //     //按ESC按键退出视频保存
    //     if(c == 27){
    //         break;
    //     }
    // }
    // //退出程序时自动关闭视频流,默认也会关闭
    // video.release();
    // writer.release();


/*--------------------------------------*/
    //鼠标事件

    namedWindow("mouse draw", WINDOW_AUTOSIZE);
    Mat img = Mat::zeros(Size(512, 512), CV_8UC3);
    // (窗口名称，鼠标事件回调函数，用户数据指针)
    setMouseCallback("mouse draw", on_draw, (void *)&img);
    imshow("mouse draw", img);
    // 保存原图
    orignal = img.clone();

    waitKey(0);
    return 0;
}