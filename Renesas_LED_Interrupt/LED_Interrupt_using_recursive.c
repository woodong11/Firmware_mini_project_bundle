#include "hal_data.h"

FSP_CPP_HEADER
void R_BSP_WarmStart(bsp_warm_start_event_t event);
FSP_CPP_FOOTER

// 유저 함수들

volatile int start_flag = 0;
volatile int stop_flag = 0;
volatile int path[4] = {0, 0, 0, 0};

void led_on(int num){
    if (num == 0) R_IOPORT_PinWrite(&g_ioport_ctrl, usr_LED1, 1);
    else if (num == 1) R_IOPORT_PinWrite(&g_ioport_ctrl, usr_LED2, 1);
    else if (num == 2) R_IOPORT_PinWrite(&g_ioport_ctrl, usr_LED3, 1);
    else if (num == 3) R_IOPORT_PinWrite(&g_ioport_ctrl, usr_LED4, 1);
}

void led_off(int num){
    if (num == 0) R_IOPORT_PinWrite(&g_ioport_ctrl, usr_LED1, 0);
    else if (num == 1) R_IOPORT_PinWrite(&g_ioport_ctrl, usr_LED2, 0);
    else if (num == 2) R_IOPORT_PinWrite(&g_ioport_ctrl, usr_LED3, 0);
    else if (num == 3) R_IOPORT_PinWrite(&g_ioport_ctrl, usr_LED4, 0);
}

void func(int level){

    if (level == 4){

        // 처음부터 신호가 들어오면 다시 모두 리턴하기
        if (start_flag == 1)   return;

        // 해당 LED 켜기
        for (int i=0; i<4; i++) {
            if (path[i] == 1)   led_on(i);
        }
        R_BSP_SoftwareDelay(300, BSP_DELAY_UNITS_MILLISECONDS);

        // LED 일시정지 구현하기
        if (stop_flag == 1){
            while(1){
                if (stop_flag == 0)
                    break;
                else{
                    R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);
                }
            }
        }

        for (int i=0; i<4; i++) {
            led_off(i);
        }
        R_BSP_SoftwareDelay(300, BSP_DELAY_UNITS_MILLISECONDS);

        return;
    }

    func(level + 1);
    path[level] = 1;
    func(level + 1);
    path[level] = 0;

}

/* Callback function */
void irq_callback(external_irq_callback_args_t *p_args)
{
    // 처음부터 시작
    if( p_args-> channel ==5 ){
        if (start_flag == 0) start_flag = 1;
        else start_flag = 0;

    }
    if( p_args-> channel ==6 ){
        if (stop_flag == 0) stop_flag = 1;
        else stop_flag = 0;
    }
}

/*******************************************************************************************************************//**
 * main() is generated by the RA Configuration editor and is used to generate threads if an RTOS is used.  This function
 * is called by main() when no RTOS is used.
 **********************************************************************************************************************/
void hal_entry(void)
{
    /* TODO: add your own code here */
    R_ICU_ExternalIrqEnable(&g_external_irq6_ctrl);
    R_ICU_ExternalIrqEnable(&g_external_irq5_ctrl);

    start_flag = 0;
    stop_flag = 0;

    while(1){

        if (start_flag == 1){

            start_flag = 0;

            func(0);

        }

    }

}

/*******************************************************************************************************************//**
 * This function is called at various points during the startup process.  This implementation uses the event that is
 * called right before main() to set up the pins.
 *
 * @param[in]  event    Where at in the start up process the code is currently at
 **********************************************************************************************************************/
void R_BSP_WarmStart(bsp_warm_start_event_t event)
{
    if (BSP_WARM_START_RESET == event)
    {

    }

    if (BSP_WARM_START_POST_C == event)
    {
        /* C runtime environment and system clocks are setup. */

        /* Configure pins. */
        R_IOPORT_Open (&g_ioport_ctrl, &IOPORT_CFG_NAME);

        R_ICU_ExternalIrqOpen(&g_external_irq5_ctrl, &g_external_irq5_cfg);
        R_ICU_ExternalIrqOpen(&g_external_irq6_ctrl, &g_external_irq6_cfg);

    }
}
