#include "xdownload_task.h"
#include <iostream>

using namespace std;

bool XDownloadTask::ReadCB(const XMsg *msg)
{
    switch (msg->type)
    {
        case MSG_DOWNLOAD_ACCEPT:
            //不接收消息，开始接收文件
            set_is_recv_msg(false);
            if (msg->data)
                filesize_ = atoi(msg->data);
            else
            {
                Close();
                return false;
            }

            break;
        default:
            break;
    }
    return true;
}

//连接成功的消息回调
void XDownloadTask::ConnectedCB()
{
    if (filepath_.empty())
    {
        Close();
        return;
    }
    //3 发送下载文件请求
    string data = filepath_;

    //获取文件名
    int pos = filepath_.find_last_of('/');
    if (pos < 0)pos = 0;
    string filename = filepath_.substr(pos, filepath_.size() - pos);
    string path = localdir_ + filename;

    ofs_.open(path, ios::out | ios::binary);
    if (!ofs_.is_open())
    {
        cout << "open file " << path << " failed!" << endl;
        return;
    }
    cout << "open file " << path << " success!" << endl;

    XMsg msg;
    msg.type = MSG_DOWNLOAD_INFO;
    msg.data = (char*)data.c_str();
    msg.size = data.size() + 1;
    Write(&msg);

}
//当关闭消息接收时，数据将发送到此函数，由业务模块重载
void XDownloadTask::ReadCB(void *data, int size)
{
    if (!data || size <= 0 || !ofs_.is_open())return;
    ofs_.write((char*)data, size);
    recv_size_ += size;
    if (recv_size_ == filesize_)
    {
        //下载成功
        if(DownloadCB)
            DownloadCB();
        cout << "file write end" << endl;
        ofs_.close();
        XMsg resmsg;
        resmsg.type = MSG_DOWNLOAD_COMPLETE;
        resmsg.size = 3; // +1发送\0
        resmsg.data = (char*)"OK";
        Write(&resmsg);
    }
}