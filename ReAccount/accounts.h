class Account {
public:
    Account(char* str);
    ~Account();
    char* get_name() const{return name_of_holder;}
    int get_id() const{return id;}
    void tostring();
protected:
    int id;
    char* name_of_holder;
};

class Checking_Account : public Account {
public:
    Checking_Account(char* n, int strt_bal);
    Checking_Account(char* n);
    int get_balance() const{return balance;}
    void deposit(int a);
    void withdraw(int a);
    void tostring();
private:
    int balance;
};
