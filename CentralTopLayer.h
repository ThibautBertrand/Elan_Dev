#ifndef CENTRALTOPLAYER_H
#define CENTRALTOPLAYER_H

#include <QWidget>
#include <QDebug>

#include "Wrapper.h"
//#include "PlotGeneration.h"
#include "qpainter.h"


class CentralTopLayer : public QWidget
{
    Q_OBJECT

public:

    CentralTopLayer(QSize size);
    ~CentralTopLayer();

    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void resizeEvent(QResizeEvent *e);

    int cursorOnePositionX; // Position of cursor in pixel units
    double cursorOneRelativePosition; // Position of cursor in percentage units
    QLine *cursorOne;
    bool cursorOneDisplayed = false; // if true: cursorOne has been placed

    int cursorTwoPositionX;
    double cursorTwoRelativePosition;
    QLine *cursorTwo;

//    bool cursor = false;


signals:

    void cursorOnePosition(double);
    void cursorTwoPosition(double);

    void bothCursorPosition(double one, double two);

    void pageChangeRequest(QMouseEvent*);

public slots:

    void ResetCursor(bool);

//    void CursorChange(QMouseEvent*);
//    void cursorResize();
};

#endif // CENTRALTOPLAYER_H
