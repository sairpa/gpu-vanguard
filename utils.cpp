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

std::optional<std::string> runCommand(const char* command) {
    auto pipe = std::unique_ptr<FILE, decltype(&pclose)>(popen(command, "r"), pclose);

    if (!pipe) {
        std::cerr << "Unable to create a pipe for the command execution :/\n";
        return std::nullopt;
    }
    std::vector<char> buffer(128);
    std::string result;
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    if (result.empty()) {
        std::cerr << "Didn't get any result from the command :/\n";
        return std::nullopt;
    }
    return result;
}