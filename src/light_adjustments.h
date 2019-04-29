#ifndef LIGHT_ADJUSTMENTS_H
#define LIGHT_ADJUSTMENTS_H
#include <iostream>
using namespace std;

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;


class imgSDHL {

public:

/*
 * Method: Constructor and Deconstructor
 * Usage: imgSDHL imgsdhl;
 * ------------------------------
 * In the constructor, the instance variable Shadow is set to 0
 * while Highlight is set to 255. The constructor also invokes
 * the initializeTable method.
 */

    imgSDHL();

    virtual ~imgSDHL();

/*
 * Method: setShadow  setHighlight
 * Usage: imgsdhl.setShadow(a)  imgsdhl.setHighlight(b);
 * ------------------------------
 * The setShadow method and the setHighlight method are the setters of
 * instance variables Shadow and Highlight, respectively. Both values
 * are required to be an integer from 0 to 255, and these two methods
 * will check whether the specified values fall into the valid range.
 */

    void setShadow(int p_shadow);

    void setHighlight(int p_highlight);

/*
 * Method: initializeTable  createTable
 * Usage: imgsdhl.initializeTable()  imgsdhl.createTable();
 * ------------------------------
 * The initializeTable method initializes the instance variable colorTables
 * to be an array whose value of each entry is equal to the corresponding
 * index. This method is invoked in the constructor of the class. The
 * createTable method updates the colorTables according to the value of
 * Shadow and Highlight. This method is invoked in the adjust method.
 */

    void initializeTable();

    bool createTable();

/*
 * Method: adjust
 * Usage: imgsdhl.adjust(imgBefore, imgAfter);
 * ------------------------------
 * The adjust method iterates through all the pixel of the image. For
 * each pixel, using the B/G/R value of the old image as index, obtain
 * the B/G/R value of the new image from array colorTables.
 */

    int adjust(Mat input, Mat output);

private:

    int   Shadow;
    int   Highlight;
    uchar colorTables[256];

};

#endif // LIGHT_ADJUSTMENTS_H
