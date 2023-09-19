#pragma once

#include "../msg_enumeration.h"

#pragma pack(push, 1)
namespace morai::msg
{
    struct PointF
    {
        float x;
        float y;                
    };

    /**
     * @brief 
     * A structure to represent 3D vectors
     */
    struct Vector3f
    {
        /*@{*/
        float x;    /**< the x coordinate */
        float y;
        float z;
        /*@}*/
    };

    struct Vector3d
    {
        double x;
        double y;
        double z;
    };

    struct Quarternion
    {
        double x;
        double y;
        double z;
        double w;
    };    

    struct Wheel_4
    {
        float FL;
        float FR;
        float RL;
        float RR;
    };
}
#pragma pack(pop)