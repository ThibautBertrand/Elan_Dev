/* %%%%%%%%%%%%%%%%%%%%%%%%%
 *
 * This class is the top layer (overlay) of the Central Widget of the Main Main
 * Window. It's parent is called the wrapper (which is set to be the central
 * widget).
 * It contains the method to manage the cursors and mouses events.
 *
 * %%%%%%%%%%%%%%%%%%%%%%%%% */


#include "CentralTopLayer.h"

CentralTopLayer::CentralTopLayer(QSize size)
{
    setGeometry(0, 0, size.width(), size.height());
//    setGeometry(0, 0, 500, 500);
//    this->size() = size;
//    qDebug() << "size: " << this->size();


//    resize(size);

//    cursorFirst = new QLine();
////    this->lineMouse->start->setCoords(200, 5);
////    this->lineMouse->end->setCoords(200, -5);
//    this->cursorFirst->setVisible(false);
}



CentralTopLayer::~CentralTopLayer()
{

}



void CentralTopLayer::paintEvent(QPaintEvent *e)
{
    QWidget::paintEvent(e);
    QPainter p1(this);
    QPainter p2(this);

//    if (cursor == false)
//    {
//        p1.fillRect(cursorOnePositionX, 0, 1, this->height(), QBrush(QColor(0, 154, 207)));
//    }
//    else
//    {
//        p2.fillRect(cursorTwoPositionX, 0, 1, this->height(), QBrush(QColor(255, 102, 102)));
//    }


    p1.fillRect(cursorOnePositionX, 0, 1, this->height(), QBrush(QColor(0, 154, 207)));
    p2.fillRect(cursorTwoPositionX, 0, 1, this->height(), QBrush(QColor(255, 102, 102)));




//    ORIGINAL

//    QWidget::paintEvent(e);
//    QPainter p(this);
//    p.fillRect(cursorOnePositionX, 0, 1, this->height(), QBrush(QColor(0, 154, 207)));
}



