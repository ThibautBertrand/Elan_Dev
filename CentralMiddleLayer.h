#ifndef CENTRALMIDDLELAYER_H
#define CENTRALMIDDLELAYER_H

#include <QWidget>
#include <QListWidget>
#include <QDebug>

#include "Wrapper.h"
#include "PlotGeneration.h"
#include "qcustomplot.h"

class CentralMiddleLayer : public QWidget
{

    Q_OBJECT

public:
    CentralMiddleLayer(QSize size);
    ~CentralMiddleLayer();

//    void connectPlot(PlotGeneration *plot);


    QCPRange actualRange;
    double lowerRangeMin = 0; // There is no data under x = 0 #############
    double upperRangeMax; // it's the last point of the data
    double scale; // scale of the x-axis, how mant points to show per pages
    int page; // Number of the actual page

    void setActualRange(double lower);

    QVector<double> x, y;


signals:

    void sendData(double);
    void sendPage(int);

public slots:
//    void XAxisChanged(QCPRange range);
//    void mouseClick(QMouseEvent*);

    void pageChange(QMouseEvent *);
    void averageAtCursor(double posX);


private:
    QList<PlotGeneration*> allPlot;
};

#endif // CENTRALMIDDLELAYER_H
