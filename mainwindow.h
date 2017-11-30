#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_openButton_clicked(); // open file using qt
    void openFile(const QString &fileName); // file open process
    void on_covertImage_clicked(); //그림 입히기 - 이설희
    void on_Mosaic_clicked(); //모자이크 - 장예솔
    void on_calibration_clicked(); //점 (자동) 없애기 - 허정우
    void on_convertFace_clicked(); //얼굴 바꾸기 - 조민규

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