void CentralTopLayer::mousePressEvent(QMouseEvent *e)
{
//    qDebug() << "e pos x (click): " << e->pos().x();

//    if(e->button() == Qt::MiddleButton)
//    {
//        if (cursor == false)
//        {
//            cursorOnePositionX = e->pos().x();
//    //        qDebug() << "positionX (click): " << cursorOnePositionX;
//            cursorOneRelativePosition = (double)(100.0 * (double)cursorOnePositionX) / (double)this->width();
//    //        qDebug() << "this width (click): " << this->width();
//    //        qDebug() << "relativePosition (click): " << cursorOneRelativePosition << "\n\n";

//            emit cursorOnePosition(cursorOneRelativePosition);

//            repaint();
//    //        update(); // Pareil semblerait-il...

//            cursor = true;
//        }

//        else
//        {
//            cursorTwoPositionX = e->pos().x();
//    //        qDebug() << "positionX (click): " << cursorOnePositionX;
//            cursorTwoRelativePosition = (double)(100.0 * (double)cursorTwoPositionX) / (double)this->width();
//    //        qDebug() << "this width (click): " << this->width();
//    //        qDebug() << "relativePosition (click): " << cursorOneRelativePosition << "\n\n";

//            emit cursorTwoPosition(cursorTwoRelativePosition);

//            repaint();
//    //        update(); // Pareil semblerait-il...

//            cursor = false;
//        }
//    }







    if(e->button() == Qt::MiddleButton)
    {
        if (cursorOneDisplayed == false) // If the first cursor isn't display = if there is no cursor on the screen
        {
            cursorOnePositionX = e->pos().x();
    //        qDebug() << "positionX (click): " << cursorOnePositionX;
            cursorOneRelativePosition = (double)(100.0 * (double)cursorOnePositionX) / (double)this->width();
    //        qDebug() << "this width (click): " << this->width();
    //        qDebug() << "relativePosition (click): " << cursorOneRelativePosition << "\n\n";

            emit cursorOnePosition(cursorOneRelativePosition);

            repaint();
            cursorOneDisplayed = true;
        }

        else // The first cursor is on the screen
        {
            double clickRelativePosition = (double)(100.0 * (double)e->pos().x()) / (double)this->width();

            if (clickRelativePosition > cursorOneRelativePosition) // if the second click is on the right side of the first cursor
            {
                cursorTwoPositionX = e->pos().x();
        //        qDebug() << "positionX (click): " << cursorOnePositionX;
                cursorTwoRelativePosition = (double)(100.0 * (double)cursorTwoPositionX) / (double)this->width();
        //        qDebug() << "this width (click): " << this->width();
        //        qDebug() << "relativePosition (click): " << cursorOneRelativePosition << "\n\n";

                emit cursorTwoPosition(cursorTwoRelativePosition);

                repaint();
            }

            else // if the second click is on the left side of the first cursor
            {
                cursorTwoPositionX = cursorOnePositionX;
                cursorTwoRelativePosition = cursorOneRelativePosition;

                cursorOnePositionX = e->pos().x();
        //        qDebug() << "positionX (click): " << cursorOnePositionX;
                cursorOneRelativePosition = (double)(100.0 * (double)cursorOnePositionX) / (double)this->width();
        //        qDebug() << "this width (click): " << this->width();
        //        qDebug() << "relativePosition (click): " << cursorOneRelativePosition << "\n\n";

                emit cursorOnePosition(cursorOneRelativePosition);
                emit cursorTwoPosition(cursorTwoRelativePosition);

                repaint();
            }

            emit bothCursorPosition(cursorOneRelativePosition, cursorTwoRelativePosition); // Send both limit of the interval
        }
    }



    else
    {
        emit pageChangeRequest(e);
    }








//    ORIGINAL

//    if(e->button() == Qt::MiddleButton)
//    {
//        cursorOnePositionX = e->pos().x();
////        qDebug() << "positionX (click): " << cursorOnePositionX;
//        cursorOneRelativePosition = (double)(100.0 * (double)cursorOnePositionX) / (double)this->width();
////        qDebug() << "this width (click): " << this->width();
////        qDebug() << "relativePosition (click): " << cursorOneRelativePosition << "\n\n";

//        emit cursorOnePosition(cursorOneRelativePosition);

//        repaint();
////        update(); // Pareil semblerait-il...
//    }

//    else
//    {
//        emit pageChangeRequest(e);
//    }
}

void CentralTopLayer::ResetCursor(bool)
{
    qDebug() << "one";

    cursorOnePositionX = 0.0;
    cursorTwoPositionX = 0.0;
    cursorOneRelativePosition = 0.0;
    cursorTwoRelativePosition = 0.0;

    cursorOneDisplayed = false;

    repaint();
}


void CentralTopLayer::resizeEvent(QResizeEvent *e)
{
//    qDebug() << "e size (resize): " << e->size();
//    emit sizeChanged(e->size());

    cursorOnePositionX = (int) ( (this->width() * cursorOneRelativePosition) / 100 );
    cursorTwoPositionX = (int) ( (this->width() * cursorTwoRelativePosition) / 100 );
//    qDebug() << "positionX (resize): " << cursorOnePositionX;
//    qDebug() << "this width (resize): " << this->width();
//    qDebug() << "relativePosition (resize): " << cursorOneRelativePosition << "\n\n";

    repaint();
}



//void CentralTopLayer::CursorChange(QMouseEvent *)
//{
//    if (point->button() == Qt::MiddleButton)
//    {
//        if (this->lineMouse->visible())
//        {
//            this->lineMouse->setVisible(false);
//        }
//        else
//        {
//            qDebug() << point->pos().x();
////            double x = point->pos().x();
////            double y = point->pos().y();
////            this->lineMouse->start->setCoords(x, 5.0);
////            this->lineMouse->end->setCoords(y, 5.0);


////            qDebug() << x + y;
//            this->lineMouse->setVisible(true);
//        }
//    }
//}
