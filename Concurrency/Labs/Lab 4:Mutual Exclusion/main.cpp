// #Cathal Brady 
// #Student Number : C00202493 
// # Date of creation  : 14 /  02 / 19 

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>

/*! \Mutual Exclusion Lab
  \mainpage Cathal Brady Student Number : C00202493 
  
  Using a semaphore to lock the loop to stop other threads from being able to access it while another thread is currently running or in process. Once the thread has finished, signals to the next thread to continue. 
   Uses C++11 features such as mutex and condition variables to implement Semaphores in thread functions 
*/
static const int num_threads = 100;
int sharedVariable=0;

void updateTask(std::shared_ptr<Semaphore> firstSemaphore, int numUpdates){
// set wait at start of the method
  firstSemaphore->Wait();
  for(int i=0;i<numUpdates;i++){      
      sharedVariable++;
  }
  // when firstSemaphore is finsihed signal to show completion 
  firstSemaphore->Signal();

}

int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Semaphore> aSemaphore( new Semaphore(1));
  /**< Launch the threads  
   * till upper limit is reachd 1000
  */
  for(std::thread& t: vt){
    t=std::thread(updateTask,aSemaphore,1000);
  }
  std::cout << "Launched from the main\n";
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}