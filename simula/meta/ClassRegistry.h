#ifndef SIMULA_COMPONENT_REGISTRY_H
#define SIMULA_COMPONENT_REGISTRY_H

#include <array>
#include <string_view>

//--------------------------------------------------
// ClassData
//--------------------------------------------------
struct ClassData {
    std::string_view name;
};

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

    constexpr bool build(std::string_view className) const {
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

struct MyClassA {
public:
    static constexpr ClassData classData() { return { "MyClassA" }; }
};

struct MyClassB {
    static constexpr ClassData classData() { return { "MyClassB" }; }
};

constexpr auto classRegistry = makeRegistry<MyClassA, MyClassB>();

#endif