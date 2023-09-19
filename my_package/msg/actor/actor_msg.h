#ifndef ACTOR_MESSAGES_H_
#define ACTOR_MESSAGES_H_

#include <string>
#include "../morai_msg.h"

#pragma pack(push, 1)
namespace morai::msg
{
    // struct SubjectVehicleStates
    // {
    //     Vector3f position;
    //     float angle;
    //     float speed;
    //     float acceleration;
    //     int[] laneNumber;
    //     Point size;
    //     //...
    // };

    struct Actor
    {
        Header header;
        Vector3f position;
        Gear gear;
        Wheel_4 wheel;
    };

    // for grpc
    //class VehicleSpawnParam
    //{
    //public:
    //private:
    //    Transform transform;
    //    std::string model_name;
    //    std::string label;
    //    double velocity;
    //    bool pause;
    //    bool multi_ego;
    //};
}
#pragma pack(pop)

#endif /* ACTOR_MESSAGES_H_ */