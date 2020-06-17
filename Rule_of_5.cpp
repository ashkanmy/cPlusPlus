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
       MyPositiveInt(int i){ // --- Default constructor
           pi_=(int*)malloc(sizeof(int));
           *pi_=i;
           Validate();                 
       }
       ~MyPositiveInt(){ // --- Destructor
           if (this!=nullptr){
               cout << "free : stack : " << this << " <--> Heap : " << pi_ << endl; 
               free(pi_);                
           }
        }       
       
       MyPositiveInt& operator=(MyPositiveInt& pi){ // --- Copy assignment
           pi_ =(int*)malloc(sizeof(int));
           *pi_=*pi.pi_;
           Validate();
           pi.pi_=nullptr;              
           return *this;
       }
       
       MyPositiveInt(MyPositiveInt& pi){ // --- Copy constructor
           pi_=(int*)malloc(sizeof(int));
           *pi_=*pi.pi_;
           Validate();
           pi.pi_=nullptr;                 
       }
       
       MyPositiveInt(MyPositiveInt&& pi){ // --- Move constructor
          cout << "xxxxxxxxxxxxx" << endl;
          cout << pi.pi_ << " -- move constructor--> " << pi_ << endl;
          cout << "xxxxxxxxxxxxx" << endl;
          *pi_=*pi.pi_;
          Validate();                 
          pi.pi_=nullptr;
       }
       
       MyPositiveInt& operator=(MyPositiveInt&& pi){ // --- Move assignment
          cout << "xxxxxxxxxxxxx" << endl;
          cout << pi.pi_ << " -- move assignment --> " << pi_ << endl;
          cout << "xxxxxxxxxxxxx" << endl;
          if (pi_==pi.pi_) return *this; // self copy!
          *pi_=*pi.pi_ ;               
          pi.pi_=nullptr;
          return *this;
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
        /*
        // --- Copy assignment
        MyPositiveInt pi_0(100);
        MyPositiveInt pi_1(200);
        pi_0.Addresses();
        pi_1.Addresses();
        cout << "<---- Copy assignment ---->" << endl;
        pi_1 = pi_0;
        pi_0.Addresses();
        pi_1.Addresses();
        */
        
        /*
        // --- Copy constructor
        MyPositiveInt pi_2(12);
        MyPositiveInt pi_3(pi_2); 
        cout << "<---- Copy constructor ---->" << endl;
        pi_2.Addresses();
        pi_3.Addresses();
        */
        
        
        // --- Move constructor
        MyPositiveInt pi_5(100);
        pi_5.Addresses();
        //cout << "<---- Move constructor ---->" << endl;
        MyPositiveInt pi_6 = MyPositiveInt(pi_5);
        pi_5.Addresses();
        pi_6.Addresses();
        
        
        /*
        // Move assignment
        MyPositiveInt pi_7(7);
        pi_7.Addresses();
        MyPositiveInt pi_8(8);
        pi_8.Addresses();
        cout << "<---- Move assignment ---->" << endl;
        pi_7 = MyPositiveInt(pi_8);
        pi_7.Addresses();
        pi_8.Addresses();
        */
        
       }
       catch(invalid_argument& e)
       {
           cout << e.what() << endl;
       }
}
