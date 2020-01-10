#include "ScaleWindow.h"
#include "ui_ScaleWindow.h"

ScaleWindow::ScaleWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScaleWindow)
{
    ui->setupUi(this);

    connect(this->ui->OKButton, SIGNAL(clicked()),
            this, SLOT(close()));

    connect(this->ui->applyTimeButton, SIGNAL(clicked()),
            this, SLOT(SendRequestTimeScaleChange()));
    connect(this->ui->applyAmplitudeButton, SIGNAL(clicked()),
            this, SLOT(SendRequestAmplitudeScaleChange()));
    connect(this->ui->defaultTimeButton, SIGNAL(clicked()),
            this, SLOT(SendRequestTimeScaleDefault()));
    connect(this->ui->defaultAmplitudeButton, SIGNAL(clicked()),
            this, SLOT(SendRequestAmplitudeScaleDefault()));
}

ScaleWindow::~ScaleWindow()
{
    delete ui;
}




void ScaleWindow::SendRequestTimeScaleChange()
{
    emit RequestTimeScaleChange();
}

void ScaleWindow::SendRequestAmplitudeScaleChange()
{
    emit RequestAmplitudeScaleChange();
}




void ScaleWindow::SendRequestTimeScaleDefault()
{
    emit RequestTimeScaleChange();
}

void ScaleWindow::SendRequestAmplitudeScaleDefault()
{
    emit RequestAmplitudeScaleChange();
}
