#include "Wrapper.h"

Wrapper::Wrapper(QSize size)
{
    bottomLayer = new CentralBottomLayer(size);
    bottomLayer->setParent(this);

    middleLayer = new CentralMiddleLayer(size);
    middleLayer->setParent(this);

    topLayer = new CentralTopLayer(size);
    topLayer->setParent(this);

    connect(this->topLayer, SIGNAL(cursorOnePosition(double)),
            this, SLOT(truc(double)));
    connect(this->topLayer, SIGNAL(cursorTwoPosition(double)),
            this, SLOT(truc(double)));

    connect(this->middleLayer, SIGNAL(sendData(double)),
            this, SLOT(SendDataToDock(double)));
    connect(this->middleLayer, SIGNAL(sendPage(int)),
            this, SLOT(SendPageToDock(int)));

    connect(this->topLayer, SIGNAL(pageChangeRequest(QMouseEvent*)),
            this->middleLayer, SLOT(pageChange(QMouseEvent*)));

    connect(this->topLayer, SIGNAL(cursorOnePosition(double)),
            this->middleLayer, SLOT(averageAtCursor(double)));
    connect(this->topLayer, SIGNAL(cursorTwoPosition(double)),
            this->middleLayer, SLOT(averageAtCursor(double)));

    connect(this, SIGNAL(RequestColorChange(QColor)),
            this->bottomLayer, SLOT(ChangeBackgroundColor(QColor)));
    connect(this, SIGNAL(CursorReset(bool)),
            this->topLayer, SLOT(ResetCursor(bool)));
}

void Wrapper::truc(double posX)
{
    qDebug() << "Position: " << posX;
}

void Wrapper::SendDataToDock(double data)
{
    emit DataToDock(data);
}

void Wrapper::SendPageToDock(int page)
{
    emit PageToDock(page);
}

void Wrapper::ResetCursorRequest(bool reset)
{
    emit CursorReset(reset);
}




void Wrapper::resizeEvent(QResizeEvent *e)
{
    QWidget::resizeEvent(e);

    int oldWidth = e->oldSize().width();

    if (oldWidth >= 0)
    {
        bottomLayer->resize(bottomLayer->width() + e->size().width() - oldWidth,
                        bottomLayer->height() + e->size().height() - e->oldSize().height());

        middleLayer->resize(middleLayer->width() + e->size().width() - oldWidth,
                        middleLayer->height() + e->size().height() - e->oldSize().height());

        topLayer->resize(topLayer->width() + e->size().width() - oldWidth,
                        topLayer->height() + e->size().height() - e->oldSize().height());
    }
}


void Wrapper::connectPlot(/*PlotGeneration *plot*/)
{
//    connect(plot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(XAxisChanged(QCPRange)));

//    connect(m_topLayer, SIGNAL(mouseRelease(QMouseEvent*)), qApp, SLOT(quit()));
//    connect(plot, SIGNAL(mouseRelease(QMouseEvent*)), plot, SLOT(ChangeLine(QMouseEvent*)));
}
