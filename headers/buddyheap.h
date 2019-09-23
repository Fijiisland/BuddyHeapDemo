#pragma once

#include "headers/_utility.h"

struct Process{
    QString PID;
    unsigned allocated_mem;
    Process() = default;
    Process(QString PID, unsigned value):PID(PID), allocated_mem(value)
    {}
};

class BuddyHeap
{
public:
    BuddyHeap();
    void           setCurrentMemoryCapacity(unsigned value);
    unsigned       currentMemCapacity() const;
    void           appendProcess(Process v);
public:
    static const unsigned DEFAULT_MEMORY_CAPACITY;
    static const unsigned MINIMUM_MEMORY_CAPACITY;
private:
    unsigned currentMemoryCapacity;
    QList<Process> processes;
};
