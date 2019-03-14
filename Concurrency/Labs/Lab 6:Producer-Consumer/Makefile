#Joseph Kehoe 13/9/2017
# maintainer Cathal Brady 

#First simple Makefile
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS= -std=c++11 -pthread

CFILES= SafeBuffer.cpp Semaphore.cpp Event.cpp main.cpp
OBJFILES= SafeBuffer.o Semaphore.o Event.o main.o

%.o:%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ALL: $(OBJFILES)
	$(CC) -o lab6 $(OBJFILES) $(CFLAGS)

CLEAN:
	rm *.o
