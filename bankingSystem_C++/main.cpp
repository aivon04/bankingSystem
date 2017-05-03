//
//  main.cpp
//  bankingSystem
//
//  Created by Ichigo Ichie on 2016-10-08.
//  Copyright © 2016 Yiting Wang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "Manager.hpp"
#include "Customer.hpp"
#include "Maintainer.hpp"

using namespace std;
//***************************************************************
//    	function declaration
//***************************************************************
void Show_Managermenu();
void Show_CustomerMenu();
void Show_MaintainerMenu();
void customerChooseNum();
//***************************************************************
//    	MENU FUNCTION
//***************************************************************

//Show the customer menu
void Show_CustomerMenu()

{
    
    cout<<">>>>>>>>>>>>>>>Welcome to use Bank Customer System<<<<<<<<<<<<<<\n";
    
    cout<<"****************************************************************\n";
    
    cout<<"           1.Deposit           |        2.Withdraw              \n";
    
    cout<<"           3.Set password      |        4.Open(complement)      \n";
    
    cout<<"           5.Account Balance   |        6.Total Balance         \n";
    
    cout<<"   7.transfer specific amount from one accout to another client \n";
    
    cout<<"   8.transfer sum from one accout to another account            \n";
    
    cout<<"   9.transfer sum of one account to another client              \n";
    
    cout<<"   10.transfer specific amount from one accout to another       \n";
    
    cout<<"                           0.Log out                            \n";
    
    cout<<"****************************************************************\n";
    
}

//Show the manager menu
void Show_Managermenu()

{
    
    cout<<">>>>>>>>>Welcome to use Bank Manager System<<<<<<<<<<<\n";
    
    cout<<"******************************************************\n";
    
    cout<<"         1.Open Account    |    2.Close Account       \n";
    
    cout<<"         3.Show One        |    4.Show All            \n";
    
    cout<<"         5.SUM(saving)     |    6.SUM(chequing)       \n";
    
    cout<<"         7.Total Funding   |    0.Log out             \n";
    
    cout<<"******************************************************\n";
    
}

//Show the maintainer menu

void Show_MaintainerMenu()

{
    
    cout<<">>>>>>>>>>Welcome to use Bank Maintainer System<<<<<<<<<<<\n";
    
    cout<<"**********************************************************\n";
    
    cout<<"         1.Trace(Status)    |         2.Trace(On)         \n";
    
    cout<<"         3.Trace(Off)       |         0.Logout            \n";
    
    cout<<"**********************************************************\n";
    
}

//***************************************************************
//      ChooseNum FUNCTION
//***************************************************************
void customerChooseNum(){
    
}
//***************************************************************
//    	Current Time FUNCTION
//***************************************************************

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

//***************************************************************
//    	WRITE FUNCTION
//***************************************************************

static void write(ofstream &file, string description){
    if(file.is_open())
        file<<currentDateTime()+"\t\t\t"+description+"\n";
}


//***************************************************************
//    	MAIN FUNCTION
//***************************************************************


