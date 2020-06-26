#include <iostream>
#include <thread>
#include <mutex>

enum ThreadType{
    DEPOSITOR,
    WITHDRAWER
};


class Account{
    public:
    Account(double balance):balance_(balance){}
    double getBalance(){return balance_;}
    void deposit(double amount){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        balance_+=amount;
    }
    void withdraw(double amount){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        if (balance_<0){
            std::cout<<"Negative balance, can't withdraw!"<<std::endl;
            return;
        }
        else{
            balance_-=amount;
        }
    }
    private:
       double balance_;
};

 
class Thread{
    public:
      Thread(Account *account,ThreadType typeOfThread){
          // set the thread with (Account,Type) and make it null
          pAccount_=account;
          typeOfThread_ = typeOfThread;
          pThread_ = nullptr;
          
      };
      ~Thread(){ 
          delete pThread_;
          delete pAccount_;
      }  
      void start(){
          pThread_ = new std::thread(&Thread::run,this);
      }
      void end(){
          pThread_->join();
      }
    private:
      std::thread *pThread_;
      std::mutex static locker_;
      Account *pAccount_;
      ThreadType typeOfThread_;
      
      void run(){
        while(1)
        {
            switch(typeOfThread_){
                                  case DEPOSITOR :
                                  { 
                                      locker_.lock();
                                      std::cout<<"--> current amount: "<<pAccount_->getBalance()<<std::endl;
                                      std::cout<<"--> after deposit "<<pAccount_->getBalance()<<std::endl;
                                      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                                      pAccount_->deposit(500);
                                      locker_.unlock();
                                  }
                                  break;
                                  case WITHDRAWER:
                                  {
                                      locker_.lock();
                                      std::cout<<"--> current amount: "<<pAccount_->getBalance()<<std::endl;
                                      std::cout<<"--> after withdraw "<<pAccount_->getBalance()<<std::endl;
                                      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                                      pAccount_->withdraw(200);
                                      locker_.unlock();
                                  }
                                  break;
            }
        }
      };
};

std::mutex Thread::locker_;

int main(){
  
    Account account(1000);
        
    Thread depositor(&account,ThreadType::DEPOSITOR);
    Thread withdrawel(&account,ThreadType::WITHDRAWER);
    
    depositor.start();
    withdrawel.start();
        
    depositor.end();
    withdrawel.end();
};
