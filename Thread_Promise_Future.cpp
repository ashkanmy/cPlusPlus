// Consider (i), (ii), (iii) and (v)
// as major steps in implementing a 
// promise-future mechanisem!

#include <iostream>
#include <string>
#include <future>

// -->(ii)<-- : declare the function whose argument is a r-value reference
//        accepting a promise of string
void Show(std::promise<std::string> &&p,std::string message){
    
    std::string modifiedMessage = "New " + message;       // delay / modified message    
    
    // -->(iii)<-- : set the promise value with the modified message
    p.set_value(modifiedMessage);
}

int main(){
    // -->(i)<-- : introduce promise and future of strings
    std::promise<std::string> p;
    std::future<std::string> f = p.get_future();
    
    
    //            func       r-value           message
    std::thread t(Show,      std::move(p),     "my location");
    
    // --> (v) <-- : listen to the thread!
    std::string fromThread  =  f.get();
    
        
    std::cout<<fromThread<<std::endl;     
    t.join();  // thread barrier
    
    
    
    return 0;
}
