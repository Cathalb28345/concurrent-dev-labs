/* Code: */
#pragma once
class Barrier{
  int numThreads;
 public:
  Barrier(int numThreads);
  virtual ~Barrier();
  void wait();  
};


/* Barrier.h ends here */
