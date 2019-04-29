#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;

int imageRotate(InputArray src, OutputArray dst, double angle, bool isClip)
{
    Mat input = src.getMat();
    if( input.empty() ) {
        return -1;
    }

    //get size
    int width = input.cols;
    int height = input.rows;

    //compute the origion
    Point2f center;
    center.x = width / 2.0;
    center.y = height / 2.0;

    //get the rotation matrix
    double scale = 1.0;
    Mat trans_mat = getRotationMatrix2D( center, -angle, scale );

    //compute the size of new image
    double angle1 = angle  * CV_PI / 180. ;
    double a = sin(angle1) * scale;
    double b = cos(angle1) * scale;
    double out_width = height * fabs(a) + width * fabs(b); //outer frame width
    double out_height = width * fabs(a) + height * fabs(b);//outer frame height

    int new_width, new_height;
    if ( ! isClip ) {
        new_width = cvRound(out_width);
        new_height = cvRound(out_height);
    } else {
        //calculate width and height of clip rect
        double angle2 = fabs(atan(height * 1.0 / width)); //angle b
        double len = width * fabs(b);
        double Y = len / ( 1 / fabs(tan(angle1)) + 1 / fabs(tan(angle2)) );
        double X = Y * 1 / fabs(tan(angle2));
        new_width = cvRound(out_width - X * 2);
        new_height= cvRound(out_height - Y * 2);
    }

    // add translation to the rotation matrix
    trans_mat.at<double>(0, 2) += cvRound( (new_width - width) / 2 );
    trans_mat.at<double>(1, 2) += cvRound( (new_height - height) / 2);

    //Affine transform
    warpAffine( input, dst, trans_mat, Size(new_width, new_height));

    return 0;
}

