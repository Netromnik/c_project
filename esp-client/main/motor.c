#include "head.h"
#define Range_x_min -45
#define Range_x_max 45
#define Range_y_min -45
#define Range_y_max 45

#define GPIO_OUTPUT_IO_0    16
#define GPIO_OUTPUT_IO_1    5
#define GPIO_OUTPUT_IO_2    4
#define GPIO_OUTPUT_IO_3    0

#define GPIO_OUTPUT_PIN_SEL  ((1ULL<<GPIO_OUTPUT_IO_0) | (1ULL<<GPIO_OUTPUT_IO_1)| (1ULL<<GPIO_OUTPUT_IO_2)| (1ULL<<GPIO_OUTPUT_IO_3))
#define ESP_INTR_FLAG_DEFAULT 0
static const char *TAG = "motor control";

int state[5][5]={
/*M_Up*/	{0,	1,	0,	1},
/*M_Down*/	{1	,0,	1,	0},
/*M_Right*/	{1,	0,	0,	1},
/*M_LEFT*/	{0,	1,	1,	0},
/*M_STOP*/	{0 ,0,	0,	0}
};

#define M_Up	  state[0]
#define M_Down	state[1]
#define M_Right	state[2]
#define M_LEFT	state[3]
#define M_STOP	state[4]

static void c_motor_set_state(int *p){

  gpio_set_level(GPIO_OUTPUT_IO_0, p[0]);
  gpio_set_level(GPIO_OUTPUT_IO_1, p[1]);
  gpio_set_level(GPIO_OUTPUT_IO_2, p[2]);
  gpio_set_level(GPIO_OUTPUT_IO_3, p[3]);
}

void motor_init_d(void)
{
    gpio_config_t io_conf;
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set,e.g.GPIO18/19
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //disable pull-up mode
    io_conf.pull_up_en = 0;
    //configure GPIO with the given settings
    gpio_config(&io_conf);
    //enable pull-up mode
    io_conf.pull_up_en = 1;
    gpio_config(&io_conf);
}

void motor_set_state(int *row){

		if(row[1]>(Range_x_max) ){
			c_motor_set_state(M_Right);
		}
		else if(row[1] < Range_x_min){
			c_motor_set_state(M_LEFT);
		}
		else if(row[0]>Range_y_max ){
			c_motor_set_state(M_Up);
		}
		else if(row[0] < Range_y_min){
			c_motor_set_state(M_Down);
		}else{
			c_motor_set_state(M_STOP);

		}
}
