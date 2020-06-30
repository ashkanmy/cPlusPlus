#include <iostream>
#include <future>

int main(){
    
    std::packaged_task<int(int,int)> task([](int alpha,int beta){
                                                                    return (alpha+beta); 
                                                                }
                                         );
    std::future<int> f=task.get_future();
    task(3,4);
    std::cout<<"S->"<<f.get()<<std::endl;
    
    return 0;
}
