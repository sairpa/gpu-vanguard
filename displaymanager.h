/**
   @file displaymanager.h
   @author Ajay(pranav.ajay2000@gmail.com)
   @brief The TUI base class which is to be used for rendering the polled dynamic data
   @date May 2026   
**/


#pragma once
#include"baseparser.h"

class CDisplayManager{
    public:
        CDisplayManager() = default;
        ~CDisplayManager() = default;

        void renderDashboard(const std::string& gpuName, const SGpuData& gpuData);
};