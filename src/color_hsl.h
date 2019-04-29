#ifndef COLOR_H
#define COLOR_H
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include "HSL.hpp"

using namespace std;

/*
 * Function: hue_adjust
 * Usage: dst = hue_adjust(img, num, color);
 * ----------------------------------------
 * This function adjsut the hue of the given channel of the image
 * The first argument img is input image, the second
 * argument is the adjust value, and the color argument
 * is the channel number. The output is the adjusted image.
 */

cv::Mat hue_adjust(cv::Mat& img , int num, int color);

/*
 * Function: satuation_adjust
 * Usage: dst = satuation_adjust(img, num, color);
 * ----------------------------------------
 * This function adjsut the satuation of the given channel of the image
 * The first argument img is input image, the second
 * argument is the adjust value, and the color argument
 * is the channel number. The output is the adjusted image.
 */
cv::Mat satuation_adjust(cv::Mat &img, int num, int color);

/*
 * Function: brightness_adjust
 * Usage: dst = brightness_adjust(img, num, color);
 * ----------------------------------------
 * This function adjsut the brightness of the given channel of the image
 * The first argument img is input image, the second
 * argument is the adjust value, and the color argument
 * is the channel number. The output is the adjusted image.
 */

cv::Mat brightness_adjust(cv::Mat &img, int num, int color);

#endif // COLOR_H
