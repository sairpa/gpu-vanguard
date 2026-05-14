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
        // Parse logic for the string to gpuData conversion
        std::cout << "Results: " << result.value() << "\n";
        int index{0}, count{0}, val{0};
        std::string res = result.value() + ",";
        for(int i =0; i< res.size(); i++){
            if(res[i] == ','){ 
                try{
                    if(res[index] == ' '){
                        val = std::stoi((res.substr(index+1,i-index)));
                    }else{
                        val = std::stoi((res.substr(index,i-index)));
                    }
                    
                    switch(count){
                        case 0:
                            gpuData.temperature = val;
                            break;
                        case 1:
                            gpuData.fanSpeed = val;
                            break;
                        case 2:
                            gpuData.coreClock = val;
                            break;
                        case 3:
                            gpuData.memoryClock = val;
                            break;
                        case 4:
                            gpuData.gpuUtilization = val;
                            break;
                        case 5:
                            gpuData.vram = val;
                    };
                    index = i+1;
                    count++;
                }catch(const std::invalid_argument e){
                    std::cerr << "Got an invalid argument so skipping read and using default 0 val for count: " << count++ << "\n";
                    index = i+1;
                }                
            }
        }
        return gpuData;
    }
    else{
        std::cerr << "Couldn't fetch data for the nvidia card :/\n";
        return std::nullopt; //stub for now :D
    }
}