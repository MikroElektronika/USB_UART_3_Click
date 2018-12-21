#line 1 "D:/Clicks_git/USB_UART_3_Click/SW/example/c/ARM/STM/Click_USBUART3_STM.c"
#line 1 "d:/clicks_git/usb_uart_3_click/sw/example/c/arm/stm/click_usbuart3_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/usb_uart_3_click/sw/example/c/arm/stm/click_usbuart3_config.h"
#line 1 "d:/clicks_git/usb_uart_3_click/sw/example/c/arm/stm/click_usbuart3_types.h"
#line 3 "d:/clicks_git/usb_uart_3_click/sw/example/c/arm/stm/click_usbuart3_config.h"
const uint32_t _USBUART3_UART_CFG[ 4 ] =
{
 9600,
 _UART_8_BIT_DATA,
 _UART_NOPARITY,
 _UART_ONE_STOPBIT
};
#line 1 "d:/clicks_git/usb_uart_3_click/sw/library/__usbuart3_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 78 "d:/clicks_git/usb_uart_3_click/sw/library/__usbuart3_driver.h"
void usbuart3_uartDriverInit( const uint8_t*  gpioObj,  const uint8_t*  uartObj);
#line 90 "d:/clicks_git/usb_uart_3_click/sw/library/__usbuart3_driver.h"
void usbuart3_writeByte(uint8_t input);
#line 99 "d:/clicks_git/usb_uart_3_click/sw/library/__usbuart3_driver.h"
uint8_t usbuart3_readByte();
#line 108 "d:/clicks_git/usb_uart_3_click/sw/library/__usbuart3_driver.h"
uint8_t usbuart3_byteReady();

void usbuart3_reset();

uint8_t usbuart3_getSUSP();
#line 32 "D:/Clicks_git/USB_UART_3_Click/SW/example/c/ARM/STM/Click_USBUART3_STM.c"
const uint8_t MESSAGE_DATA[9] = { 'M', 'i', 'k', 'r', 'o', 'E', 13, 10, 0 };

void systemInit()
{
 mikrobus_uartInit( _MIKROBUS1, &_USBUART3_UART_CFG[0] );
 mikrobus_logInit( _MIKROBUS1, 9600 );
 Delay_ms( 100 );
}

void applicationInit()
{
 usbuart3_uartDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_UART );
 mikrobus_logWrite( "Initialized", _LOG_LINE );
 Delay_ms( 100 );
}

void applicationTask()
{
 char tmp;
 uint8_t rdyFlag;



 rdyFlag = usbuart3_byteReady();

 if (1 == rdyFlag)
 {
 tmp = usbuart3_readByte();
 mikrobus_logWrite( &tmp, _LOG_BYTE );
 }



 for (tmp = 0; tmp < 9; tmp++)
 {
 usbuart3_writeByte( MESSAGE_DATA[tmp] );
 mikrobus_logWrite( "MESSAGE SENT", _LOG_LINE );
 }
 Delay_ms(2000);

}

void main()
{
 systemInit();
 applicationInit();

 while (1)
 {
 applicationTask();
 }
}
