#ifndef MAIN_PIC_H
#define MAIN_PIC_H
#include "iostream"
#include <vector>
// OpenCV includes
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

using namespace std;

/*
 * Class: main_pic
 * --------------------
 * The is the data struction for storing
 * large images and small images.
 */

class main_pic
{
public:

    /*
     * Constructor: main_pic()
     * ------------------------------
     * Initializes the main_pic with empty vectors
     * of large and small images.
     */
    main_pic();

    /*
     * Constructor: main_pic(small, large)
     * ------------------------------
     * Initializes the main_pic with inputed
     * large and small images.
     */

    main_pic(cv::Mat small,cv::Mat large);

    /*
     * Method: get_small_pic
     * Usage: pic = main_picture.get_small_pic();
     * -----------------------------------------
     * Return the latest small picture.
     */

    cv::Mat get_small_pic();

    /*
     * Method: get_large_pic
     * Usage: pic = main_picture.get_large_pic();
     * -----------------------------------------
     * Return the latest large picture.
     */

    cv::Mat get_large_pic();

    /*
     * Method: regret
     * Usage: pic = main_picture.regret();
     * -----------------------------------
     * delete the latest large and small images,
     * and return the latest small picture.
     */

    cv::Mat regret();

    /*
     * Method: isEmpty
     * Usage: test = main_picture.isEmpty();
     * -------------------------------------
     * test whether there is no small picture.
     */

    bool isEmpty();

    /*
     * Method: consistent
     * Usage: test = main_picture.consistent();
     * -------------------------------------
     * test whether the number of large images
     * is the same as small images.
     */

    bool consistent();

    /*
     * Method: push_small
     * Usage: pic2 = main_picture.push_small(pic);
     * -----------------------------------------
     * Record the pic as a small picture and return it.
     */

    cv::Mat push_small(cv::Mat& img);

    /*
     * Method: push_large
     * Usage: pic2 = main_picture.push_large(pic);
     * -----------------------------------------
     * Record the pic as a small picture and return it.
     */

    cv::Mat push_large(cv::Mat& img);

    /*
     * Method: get_original_large
     * Usage: pic = main_picture.get_original_large();
     * -----------------------------------------
     * Return the original large picture,
     */

    cv::Mat get_original_large();

    /*
     * Method: get_original_small
     * Usage: pic = main_picture.get_original_small();
     * -----------------------------------------
     * Return the original small picture,
     */

    cv::Mat get_original_small();

    /*
     * Method: recover
     * Usage: main_picture.recover();
     * -----------------------------------------
     * Discard every change made to the original pictures.
     */

    void recover();

private:
    cv::Mat original_large = cv::Mat(2, 2, CV_8UC3, cv::Scalar::all(1)); //orginal large picture
    cv::Mat original_small = cv::Mat(2, 2, CV_8UC3, cv::Scalar::all(1)); //orginal small picture
    vector<cv::Mat> small_vec;  //vector of small pictures
    vector<cv::Mat> large_vec;  //vector of large pictures
    int smallsize = small_vec.size();
    int largesize = large_vec.size();
};

#endif // MAIN_PIC_H
