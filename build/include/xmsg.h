#ifndef XMSG_H
#define XMSG_H

#define XCOM_API

enum MsgType
{
    MSG_NONE = 0,
    ///请求目录
    MSG_GETDIR,
    ///返回目录列表
    MSG_DIRLIST,
    ///请求上传文件
    MSG_UPLOAD_INFO,
    ///服务端准备好接收文件
    MSG_UPLOAD_ACCEPT,
    ///服务端接收文件结束
    MSG_UPLOAD_COMPLETE,
    ///请求下载文件
    MSG_DOWNLOAD_INFO,
    ///开始发送数据给客户端
    MSG_DOWNLOAD_ACCEPT,
    ///客户端下载成功
    MSG_DOWNLOAD_COMPLETE,
    ///用来验证类型正确
    MSG_MAX_TYPE,
};

//消息最大字节数
#define MSG_MAX_SIZE 1000000

//消息头
struct XCOM_API XMsgHead
{
    MsgType type;
    int size = 0;
};

//约定每个消息必须包含内容，没有内容使用OK
struct XCOM_API XMsg :public XMsgHead
{
    //存储消息内容
    char *data = 0;
    //已经接收的消息字节数
    int recved = 0;
};

#endif