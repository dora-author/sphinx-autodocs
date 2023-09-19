#pragma once

#pragma pack(push, 1)
namespace cirrus::msg
{
    struct CirrusTx
    {
        float lon;              // deg
        float lat;              // deg
        float alt;              // ft        
        float heading;          // deg
        float roll;             // deg
        float pitch;            // deg
        float sur_aileron;      // [-1 ~ 1]
        float sur_flap;         // [-1 ~ 1]
        float sur_elevator;     // [-1 ~ 1]
        float sur_rudder;       // [-1 ~ 1]
    };

    struct TxPacket
    {
        int size;
        char* txData;
    };

    struct RxPacket
    {
        int size;
        char* rxData;
    };
        
    struct CirrusControlPosition
    {
        float SetDaCmd;             // get_aileron              -1 ~ +1                 // roll     // key left 4 right 6 
        float SetRollTrimCmd;       // get_aileron_trim         (-0.1 ~ +0.1)           // micro control
        float SetDeCmd;             // get_elevator             -1 ~ +1                 // pitch    // key 8 down  2 up
        float SetPitchTrimCmd;      // get_elevator_trim        (-0.1 ~ +0.1)           // 
        float SetDrCmd;             // get_rudder               -1 ~ +1                 // yaw      // key 7 left   9 right 
        float SetDsCmd;             // get_rudder               -1 ~ +1                 // steering (ground)
        float SetYawTrimCmd;        // get_rudder_trim          (-0.1 ~ +0.1)
        float SetDfCmd;             // get_flaps                0 ~ 1
    };

    struct CirrusBraking
    {
        float SetBrake;             // Left + Right             0~1                 // wheel brake
        // air Speed brake
    };
    
    struct CirrusEngine
    {
        float SetThrottleCmd;      // get_throttle(i)           0~1                 // 
    }; 
}
#pragma pack(pop)