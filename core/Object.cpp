#include "core/Object.h"

namespace simula {
namespace core {

//--------------------------------------------------
// Constructor
//--------------------------------------------------
Object::Object()
{

}

//--------------------------------------------------
// Destructor
//--------------------------------------------------
Object::~Object()
{

}

//--------------------------------------------------
// Copy Constructor
//--------------------------------------------------
Object::Object(const Object& other)
{

}

//--------------------------------------------------
// Move Constructor
//--------------------------------------------------
Object::Object(Object&& other) noexcept
{

}

//--------------------------------------------------
// Copy Assignment
//--------------------------------------------------
Object& Object::operator=(const Object& other)
{
    return *this;
}

//--------------------------------------------------
// Move Assignment
//--------------------------------------------------
Object& Object::operator=(Object&& other) noexcept
{
    return *this;
}

} // end core
} // end simula