/**
   @file nvidiaparser.h
   @author Ajay(pranav.ajay2000@gmail.com)
   @brief The header file for nVidia parser which takes responsibility of going processes any and all nVidia GPUs :D
   @date May 2026   
**/

#pragma once
#include "baseparser.h"
#include "utils.h"

constexpr const char* nvidiaSmiDefaultQuery = "nvidia-smi --query-gpu=temperature.gpu,fan.speed,clocks.current.graphics,clocks.current.memory,utilization.gpu,memory.used --format=csv,noheader,nounits";

class CNvidiaParser: public IBaseParser{
    public:
        explicit CNvidiaParser() = default;
        ~CNvidiaParser() = default;
        std::optional<SGpuData> parseData() override;
};