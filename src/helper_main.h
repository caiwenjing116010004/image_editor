#ifndef HELPER_H
#define HELPER_H
#include<cv.h>
#include<opencv2/opencv.hpp>
#include <QFileDialog>
#include <QLabel>

/*
 * Function: present
 * Usage: present(src, label1, label2);
 * ------------------------------------
 * This function presents the image on the main picture window and
 * histogram window. The first parameter src is the image to be shown,
 * The second parameter label1 is the main window, and the last
 * parameter label2 is the histogram window. The function
 * will not modify the original image.
 */

void present(const cv::Mat& src,QLabel& label1, QLabel& label2);

/*
 * Function: keep_ratio
 * Usage: pixmap = keep_ratio(src, width, height);
 * -----------------------------------------------
 * This function generate a QPixmap and resize it to the ratio
 * of the original image. The QPixmap can be used in the main
 * window.
 */

QPixmap keep_ratio(const cv::Mat& src, int width, int height);

/*
 * Function: keep_ratio_no
 * Usage: pixmap = keep_ratio_no(src, width, height);
 * -----------------------------------------------
 * This function generate a QPixmap and resize the image so
 * that the image can fit into the fixed Qt window.
 * The QPixmap can be used in the main window.
 */

QPixmap keep_ratio_no(const cv::Mat& src, int width, int height);

/*
 * Function: compress
 * usage: dst = compress(src);
 * This function compress the original image and return a
 * compressed new image according to its
 * size. When the original image is large, it has larger compress
 * number. Should note that the original image is not modified.
 */

cv::Mat compress(const cv::Mat& src);

/*
 * Function: compress_number
 * usage num = compress_number(src);
 * The function generates the compress number which
 * is applied in the compress function
 */

int compress_number(const cv::Mat& src);

#endif // HELPER_H
