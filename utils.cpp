/**
   @file utils.cpp
   @author Ajay(pranav.ajay2000@gmail.com)
   @brief Utils class for the whole project!
   @date May 2026   
**/
#include"utils.h"

std::optional<std::string> parseCardInfo(const std::string& cardPath){
    // readthrough the uevent file as a vector of string
    std::cout<< cardPath << "\n";
    std::ifstream ueventFile(cardPath + "/device/uevent");
    if(!ueventFile.is_open()){
        std::cerr << "Failed to open uevent file of path: " << cardPath << "\n";
        return std::nullopt;
    }
    std::string fileContents;
    std::string device;
    while(getline(ueventFile, fileContents)){
        if(fileContents.find("DRIVER")!= std::string::npos){
            device = fileContents.substr(fileContents.find("=")+1);
            break;
        }
    }
    if(device.empty()){
        std::cerr <<"Missing contents in the uevent file of path: " << cardPath << "\n";
        return std::nullopt;
    }
    return device;
}