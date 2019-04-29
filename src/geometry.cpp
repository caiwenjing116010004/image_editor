#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

Mat trans_up (Mat& img,int num, int width, int height) {
    double percent = double(num)/double(50)/double(16);
    Mat pers;
    Point2f AffinePoints2[4] = { Point2f(width/8, height/8),
                                 Point2f(width/8, height/8*7),
                                 Point2f(width/8*7, height/8),
                                 Point2f(width/8*7, height/8*7)
                               };
    Point2f AffinePoints3[4] = { Point2f(width*(double(1)/double(8)-percent), height/8),
                                 Point2f(width/8, height/8*7),
                                 Point2f(width*(double(7)/double(8)+percent), height/8),
                                 Point2f(width/8*7, height/8*7)
                               };
    Mat Trans_pers = getPerspectiveTransform(AffinePoints2, AffinePoints3);
    warpPerspective(img,pers,Trans_pers,Size(img.cols, img.rows), CV_INTER_CUBIC);

//    for (int i = 0; i < 4; i++){
//        circle(pers, AffinePoints3[i], 2, Scalar(0, 0, 255), 2);
//    }
    return pers;
}

Mat trans_below (Mat& img,int num, int width, int height) {
        Mat pers;
        double percent = double(num)/double(50)/double(16);
        Point2f AffinePoints2[4] = { Point2f(width/8, height/8),
                                     Point2f(width/8, height/8*7),
                                     Point2f(width/8*7, height/8),
                                     Point2f(width/8*7, height/8*7)
                                   };
        Point2f AffinePoints3[4] = { Point2f(width/8, height/8),
                                     Point2f(width*(double(1)/double(8)-percent),
                                     height/8*7), Point2f(width/8*7, height/8),
                                     Point2f(width*(double(7)/double(8)+percent),
                                     height/8*7)
                                   };

        Mat Trans_pers = getPerspectiveTransform(AffinePoints2, AffinePoints3);
        warpPerspective(img,pers,Trans_pers,Size(img.cols, img.rows), CV_INTER_CUBIC);

//        for (int i = 0; i < 4; i++){
//            circle(pers, AffinePoints3[i], 2, Scalar(0, 0, 255), 2);
//        }
        return pers;
    }
