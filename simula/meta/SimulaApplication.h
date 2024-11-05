#ifndef SIMULA_META_SIMULA_APPLICATION_H
#define SIMULA_META_SIMULA_APPLICATION_H

#include "core/Component.h"

#include <string>
#include <filesystem>

//-----------------------------------------------------------------------------
// class SimulaApplication
// 
// description: RAII wrapper class for running a Simula application from a
//              Simula configuration file. No moving or copying. Throws with
//              error description if an error is encountered.
// 
//              Holds the instance of SimulaTree, and destroys it in destructor.
// 
//-----------------------------------------------------------------------------
class SimulaApplication {
    struct MetaInfo {
        std::string version;
    };

public:
    SimulaApplication(const std::string& inputFile);
    ~SimulaApplication();

    SimulaApplication(const SimulaApplication& other) = delete;
    SimulaApplication(SimulaApplication&& other) noexcept = delete;

    SimulaApplication& operator=(const SimulaApplication& other) = delete;
    SimulaApplication& operator=(SimulaApplication&& other) noexcept = delete;

private:
    void parseScenario(const std::filesystem::path& file);

    MetaInfo                m_MetaInfo;
    simula::core::Component m_ComponentTree;
};

#endif