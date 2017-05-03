//
//  Maintainer.cpp
//  bankingSystem
//
//  Created by Ichigo Ichie on 2016-10-08.
//  Copyright © 2016 Yiting Wang. All rights reserved.
//



#include "Maintainer.hpp"

//***************************************************************
//      Maintainer Constructor
//***************************************************************

Maintainer::Maintainer(){
    
}
//***************************************************************
//      Maintainer Deconstructor
//***************************************************************

Maintainer::~Maintainer(){
    
}

//***************************************************************
//      Get the ID
//***************************************************************
string Maintainer:: getId(){
    return this->id;
}

//***************************************************************
//      Get the trace
//***************************************************************
bool Maintainer:: getTrace(){
    return this->trace;
}

//***************************************************************
//     Turn ON the trace
//***************************************************************
void Maintainer:: turnOn(){
    this->trace=false;
}

//***************************************************************
//     Turn Off the trace
//***************************************************************
void Maintainer:: turnOff(){
    this->trace=true;
}


//***************************************************************
//      Print the trace
//***************************************************************
void Maintainer::printTrace(){
    cout<<trace<<endl;
}