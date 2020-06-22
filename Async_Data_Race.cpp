/*Here, our working thread could not update the name_ of Human. The reason is
  the name_ attribute is defined as a pointer and when the Human is passed into 
  the lambda function the same addressed pointed */

#include <thread>
#include <string>
#include <iostream>
#include <future>

class Human{
    public:
       void setName(std::string name){
           name_=&name;
       }
       std::string getName(){return *name_;}
    private:
       std::string* name_=nullptr;
};

int main(){
    Human Ashkan;
    Ashkan.setName("Ash");
    std::future<void> f = std::async(    /*lambda starts*/  [](Human human_par){std::this_thread::sleep_for(std::chrono::milliseconds(500));human_par.setName("Asho");}  /*lambda ends*/,Ashkan);
    f.wait();
    std::cout<<Ashkan.getName()<<std::endl;       
    return 0;
}
