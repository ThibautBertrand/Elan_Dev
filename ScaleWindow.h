#ifndef SCALEWINDOW_H
#define SCALEWINDOW_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class ScaleWindow;
}

class ScaleWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ScaleWindow(QWidget *parent = 0);
    ~ScaleWindow();

private:
    Ui::ScaleWindow *ui;

signals:
    void RequestTimeScaleChange();
    void RequestAmplitudeScaleChange();

public slots:
    void SendRequestTimeScaleChange();
    void SendRequestAmplitudeScaleChange();

    void SendRequestTimeScaleDefault();
    void SendRequestAmplitudeScaleDefault();
};

#endif // SCALEWINDOW_H
