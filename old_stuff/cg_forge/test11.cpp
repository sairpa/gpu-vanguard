#include<bits/stdc++.h>
using namespace std;

// My test code snippet collection to learn c11 standards
// g++ -std=c++11 /home/tintu/dev/gfx_garden/cpp/c++11/test.cpp -o test; ./test


// constexpr float inlinestuff(int x){
//         return x*M_PI;
//     };

// float inlinestuff(int x){
//     return x*M_PI;
// };

// int fun1(int p){
//     if(p <0){
//         return p+1000;
//     }else{
//         return p%100;
//     }
//    }

//    int f(int i)[[expects:i > 0]]
//         return i%100;
//    }

// int fun1(float x){
//     return x*M_1_PI;
// }

int main(){

    // Code for range based iterator
    // {
    //     vector<int> list = {1,2,3,4};

    //     for(int i:list){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }


    //  lambda expressions
    // {
    //     auto res = [](int x){
    //         return x*x;
    //     };

    //     cout << res(5) << endl;
    //     cout << res(0) << endl;
    // }

    // Smart pointers
    // {
        // we have an auto_ptr but is depreciated in c17 so not needed but essentially 
        // it is a smart auto allocate and deallocate pointer architecture but is phased out due to better impls
        // instead now we have unique, shared and weak pointers- unique_ptr shared_ptr weak_ptr
        // unique_ptr<int> k(new int(13));
        // cout << *k << endl;

        // unique_ptr<int> p;
        // p = move(k);
        // cout << (k == nullptr) << " ," << *p << endl;


    //     shared_ptr<int> l,l0(new int(13));
    //     l = l0;
    //     cout << *l << *l0 << l0.use_count() << endl;

    //     weak_ptr<int> l1(l0);
    //     cout << *l0 << l1.use_count() << l0.use_count() << endl;

    // }

    // Move semantics :D
    // helps move/transfer ownership of objects instead of redundantly copying
    // copy( creates duplicate, holds the orignal object, slower and intensive per usage)
    // move (transfers ownership, deletes the orignal object, faster io)
    {
        // string k,s(" Hello!");
        // k = move(s);
        // cout << k << s << endl;
        // Expression semantics
        // lvalue, rvalue T& and T&&
        // lvalue -> actual solid reference to value and the physical memory address/location 
        // updates 
        // int x = 13;
        // int& ref = x;
        // ref = 20;
        // cout << x << "\t" << ref << endl;
        // rvalue -> binds to temporary references/objects/values
        // int x = 10;
        // int&& y1 = 13;
        // cout << x << "\t" << y1 << endl;
    }

    // constexpr
    // compile time evaluation and helps runtime performance
    // 
    // constexpr int k(10);
    // cout << inlinestuff(k) << endl;
    // int k(10);
    // cout << inlinestuff(k) << endl;

    // NULL POINTER
    // before it was a compiler dependent constant defintion
    // now we have a universal defenition
    // nullptr points to the earlier NULL keyword
    // assigning 0 to pointers also does the same
    // dereferencing null pointers still ambigious
    // check for null a must
    // int* emptr = NULL;
    // int* emptr1 = nullptr;
    // int* emptr2 = 0;

    // cout << (emptr1 == emptr) << "\t"<< (emptr2 == emptr) << endl;

    // Auto keyword
    // decltype keyword // helps extract the datatype of the infered var/ function
    // auto x = 14;
    // auto y = &x;

    // cout << typeid(x).name() << "\t" << typeid(y).name() << endl;

    // auto k =13.5;
    // decltype(fun1(k)) z;

    // cout << typeid(z).name() << endl;

    // Uniform initialiation
    // int i(10);
    // int p{13};
    // int k[]{1,2,3,4};

    // cout << i << "\t" << p << "\t" << k[3] << endl;
    // int* p= new int[9]{1,2,3,4,5,6,7,8,9};
    // for(int i=0; i<9; i++){
    //     cout << *(p+i) << "\t";
    // }
    
    /*
        Attributes
        Mordern comments to give devs some work to compiler
        for optimising things a bit more stringently


        Untill c17, there were lot of informal non-standard attributes
        so we have some compiler dependent behaviour for most of the attributes
    */
   

   


    return 0;
}