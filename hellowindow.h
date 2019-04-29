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
    void generate_hello();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::HelloWindow *ui;

    QWizardPage *createPage1();
    QWizardPage *createPage2();
    QWizardPage *createPage3();
    QWizardPage *createPage4();

};

#endif // HELLOWINDOW_H
