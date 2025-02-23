#ifndef L298N_HPP
#define L298N_HPP

#include "dc_motor.hpp"
#include "utility.hpp"
#include <array>
#include <cmath>
#include <cstdint>
#include <utility>

namespace L298N {

    struct L298N {
    public:
        enum struct Channel : std::uint8_t {
            CHANNEL_A,
            CHANNEL_B,
        };

        struct DCMotorChannel {
            Channel channel{};
            DCMotor motor{};
        };

        using Direction = DCMotor::Direction;

        void reset() const noexcept;

        void set_voltage(Channel const channel, float const voltage) const noexcept;
        void set_max_voltage(Channel const channel) const noexcept;
        void set_min_voltage(Channel const channel) const noexcept;

        void set_direction(Channel const channel, Direction const direction) const noexcept;
        void set_forward_direction(Channel const channel) const noexcept;
        void set_backward_direction(Channel const channel) const noexcept;
        void set_soft_stop_direction(Channel const channel) const noexcept;
        void set_fast_stop_direction(Channel const channel) const noexcept;

        void set_voltages(float const voltage) const noexcept;
        void set_max_voltages() const noexcept;
        void set_min_voltages() const noexcept;

        void set_directions(Direction const direction) const noexcept;
        void set_forward_directions() const noexcept;
        void set_backward_directions() const noexcept;
        void set_soft_stop_directions() const noexcept;
        void set_fast_stop_directions() const noexcept;

        std::array<DCMotorChannel, 2UL> motor_channels{};

    private:
        DCMotor const& get_motor(Channel const channel) const noexcept;
        DCMotor& get_motor(Channel const channel) noexcept;
    };

}; // namespace L298N

#endif // L298N_HPP