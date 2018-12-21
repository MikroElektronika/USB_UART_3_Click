/*
Example for USBUART3 Click

    Date          : maj 2018.
    Author        : Katarina Perendic

Test configuration STM32 :
    
    MCU              : STM32F107VCT6
    Dev. Board       : EasyMx PRO v7 for STM32
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Intializes UART module
- Application Initialization - Driver intialization
- Application Task - (code snippet) - Checks if new data byte have received in rx buffer (ready for reading),
  and if ready than reads one byte from rx buffer. In second case aplication task writes
  message data via UART.

*/

#include "Click_USBUART3_types.h"
#include "Click_USBUART3_config.h"

const uint8_t MESSAGE_DATA[9] = { 'M', 'i', 'k', 'r', 'o', 'E', 13, 10, 0 };

void systemInit()
{
    mikrobus_uartInit( _MIKROBUS1, &_USBUART3_UART_CFG[0] );
    mikrobus_logInit( _MIKROBUS1, 9600 );
    Delay_ms( 100 );
}

void applicationInit()
{
    usbuart3_uartDriverInit( (T_USBUART3_P)&_MIKROBUS1_GPIO, (T_USBUART3_P)&_MIKROBUS1_UART );
    mikrobus_logWrite( "Initialized", _LOG_LINE );
    Delay_ms( 100 );
}

void applicationTask()
{
    char tmp;
    uint8_t rdyFlag;

// RECEIVER - UART polling 

    rdyFlag = usbuart3_byteReady();

    if (1 == rdyFlag)
    {
        tmp = usbuart3_readByte();
        mikrobus_logWrite( &tmp, _LOG_BYTE );
    }

// TRANSMITER - TX each 2 sec

 /*   for (tmp = 0; tmp < 9; tmp++)
    {
        usbuart3_writeByte( MESSAGE_DATA[tmp] );
        mikrobus_logWrite( "MESSAGE SENT", _LOG_LINE );
    }
    Delay_ms(2000);*/

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