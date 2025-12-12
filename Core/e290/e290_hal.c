#include "e290_hal.h"

en_flag_status_t PORT_GetBit(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    HAL_GPIO_ReadPin(GPIOx,GPIO_Pin);
    return Set;
}






