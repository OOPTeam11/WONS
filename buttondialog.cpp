#include "buttondialog.h"
#include "ui_buttondialog.h"

ButtonDialog::ButtonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ButtonDialog)
{
    ui->setupUi(this);
}

ButtonDialog::~ButtonDialog()
{
    delete ui;
}

void ButtonDialog::on_catButton_clicked()
{
    done(cat);
    this->close();
}

void ButtonDialog::on_cheekButton_clicked()
{
    done(cheek);
    this->close();
}

void ButtonDialog::on_RudolfButton_clicked()
{
    done(rudolf);
    this->close();
}

void ButtonDialog::on_blusherButton_clicked()
{
    done(blusher);
    this->close();
}
