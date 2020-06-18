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
    Human(string name):name_(name){cout<<name_;}
    void PrintAddresses(){
        cout << " --> Objekt--> " << this << " --> member--> " << &name_ << endl;  
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
    PassOwnerShip(move(ash));
}
