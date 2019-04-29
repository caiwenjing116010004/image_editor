// OpenCV includes
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "iostream"
using namespace cv;
using namespace std;

void showHistoCallback(Mat& img) {
// generate Gray image
    Mat grey;
    cvtColor(img, grey, COLOR_BGR2GRAY);
// Separate image in BRG
    vector<Mat> bgr;
    split(img, bgr );
// Create the histogram for 256 bins
    // The number of possibles values [0..255]
    int numbins= 256;

/// Set the ranges ( for B,G,R) ), last is not included
    float range[] = { 0, 256 } ;
    const float* histRange = { range };

    Mat b_hist, g_hist, r_hist, grey_hist;

    calcHist( &bgr[0], 1, 0, Mat(), b_hist, 1, &numbins, &histRange );
    calcHist( &bgr[1], 1, 0, Mat(), g_hist, 1, &numbins, &histRange );
    calcHist( &bgr[2], 1, 0, Mat(), r_hist, 1, &numbins, &histRange );
    calcHist( &grey, 1, 0, Mat(), grey_hist, 1, &numbins, &histRange );
// Draw the histogram
// We go to draw lines for each channel
    int width= 512;
    int height= 300;

    // Create image with gray base
    Mat histImage( height, width, CV_8UC3, Scalar(212,212,213) );
    // Normalize the histograms to height of image
    normalize(b_hist, b_hist, 0, height, NORM_MINMAX );
    normalize(g_hist, g_hist, 0, height, NORM_MINMAX );
    normalize(r_hist, r_hist, 0, height, NORM_MINMAX );
    normalize(grey_hist, grey_hist, 0, height, NORM_MINMAX );

    int binStep= cvRound((float)width/(float)numbins);
    for( int i=1; i< numbins; i++) {
        if ((i == numbins/4) || (i == numbins/4*2)||(i == numbins/4*3)  ){
            line(histImage, Point( binStep*i, 0 ), Point(binStep*i, height-1),Scalar(100,100,100));
            }

        line( histImage,
              Point( binStep*(i-1), height-cvRound(b_hist.at<float>(i-1) ) ),
//              Point( binStep*(i), height-cvRound(b_hist.at<float>(i) ) ),
              Point( binStep*(i-1), height),
              Scalar(255,0,0));
        line( histImage,
              Point( binStep*(i-1), height-cvRound(g_hist.at<float>(i-1) ) ),
//              Point( binStep*(i), height-cvRound(g_hist.at<float>(i) ) ),
              Point( binStep*(i-1), height),
              Scalar(0,255,0));
        line( histImage,
              Point( binStep*(i-1), height-cvRound(r_hist.at<float>(i-1) ) ),
//              Point( binStep*(i), height-cvRound(r_hist.at<float>(i) ) ),
              Point( binStep*(i-1), height),
              Scalar(0,0,255));
        line( histImage,
              Point( binStep*(i-1), height-cvRound(grey_hist.at<float>(i-1) ) ),
//              Point( binStep*(i), height-cvRound(b_hist.at<float>(i) ) ),
              Point( binStep*(i-1), height),
              Scalar(199,199,199));
    }
    imshow("Histogram", histImage);

    }


Mat generateHistoCallback(const Mat& src, int width, int height) {
// generate Gray image
    Mat img = src;
    Mat grey;
    cvtColor(img, grey, COLOR_BGR2GRAY);
// Separate image in BRG
    vector<Mat> bgr;
    split(img, bgr );
// Create the histogram for 256 bins
    // The number of possibles values [0..255]
    int numbins= width;

// Set the ranges ( for B,G,R) ), last is not included
    float range[] = { 0, 256 } ;
    const float* histRange = { range };

    Mat b_hist, g_hist, r_hist, grey_hist;

    calcHist( &bgr[0], 1, nullptr, Mat(), b_hist, 1, &numbins, &histRange );
    calcHist( &bgr[1], 1, nullptr, Mat(), g_hist, 1, &numbins, &histRange );
    calcHist( &bgr[2], 1, nullptr, Mat(), r_hist, 1, &numbins, &histRange );
    calcHist( &grey, 1, nullptr, Mat(), grey_hist, 1, &numbins, &histRange );
// Draw the histogram


// draw lines for each channel
    // Create image with gray base
    Mat histImage( height, width, CV_8UC3, Scalar(99,99,99) );
    // Normalize the histograms to height of image
    normalize(b_hist, b_hist, 0, height, NORM_MINMAX );
    normalize(g_hist, g_hist, 0, height, NORM_MINMAX );
    normalize(r_hist, r_hist, 0, height, NORM_MINMAX );
    normalize(grey_hist, grey_hist, 0, height, NORM_MINMAX );

    int binStep= cvRound((float)width/(float)numbins);
    for( int i=1; i< numbins; i++) {
        if ((i == numbins/4) || (i == numbins/4*2)||(i == numbins/4*3)  ){
            line(histImage, Point( binStep*i, 0 ), Point(binStep*i, height-1),Scalar(100,100,100));
            }

        line( histImage,
              Point( binStep*(i-1), height-cvRound(b_hist.at<float>(i-1) ) ),
              Point( binStep*(i-1), height),
              Scalar(255,0,0));
        line( histImage,
              Point( binStep*(i-1), height-cvRound(g_hist.at<float>(i-1) ) ),
              Point( binStep*(i-1), height),
              Scalar(0,255,0));
        line( histImage,
              Point( binStep*(i-1), height-cvRound(r_hist.at<float>(i-1) ) ),
              Point( binStep*(i-1), height),
              Scalar(0,0,255));
        line( histImage,
              Point( binStep*(i-1), height-cvRound(grey_hist.at<float>(i-1) ) ),
//              Point( binStep*(i), height-cvRound(b_hist.at<float>(i) ) ),
              Point( binStep*(i-1), height),
              Scalar(199,199,199));
    }
    return histImage;
    }
























