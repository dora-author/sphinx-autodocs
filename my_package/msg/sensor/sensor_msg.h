#pragma once

#pragma pack(push, 1)
namespace morai::msg
{
    struct VORDMEInfo
    {
        int32_t hertz;
        float latitude;
        float longitude;
        float angle;
        double distance;
    };
        
    struct VORDMECtrl
    {
        int32_t frequency[100];
    };

    // #ifdef _WIN32
    //     #pragma pack(push, 1)
    //     typedef struct _VORDMEInfo
    // #else
    //     typedef struct __attribute__((packed)) _VORDMEInfo
    // #endif
    //     {
    //         int32_t hertz;
    //         float latitude;
    //         float longitude;
    //         float angle;
    //         double distance;
    //     }VORDMEInfo;
    // #ifdef _WIN32
    //     #pragma pack(pop)
    // #endif
    
    // #ifdef _WIN32
    //     #pragma pack(push, 1)
    //     typedef struct _VORDMECtrl
    // #else
    //     typedef struct __attribute__((packed)) _VORDMECtrl
    // #endif
    //     {
    //         int32_t frequency[100];
    //     }VORDMECtrl;
    // #ifdef _WIN32
    //     #pragma pack(pop)
    // #endif
}
#pragma pack(pop)