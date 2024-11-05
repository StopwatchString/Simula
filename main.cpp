#include "meta/SimulaApplication.h"
#include "meta/ClassRegistry.h"

#include "argh/argh.h"

#include <iostream>

std::string DEFAULT_SCENARIO_FILE = "SimulaScenario.json";

int main(int argc, char* argv[])
{
    std::string configFile;

    argh::parser cmdl(argc, argv);
    if (cmdl({"-i", "--input"}) >> configFile) {
        configFile = cmdl({"-i", "--input"}).str();
    }
    else {
        std::cout << "No input file given, choosing default scenario file: " << DEFAULT_SCENARIO_FILE << std::endl;
        configFile = DEFAULT_SCENARIO_FILE;
    }

    try {
        SimulaApplication app(configFile);
    }
    catch (std::exception& e) {
        std::cerr << "ERROR main() SimulaApplication has thrown an unhandled exception. More information below:" << std::endl;
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}