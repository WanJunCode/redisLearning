/* 一个简单的事件驱动库
 * A simple event-driven programming library. Originally I wrote this code
 * for the Jim's event-loop (Jim is a Tcl interpreter) but later translated
 * it in form of a library for easy reuse.
 *
 * Copyright (c) 2006-2012, Salvatore Sanfilippo <antirez at gmail dot com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of Redis nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __AE_H__
#define __AE_H__

#include <time.h>

#define AE_OK 0
#define AE_ERR -1

#define AE_NONE 0       /* No events registered. */
#define AE_READABLE 1   /* Fire when descriptor is readable. 文件描述符可读 */
#define AE_WRITABLE 2   /* Fire when descriptor is writable. 文件描述符可写 */

#define AE_BARRIER 4    // 可读可写时，优先处理可写
/* 在可写的时候不会触发可读事件，用于将某些thing持久化到磁盘中
With WRITABLE, never fire the event if the READABLE event already fired in the same event
loop iteration. Useful when you want to persist things to disk before sending replies, and want
to do that in a group fashion. */

#define AE_FILE_EVENTS 1    // 文件事件
#define AE_TIME_EVENTS 2    // 定时器事件
#define AE_ALL_EVENTS (AE_FILE_EVENTS|AE_TIME_EVENTS)       // 文件事件和定时器事件
#define AE_DONT_WAIT 4          // 不等待
#define AE_CALL_AFTER_SLEEP 8

#define AE_NOMORE -1
#define AE_DELETED_EVENT_ID -1  // 被删除的事件ID

/* Macros */
#define AE_NOTUSED(V) ((void) V)

// 声明
struct aeEventLoop;

/* Types and data structures */
// 文件事件处理函数
typedef void aeFileProc(struct aeEventLoop *eventLoop, int fd, void *clientData, int mask);
// 定时器事件处理函数
typedef int aeTimeProc(struct aeEventLoop *eventLoop, long long id, void *clientData);
// 终止处理函数
typedef void aeEventFinalizerProc(struct aeEventLoop *eventLoop, void *clientData);
// 在sleep之前处理函数
typedef void aeBeforeSleepProc(struct aeEventLoop *eventLoop);

/* 文件描述符事件结构 File event structure */
typedef struct aeFileEvent {
    int mask; /* one of AE_(READABLE|WRITABLE|BARRIER) */
    aeFileProc *rfileProc;      // 读取文件描述符处理函数
    aeFileProc *wfileProc;      // 写入文件描述符处理函数
    void *clientData;
} aeFileEvent;

/* 定时器事件 Time event structure */
typedef struct aeTimeEvent {
    long long id; /* time event identifier. */
    long when_sec; /* seconds */
    long when_ms; /* milliseconds */
    aeTimeProc *timeProc;
    aeEventFinalizerProc *finalizerProc;
    void *clientData;
    struct aeTimeEvent *prev;       // 指向前一个时间器
    struct aeTimeEvent *next;       // 指向下一个时间器
} aeTimeEvent;

/* 触发的事件 A fired event */
typedef struct aeFiredEvent {
    int fd;
    int mask;
} aeFiredEvent;

/* State of an event based program */
typedef struct aeEventLoop {
    int maxfd;   /* highest file descriptor currently registered 当前注册的文件描述符最大值 */
    int setsize; /* max number of file descriptors tracked 追踪的文件描述符最大数量 */
    long long timeEventNextId;      // 下一个时间器的ID
    time_t lastTime;     /* Used to detect system clock skew 用于检测系统时钟偏斜，记录最近一次的时间器处理时间 */
    aeFileEvent *events; /* Registered events 注册的事件数组，索引就是文件描述符 */
    aeFiredEvent *fired; /* Fired events 存储触发的事件fd以及对应的事件掩码mask */
    aeTimeEvent *timeEventHead; // 时间器单链表，新创建的时间器会作为表头。目前时间器是未排序的
    int stop;
    void *apidata; /* This is used for polling API specific data 指向底层特定实现的结构体指针 */
    aeBeforeSleepProc *beforesleep;     // 在 sleep 之前执行的函数
    aeBeforeSleepProc *aftersleep;      // 在 sleep 之后执行的函数
    int flags;
} aeEventLoop;

/* Prototypes 函数原型 */
aeEventLoop *aeCreateEventLoop(int setsize);
void aeDeleteEventLoop(aeEventLoop *eventLoop);
void aeStop(aeEventLoop *eventLoop);
int aeCreateFileEvent(aeEventLoop *eventLoop, int fd, int mask,
        aeFileProc *proc, void *clientData);
void aeDeleteFileEvent(aeEventLoop *eventLoop, int fd, int mask);
int aeGetFileEvents(aeEventLoop *eventLoop, int fd);
long long aeCreateTimeEvent(aeEventLoop *eventLoop, long long milliseconds,
        aeTimeProc *proc, void *clientData,
        aeEventFinalizerProc *finalizerProc);
int aeDeleteTimeEvent(aeEventLoop *eventLoop, long long id);
int aeProcessEvents(aeEventLoop *eventLoop, int flags);
int aeWait(int fd, int mask, long long milliseconds);
void aeMain(aeEventLoop *eventLoop);
char *aeGetApiName(void);
void aeSetBeforeSleepProc(aeEventLoop *eventLoop, aeBeforeSleepProc *beforesleep);
void aeSetAfterSleepProc(aeEventLoop *eventLoop, aeBeforeSleepProc *aftersleep);
int aeGetSetSize(aeEventLoop *eventLoop);
int aeResizeSetSize(aeEventLoop *eventLoop, int setsize);
void aeSetDontWait(aeEventLoop *eventLoop, int noWait);

#endif
