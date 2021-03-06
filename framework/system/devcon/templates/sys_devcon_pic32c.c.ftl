/*******************************************************************************
  Device Control System Service Implementation

  Company:
    Microchip Technology Inc.

  File Name:
    sys_devcon.c

  Summary:
    Device Control System Service implementation for PIC32C devices.

  Description:
    The DEVCON system service provides a simple interface to manage the Device 
    Control module on Microchip PIC32C microcontrollers. This file Implements the 
    core interface routines for the Device Control system service. While building 
    the system service from source, ALWAYS include this file in the build for 
    PIC32C devices.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2016 released Microchip Technology Inc.  All rights reserved.

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
//DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "system/devcon/src/sys_devcon_local_pic32c.h"


// *****************************************************************************
// *****************************************************************************
// Section: Variable Definitions
// *****************************************************************************
// *****************************************************************************

/* System Device Control Instance */
SYS_DEVCON_OBJECT sysDevconObj;


// *****************************************************************************
// *****************************************************************************
// Section: SYS DEVCON Module Initialization Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    SYS_MODULE_OBJ SYS_DEVCON_Initialize( const SYS_MODULE_INDEX           index,
                                          const SYS_MODULE_INIT * const    init )

  Summary:
    Initializes data for the instance of the Device Control module and opens
    the specific module instance.

  Description:
    This function initializes the instance of the Device Control module,
    using the specified initialization data. It also initializes any
    internal data structures.

  Remarks:
    This routine should only be called once during system initialization
    unless SYS_DEVCON_Deinitialize is first called to deinitialize the device
    instance before reinitializing it. If the system was already initialized
    it safely returns without causing any disturbance.
*/

SYS_MODULE_OBJ SYS_DEVCON_Initialize( const SYS_MODULE_INDEX index,
                                      const SYS_MODULE_INIT * const init )
{
    sysDevconObj.status = SYS_STATUS_READY;

    sysDevconObj.state = SYS_DEVCON_STATE_READY;

    return (SYS_MODULE_OBJ)SYS_DEVCON_INDEX_0;
}


// *****************************************************************************
/* Function:
    void SYS_DEVCON_Reinitialize( SYS_MODULE_OBJ                  object,
                                  const SYS_MODULE_INIT * const   init )

   Summary:
    Reinitializes and refreshes the hardware for the instance of the Device 
    Control module.

   Description:
    This function reinitializes the instance of the Device Control module using 
    the supplied data. It modifies the internal data structure.

   Remarks:
    This operation uses the same initialization data structure as the
    SYS_DEVCON_Initialize operation. This operation can be used to change the
    power state of a DEVCON module. This function can be called multiple times
    to reinitialize the module. This operation uses the same initialization
    data structure as the Initialize operation. This operation can also be
    used to refresh the hardware registers as defined by the initialization
    data.
*/

void SYS_DEVCON_Reinitialize( SYS_MODULE_OBJ object,
                              const SYS_MODULE_INIT * const init )
{
    sysDevconObj.status = SYS_STATUS_READY;

    sysDevconObj.state = SYS_DEVCON_STATE_READY;
}


// *****************************************************************************
/* Function:
    void SYS_DEVCON_Deinitialize( SYS_MODULE_OBJ object )

  Summary:
    Deinitializes the specific module instance of the DEVCON module

  Description:
    This function deinitializes the specific module instance disabling its operation 
    (and any hardware for driver modules). Resets all of the internal data
    structures and fields for the specified instance to the default settings.

  Remarks:
    Once the Initialize operation has been called, the Deinitialize
    operation must be called before the Initialize operation can be called
    again.
*/

void SYS_DEVCON_Deinitialize( SYS_MODULE_OBJ object )
{
    sysDevconObj.status = SYS_STATUS_UNINITIALIZED;
}


// *****************************************************************************
/* Function:
    SYS_STATUS SYS_DEVCON_Status( SYS_MODULE_OBJ object )

  Summary:
    Returns status of the specific instance of the Device Control module.

  Description:
    This function returns the status of the specific module instance.

  Remarks:
    None.
*/

SYS_STATUS SYS_DEVCON_Status( SYS_MODULE_OBJ object )
{
    return sysDevconObj.status; 
}


// *****************************************************************************
/* Function:
    void SYS_DEVCON_Tasks( SYS_MODULE_OBJ object )

  Summary:
    Maintains the system Device Control state machine.

  Description:
    This function is used to maintain the system Device Control internal state machine.

  Remarks:
    This function is normally not called directly by an application.  It is
    called by the system's Tasks routine (SYS_Tasks) or by the appropriate raw
    ISR.
*/

void SYS_DEVCON_Tasks( SYS_MODULE_OBJ object )
{
    switch (sysDevconObj.state)
    {
        case SYS_DEVCON_STATE_INIT:
        case SYS_DEVCON_STATE_BUSY:
        case SYS_DEVCON_STATE_READY:
        default:
            break;
    }
}

    
// *****************************************************************************
// *****************************************************************************
// Section: SYS DEVCON Client Setup Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void SYS_DEVCON_SystemUnlock( void )

   Remarks:
    See sys_devcon.h.
*/

void SYS_DEVCON_SystemUnlock( void )
{
    return;
}


// *****************************************************************************
/* Function:
    void SYS_DEVCON_SystemLock( void )

  Remarks:
    See sys_devcon.h.
*/

void SYS_DEVCON_SystemLock( void )
{
    return;
}


// *****************************************************************************
/* Function:
    void SYS_DEVCON_JTAGEnable( void )

  Remarks:
    See sys_devcon.h.
*/

void SYS_DEVCON_JTAGEnable( void )
{
    return;
}


// *****************************************************************************
/* Function:
    void SYS_DEVCON_JTAGDisable( void )

  Remarks:
    See sys_devcon.h.
*/

void SYS_DEVCON_JTAGDisable( void )
{
    return;
}


// *****************************************************************************
/* Function:
    void SYS_DEVCON_TraceEnable( void )

  Remarks:
    See sys_devcon.h.
*/

void SYS_DEVCON_TraceEnable( void )
{
    return;
}


// *****************************************************************************
/* Function:
    void SYS_DEVCON_TraceDisable( void )

  Remarks:
    See sys_devcon.h.
*/

void SYS_DEVCON_TraceDisable( void )
{
    return;
}


// *****************************************************************************
/* Function:
    void SYS_DEVCON_PowerModeEnter(SYS_POWER_MODE pwrMode)

  Remarks:
     See sys_devcon.h.
*/

void SYS_DEVCON_PowerModeEnter( SYS_POWER_MODE pwrMode )
{
    return;
}


/*******************************************************************************
 End of File
*/
