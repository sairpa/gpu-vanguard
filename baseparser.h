/**
   @file baseparser.h
   @author Ajay(pranav.ajay2000@gmail.com)
   @brief The header file for main base parser which takes responsibility of going through the process of running through the gpu vitals read.
   @date May 2026   
**/
#pragma once
#include<iostream>
#include<memory>
#include<string>
#include<optional>
#include<fstream>

// GPU Data Skeleton
struct SGpuData{
   int temperature;    // Celsius
   int fanSpeed;       // rpm / %
   int coreClock;      // Mhz
   int memoryClock;    // Mhz
   int gpuUtilization; // %
   int vram;           // MB
};

// Base Interface
class IBaseParser{
   public:
     virtual ~IBaseParser() = default;
     virtual std::optional<SGpuData> parseData() = 0;
};




