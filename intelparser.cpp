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
    SGpuData gpuData{0};
    std::string line{""};
    if(std::ifstream curFreqFile(m_sysFsPath + "/gt_cur_freq_mhz"); curFreqFile.is_open()){ // File exists and is open!
        while(getline(curFreqFile, line)){
            if(line.empty()){
                std::cerr << "Doesn't contain current frequncy of the gpu, skipping \n";
                break;
            }else{
                gpuData.coreClock = std::stoi(line);
            }
        }
        return gpuData;
    }else{
        std::cerr << "Unable to read the gt_cur_freq_mhz file :/ \n";
        return std::nullopt;
    }
}