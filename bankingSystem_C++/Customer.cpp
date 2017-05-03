//
//  Customer.cpp
//  bankingSystem
//
//  Created by Ichigo Ichie on 2016-10-08.
//  Cchoosenumyright © 2016 Yiting Wang. All rights reserved.
//

#include "Customer.hpp"


Customer::Customer(){
    id="0";
    password="000";
    chequing=-100;
    saving=-100;
    
}

//***************************************************************
//      Customer Deconstructor
//***************************************************************

Customer::~Customer(){
    
}
//***************************************************************
//      Customer set Password
//***************************************************************

void Customer:: setPsw(string psw){
    this->password=psw;
}
//***************************************************************
//      Customer get Password
//***************************************************************
string Customer:: getPsw(){
    return password;
}
//***************************************************************
//      To open chequing account
//***************************************************************
void Customer:: openChequing(){
    this->chequing=0;
    cout<<"open chequing account successfully"<<endl;
}

//***************************************************************
//      To open saving account
//***************************************************************
void Customer:: openSaving(){
    this->saving=0;
    cout<<"open saving account successfully"<<endl;
}



//***************************************************************
//      Check the current accounts
//***************************************************************
char Customer:: currentAccount(){
    char account;
    while(1){
        cout<<"c: Chequing  ｜  s: Saving"<<endl;
        cout<<"Which account do you want to use (c/s): ";
        cin>>account;
        //when the customer enter C/S covert to lower case: c/s
        account=tolower(account);
        switch (account) {
                
            case 'c':
                //check exist of chequing account
                if(getChequing()>=0){
                    return 'c';
                }
                else{
                    //saving not exists
                    cout<<"You don't have a Chequing account. Please Try again."<<endl;
                    
                }
                
                break;
                
            case 's':
                //check exist of saving account
                if(getSaving()>=0){
                    return 's';
                    
                }
                else{
                    //saving not exists
                    cout<<"You don't have a Saving account. Please Try again."<<endl;
                }
                
                break;
            default:
                cout<<"Invalid input. Please enter C/S only. Please Try again."<<endl;
        }
    }
}


//***************************************************************
//      set Functions
//***************************************************************

//set ID
void Customer:: setId(string newId){
    this->id=newId;
}
//set money from Chequing account
void Customer:: setChequing(double money){
    this->chequing=money;
}
//set money from Saving account
void Customer:: setSaving(double money){
    this->saving=money;
}

//***************************************************************
//      get Functions
//***************************************************************

//get ID
string Customer:: getId(){
    return this->id;
}
//get the money from chequing account
double Customer:: getChequing(){
    return this->chequing;
}
//get the money from saving account
double Customer:: getSaving(){
    return this->saving;
}

//***************************************************************
//      To show the customer account balance (saving||chequing)
//***************************************************************

double Customer:: accountBalance(){
    char account=currentAccount();
    double result=0;
    if (account=='c'){
        result=getChequing();
        cout<<"Chequing balance is "<<result<<endl;
    }
    if (account=='s'){
        result=getSaving();
        cout<<"Saving balance is "<<result<<endl;
    }
    return result;
}

//***************************************************************
//      To show the total balance
//***************************************************************

double Customer:: totalBalance(){
    double result=0;
    if (this->saving>0)
        result=result+saving;
    if(this->chequing>0)
        result=result+chequing;
    cout<<"Your total balance is $"<<result<<endl;
    return result;
}

//***************************************************************
//      ask the account money Functions
//***************************************************************

double Customer:: askMoney(string num){
    double money;
    while(1){
        cout<<"Amount of money you want to "<<num<<":";
        cin>>money;
        if(money>0)
            return money;
        else
            cout<<"Invalid input. Input must be > 0. Please Try again."<<endl;
    }
}

//***************************************************************
//      Deposit money to saving || chequing account Functions
//***************************************************************

