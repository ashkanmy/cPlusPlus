//Here we check if the worker thread, needs to be synch. or 
//asynch. with respect to the main-thread! We used the 
//std::launch<--deferred or std::launch<--async option of the asynch!


#include <future>
#include <iostream>

int show(int mn){
    std::cout<<"function-thread->"<<std::this_thread::get_id()<<std::endl;
    mn++;
    return mn; 
}

int main(){    
    int myNumber=10;
    int myNumberUpdated;
    // launch option
    //std::future<int> f=std::async(std::launch::async,show,myNumber); //asynchronous!
    //std::future<int> f=std::async(std::launch::deferred,show,myNumber); //synchronous! 
     
    myNumberUpdated=f.get();
    std::cout<<"main-thread"<<std::this_thread::get_id()<<std::endl;
    std::cout<<"update->"<<myNumberUpdated<<std::endl;
    return 0;
}
