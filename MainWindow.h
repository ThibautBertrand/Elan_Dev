#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QtWidgets>
#include <QMainWindow>
#include <QListWidget>
#include <vector>

#include "qcustomplot.h"
#include "PlotGeneration.h"
#include "SettingWindow.h"
#include "ScaleWindow.h"
#include "Wrapper.h"
//#include "CentralBottomLayer.h"
//#include "CentralMiddleLayer.h"
//#include "CentralTopLayer.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void connectPlot(PlotGeneration *plot);

    void resizeEvent(QResizeEvent *e);

    QWidget *wrapper; // Background

signals:
    void RequestColorChange(QColor);


public slots:
    void XAxisChanged(QCPRange range);
    void mouseClick(QMouseEvent*);

    void OpenSettingWindow();
    void OpenScaleWindow();

    void DockShowAverage(double data);
//    void DockShowAverageInterval(double data);
    void DockShowPage(int page);

private:
    QList<PlotGeneration*> allPlot;
    Ui::MainWindow *ui;
    SettingWindow *settingWindow; // Smart pointers ?
    ScaleWindow *scaleWindow;
};

#endif // MAINWINDOW_H
