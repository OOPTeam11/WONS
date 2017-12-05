#ifndef BUTTONDIALOG_H
#define BUTTONDIALOG_H

#include <QDialog>

namespace Ui {
class ButtonDialog;
}

class ButtonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ButtonDialog(QWidget *parent = 0);
    ~ButtonDialog();

private slots:
    void on_catButton_clicked();

    void on_cheekButton_clicked();

    void on_RudolfButton_clicked();

    void on_blusherButton_clicked();

private:
    Ui::ButtonDialog *ui;
    enum{
        cat = 0,
        rudolf,
        cheek,
        blusher
    };
};

#endif // BUTTONDIALOG_H
