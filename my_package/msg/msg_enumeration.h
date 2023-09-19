
#ifndef MESSAGE_ENUM_H
#define MESSAGE_ENUM_H

#pragma pack(push, 1)
namespace morai::msg
{
    enum class ControlMode : uint8_t
    {
        Auto,
        Keyboard,
    };

    /** @enum mapper::IMAGE_REPORTING
     *  @brief is a strongly typed enum class representing the status of image reporting
     */
    enum class Gear : uint8_t
    {
        Manual = 0,         /**< is coded as std::uint8_t of value 0 */
        Parking,            /**< parking mode */
        Reverse,            /**< reverse mode */
        Neutral,            /**< neutral mode */
        Drive,              /**< drive mode */
        Low,                /**< for hill */
        Up,                 /**< shift up */        
        Down                /**< shift down */
    };


    /**
     * @brief 
     * 
     */
    enum class CommandType : uint8_t
    {
        throttle,           /**< throttle command accel/brake/steering */
        velocity,           /**< Velocity command velocity/steering */
        acceleration       /**< Acceleration command acceleration/steering */
    };

    enum class ActorType : uint8_t
    {
        ego,
        npc
    };

    enum class VehicleType : uint8_t
    {
        car,
        ship,        
        airplane,
        heli,
        drone,
        spaceship
    };

    enum class WheelDirection : uint8_t
    {
        left,
        right
    };
}
#pragma pack(pop)

#endif