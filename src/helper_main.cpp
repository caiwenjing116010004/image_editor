#include<cv.h>
#include<opencv2/opencv.hpp>
#include <QFileDialog>
#include "helper_main.h"
#include "histogram.h"

void present(const cv::Mat& src,QLabel& label1, QLabel& label2){
    cv::Mat dst;
    if (src.channels() == 3){
            cv::cvtColor(src,dst,CV_BGR2RGB);
            QPixmap pixmap = keep_ratio(dst,label1.width(),label1.height());
            label1.setPixmap(pixmap); //将图片显示在QLabel上

            cv::Mat histo = generateHistoCallback(src,label2.width(), label2.height());
            cv::cvtColor(histo,histo,CV_BGR2RGB);
//            QPixmap hist_map = keep_ratio_no(histo,label2.width(),label2.height());
            QPixmap hist_map = keep_ratio_no(histo,label2.width(),label2.height());
            label2.setPixmap(hist_map);  //显示 直方图
    }

}


QPixmap keep_ratio(const cv::Mat& src, int width, int height) {
    QImage showImage((const uchar*)src.data,src.cols,src.rows,src.cols*src.channels(),QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(showImage);
    QPixmap fitpixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
    return fitpixmap;
}

QPixmap keep_ratio_no(const cv::Mat& src, int width, int height) {
    QImage showImage((const uchar*)src.data,src.cols,src.rows,src.cols*src.channels(),QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(showImage);
    QPixmap fitpixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    return fitpixmap;
}
cv::Mat compress(const cv::Mat& src){
    cv::Mat dst;
    if (src.cols >= 4000){
        cv::resize(src,dst,cv::Size(src.cols/8,src.rows/8),0,0,cv::INTER_LINEAR);
    }else if (2000 <= src.cols && src.cols < 4000){
        cv::resize(src,dst,cv::Size(src.cols/4,src.rows/4),0,0,cv::INTER_LINEAR);
    }else if (1000 <= src.cols && src.cols < 2000){
        cv::resize(src,dst,cv::Size(src.cols/2,src.rows/2),0,0,cv::INTER_LINEAR);
    }else if (src.cols < 1000){
        dst = src;
    }
    return dst;
}

int compress_number(const cv::Mat& src){
    int num;
    if (src.cols >= 4000){
        num = 8;
    }else if (2000 <= src.cols && src.cols < 4000){
        num  = 4;
    }else if (1000 <= src.cols && src.cols < 2000){
        num = 2;
    }else{
        num = 1;
    }
    return num;
}

