#include "SettingWindow.h"
#include "ui_SettingWindow.h"

SettingWindow::SettingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingWindow)
{
    ui->setupUi(this);

    connect(this->ui->OKButton, SIGNAL(clicked()),
            this, SLOT(close()));

    connect(this->ui->applyButton, SIGNAL(clicked()),
            this, SLOT(SendRequestColorChange()));

    connect(this->ui->defaultButton, SIGNAL(clicked()),
            this, SLOT(SendRequestColorDefault()));
}

SettingWindow::~SettingWindow()
{
    delete ui;
}


void SettingWindow::SendRequestColorChange()
{
//    int R = ui->editRed->text().toInt();
//    int G = ui->editGreen->text().toInt();
//    int B = ui->editBlue->text().toInt();

    emit RequestColorChange(QColor(ui->editRed->text().toInt(),
                                   ui->editGreen->text().toInt(),
                                   ui->editBlue->text().toInt()));
}

void SettingWindow::SendRequestColorDefault()
{
    emit RequestColorChange(QColor(240, 222, 173));
}
