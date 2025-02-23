#include "l298n.hpp"
#include "dc_motor.hpp"
#include <algorithm>
#include <cassert>
#include <expected>
#include <ranges>
#include <utility>

namespace L298N {

    void L298N::reset() const noexcept
    {
        std::ranges::for_each(this->motor_channels, [](auto& motor_channel) {
            motor_channel.motor.set_fast_stop_direction();
            motor_channel.motor.set_min_voltage();
        });
    }

    void L298N::set_voltage(Channel const channel, float const voltage) const noexcept
    {
        this->get_motor(channel).set_voltage(voltage);
    }

    void L298N::set_max_voltage(Channel const channel) const noexcept
    {
        this->get_motor(channel).set_max_voltage();
    }

    void L298N::set_min_voltage(Channel const channel) const noexcept
    {
        this->get_motor(channel).set_min_voltage();
    }

    void L298N::set_direction(Channel const channel, Direction const direction) const noexcept
    {
        this->get_motor(channel).set_direction(direction);
    }

    void L298N::set_forward_direction(Channel const channel) const noexcept
    {
        this->get_motor(channel).set_forward_direction();
    }

    void L298N::set_backward_direction(Channel const channel) const noexcept
    {
        this->get_motor(channel).set_backward_direction();
    }

    void L298N::set_soft_stop_direction(Channel const channel) const noexcept
    {
        this->get_motor(channel).set_soft_stop_direction();
    }

    void L298N::set_fast_stop_direction(Channel const channel) const noexcept
    {
        this->get_motor(channel).set_fast_stop_direction();
    }

    void L298N::set_voltages(float const voltage) const noexcept
    {
        std::ranges::for_each(this->motor_channels,
                              [voltage](auto& motor_channel) { motor_channel.motor.set_voltage(voltage); });
    }

    void L298N::set_max_voltages() const noexcept
    {
        std::ranges::for_each(this->motor_channels, [](auto& motor_channel) { motor_channel.motor.set_max_voltage(); });
    }

    void L298N::set_min_voltages() const noexcept
    {
        std::ranges::for_each(this->motor_channels, [](auto& motor_channel) { motor_channel.motor.set_min_voltage(); });
    }

    void L298N::set_directions(Direction const direction) const noexcept
    {
        std::ranges::for_each(this->motor_channels,
                              [direction](auto& motor_channel) { motor_channel.motor.set_direction(direction); });
    }

    void L298N::set_forward_directions() const noexcept
    {
        std::ranges::for_each(this->motor_channels,
                              [](auto& motor_channel) { motor_channel.motor.set_forward_direction(); });
    }

    void L298N::set_backward_directions() const noexcept
    {
        std::ranges::for_each(this->motor_channels,
                              [](auto& motor_channel) { motor_channel.motor.set_backward_direction(); });
    }

    void L298N::set_soft_stop_directions() const noexcept
    {
        std::ranges::for_each(this->motor_channels,
                              [](auto& motor_channel) { motor_channel.motor.set_soft_stop_direction(); });
    }

    void L298N::set_fast_stop_directions() const noexcept
    {
        std::ranges::for_each(this->motor_channels,
                              [](auto& motor_channel) { motor_channel.motor.set_fast_stop_direction(); });
    }

    DCMotor const& L298N::get_motor(Channel const channel) const noexcept
    {
        if (const auto it{std::ranges::find_if(
                std::as_const(this->motor_channels),
                [channel](auto const& motor_channel) { return motor_channel.channel == channel; })};
            it != this->motor_channels.cend()) {
            return it->motor;
        }
        std::unreachable();
    }

    DCMotor& L298N::get_motor(Channel const channel) noexcept
    {
        if (auto it{std::ranges::find_if(
                this->motor_channels,
                [channel](auto const& motor_channel) { return motor_channel.channel == channel; })};
            it != this->motor_channels.cend()) {
            return it->motor;
        }
        std::unreachable();
    }

}; // namespace L298N