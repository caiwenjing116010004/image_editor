#include "hellowindow.h"
#include "ui_hellowindow.h"
#include "developwindow.h"
#include<cv.h>
#include<opencv2/opencv.hpp>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

cv::Mat openPic;


HelloWindow::HelloWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HelloWindow)
{
    ui->setupUi(this);
}

HelloWindow::~HelloWindow()
{
    delete ui;
}
//*.bmp *.pbm *.pgm *.png *.ppm *.xbm *.xpm
void HelloWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "open", ".",
                                    "Image (*.jpg)");
    if(fileName.length() == 0) {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
    } else {
        openPic  = cv::imread(fileName.toStdString()); //读入一张图片 暂时读入桌面上的一个文件
        developWindow *develop = new developWindow();
        develop ->show();
        this->hide();
    }
}

QWizardPage * HelloWindow::createPage1(){
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("This is a simple Image Editor created by 116010004, 116010103, 116010265"));
    return page;
}

QWizardPage * HelloWindow::createPage2(){
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("Tip 1: In each step of your image change"
                      "if you feel satisfied, you need to press 'Done' button to render the full image"));
    page->setSubTitle(tr("由于软件没有使用多线程运行，出于性能的考虑，您每次实时预览的是压缩过的图片。"
                         "如果您想保存当前的修改，您需要按'Done'按钮，这样您可以查看原图的效果。"
                         "否则这步操作不会被保存。"
                         "如给您带来不便，敬请谅解。"));
    return page;
}

QWizardPage * HelloWindow::createPage3(){
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("Finally, please remember do not use Chinese name in the file path!"));
    page->setSubTitle(tr("最后一点，请不要在文件路径中写中文！"));
    return page;
}

void HelloWindow::on_pushButton_2_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("Guideline For ImageEditor"));
    wizard.addPage(createPage1());
    wizard.addPage(createPage2());
    wizard.addPage(createPage3());
    wizard.exec();
}
