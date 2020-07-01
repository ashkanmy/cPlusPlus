/* Captured x by lambda can be changed since the lambda is defined to be mutable. */

#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> v;
    v.push_back(1);
    
    int x = 100;
    
    for_each(v.begin(),v.end(),[x](int e) mutable {
                                              std::cout<<"e . 100 -> "<<e*x<<std::endl;
                                              x*=2;
                                              std::cout<<"e . 200 -> "<<e*x<<std::endl;
                                                  });
    return 0;
}
