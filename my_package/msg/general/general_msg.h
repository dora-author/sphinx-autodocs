#pragma once

#include "../msg_type.h"

#pragma pack(push, 1)
namespace morai::msg
{    
    struct Identifier
    {
        uint8_t id;
    };
}
#pragma pack(pop)