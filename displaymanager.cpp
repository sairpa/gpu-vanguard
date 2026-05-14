/**
   @file displaymanager.cpp
   @author Ajay(pranav.ajay2000@gmail.com)
   @brief The TUI base class which is to be used for rendering the polled dynamic data
   @date May 2026   
**/

#include "displaymanager.h"
#include<string>
#include<ftxui/dom/elements.hpp>
#include<ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

using namespace ftxui;

void CDisplayManager::renderDashboard(const std::string& gpuName, const SGpuData& gpuData){

    auto screen = ScreenInteractive::TerminalOutput();
    auto renderer = Renderer([&] {
        return window(
            text(" Project GPU Vanguard ") | bold | center, // The title of the border
            vbox({
                text("Hardware: " + gpuName) | color(Color::Cyan),
                separator(),
                text("Core Clock : " + std::to_string(gpuData.coreClock) + " MHz"),
                text("Temperature: " + std::to_string(gpuData.temperature) + " C"),
                text("VRAM Used  : " + std::to_string(gpuData.vram) + " MB"),
                text("Fan Speed  : " + std::to_string(gpuData.fanSpeed) + " %"),
                filler(), // Pushes the quit text to the bottom
                text("Press 'q' to quit.") | dim | center
            })
        ) | flex; // Flex makes the window fill the available terminal space
    });
    auto component = CatchEvent(renderer, [&](Event event) {
        if (event == Event::Character('q') || event == Event::Escape) {
            screen.Exit();
            return true;
        }
        return false;
    });
    screen.Loop(component);
}