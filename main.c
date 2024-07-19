/*----------------------------------------------------------------------------
* RL-ARM - RTX
*----------------------------------------------------------------------------
#include <RTL.h>
#include <LPC18xx.h> /* LPC18xx Definitions */
#include "GLCD.h"
#include "LED.h"
OS_TID t_phaseA; /* assigned task id of task: phase_a */
OS_TID t_lcd; /* assigned task id of task: lcd */
#define LED_A 2
#define __FI 1 /* Font index 16x24 */
/*----------------------------------------------------------------------------
* Switch LED on
*---------------------------------------------------------------------------*/
void Switch_On (unsigned char led) {
LED_On (led);
}
/*----------------------------------------------------------------------------
* Switch LED off
*---------------------------------------------------------------------------*/
void Switch_Off (unsigned char led) {
LED_Off (led);
}
/*----------------------------------------------------------------------------
* Task 1 'phaseA': Phase A output
*---------------------------------------------------------------------------*/
__task void phaseA (void) {
for (;;) {
Switch_On (LED_A);
os_dly_wait (100);
Switch_Off(LED_A);
os_dly_wait (100);
}
}
