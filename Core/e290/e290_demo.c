#include "e290_demo.h"
#include "pan_rf.h"


uint8_t spi_readwritebyte(uint8_t txdata)
{

}

void TIM_Delay_us(uint32_t us)
{

}

bool e290_demo_check_rx_done( uint8_t *buffer, uint8_t * length  , double *rssi)
{

}

void e290_demo_receive( void )
{

}

void e290_demo_transmit( uint8_t *buffer , uint8_t length )
{
    
}

void e290_demo_config_init (void)
{
    
}

void e290_demo_task(void)
{
    HAL_GPIO_TogglePin(LED_RX_GPIO_Port, LED_RX_Pin);
    HAL_Delay(500);
    HAL_GPIO_TogglePin(LED_RX_GPIO_Port, LED_RX_Pin);
    HAL_Delay(500);
}