#include "pch.h"
#include<iostream>
#include<string>
#include<cmath>
#include<ctime>

using namespace std;
const int SIZE = 5;

/////////////////////Unit Test Section/////////////////////
int UnitTesting(int a,char **b) {
    testing::InitGoogleTest(&a,b);
    return RUN_ALL_TESTS();
}
///////////////////////////End Test Section///////////////

class Account {

private:
    int id;
    double balance = .0;
    time_t dateCreated;
public:

    Account();
    int getId() { return id; }
    double getBalance() { return balance; }
    time_t getDate();

    //below are the set methods
    void setId(int);
    void setBalance(double);
    void withdraw(double);
    void deposit(double);
};
Account::Account() {
    id = 0;
    balance = 0;
    // current date/time based on current system
    dateCreated = time(0);
}

void Account::deposit(double depAmount) {
    balance = balance + depAmount;
}

void Account::withdraw(double amount)
{
    balance = balance - amount;
}
void Account::setId(int identity) {
    id = identity;
}
void Account::setBalance(double bal) {
    balance = bal;
}


time_t Account::getDate() {
    return dateCreated;
}

class SavingsAccount : public Account {

private:
    double annualInterestRate;
    double monthlyInterestRate;
public:
    SavingsAccount();
    double getMonthlyInterestRate();
    double getMonthlyInterest();

};

SavingsAccount::SavingsAccount() {
    annualInterestRate = 0;
    monthlyInterestRate = 0;
}
double SavingsAccount::getMonthlyInterestRate()
{
    monthlyInterestRate = (annualInterestRate / 12) / 100;
    return monthlyInterestRate;
}

double SavingsAccount::getMonthlyInterest()
{
    double balance = getBalance();
    return balance * monthlyInterestRate;
}

class CheckingAccount : public Account {

private:
    double overdraft;
public:
    double getOveradraft() { return overdraft; }
};

void showMenu()
{
    cout << endl;
    cout << "*************MENU**************" << endl;
    cout << "1. Check the balance" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Exit" << endl;
    cout << "*******************************" << endl;
    cout << endl;
}

//Global Array 
Account arrId[SIZE];
void createAccount(Account accs[])
{
    int uId;
    double initDep;
    time_t date;
    char* dt;
    for (int acc = 0; acc < SIZE; acc++)
    {
        cout << "Enter id : ";
        cin >> uId;
        if (uId < 1)
        {
            cout << "Enter valid id" << endl;
        }
        else
        {
            accs[acc].setId(uId);
            cout << "Enter initial deposit amount R ";
            cin >> initDep;
            accs[acc].setBalance(initDep); // change to deposit

            //Loading the ID VALUES
            arrId[acc].setId(uId);
            arrId[acc].setBalance(initDep);

            //storing the current date time below
            date = accs[acc].getDate();
            dt = ctime(&date);
            cout << "Date of Account creation : " << dt << endl;
        }
    }
}

//This is funtion implemented to ensure that a valid id is Entered
int ValidId(int index) {
        //status = users[x].getId();
        //Returns a -1 when the id is invalid
        //Returns a 1 when the id is valid
        if (arrId[index].getId()>0) { return 1; }
        else { return -1; }
}



////////////////////////////////////////////////////////////////////////////////UNIT TEST SECTION////////////////////////////////////////////////////////////////////////////////////////////

TEST(AtmSystem, DebitedAmt) {
    //Testing the function "withdraw" from the Account super class
    //After the withdrawal the balance amount should be decreased by the amount specified in the paranthesis "withdraw(900)"
    //The value 100 should be returned because of the withdrawal of 900 from 1000
    //Making sure that the balance is debited after the withdrawal amount requested
    Account arr;
    arr.setBalance(1000);
    arr.withdraw(900);
     ASSERT_EQ(arr.getBalance(),100);
}

//This is used to test the validation of the Id
TEST(AtmSystem, idTest) {
    for (int x = 0; x < SIZE; x++) {
     //Note that a one is returned to denote that the id is Valid and a -1 is returned to indicate that the id is invalid
        ASSERT_EQ(1,ValidId(x));
    }
}

//Testing the deposit function below
TEST(AtmSystem, DepositFunctionTest) {
    Account arr;
    arr.deposit(1000);
    //The balance of the instantiated array should return 1000 since the deposit function from the super class has been invoked e.g deposit(1000)
    //The can also serve to test the getBalance() funtion from the super class Account
    ASSERT_EQ(arr.getBalance(), 1000);
}

TEST(AtmSystem,negativeNumber ) {
    for (int x = 0; x < SIZE; x++) {
        ASSERT_TRUE(arrId[x].getBalance() >= 0);
        }
}
/////////////////////////////////////////////////////////////////////////////////END OF UNIT TESTS///////////////////////////////////////////////////////////////////////////////////////////



int main(int argc, char** argv)
{
    Account accounts[SIZE];
    SavingsAccount sAcc[SIZE];
    CheckingAccount cAcc[SIZE];
    int userId, selection;
    int count = 0;
    double withdrwalAmnt = 0;
    double depAmnt = 0;
    int ct = 0;

    cout << endl;

    // Creating new accounts
    createAccount(accounts);
    UnitTesting(argc, argv);
    // Perfroming transactions
    cout << "-------Transactions--------" << endl;
    while (true)
    {
        cout << "Enter id : ";
        cin >> userId;
        if (userId < 1 && userId>5)
        {
            cout << "Enter valid id" << endl;
        }
        else
        {
            showMenu();
            cout << "Make selection : ";
            cin >> selection;
            switch (selection)
            {
            case 1:
                cout << "Your balance is : " << accounts[userId - 1].getBalance() << endl; // note change
                break;
            case 2:
                cout << "Enter amount to withdraw : ";
                cin >> withdrwalAmnt;
                accounts[userId - 1].withdraw(withdrwalAmnt);
                break;
            case 3:
                cout << "Deposit amount : ";
                cin >> depAmnt;
                accounts[userId - 1].deposit(depAmnt);
                break;
            case 4:
                break;
            }
        }

        if (ct == 4) { ct = 0; }
        ct++;
    }
    system("pause");
    return 0;
}