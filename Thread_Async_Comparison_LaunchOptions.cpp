#include <iostream>
#include <future>
#include <thread>
#include <cmath>
#include <vector>
void DoIt(int i,int thr_no){
    std::cout<<"Thread id-> "<<std::this_thread::get_id()<<std::endl;
    for(int c=1;c<i;c++){sqrt(81);}
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout<<"Thread no-> "<<thr_no<<std::endl;
};
int main(){
   int loop=10;
   int Threads = 4;
    
   std::cout<<std::this_thread::get_id()<<std::endl;
   std::chrono::high_resolution_clock::time_point Tx = std::chrono::high_resolution_clock::now(); 
   std::vector<std::future<void>> futures;
   for(int nThread=0;nThread<Threads;nThread++)
   {
       //---->  std::launch::async	     ---->    a new thread is launched to execute the task asynchronously
       //---->  std::launch::deferred	 ---->    the task is executed on the already called (main) thread (lazy evaluation)
       
       futures.emplace_back(std::async(std::launch::async,DoIt,loop,nThread)); 
       //futures.emplace_back(std::async(std::launch::deferred,DoIt,loop,nThread));
       //futures.emplace_back(std::async(std::launch::any,DoIt,loop));
   }
   for(std::future<void> &f:futures)
    f.wait();
   std::chrono::high_resolution_clock::time_point Ty = std::chrono::high_resolution_clock::now();
   std::cout << "nLoops-> " <<loop <<" nThreads->" << Threads << " microseconds-> " << std::chrono::duration_cast<std::chrono::microseconds>( Ty - Tx ).count()<<std::endl;
   return 0;
}
