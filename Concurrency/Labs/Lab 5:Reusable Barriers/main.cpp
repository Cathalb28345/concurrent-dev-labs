// #Cathal Brady 
// #Student Number : C00202493 
// # Date of creation  : 14 /  02 / 19 
 
#include "Barrier.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 100;
int sharedVariable=0;


/*! \fn barrierTask
    \brief An example of using a reusable barrier
*/
/*! displays a message that is split in to 2 sections to show how a rendezvous works*/
void barrierTask(std::shared_ptr<Barrier> newBarrier, int numLoops){

  for(int i=0;i<numLoops;++i){
    //Do first instruction 
    std::cout << "A"<< i;
    //Set barrer then wait till comletion 
    newBarrier.wait();
    //Do next step and out Z when the first step is complete
    std::cout<< "Z" << i;
  }
  

}


int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Barrier> aBarrier( new Barrier(num_threads));
  /**< Launch the threads  */
  int i=0;
  for(std::thread& t: vt){
    t=std::thread(updateTask,aBarrier,10);
  }
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}
