/*
 * File: developwindow.h
 * ------------------------
 * This file is the header file for the main window of the
 * software. It can be triggered by the hello window. It consists
 * of all the tools that users will use with this image editor.
 * It defines a class called developWindow and an enum that
 * contains all the adjustments.
 */

#ifndef DEVELOPWINDOW_H
#define DEVELOPWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include <QTextCodec>
#include<cv.h>
#include <vector>
#include<opencv2/opencv.hpp>
#include "main_pic.h"

using namespace std;

/*
 * enum: adjust
 * ------------
 * This enum stores all the adjustments which apply the
 * Qslider. It helps with previously used adjustments.
 */

enum adjust {
    Set,  // undefined adjust
    Hue,
    Satuation,
    Brightness,
    HSL_adj,
    Geo_up,
    Geo_down,
    Contrast,
    Brightness_2,
    Rotate_adj,
    Shadow_adj,
    Highlight_adj,
    Warmth_adj,
    Satuation_2_adj,
    Blur_adj,
    Sharpen_adj
};

enum button {
    Architecture,
    Black_white,
    Plant,
    Portrait,
    Remove_flaw,
    Sketch,
    Waterscape,
    Vintage,
    Border,
    Whitebalance,
    Rotate_left,
    Rotate_right,
    Flip,
};

namespace Ui {

/*
 * Class: developWindow
 * --------------------
 * The is the main window for the software.
 * It can be triggered by hello window.
 */

class developWindow;
}

class developWindow : public QMainWindow
{
    Q_OBJECT

public:

    /*
     * Constructor: developWindow
     * ------------------------------
     * Initializes the developWindow.
     */

    explicit developWindow(QWidget *parent = 0);

    /*
     * Destructor: ~developWindow
     * --------------------------
     * Destruct the developWindow
     */

    ~developWindow();

private slots:

//    Functions that have no connection with image
//    adjustment

    /*
     * Method: on_actionUndo_triggered
     * Usage on_actionUndo_triggered();
     * --------------------------------
     * This is a private slot for the undo button
     * in the menubar. It discards the latest change
     * and show the previous image.
     */

    void on_actionUndo_triggered();

    /*
     * Method: on_actionRecover_triggered
     * Usage on_actionRecover_triggered();
     * ----------------------------------
     * This is a private slot for the Recover button
     * in the menubar. It discards all changes and reture
     * the image to its original form and all
     * sliders to its original position
     */

    void on_actionRecover_triggered();

    /*
     * Method: on_actionOrginal_triggered
     * Usage on_actionOrginal_triggered();
     * ----------------------------------
     * This is a private slot for the Original button
     * in the menubar. It shows the original compressed
     * image
     */

    void on_actionOrginal_triggered();

    /*
     * Method: on_actionPresent_triggered
     * Usage on_actionPresent_triggered();
     * ----------------------------------
     * This is a private slot for the Present button
     * in the menubar. It shows the latest version
     * of image that user has changed.
     */

    void on_actionPresent_triggered();

    /*
     * Method: on_Donebutton_clicked
     * Usage on_Donebutton_clicked();
     * ------------------------------
     * This is a private slot for the Done button
     * in main window. It applies the latest change
     * to the large picture and returns all the sliders
     * to their original position.
     */

    void on_Donebutton_clicked();

    /*
     * Method: on_actionOpen_file_triggered
     * Usage on_actionOpen_file_triggered();
     * ----------------------------------
     * This is a private slot for the Open button
     * in the menubar. It opens the image and creates
     * the small image.
     */

    void on_actionOpen_file_triggered();

    /*
     * Method: on_actionSave_triggered
     * Usage on_actionSave_triggered();
     * --------------------------------
     * This is a private slot for the Save button
     * in the menubar. It Save the large image to the disk.
     */

    void on_actionSave_triggered();

    /*
     * Method: on_actionfull_picture_triggered
     * Usage on_actionfull_picture_triggered();
     * ----------------------------------
     * This is a private slot for the full picture button
     * in the menubar. It shows the latest large image.
     */

    void on_actionfull_picture_triggered();



//    adjustment methods

    /*
     * Method: on_satuation_valueChanged
     * Usage on_satuation_valueChanged(value);
     * ----------------------------------
     * This is a private slot for the satuation slider
     * belonging to the HSL function. It delivers the
     * value to the satuation function and apply it
     * to the dst image.
     */

    void on_satuation_valueChanged(int value);

    /*
     * Method: on_hue_valueChanged
     * Usage on_hue_valueChanged(value);
     * ----------------------------------
     * This is a private slot for the hue slider
     * belonging to the HSL function. It delivers the
     * value to the hue function and apply it
     * to the dst image.
     */

    void on_hue_valueChanged(int value);

    /*
     * Method: on_brightness_valueChanged
     * Usage on_brightness_valueChanged(value);
     * ----------------------------------
     * This is a private slot for the brightness slider
     * belonging to the HSL function. It delivers the
     * value to the brightness function and apply it
     * to the dst image.
     */

