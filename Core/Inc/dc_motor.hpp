#ifndef H_BRIDGE_HPP
#define H_BRIDGE_HPP

#include "gpio.hpp"
#include "pwm_device.hpp"
#include "utility.hpp"
#include <cstdint>

namespace L298N {

    struct DCMotor {
    public:
        enum struct Direction : std::uint8_t {
            FORWARD,
            BACKWARD,
            FAST_STOP,
            SOFT_STOP,
        };

        using PWMDevice = Utility::PWMDevice;
        using GPIO = Utility::GPIO;

        void set_voltage(float const voltage) const noexcept;
        void set_max_voltage() const noexcept;
        void set_min_voltage() const noexcept;

        void set_direction(Direction const direction) const noexcept;
        void set_forward_direction() const noexcept;
        void set_backward_direction() const noexcept;
        void set_soft_stop_direction() const noexcept;
        void set_fast_stop_direction() const noexcept;

        PWMDevice pwm_device{};

        GPIO pin_left{};
        GPIO pin_right{};
    };

}; // namespace L298N

#endif // H_BRIDGE_HPP