/* %%%%%%%%%%%%%%%%%%%%%%%%%
 *
 * This class is the bottom layer (underlay) of the Central Widget of the Main
 * Window. It's parent is called the wrapper (which is set to be the central
 * widget).
 * It contains the method to set and change the background color and to set the
 * graph paper.
 *
 * %%%%%%%%%%%%%%%%%%%%%%%%% */


#include "CentralBottomLayer.h"

CentralBottomLayer::CentralBottomLayer(QSize size)
{
    setGeometry(0, 0, size.width(), size.height());
//    setGeometry(0, 0, 500, 500);
//    this->size() = size;
//    qDebug() << "size: " << this->size();

//    resize(size);

//    backgroundColor.setRgb(240, 222, 173);
    backgroundColor.setRgb(224, 224, 224);

//    QPalette pal = palette();
    palette.setColor(QPalette::Background, backgroundColor);
    setAutoFillBackground(true);
    setPalette(palette);
}

CentralBottomLayer::~CentralBottomLayer()
{

}



void CentralBottomLayer::ChangeBackgroundColor(QColor background)
{
    qDebug() << background;

    palette.setColor(QPalette::Background, background);
    setAutoFillBackground(true);
    setPalette(palette);
}
