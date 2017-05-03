//
//  Customer.hpp
//  bankingSystem
//
//  Created by Ichigo Ichie on 2016-10-08.
//  Copyright © 2016 Yiting Wang. All rights reserved.
//



#include <stdio.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#ifndef Customer_hpp
#define Customer_hpp

class Customer{
    
private:
    string id;
    string password;
    double saving;
    double chequing;
public:
    Customer();
    ~Customer();
    void openChequing();
    void openSaving();
    void openComplement();    
    void setId(string newId);
    void setChequing(double money);
    void setSaving(double money);
    void setPsw(string psw);
    double getChequing();
    double getSaving();
    string getId();
    string getPsw();
    double accountBalance();
    double totalBalance();
    
private:
    char currentAccount();
    double askMoney(string num);
    
public:
    //deposit money
    void deposit();
    //withdraw money
    void withdraw();
    
    //transfer specific amount between accounts
    void transBetweenAccounts();
    //transfer a sum from ac account to another account
    void transSumAcctoAcc();
    //transfer amount of money to another client
    void transAmountCus(vector<Customer> &list);
    //transfer current sum to another client account
    void transSumCustoCus(vector<Customer> &list);
    
    
    
};
#endif /* Customer_hpp */
