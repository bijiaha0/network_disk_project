#include "xdisk_gui.h"
#include <QtWidgets/QApplication>
#include <signal.h>

int main(int argc, char *argv[]) {
    //使用断开连接socket，会发出此信号，造成程序退出
    if (signal(SIGPIPE, SIG_IGN) == SIG_ERR)
        return 1;

    QApplication a(argc, argv);
    XDiskGUI w;
    w.show();
    //处理信号槽
    return a.exec();
}