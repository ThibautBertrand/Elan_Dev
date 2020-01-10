/* %%%%%%%%%%%%%%%%%%%%%%%%%
 *
 * This class is the middle layer of the Central Widget of the Main Main Window.
 * It's parent is called the wrapper (which is set to be the central widget).
 * It contains the method to create and update the plots, as well as display
 * them in order with their name.
 *
 * %%%%%%%%%%%%%%%%%%%%%%%%% */


#include "CentralMiddleLayer.h"

CentralMiddleLayer::CentralMiddleLayer(QSize size)
{
    scale = 500.0; // x-axis scale, the number of points on the screen for each plots
    setActualRange(0.0);
    upperRangeMax = 5000.0;
    page = 1;

    setGeometry(0, 0, size.width(), size.height());
//    setGeometry(0, 0, 500, 500);
//    this->size() = size;
//    qDebug() << "size: " << this->size();

//    resize(size);

    int nbPlot = 32; // Plots number for testing



    QCustomPlot *plot = new QCustomPlot;
    QCPRange defaultRange(-3.,3.);

    for (int i = 0; i <= nbPlot; i++)
    {
        QCPAxis *axis = plot->axisRect()->addAxis(QCPAxis::atLeft);
        axis->setRange(defaultRange.lower - (nbPlot - 1 - i) * defaultRange.size(),
                        defaultRange.upper + i * defaultRange.size());
        axis->setVisible(false);

        QCPGraph *graph = new QCPGraph(plot->xAxis, axis);
    }



    QVector<double> x(5000), y(5000); // plot1
    double a = 0.0;
    y[0] = a;
    x[0] = 0;
    for (int i=1; i<5000; ++i)
    {
        x[i] = i;
        a = a + ( (double) rand() / ((double) RAND_MAX / 2) ) - 1;
        if (a > 3) a = 3;
        if (a < -3) a = -3;
        y[i] = a;
    }

    for(int i = 0; i< plot->graphCount(); i++)
    {
        plot->graph(i)->setData(x, y);

        plot->graph(i)->setPen(QPen(Qt::black, 0.4));

//        double currentHueAngle = 137.50776 * i;
//        int h = int(fmod(currentHueAngle, 360.0));
//        int s = 127;
//        int v = 242;
//        plot->graph(i)->setPen(QPen(QColor::fromHsv(h, s, v)));
    }



    for(int i = 0; i< plot->graphCount(); i++)
    {
        QCPGraphDataContainer *data = plot->graph(i)->data().data();
        for (QCPGraphDataContainer::iterator it = data->begin(); it != data->end(); it++)
        {
            it->value += i * 2; // y-axis
        }
    }

    plot->xAxis->setRange(0, 500);
//    plot->yAxis->setRange(-1.5, 1.5);

    plot->xAxis->setVisible(false);
    plot->yAxis->setVisible(false);

    plot->axisRect()->setAutoMargins(QCP::msNone);
    plot->axisRect()->setMargins(QMargins(0, 10, 0, 0));
    plot->setStyleSheet(("background:hsva(255, 255, 255, 0%);"));
    plot->setBackground(QBrush(Qt::NoBrush));

    plot->setFixedHeight(700);


    QVBoxLayout *vLayout1 = new QVBoxLayout;
    vLayout1->addWidget(plot);
    vLayout1->setMargin(0);
    vLayout1->setSpacing(0);
    vLayout1->addStretch();





    // ##### VBox with Channels
    QVBoxLayout *vLayout2= new QVBoxLayout;
    for (int i = 0; i < nbPlot; i++)
    {
        QLabel *label = new QLabel;
        label->setText(" Ch. " + QString::number(i + 1));
        label->setFixedSize(30, 15);
        QFont f("Arial", 7);
        label->setFont(f);
        vLayout2->addWidget(label);
    }
    vLayout2->setMargin(10);
    vLayout2->setSpacing(0);
    vLayout2->addStretch();


    // HBox with 2 VBox
    QHBoxLayout *hLayout1 = new QHBoxLayout;
    hLayout1->addLayout(vLayout2);
    hLayout1->addLayout(vLayout1);
    hLayout1->setSpacing(0);
    hLayout1->setMargin(0);

    setLayout(hLayout1);
}

