 #include <iostream>
 
 using std::cout;
 using std::endl;
 
 void UseMe(int&& My_rVal){
     cout << "Here is my integer-> "<< My_rVal << endl;
 };
 
 int main(){
     UseMe(12+12+12+12+12+12+12+12+12+12+12+1+12+12+12+12+12+12+12+12);
     return 0;
 }
