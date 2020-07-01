/* Lambda to print vector elements */

#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> v;
    
    v.push_back(1);
    v.push_back(2);
    
    for_each(v.begin(),v.end(),[](int v_element){ std::cout<<"v-> "<<v_element<<std::endl; } );
    
    return 0;
}
