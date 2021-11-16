//
// Created by bijh on 2021/11/16.
//

#ifndef QT_PROJECT_XDISK_GUI_H
#define QT_PROJECT_XDISK_GUI_H

#include <QWidget>
#include "ui_xdisk_gui.h"

class XDiskGUI : public QWidget
{
Q_OBJECT

public:
    XDiskGUI(QWidget *parent = Q_NULLPTR);

    void UpdateServerInfo();
public slots:
    void Refresh();
    void UpdateDir(std::string dirs);
    void Upload();
    void Download();
    void DownloadComplete();
private:
    Ui::XDiskGUIClass ui;
};

#endif //QT_PROJECT_XDISK_GUI_H
