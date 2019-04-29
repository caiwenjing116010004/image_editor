#include "basic_adjustments.h"


Mat contrastAdjust(Mat & img, double beta = 0) {
    double alpha = (beta+double(50))/double(50);
    Mat imgNew = Mat::zeros(img.size(), img.type());
    int height = img.rows;
    int width = img.cols;

    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            for(int c = 0; c < 3; c++ )
            {
                uchar pixel = img.at<Vec3b>(y,x)[c];
                int newPixel = alpha * (int) pixel;
                if (newPixel > 255) newPixel = 255;
                imgNew.at<Vec3b>(y,x)[c] = (uchar) newPixel;
            }
        }
    }

    return imgNew;
}


Mat brightnessAdjust(Mat & img, int beta = 0) {
    Mat imgNew = Mat::zeros(img.size(), img.type());
    int height = img.rows;
    int width = img.cols;

    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            for(int c = 0; c < 3; c++ )
            {
                uchar pixel = img.at<Vec3b>(y,x)[c];
                int newPixel = (int) pixel + beta;
                if (newPixel > 255) newPixel = 255;
                if (newPixel < 0) newPixel = 0;
                imgNew.at<Vec3b>(y,x)[c] = (uchar) newPixel;
            }
        }
    }

    return imgNew;
}


Mat whiteBalance(Mat & img) {
    Mat imgBalanced;
    vector<Mat> threeChannels;
    double B_mean, G_mean, R_mean, B_coef, G_coef, R_coef;
    split(img, threeChannels);

    B_mean = mean(threeChannels[0])[0];
    G_mean = mean(threeChannels[1])[0];
    R_mean = mean(threeChannels[2])[0];

    B_coef = (R_mean + G_mean + B_mean) / (3 * B_mean);
    threeChannels[0] = threeChannels[0] * B_coef;
    G_coef = (R_mean + G_mean + B_mean) / (3 * G_mean);
    threeChannels[1] = threeChannels[1] * G_coef;
    R_coef = (R_mean + G_mean + B_mean) / (3 * R_mean);
    threeChannels[2] = threeChannels[2] * R_coef;

    merge(threeChannels, imgBalanced);
    return imgBalanced;
}


Mat imgBlur(Mat & img, int p_size = 1) {
    Mat imgBlurred;

    if (p_size % 2 == 0) {
        p_size++;
        cout << "The kernel size has to be an odd number." << endl;
        cout << "Here we add 1 to the input size, and the size now becomes " << p_size << endl;
    }

    GaussianBlur(img, imgBlurred, Size(p_size, p_size), 0, 0);
    return imgBlurred;
}


Mat imgBorder(Mat & img, int p_size) {
    Mat imglo;

    if (p_size % 2 == 0) {
        p_size++;
        cout << "The kernel size has to be an odd number." << endl;
        cout << "Here we add 1 to the input size, and the size now becomes " << p_size << endl;
    }

    int ddepth = CV_8U;
    Laplacian(img, imglo, ddepth, p_size, 1, 0, BORDER_DEFAULT);
    return imglo;
}


Mat imgSharpen(Mat & img, double degree = 0.0) {
    Mat imgSharpened = Mat::zeros(img.size(), img.type());
    Mat kernel(3,3,CV_32F,Scalar(0));

    if (degree > 1.5) {
        degree = 1.5;
        cout << "Degree value is out of range [0.0,1.5]. Degree is set to 1.5.";
    }
    if (degree < 0.0) {
        degree = 0.0;
        cout << "Degree value is out of range [0.0,1.5]. Degree is set to 0.0.";
    }

    double value0 = 1.0 + 4 * degree;
    double value1 = - degree;
    kernel.at<float>(1,1)= value0;
    kernel.at<float>(0,1)= value1;
    kernel.at<float>(2,1)= value1;
    kernel.at<float>(1,0)= value1;
    kernel.at<float>(1,2)= value1;

    filter2D(img,imgSharpened,img.depth(),kernel);
    return imgSharpened;
}


Mat imgShadow(Mat & img, int degree = 0) {
    Mat imgShadowed = Mat::zeros(img.size(), img.type());
    imgSDHL imgsdhl;

    if (degree > 255) {
        degree = 255;
        cout << "Degree value is out of range [0, 255]. Degree is set to 255.";
    }
    if (degree < 0) {
        degree = 0;
        cout << "Degree value is out of range [0, 255]. Degree is set to 0.";
    }

    imgsdhl.setShadow(degree);
    imgsdhl.adjust(img, imgShadowed);
    return imgShadowed;
}


Mat imgHighlight(Mat & img, int degree = 0) { //degree should be 0-255
    Mat imgHighlighted = Mat::zeros(img.size(), img.type());
    imgSDHL imgsdhl;

    if (degree > 255) {
        degree = 255;
        cout << "Degree value is out of range [0, 255]. Degree is set to 255.";
    }
    if (degree < 0) {
        degree = 0;
        cout << "Degree value is out of range [0, 255]. Degree is set to 0.";
    }

    imgsdhl.setHighlight(degree);
    imgsdhl.adjust(img, imgHighlighted);
    return imgHighlighted;
}


Mat imgWarmth(Mat & img, int degree = 0) {
    Mat imgAdjusted = Mat::zeros(img.size(), img.type());
    imgHSB imghsb;

    if (degree > 30) {
        degree = 30;
        cout << "Degree value is out of range [0,30]. Degree is set to 30.";
    }
    if (degree < 0) {
        degree = 0;
        cout << "Degree value is out of range [0,30]. Degree is set to 0.";
    }

    imghsb.setHue(- degree);
    imghsb.imgAdjust(img, imgAdjusted);
    return imgAdjusted;
}


Mat imgSatuation(Mat & img, int degree = 0) {
    Mat imgAdjusted = Mat::zeros(img.size(), img.type());
    imgHSB imghsb;

    if (degree > 100) {
        degree = 100;
        cout << "Degree value is out of range [-100,100]. Degree is set to 100.";
    }
    if (degree < -100) {
        degree = -100;
        cout << "Degree value is out of range [-100,100]. Degree is set to -100.";
    }

    imghsb.setSaturation(degree);
    imghsb.imgAdjust(img, imgAdjusted);
    return imgAdjusted;
}
