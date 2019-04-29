#ifndef FILTERS_PACKS_H
#define FILTERS_PACKS_H
#include "hsl_class.h"
#include "basic_adjustments.h"


/*
 * Function: portrait
 * Usage: imgNew = portrait(imgOld);
 * ------------------------------
 * This function implements a filter specialized for images of portraits.
 * Key idea of this filter is to make the image warmer and more saturated.
 * This function invokes the contrastAdjust function, the imgShadow function,
 * and the imgHighlight function. An object of imgHSB class is created,
 * followed by multiple adjustments.
 */

Mat portrait(Mat & img);

/*
 * Function: removeFlaw
 * Usage: imgNew = portrait(imgOld);
 * ------------------------------
 * This function implements a filter specialized for images of portraits
 * with flaws such as speckles.
 * In addition to the normal portrait filter, this function invokes the
 * imgBlur function to blur out the flaws.
 */

Mat removeFlaw(Mat & img);

/*
 * Function: waterscape
 * Usage: imgNew = waterscape(imgOld);
 * ------------------------------
 * This function implements a filter specialized for images of lakes or seaside.
 * Key idea of this filter is to make the water looks bluer.
 * This function invokes the contrastAdjust function and the imgHighlight function.
 * An object of imgHSB class is created, followed by multiple adjustments.
 */

Mat waterscape(Mat & img);

/*
 * Function: plant
 * Usage: imgNew = plant(imgOld);
 * ------------------------------
 * This function implements a filter specialized for images of plants.
 * Key idea of this filter is to make the withered and yellowish plants look green.
 * This function invokes the imgShadow function and the imgHighlight function.
 * An object of imgHSB class is created, followed by multiple adjustments.
 */

Mat plant(Mat & img);

/*
 * Function: architecture
 * Usage: imgNew = architecture(imgOld);
 * ------------------------------
 * This function implements a filter specialized for images of architectures.
 * Key idea of this filter is to sharpen the lines to make the building more stereoscopic.
 * This function invokes the contrastAdjust function, the imgShadow function,
 * and the imgSharpen function. An object of imgHSB class is created,
 * followed by multiple adjustments.
 */

Mat architecture(Mat & img);

/*
 * Function: vintage
 * Usage: imgNew = vintage(imgOld);
 * ------------------------------
 * This function implements a filter that can mimic the style of an old photo.
 * The function iterates through all the pixels in the image, and for each pixel,
 * a new set of BGR values is calculated by linearly combining the original B value,
 * the original G value, and the original R value, using some fixed coefficients.
 */

Mat vintage(Mat & img);

/*
 * Function: sketch
 * Usage: imgNew = sketch(imgOld);
 * ------------------------------
 * This function implements a filter that can mimic the style of a sketch.
 * The function first invokes the cvtColor function in openCV to convert
 * the image into gray scale, after which an inverted gray scale image is
 * created, and the two gray scale images are merged.
 */

Mat sketch(Mat & imgIn);

/*
 * Function: blackAndWhite
 * Usage: imgNew = blackAndWhite(imgOld);
 * ------------------------------
 * This function implements a filter that can convert an image into a
 * black-and-white image. In addition to the cvtColor function in openCV,
 * This function invokes the contrastAdjust function, the imgShadow function,
 * and the imgHighlight function to obtain better color conversion.
 */

Mat blackAndWhite(Mat & img);

#endif // FILTERS_PACKS_H
