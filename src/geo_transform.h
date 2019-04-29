#ifndef GEO_TRANSFORM_H
#define GEO_TRANSFORM_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;


/*
 * Function: imgFlip
 * Usage: imgNew = imgFlip(imgOld);
 * ------------------------------
 * This function flips the image with respect to the central column.
 * Pixels on the left of central column in the old image will appear
 * on the right of central column in the new image, and vice versa.
 */

Mat imgFlip(Mat & img);

/*
 * Function: imgCropRect
 * Usage: imgNew = imgCropRect(imgOld, r0, c0, height, width);
 * ------------------------------
 * This function crops the original image matrix into a smaller image matrix.
 * The parameters rowStart and colStart specify which row and which column in
 * the old image will correspond to the first row and the first column in the
 * new image. The parameters height and width specify the number of rows and
 * the number of columns in the new image. The function will check whether the
 * arguments are properly assigned so that a valid subimage is available.
 */

Mat imgCropRect(Mat & img, int rowStart, int colStart, int height, int width);

/*
 * Function: imgCropSquare
 * Usage: imgNew = imgCropSquare(imgOld, r0, c0, p_size);
 * ------------------------------
 * This function crops the original image matrix into a smaller image matrix
 * with equal numbers of rows and columns (i.e. a square image). This function
 * will call the imgCropRect function, assigning rowStart and colStart to the
 * corresponding parameters while assigning sidelength to both height and width.
 */

Mat imgCropSquare(Mat & img, int rowStart, int colStart, int sideLength);

/*
 * Function: imgCropAuto
 * Usage: imgNew = imgCropAuto(imgOld, p_ratio);
 * ------------------------------
 * This function crops the original image matrix into a smaller image matrix.
 * The new image will be taken from the central part of the old image. The
 * number of rows (columns) in the new image will be equal to ratio times the
 * number of rows (columns) in the old image. This function will call the
 * imgCropRect function, assigning the calculated rowStart, colStart, height,
 * and width to the corresponding parameters.
 */

Mat imgCropAuto(Mat & img, double ratio);

/*
 * Function: imgClockwise
 * Usage: imgNew = imgClockwise(imgOld);
 * ------------------------------
 * This function rotates the image by 90 degrees in clockwise direction.
 * The number of rows (columns) in the new image will be equal to the
 * number of columns (rows) in the old image.
 */

Mat imgClockwise(Mat & img);

/*
 * Function: imgCounterClockwise
 * Usage: imgNew = imgCounterClockwise(imgOld);
 * ------------------------------
 * This function rotates the image by 90 degrees in counterclockwise direction.
 * The number of rows (columns) in the new image will be equal to the number
 * of columns (rows) in the old image.
 */

Mat imgCounterClockwise(Mat & img);

/*
 * Function: imgRotate
 * Usage: imgNew = imgRotate(imgOld, p_degree);
 * ------------------------------
 * This function rotates the image by an arbitrary degree.
 * If the degree is a positive number, then the image will be rotated
 * in counterclockwise direction. If the degree is a negative number,
 * then the image will be rotated in clockwise direction.
 */

Mat imgRotate(const Mat & img, double degree);

#endif // GEO_TRANSFORM_H
