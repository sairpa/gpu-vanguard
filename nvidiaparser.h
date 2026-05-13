/**
   @file nvidiaparser.h
   @author Ajay(pranav.ajay2000@gmail.com)
   @brief The header file for nVidia parser which takes responsibility of going processes any and all nVidia GPUs :D
   @date May 2026   
**/

#pragma once
#include "baseparser.h"

class CNvidiaParser: public IBaseParser{
    public:
        explicit CNvidiaParser() = default;
        ~CNvidiaParser() = default;
        std::optional<SGpuData> parseData() override;
};