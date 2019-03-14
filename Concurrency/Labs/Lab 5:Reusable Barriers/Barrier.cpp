/*! \fn Barrier.cpp
    \brief An Implementation of Barrier.h to introduce a barrier for the main method
    #Cathal Brady 
      #Student Number : C00202493 
*/

#include "Semaphore.h"
#include "Barrier.h"
#include <iostream>


/*! Constructor Method*/
Barrier::Barrier(int numOfThreads) : numThreads(numOfThreads),
				semaphore1(std::shared_ptr<Semaphore>(new Semaphore(0))),
				semaphore2(std::shared_ptr<Semaphore>(new Semaphore(1))),
				mutexlock(std::shared_ptr<Semaphore>(new Semaphore(1))){
}
/*! Wait Method*/
void Barrier::Wait()
{
      mutexLock->Wait();
      count++;

      if(count == numThreads) {
	semaphore2->Wait();
	semaphore1->Signal();
      }
      mutexLock->Signal();

	semaphore1->Wait();
	semaphore1->Signal();

      mutexLock->Wait();
      count--;

      if(count == 0) {
	semaphore1->Wait();
	semaphore2->Signal();
      }
      mutexLock->Signal();

	semaphore2->Wait();
	semaphore2->Signal();
}
/*! Destructor method  destroy barrior*/
Barrier::~Barrier() {
}