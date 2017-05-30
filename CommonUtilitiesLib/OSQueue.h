/*
 *
 * @APPLE_LICENSE_HEADER_START@
 *
 * Copyright (c) 1999-2008 Apple Inc.  All Rights Reserved.
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_LICENSE_HEADER_END@
 *
 */
/*
    File:       OSQueue.h

    Contains:   implements OSQueue class


*/

#ifndef _OSQUEUE_H_
#define _OSQUEUE_H_

#include "MyAssert.h"
#include "OSHeaders.h"
#include "OSMutex.h"
#include "OSCond.h"
#include "OSThread.h"

#define OSQUEUETESTING 0

class OSQueue;

class OSQueueElem {
public:
    OSQueueElem(void *enclosingObject = nullptr) : fNext(nullptr), fPrev(nullptr), fQueue(nullptr),
                                                   fEnclosingObject(enclosingObject) {}

    virtual ~OSQueueElem() {Assert(fQueue == nullptr); }

    bool IsMember(const OSQueue &queue) { return (&queue == fQueue); }

    bool IsMemberOfAnyQueue() { return fQueue != nullptr; }

    void *GetEnclosingObject() { return fEnclosingObject; }

    void SetEnclosingObject(void *obj) { fEnclosingObject = obj; }

    OSQueueElem *Next() { return fNext; }

    OSQueueElem *Prev() { return fPrev; }

    OSQueue *InQueue() { return fQueue; }

    inline void Remove();

private:

    OSQueueElem *fNext;
    OSQueueElem *fPrev;
    OSQueue *fQueue;
    void *fEnclosingObject;

    friend class OSQueue;
};

class OSQueue {
public:
    OSQueue();

    ~OSQueue() {}

    void EnQueue(OSQueueElem *object);

    OSQueueElem *DeQueue();

    OSQueueElem *GetHead()
    {
        if (fLength > 0) return fSentinel.fPrev;
        return nullptr;
    }

    OSQueueElem *GetTail()
    {
        if (fLength > 0) return fSentinel.fNext;
        return nullptr;
    }

    UInt32 GetLength() { return fLength; }

    void Remove(OSQueueElem *object);

#if OSQUEUETESTING
    static bool       Test();
#endif

protected:
    OSMutex fMutex;

    OSQueueElem fSentinel;
    UInt32 fLength;
};

class OSQueueIter {
public:
    OSQueueIter(OSQueue *inQueue) : fQueueP(inQueue), fCurrentElemP(inQueue->GetHead()) {}

    OSQueueIter(OSQueue *inQueue, OSQueueElem *startElemP) : fQueueP(inQueue)
    {
        if (startElemP) {
            Assert(startElemP->IsMember(*inQueue));
            fCurrentElemP = startElemP;

        } else
            fCurrentElemP = nullptr;
    }

    ~OSQueueIter() {}

    void Reset() { fCurrentElemP = fQueueP->GetHead(); }

    OSQueueElem *GetCurrent() { return fCurrentElemP; }

    void Next();

    bool IsDone() { return fCurrentElemP == nullptr; }

private:

    OSQueue *fQueueP;
    OSQueueElem *fCurrentElemP;
};

// 该类用作 TaskThread 的私有成员类,实际上是利用线程的条件变量实现了一个可等待唤醒的队列操
// 作。下面是一些成员函数的分析:
class OSQueue_Blocking {
public:
    OSQueue_Blocking() {}

    ~OSQueue_Blocking() {}

    OSQueueElem *DeQueueBlocking(OSThread *inCurThread, SInt32 inTimeoutInMilSecs);

    OSQueueElem *DeQueue();//will not block
    void EnQueue(OSQueueElem *obj);

    OSCond *GetCond() { return &fCond; }

    OSQueue *GetQueue() { return &fQueue; }

private:

    OSCond fCond;
    OSMutex fMutex;
    OSQueue fQueue;
};


void OSQueueElem::Remove()
{
    if (fQueue != nullptr)
        fQueue->Remove(this);
}

#endif //_OSQUEUE_H_
