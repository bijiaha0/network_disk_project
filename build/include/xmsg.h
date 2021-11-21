#ifndef XMSG_H
#define XMSG_H

#define XCOM_API

enum MsgType
{
    MSG_NONE = 0,
    ///����Ŀ¼
    MSG_GETDIR,
    ///����Ŀ¼�б�
    MSG_DIRLIST,
    ///�����ϴ��ļ�
    MSG_UPLOAD_INFO,
    ///�����׼���ý����ļ�
    MSG_UPLOAD_ACCEPT,
    ///����˽����ļ�����
    MSG_UPLOAD_COMPLETE,
    ///���������ļ�
    MSG_DOWNLOAD_INFO,
    ///��ʼ�������ݸ��ͻ���
    MSG_DOWNLOAD_ACCEPT,
    ///�ͻ������سɹ�
    MSG_DOWNLOAD_COMPLETE,
    ///������֤������ȷ
    MSG_MAX_TYPE,
};

//��Ϣ����ֽ���
#define MSG_MAX_SIZE 1000000

//��Ϣͷ
struct XCOM_API XMsgHead
{
    MsgType type;
    int size = 0;
};

//Լ��ÿ����Ϣ����������ݣ�û������ʹ��OK
struct XCOM_API XMsg :public XMsgHead
{
    //�洢��Ϣ����
    char *data = 0;
    //�Ѿ����յ���Ϣ�ֽ���
    int recved = 0;
};

#endif