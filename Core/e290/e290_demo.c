#include "e290_demo.h"
#include "pan_rf.h"


 /* ʹ����ʾ�˵��û����ò�����������ģ�� */
void e290_demo_menu_config( menu_config_t  *config )
{
    int8_t power_select;
    
    rf_set_freq(config->frequency_mhz* 1000000 );
    rf_set_bw(config->ChirpIoT_bw);
    rf_set_sf(config->ChirpIoT_sf);
    rf_set_code_rate(config->ChirpIoT_cr);
    
    switch( config->tx_power )
	{
		case 27: 
			power_select = 18; 
			break;
		
		case 24:
			power_select = 13; 
			break;			
		
		case 20:
			power_select = 11; 
			break;	

		default:
			power_select = 22; 
			break;
	}
    
    rf_set_tx_power(power_select);
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
    rf_irq_process();

    HAL_GPIO_TogglePin(LED_RX_GPIO_Port, LED_RX_Pin);
    HAL_Delay(500);
    HAL_GPIO_TogglePin(LED_RX_GPIO_Port, LED_RX_Pin);
    HAL_Delay(500);
}