#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QDialog>

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = 0);
    ~SettingWindow();

    QColor background;

private:
    Ui::SettingWindow *ui;

signals:
    void RequestColorChange(QColor);

public slots:
    void SendRequestColorChange();
    void SendRequestColorDefault();
};

#endif // SETTINGWINDOW_H
