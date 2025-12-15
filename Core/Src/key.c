#include "main.h"

#define KEY_SHORT_PRESS_TIME_MS  100

typedef struct
{
		uint32_t count ; 
		bool continue_enable;	
		bool is_press;
		bool is_continue;
}key_config_t;

static key_config_t key_group[3] = 
{
		[ KEY_NAME_UP ] = {
			.count = 0,
			.is_press = 0,
			.continue_enable = false,
			.is_continue =  false,
		},
		
		[ KEY_NAME_DOWN ] = {
			.count = 0,
			.is_press = 0,
			.continue_enable = false,
			.is_continue =  false,
		},

		[ KEY_NAME_ENTER ] = {
			.count = 0,
			.is_press = 0,
			.continue_enable = false,
			.is_continue =  false,
		}		
};


bool key_check_press( key_name_t name )
{
	bool ret = false;
	
	/* �ϲ�������ѯ״̬��������ǰ״̬ */
	ret = key_group[name].is_press;
	
	/* ����flash����ֹ���δ��� */
	key_group[name].is_press = false;
	
	return ret;
}

void key_set_continue( key_name_t name , bool enable )
{
	key_group[name].continue_enable = enable;
}

static inline void key_press( key_name_t name )
{
	key_group[name].count ++;

	/* ����̰������ж�ʱ�� */
	if( key_group[name].count > KEY_SHORT_PRESS_TIME_MS )
	{
		/* �����ֹ���������ж� */
		if( key_group[name].continue_enable == false )
		{
				/* ���ڵ�һ�ζ̰��´����ж� */
				if( key_group[name].is_continue == false )
				{
					/* ��ֹ�´δ��� ֱ�������ͷ� ����false*/
					key_group[name].is_continue = true;
					/* ��һ�θ������±�ʶ */
					key_group[name].is_press = true;
				}			
		}
		/* ����������������ж� */
		else
		{
				/* �����������±�ʶ */
				key_group[name].is_press = true;
				/* ���¼�ʱ */
				key_group[name].count = 0;
		}
	}
}

static inline void key_release( key_name_t name )
{
	key_group[ name ].count = 0;
	key_group[ name ].is_continue = false;
}


void key_timer_1ms_interrupt_callback(void)
{
	if( HAL_GPIO_ReadPin( KEY_UP_GPIO_Port, KEY_UP_Pin ) == RESET )
	{
			key_press( KEY_NAME_UP );
	}
	else
	{
			key_release( KEY_NAME_UP );
	}
	
	if( HAL_GPIO_ReadPin( KEY_DOWN_GPIO_Port, KEY_DOWN_Pin ) == RESET )
	{
			key_press( KEY_NAME_DOWN );
	}
	else
	{
			key_release( KEY_NAME_DOWN );
	}

	if( HAL_GPIO_ReadPin( KEY_ENTER_GPIO_Port, KEY_ENTER_Pin ) == RESET )
	{
			key_press( KEY_NAME_ENTER );
	}
	else
	{
			key_release( KEY_NAME_ENTER );
	}	
	
}
