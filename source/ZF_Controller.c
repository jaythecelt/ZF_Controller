 
/**
 * @file    ZF_Controller.c
 * @brief   Application entry point.
 */
/*
 */

#include "fsl_debug_console.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "fsl_common.h"
#include "fsl_pit.h"
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BOARD_SW_GPIO BOARD_SW1_GPIO
#define BOARD_SW_PORT BOARD_SW1_PORT
#define BOARD_SW_GPIO_PIN BOARD_SW1_GPIO_PIN
#define BOARD_SW_IRQ BOARD_SW1_IRQ
#define BOARD_SW_IRQ_HANDLER BOARD_SW1_IRQ_HANDLER
#define BOARD_SW_NAME BOARD_SW1_NAME

#define PTC1_PIN 1U
#define PTC2_PIN 2U
#define PTB0_PIN 0U
#define PTB1_PIN 1U

#define PIT_IRQ_ID PIT_IRQn
#define PIT_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_BusClk) // Get source clock for PIT driver




/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile bool interrupted = false;
long count = 0;

volatile bool pitIsrFlag = false;

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Interrupt service to handle port C interrupts
 *
 * Overrides PORTC_PORTD_DriverIRQHandler in startup_mkl26z4c.c
 */
void PORTC_PORTD_DriverIRQHandler(void)
{
	/* Get which interrupt pin triggered this call */
	uint32_t intFlags = GPIO_GetPinsInterruptFlags(GPIOC);

//	PRINTF("intFlags: %0x", intFlags );

	/* Clear interrupt flags */
	if ((intFlags >> BOARD_SW_GPIO_PIN) & 1U) {
		// Clear the SW1 interrupt flag
	    GPIO_ClearPinsInterruptFlags(GPIOC, 1U << BOARD_SW_GPIO_PIN);
	}
	if ((intFlags >> PTC1_PIN) & 1U) {
		// Clear external interrupt flag on PTC1.
	    GPIO_ClearPinsInterruptFlags(GPIOC, 1U << PTC1_PIN);
	}
	if ((intFlags >> PTC2_PIN) & 1U) {
		// Clear external interrupt flag on PTC2.
	    GPIO_ClearPinsInterruptFlags(GPIOC, 1U << PTC2_PIN);
	}

    interrupted = true;
}


void PIT_IRQHandler(void)
{
    /* Clear interrupt flag.*/
    PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
    pitIsrFlag = true;
}







/************************** Main *************************************************/
/*!
 * @brief Main function
 */
int main(void)
{
    // Init structure for the input SW1 pin
	gpio_pin_config_t sw_config = {kGPIO_DigitalInput, 0,};

	// Init structure for the external interrupt pins
	gpio_pin_config_t extInt1_config = {kGPIO_DigitalInput, 0,};
    gpio_pin_config_t extInt2_config = {kGPIO_DigitalInput, 0,};

    // Init structure for the output pins
    gpio_pin_config_t led_config = {kGPIO_DigitalOutput, 0,};
    gpio_pin_config_t ptb0_config = {kGPIO_DigitalOutput, 0,};
    gpio_pin_config_t ptb1_config = {kGPIO_DigitalOutput, 0,};

    //Initialize the board
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    /* Init input switch GPIO. */
    PORT_SetPinInterruptConfig(BOARD_SW_PORT, BOARD_SW_GPIO_PIN, kPORT_InterruptFallingEdge);
    GPIO_PinInit(BOARD_SW_GPIO, BOARD_SW_GPIO_PIN, &sw_config);

    /* Init external interrupt on PTC1. */
    PORT_SetPinInterruptConfig(PORTC, PTC1_PIN, kPORT_InterruptFallingEdge);
    GPIO_PinInit(GPIOC, PTC1_PIN, &extInt1_config);

    /* Init external interrupt on PTC2. */
    PORT_SetPinInterruptConfig(PORTC, PTC2_PIN, kPORT_InterruptFallingEdge);
    GPIO_PinInit(GPIOC, PTC2_PIN, &extInt2_config);

    /* Enable the interrupt for port C */
    EnableIRQ(PORTC_PORTD_IRQn);


    /* Init outputs */
    GPIO_PinInit(BOARD_LED_RED_GPIO, BOARD_LED_RED_GPIO_PIN, &led_config); //LED
    GPIO_PinInit(GPIOB, PTB0_PIN, &ptb0_config); // ZFA
    GPIO_PinInit(GPIOB, PTB1_PIN, &ptb1_config); // ZFB


    /* Init PIT */
    pit_config_t pitConfig;
    PIT_GetDefaultConfig(&pitConfig);

    PIT_Init(PIT, &pitConfig);//Init PIT Module

    PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(500U, CLOCK_GetFreq(kCLOCK_BusClk))); //Set timer period for channel 0

    PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable); //Enable timer interrupts for channel 0
    EnableIRQ(PIT_IRQ_ID); //Enable at the NVIC


    while (1)
    {
        if (true == pitIsrFlag)
        {
            PIT_StopTimer(PIT, kPIT_Chnl_0); //Stop channel 0
            GPIO_ClearPinsOutput(GPIOB, (1U << PTB0_PIN) | (1U << PTB1_PIN));
            pitIsrFlag = false;
        }

    	if (interrupted)
        {
            /* Toggle LED. */
            GPIO_TogglePinsOutput(BOARD_LED_RED_GPIO, 1U << BOARD_LED_RED_GPIO_PIN);

            //Pulse the output
            GPIO_SetPinsOutput(GPIOB, (1U << PTB0_PIN) | (1U << PTB1_PIN));
            PIT_StartTimer(PIT, kPIT_Chnl_0); //Timer is stopped in the PIT ISR

            // Reset state
            interrupted = false;
            count++;
        }
    }
}
