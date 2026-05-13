/**
   @file nvidiaparser.cpp
   @author Ajay(pranav.ajay2000@gmail.com)
   @brief The implementation file for nVidia parser which takes responsibility of going processes any and all nVidia GPUs :D
   @date May 2026   
**/

#include"nvidiaparser.h"

std::optional<SGpuData> CNvidiaParser::parseData(){

    SGpuData gpuData{0};
    std::string line{""};
    if(std::optional<std::string> result = runCommand(nvidiaSmiDefaultQuery); result.has_value()){
        std::cout << "yayy!\n";
        return gpuData;
    }
    else{
        std::cerr << "Couldn't fetch data for the nvidia card :/\n";
        return std::nullopt; //stub for now :D
    }
}