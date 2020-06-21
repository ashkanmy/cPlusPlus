//Here we adjusted the promise/future already 
//written code so that it uses a async/future
//mechanisem that is much shorter!

#include <future>
#include <iostream>

int show(int mn){
//void show(std::promise<int>&& p,int mn){
    mn++;
    return mn; //p.set_value(mn);
}

int main(){    
    int myNumber=10;
    int myNumberUpdated;
    //std::promise<int> p;
    std::future<int> f=std::async(show,myNumber);   //std::future<int> f=p.get_future();
    //std::thread t(show,std::move(p),myNumber);
    myNumberUpdated=f.get();
    std::cout<<"update->"<<myNumberUpdated<<std::endl;
    //t.join();
    return 0;
}
 
