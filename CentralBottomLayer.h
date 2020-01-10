#ifndef CENTRALBOTTOMLAYER_H
#define CENTRALBOTTOMLAYER_H

#include <QWidget>
#include <QPalette>

#include "Wrapper.h"

class CentralBottomLayer : public QWidget
{

    Q_OBJECT

public:
    CentralBottomLayer(QSize size);
    ~CentralBottomLayer();

    QColor backgroundColor;
    QPalette palette;

public slots:

    void ChangeBackgroundColor(QColor background);
};

#endif // CENTRALBOTTOMLAYER_H
