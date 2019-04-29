/*
 * File: developwindow.cpp
 * ------------------------
 * This file is the implementation for the main window of the
 * software. It can be triggered by the hello window. It consists
 * of all the tools that users will use with this image editor.
 */

#include "developwindow.h"
#include "ui_developwindow.h"
#include <cv.h>
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <string>
#include <QScreen>
#include <QMessageBox>
#include <QBuffer>
#include <vector>

// My own code
#include "helper_main.h"
#include "histogram.h"
#include "color_hsl.h"
#include "imagerotate.h"
#include "crop.h"
#include "color_hsl.h"
#include "main.h"
#include "main_pic.h"
#include "geometry.h"
#include "geo_transform.h"
#include "basic_adjustments.h"
#include "filters_packs.h"
using namespace std;
extern cv::Mat openPic;

developWindow::developWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::developWindow)
{
    ui->setupUi(this);
    setUnifiedTitleAndToolBarOnMac(true);
    ui->menubar->setNativeMenuBar(false);
    pict = openPic;
    dst_large = pict;
    main_picture.push_large(dst_large);
    pict = compress(pict);
    main_picture.push_small(pict);
    dst = pict;
    present(dst_large,*ui->label,*ui->label_2);
    ui->contrast->actions();
}

developWindow::~developWindow()
{
    delete ui;
}


void developWindow::on_actionUndo_triggered()
{
    main_picture.regret();
    cv::Mat pic = main_picture.get_small_pic();
    slider_recover();
    done_already = true;
    present(pic,*ui->label,*ui->label_2);
}

void developWindow::on_actionRecover_triggered()
{
    main_picture.recover();
    cv::Mat pic = main_picture.get_small_pic();
    slider_recover();
    color_vec = {{0,0,0},
                 {0,0,0},
                 {0,0,0},
                 {0,0,0},
                 {0,0,0},
                 {0,0,0},
                 {0,0,0}};
    dst = main_picture.get_original_small();
    dst_large = main_picture.get_original_large();
    present(pic,*ui->label,*ui->label_2);
    done_already = true;
}

void developWindow::on_actionOpen_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "open", ".", "Image(*jpg)");
    pict  = cv::imread(fileName.toStdString()); // read an image
    dst_large = pict;
    main_picture.push_large(dst_large);
    pict = compress(pict);  // create smaller image

    main_picture.push_small(pict);
    dst = pict;
    present(dst,*ui->label,*ui->label_2); //show the small image
}

//    Functions that have no connection with image
//    adjustment

void developWindow::on_Donebutton_clicked()
{
    cv::Mat large_pic = main_picture.get_large_pic();
    switch (current_adjust.back()) { // switch between different adjustments
    case Hue:
        dst_large = hue_adjust(large_pic,ui->hue->value(),ui->colour_choose->value());
        break;
    case Satuation:
        dst_large = satuation_adjust(large_pic,ui->satuation->value(),ui->colour_choose->value());
        break;
    case Brightness:
        dst_large = brightness_adjust(large_pic,ui->satuation->value(),ui->colour_choose->value());
        break;
    case HSL_adj:
        break;
    case Geo_up:
        dst_large =  trans_up(large_pic,ui->geometry->value(),large_pic.cols,large_pic.rows);
        break;
    case Geo_down:
        dst_large = trans_below(large_pic,ui->geometric_below->value(),large_pic.cols,large_pic.rows);
        break;
    case Contrast:
        dst_large = contrastAdjust(large_pic,ui->contrast->value());
        break;
    case Brightness_2:
        dst_large = brightnessAdjust(large_pic,ui->brightness_2->value());
        break;
    case Rotate_adj:
    {
        bool crop;
        Qt::CheckState state =  ui->rotate_crop->checkState();
        if (state == Qt::Unchecked){
            crop = false;
        }else{
            crop = true;
        }
        imageRotate(large_pic,dst_large,ui->rotation->value()*90/50,crop);
        break;
    }
    case Shadow_adj:
        dst_large = imgShadow(large_pic,ui->shadow->value()*5);
        break;
    case Highlight_adj:
        dst_large = imgHighlight(large_pic,ui->highlight->value()*5);
        break;
    case Warmth_adj:
        dst_large = imgWarmth(large_pic,ui->warmth->value()*3/5);
        break;
    case Satuation_2_adj:
        dst_large = imgSatuation(large_pic,ui->satuation_full->value());
        break;
    case Blur_adj:
    {
        int size = ui->blur->value();
        cv::Mat im_small = main_picture.get_small_pic();
        dst_large = imgBlur(im_small,size);
        break;
    }
    case Sharpen_adj:
    {
        double other = double(ui->sharpen->value())/double(30);
        dst_large = imgSharpen(large_pic,other);
        break;
    }
    default:
        break;
    }
    slider_recover();   //recover all the sliders to the original position
    main_picture.push_small(dst);
    main_picture.push_large(dst_large);
    done_already = true;
    ui->textBrowser->clear();
    present(dst,*ui->label,*ui->label_2);
}





// Button



//HSL

