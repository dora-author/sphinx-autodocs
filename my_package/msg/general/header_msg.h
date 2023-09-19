#pragma once

#include "../msg_type.h"

#pragma pack(push, 1)
namespace morai::msg
{    
    // 16
    struct Frame
    {
        uint32_t msg_frames;            // total frame count
        uint32_t frame_size;            // frame size
        uint32_t frame_pos;             // index * frame_size
        uint32_t frame_index;           // 
    };

    // 30
    struct Header
    {
        uint32_t header_version;         //        
        MsgType msg_type;               // message type
        uint8_t protocol_type;          // protocol type  tcp, udp, ros ...
        uint16_t send_count;            // send count        
        Frame frame;
        uint32_t msg_size;
        uint8_t reserved_01;
        uint8_t reserved_02;
    };
}
#pragma pack(pop)