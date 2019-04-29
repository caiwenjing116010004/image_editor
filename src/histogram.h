#ifndef HISTOGRAM_H
#define HISTOGRAM_H
// OpenCV includes
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;

/*
 * Function: showHistoCallback
 * Usage: showHistoCallback(img);
 * -----------------------------
 * This function shows the histogram
 * of a given image.
 */

void showHistoCallback(Mat& img);

/*
 * Function: generateHistoCallback
 * Usage: histo = generateHistoCallback(img);
 * -----------------------------
 * This function generates the histogram
 * of a given image and return it.
 */
Mat generateHistoCallback(const Mat& src, int width, int height);

#endif // HISTOGRAM_H