int main(int argc, const char * argv[]) {
    Manager manager;//manager user id = 1000
    Maintainer maintainer;//maintainer user id = 2000
    vector<Customer> *list;
    ofstream traceFile;
    char choosenum;
    list=&manager.getList();//list is a pointer pointing to object
    bool trace=maintainer.getTrace();
    
    
    while(1){
        if(trace==true) traceFile.open ("/Users/wangyiting/Desktop/<WANG YITING>_C++_Assignment/<WANG YITING>_C++_Deliverable 3/Trace.txt");
        //Let the user enter the login id
        string id;
        cout<<"Please Enter Your Login ID: ";
        cin>>id;
        //identify role by the first char of the id
        char role=id.at(0);
        if(role=='0'){
            bool exist=true;
            Customer *customer= NULL;
            for(int i=0; i<(*list).size()&&exist; i++){
                customer=&((*list)[i]);
                if((*customer).getId().compare(id)==0){
                    exist=false;
                }
            }
            if(exist)
                //Customer id does not exist
                cout<<"Sorry, You are not in our Bank System, Please go to Manager Menu for opening an account."<<endl;
            else{
                //Customer exists, then ask for password
                string psw;
                cout<<"Please enter your password: ";
                cin>>psw;
                //verify psw
                if((*customer).getPsw().compare(psw)==0){
                    cout<<"password match. Customer successfully login."<<endl;
                    write(traceFile,"CustomerID:"+id+" login");
                    bool logout=false;
                    while(!logout){
                        Show_CustomerMenu();
                        cout<<"Enter your option : ";
                        cin>>choosenum;
                        switch (choosenum) {
                            case '0':
                                //logout
                                logout=true;
                                write(traceFile,"logout");
                                cout<<"You have successfully logout."<<endl;
                                break;
                            case '1':
                                //deposite
                                (*customer).deposit();
                                write(traceFile,"deposit");
                                break;
                            case '2':
                                //withdraw
                                (*customer).withdraw();
                                write(traceFile,"withdraw");
                                break;
                            case '3':
                                //Set new password
                                cout<<"New password:";
                                cin>>psw;
                                (*customer).setPsw(psw);
                                write(traceFile,"Set new password");
                                break;
                            case '4':
                                //Open complementary accountOpen complementary account
                                (*customer).openComplement();
                                write(traceFile,"Open complementary account");
                                break;
                            case '5':
                                //Get chequing or saving account balance
                                (*customer).accountBalance();
                                write(traceFile,"Get chequing or saving account balance");
                                break;
                            case '6':
                                //Get total balance
                                (*customer).totalBalance();
                                write(traceFile,"Get total balance");
                                break;
                            case '7':
                                //Make transaction to another client
                                (*customer).transAmountCus(manager.getList());
                                write(traceFile,"Make transaction to another client");
                                break;
                            case '8':
                                //Transfer sum to another account
                                (*customer).transSumAcctoAcc();
                                write(traceFile,"Transfer sum to another account");
                                break;
                            case '9':
                                //Transfer sum of one account to another client
                                (*customer).transSumCustoCus(manager.getList());
                                write(traceFile,"Transfer sum of one account to another client");
                                break;
                            case '10':
                                //Make the transaction between accounts
                                (*customer).transBetweenAccounts();
                                write(traceFile,"Make the transaction between accounts");
                                break;
                            default:
                                cout<<"Invalid Input. Please try again."<<endl;
                        }
                    }
                    
                }
                else{
                    cout<<"Sorry! Incorrect password"<<endl;
                    
                }
            }
        }
        else if(role=='1'){
            //manager
            if(manager.getId().compare(id)==0){
                
                //id matched
                write(traceFile,"ManagerID:"+id+" login");
                bool logmanager=false;
                while(!logmanager){
                    Show_Managermenu();
                    cout<<"Enter your option : ";
                    cin>>choosenum;
                    switch (choosenum) {
                        case '0':
                            //logout
                            logmanager=true;
                            write(traceFile,"logout");
                            cout<<"You have successfully logout."<<endl;
                            break;
                        case '1':
                            //Open account for customer
                            manager.OpenAccount();
                            write(traceFile,"Open account");
                            break;
                        case '2':
                            //Close account for customer
                            manager.closeAccount();
                            write(traceFile,"Close account");
                            break;
                        case '3':
                            //Show one specific customer
                            manager.showOne();
                            write(traceFile,"Show one specific customer");
                            break;
                        case '4':
                            //Show all customers
                            manager.showAllList();
                            write(traceFile,"Show all customers");
                            break;
                        case '5':
                            //Show sum of saving in bank
                            manager.bankSaving();
                            write(traceFile,"Show sum of saving in bank");
                            break;
                        case '6':
                            //Show sum of chequing in bank
                            manager.bankChequing();
                            write(traceFile,"Show sum of chequing in bank");
                            break;
                        case '7':
                            //Show all funding in bank
                            manager.allFund();
                            write(traceFile,"Show all funding in bank");
                            break;
                        default:
                            cout<<"Input incorrect. try again"<<endl;
                    }
                }
            }
            else{
                cout<<"Sorry! Manager ID incorrects.Try again!"<<endl;
                continue;
            }
        }
        else if(role=='2'){
            //maintainer
            if(maintainer.getId().compare(id)==0){
                
                //id matched
                write(traceFile,"MaintainerID:"+id+" login");
                bool logmaintainer=false;
                while(!logmaintainer){
                    Show_MaintainerMenu();
                    cout<<"Enter your option : ";
                    cin>>choosenum;
                    switch (choosenum) {
                        case '0':
                            //maintainer log out
                            logmaintainer=true;
                            cout<<"You have successfully logout."<<endl;
                            write(traceFile,"logout");
                            break;
                        case '1':
                            //reset Customer Password to default 000
                            maintainer.getTrace();
                            write(traceFile,"display status of trace");
                            break;
                        case '2':
                            //maintainer turn on the trace
                            maintainer.turnOn();
                            write(traceFile,"turn on trace");
                            break;
                        case '3':
                            //maintainer turn off the trace
                            maintainer.turnOff();
                            write(traceFile,"turn off trace");
                            break;
                        default:
                            cout<<"Error: Please enter again."<<endl;
                            
                    }
                }
                
            }
            else{
                cout<<"Sorry, Maintainer ID incorrects.Try again"<<endl;
                continue;
            }
        }
        else{
            cout<<"Sorry Invalid ID!!"<<endl;
        }
        if(traceFile.is_open())
            traceFile.close();
    }
    return 0;
}
