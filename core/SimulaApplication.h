#ifndef SIMULA_CORE_SIMULA_APPLICATION_H
#define SIMULA_CORE_SIMULA_APPLICATION_H

#include <string>

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
public:
    SimulaApplication(const std::string& inputFile);
    ~SimulaApplication();

    SimulaApplication(const SimulaApplication& other) = delete;
    SimulaApplication(SimulaApplication&& other) noexcept = delete;

    SimulaApplication& operator=(const SimulaApplication& other) = delete;
    SimulaApplication& operator=(SimulaApplication&& other) noexcept = delete;

private:
    std::string inputFile;

};

#endif