void Customer:: deposit(){
    
    double money=askMoney("deposit");
    char account=currentAccount();
    if (account=='c'){
        setChequing(getChequing()+money);
        cout<<"Successfully, current deposited $"<<this->chequing<<endl;
    }
    if (account=='s'){
        setSaving(getSaving()+money);
        cout<<"Successfully, current deposited $"<<this->saving<<endl;
    }
    
}

//***************************************************************
//      Withdraw money from saving || chequing account Functions
//***************************************************************

void Customer:: withdraw(){
    char account=currentAccount();
    if(account=='c')
    {
        cout<<"Chequing balance="<<this->chequing;
    }
    else
        cout<<"Saving balance="<<this->saving;
    
    double money=askMoney("withdraw");
    if(account=='s'){
        if (getSaving()>=money) {
            //sufficient fund
            setSaving(getSaving()-money);
            cout<<"successfully withdrawed $"<<money<<" from Saving account"<<endl;
            cout<<"Saving balance="<<getSaving()<<endl;
            
        }
        else{
            cout<<"Sorry, Insuffient money in Saving account"<<endl;
        }
    }
    else{
        int balance=getChequing()-money-2;//$2 transaction fee
        if( balance>=0){
            if(balance<1000){
                char choosenum;
                bool result=true;
                while(result){
                    cout<<"Chequing account under $1000 and you will be charged $2. Continue? Y/N:";
                    cin>>choosenum;
                    choosenum=tolower(choosenum);
                    if(choosenum=='y'){
                        setChequing(balance);
                        cout<<"Charged $2 successfully"<<endl;
                        cout<<"Successfully withdrawed $"<<money<<" from chequing account"<<endl;
                        cout<<"chequing balance="<<getChequing()<<endl;
                        result=false;
                    }
                    else if(choosenum=='n'){
                        cout<<"Withdraw cancelled"<<endl;
                        result=false;
                    }
                    else{
                        cout<<"Invalid input. Please enter Y/N only. Try Again."<<endl;
                    }
                }
            }
            else{
                setChequing(getChequing()-money);
                cout<<"Successfully withdrawed $"<<money<<" from chequing account"<<endl;
                cout<<"Chequing balance="<<getChequing()<<endl;
            }
        }
        else
            cout<<"Insufficient fund in Chequing account"<<endl;
    }
}


//*******************************************************************
//      open the saving or chequing account as complement Functions
//*******************************************************************

void Customer:: openComplement(){
    if(getChequing()<0){
        openChequing();
        cout<<"Choosenumen chequing as complement successfully"<<endl;
    }
    if(getSaving()<0){
        openSaving();
        cout<<"Choosenumen saving as complement successfully"<<endl;
    }
}

//***************************************************************
//      Transfer specific amount between accounts
//***************************************************************

