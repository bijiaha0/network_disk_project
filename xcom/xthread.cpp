#include "xthread.h"
#include <thread>
#include <iostream>
#include <event2/event.h>
#include "xtask.h"
#include <unistd.h>

using namespace std;

/// 回调函数
static void NotifyCB(int fd, short which, void *arg) {
    XThread *t = (XThread *) arg;
    t->Notify(fd, which);
}

/// 通知
void XThread::Notify(int fd, short which) {
    //水平触发 只要没有接受完成，会再次进来
    char buf[2] = {0};

    int re = read(fd, buf, 1);
    if (re <= 0)
        return;
    cout << id << " thread " << buf << endl;

    XTask *task = NULL;
    //获取任务，并初始化任务
    tasks_mutex_.lock();
    if (tasks_.empty()) {
        tasks_mutex_.unlock();
        return;
    }
    task = tasks_.front(); //先进先出
    tasks_.pop_front();
    tasks_mutex_.unlock();
    //任务初始化
    task->Init();
}

///
void XThread::AddTask(XTask *t) {
    if (!t)return;
    t->set_base(this->base_);
    tasks_mutex_.lock();
    tasks_.push_back(t);
    tasks_mutex_.unlock();
}

///线程激活
void XThread::Activate() {
    int re = write(this->notify_send_fd_, "c", 1);
    if (re <= 0) {
        cerr << "XThread::Activate() failed!" << endl;
    }
}

///启动线程
void XThread::Start() {
    ///初始化event_base和管道监听事件用于激活
    Setup();
    //启动线程
    thread th(&XThread::Main, this);
    //断开与主线程联系
    th.detach();
}

///安装线程，初始化event_base和管道监听事件用于激活
bool XThread::Setup() {
    // 创建的管道
    int fds[2];

    // pipe函数会建立管道，并将文件描述词由参数fds数组返回。
    // fds[0]为管道里的读取端
    // fds[1]为管道里的写入端。
    if (pipe(fds)) {
        cerr << "pipe failed!" << endl;
        return false;
    }

    notify_send_fd_ = fds[1];

    /// 创建 libevent 上下文（无锁）
    event_config *ev_conf = event_config_new();
    event_config_set_flag(ev_conf, EVENT_BASE_FLAG_NOLOCK);
    this->base_ = event_base_new_with_config(ev_conf);
    event_config_free(ev_conf);
    if (!base_) {
        cerr << "event_base_new_with_config failed in thread!" << endl;
        return false;
    }

    event *ev = event_new(base_, fds[0], EV_READ | EV_PERSIST, NotifyCB, this);
    event_add(ev, 0);
    return true;
}

/// 线程入口函数
void XThread::Main() {
    cout << id << " XThread::Main() begin" << endl;
    if (!base_) {
        cerr << "XThread::Main faield! base_ is null " << endl;
        return;
    }
    event_base_dispatch(base_);
    event_base_free(base_);

    cout << id << " XThread::Main() end" << endl;
}

XThread::XThread() {
}

XThread::~XThread() {
}