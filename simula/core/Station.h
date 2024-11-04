#ifndef SIMULA_CORE_STATION_H
#define SIMULA_CORE_STATION_H

#include "meta/ClassRegistry.h"
#include "core/Component.h"

namespace simula {
namespace core {

class Station : public Component {
public:
    Station();
    ~Station();

public:
    static constexpr ClassData classData() {
        return { "Station" };
    }
};

} // end core
} // end simula
#endif