void Customer:: transBetweenAccounts(){
    char account=currentAccount();
    //specific amount to aother account
    double money=-100;
    double sufficiency;
    bool result=false;
    //make sure enough money
    while(!result){
        cout<<"Amount of money you want to transfer: $";
        cin>>money;
        if(account=='s')
            sufficiency=getSaving() - money;
        else
            sufficiency=getChequing() - money - 2;//including $2 transition fee
        if (money<0)
            cout<<"Failed: Amount of money cannot be negative. Please Try Again"<<endl;
        else if (sufficiency<0)
            cout<<"Failed: current account balance is not engouh. Please Try Again"<<endl;
        else
            result = true;
    }
    
    char choosenum;
    result=false;
    //make sure another account exist
    if(account=='s'){
        if(getChequing()<0){
            while(!result){
                cout<<"You still do not have a Chequing account yet. Do you want to choosenumen it now? Y/N: ";
                cin>>choosenum;
                choosenum=tolower(choosenum);
                switch (choosenum) {
                    case 'y':
                        //open chequing account
                        openComplement();
                        result=true;
                        break;
                    case 'n':
                        cout<<"Already cancelled transfer."<<endl;
                        return;
                    default:
                        cout<<"Invalid input. Please enter Y/N only. Try Again."<<endl;
                }
            }
        }
        //chequing accout exists
        saving=saving-money;
        chequing=chequing+money;
        cout<<"Successfully transfter $"<<money<<" from Saving to Chequing account."<<endl;
    }
    else{
        if(getSaving()<0){
            while(!result){
                cout<<"You still do not have a Saving account yet. Do you want to choosenumen it now? Y/N: ";
                cin>>choosenum;
                //when the user enter 'Y'/'N', lower the case to 'y'/'n'.
                choosenum=tolower(choosenum);
                switch (choosenum) {
                    case 'y':
                        //open saving account
                        openComplement();
                        result=true;
                        break;
                    case 'n':
                        cout<<"Already cancelled transfer."<<endl;
                        return;
                    default:
                        cout<<"Invalid input. Please enter Y/N only. Try Again."<<endl;
                }
            }
        }
        //saving accout exists
        result=false;
        double balance=chequing-money;
        if(balance<1000){
            while(!result){
                cout<<"chequing account under $1000 and you will be charged $2. Continue? Y/N: ";
                cin>>choosenum;
                choosenum=tolower(choosenum);
                switch (choosenum) {
                    case 'y':
                        chequing=chequing-2;//$2 transaction fee
                        cout<<"Successfully charge $2."<<endl;
                        result=true;
                        break;
                    case'n':
                        cout<<"Already cancelled transfer."<<endl;
                        return;
                    default:
                        cout<<"Invalid input. Please enter Y/N only. Try Again."<<endl;
                }
            }
        }
        chequing=chequing-money;
        saving=saving+money;
        cout<<"Successfully transfer $"<<money<<"from Chequing to Saving account."<<endl;
    }
    
}


//***************************************************************
//      Transfer sum amount between accounts
//***************************************************************

void Customer:: transSumAcctoAcc(){
    char account=currentAccount();
    char choosenum;
    bool result=false;
    //make sure another account exist
    if(account=='s'){
        if(getChequing()<0){
            while(!result){
                cout<<"You dont have Chequing account yet. Do you want to open it now? Y/N: ";
                cin>>choosenum;
                choosenum=tolower(choosenum);
                switch (choosenum) {
                    case 'y':
                        //transfer to chequing account
                        openComplement();
                        result=true;
                        break;
                    case 'n':
                        cout<<"Already cancelled transfer."<<endl;
                        return;
                    default:
                        cout<<"Invalid input. Please enter Y/N only. Try Again."<<endl;
                }
            }
        }
        //chequing accout exists: saving to chequing
        chequing=chequing+saving;
        saving=0;
        cout<<"Successfully transfter Saving sum to Chequing account."<<endl;
    }
    else{
        if(getSaving()<0){
            while(!result){
                cout<<"You dont have Saving account yet. Do you want to open it now? Y/N: ";
                cin>>choosenum;
                choosenum=tolower(choosenum);
                switch (choosenum) {
                    case 'y':
                        openComplement();//transfer to saving account
                        result=true;
                        break;
                    case 'n':
                        cout<<"Already cancelled transfer."<<endl;
                        return;
                    default:
                        cout<<"Invalid input. Please enter Y/N only. Try Again."<<endl;
                }
            }
        }
        
        result=false;
        while(!result){
            cout<<"chequing account under $1000 and you will be charged $2. Continue? Y/N: ";
            cin>>choosenum;
            choosenum=tolower(choosenum);
            switch (choosenum) {
                case 'y':
                    saving=saving+chequing-2;
                    chequing=0;
                    cout<<"Successfully charge $2 transaction fee."<<endl;
                    cout<<"Successfully transfter Chequing sum to Saving account."<<endl;
                    result=true;
                    break;
                case'n':
                    cout<<"Already cancelled transfer."<<endl;
                    return;
                default:
                    cout<<"Invalid input. Please enter Y/N only. Try Again."<<endl;
            }
        }
    }
}


//***************************************************************
//      Transfer amount of money to another customer
//***************************************************************

