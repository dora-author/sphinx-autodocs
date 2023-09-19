#pragma once

#pragma pack(push, 1)
namespace morai::msg
{    
    // for test
    struct LargePacket
    {
        char data[1024];
    };
    
    // legacy
    struct EgoVehicleStatus
    {
        Header header;
        uint8_t start_indicator;
        char header_name[9];
        uint8_t doller_indicator;
        uint32_t data_length;
        char aux_data[12];
        uint8_t ctrl_mode;
        uint8_t gear;
        float signed_velocity;
        int map_data_id;
        float accel;
        float brake;
        float size_x;
        float size_y;
        float size_z;
        float overhang;
        float wheel_base;
        float rear_overhang;
        float pos_x;
        float pos_y;
        float pos_z;
        float roll;
        float pitch;
        float yaw;
        float velocity_x;
        float velocity_y;
        float velocity_z;
        float accel_x;
        float accel_y;
        float accel_z;
        float steer;
        char link_id[38];
        float wheel_fl;
        float wheel_fr;
        float wheel_rl;
        float wheel_rr;
        float yaw_rate;        
        uint16_t end_point;
    };

     
}
#pragma pack(pop)