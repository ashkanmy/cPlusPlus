/*Here, we use an async rather than a thread. In addition, the future concept 
  is used so that the working thread can respond to the main thread. Meanwhile, 
  position of future.get() makes a difference in direction of getting the name_ 
  attribute of the Human class to be updated or not based on either (i) or (ii)
  being activated. */

#include <thread>
#include <string>
#include <iostream>
#include <future>

class Human{
    public:
       Human(std::string name):name_(name){}
       void setName(std::string name){
           name_=name;
       }
       std::string getName(){return name_;}
    private:
       std::string name_;
};

int main(){
    Human Ashkan("Ash");
    std::future<void> f = std::async(    /*lambda starts*/  [&Ashkan](){Ashkan.setName("Asho");}  /*lambda ends*/  );
    
    
    std::cout<<Ashkan.getName()<<std::endl;    /*(i)*/
    f.wait();
    //std::cout<<Ashkan.getName()<<std::endl;  /*(ii)*/    
    
    
    return 0;
    /* (ii) if activated and (i) is deactivated we see the name change,
       but if (ii) is deactivated and (i) is activated we do not see the 
       name change */
}