void Customer::transAmountCus(vector<Customer> &list){
    
    vector<Customer> *customerList=&list;
    //1. ask Customer ID
    string id;
    cout<<"Recipient CustomerId:";
    cin>>id;
    //2. find it in list
    bool exist=true;
    Customer *Recipient = NULL;
    for(int i=0; i<(*customerList).size()&&exist; i++){
        Recipient=&((*customerList)[i]);
        if((*Recipient).getId().compare(id)==0){
            exist=false;
        }
    }
    if(exist==true){
        cout<<"Recipient does not exist"<<endl;
        return;
    }
    else{
        char account=currentAccount();
        //access current balance
        double sufficiency;
        if(account=='s'){
            cout<<"Saving balance="<<getSaving()<<endl;
            sufficiency=getSaving();
        }
        else{
            cout<<"Chequing balance="<<getChequing()<<endl;
            sufficiency=getChequing()-2;//include $2 transaction fee
            
        }
        
        double money=-10;
        bool result=false;
        while(!result){
            cout<<"Amounting of money you want to transfer: $";
            cin>>money;
            if(money<0)
                cout<<"Error: Amount of money must be > 0. Try Again."<<endl;
            else if(money>sufficiency){
                bool result=false;
                char choosenum;
                while(!result){
                    cout<<"Error: You balance is not enough for this transaction. Try Again? Y/N: ";
                    cin>>choosenum;
                    choosenum=tolower(choosenum);
                    switch(choosenum){
                        case 'y':
                            break;
                        case 'n':
                            result=true;
                            cout<<"Transfer cancelled"<<endl;
                            return;
                        default:
                            cout<<"Invalid input. Please enter Y/N only. Try Again."<<endl;
                            
                            
                    }
                }
            }
            else
                result=true;
        }
        char choosenum;
        result=false;
        while(!result){
            cout<<"Recipient account S/C: ";
            cin>>choosenum;
            choosenum=tolower(choosenum);
            double moneyy=0;
            int balance;
            switch (choosenum) {
                case 's':
                    if((*Recipient).getSaving()<0)
                        cout<<"Recipient saving account doesnot exist. Transaction failed."<<endl;
                    else{
                        if(choosenum=='s'){
                            //saving to saving
                            moneyy=(*Recipient).getSaving();
                            (*Recipient).setSaving(moneyy+money);
                            moneyy=getSaving()-money;
                            setSaving(moneyy);
                            cout<<"Successfully transfer $"<<money<<" from Saving account to Customer"<<(*Recipient).getId()<<"'s Saving account."<<endl;
                        }
                        else{
                            //chequing to saving
                            moneyy=(*Recipient).getSaving()+money;
                            (*Recipient).setSaving(moneyy);
                            balance=getChequing()-money;
                            if(balance<1000){
                                setChequing(balance-2);
                                cout<<"chequing account under $1000 and you has been charged $2."<<endl;
                            }
                            cout<<"Successfully transfer $"<<money<<" from Chequing account to Customer"<<(*Recipient).getId()<<"'s Saving account."<<endl;
                        }
                    }
                    result=true;
                    break;
                case 'c':
                    if((*Recipient).getChequing()<0)
                        cout<<"Recipient chequing account doesnot exist. Transaction failed."<<endl;
                    else{
                        if(account=='s'){
                            //saving to chequing
                            
                            moneyy=(*Recipient).getChequing()+money;
                            (*Recipient).setChequing(moneyy);
                            moneyy=getSaving()-money;
                            setSaving(money);
                            cout<<"Successfully transfer $"<<money<<" from Saving account to CustomerID"<<(*Recipient).getId()<<"'s Chequing account."<<endl;
                        }
                        else{
                            //chequing to chequing
                            moneyy=(*Recipient).getChequing()+money;
                            (*Recipient).setChequing(moneyy);
                            balance=getChequing()-money;
                            if(balance<1000){
                                setChequing(balance-2);
                                cout<<"chequing account under $1000 and you has been charged $2."<<endl;
                            }
                            cout<<"Successfully transfer $"<<money<<" from Chequing account to CustomerID"<<(*Recipient).getId()<<"'s Chequing account."<<endl;
                        }
                    }
                    result=true;
                    break;
                default:
                    cout<<"Error: enter S/C only. Try Again."<<endl;
                    break;
            }
        }
    }
}


