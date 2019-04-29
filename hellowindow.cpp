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
void HelloWindow::generate_hello()
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("Guideline For ImageEditor"));
    wizard.addPage(createPage1());
    wizard.addPage(createPage2());
    wizard.addPage(createPage3());
    wizard.addPage(createPage4());
    wizard.exec();
}
QWizardPage * HelloWindow::createPage1(){
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("This is a simple Image Editor created by ：\n蔡文婧：116010004 \n兰一帆：116010103 \n叶成葳：116010265"));
    return page;
}

QWizardPage * HelloWindow::createPage2(){
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("Tip 1: In each step of your image change, "
                      "if you feel satisfied, you need to press 'Done' button to render the full image"));
    page->setSubTitle(tr("由于在大二我们还没有学到多线程，此软件没有运用多线程编程。因此出于流畅度的考虑，您每次实时预览的是压缩过的图片。"
                         "如果您想保存当前的修改，您需要按'Done'按钮，这样您可以查看原图的效果。"
                         "否则这步操作不会被保存。"
                         "如给您带来不便，敬请谅解。"));
    return page;
}

QWizardPage * HelloWindow::createPage3(){
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("Every change you have done is stored in a stack. Feel free to use Undo or Recover function"));
    page->setSubTitle(tr("你进行的所有更改都存储在了一个栈中，因此你可以使用Undo或者Recover功能进行所有更改的撤销."));
    return page;
}

QWizardPage * HelloWindow::createPage4(){
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
    wizard.addPage(createPage4());
    wizard.exec();
}
