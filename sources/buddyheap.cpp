#include "headers/buddyheap.h"

BuddyHeap::BuddyHeap():
    currentMemoryCapacity(DEFAULT_MEMORY_CAPACITY)
{

}

const unsigned BuddyHeap::DEFAULT_MEMORY_CAPACITY = 1024;
const unsigned BuddyHeap::MINIMUM_MEMORY_CAPACITY = 256;

void BuddyHeap::setCurrentMemoryCapacity(unsigned value){
    currentMemoryCapacity = value;
}

unsigned BuddyHeap::currentMemCapacity() const
{
    return currentMemoryCapacity;
}

void BuddyHeap::appendProcess(Process v)
{
    processes.append(v);
}