//***************************************************************
//     Transfer current sum to another customer account
//***************************************************************
void Customer:: transSumCustoCus(vector<Customer> &list){
    vector<Customer> *customerList=&list;
    //1. ask Customer ID
    string id;
    cout<<"Recipient CustomerId:";
    cin>>id;
    //2. find it in list
    bool exist=true;
    Customer *Recipient = NULL;
    for(int i=0; i<(*customerList).size()&&exist; i++){
        Recipient=&((*customerList)[i]);
        if((*Recipient).getId().compare(id)==0){
            exist=false;
        }
    }
    if(exist==true){
        cout<<"Recipient does not exist"<<endl;
        return;
    }
    else{
        char account=currentAccount();
        //access current balance
        double sufficiency;
        if(account=='s'){
            cout<<"Saving balance="<<getSaving()<<endl;
            sufficiency=getSaving();
        }
        else{
            cout<<"Chequing balance="<<getChequing()<<endl;
            sufficiency=getChequing()-2;//include $2 transaction fee
            
        }
        
        double money=sufficiency;
        
        char choosenum;
        bool result=false;
        while(!result){
            cout<<"Recipient account S/C: ";
            cin>>choosenum;
            choosenum=tolower(choosenum);
            double money2=0;
            int balance;
            switch (choosenum) {
                case 's':
                    if((*Recipient).getSaving()<0)
                        cout<<"Recipient saving account doesnot exist. Transaction failed."<<endl;
                    else{
                        if(choosenum=='s'){
                            //saving to saving
                            money2=(*Recipient).getSaving();
                            (*Recipient).setSaving(money2+money);
                            money2=getSaving()-money;
                            setSaving(money2);
                            cout<<"Successfully transfer $"<<money<<" from Saving account to Customer"<<(*Recipient).getId()<<"'s Saving account."<<endl;
                        }
                        else{
                            //chequing to saving
                            money2=(*Recipient).getSaving()+money;
                            (*Recipient).setSaving(money2);
                            balance=getChequing()-money;
                            if(balance<1000){
                                setChequing(balance-2);
                                cout<<"chequing account under $1000 and you has been charged $2."<<endl;
                            }
                            cout<<"Successfully transfer $"<<money<<" from Chequing account to Customer"<<(*Recipient).getId()<<"'s Saving account."<<endl;
                        }
                    }
                    result=true;
                    break;
                case 'c':
                    if((*Recipient).getChequing()<0)
                        cout<<"Recipient chequing account doesnot exist. Transaction failed."<<endl;
                    else{
                        if(account=='s'){
                            //saving to chequing
                            
                            money2=(*Recipient).getChequing()+money;
                            (*Recipient).setChequing(money2);
                            money2=getSaving()-money;
                            setSaving(money);
                            cout<<"Successfully transfer $"<<money<<" from Saving account to CustomerID"<<(*Recipient).getId()<<"'s Chequing account."<<endl;
                        }
                        else{
                            //chequing to chequing
                            money2=(*Recipient).getChequing()+money;
                            (*Recipient).setChequing(money2);
                            balance=getChequing()-money;
                            if(balance<1000){
                                setChequing(balance-2);
                                cout<<"chequing account under $1000 and you has been charged $2."<<endl;
                            }
                            cout<<"Successfully transfer $"<<money<<" from Chequing account to CustomerID"<<(*Recipient).getId()<<"'s Chequing account."<<endl;
                        }
                    }
                    result=true;
                    break;
                default:
                    cout<<"Invalid Input! Please enter S/C only. Try Again."<<endl;
                    break;
            }
        }
    }
}





