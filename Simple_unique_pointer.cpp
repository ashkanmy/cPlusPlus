#include <memory>
#include <iostream>

using std::unique_ptr;
using std::cout;
using std::endl; 


void Raw_on_heap(int p){
   int* raw = new int(p);
   //--
   cout << "Value on heap --> " << *raw << endl;
   cout << "Address of raw pointer on heap --> " << raw << endl;
   (*raw)++;
   cout << "New value on heap --> " << *raw << endl;
   //--
   cout << "Deleting the raw pointer --> " << raw << " <-- from heap" << endl;
   delete raw;
}


void Unique_on_stack(int p){
    unique_ptr<int> up(new int(p));
    cout << "Unique pointer value --> " << *up << " <-- on stack\n";
    cout << "New unique pointer value --> " << ++(*up) << endl;
    // No deletion necessary for unique_ptr
}


int main(){
    
    // Handle a raw pointer on heap
    Raw_on_heap(10);
    cout << "--------------\n";
    // Handle a unique pointer on stack
    Unique_on_stack(29);
    return 0;
}
