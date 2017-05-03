//
//  Manager.hpp
//  bankingSystem
//
//  Created by Ichigo Ichie on 2016-10-08.
//  Copyright © 2016 Yiting Wang. All rights reserved.
//


#include <stdlib.h>
#include <ctype.h>
#include <vector>
#include <cctype>
#include <iostream>
#include <string>
#include <stdio.h>
#include "Customer.hpp"

using namespace std;

#ifndef Manager_hpp
#define Manager_hpp

class Manager{
private:
    string id="1000";//set the manager id is 1000
    vector<Customer> customerList;
    
public:
    Manager();
    ~Manager();
    vector<Customer>& getList();
    //open new customer account
    void OpenAccount();
    //close customer account
    void closeAccount();
    //To show just one customer banking information
    void showOne();
    //To show all customers banking information
    void showAllList();
    //To show total saving money
    void bankSaving();
    //To show total chequing money
    void bankChequing();
    //Show the banking all fundings
    void allFund();
    string getId();
    //Give the customer an ID
    void GiveCustomerID();
    //Ask the customer open account('c' for chequing; 's' for saving; 'b' for both)
    void AskCustomerOpenAccount();
    //Close account for finding it in list function
    void FindCustomerInList();
};




#endif /* Manager_hpp */
