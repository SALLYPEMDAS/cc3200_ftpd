#include <hw_common_reg.h>
#include <hw_memmap.h>
#include <uart.h>
#include <interrupt.h>
#include <utils.h>
#include <prcm.h>
#include <string.h>
#include <device.h>

#include "userfunc.h"
#include "sdreader.h"
#include "sdcard.h"
#include "board.h"
#include "twi.h"
#include "pin.h"
#include "ff.h"
#include "main.h"
#include "lantask.h"


#define         NUM_BYTES		128

/** 
 * ��������� ������ �����
 */
int main(void)
{

    /* Initailizing the board */
    board_init();

    /* ������������� ��������� �� �����. ������ �� ����� ������� */
    com_mux_config();
    PRINTF("INFO: Program %s %s start OK\n", __DATE__, __TIME__);

    led_init();
    led_off(0);
    led_off(1);    

    /* ������������� i2c ����� ��������� ����� 2 � 3  + �������� Lock ������ */
    // twi_init();

    /* SD ����� � ���������� */
    // set_sd_to_mcu();

    sd_card_mux_config(); 
    
    xchg_start();

    /* Start the task scheduler */
    osi_start();
    return 0;
}
