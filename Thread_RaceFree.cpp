/* Here we care about the position of join(), since 
   we need to use our thread with no data race issue */

#include <thread>
#include <string>
#include <iostream>
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
    std::thread t_change_name(    /*lambda starts*/  [&Ashkan](){Ashkan.setName("Asho");}  /*lambda ends*/  );
    
    
    //std::cout<<Ashkan.getName()<<std::endl;    (i)
    t_change_name.join();
    //std::cout<<Ashkan.getName()<<std::endl;   (ii)    
    
    
    return 0;
    /* (ii) if activated and (i) is deactivated we see the name change,
       but if (ii) is deactivated and (i) is activated we do not see the 
       name change */
}
