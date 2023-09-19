
#pragma once

#pragma pack(push, 1)
namespace rohde::msg
{
    #ifdef _WIN32
        #pragma pack(push, 1)
        typedef struct _udp_position_data
    #else
        typedef struct __attribute__((packed)) _udp_position_data
    #endif
        {
            int reserve0;
            int reserve1;
            int reserve2;
            int reserve3;
            double elapsedTime;
            double xx;
            double yy;
            double zz;
            double xDot;
            double yDot;
            double zDot;
            double xDotDot;
            double yDotDot;
            double zDotDot;
            double xDotDotDot;
            double yDotDotDot;
            double zDotDotDot;
            double yaw;
            double pitch;
            double roll;
            double yawDot;
            double pitchDot;
            double rollDot;        
            double yawDotDot;
            double pitchDotDot;
            double rollDotDot;
            double yawDotDotDot;
            double pitchDotDotDot;
            double rollDotDotDot;            
        } UDP_POSITION_DATA;
    #ifdef _WIN32
        #pragma pack(pop)
    #endif    
}
#pragma pack(pop)