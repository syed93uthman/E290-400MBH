#ifndef E290_DEMO_H
#define E290_DEMO_H

#include "main.h"
#include "stm32f1xx_hal.h"
#include "tim.h"
#include "string.h"

typedef struct
{
	int ChirpIoT_sf;
	int ChirpIoT_bw;
	int ChirpIoT_cr;
	int frequency_mhz;
	int tx_power;
	int tx_count;
}pan_config_t;

extern pan_config_t user_config;

// Hardware abstraction functions
uint8_t spi_readwritebyte(uint8_t txdata);
void TIM_Delay_us(uint32_t us);

// E290 demo functions
bool e290_demo_check_rx_done( uint8_t *buffer, uint8_t * length  , double *rssi);
void e290_demo_receive( void );
void e290_demo_transmit( uint8_t *buffer , uint8_t length );


// E290 function
void e290_demo_config_init(void);
void e290_demo_task(void);

#endif