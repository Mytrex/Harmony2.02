/*******************************************************************************
  MPLAB Harmony System Configuration Header

  File Name:
    system_config.h

  Summary:
    Build-time configuration header for the system defined by this MPLAB Harmony
    project.

  Description:
    An MPLAB Project may have multiple configurations.  This file defines the
    build-time options for a single configuration.

  Remarks:
    This configuration header must not define any prototypes or data
    definitions (or include any files that do).  It only provides macro
    definitions for build-time configuration options that are not instantiated
    until used by another MPLAB Harmony module or application.
    
    Created with MPLAB Harmony Version 2.02
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef _SYSTEM_CONFIG_H
#define _SYSTEM_CONFIG_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/*  This section Includes other configuration headers necessary to completely
    define this configuration.
*/
#include "bsp.h"


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END 

// *****************************************************************************
// *****************************************************************************
// Section: System Service Configuration
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/* Common System Service Configuration Options
*/
#define SYS_VERSION_STR           "2.02"
#define SYS_VERSION               20200

// *****************************************************************************
/* Clock System Service Configuration Options
*/
#define SYS_CLK_FREQ                        80000000ul
#define SYS_CLK_BUS_PERIPHERAL_1            80000000ul
#define SYS_CLK_UPLL_BEFORE_DIV2_FREQ       48000000ul
#define SYS_CLK_CONFIG_PRIMARY_XTAL         8000000ul
#define SYS_CLK_CONFIG_SECONDARY_XTAL       32768ul
#define SYS_CLK_CONFIG_FREQ_ERROR_LIMIT     10
#define SYS_CLK_WAIT_FOR_SWITCH             true
#define SYS_CLK_ON_WAIT                     OSC_ON_WAIT_IDLE 

/*** Ports System Service Configuration ***/
#define SYS_PORT_AD1PCFG        ~0xffff
#define SYS_PORT_CNPUE          0x98000
#define SYS_PORT_CNEN           0x0
#define SYS_PORT_A_TRIS         0xFF00
#define SYS_PORT_A_LAT          0x0000
#define SYS_PORT_A_ODC          0x0000

#define SYS_PORT_B_TRIS         0xFFFF
#define SYS_PORT_B_LAT          0x0000
#define SYS_PORT_B_ODC          0x0000

#define SYS_PORT_C_TRIS         0xFFFF
#define SYS_PORT_C_LAT          0x0000
#define SYS_PORT_C_ODC          0x0000

#define SYS_PORT_D_TRIS         0xFFFF
#define SYS_PORT_D_LAT          0x0000
#define SYS_PORT_D_ODC          0x0000

#define SYS_PORT_E_TRIS         0xFFFF
#define SYS_PORT_E_LAT          0x0000
#define SYS_PORT_E_ODC          0x0000

#define SYS_PORT_F_TRIS         0xFFFF
#define SYS_PORT_F_LAT          0x0000
#define SYS_PORT_F_ODC          0x0000

#define SYS_PORT_G_TRIS         0xFFFF
#define SYS_PORT_G_LAT          0x0000
#define SYS_PORT_G_ODC          0x0000


/*** Interrupt System Service Configuration ***/
#define SYS_INT                     true

// *****************************************************************************
// *****************************************************************************
// Section: Driver Configuration
// *****************************************************************************
// *****************************************************************************

/*** NVM Driver Configuration ***/

#define DRV_NVM_INSTANCES_NUMBER     	1
#define DRV_NVM_CLIENTS_NUMBER        	1
#define DRV_NVM_BUFFER_OBJECT_NUMBER  	5

#define DRV_NVM_INTERRUPT_MODE        	true
#define DRV_NVM_INTERRUPT_SOURCE      	INT_SOURCE_FLASH_CONTROL

#define DRV_NVM_MEDIA_SIZE              32
#define DRV_NVM_MEDIA_START_ADDRESS     0x9D010000

#define DRV_NVM_ERASE_WRITE_ENABLE




// *****************************************************************************
/* USART Driver Configuration Options
*/
#define DRV_USART_INTERRUPT_MODE                    true

#define DRV_USART_BYTE_MODEL_SUPPORT                false

#define DRV_USART_READ_WRITE_MODEL_SUPPORT          true

#define DRV_USART_BUFFER_QUEUE_SUPPORT              false

#define DRV_USART_CLIENTS_NUMBER                    1
#define DRV_USART_INSTANCES_NUMBER                  1

#define DRV_USART_PERIPHERAL_ID_IDX0                USART_ID_2
#define DRV_USART_OPER_MODE_IDX0                    DRV_USART_OPERATION_MODE_NORMAL
#define DRV_USART_OPER_MODE_DATA_IDX0               
#define DRV_USART_INIT_FLAG_WAKE_ON_START_IDX0      false
#define DRV_USART_INIT_FLAG_AUTO_BAUD_IDX0          false
#define DRV_USART_INIT_FLAG_STOP_IN_IDLE_IDX0       false
#define DRV_USART_INIT_FLAGS_IDX0                   0
#define DRV_USART_BRG_CLOCK_IDX0                    80000000
#define DRV_USART_BAUD_RATE_IDX0                    9600
#define DRV_USART_LINE_CNTRL_IDX0                   DRV_USART_LINE_CONTROL_8NONE1
#define DRV_USART_HANDSHAKE_MODE_IDX0               DRV_USART_HANDSHAKE_NONE
#define DRV_USART_XMIT_INT_SRC_IDX0                 INT_SOURCE_USART_2_TRANSMIT
#define DRV_USART_RCV_INT_SRC_IDX0                  INT_SOURCE_USART_2_RECEIVE
#define DRV_USART_ERR_INT_SRC_IDX0                  INT_SOURCE_USART_2_ERROR
#define DRV_USART_INT_VECTOR_IDX0                   INT_VECTOR_UART2
#define DRV_USART_INT_PRIORITY_IDX0                 INT_PRIORITY_LEVEL4
#define DRV_USART_INT_SUB_PRIORITY_IDX0             INT_SUBPRIORITY_LEVEL0


