#include "core/Component.h"

namespace simula {
namespace core {

//--------------------------------------------------
// Constructor
//--------------------------------------------------
Component::Component()
{

}

//--------------------------------------------------
// Destructor
//--------------------------------------------------
Component::~Component()
{

}

//--------------------------------------------------
// Copy Constructor
//--------------------------------------------------
Component::Component(const Component& other)
{

}

//--------------------------------------------------
// Move Constructor
//--------------------------------------------------
Component::Component(Component&& other) noexcept
{

}

//--------------------------------------------------
// Copy Assignment
//--------------------------------------------------
Component& Component::operator=(const Component& other)
{
    return *this;
}

//--------------------------------------------------
// Move Assignment
//--------------------------------------------------
Component& Component::operator=(Component&& other) noexcept
{
    return *this;
}

} // end core
} // end simula