#include <memory>
#include <iostream>

using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;

class Human{
    public:
     Human(int age):age_(age){} 
    private:
     int age_;
};

void PassAge(shared_ptr<Human> human_par)
{
    cout << "shared_ptr add. (called from function) --> " << &human_par << ", ref_no (" << human_par.use_count() << ")" << endl;
    cout << " - - - " << endl;
}

int main(){
    shared_ptr<Human> human = make_shared<Human>(23);
    
    cout << "shared_ptr add. (called from main)  --> " << &human << ", ref_no (" << human.use_count() << ")" << endl;
    cout << " - - - " << endl;    
    PassAge(human);
    cout << "shared_ptr add.  (called from main) --> " << &human << ", ref_no (" << human.use_count() << ")" << endl;
    cout << " - - - " << endl;
}