    void on_brightness_valueChanged(int value);

    /*
     * Method: on_colour_choose_valueChanged
     * Usage on_colour_choose_valueChanged(value);
     * ----------------------------------
     * This is a private slot for the colour slider
     * belonging to the HSL function. It chooses the
     * colour for the modification of the HSL function
     */

    void on_colour_choose_valueChanged(int value);

    /*
     * Method: on_geometry_valueChanged
     * Usage on_geometry_valueChanged(value);
     * ----------------------------------
     * This is a private slot for the geometry transform
     * slider. It applies the affine transformation using
     * the upper two position points.
     */

    void on_geometry_valueChanged(int value);

    /*
     * Method: on_geometric_below_valueChanged
     * Usage on_geometric_below_valueChanged(value);
     * ----------------------------------
     * This is a private slot for the geometry transform
     * slider. It applies the affine transformation using
     * the lower two position points.
     */

    void on_geometric_below_valueChanged(int value);

    /*
     * Method: on_contrast_valueChanged
     * Usage on_contrast_valueChanged(value);
     * ----------------------------------
     * This is a private slot for the contrast
     * slider. It changes the contrast value for
     * the small image.
     */

    void on_contrast_valueChanged(int value);

    /*
     * Method: on_brightness_2_valueChanged
     * Usage on_brightness_2_valueChanged(value);
     * ----------------------------------
     * This is a private slot for the brightness_2
     * slider. It changes the general brightness value
     * for the small image.
     */

    void on_brightness_2_valueChanged(int value);

    /*
     * Method: on_whitebalance_clicked
     * Usage on_whitebalance_clicked();
     * ----------------------------------
     * This is a private slot for the whitebalance
     * button. It automatically changes the general
     * whitebalance value for the small image and the
     * large image.
     */

    void on_whitebalance_clicked();


    /*
     * Method: on_rotation_valueChanged
     * Usage on_rotation_valueChanged(value);
     * ----------------------------------
     * This is a private slot for the rotation
     * slider. It ratates the small image clockwisely
     * according to the input value as the angle.
     */

    void on_rotation_valueChanged(int value);

    /*
     * Method: on_actionflip_triggered
     * Usage on_actionflip_triggered();
     * ----------------------------------
     * This is a private slot for the flip button in
     * the menubar. It horizontally flips the small image
     * and the large image.
     */

    void on_actionflip_triggered();

    /*
     * Method: on_actionrotateright_triggered
     * Usage on_actionrotateright_triggered();
     * ----------------------------------
     * This is a private slot for the rotateright
     * button in the menubar. It clockwisely rotates
     * the small image and the large image
     * for 90 degrees.
     */

    void on_actionrotateright_triggered();

    /*
     * Method: on_actionrotateleft_triggered
     * Usage on_actionrotateleft_triggered();
     * ----------------------------------
     * This is a private slot for the rotateleft
     * button in the menubar. It anticlockwisely rotates
     * the small image and the large image
     * for 90 degrees.
     */

    void on_actionrotateleft_triggered();

    /*
     * Method: on_actioncrop_pic_triggered
     * Usage on_actioncrop_pic_triggered();
     * ----------------------------------
     * This is a private slot for the Crop
     * button. It creates a new window and asks
     * the user to draw a rectangle and crops that
     * part of the image. Then both the large and
     * the small pictures are cropped.
     */

    void on_actioncrop_pic_triggered();

    /*
     * Method: on_actionPortrait_triggered
     * Usage on_actionPortrait_triggered();
     * ----------------------------------
     * This is a private slot for the portrait filter
     * button in the menubar. It applies the protrait
     * filter to the large and the small images.
     */


    void on_actionPortrait_triggered();

    /*
     * Method: on_actionRemoveFlaw_triggered
     * Usage on_actionRemoveFlaw_triggered();
     * ----------------------------------
     * This is a private slot for the removeFlaw filter
     * button in the menubar. It applies the removeFlaw
     * filter to the large and the small images.
     */

    void on_actionRemoveFlaw_triggered();

    /*
     * Method: on_actionWaterscape_triggered
     * Usage on_actionWaterscape_triggered();
     * ----------------------------------
     * This is a private slot for the Waterscape filter
     * button in the menubar. It applies the Waterscape
     * filter to the large and the small images.
     */

    void on_actionWaterscape_triggered();

    /*
     * Method: on_actionArchitecture_triggered
     * Usage on_actionArchitecture_triggered();
     * ----------------------------------
     * This is a private slot for the Architecture filter
     * button in the menubar. It applies the Architecture
     * filter to the large and the small images.
     */

    void on_actionArchitecture_triggered();

    /*
     * Method: on_actionVintage_triggered
     * Usage on_actionVintage_triggered();
     * ----------------------------------
     * This is a private slot for the Vintage filter
     * button in the menubar. It applies the Vintage
     * filter to the large and the small images.
     */

