#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

/*
 * Function: trans_up
 * Usage: dst = trans_up(img, num);
 * --------------------------------
 * This function performs the AffineTransformation using
 * the upper two Affine points. The first argument is the
 * input image, the second argument is the strength of
 * transformation. The output is the transformed image.
 */

Mat trans_up (Mat& img,int num, int width, int height);

/*
 * Function: trans_below
 * Usage: dst = trans_below(img, num);
 * --------------------------------
 * This function performs the AffineTransformation using
 * the lower two Affine points. The first argument is the
 * input image, the second argument is the strength of
 * transformation. The output is the transformed image.
 */

Mat trans_below (Mat& img,int num, int width, int height);

#endif // GEOMETRY_H
