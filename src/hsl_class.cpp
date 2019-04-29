#include "hsl_class.h"
#include "colorspace_trans.h"
#include <math.h>



imgHSB::imgHSB() {
    hue = 0;
    saturation = 0;
    brightness = 0;
}


void imgHSB::setHue(int p_hue = 0) {
    hue = p_hue;
}


void imgHSB::setSaturation(int p_saturation = 0) {
    saturation = p_saturation;
    if (saturation > 100) saturation = 100;
    if (saturation < -100) saturation = -100;
}


void imgHSB::setBrightness(int p_brightness = 0) {
    brightness = p_brightness;
    if (brightness > 100) brightness = 100;
    if (brightness < -100) brightness = -100;
}


void imgHSB::adjustHue (float (&array)[3]) {
    array[0] = int(array[0] + hue) % 360;
    if (array[0] <  0) array[0] += 360;
}


void imgHSB::adjustSaturation(float (&array)[3]) {
    if (saturation < 0) {
        array[1] = array[1] * (1 + saturation / 100.0);
    }
    else {
        array[1] = array[1] + (1 - array[1]) * saturation / 100.0; //saturation increase
        array[2] = array[2] + (1 - array[2]) * saturation / 100.0; //brightness increase
    }
}


void imgHSB::adjustBrightness(float (&array)[3]) {
    if (brightness < 0) {
        array[2] = array[2] * (1 + brightness / 100.0);
    }
    else {
        array[2] = array[2] + (1 - array[2]) * brightness / 100.0; //brightness increase
        array[1] = array[1] - array[1] * brightness / 100.0; //saturation decrease
    }
}


int imgHSB::imgAdjust(Mat input, Mat output) {
    const uchar *in;
    uchar *out;
    int width = input.cols;
    int height = input.rows;
    int channel_count = input.channels();
    float hsb[3];

    //scan pixels of image
    for (int y = 0; y < height; y++) {
        in = input.ptr<uchar>(y);
        out = output.ptr<uchar>(y);

        for (int x = 0; x < width; x++) {
            //BGR to HSB conversion
            BGR2HSB(in, hsb);

            //adjust hue
            adjustHue(hsb);
            //adjust saturation
            adjustSaturation(hsb);
            //adjust brightness
            adjustBrightness(hsb);

            //HSB to BGR conversion
            HSB2BGR(hsb, out);

            in += 3;
            out += 3;
            for (int c = 0; c < channel_count - 3; c++) {
                *out++ = *in++;
            }
        }
    }
    return 0;
}
