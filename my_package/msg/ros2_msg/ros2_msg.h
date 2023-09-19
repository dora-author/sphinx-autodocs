#pragma once

// udp -> ros2bridge -> ros2 publish
#include "../morai_msg.h"
#include "../../Socket/util.h"

#include <string>

#pragma pack(push, 1)
namespace morai::msg
{
#pragma region geometry_msgs
    struct Point
    {
        double x;
        double y;
        double z;
    };
#pragma endregion

#pragma region std_msgs
    struct RosTimestamp
    {
        int32_t sec;
        uint32_t nanosec;
    };

    //class RosHeader : public IMsg
    struct RosHeader    
    {    
    public:
        //char* frame_id;   
        RosHeader() {}
        RosHeader(int32_t _sec, int32_t _nano_sec, std::string _frame_id) {
            stamp.sec = _sec;
            stamp.nanosec = _nano_sec;
            set_frame_id(_frame_id);
        }
        ~RosHeader() { }

        RosTimestamp stamp;

        void set_frame_id(std::string _frame_id)
        {
            str_len = _frame_id.length() + 1;
            frame_id = _frame_id;
        }

        std::string get_frame_id() {
            return frame_id;
        }

        // total length
        int length()
        {
            return sizeof(RosTimestamp) + sizeof(RosHeader::str_len) + str_len;
        }

        bool Serialize(char* buffer, int buffer_size, int index = 0)
        {
            if (length() > buffer_size - index)
                return false;
            
            memcpy(buffer + index, &stamp, sizeof(RosTimestamp));
            index += sizeof(RosTimestamp);

            memcpy(buffer + index, &str_len, sizeof(RosHeader::str_len));
            index += sizeof(RosHeader::str_len);

            memcpy(buffer + index, frame_id.c_str(), str_len);
            index += str_len;

            return true;
        }

        bool Deserialize(char* data, int data_size, int index = 0)
        {
            bool res = true;

            if (data_size < 9)
                res = false;
            else
            {
                memcpy(&stamp, data + index, sizeof(RosTimestamp));
                index += sizeof(RosTimestamp);

                memcpy(&str_len, data + index, sizeof(RosHeader::str_len));
                index += sizeof(RosHeader::str_len);

                if (str_len == 0)
                {
                    frame_id = "";
                }
                else if (str_len > 0 && data_size - index >= str_len)
                {
                    // check
                    char* _frame_id = new char[str_len];
                    memcpy(_frame_id, data + index, str_len);
                    frame_id = _frame_id;
                    morai::comm::DeletePtr(_frame_id);
                }
                else
                {
                    // something wrong
                    res = false;
                }
            }            
            return res;
        }

    private:        
        uint8_t str_len;                    // frame_id length
        std::string frame_id;
    };
#pragma endregion


#pragma region sensor_msgs
    struct NavSatStatus
    {
        /*int8 STATUS_NO_FIX = -1
        int8 STATUS_FIX = 0
        int8 STATUS_SBAS_FIX = 1
        int8 STATUS_GBAS_FIX = 2
        uint16 SERVICE_GPS = 1
        uint16 SERVICE_GLONASS = 2
        uint16 SERVICE_COMPASS = 4
        uint16 SERVICE_GALILEO = 8*/
        int8_t status;
        uint16_t service;
    };

    struct NavSatFix
    {        
        /*uint8 COVARIANCE_TYPE_UNKNOWN = 0
        uint8 COVARIANCE_TYPE_APPROXIMATED = 1
        uint8 COVARIANCE_TYPE_DIAGONAL_KNOWN = 2
        uint8 COVARIANCE_TYPE_KNOWN = 3
        RosHeader header;
        NavSatStatus status;        */
        double latitude;
        double longitude;
        double altitude;
        double position_covariance[9];
        uint8_t position_covariance_type;
    };

    struct Imu
    {
        Quarternion orientation;
        double orientation_covariance[9];
        Vector3d angular_velocity;
        double angular_velocity_covariance[9];
        Vector3d linear_acceleration;
        double liner_acceleration_covariance[9];
    };

    struct PointField
    {
        // uint8_t INT8    = 1;
        // uint8_t UINT8   = 2;
        // uint8_t INT16   = 3;
        // uint8_t UINT16  = 4;
        // uint8_t INT32   = 5;
        // uint8_t UINT32  = 6;
        // uint8_t FLOAT32 = 7;
        // uint8_t FLOAT64 = 8;
        uint32_t offset;
        uint8_t datatype;
        uint32_t count;

        void set_name(std::string _name) {
            name_length = _name.length() + 1;
            name = _name;
        }

        std::string get_name() {
            return name;
        }

        int length()
        {
            return sizeof(PointField::offset) + sizeof(PointField::datatype) +
                sizeof(PointField::count) + sizeof(PointField::name_length) + name_length;
        }

        bool Serialize(char* buffer, int buffer_size, int index)
        {
            if (length() > buffer_size - index)
                return false;

            memcpy(buffer + index, &name_length, sizeof(PointField::name_length));
            index += sizeof(PointField::name_length);

            memcpy(buffer + index, name.c_str(), name_length);
            index += name_length;

            memcpy(buffer + index, &offset, sizeof(PointField::offset));
            index += sizeof(PointField::offset);

            memcpy(buffer + index, &datatype, sizeof(PointField::datatype));
            index += sizeof(PointField::datatype);

            memcpy(buffer + index, &count, sizeof(PointField::count));
            index += sizeof(PointField::count);

            return true;
        }

