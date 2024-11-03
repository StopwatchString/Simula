#ifndef SIMULA_CORE_OBJECT_H
#define SIMULA_CORE_OBJECT_H

#include <string>

namespace simula {
namespace core {
class Object
{
public:
    Object();
    ~Object();

    Object(const Object& other);
    Object(Object&& other) noexcept;

    virtual Object& operator=(const Object& other);
    virtual Object& operator=(Object&& other) noexcept;

    virtual std::string getObjectName() = 0;
private:

};
} // end core
} // end simula

#endif