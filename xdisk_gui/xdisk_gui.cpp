#include "xdisk_gui.h"
#include <QMessageBox>
#include <QFileDialog>
#include <string>
#include "xdisk_client.h"

using namespace std;

XDiskGUI::XDiskGUI(QWidget *parent) : QWidget(parent) {
    ui.setupUi(this);
    XDiskClient::Get()->Init();
    //注册信号支持的类型
    qRegisterMetaType<std::string>("std::string");
    //绑定目录获取的信号
    ///上传
    QObject::connect(XDiskClient::Get(), SIGNAL(SDir(std::string)), this, SLOT(UpdateDir(std::string)));
    ///刷新
    QObject::connect(XDiskClient::Get(), SIGNAL(SUploadComplete()), this, SLOT(Refresh()));
    ///下载
    QObject::connect(XDiskClient::Get(), SIGNAL(SDownloadComplete()), this, SLOT(DownloadComplete()));
    Refresh();
}

void XDiskGUI::DownloadComplete() {
    QMessageBox::information(this, "", "download complete");
}

void XDiskGUI::UpdateDir(std::string dirs) {
    //QMessageBox::information(this, "", dirs.c_str());
    /// "file1,1024;file2,4096;file3.zip,10240"
    QString str = dirs.c_str();
    str = str.trimmed();
    if (str.isEmpty())
        return;

    QStringList filestr = str.split(';');
    ui.filelistWidget->setRowCount(filestr.size());
    for (int i = 0; i < filestr.size(); i++) {
        QStringList fileinfo = filestr[i].split(',');
        if (fileinfo.size() != 2) continue;
        //插入到列表
        ui.filelistWidget->setItem(i, 0, new QTableWidgetItem(fileinfo[0]));
        ui.filelistWidget->setItem(i, 1, new QTableWidgetItem(tr("%1Byte").arg(fileinfo[1])));
    }
}

void XDiskGUI::UpdateServerInfo() {
    string ip = ui.ipEdit->text().toStdString();
    string root = ui.pathEdit->text().toStdString();
    int port = ui.portBox->value();

    ///服务器端口
    XDiskClient::Get()->set_port(port);
    ///服务器IP
    XDiskClient::Get()->set_server_ip(ip);
    ///服务器路径
    XDiskClient::Get()->set_server_root(root);
}

void XDiskGUI::Refresh() {
    UpdateServerInfo();
    XDiskClient::Get()->GetDir();
    //1 连接服务器
    //2 设置回调
}

void XDiskGUI::Download() {
    //用户选择下载文件和路径
    UpdateServerInfo();
    int row = ui.filelistWidget->currentRow();
    if (row < 0) {
        QMessageBox::information(this, "", QString::fromLocal8Bit("请选择下载文件"));
        return;
    }

    //获取选择的文件名
    auto item = ui.filelistWidget->item(row, 0);
    string filename = item->text().toStdString();

    //获取下载路径
    QString localpath = QFileDialog::getExistingDirectory(this, QString::fromLocal8Bit("请选择下载路径"));
    if (localpath.isEmpty())
        return;
    string filepath = ui.pathEdit->text().toStdString();
    filepath += "/";
    filepath += filename;
    XDiskClient::Get()->Download(filepath, localpath.toStdString());
}

void XDiskGUI::Upload() {
    //用户选择一个文件
    QString filename = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("请选择上传文件"));
    if (filename.isEmpty())
        return;
    UpdateServerInfo();
    XDiskClient::Get()->Upload(filename.toStdString());
}