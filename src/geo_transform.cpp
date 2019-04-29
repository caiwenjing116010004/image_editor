#include "geo_transform.h"


Mat imgFlip(Mat & img) {
    Mat imgFlipped = Mat::zeros(img.size(), img.type());
    int height = img.rows;
    int width = img.cols;

    for (int row_i = 0; row_i < height; row_i++)
    {
        for (int col_i = 0; col_i < (width / 2); col_i++)
        {
            Vec3b pixelLeft = img.at<Vec3b>(row_i, col_i);
            Vec3b pixelRight = img.at<Vec3b>(row_i, width-1-col_i);
            imgFlipped.at<Vec3b>(row_i, width-1-col_i) = pixelLeft;
            imgFlipped.at<Vec3b>(row_i, col_i) = pixelRight;
        }
    }
    return imgFlipped;
}


Mat imgCropRect(Mat & img, int rowStart, int colStart, int height, int width) {
    if ((rowStart + height >= img.rows) || (colStart + height >= img.cols)) {
        cout << "Cropping operation out of range. Please specify again." << endl;
        return img;
    }

    Mat imgCropped = Mat::zeros(height, width, img.type());
    for (int row_i = 0; row_i < height; row_i++)
    {
        for (int col_i = 0; col_i < width; col_i++)
        {
            Vec3b pixel = img.at<Vec3b>(rowStart + row_i, colStart + col_i);
            imgCropped.at<Vec3b>(row_i, col_i) = pixel;
        }
    }
    return imgCropped;
}


Mat imgCropSquare(Mat & img, int rowStart, int colStart, int sideLength) {
    if ((rowStart + sideLength >= img.rows) || (colStart + sideLength >= img.cols)) {
        cout << "Cropping operation out of range. Please specify again." << endl;
        return img;
    }

    return imgCropRect(img, rowStart, colStart, sideLength, sideLength);
}


Mat imgCropAuto(Mat & img, double ratio) {
    if ((ratio >= 1.0) || (ratio <= 0.0)) {
        cout << "Invalid ratio. Ratio should be between 0.0 and 1.0, please specify again." << endl;
        return img;
    }

    int newHeight = (int)(img.rows * ratio);
    int newWidth = (int)(img.cols * ratio);
    int rowStart = (img.rows - newHeight) / 2;
    int colStart = (img.cols - newWidth) / 2;
    return imgCropRect(img, rowStart, colStart, newHeight, newWidth);
}


Mat imgClockwise(Mat & img) {
    Mat imgRotated = Mat(img.cols, img.rows, img.type());
    int height = img.rows;
    int width = img.cols;

    for (int row_i = 0; row_i < height; row_i++)
    {
        for (int col_i = 0; col_i < width; col_i++)
        {
            Vec3b pixel = img.at<Vec3b>(row_i, col_i);
            imgRotated.at<Vec3b>(col_i, height-1-row_i) = pixel;
        }
    }
    return imgRotated;
}


Mat imgCounterClockwise(Mat & img) {
    Mat imgRotated = Mat(img.cols, img.rows, img.type());
    int height = img.rows;
    int width = img.cols;

    for (int row_i = 0; row_i < height; row_i++)
    {
        for (int col_i = 0; col_i < width; col_i++)
        {
            Vec3b pixel = img.at<Vec3b>(row_i, col_i);
            imgRotated.at<Vec3b>(width-1-col_i, row_i) = pixel;
        }
    }
    return imgRotated;
}


Mat imgRotate(const Mat & img, double degree) {
    Mat imgRotated;
    int height = img.rows;
    int width = img.cols;
    while (degree < 0) degree += 360;

    int diaLength = int(sqrt((height * height + width * width)));
    Mat diaSquare = Mat::zeros(diaLength, diaLength, img.type());
    int xStart = (diaLength - width) / 2;
    int yStart = (diaLength - height) / 2;

    for (int row_i = 0; row_i < height; row_i++)
    {
        for (int col_i = 0; col_i < width; col_i++)
        {
            Vec3b pixel = img.at<Vec3b>(row_i, col_i);
            diaSquare.at<Vec3b>(yStart + row_i, xStart + col_i) = pixel;
        }
    }

    Mat rotationMat = getRotationMatrix2D(Point(diaLength/2, diaLength/2), degree, 1);
    warpAffine(diaSquare, imgRotated, rotationMat, Size(diaLength, diaLength));
    imgRotated = imgRotated(Range(yStart, yStart + height), Range(xStart, xStart + width));
    return imgRotated;
}
