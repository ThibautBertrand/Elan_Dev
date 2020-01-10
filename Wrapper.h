#ifndef WRAPPER_H
#define WRAPPER_H

#include <QWidget>
#include <QResizeEvent>
#include <QDebug>

#include "CentralBottomLayer.h"
#include "CentralMiddleLayer.h"
#include "CentralTopLayer.h"

class Wrapper : public QWidget
{

    Q_OBJECT

public:
    Wrapper(QSize size);

    void resizeEvent(QResizeEvent *e) override;

    void connectPlot();

//    // Child of the Wrapper
    QWidget *bottomLayer; // Background
    QWidget *middleLayer; // Plots
    QWidget *topLayer; // Cursors

signals:

    void DataToDock(double);
    void PageToDock(int);

    void RequestColorChange(QColor);
    void CursorReset(bool);

public slots:
    void truc(double posX);

    void SendDataToDock(double data);
    void SendPageToDock(int page);

    void ResetCursorRequest(bool);
};

#endif // WRAPPER_H
