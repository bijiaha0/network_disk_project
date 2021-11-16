#pragma once
#include "xcom_task.h"
#include <fstream>
typedef void(*DownloadCBFunc)();

class XDownloadTask :public XComTask
{
public:
    //当关闭消息接收时，数据将发送到此函数，由业务模块重载
    virtual void ReadCB(void *data, int size);

    //接收到消息的回调
    virtual bool ReadCB(const XMsg *msg);

    //连接成功的消息回调
    virtual void ConnectedCB();

    DownloadCBFunc DownloadCB = 0;

    void set_filepath(std::string path) { this->filepath_ = path; }
    void set_localdir(std::string localdir) { this->localdir_ = localdir; }

private:
    //文件大小
    int filesize_ = 0;

    //需要下载的文件相对路径
    std::string filepath_;

    //下载到本地的目录
    std::string localdir_;

    //客户已经下载的大小
    int recv_size_ = 0;

    //写入接收的文件
    std::ofstream ofs_;
};
