#ifndef SIMULA_CORE_COMPONENT_H
#define SIMULA_CORE_COMPONENT_H

#include "core/Object.h"

namespace simula {
namespace core {
class Component : public Object
{
public:
    Component();
    ~Component();

    Component(const Component& other);
    Component(Component&& other) noexcept;

    virtual Component& operator=(const Component& other);
    virtual Component& operator=(Component&& other) noexcept;

    virtual std::string getObjectName() = 0;
};
} // end core
} // end simula

#endif