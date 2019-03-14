#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <chrono>


void taskOne(std::shared_ptr<Semaphore> Semaphore1,std::shared_ptr<Semaphore>  Semaphore2, int delay){
  std::this_thread::sleep_for(std::chrono::seconds(delay));
  std::cout <<"Task One has finished! "<< std::endl;
  //Rendezvous begin with signal for semaphore 1 and semaphore 2 will wait till it recieves a signal to begin.
  Semaphore1->Signal();
  Semaphore2->Wait();
  std::cout << "Task One has begining !"<<std::endl;
}
/*! \brief displays a message that is split in to 2 sections to show how a rendezvous works.
    The second task arrives and sends a wait to the thread stopping if from continuing. Then it receives a signal from the other thread and is released.
*/
void taskTwo(std::shared_ptr<Semaphore> Semaphore1, std::shared_ptr<Semaphore> Semaphore2, int delay){
  std::this_thread::sleep_for(std::chrono::seconds(delay));
  std::cout <<"Task Two started "<<std::endl;
  //Rendezvous begin with signal for semaphore 2 and semaphore 1 will wait till it recieves a signal to begin.
  Semaphore2->Signal();
  Semaphore1->Wait();
  std::cout << "Task Two has left and is running"<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> Semaphore1( new Semaphore);
  std::shared_ptr<Semaphore> Semaphore2( new Semaphore);
  int taskOneDelay=5;
  int taskTwoDelay=1;
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,Semaphore1,Semaphore2,taskTwoDelay);
  threadTwo=std::thread(taskOne,Semaphore1,Semaphore2,taskOneDelay);
  std::cout << "Launched from the main method begin now \n";
  threadOne.join();
  threadTwo.join();
  return 0;
}