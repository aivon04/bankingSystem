//
//  Manager.cpp
//  bankingSystem
//
//  Created by Ichigo Ichie on 2016-10-08.
//  Copyright © 2016 Yiting Wang. All rights reserved.
//

#include "Manager.hpp"


//***************************************************************
//      Manager Constructor
//***************************************************************

Manager::Manager(){
    
}
//***************************************************************
//      Manager Deconstructor
//***************************************************************

Manager::~Manager(){
    
}


//***************************************************************
//      Get the Customer List
//***************************************************************
vector<Customer>& Manager:: getList(){
    return this->customerList;
}

//***************************************************************
//      Get the ID
//***************************************************************
string Manager:: getId(){
    return this->id;
}


//***************************************************************
//      Show the bank total saving money
//***************************************************************
void Manager:: bankSaving(){
    double money=0;
    for(auto i=customerList.begin();i<customerList.end();i++){
        if((*i).getSaving()>0)
            money+=(*i).getSaving();
    }
    cout<<"Total Bank Saving is: "<<money<<endl;
}

//***************************************************************
//      Show the bank total chequing money
//***************************************************************
void Manager:: bankChequing(){
    double money=0;
    for(auto i=customerList.begin();i<customerList.end();i++){
        if((*i).getChequing()>0)
            money+=(*i).getChequing();
    }
    cout<<"Total Bank Chequing is: "<<money<<endl;
}
//***************************************************************
//      Show the bank total funding money
//***************************************************************

void Manager:: allFund(){
    double money=0;
    for(auto i=customerList.begin();i<customerList.end();i++){
        if((*i).getChequing()>0)
            money+=(*i).getChequing();
        if((*i).getSaving()>0)
            money+=(*i).getSaving();
    }
    cout<<"Total Bank Funding is: "<<money<<endl;
    
}

//***************************************************************
//      To open a customer account
//***************************************************************
void Manager::OpenAccount(){
    Customer cust;
    //Give the customer an ID
    if(customerList.size()!=0){
        string id=customerList.back().getId();
        int idNum = atoi(id.c_str())+1;//string to int
        id = to_string(idNum);//int to string
        string newId="0"+id;
        cust.setId(newId);
    }
    else{
        cust.setId("00");
    }
    cout<<"New customerID: "<<cust.getId()<<endl;
    
    
    //To ask the customer open account('c' for chequing; 's' for saving; 'b' for both)
    bool input=false;
    char account;
    while(!input){
        cout<<"Open chequing/saving/both account? C/S/B:  ";
        cin>>account;
        //when the customer enter C/S/B covert to lower case: c/s/b
        account=tolower(account);
        switch (account) {
            case 'c':
                cust.openChequing();
                input=true;
                break;
                
            case 's':
                cust.openSaving();
                input=true;
                break;
                
            case 'b':
                cust.openSaving();
                cust.openChequing();
                input=true;
                break;
            default:
                cout<<"Sorry, Invalid Input. Please enter S/C/B only. Try Again."<<endl;
        }
    }
    //push new Customer to list
    customerList.push_back(cust);
}

//***************************************************************
//      To close a customer account
//***************************************************************
void Manager:: closeAccount(){
    
    //Let the customer to enter the ID
    string id;
    cout<<"Please enter the customer ID:";
    cin>>id;
    bool exist=true;
    Customer *cust;
    for(int i=0; i<customerList.size()&&exist; i++){
        cust=&customerList[i];
        if((*cust).getId().compare(id)==0){
            //find it in list
            bool result=false;
            char account;
            while(!result){
                cout<<"Which account do you want to close? 'C' for chequing, 'S' for saving.";
                cin>>account;
                //when the customer enter C/S covert to lower case: c/s
                account=tolower(account);
                switch (account) {
                    case 'c':
                        if((*cust).getChequing()==0){
                            (*cust).setChequing(-100);
                            cout<<"Successfully closed your chequing account"<<endl;
                        }
                        else{
                            if((*cust).getChequing()<0)
                                cout<<"Sorry, your chequing account does not exist."<<endl;
                            else
                                cout<<"Sorry, your chequing balance is greater than zero."<<endl;
                        }
                        result=true;
                        break;
                        
                    case 's':
                        if((*cust).getSaving()==0){
                            (*cust).setSaving(-100);
                            cout<<"Successfully closed your saving account"<<endl;
                        }
                        else{
                            if((*cust).getSaving()<0)
                                cout<<"Sorry, your saving account doesnt exist."<<endl;
                            else
                                cout<<"Sorry, your saving balance is greater than zero."<<endl;
                        }
                        result=true;
                        break;
                        
                    default:
                        cout<<"Sorry, Invalid Input. Please enter S/C only. Try Again."<<endl;
                }
                
            }
            exist=false;
        }
    }
    if(exist==true)
        cout<<"Error:Customer doesnt exist."<<endl;
}

//***************************************************************
//      To show a list for all customers
//***************************************************************
void Manager:: showAllList(){
    //Title
    cout<<">>>>>>>>>>Customer List<<<<<<<<<<"<<endl;
    //for loop to show all list
    for(int i=0;i<customerList.size();i++){
        cout<<"CustomerID: "<<customerList[i].getId()<<endl;
        cout<<"password: "<<customerList[i].getPsw()<<endl;
        if(customerList[i].getSaving()>=0)
            cout<<"Saving Balance="<<customerList[i].getSaving()<<endl;
        if(customerList[i].getChequing()>=0)
            cout<<"Chequing Balance="<<customerList[i].getChequing()<<endl;
    }
}

//***************************************************************
//      To show the specific one customer
//***************************************************************
void Manager:: showOne(){
    //1. Let the customer to enter the ID
    string id;
    cout<<"Dear customer, please enter your ID:";
    cin>>id;
    //2. find it in list
    bool exist=true;
    for(auto i=customerList.begin(); i<customerList.end()&&exist; i++){
        if((*i).getId().compare(id)==0){
            //3. display the specific customer banking account information
            cout<<">>>>>This is the "<<id<<"'s account info<<<<<"<<endl;
            cout<<"CustomerID"<<(*i).getId()<<": "<<endl;
            cout<<"password: "<<(*i).getPsw()<<endl;
            if((*i).getSaving()>=0)
                cout<<"Saving Balance="<<(*i).getSaving()<<endl;
            if((*i).getChequing()>=0)
                cout<<"Chequing Balance="<<(*i).getChequing()<<endl;
            exist=false;
        }
    }
    if(exist==true){
        cout<<"Sorry, cannot find this customer."<<endl;
    }
}

//***************************************************************
//      Give the customer an ID
//***************************************************************
void Manager::GiveCustomerID(){
    
}


//********************************************************************************************
//      ask the customer open account
//********************************************************************************************

void Manager::AskCustomerOpenAccount(){
}
//************************************************************
//      close account for finding it in list function
//************************************************************
void Manager::FindCustomerInList(){
}
