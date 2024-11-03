#include "core/SimulaApplication.h"

#include <iostream>

const std::string SCENARIO_FILE = "SimulaScenario.json";

int main()
{
    try {
        SimulaApplication app(SCENARIO_FILE);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}