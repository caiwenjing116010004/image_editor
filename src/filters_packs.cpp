#include "filters_packs.h"


Mat portrait(Mat & img) {
    Mat imgAfter = Mat::zeros(img.size(), img.type());

    Mat imgTemp = contrastAdjust(img, 1.1);
    imgTemp = imgShadow(imgTemp, 15);
    imgTemp = imgHighlight(imgTemp, 15);

    imgHSB imghsb;
    imghsb.setHue(-5);
    imghsb.setSaturation(5);
    imghsb.setBrightness(-5);
    imghsb.imgAdjust(imgTemp, imgAfter);

    return imgAfter;
}


Mat removeFlaw(Mat & img) {
    Mat imgAfter = Mat::zeros(img.size(), img.type());

    imgAfter = imgBlur(img, 3);
    imgAfter = portrait(imgAfter);

    return imgAfter;
}


Mat waterscape(Mat & img) {
    Mat imgAfter = Mat::zeros(img.size(), img.type());

    Mat imgTemp = contrastAdjust(img, 1.1);
    imgTemp = imgHighlight(imgTemp, 10);

    imgHSB imghsb;
    imghsb.setHue(10);
    imghsb.setSaturation(5);
    imghsb.setBrightness(-5);
    imghsb.imgAdjust(imgTemp, imgAfter);

    return imgAfter;
}


Mat plant(Mat & img) {
    Mat imgAfter = Mat::zeros(img.size(), img.type());

    Mat imgTemp = imgHighlight(img, 5);
    imgTemp = imgShadow(imgTemp, 10);

    imgHSB imghsb;
    imghsb.setHue(15);
    imghsb.setSaturation(7);
    imghsb.setBrightness(-3);
    imghsb.imgAdjust(imgTemp, imgAfter);

    return imgAfter;
}


Mat architecture(Mat & img) {
    Mat imgAfter = Mat::zeros(img.size(), img.type());

    Mat imgTemp = imgSharpen(img, 0.8);
    imgTemp = imgShadow(imgTemp, 20);
    imgTemp = contrastAdjust(imgTemp, 1.05);

    imgHSB imghsb;
    imghsb.setSaturation(5);
    imghsb.setBrightness(-10);
    imghsb.imgAdjust(imgTemp, imgAfter);

    return imgAfter;
}


Mat vintage(Mat & img) {
    Mat imgAfter = Mat::zeros(img.size(), img.type());
    for (int row_i = 0; row_i < img.rows; row_i++)
    {
        for (int col_i = 0; col_i < img.cols; col_i++)
        {
            Vec3b pixel = img.at<Vec3b>(row_i, col_i);
            float blue = pixel[0];
            float green = pixel[1];
            float red = pixel[2];

            float newblue = 0.272 * red + 0.534 * green + 0.131 * blue;
            if(newblue < 0) newblue = 0;
            if(newblue > 255) newblue = 255;

            float newgreen = 0.349 * red + 0.686 * green + 0.168 * blue;
            if(newgreen < 0) newgreen = 0;
            if(newgreen > 255) newgreen = 255;

            float newred = 0.393 * red + 0.769 * green + 0.189 * blue;
            if(newred < 0) newred = 0;
            if(newred > 255) newred = 255;

            imgAfter.at<Vec3b>(row_i, col_i)[0] = (uchar) newblue;
            imgAfter.at<Vec3b>(row_i, col_i)[1] = (uchar) newgreen;
            imgAfter.at<Vec3b>(row_i, col_i)[2] = (uchar) newred;
        }
    }
    return imgAfter;
}


Mat sketch(Mat & imgIn) {
    int height = imgIn.rows;
    int width = imgIn.cols;

    /* Convert the image into a gray scale image named gray */
    Mat gray;
    cvtColor(imgIn, gray, CV_BGR2GRAY);

    /* Create an image named grayInverted such that the corresponding entries
       of gray and grayInverted add up to 255 */
    Mat grayInverted = Mat::zeros(gray.size(), gray.type());
    for (int row_i = 0; row_i < height; row_i++)
    {
        for (int col_i = 0; col_i < width; col_i++)
        {
            float pixel = gray.at<uchar>(row_i, col_i);
            uchar newpixel = uchar (255 - pixel);
            grayInverted.at<uchar>(row_i, col_i) = newpixel;
        }
    }
    grayInverted = imgBlur(grayInverted, 11);

    /* Merge gray and grayInverted into imgAfter */
    Mat imgAfter(grayInverted.size(),CV_8UC1);
    for (int row_i = 0; row_i < height; row_i++)
    {
        for (int col_i = 0; col_i < width; col_i++)
        {
            int pixel1 = gray.at<uchar>(row_i, col_i);
            int pixel2 = grayInverted.at<uchar>(row_i, col_i);
            int pixelnew = pixel1 + (pixel1 * pixel2) / (256 - pixel2);
            if (pixelnew > 255) pixelnew = 255;
            if (pixelnew < 0) pixelnew = 0;
            imgAfter.at<uchar>(row_i, col_i) = uchar (pixelnew);
        }
    }

    /* Use the imgSharpen() function, the brightnessAdjust() function, and the
     * contrastAdjust() function, which are implemented in basic_adjustments.cpp */
    imgAfter = imgSharpen(imgAfter, 1.5);
    imgAfter = brightnessAdjust(imgAfter, -25);
    imgAfter = contrastAdjust(imgAfter, 1.1);

    return imgAfter;
}


Mat blackAndWhite(Mat & img) {
    Mat imgAfter(img.size(),CV_8UC1);

    Mat imgTemp = imgShadow(img, 15);
    imgTemp = imgHighlight(imgTemp, 5);
    cvtColor(imgTemp, imgTemp, CV_BGR2GRAY);

    for (int row_i = 0; row_i < img.rows; row_i++)
    {
        for (int col_i = 0; col_i < img.cols; col_i++)
        {
            int pixel = imgTemp.at<uchar>(row_i, col_i);
            int pixelnew = 1.1 * pixel;
            if (pixelnew > 255) pixelnew = 255;
            if (pixelnew < 0) pixelnew = 0;
            imgAfter.at<uchar>(row_i, col_i) = uchar (pixelnew);
        }
    }
    return imgAfter;
}
