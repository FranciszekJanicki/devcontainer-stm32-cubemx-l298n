#include "dc_motor.hpp"
#include <algorithm>
#include <expected>
#include <utility>

namespace L298N {

    void DCMotor::set_voltage(float const voltage) const noexcept
    {
        this->pwm_device.set_compare_voltage(voltage);
    }

    void DCMotor::set_max_voltage() const noexcept
    {
        this->pwm_device.set_compare_max();
    }

    void DCMotor::set_min_voltage() const noexcept
    {
        this->pwm_device.set_compare_min();
    }

    void DCMotor::set_direction(Direction const direction) const noexcept
    {
        switch (direction) {
            case Direction::SOFT_STOP:
                this->set_soft_stop_direction();
                break;
            case Direction::FAST_STOP:
                this->set_fast_stop_direction();
                break;
            case Direction::FORWARD:
                this->set_forward_direction();
                break;
            case Direction::BACKWARD:
                this->set_backward_direction();
                break;
        }
    }

    void DCMotor::set_forward_direction() const noexcept
    {
        gpio_write_pin(this->pin_left, GPIO_PIN_RESET);
        gpio_write_pin(this->pin_right, GPIO_PIN_RESET);
        this->set_max_voltage();
    }

    void DCMotor::set_backward_direction() const noexcept
    {
        gpio_write_pin(this->pin_left, GPIO_PIN_SET);
        gpio_write_pin(this->pin_right, GPIO_PIN_SET);
        this->set_min_voltage();
    }

    void DCMotor::set_fast_stop_direction() const noexcept
    {
        gpio_write_pin(this->pin_left, GPIO_PIN_SET);
        gpio_write_pin(this->pin_right, GPIO_PIN_RESET);
    }

    void DCMotor::set_soft_stop_direction() const noexcept
    {
        gpio_write_pin(this->pin_left, GPIO_PIN_RESET);
        gpio_write_pin(this->pin_right, GPIO_PIN_SET);
    }

}; // namespace L298N
