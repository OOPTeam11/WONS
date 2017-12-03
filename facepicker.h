#ifndef FACEPICKER_H
#define FACEPICKER_H

#endif // FACEPICKER_H

#include <vector>

#include <QDialog>
#include <QGraphicsItem>
#include <QPushButton>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class FacePicker : public QDialog{

    Q_OBJECT

public:
    FacePicker(QWidget *parent = 0);
    // image data, facedata
    FacePicker(QWidget *parent = 0, IplImage *img = 0, std::vector<cv::Rect> *faces = 0);

private:

    QWidget *picker;
    QGraphicsScene *imageScene;
    QGraphicsPixmapItem *imageItem;

    IplImage *img;
    std::vector<cv::Rect> *faces;
    std::vector<QPushButton> buttons;
};
