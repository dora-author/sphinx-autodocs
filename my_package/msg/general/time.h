#pragma once

#include "../msg_type.h"

#pragma pack(push, 1)
namespace morai::msg
{    
    struct TimeStamp
    {
        long timestamp;
    };

    struct TimeVal
    {
        long sec;
        long nano_sec;
    };
}
#pragma pack(pop)