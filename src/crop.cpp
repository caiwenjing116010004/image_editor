#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/highgui.hpp"
#include <iostream>
#include <vector>
using namespace cv;
using namespace std;
/*
 * This is a file partly written by
 * an author from the Internet
 */


//Image crop
//src represents the original image, dst represents the
//changed image


//return value: 0 is success, otherwise failure
int imageCrop(InputArray src, OutputArray dst, Rect rect)
{
    cv::Mat input = src.getMat();
    if( input.empty() ) {
        return -1;
    }

//    computer crop area
    cv::Rect srcRect(0, 0, input.cols, input.rows);
    rect = rect & srcRect;
    if ( rect.width <= 0  || rect.height <= 0 ) return -2;

    //creat destination image
    dst.create(Size(rect.width, rect.height), src.type());
    cv::Mat output = dst.getMat();
    if ( output.empty() ) return -1;

    try {
        //copy the cropped area to the destination image
        input(rect).copyTo( output );
        return 0;
    } catch (...) {
        return -3;
    }
}

const string window_name = "Crop window: press any key to finish";
cv::Mat src;  //source image
bool  isDrag = false;
//vector containing diagonal points in the rectangle
vector<Point> rect_point = {Point(0,0),Point(0,0)};



void callbackMouseEvent(int mouseEvent, int x, int y, int flags, void* param)
{
    switch(mouseEvent) {

    case CV_EVENT_LBUTTONDOWN:
        rect_point[0] = Point(x,y);
        rect_point[1] = Point(x,y);
        isDrag = true;
        break;

    case CV_EVENT_MOUSEMOVE:
        if ( isDrag ) {
            rect_point[1] = Point(x,y);
            cv::Mat dst = src.clone();
            Rect rect (rect_point[0],rect_point[1]); //get rectangle
            rectangle(dst, rect, Scalar(0,0,255));// draw rectangle
            imshow(window_name, dst); //show rectangle
        }
        break;

    case CV_EVENT_LBUTTONUP:
        if (isDrag) {
            isDrag = false;
            Rect rect(rect_point[0],rect_point[1]); //get rectangle
            imageCrop(src, src, rect); //crop image
            imshow(window_name, src); //show image
            cout<<x<<y<<endl;
        }
        break;

    }

    return;
}


vector<Point> crop1(cv::Mat& img)
{
    img.copyTo(src);
    //create window
    namedWindow(window_name);
    imshow(window_name, src);

    //set mouse event call back
    setMouseCallback(window_name, callbackMouseEvent, NULL );

    waitKey();
    cv::destroyAllWindows();
    return rect_point;

}
