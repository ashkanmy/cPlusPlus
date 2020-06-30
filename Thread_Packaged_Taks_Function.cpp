#include <iostream>
#include <future>

int PowFunc(int digit){
    return digit*digit;
}

int main(){
    int digit=4;
    std::packaged_task<int(int)> myTaks(PowFunc);
    std::future<int> f=myTaks.get_future();
    myTaks(digit);
    std::cout<<"-->"<<f.get()<<std::endl;
    return 0;
}