void developWindow::on_hue_valueChanged(int value)
{
    adjust present_adjust = Hue;
    if (check_done(present_adjust)){
        current_adjust.push_back(present_adjust);
        done_already = false;
        cv::Mat picture = main_picture.get_small_pic();
        if (value != color_vec[present_colour][0]) {
            dst = hue_adjust(picture,value, ui->colour_choose->value());
            present(dst,*ui->label,*ui->label_2);
        }
    }else {
        ui->textBrowser->clear();
        ui->textBrowser->append("press done");
    }
}

void developWindow::on_satuation_valueChanged(int value)
{
    adjust present_adjust = Satuation;
    if (check_done(present_adjust) && response == true){

        current_adjust.push_back(present_adjust);
        done_already = false;
        check_done(present_adjust);
        cv::Mat picture = main_picture.get_small_pic();
        if (value != color_vec[present_colour][1]) {
            dst = satuation_adjust(picture,value, ui->colour_choose->value());
            present(dst,*ui->label,*ui->label_2);
        }
    }else {
        ui->textBrowser->clear();
        ui->textBrowser->append("press done");
    }

}

void developWindow::on_brightness_valueChanged(int value)
{
    adjust present_adjust = Brightness;
    if (check_done(present_adjust) && response == true){
        current_adjust.push_back(present_adjust);
        done_already = false;
        check_done(present_adjust);
        cv::Mat picture = main_picture.get_small_pic();
        if (value != color_vec[present_colour][2]) {
            dst = brightness_adjust(picture,value, ui->colour_choose->value());
            present(dst,*ui->label,*ui->label_2);
        }
    }else{
        ui->textBrowser->clear();
        ui->textBrowser->append("press done");
    }
}

void developWindow::on_colour_choose_valueChanged(int value)
{
    color_vec[present_colour][0] = ui->hue->value();
    color_vec[present_colour][1] = ui->satuation->value();
    color_vec[present_colour][2] = ui->brightness->value();
    present_colour = value;

    ui->hue->setValue(color_vec[value][0]);
    ui->satuation->setValue(color_vec[value][1]);
    ui->brightness->setValue(color_vec[value][2]);
    done_already = false;
    colour = value;
}





void developWindow::on_rotation_valueChanged(int value)
{
    adjust present_adjust = Rotate_adj;
    if (!check_done(present_adjust)){
        ui->textBrowser->clear();
        ui->textBrowser->append("press done");
    } else if (check_done(present_adjust) && response == true){
        done_already = false;
        current_adjust.push_back(present_adjust);
        cv::Mat pic = main_picture.get_small_pic();
        bool crop;
        Qt::CheckState state =  ui->rotate_crop->checkState();
        if (state == Qt::Unchecked){
            crop = false;
        }else{
            crop = true;
        }
        imageRotate(pic,dst,value*90/50,crop);
        present(dst,*ui->label,*ui->label_2);
    }
}



//helper


bool developWindow::check_done(adjust present_adjust){
    if (current_adjust.back() != present_adjust && done_already == false) {
        return false;
    } else{
        return true;
    }
}


void developWindow::slider_recover(){   // recover all the sliders to the original position
    response = false;
    ui->hue->setValue(0);
    ui->satuation->setValue(0);
    ui->brightness->setValue(0);
    ui->geometry->setValue(0);
    ui->geometric_below->setValue(0);
    ui->contrast->setValue(0);
    ui->brightness_2->setValue(0);
    ui->rotation->setValue(0);
    ui->shadow->setValue(0);
    ui->highlight->setValue(0);
    ui->warmth->setValue(0);
    ui->satuation_full->setValue(0);
    ui->blur->setValue(0);
    ui->sharpen->setValue(0);
    response = true;
}

void developWindow::button_change(button Button_click){
    cv::Mat picture = main_picture.get_small_pic();
    cv::Mat large = main_picture.get_large_pic();
    switch (Button_click) {
    case Portrait: dst = portrait(picture); dst_large = portrait(large); break;
    case Remove_flaw: dst = removeFlaw(picture); dst_large = removeFlaw(large); break;
    case Waterscape: dst = waterscape(picture); dst_large = waterscape(large); break;
    case Architecture: dst = architecture(picture); dst_large = architecture(large); break;
    case Vintage: dst = vintage(picture); dst_large = vintage(large); break;
    case Sketch: dst = sketch(picture); dst_large = sketch(large); break;
    case Black_white: dst = blackAndWhite(picture); dst_large = blackAndWhite(large); break;
    case Plant: dst = plant(picture); dst_large = plant(large); break;
    case Flip: dst = imgFlip(picture); dst_large = imgFlip(large); break;
    case Rotate_right: dst = imgClockwise(picture); dst_large = imgClockwise(large); break;
    case Rotate_left: dst = imgCounterClockwise(picture); dst_large = imgCounterClockwise(large); break;
    case Whitebalance:dst = whiteBalance(picture); dst_large = whiteBalance(large); break;
    case Border: dst = imgBorder(picture,2); dst_large = imgBorder(large, 2 * compress_number(large)); break;
    }
    present(dst,*ui->label,*ui->label_2);
    main_picture.push_small(dst);
    main_picture.push_large(dst_large);
}
void developWindow::on_actionBorder_triggered()
{
    button_change(Border);
}
void developWindow::on_actionflip_triggered()
{
    button_change(Flip);
}

