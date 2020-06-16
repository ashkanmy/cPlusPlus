// The rule of 3 example
#include <iostream>
#include <string>
#include <stdexcept>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::invalid_argument;

class MyPositiveInt
{
    private:
       int* pi_;
       void Validate(){
           if (*pi_<=0)
           {
               throw invalid_argument("Negative integer!");
           }
       }
    public:
       MyPositiveInt(int i){
           pi_=(int*)malloc(sizeof(int));
           *pi_=i;
           Validate();
       }
       ~MyPositiveInt(){
           cout << "free : " << pi_ << endl; 
           free(pi_);
        }       
       
       MyPositiveInt& operator=(MyPositiveInt& pi){
           pi_ =(int*)malloc(sizeof(int));
           *pi_=*pi.pi_;
           Validate();
           pi.pi_=nullptr;
           return *this;
       }
       
       
       MyPositiveInt(MyPositiveInt& pi){
           pi_=(int*)malloc(sizeof(int));
           *pi_      = *pi.pi_;
           Validate();
           pi.pi_=nullptr;
       }
       
       void Addresses(){
           cout << "Stack-add= " << this << endl;
           cout << "Heap-add= " << pi_ << endl;
           if (pi_!=nullptr) {cout << "Heap-val= " << *pi_ << endl;}
           else {cout << "Heap cleared\n";}
           cout << "---" << endl;
       }
};


int main()
{
    try{
        
        MyPositiveInt pi_0(100);
        MyPositiveInt pi_1(200);
        pi_1 = pi_0;
        pi_0.Addresses();
        pi_1.Addresses();
        
        /*
        MyPositiveInt pi_2(-2);
        MyPositiveInt pi_3(pi_2); 
        pi_2.Addresses();
        pi_3.Addresses();
        */
       }
       catch(invalid_argument& e)
       {
           cout << e.what() << endl;
       }
}
