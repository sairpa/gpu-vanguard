/**
   @file intelparser.cpp
   @author Ajay(pranav.ajay2000@gmail.com)
   @brief The implementation file for intel parser which takes responsibility of going processes any and all Intel GPUs :D
   @date May 2026   
**/

#include "intelparser.h"

CIntelParser::CIntelParser(std::string sysFsPath): m_sysFsPath(std::move(sysFsPath)) {

}

std::optional<SGpuData> CIntelParser::parseData(){
    // Parse through the Intel stuff
    
    return std::nullopt;
}