CentralMiddleLayer::~CentralMiddleLayer()
{

}


void CentralMiddleLayer::setActualRange(double lower)
{
    actualRange.lower = lower;
    actualRange.upper = lower + scale;
}



//void CentralMiddleLayer::connectPlot(PlotGeneration *plot)
//{
//    connect(plot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(XAxisChanged(QCPRange)));

//    connect(plot, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(mouseClick(QMouseEvent*)));
//}



//void CentralMiddleLayer::XAxisChanged(QCPRange range)
//{
//    QList<PlotGeneration*>::iterator plotIt;

//    if (range.lower < 0)
//    {
//        range.lower = 0;
//        range.upper = range.lower + 500.0;
//    }

//    if (range.upper > 5000)
//    {
//        range.upper = 5000;
//        range.lower = range.upper - 500.0;
//    }

//    range.upper = range.lower + 500.0;

//    for(plotIt = this->allPlot.begin(); plotIt != this->allPlot.end(); ++plotIt)
//    {
//        (*plotIt)->xAxis->setRange(range);
////        qDebug()<<range.lower;
//        (*plotIt)->replot(QCustomPlot::rpQueuedReplot);
//    }
//}



//void CentralMiddleLayer::mouseClick(QMouseEvent *event)
//{
//    if (event->button() == Qt::MiddleButton)
//    {
//        qDebug() << event->pos();
//    }
//}


void CentralMiddleLayer::pageChange(QMouseEvent *e)
{
    QList<PlotGeneration*>::iterator plotIt;

    if (e->button() == Qt::LeftButton) // Previous page
    {
        qDebug() << "To the Left!";

        page -= 1;

        double newLowerRange;
        newLowerRange = actualRange.lower - scale;

        if (newLowerRange < 0)
        {
            newLowerRange = 0;
            page += 1;
        }

        qDebug() << "page: " << page;

        setActualRange(newLowerRange);


        for(plotIt = this->allPlot.begin(); plotIt != this->allPlot.end(); ++plotIt)
        {
            (*plotIt)->xAxis->setRange(actualRange);
    //        qDebug()<<range.lower;
            (*plotIt)->replot(QCustomPlot::rpQueuedReplot);
        }
    }


    else // Right button, Next page
    {
        qDebug() << "To the Right!";

        page += 1;

        double newLowerRange;
        newLowerRange = actualRange.lower + scale;

        if (newLowerRange + scale > upperRangeMax)
        {
            newLowerRange = upperRangeMax - scale;
            page -= 1;
        }

        qDebug() << "page: " << page;

        setActualRange(newLowerRange);


        for(plotIt = this->allPlot.begin(); plotIt != this->allPlot.end(); ++plotIt)
        {
            (*plotIt)->xAxis->setRange(actualRange);
    //        qDebug()<<range.lower;
            (*plotIt)->replot(QCustomPlot::rpQueuedReplot);
        }
    }

    emit sendPage(page);
}




void CentralMiddleLayer::averageAtCursor(double posX)
{
    QList<PlotGeneration*>::iterator plotIt;


    double actualPage = (page - 1) * 500;
    double actualPosition = (int)(posX * 500) / 100;
    int dataPosition = actualPage + actualPosition;

    double data = 0.0;
    int i = 0;

    for(plotIt = this->allPlot.begin(); plotIt != this->allPlot.end(); ++plotIt)
    {
        data = data + ((*plotIt)->graph(0)->data()->begin() + dataPosition)->value;
        i++;
    }

    double average = data / i;
    qDebug() << "data: " << average;

    emit sendData(average);
}

