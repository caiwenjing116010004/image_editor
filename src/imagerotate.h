#ifndef IMAGEROTATE_H
#define IMAGEROTATE_H


/*
 * Function imageRotate
 * Usage: imageRotate(src, dst, angle, isClip);
 * -------------------------------------------
 * Rotate the input image to a given angle, and put the
 * image into the output image:dst. When isClip is true,
 * the function will automatically delete the black frame
 * caused by the rotation.
 */

int imageRotate(InputArray src, OutputArray dst, double angle, bool isClip);

#endif // IMAGEROTATE_H
