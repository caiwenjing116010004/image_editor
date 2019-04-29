#include "main_pic.h"
#include "iostream"
#include <QtGui>
// OpenCV includes
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"


main_pic::main_pic()
{
    smallsize = 0;
    largesize = 0;
}

main_pic::main_pic(cv::Mat small,cv::Mat large){
    small_vec.push_back(small);
    large_vec.push_back(large);
    original_large = large;
    original_small = small;
}

bool main_pic::isEmpty(){
    if (consistent()){
        return small_vec.empty();
    }else{
        return false;
    }
}

bool main_pic::consistent(){
    return small_vec.size() == large_vec.size();
}
cv::Mat main_pic::get_small_pic(){
    if (small_vec.empty()) {
        return cv::Mat(2, 2, CV_8UC3, cv::Scalar::all(1));
    } else {
        return small_vec.back();
    }
}

cv::Mat main_pic::get_large_pic(){
    if (large_vec.empty()) {
        return cv::Mat(2, 2, CV_8UC3, cv::Scalar::all(1));
    } else {
        return large_vec.back();
    }
}


cv::Mat main_pic::regret(){
    if (large_vec.size() >= 2){
        large_vec.pop_back();
    }
    if (small_vec.size() >= 2){
        cv::Mat last_pic = small_vec.back();
        small_vec.pop_back();
        return last_pic;
    } else{
        return small_vec[0];
    }
}

void main_pic::recover(){
    while (small_vec.size() > 1){
        small_vec.pop_back();
    }
    while (large_vec.size() > 1){
        large_vec.pop_back();
    }
}
cv::Mat main_pic::push_small(cv::Mat& img){
    if (small_vec.size() == 0){
        original_small = img;
    }
    small_vec.push_back(img);
    return img;
}

cv::Mat main_pic::push_large(cv::Mat& img){
    if (large_vec.size() == 0){
        original_large = img;
    }
    large_vec.push_back(img);
    return img;
}

cv::Mat main_pic::get_original_large(){
    return original_large;
}

cv::Mat main_pic::get_original_small(){
    return original_small;
}
