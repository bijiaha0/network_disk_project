#include "xdisk_client.h"
#include "xdir_task.h"
#include "xthread_pool.h"
#include "xupload_task.h"
#include "xdownload_task.h"
#include <iostream>

using namespace std;

bool XDiskClient::Init() {
    XThreadPool::Get()->Init(10);
    return true;
}

static void DirCB(string dirs) {
    cout << dirs << endl;
    XDiskClient::Get()->SDir(dirs);
}

static void UploadCB() {
    cout << "UploadCB" << endl;
    XDiskClient::Get()->SUploadComplete();
}

////////////////////////////////////////////////////////////
///@brief 上传文件请求
///@para filepath 本地文件路径
void XDiskClient::Upload(std::string filepath) {
    auto task = new XUploadTask();
    task->set_server_ip(server_ip_);
    task->set_port(server_port_);
    task->set_filepath(filepath);
    task->UploadCB = UploadCB;
    XThreadPool::Get()->Dispatch(task);
}

static void DownloadCB() {
    cout << "SDownloadComplete" << endl;
    XDiskClient::Get()->SDownloadComplete();
}

////////////////////////////////////////////////////////////
///@brief 上传文件请求
///@para serverpath 远端文件的相对路径
///@para localdir 本地存储的目录
void XDiskClient::Download(std::string serverpath, std::string localdir) {
    auto task = new XDownloadTask();
    task->set_server_ip(server_ip_);
    task->set_port(server_port_);
    task->set_filepath(serverpath);
    task->set_localdir(localdir);
    task->DownloadCB = DownloadCB;
    XThreadPool::Get()->Dispatch(task);
}

////////////////////////////////////////////////////////////
///@brief 获取目录下的文件列表，只是请求消息到服务端
void XDiskClient::GetDir() {
    cout << "GetDir " << server_ip_ << ":" << server_port_ << "/" << server_root_ << endl;
    auto task = new XDirTask();
    task->set_server_ip(server_ip_);
    task->set_port(server_port_);
    task->set_server_root(server_root_);
    task->DirCB = DirCB;
    //现在不能操作，task未初始化。task没有event_base
    XThreadPool::Get()->Dispatch(task);
}