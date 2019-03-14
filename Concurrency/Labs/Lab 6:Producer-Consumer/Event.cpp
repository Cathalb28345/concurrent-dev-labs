//
// Created by jk on 01/03/19.
//


#include "Event.h"
#include <stdlib.h>
#include <iostream>

Event::Event(){
    eric = 'a'+rand()%26;
//    std::cout << "producing " << eric << std::endl;
    std::cout <<    eric ;
 };

bool Event::consume(){
    char betterEric = eric-32;
    std::cout << betterEric;
};
