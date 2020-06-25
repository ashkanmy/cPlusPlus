#include <iostream>
#include <thread>

class Account{
    public:
    Account(int amount):balance_(amount){}
    int getBalance(){return balance_;}
    void Deposit(int amount){
      balance_+=amount;
    }
    void Withdraw(int amount){
        if(balance_>0){
            balance_-=amount;
        }
        else{
            std::cout<<"No withdraw possible (negative balance)"<<std::endl;
            return;
        }
    }
    private:
      int balance_;
};

Account account(1000);

enum ThreadType{
    DEPOSITOR,
    WITHDRAWER
};

void ThreadProcessing(ThreadType typeOfThread){
    while(1){
        switch(typeOfThread){
            case DEPOSITOR:{account.Deposit(2000);
                            std::cout<<"DEPOSITOR: "<<account.getBalance()<<std::endl;
                            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                           }break;
            case WITHDRAWER:{account.Withdraw(1000);
                             std::cout<<"WITHDRAWER: "<<account.getBalance()<<std::endl;
                             std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                            }break;
        }
    }
};

int main(){
    std::thread depositor(ThreadProcessing,ThreadType::DEPOSITOR);
    std::thread withdrawer(ThreadProcessing,ThreadType::WITHDRAWER);
    
    depositor.join();
    withdrawer.join();
    return 0;
}
