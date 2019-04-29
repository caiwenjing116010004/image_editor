#ifndef HSL_CLASS_H
#define HSL_CLASS_H

#include "opencv2/core.hpp"
using namespace cv;



class imgHSB {

public:

/*
 * Method: Constructor
 * Usage: imgHSB imghsb;
 * ------------------------------
 * In the constructor, the instance variables hue, saturation,
 * and brightness are all initialized to be 0.
 */

    imgHSB();

/*
 * Method: setHue  setSaturation  setBrightness
 * Usage: imghsb.setHue(a)  imghsb.setSaturation(b)  imghsb.setBrightness(c);
 * ------------------------------
 * The setHue method, the setSaturation method, and the setBrightness
 * method are the setters of instance variables hue, saturation, and
 * brightness, respectively. Both saturation and brightness values
 * are required to be an integer from -100 to 100, and these two methods
 * will check whether the specified values fall into the valid range.
 */

    void setHue(int p_hue);

    void setSaturation(int p_saturation);

    void setBrightness(int p_brightness);

/*
 * Method: adjustHue  adjustSaturation  adjustBrightness
 * Usage: imghsb.adjustHue(arr)  imghsb.adjustSaturation(arr)  imghsb.adjustBrightness(arr);
 * ------------------------------
 * The three adjust methods work on a single pixel. The HSB values,
 * rather than the BGR values, of a pixel is stored in an array of
 * length three and passed into the adjust methods. Then the adjust
 * methods will modify the array according to values of the instance
 * variables hue, saturation, and brightness.
 */

    void adjustHue(float (&array)[3]);

    void adjustSaturation(float (&array)[3]);

    void adjustBrightness(float (&array)[3]);

/*
 * Method: imgAdjust
 * Usage: imghsb.imgAdjust(imgBefore, imgAfter);
 * ------------------------------
 * The imgAdjust method iterates through all the pixels of the image.
 * For each pixel, use the BGR2HSB function (written by others) to
 * convert a set of BGR values into a set of HSB values, stored in
 * an array of length three. Then adjustHue, adjustSaturation, and
 * adjustBrightness are invoked to update the HSB array. Finally the
 * set of HSB values are converted back to BGR values using function
 * HSB2BGR (written by others).
 */

    int imgAdjust(Mat input, Mat output);

private:

    int hue;          //[-180, 180]
    int saturation;   //[-100, 100]
    int brightness;   //[-100, 100]

};



#endif // HSL_CLASS_H
