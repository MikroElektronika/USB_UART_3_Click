/*
    __usbuart3_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __usbuart3_driver.h
@brief    USBUART3 Driver
@mainpage USBUART3 Click
@{

@image html sch.jpg

@}

@defgroup   USBUART3
@brief      USBUART3 Click Driver
@{

| Global Library Prefix | **USBUART3** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **maj 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _USBUART3_H_
#define _USBUART3_H_

/** 
 * @macro T_USBUART3_P
 * @brief Driver Abstract type 
 */
#define T_USBUART3_P    const uint8_t*

/** @defgroup USBUART3_COMPILE Compilation Config */              /** @{ */

//  #define   __USBUART3_DRV_SPI__                            /**<     @macro __USBUART3_DRV_SPI__  @brief SPI driver selector */
//  #define   __USBUART3_DRV_I2C__                            /**<     @macro __USBUART3_DRV_I2C__  @brief I2C driver selector */                                          
  #define   __USBUART3_DRV_UART__                           /**<     @macro __USBUART3_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup USBUART3_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup USBUART3_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup USBUART3_INIT Driver Initialization */              /** @{ */

#ifdef   __USBUART3_DRV_SPI__
void usbuart3_spiDriverInit(T_USBUART3_P gpioObj, T_USBUART3_P spiObj);
#endif
#ifdef   __USBUART3_DRV_I2C__
void usbuart3_i2cDriverInit(T_USBUART3_P gpioObj, T_USBUART3_P i2cObj, uint8_t slave);
#endif
#ifdef   __USBUART3_DRV_UART__
void usbuart3_uartDriverInit(T_USBUART3_P gpioObj, T_USBUART3_P uartObj);
#endif
                                                                       /** @} */
/** @defgroup USBUART3_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Write Single Byte
 *
 * @param[in] input 
 *
 * Writes sinle byte.
 */
void usbuart3_writeByte(uint8_t input);

/**
 * @brief Read Single Byte
 *
 * @return received byte
 *
 * Read received byte.
 */
uint8_t usbuart3_readByte();

/**
 * @brief Check for new byte received
 *
 * @retval 0 - no new data / 1 - data ready
 *
 * Checks is there a new byte received.
 */
uint8_t usbuart3_byteReady();

void usbuart3_reset();

uint8_t usbuart3_getSUSP();
                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_USBUART3_STM.c
    @example Click_USBUART3_TIVA.c
    @example Click_USBUART3_CEC.c
    @example Click_USBUART3_KINETIS.c
    @example Click_USBUART3_MSP.c
    @example Click_USBUART3_PIC.c
    @example Click_USBUART3_PIC32.c
    @example Click_USBUART3_DSPIC.c
    @example Click_USBUART3_AVR.c
    @example Click_USBUART3_FT90x.c
    @example Click_USBUART3_STM.mbas
    @example Click_USBUART3_TIVA.mbas
    @example Click_USBUART3_CEC.mbas
    @example Click_USBUART3_KINETIS.mbas
    @example Click_USBUART3_MSP.mbas
    @example Click_USBUART3_PIC.mbas
    @example Click_USBUART3_PIC32.mbas
    @example Click_USBUART3_DSPIC.mbas
    @example Click_USBUART3_AVR.mbas
    @example Click_USBUART3_FT90x.mbas
    @example Click_USBUART3_STM.mpas
    @example Click_USBUART3_TIVA.mpas
    @example Click_USBUART3_CEC.mpas
    @example Click_USBUART3_KINETIS.mpas
    @example Click_USBUART3_MSP.mpas
    @example Click_USBUART3_PIC.mpas
    @example Click_USBUART3_PIC32.mpas
    @example Click_USBUART3_DSPIC.mpas
    @example Click_USBUART3_AVR.mpas
    @example Click_USBUART3_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __usbuart3_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */