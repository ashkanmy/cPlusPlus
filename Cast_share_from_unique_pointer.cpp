 #include <memory>
 #include <iostream>
 using std::move;
 using std::unique_ptr;
 using std::shared_ptr;
 using std::cout;
 using std::endl;
 
 class Account{
     public:
        Account(int value):value_(value){}
        void Deposit(int value){
           value_+=value;
        }
        void Withdraw(int value){
           value_-=value;
        }
        int Current(){return value_;}
     private:
        int value_;
 };
 
 int main()
 {
     unique_ptr<Account> up_acc(new Account(1000));
     
     // cast share pointer from unique pointer
     shared_ptr<Account> my_access = move(up_acc);
     
     shared_ptr<Account> your_access = my_access;
     
     cout << "current--> " << my_access->Current() << endl;
     cout << "----\n";
     my_access->Deposit(-1000);
     cout << "current--> " << my_access->Current() << endl;
     cout << "----\n";
     your_access->Deposit(3000);
     cout << "Current-->" << my_access->Current() << endl;
     cout << "----\n";
     cout << "Stack addresses of shared pointers --> " << my_access.get() << " / " << your_access.get() << endl;
     cout << "----\n";
     return 0;
 }
