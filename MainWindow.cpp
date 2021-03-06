#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    setGeometry(0, 0, 1500, 500);

    connect(ui->actionQuit, SIGNAL(triggered(bool)),
            qApp, SLOT(quit()));
    connect(ui->actionPreferences, SIGNAL(triggered(bool)),
            this, SLOT(OpenSettingWindow()));
    connect(ui->actionScales, SIGNAL(triggered(bool)),
            this, SLOT(OpenScaleWindow()));


    //####################
//    ui->dockWidget->hide(); // Hide the dock Widget
    //####################


//    QSize sizeCentral = this->size();
//    sizeCentral.setWidth(this->size().width() - ui->dockWidget->size().width());
//    sizeCentral.setHeight(this->size().height());
//    wrapper = new Wrapper(sizeCentral);

//    QSize size;
//    size.setHeight(437);
//    size.setWidth(652);

//    qDebug() << "plot: " << ui->plotFrame->size();
//    qDebug() << "data: " << ui->dataFrame->size();
//    qDebug() << "central: " << ui->centralWidget->size();

//    wrapper = new Wrapper(this->size());
//    wrapper = new Wrapper(size);
    wrapper = new Wrapper(ui->plotFrame->size());
//    wrapper->setParent(this);


    connect(wrapper, SIGNAL(DataToDock(double)),
            this, SLOT(DockShowAverage(double)));
    connect(wrapper, SIGNAL(PageToDock(int)),
            this, SLOT(DockShowPage(int)));
    connect(this, SIGNAL(RequestColorChange(QColor)),
            this->wrapper, SIGNAL(RequestColorChange(QColor)));

    connect(ui->resetCursor, SIGNAL(clicked(bool)),
            this->wrapper, SLOT(ResetCursorRequest(bool)));


//    setCentralWidget(wrapper);
    ui->plotLayout->addWidget(wrapper);
}



MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::connectPlot(PlotGeneration *plot)
{
    connect(plot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(XAxisChanged(QCPRange)));

    connect(plot, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(mouseClick(QMouseEvent*)));
}



void MainWindow::XAxisChanged(QCPRange range)
{
    QList<PlotGeneration*>::iterator plotIt;

    if (range.lower < 0)
    {
        range.lower = 0;
        range.upper = range.lower + 500.0;
    }

    if (range.upper > 10000)
    {
        range.upper = 10000;
        range.lower = range.upper - 500.0;
    }

    range.upper = range.lower + 500.0;

    for(plotIt = this->allPlot.begin(); plotIt != this->allPlot.end(); ++plotIt)
    {
        (*plotIt)->xAxis->setRange(range);
//        qDebug()<<range.lower;
        (*plotIt)->replot(QCustomPlot::rpQueuedReplot);
    }
}



void MainWindow::mouseClick(QMouseEvent *event)
{
    if (event->button() == Qt::MiddleButton)
    {
        qDebug() << event->pos();
    }
}



void MainWindow::OpenSettingWindow()
{
    settingWindow = new SettingWindow(this);

    connect(settingWindow, SIGNAL(RequestColorChange(QColor)),
            this, SIGNAL(RequestColorChange(QColor)));

    settingWindow->show();
}



void MainWindow::OpenScaleWindow()
{
    scaleWindow = new ScaleWindow(this);

    scaleWindow->show();
}



void MainWindow::resizeEvent(QResizeEvent *e)
{

}



void MainWindow::DockShowAverage(double data)
{
//    qDebug() << "Dock average: " << data;
    QString dataString = QString::number(data);
    ui->dataLabel->setText(dataString);
}



void MainWindow::DockShowPage(int page)
{
    qDebug() << "Dock page: " << page;
    QString pageString = QString::number(page);
    ui->pageLabel_2->setText(pageString);
}
