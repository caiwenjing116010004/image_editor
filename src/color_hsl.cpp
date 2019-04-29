

#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include "HSL.hpp"
#include "color_hsl.h"
static HSL hsl;



cv::Mat hue_adjust(cv::Mat& img , int num, int color)
{
    cv::Mat dst;
    num = num*180/50;
    hsl.channels[color].hue = num;
    hsl.adjust(img, dst);
    return dst;
    return dst;
}


cv::Mat satuation_adjust(cv::Mat &img, int num, int color){
    cv::Mat dst;
    hsl.channels[color].saturation = num;
    hsl.adjust(img,dst);
    return dst;
}

cv::Mat brightness_adjust(cv::Mat &img, int num, int color){
    cv::Mat dst;
    hsl.channels[color].brightness = num;
    hsl.adjust(img,dst);
    return dst;
}

