#include "meta/SimulaApplication.h"
#include "meta/ClassRegistry.h"

#include <iostream>

const std::string SCENARIO_FILE = "SimulaScenario.json";

int main()
{
    if (classRegistry.contains("MyClassA")) {
        std::cout << "contains" << std::endl;
    }

    try {
        SimulaApplication app(SCENARIO_FILE);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}