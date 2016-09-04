#include <iostream>
#include <cstring>
#include <time.h>

#include "accounts.h"

#define MAX_ID_ACCOUNT_NUM 1000000000

Account::Account(char* str)
{
    name_of_holder = new char[strlen(str)+1];
    strcpy(name_of_holder, str);

    srand(time(NULL));
    int rnum = rand() % MAX_ID_ACCOUNT_NUM + 1;
    id = rnum;
}
Account::~Account()
{
    delete[] name_of_holder;
}
void Account::tostring()
{
    std::cout << "name: "
              << name_of_holder
              << " account ID: "
              << id
              << std::endl;
}
Checking_Account::Checking_Account(char* n, int strt_bal)
    : Account(n)
{
    balance = strt_bal;
}
Checking_Account::Checking_Account(char* n)
    : Account(n)
{
    balance = 0;
}
void Checking_Account::deposit(int a)
{
    if(a < 0)
        throw "cannot deposit negative number";
    balance += a;
}
void Checking_Account::withdraw(int a)
{
    if(balance - a)
        throw "cannot overdraft";
    balance -= a;
}
void Checking_Account::tostring()
{
    Account::tostring();
    std::cout << "current balance: " << balance
              << std::endl;
}
int main()
{
    Checking_Account* ca = new Checking_Account("matt");
    ca->tostring();
}
