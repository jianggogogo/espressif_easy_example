/**@author : shan jiang 
*  @time   :  2019.12.3
*/

#include <stdio.h>
#include "driver/mcpwm.h"
#include "soc/mcpwm_periph.h"

//定义一个输出管脚和一个输入捕获管脚
#define GPIO_PWM0A_OUT 21 //Set GPIO 15 as PWM0A

/** @brief  管脚配置
 *  @brief  pin conifg
 * 
 * **/
void M_pwm_init()
{
    mcpwm_pin_config_t pin_config = {
        .mcpwm0a_out_num = GPIO_PWM0A_OUT,
    };
    //设置这些gpio为PWM管脚
    mcpwm_set_pin(MCPWM_UNIT_0, &pin_config);

}

/** @brief 输出的初始化和配置,以及开启
 *  @brief pwm config and start
 * 
 * **/
void M_pwm_out_init()
{
    M_pwm_init();
    mcpwm_config_t pwm_config;
    pwm_config.frequency = 1000; //frequency = 1000Hz
    pwm_config.cmpr_a = 60.0;    //duty cycle of PWMxA = 60.0%
    pwm_config.cmpr_b = 50.0;    //duty cycle of PWMxb = 50.0%
    pwm_config.counter_mode = MCPWM_UP_COUNTER;
    pwm_config.duty_mode = MCPWM_DUTY_MODE_0;
    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config); //Configure PWM0A & PWM0B with above settings
   //start pwm
   mcpwm_start(MCPWM_UNIT_0,MCPWM_TIMER_0);
}
