#include <iostream>
#include <thread>
#include <string>

void Show(std::string status){
    std::cout<<"status-->"<<status<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(129));
}

int main(){
    std::string status_1{"Ready"};
    std::string status_2{"Sleeply"};
    
    //thread-1
    std::thread t1(Show,status_1);
    std::this_thread::sleep_for(std::chrono::milliseconds(22));
    
    //thread-2
    std::thread t2([status_2](){
                                   std::cout << "status-->"<<status_2<<std::endl;
                                   std::this_thread::sleep_for(std::chrono::milliseconds(2));
                               }
                  );
    
    std::cout<<"main thread ends>"<<std::endl;
    
    t1.join();
    t2.join();
    return 0;
}
