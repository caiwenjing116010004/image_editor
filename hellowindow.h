#ifndef HELLOWINDOW_H
#define HELLOWINDOW_H

#include <QMainWindow>
#include <QWizard>

namespace Ui {
class HelloWindow;
}

class HelloWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HelloWindow(QWidget *parent = 0);
    ~HelloWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::HelloWindow *ui;

    QWizardPage *createPage1();
    QWizardPage *createPage2();
    QWizardPage *createPage3();
};

#endif // HELLOWINDOW_H