#define DRV_USART_POWER_STATE_IDX0                  SYS_MODULE_POWER_RUN_FULL


// *****************************************************************************
// *****************************************************************************
// Section: Middleware & Other Library Configuration
// *****************************************************************************
// *****************************************************************************

/*** USB Driver Configuration ***/


/* Enables Device Support */
#define DRV_USBFS_DEVICE_SUPPORT      true

/* Disable Device Support */
#define DRV_USBFS_HOST_SUPPORT      false

/* Maximum USB driver instances */
#define DRV_USBFS_INSTANCES_NUMBER    1


/* Interrupt mode enabled */
#define DRV_USBFS_INTERRUPT_MODE      true


/* Number of Endpoints used */
#define DRV_USBFS_ENDPOINTS_NUMBER    4




/*** USB Device Stack Configuration ***/






#define USB_DEVICE_MSD_NUM_SECTOR_BUFFERS 1




/* The USB Device Layer will not initialize the USB Driver */
#define USB_DEVICE_DRIVER_INITIALIZE_EXPLICIT

/* Maximum device layer instances */
#define USB_DEVICE_INSTANCES_NUMBER     1

/* EP0 size in bytes */
#define USB_DEVICE_EP0_BUFFER_SIZE      8










/* Maximum instances of CDC function driver */
#define USB_DEVICE_CDC_INSTANCES_NUMBER     1










/* CDC Transfer Queue Size for both read and
   write. Applicable to all instances of the
   function driver */
#define USB_DEVICE_CDC_QUEUE_DEPTH_COMBINED 3


/* Number of MSD Function driver instances in the application */
#define USB_DEVICE_MSD_INSTANCES_NUMBER 1

/* Number of Logical Units */
#define USB_DEVICE_MSD_LUNS_NUMBER      1

/* Size of disk image (in KB) in Program Flash Memory */
#define DRV_NVM_BLOCK_MEMORY_SIZE       36



// *****************************************************************************
/* BSP Configuration Options
*/
#define BSP_OSC_FREQUENCY 8000000

#define APP_USB_LED_1 BSP_LED_3
#define APP_USB_LED_2 BSP_LED_4
#define APP_USB_LED_3 BSP_LED_5

// *****************************************************************************
// *****************************************************************************
// Section: Application Configuration
// *****************************************************************************
// *****************************************************************************
/*** Application Defined Pins ***/

/*** Functions for BSP_LED_3 pin ***/
#define BSP_LED_3Toggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_0)
#define BSP_LED_3On() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_0)
#define BSP_LED_3Off() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_0)
#define BSP_LED_3StateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_0)

/*** Functions for BSP_LED_4 pin ***/
#define BSP_LED_4Toggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_1)
#define BSP_LED_4On() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_1)
#define BSP_LED_4Off() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_1)
#define BSP_LED_4StateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_1)

/*** Functions for BSP_LED_5 pin ***/
#define BSP_LED_5Toggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_2)
#define BSP_LED_5On() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_2)
#define BSP_LED_5Off() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_2)
#define BSP_LED_5StateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_2)

/*** Functions for BSP_LED_6 pin ***/
#define BSP_LED_6Toggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3)
#define BSP_LED_6On() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3)
#define BSP_LED_6Off() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3)
#define BSP_LED_6StateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3)

/*** Functions for BSP_LED_7 pin ***/
#define BSP_LED_7Toggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_4)
#define BSP_LED_7On() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_4)
#define BSP_LED_7Off() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_4)
#define BSP_LED_7StateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_4)

/*** Functions for BSP_LED_8 pin ***/
#define BSP_LED_8Toggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_5)
#define BSP_LED_8On() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_5)
#define BSP_LED_8Off() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_5)
#define BSP_LED_8StateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_5)

/*** Functions for BSP_LED_9 pin ***/
#define BSP_LED_9Toggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_6)
#define BSP_LED_9On() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_6)
#define BSP_LED_9Off() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_6)
#define BSP_LED_9StateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_6)

/*** Functions for BSP_LED_10 pin ***/
#define BSP_LED_10Toggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_7)
#define BSP_LED_10On() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_7)
#define BSP_LED_10Off() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_7)
#define BSP_LED_10StateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_7)

/*** Functions for BSP_SWITCH_4 pin ***/
#define BSP_SWITCH_4StateGet() PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_13)

/*** Functions for BSP_SWITCH_3 pin ***/
#define BSP_SWITCH_3StateGet() PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_6)

/*** Functions for BSP_SWITCH_6 pin ***/
#define BSP_SWITCH_6StateGet() PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_7)


/*** Application Instance 0 Configuration ***/

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // _SYSTEM_CONFIG_H
/*******************************************************************************
 End of File
*/