void developWindow::on_actionrotateright_triggered()
{
    button_change(Rotate_right);
}

void developWindow::on_actionrotateleft_triggered()
{
    button_change(Rotate_left);
}

void developWindow::on_whitebalance_clicked()
{
    button_change(Whitebalance);
}

void developWindow::on_actionPortrait_triggered()
{
    button_change(Portrait);
}

void developWindow::on_actionRemoveFlaw_triggered()
{
    button_change(Remove_flaw);
}

void developWindow::on_actionWaterscape_triggered()
{
    button_change(Waterscape);
}

void developWindow::on_actionArchitecture_triggered()
{
    button_change(Architecture);
}

void developWindow::on_actionVintage_triggered()
{
    button_change(Vintage);
}

void developWindow::on_actionSketch_triggered()
{
    button_change(Sketch);
}

void developWindow::on_actionBlackAndWhite_triggered()
{
    button_change(Black_white);
}

void developWindow::on_actionPlant_triggered()
{
    button_change(Plant);
}

void developWindow::slider_change(int value, adjust present_adjust){
    if (!check_done(present_adjust)){
        ui->textBrowser->clear();
        ui->textBrowser->append("press done");
    } else if (check_done(present_adjust) && response == true){
        done_already = false;
        current_adjust.push_back(present_adjust);
        cv::Mat picture = main_picture.get_small_pic();
        int change;
        double minor_change;
        switch (present_adjust) {
            case Shadow_adj: change = value *5; dst = imgShadow(picture,change); break;
            case Highlight_adj: change = value *5; dst = imgHighlight(picture,change); break;
            case Warmth_adj: change = value *3/5; dst = imgWarmth(picture,change); break;
            case Satuation_2_adj: change = value; dst = imgSatuation(picture,change); break;
            case Blur_adj: change = value; dst = imgBlur(picture,change); break;
            case Contrast: change = value; dst = contrastAdjust(picture,change); break;
            case Sharpen_adj: minor_change = double(value)/double(30); dst = imgSharpen(picture,minor_change); break;
            case Brightness_2: change = value; dst = brightnessAdjust(picture, value); break;
            case Geo_up: change = value; dst = trans_up(picture,value,picture.cols,picture.rows); break;
            case Geo_down: change = value; dst = trans_below(picture,value,picture.cols,picture.rows); break;

            default: return;
        }
        present(dst,*ui->label,*ui->label_2);
    }
}


void developWindow::on_brightness_2_valueChanged(int value)
{
    slider_change(value, Brightness_2);
}


void developWindow::on_sharpen_valueChanged(int value)
{
    slider_change(value, Sharpen_adj);
}


void developWindow::on_contrast_valueChanged(int value)
{
    slider_change(value, Contrast);
}

void developWindow::on_shadow_valueChanged(int value)  // same
{
    slider_change(value, Shadow_adj);
}

void developWindow::on_highlight_valueChanged(int value) // same
{
    slider_change(value, Highlight_adj);
}

void developWindow::on_warmth_valueChanged(int value) // same
{
    slider_change(value, Warmth_adj);
}

void developWindow::on_satuation_full_valueChanged(int value) // same
{
    slider_change(value, Satuation_2_adj);
}

void developWindow::on_geometry_valueChanged(int value)
{
    slider_change(value, Geo_up);
}

void developWindow::on_geometric_below_valueChanged(int value)
{
    slider_change(value, Geo_down);
}


void developWindow::on_blur_valueChanged(int value) // same
{
    slider_change(value, Blur_adj);
}







void developWindow::on_actionSave_triggered()    // save button
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save"), ".",
                              tr("Image (*.jpg)"));
        if(fileName.length() == 0) {
            QMessageBox::information(NULL, tr("Path"), tr("You didn't save the file."));
        } else {
            string fileAsSave = fileName.toStdString();
            cv::imwrite(fileAsSave, main_picture.get_large_pic());
        }
}

void developWindow::on_actionfull_picture_triggered()
{
    cv::Mat pic = main_picture.get_large_pic();
    present(pic,*ui->label,*ui->label_2);
}

void developWindow::on_actionOrginal_triggered()
{
    cv::Mat pic = main_picture.get_original_small();
    present(pic,*ui->label,*ui->label_2);
}

void developWindow::on_actionPresent_triggered()
{
    cv::Mat pic = main_picture.get_small_pic();
    present(pic,*ui->label,*ui->label_2);
}

void developWindow::on_actioncrop_pic_triggered()
{
    cv::Mat pic = main_picture.get_small_pic();
    vector<cv::Point> rect_point;
    rect_point = crop1(pic);
    Rect rect(rect_point[0],rect_point[1]);
    int num = compress_number(dst_large);
    Rect rect_large(rect_point[0]*num,rect_point[1]*num);
    imageCrop(pic,pic,rect);
    imageCrop(dst_large,dst_large,rect_large);
    main_picture.push_small(pic);
    main_picture.push_large(dst_large);
    present(pic,*ui->label,*ui->label_2);
}


