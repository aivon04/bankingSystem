//
//  Maintainer.hpp
//  bankingSystem
//
//  Created by Ichigo Ichie on 2016-10-08.
//  Copyright © 2016 Yiting Wang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <iostream>
#include "Customer.hpp"
#include "Manager.hpp"
using namespace std;

#ifndef Maintainer_hpp
#define Maintainer_hpp

class Maintainer{
private:
    string id="2000"; //set the maintainer id is 2000
    bool trace=false;
    fstream maintfile;
    
public:
    Maintainer();
    ~Maintainer();
    string getId();
    //To get the Trace
    bool getTrace();
    //Turn On the Trace
    void turnOn();
    //Turn Off the Trace
    void turnOff();
    //Print the Trace
    void printTrace();
    
    
};
#endif /* Maintainer_hpp */

