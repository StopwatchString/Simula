#ifndef SIMULA_CORE_COMPONENT_H
#define SIMULA_CORE_COMPONENT_H

#include "meta/ClassData.h"

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

public:
    static constexpr ClassData classData() {
        return { "Component" };
    }
};
} // end core
} // end simula

#endif