    void on_actionVintage_triggered();

    /*
     * Method: on_actionSketch_triggered
     * Usage on_actionSketch_triggered();
     * ----------------------------------
     * This is a private slot for the Sketch filter
     * button in the menubar. It applies the Sketch
     * filter to the large and the small images.
     */

    void on_actionSketch_triggered();

    /*
     * Method: on_actionBlackAndWhite_triggered
     * Usage on_actionBlackAndWhite_triggered();
     * ----------------------------------
     * This is a private slot for the BlackAndWhite filter
     * button in the menubar. It applies the BlackAndWhite
     * filter to the large and the small images.
     */

    void on_actionBlackAndWhite_triggered();

    /*
     * Method: on_actionPlant_triggered
     * Usage on_actionPlant_triggered();
     * ----------------------------------
     * This is a private slot for the Plant filter
     * button in the menubar. It applies the plant
     * filter to the large and the small images.
     */

    void on_actionPlant_triggered();

    /*
     * Method: on_actionBorder_triggered
     * Usage on_actionBorder_triggered();
     * ----------------------------------
     * This is a private slot for the Border filter
     * button in the menubar. It applies the Border
     * filter to the large and the small images.
     */

    void on_actionBorder_triggered();

    /*
     * Method: on_shadow_valueChanged
     * Usage on_shadow_valueChanged(value);
     * ----------------------------------
     * This is a private slot for the shadow slider
     * in the main window. It changes the shadow of
     * the small image according to the given value.
     */


    void on_shadow_valueChanged(int value);

    /*
     * Method: on_highlight_valueChanged
     * Usage on_highlight_valueChanged(value);
     * ----------------------------------
     * This is a private slot for the highlight slider
     * in the main window. It changes the highlight of
     * the small image according to the given value.
     */

    void on_highlight_valueChanged(int value);

    /*
     * Method: on_highlight_valueChanged
     * Usage on_highlight_valueChanged(value);
     * ----------------------------------
     * This is a private slot for the highlight slider
     * in the main window. It changes the highlight of
     * the small image according to the given value.
     */

    void on_warmth_valueChanged(int value);

    /*
     * Method: on_satuation_full_valueChanged
     * Usage on_satuation_full_valueChanged(value);
     * ----------------------------------
     * This is a private slot for the satuation_full slider
     * in the main window. It changes the overall satuation of
     * the small image according to the given value.
     */

    void on_satuation_full_valueChanged(int value);

    /*
     * Method: on_blur_valueChanged
     * Usage on_blur_valueChanged(value);
     * ----------------------------------
     * This is a private slot for the highlight slider
     * in the main window. It changes the highlight of
     * the small image according to the given value.
     */

    void on_blur_valueChanged(int value);

    /*
     * Method: on_sharpen_valueChanged
     * Usage on_sharpen_valueChanged(value);
     * ----------------------------------
     * This is a private slot for the sharpen slider
     * in the main window. It sharpens the small image
     * according to the given value.
     */

    void on_sharpen_valueChanged(int value);

    void slider_change(int value, adjust present_adjust);

    void button_change(button Button_click);


//   help function

    /*
     * Method: check_done
     * Usage test = check_done(present_adjust);
     * ----------------------------------
     * This function checks whether the user
     * has press the done button after he has
     * moved one slider and now is moving another
     * slider. If he has not pressed the done
     * button, the function returns false.
     */

    bool check_done(adjust present_adjust);

    /*
     * Method: slider_recover
     * Usage slider_recover();
     * ----------------------------------
     * This function recovers every slider to its
     * original position.
     */

    void slider_recover();



    void on_actionGo_Help_Page_triggered();

private:
    Ui::developWindow *ui;
    // current_adjust records all steps that involves moving slider.
    vector<adjust> current_adjust = {Set};
    // done_already indicates whether the software is read for the
//    user to move another slider.
    bool done_already = true;
    // response indicates whether slider should respond to value change.
    bool response = true;
    // colour for hsl change.
    int colour = 0;
    //another indicator for colour of hsl.
    int present_colour = 0;
    // color_vec records all hsl data with its previously set value
    vector<vector<int>> color_vec = {{0,0,0},
                                     {0,0,0},
                                     {0,0,0},
                                     {0,0,0},
                                     {0,0,0},
                                     {0,0,0},
                                     {0,0,0}};
    // initializing picture
    cv::Mat pict = cv::Mat(2, 2, CV_8UC3, cv::Scalar::all(1));
    // a frequently changed small picture, which is shown every time
    cv::Mat dst = cv::Mat(2, 2, CV_8UC3, cv::Scalar::all(1));
    // large picture which is changed when done is pressed.
    cv::Mat dst_large = cv::Mat(2, 2, CV_8UC3, cv::Scalar::all(1));
    // all picture data for manipulation.
    main_pic main_picture;
};

#endif // DEVELOPWINDOW_H
