#include "meta/SimulaApplication.h"

#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>


//--------------------------------------------------
// Constructor
//--------------------------------------------------
SimulaApplication::SimulaApplication(const std::string& inputFile)
{
    std::filesystem::path file = std::filesystem::current_path() / inputFile;
    parseScenario(file);
}

//--------------------------------------------------
// Destructor
//--------------------------------------------------
SimulaApplication::~SimulaApplication()
{

}

//--------------------------------------------------
// parseScenario()
//--------------------------------------------------
void SimulaApplication::parseScenario(const std::filesystem::path& file)
{
    nlohmann::json scenario;
    try {
        std::ifstream f(file);
        scenario = nlohmann::json::parse(f);
    }
    catch (nlohmann::json::parse_error& e) {
        throw std::runtime_error("ERROR SimulaApplication::parseScenario() Failed to parse scenario file: " + file.string());
    }

    // Get meta information
    try {
        auto metaInfo = scenario["Simula"]["meta-info"];
        m_MetaInfo.version = metaInfo["version"];
    }
    catch (std::exception& e) {
        throw std::runtime_error("ERROR SimulaApplication::parseScenario() Failed to parse meta-info fields from " + file.string());
    }
    
    // Build component tree
    try {
        auto simulaTree = scenario["Simula"]["Tree"];
    }
    catch (std::exception& e) {
        throw std::runtime_error("ERROR SimulaApplication::parseScenario() Failed to parse component tree from " + file.string());
    }
}