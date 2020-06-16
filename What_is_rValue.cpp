 #include <iostream>
 
 using std::cout;
 using std::endl;
 
 void UseMe(int&& My_rVal){
     cout << "Here is my integer-> "<< My_rVal << endl;
 };
 
 // Here, 
 //   (i) I do not need to define many variable of type int and assign them all with 12! (This way is more efficient)
 //   (ii) The argument of UseMe is a r-value. Dissimilar to l-value referencing, any change done on My_rVal does not 
 //        impact its value out of the scope of the UseMe function. This could have happened if My_rVal was passed by 
 //        l-value reference and not with r-value reference.
 int main(){
     UseMe(12+12+12+12+12+12+12+12+12+12+12+1+12+12+12+12+12+12+12+12);
     return 0;
 }
