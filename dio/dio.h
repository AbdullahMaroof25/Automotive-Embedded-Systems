/******************************************************************************
 * Module: DIO
 *
 * File Name: dio.h
 *
 * Description: Header File for the DIO Driver
 *
 * Author: Ahmed Salah
 *
 *******************************************************************************/

#ifndef DIO_H_
#define DIO_H_

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "dio_types.h"
#include "std_types.h"

/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/
#define NUM_OF_PINS_PER_PORT			(15u)
#define NUM_OF_PORTS					(8u)

/*******************************************************************************
 *                      Global Function Macros                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data Types and Structures                       *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data Prototypes                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Function Prototypes                             *
 *******************************************************************************/
STD_ReturnState DIO_setupPinMode(DIO_PortID portID, DIO_PinID pinID, DIO_PinMode pinMode);
STD_ReturnState DIO_writePin(DIO_PortID portID, DIO_PinID pinID, DIO_PinLevel pinLevel);
STD_ReturnState DIO_togglePin(DIO_PortID portID, DIO_PinID pinID);
STD_ReturnState DIO_readPin(DIO_PortID portID, DIO_PinID pinID, DIO_PinLevel *pinLevel);
STD_ReturnState DIO_activateInternal(DIO_PortID portID, DIO_PinID pinID, DIO_InternalMode internalMode);
STD_ReturnState DIO_setAlternateFunction (DIO_PortID portID, DIO_PinID pinID, DIO_AltFuncID altFunID);

#endif

/*******************************************************************************
 *                      End of File: dio.h                                     *
 *******************************************************************************/
