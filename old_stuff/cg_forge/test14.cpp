#include<bits/stdc++.h>
using namespace std;

// C++ 14 standards galore :D

// unique pointer and make_unique constructs
// class myClass{
//     public:
//      myClass(){
//         cout << "Constructor!!! \n";
//      }

//      ~myClass(){
//         cout << "Destructor :/\n";
//      }
// };

// shared_mutex sharedmutex;
// int val = 0;

// void putv( int v )
// {
//   sharedmutex.lock();
// 	  std::this_thread::sleep_for(std::chrono::microseconds(2));  //some latency simulation
// 		val = v;
//   sharedmutex.unlock();
// }
 
// void getv( int &v )
// {
//   sharedmutex.lock_shared();
// 	  std::this_thread::sleep_for(std::chrono::microseconds(2));  // some latency simulation
// 	  v = val;
//   sharedmutex.unlock_shared();
// }
 

int main(int argc, char** argv){
    // Hello c14 :D
    
    // auto lam = [] (auto x){
    //     return x*x;
    // };
    // cout << lam(5) << "\t" << lam(4.9) << endl;

    // Introduction of digit separators
    // long int k = 1'000'123'456789;
    // cout << k << endl;

    // smart pointers:
    // unique_ptr<myClass> ptr = make_unique<myClass>();
    // // ptr.reset();
    // cout << "some ops here\n";

    // instead of copying, we now have a exchange method which in atomic update,
    // moves l and r and also returns the old value to the left side
    // int x{13},y;
    // y = exchange(x,15);
    // cout << x << "\t" << y << endl;   

    // int readval;
    // std::thread t1( getv , std::ref( readval ) );
    // std::thread t2( putv , 100);
    
    // t1.join();
    // t2.join();
    
    // std::cout << readval << std::endl;
    // std::cout << val << std::endl;

    
    return 0;
}