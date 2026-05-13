/**
   @file nvidiaparser.cpp
   @author Ajay(pranav.ajay2000@gmail.com)
   @brief The implementation file for nVidia parser which takes responsibility of going processes any and all nVidia GPUs :D
   @date May 2026   
**/

#include "nvidiaparser.h"

CNvidiaParser::CNvidiaParser(std::string sysFsPath): m_sysFsPath(std::move(sysFsPath)){

}

std::optional<SGpuData> CNvidiaParser::parseData(){
    return std::nullopt; //stub for now :D
}