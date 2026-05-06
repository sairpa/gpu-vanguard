#include<bits/stdc++.h>
using namespace std;

// C++ 17 Standards dive :D

// namespace Game::Graphics::UI{
//     void startup(){
//         // ops for gameui
//         cout << "Whatever!\n";
//     }
//     void display(){
//         cout << "GAME UI Init\n";
//         startup();
//     }
// }

// template<typename... Args>
// auto SumWithOne(Args... args){
//     return (10 + ... + args);
// }

// int   = 100;


    template<typename... args> auto addstuff(args... arg){
        return (1 - (... - arg));
    }


set<string> identifiers; // f,g,s

int main(int argc, char** argv){

    // Nested namespaces
    // Game::Graphics::UI::display();

    // Tuple unpacking with auto
    // tuple<int,string> s = make_tuple(1,"rpa");
    // auto [id,name]{s};
    // cout << id << "\t" << name << endl;

    // cout << SumWithOne(-10) << endl;

    // inline variables
    
    // cout << var << endl;


    // Any datatype
    // any p{13};
    // cout << p.has_value() << "\t" << p.type().name() << "\t" << any_cast<int>(p) << endl;

    // variant<int, string, double> v{"rpa"};
    // cout << get<string>(v) << endl;

    // string_view sv{"This is a string view in c++17"};
    // cout << sv << "\t" << sv.size() << endl;
    
    // identifiers involved: 
    
    // ifstream objFile("/home/tintu/dev/gfx_garden/trw/diablo3_pose.obj");
    // if(objFile.is_open()){
    //     cout << "File opened!\n";
    //     string line;
    //     while(getline(objFile, line)){
    //         // actualplace to read the obj file line by line
    //         string_view sv{line};
    //         // extract only 1 or 2 chars from the string_view based on whitespace
    //         string id;
    //         // if cout << sv.at(0) << endl;
    //         if(sv.at(1) == '#'){
    //             id = string{sv.substr(0,1)};
    //             identifiers.insert(string{id});
    //         }
    //     }
    //     objFile.close();
    // }
    // else{
    //     cout << "File didn't open :/\n";
    // }

    // cout << "Identifiers found in the obj file: \n";
    // for(const auto &id : identifiers){
    //     cout << id << "\n";
    // }

    // constexpression in if blocks
    // const int k = 13;

    // if constexpr (k % 2 == 1){
    //     cout << "Odd\n";
    // }
    // else{
    //     cout << "Even\n";
    // }

    // fold expressions on variadic templates
    auto k{4}, p{2}, s{3};

    cout << addstuff(k,p,s) << endl;


    return 0;
}