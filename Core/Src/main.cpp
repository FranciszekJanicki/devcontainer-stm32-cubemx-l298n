#include "main.h"
#include "clock_config.h"
#include "gpio.h"
#include "l298n.hpp"
#include "pwm_device.hpp"
#include "tim.h"
#include "usart.h"

int main()
{
    HAL_Init();
    SystemClock_Config();
    PeriphCommonClock_Config();

    MX_GPIO_Init();
    MX_USART2_UART_Init();
    MX_TIM3_Init();

    using namespace L298N;
    using namespace Utility;

    auto pwm_device_a = PWMDevice{&htim3, TIM_CHANNEL_3, 39999U, 3.3F};
    auto pwm_device_b = PWMDevice{&htim3, TIM_CHANNEL_4, 39999U, 3.3F};

    auto dc_motor_a = DCMotor{.pwm_device = std::move(pwm_device_a), .pin_left = GPIO::PA8, .pin_right = GPIO::PA9};

    auto dc_motor_b = DCMotor{.pwm_device = std::move(pwm_device_b), .pin_left = GPIO::PA10, .pin_right = GPIO::PA11};

    using L298N = L298N::L298N;

    auto l298n =
        L298N{.motor_channels = {
                  L298N::DCMotorChannel{.channel = L298N::Channel::CHANNEL_A, .motor = std::move(dc_motor_a)},
                  L298N::DCMotorChannel{.channel = L298N::Channel::CHANNEL_B, .motor = std::move(dc_motor_b)}}};

    while (true) {
    }

    return 0;
}
