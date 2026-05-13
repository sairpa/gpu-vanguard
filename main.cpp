/**
   @file main.cpp
   @author Ajay(pranav.ajay2000@gmail.com)
   @brief The main class which takes responsibility of going through the system, note the gpus present, and orchestrate the whole flow!
   @date May 2026   
**/

#include<filesystem>
#include"intelparser.h"
#include"utils.h"

constexpr std::string defaultSysFsPath = "/sys/class/drm/";

int main(int argc, char** argv){
    std::cout << "Start of GPU Vanguard!\n";

    // Doing a parse of all the cards in the pc...
    auto recurse_dir_iter = std::filesystem::directory_iterator(defaultSysFsPath);
    for (const std::filesystem::directory_entry& entry: recurse_dir_iter){
        std::cout<< entry.path() << "\n";
        if(entry.path().string().find("card") != std::string::npos){
            std::cout << "\nFound a possible card!\n";
            std::optional<std::string> cardInfo = parseCardInfo(entry.path().string());
            if(!cardInfo.has_value()){
                std::cerr << "Possible peripherals like the DP or HDMI ports are being detected as cards, skipping them...\n";
                continue;
            }else{
                
                if(std::string device = cardInfo.value();device == "intel_gpu" || device == "i915" || device == "xe"){
                    std::cout << "Found an Intel GPU! \n";
                    
                    CIntelParser intelParser(entry.path().string());
                    if(std::optional<SGpuData> gpuData = intelParser.parseData();gpuData.has_value()){
                        std::cout << "GPU Data for the intel card at path: " << entry.path() << "\n";
                        std::cout << "Core clock: " << gpuData->coreClock << "Mhz\n";
                    }
                    else{
                        std::cerr << "Something wrong in parsing the gpu data for the intel gpu :/\n";
                    }
                }// else for amd and nvidia
                else if(device == "nvidia"){
                    std::cout << "Found an nVidia GPU!\n";
                    
                }
            }
        }
    }

    return 0;
}