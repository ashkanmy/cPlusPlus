#include <memory>
#include <iostream>
#include <string>
using std::unique_ptr;
using std::make_unique;
using std::cout;
using std::endl;
using std::string;
using std::move;

class Human{
    public:
    Human(string name):name_(name){}
    void PrintAddresses(){
        cout << " --> Objekt (on heap) --> " << this << " --> member  (on heap) --> " << name_ << endl;  
    }
    private:
       string name_;
};

void PassOwnerShip(unique_ptr<Human> up_human)
{
    //up_human->PrintAddresses();
    up_human->PrintAddresses();
}

int main()
{ 
    //unique_ptr<Human> ash(new Human("Ash"));
    unique_ptr<Human> ash = make_unique<Human>("Ash"); 
    cout << "unique_ptr address (on stack) ---> " << &ash;
    PassOwnerShip(move(ash));
}
