//
//  main.cpp
//  test
//
//  Created by 徐亦燊 on 2020/2/28.
//  Copyright © 2020 徐亦燊. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
using namespace std;

int equalizeMain()
{
    cv::Mat srcMat = imread("/Users/xuyishen/Desktop/sa jiganyouhaximeiyouga/2020.5.15/2/etest.jpg", 0);
    cv::Mat dstMat;

    if (srcMat.empty()) {
        cout << "fail to read pic!" << endl;
        return -1;
    }

    //0.输入图像，类型是 8位单通道
    //1.输出图像，与输入同样尺寸同样类型
    if (srcMat.type() == CV_8UC1) {
        equalizeHist(srcMat, dstMat);
    }
    else if (srcMat.type() == CV_8UC3) {
        Mat channel[3];
        Mat out[3];
        split(srcMat, channel);

        for (int i = 0; i < 3; i++) {
            equalizeHist(channel[i], out[i]);
        }

        merge(out, 3, dstMat);

    }


    //绘制直方图
    float srcHist[256];
    float dstHist[256];

    cv::Mat srcHistMat;
    cv::Mat dstHistMat;

    //calcIntenHist(srcMat, srcHist);
    //calcSimpleHist(dstMat, dstHist);
    //drawSimpleHist(srcHistMat, srcHist,3,100);
    //drawSimpleHist(dstHistMat, dstHist,3,100);

    imshow("srcMat", srcMat);
    imshow("dstMat", dstMat);
    /*imshow("srcHistMat", srcHistMat);
    imshow("dstHistMat", dstHistMat);*/

    waitKey(0);

    destroyAllWindows();

    return 0;

}
int main(int argc, const char * argv[]) {
    //开始计时
    double start = static_cast<double>(getTickCount());

    //gamma矫正演示
    //gammaMain();

    //直方图均衡演示
    equalizeMain();

    //结束计时
    double time = ((double)getTickCount() - start) / getTickFrequency();
    //显示时间
    cout << "processing time:" << time / 1000 << "ms" << endl;

    //等待键盘响应，按任意键结束程序
    system("pause");
    return 0;
}
