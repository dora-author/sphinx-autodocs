#ifndef MESSAGE_TYPE_H
#define MESSAGE_TYPE_H

#pragma pack(push, 1)
namespace morai::msg
{
    /// @enum MsgType
    /// @brief This is all message type 
    /// @version 0.2
    enum class MsgType : uint8_t
    {
        /*!< 1 */
        /*!< to ros2 udp bridge aa*/
        GNSS_SENSOR = 0x01,          
        IMAGE_SENSOR,               /*!< 2 */
        RADAR_SENSOR,               /*!< 3 */
        IMU_SENSOR,                 /*!< 4 */
        LIDAR_SENSOR,               /*!< 5 */
        COMPRESSED_IMAGE_SENSOR,    /*!< 6 */

        // user -> morai
        CIRRUS_TX,                  /*!< 7 */
        CIRRUS_CONTROL_POSITION,    /*!< 8 */
        CIRRUS_BRAKING,             /*!< 9 */
        CIRRUS_ENGINE,              /*!< 10 */

        // Device : not sensor
        VORDME_INFO_DEVICE,         /*!< 11 */
        VORDME_CTRL_DEVICE,         /*!< 12 */

        // test
        LARGE_PACKET,
    };
}
#pragma pack(pop)
#endif
