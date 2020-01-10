#include <QDebug>

#include "PlotGeneration.h"

PlotGeneration::PlotGeneration()
{
    QVector<double> x(5000), y(5000); // plot1
    double a = 0.0;
    for (int i=0; i<5000; ++i)
    {
        x[i] = i;

        a = a + ( (double) rand() / ((double) RAND_MAX / 2) ) -1;
        if (a > 1) a = 1;
        if (a < -1) a = -1;
        y[i] = a;

//        if (x[i] <= 490) {y[i] = 0;}
//        else if (491 <= x[i] && x[i] <= 510) {y[i] = -0.5;}
//        else if (511 <= x[i] <= 990) {y[i] = 0;}
//        else
//        {
//            a = a + ( (double) rand() / ((double) RAND_MAX / 2) ) -1;
//            if (a > 1) a = 1;
//            if (a < -1) a = -1;
//            y[i] = a;
//        }
    }

    addGraph();
    graph(0)->setData(x, y);
    graph(0)->setPen(QPen(Qt::black, 0.4));

    xAxis->setRange(0, 500);
    yAxis->setRange(-1.1, 1.1);

//    setInteraction(QCP::iRangeDrag);

//    axisRect()->setRangeDrag(Qt::Horizontal);

    // ###### Decrease the memory needed to drag. Slightly at least, may be not noticeable
//    setNoAntialiasingOnDrag(true);
//    xAxis->grid()->setVisible(false);
    // ######

    xAxis->setVisible(false);
    yAxis->setVisible(false);

    axisRect()->setAutoMargins(QCP::msNone);
    axisRect()->setMargins(QMargins(0, 0, 0, 0));

//    setFixedHeight(30); // Remplacer par une mesure dynamique.
//    setFixedWidth(500); // Remplacer par une mesure dynamique de la fenêtre.
//    setBackground(QBrush(QColor(240, 222, 173)));
    setStyleSheet(("background:hsva(255, 255, 255, 0%);"));
    setBackground(QBrush(Qt::NoBrush));
}



PlotGeneration::~PlotGeneration()
{

}
