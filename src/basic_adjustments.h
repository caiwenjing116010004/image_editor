#ifndef BASIC_ADJUSTMENTS_H
#define BASIC_ADJUSTMENTS_H
#include <iostream>
#include <string>
#include <vector>
#include "light_adjustments.h"
#include "hsl_class.h"
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;


/*
 * Function: contrastAdjust
 * Usage: imgNew = contrastAdjust(imgOld, p_alpha);
 * ------------------------------
 * This function adjusts the contrast of the image.
 * It takes one more argument alpha other than the argument specifying image.
 * The function iterates through all the pixels in the old image, and multiply
 * alpha to each of B, G, R entry value.
 */

Mat contrastAdjust(Mat & img, double alpha);

/*
 * Function: brightnessAdjust
 * Usage: imgNew = brightnessAdjust(imgOld, p_beta);
 * ------------------------------
 * This function adjusts the brightness of the image.
 * It takes one more argument beta other than the argument specifying image.
 * The function iterates through all the pixels in the old image, and add
 * beta to each of B, G, R entry value.
 */

Mat brightnessAdjust(Mat & img, int beta);

/*
 * Function: whiteBalance
 * Usage: imgNew = whiteBalance(imgOld);
 * ------------------------------
 * This function removes unrealistic color casts in the image, and in this way
 * return the image to its natural state. The mean values of the blue values
 * for all pixels, green values for all pixels, and red valued for all pixels
 * are calculated separately, after which a new set of BGR values is generated
 * for each pixel.
 */

Mat whiteBalance(Mat & img);

/*
 * Function: imgBlur
 * Usage: imgNew = imgBlur(imgOld, p_size);
 * ------------------------------
 * This function blurs the image to a specified extent.
 * It takes one more argument p_size other than the argument specifying image,
 * which corresponds to the kernal size in blurring operation. The larger the
 * kernal size, the blurrer the image. p_size is required to be an odd number,
 * and the function will check whether it is assigned properly.
 * This function calls the GaussianBlur function in openCV.
 */

Mat imgBlur(Mat & img, int p_size);

/*
 * Function: imgBorder
 * Usage: imgNew = imgBorder(imgOld, p_size);
 * ------------------------------
 * This function blurs the image to a specified extent.
 * It takes one more argument p_size other than the argument specifying image,
 * which corresponds to the kernel size of the Sobel operator to be applied
 * internally. p_size is required to be an odd number, and the function will
 * check whether it is assigned properly.
 * This function calls the Laplacian function in openCV.
 */

Mat imgBorder(Mat & img, int p_size);

/*
 * Function: imgSharpen
 * Usage: imgNew = imgSharpen(imgOld, deg);
 * ------------------------------
 * This function increases the apparent sharpness of the image.
 * It takes one more argument degree other than the argument specifying image,
 * which indicates the extent of sharpening operation. The larger the degree,
 * the sharper the image. degree is required to be a double between 0.0 and 1.5,
 * and the function will check whether it is assigned properly.
 */

Mat imgSharpen(Mat & img, double degree);

/*
 * Function: imgShadow
 * Usage: imgNew = imgShadow(imgOld, deg);
 * ------------------------------
 * This function darkens each pixel of the image based on the surrounding pixels
 * (local neighborhood). This function initializes an object of imgSDHL class and
 * sets the value of instance variable Shadow to be degree. Class methods are
 * invoked to obtain the shadowed image. degree is required to be an integer
 * between 0 and 255, and the function will check whether it is assigned properly.
 */

Mat imgShadow(Mat & img, int degree);

/*
 * Function: imgHighlight
 * Usage: imgNew = imgHighlight(imgOld, deg);
 * ------------------------------
 * This function lightens each pixel of the image based on the surrounding pixels
 * (local neighborhood). This function initializes an object of imgSDHL class and
 * sets the value of instance variable Highlight to be degree. Class methods are
 * invoked to obtain the highlighted image. degree is required to be an integer
 * between 0 and 255, and the function will check whether it is assigned properly.
 */

Mat imgHighlight(Mat & img, int degree);

/*
 * Function: imgWarmth
 * Usage: imgNew = imgWarmth(imgOld, deg);
 * ------------------------------
 * This function adjusts the hue of the image. The larger the degree, the warmer
 * the image (i.e. closer to red). This function initializes an object of imgHSB
 * class and sets the value of instance variable hue to be -degree. Class methods
 * are then invoked. degree is required to be an integer between 0 and 30, and the
 * function will check whether it is assigned properly.
 */

Mat imgWarmth(Mat & img, int degree);

/*
 * Function: imgSatuation
 * Usage: imgNew = imgSatuation(imgOld, deg);
 * ------------------------------
 * This function adjusts the satuation of the image. The larger the degree, the
 * more saturated the image. This function initializes an object of imgHSB class
 * and sets the value of instance variable saturation to be degree. Class methods
 * are then invoked. degree is required to be an integer between -100 and 100, and
 * the function will check whether it is assigned properly.
 */

Mat imgSatuation(Mat & img, int degree);


#endif // BASIC_ADJUSTMENTS_H
