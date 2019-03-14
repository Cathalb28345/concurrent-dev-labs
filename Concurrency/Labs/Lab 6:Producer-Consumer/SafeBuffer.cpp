#include "SafeBuffer.h"


SafeBuffer::SafeBuffer() {
    // should use make shared instead here
    theMutex = std::shared_ptr<Semaphore>(new Semaphore(1));
//    theSemaphore = std::shared_ptr<Semaphore>(new Semaphore(0));
    theSemaphore = std::make_shared<Semaphore>(0);

//    theMutex= new Semaphore(1);
};
int SafeBuffer::push(Event newEric) {
    theMutex->Wait();
    theData.push_back(newEric);
    int size=theData.size();
    theMutex->Signal();
    theSemaphore->Signal();
    return size;
} //push

Event SafeBuffer::pop() {
    theSemaphore->Wait();
    theMutex->Wait();
    Event e=theData.back();
    theData.pop_back();
    theMutex->Signal();
    return e;
} //pop