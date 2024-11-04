#include "meta/SimulaApplication.h"

#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>

//--------------------------------------------------
// Constructor
//--------------------------------------------------
SimulaApplication::SimulaApplication(const std::string& inputFile)
    : inputFile(inputFile)
{
    std::filesystem::path filepath = std::filesystem::current_path() / inputFile;

    try {
        std::ifstream f(filepath);
        auto scenario = nlohmann::json::parse(f);
        auto metaInfo = scenario["Simula"]["meta-info"];
        auto simulaTree = scenario["Simula"]["SimulaTree"];

        std::string versionInfo = metaInfo["version"];

        std::cout << versionInfo << std::endl;

        double timestep = simulaTree["Station"]["timestep (s)"];
        std::cout << "Timestep (s): " << timestep << std::endl;

    }
    catch (std::exception e) {
        throw std::runtime_error("Failed to parse scenario file: " + inputFile);
    }
}

//--------------------------------------------------
// Destructor
//--------------------------------------------------
SimulaApplication::~SimulaApplication()
{

}