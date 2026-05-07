/**
   @file intelparser.h
   @author Ajay(pranav.ajay2000@gmail.com)
   @brief The header file for intel parser which takes responsibility of going processes any and all Intel GPUs :D
   @date May 2026   
**/

#pragma once
#include "baseparser.h"

class CIntelParser: public IBaseParser{
    std::string m_sysFsPath; // Default path to the intel gpu
    public:
        explicit CIntelParser(std::string sysFsPath);
        ~CIntelParser() = default;
        std::optional<SGpuData> parseData() override;
};
