#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
  kPIN_MUX_DirectionInput = 0U,         /* Input direction */
  kPIN_MUX_DirectionOutput = 1U,        /* Output direction */
  kPIN_MUX_DirectionInputOrOutput = 2U  /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/* PORTA1 (number 23), J1[2]/D0/UART1_RX_TGTMCU */
#define BOARD_INITPINS_DEBUG_UART_RX_PERIPHERAL                            UART0   /*!< Device name: UART0 */
#define BOARD_INITPINS_DEBUG_UART_RX_SIGNAL                                   RX   /*!< UART0 signal: RX */
#define BOARD_INITPINS_DEBUG_UART_RX_PIN_NAME                           UART0_RX   /*!< Pin name */
#define BOARD_INITPINS_DEBUG_UART_RX_LABEL            "J1[2]/D0/UART1_RX_TGTMCU"   /*!< Label */
#define BOARD_INITPINS_DEBUG_UART_RX_NAME                        "DEBUG_UART_RX"   /*!< Identifier name */

/* PORTA2 (number 24), J1[4]/D1/UART1_TX_TGTMCU */
#define BOARD_INITPINS_DEBUG_UART_TX_PERIPHERAL                            UART0   /*!< Device name: UART0 */
#define BOARD_INITPINS_DEBUG_UART_TX_SIGNAL                                   TX   /*!< UART0 signal: TX */
#define BOARD_INITPINS_DEBUG_UART_TX_PIN_NAME                           UART0_TX   /*!< Pin name */
#define BOARD_INITPINS_DEBUG_UART_TX_LABEL            "J1[4]/D1/UART1_TX_TGTMCU"   /*!< Label */
#define BOARD_INITPINS_DEBUG_UART_TX_NAME                        "DEBUG_UART_TX"   /*!< Identifier name */

/* PORTC3 (number 46), SW1 */
#define BOARD_INITPINS_SW1_GPIO                                            GPIOC   /*!< GPIO device name: GPIOC */
#define BOARD_INITPINS_SW1_PORT                                            PORTC   /*!< PORT device name: PORTC */
#define BOARD_INITPINS_SW1_GPIO_PIN                                           3U   /*!< PORTC pin index: 3 */
#define BOARD_INITPINS_SW1_PIN_NAME                                         PTC3   /*!< Pin name */
#define BOARD_INITPINS_SW1_LABEL                                           "SW1"   /*!< Label */
#define BOARD_INITPINS_SW1_NAME                                            "SW1"   /*!< Identifier name */
#define BOARD_INITPINS_SW1_DIRECTION                     kPIN_MUX_DirectionInput   /*!< Direction */

/* PORTE29 (number 17), LED_RED */
#define BOARD_INITPINS_LED_RED_GPIO                                        GPIOE   /*!< GPIO device name: GPIOE */
#define BOARD_INITPINS_LED_RED_PORT                                        PORTE   /*!< PORT device name: PORTE */
#define BOARD_INITPINS_LED_RED_GPIO_PIN                                      29U   /*!< PORTE pin index: 29 */
#define BOARD_INITPINS_LED_RED_PIN_NAME                                    PTE29   /*!< Pin name */
#define BOARD_INITPINS_LED_RED_LABEL                                   "LED_RED"   /*!< Label */
#define BOARD_INITPINS_LED_RED_NAME                                    "LED_RED"   /*!< Identifier name */

/* PORTC1 (number 44), EXT_INT_PTC1 */
#define BOARD_INITPINS_EXT_INT_PTC1_GPIO                                   GPIOC   /*!< GPIO device name: GPIOC */
#define BOARD_INITPINS_EXT_INT_PTC1_PORT                                   PORTC   /*!< PORT device name: PORTC */
#define BOARD_INITPINS_EXT_INT_PTC1_GPIO_PIN                                  1U   /*!< PORTC pin index: 1 */
#define BOARD_INITPINS_EXT_INT_PTC1_PIN_NAME                                PTC1   /*!< Pin name */
#define BOARD_INITPINS_EXT_INT_PTC1_LABEL                         "EXT_INT_PTC1"   /*!< Label */
#define BOARD_INITPINS_EXT_INT_PTC1_NAME                          "EXT_INT_PTC1"   /*!< Identifier name */
#define BOARD_INITPINS_EXT_INT_PTC1_DIRECTION            kPIN_MUX_DirectionInput   /*!< Direction */

/* PORTC2 (number 45), EXT_INT_PTC2 */
#define BOARD_INITPINS_EXT_INT_PTC2_GPIO                                   GPIOC   /*!< GPIO device name: GPIOC */
#define BOARD_INITPINS_EXT_INT_PTC2_PORT                                   PORTC   /*!< PORT device name: PORTC */
#define BOARD_INITPINS_EXT_INT_PTC2_GPIO_PIN                                  2U   /*!< PORTC pin index: 2 */
#define BOARD_INITPINS_EXT_INT_PTC2_PIN_NAME                                PTC2   /*!< Pin name */
#define BOARD_INITPINS_EXT_INT_PTC2_LABEL                         "EXT_INT_PTC2"   /*!< Label */
#define BOARD_INITPINS_EXT_INT_PTC2_NAME                          "EXT_INT_PTC2"   /*!< Identifier name */
#define BOARD_INITPINS_EXT_INT_PTC2_DIRECTION            kPIN_MUX_DirectionInput   /*!< Direction */

/* PORTB0 (number 35), ZFA_PTB0 */
#define BOARD_INITPINS_ZFA_PTB0_GPIO                                       GPIOB   /*!< GPIO device name: GPIOB */
#define BOARD_INITPINS_ZFA_PTB0_PORT                                       PORTB   /*!< PORT device name: PORTB */
#define BOARD_INITPINS_ZFA_PTB0_GPIO_PIN                                      0U   /*!< PORTB pin index: 0 */
#define BOARD_INITPINS_ZFA_PTB0_PIN_NAME                                    PTB0   /*!< Pin name */
#define BOARD_INITPINS_ZFA_PTB0_LABEL                                 "ZFA_PTB0"   /*!< Label */
#define BOARD_INITPINS_ZFA_PTB0_NAME                                  "ZFA_PTB0"   /*!< Identifier name */
#define BOARD_INITPINS_ZFA_PTB0_DIRECTION               kPIN_MUX_DirectionOutput   /*!< Direction */

/* PORTB1 (number 36), ZFA_PTB1 */
#define BOARD_INITPINS_ZFA_PTB1_GPIO                                       GPIOB   /*!< GPIO device name: GPIOB */
#define BOARD_INITPINS_ZFA_PTB1_PORT                                       PORTB   /*!< PORT device name: PORTB */
#define BOARD_INITPINS_ZFA_PTB1_GPIO_PIN                                      1U   /*!< PORTB pin index: 1 */
#define BOARD_INITPINS_ZFA_PTB1_PIN_NAME                                    PTB1   /*!< Pin name */
#define BOARD_INITPINS_ZFA_PTB1_LABEL                                 "ZFA_PTB1"   /*!< Label */
#define BOARD_INITPINS_ZFA_PTB1_NAME                                  "ZFA_PTB1"   /*!< Identifier name */
#define BOARD_INITPINS_ZFA_PTB1_DIRECTION               kPIN_MUX_DirectionOutput   /*!< Direction */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
