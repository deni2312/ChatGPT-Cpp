cmake_minimum_required(VERSION 3.8.0)
project(ChatGPTDll VERSION 0.1.0)
set(SOURCES src/ChatGPT.cpp src/Error.cpp)
find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
add_library(ChatGPTDll STATIC ${SOURCES})
target_link_libraries(ChatGPTDll PRIVATE nlohmann_json::nlohmann_json cpr::cpr)