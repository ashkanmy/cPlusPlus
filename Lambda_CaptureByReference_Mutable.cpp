#include <iostream>

int main(){
    
    /* define the lambda*/
    int value = 0;
    auto temp = [&value]()mutable{value++;};
    temp();
    std::cout<<value<<std::endl; 
    return 0;
}
