#ifndef SIMULA_COMPONENT_REGISTRY_H
#define SIMULA_COMPONENT_REGISTRY_H

#include "meta/ClassData.h"

#include "core/Component.h"
#include "core/Station.h"

#include <array>
#include <string_view>

//--------------------------------------------------
// ClassRegistry
//--------------------------------------------------
template<size_t N>
class ClassRegistry {
public:
    constexpr ClassRegistry(std::array<ClassData, N> classDatas) : registeredClasses(classDatas) {}

    constexpr size_t size() const {
        return registeredClasses.size();
    }

    constexpr bool contains(std::string_view className) const {
        auto it = std::find_if(registeredClasses.begin(), registeredClasses.end(), [&](const ClassData& classData) {
            return classData.name == className;
            });

        return it != registeredClasses.end();
    }

private:
    std::array<ClassData, N> registeredClasses;
};

//--------------------------------------------------
// concept Registerable
//--------------------------------------------------
template <typename T>
concept Registerable = requires {
    { T::classData() } -> std::same_as<ClassData>;
};

//--------------------------------------------------
// makeRegistry()
//--------------------------------------------------
template <Registerable... T>
constexpr auto makeRegistry() {
    return ClassRegistry<sizeof ...(T)>{
        std::array<ClassData, sizeof ...(T)>{{
            T::classData()...
        }}
    };
}

constexpr auto classRegistry = makeRegistry<
    simula::core::Component,
    simula::core::Station
>();

#endif