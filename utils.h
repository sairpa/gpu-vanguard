/**
   @file utils.h
   @author Ajay(pranav.ajay2000@gmail.com)
   @brief Utils class for the whole project!
   @date May 2026   
**/

#pragma once
#include<iostream>
#include<optional>
#include<vector>
#include<string>
#include<fstream>
#include<memory>

std::optional<std::string> parseCardInfo(const std::string& cardpath);
std::optional<std::string> runCommand(const char* command);