    private:
        uint8_t name_length;
        std::string name;
    };   

    struct RadarDetection
    {
        uint16_t detection_id;
        Point position;
        float azimuth;
        float ragerate;
        float amplitude;
    };      
#pragma endregion    

#pragma region morai custom
    struct Radar
    {
        uint8_t num_detections;
        RadarDetection detections[64];
    };

    struct Image
    {
    public:
        Image() {
            encoding = "";
            data = nullptr;
        }
        ~Image() {
            if (data != nullptr) {
                delete[] data;
                data = nullptr;
            }
        }

        uint32_t height;
        uint32_t width;        
        uint8_t is_bigendian;
        uint32_t step;
        uint8_t* data;

        void set_encoding(std::string _encoding) {
            str_len = _encoding.length() + 1;
            encoding = _encoding;
        }

        std::string get_encoding() {
            return encoding;
        }

        void set_data(uint8_t* _data) {
            data = _data;
        }

        int data_length() {
            return width * height * 4;
        }

        int length() {
            int static_size = sizeof(Image::height) + sizeof(Image::width) + sizeof(Image::is_bigendian) + sizeof(Image::step);
            int dynamic_size = sizeof(Image::str_len) + str_len;
            return static_size + dynamic_size + data_length();
        }

        bool Serialize(char* buffer, int buffer_size, int index) {
            if (length() > buffer_size - index)
                return false;
            
            memcpy(buffer + index, &height, sizeof(Image::height));
            index += sizeof(Image::height);

            memcpy(buffer + index, &width, sizeof(Image::width));
            index += sizeof(Image::width);
            
            memcpy(buffer + index, &str_len, sizeof(Image::str_len));
            index += sizeof(Image::str_len);

            memcpy(buffer + index, encoding.c_str(), str_len);
            index += str_len;

            memcpy(buffer + index, &is_bigendian, sizeof(Image::is_bigendian));
            index += sizeof(Image::is_bigendian);

            memcpy(buffer + index, &step, sizeof(Image::step));
            index += sizeof(Image::step);

            memcpy(buffer + index, &data, data_length());
            index += data_length();

            return true;
        }

        bool Deserialize() {
            return false;
        }
    private:
        uint16_t str_len;
        std::string encoding;
    };

    // sensor_msgs/PointCloud2 Message
    struct Lidar
    {
        uint32_t height;            // 2D structure of the point cloud.If the cloud is unordered, height is
        uint32_t width;             // 1 and width is the length of the point cloud.
        uint8_t fields_len;         // size of PointField
        PointField* fields;         // Describes the channels and their layout in the binary data blob.
        bool    is_bigendian;       // Is this data bigendian ?
        uint32_t  point_step;       // Length of a point in bytes
        uint32_t  row_step;         // Length of a row in bytes
        uint8_t* data;              // Actual point data, size is(row_step* height)
        bool is_dense;              // True if there are no invalid points        

        bool Serialize(char* buffer, int buffer_size, int index) {
            if (length() > buffer_size - index)
                return false;

            memcpy(buffer + index, &height, sizeof(Lidar::height));
            index += sizeof(Lidar::height);

            memcpy(buffer + index, &width, sizeof(Lidar::width));
            index += sizeof(Lidar::width);

            memcpy(buffer + index, &fields_len, sizeof(Lidar::fields_len));
            index += sizeof(Lidar::fields_len);

            for (int i = 0; i < fields_len; i++)
            {
                fields[i].Serialize(buffer, buffer_size, index);
                index += fields[i].length();
            }

            memcpy(buffer + index, &is_bigendian, sizeof(Lidar::is_bigendian));
            index += sizeof(Lidar::is_bigendian);

            memcpy(buffer + index, &point_step, sizeof(Lidar::point_step));
            index += sizeof(Lidar::point_step);

            memcpy(buffer + index, &row_step, sizeof(Lidar::row_step));
            index += sizeof(Lidar::row_step);

            // data cop
            memcpy(buffer + index, data, data_length());
            index += data_length();

            memcpy(buffer + index, &is_dense, sizeof(Lidar::is_dense));
            index += sizeof(Lidar::is_dense);

            return true;
        }

        int data_length() {
            return row_step * height;
        }

        int length() {
            int static_size = sizeof(Lidar::height) + sizeof(Lidar::width) +
                sizeof(Lidar::fields_len) + sizeof(Lidar::point_step) + sizeof(Lidar::row_step) +
                sizeof(Lidar::is_bigendian) + sizeof(Lidar::is_dense);

            int point_fields_dynamic_size = 0;            
            for (int i = 0; i < fields_len; i++) {
                point_fields_dynamic_size += fields[i].length();
            }

            int dynamic_size = fields_len + point_fields_dynamic_size + data_length();

            return static_size + dynamic_size;
        }
    };

    struct GNSS_M
    {
        Identifier id;
        RosHeader ros_header;        
        NavSatStatus nav_sat_status;
        NavSatFix nav_sat_fix;
    };

    struct IMU_M
    {
        Identifier id;
        RosHeader ros_header;                
        Imu imu;
    };

    struct Lidar_M
    {
        Identifier id;
        RosHeader ros_header;                
        Lidar lidar;
    };

    struct Radar_M
    {
        Identifier id;
        RosHeader ros_header;                
        Radar radar;
    };

    struct Image_M
    {
        Identifier id;
        RosHeader ros_header;
        Image image;
    };

#pragma endregion
// namesapce end
}
#pragma pack(pop)