#ifndef CROP_H
#define CROP_H
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;


/*
 * Function: imageCrop
 * Usage: imageCrop(src, dst, rect);
 * --------------------------------
 * This function crops the source image with the
 * size of the rect, which is a rectangle, and
 * return the image to the output image.
 */

int imageCrop(InputArray src, OutputArray dst, Rect rect);

/*
 * Function: callbackMouseEvent
 * Usage: callbackMouseEvent;
 * ----------------------------
 * This function is the helper function for
 * crop1 which represents a mouse event.
 */

void callbackMouseEvent(int mouseEvent, int x, int y, int flags, void* param);

/*
 * Function: crop1
 * Usage vect = crop1(src);
 * ------------------------
 * This function performs the imageCrop function
 * and return the vector of points which are the
 * position points for the crop rectangle.
 */

vector<Point> crop1(Mat& img);
#endif // CROP_H
