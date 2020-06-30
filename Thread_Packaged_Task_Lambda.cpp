#include <iostream>
#include <future>

int main(){
    
    std::packaged_task<int(int,int)> task([](int alpha,int beta){
                                                                    return (alpha+beta); 
                                                                }
                                         );
    std::future<int> f=task.get_future();
    std::thread myThread(std::move(task),3,4);
    myThread.join();
    std::cout<<"->"<<f.get()<<std::endl;
    
    return 0;
}
