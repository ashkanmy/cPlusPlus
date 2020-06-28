


/*Note: The code still does not get compiled successfully. 
I obtain : 

------------------------------
Error(s):

2015426847/source.cpp: In member function ‘void Thread::start()’:
2015426847/source.cpp:79:34: error: ISO C++ forbids taking the address of an unqualified or parenthesized non-static member function to form a pointer to member function.  Say ‘&Thread::run’ [-fpermissive]
             _pThread=new Thread(&run,this);
                                  ^~~
2015426847/source.cpp:79:42: error: no matching function for call to ‘Thread::Thread(void (Thread::*)(), Thread*)’
             _pThread=new Thread(&run,this);
                                          ^
2015426847/source.cpp:77:9: note: candidate: Thread::Thread(ThreadType)
         Thread(ThreadType typeOfThread):_threadType(typeOfThread){}
         ^~~~~~
2015426847/source.cpp:77:9: note:   candidate expects 1 argument, 2 provided
2015426847/source.cpp:12:7: note: candidate: constexpr Thread::Thread(const Thread&)
 class Thread{
       ^~~~~~
2015426847/source.cpp:12:7: note:   candidate expects 1 argument, 2 provided
-------------------------------
*/




#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

enum ThreadType{
    PRODUCER,
    CONSUMER
};

class Thread{
    private:
    
        static std::mutex _locker;
        static std::queue<int> _appQueue;
        
        /*--->conditional_variable related<---*/
        static bool _ready;
        static std::condition_variable untilReady; 
        /*--->conditional_variable related<---*/
        
        /*---> Thread related<---*/
        std::thread *_pThread;
        ThreadType _threadType;
        /*--->Thread related<---*/
    
     void run(){
        while(1){
            switch(_threadType){
                case PRODUCER:{
                    
                    /*  lock push ready unlock notify  */
                    std::unique_lock<std::mutex> uniqueLock( _locker );
                    std::cout<<"PRODUCER obtained the mutex"<<std::endl;
                    
                    /*-> PUSH! <-*/
                    std::cout<<"PUSH!"<<std::endl;
                    
                    /*-----------------------------------*/
                    /*condition_variable*/ _ready = true;//
                    /*-----------------------------------*/
                    
                    uniqueLock.unlock();
                    std::cout<<"PRODUCER released mutex"<<std::endl;
                    
                    /*--------------------------------------------------------------------------------*/
                    /*condition_variable*/ untilReady.notify_one();/*-> notify other waiting thread <-*/
                    std::cout<<"PRODUCER notifies the CONSUMER"<<std::endl;/*-------------------------*/
                    /*-----------------------------------------------------*/
                    
                }break;
                
                case CONSUMER:{
                    
                    /*  lock wait pop ready  */
                    std::unique_lock<std::mutex> uniqueLock( _locker );
                    std::cout<<"CONSUMER obtained the mutex"<<std::endl;
                    
                    /*-------------------------------------------------*/
                    untilReady.wait( uniqueLock,[](){ return _ready; });/*-------------------*/
                    std::cout<<"CONSUMER recieved the ready signal from PRODUCER"<<std::endl;//
                    /*-----------------------------------------------------------------------*/
                    
                    /*-> POP! <-*/
                    std::cout<<"POP! ..."<<std::endl;
                    
                    /*-----------------------------------*/
                    /*condition_variable*/_ready = false;//
                    /*-----------------------------------*/
                    
                }break;
            }
        }
    }
    public:
        Thread(ThreadType typeOfThread):_threadType(typeOfThread){}
        void start(){ 
            _pThread=new Thread(Thread::run,this);
        }
        void join(){
            _pThread->join();
        }
        ~Thread(){
            delete _pThread;
        }    
};

std::mutex Thread::_locker;
bool Thread::_ready;
std::queue<int> Thread::_appQueue;

int main(){
    Thread producer(ThreadType::PRODUCER);
    Thread consumer(ThreadType::CONSUMER);
    
    producer.start();
    consumer.start();
    
    producer.join();
    consumer.join();
    
    return 0;
}
