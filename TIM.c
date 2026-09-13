// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "TIM.h"
#include "TIM_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

TIM_Status_t TIM_Initialize( TIM_t TIMx )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( TIMx=%d )", __FUNCTION__, TIMx );

        if ( ( Status = TIM_Port_Initialize( TIMx ) ) != TIM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_Cycle( TIM_t TIMx )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( TIMx=%d )", __FUNCTION__, TIMx );

        if ( ( Status = TIM_Port_Cycle( TIMx ) ) != TIM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_DeInitialize( TIM_t TIMx )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( TIMx=%d )", __FUNCTION__, TIMx );

        if ( ( Status = TIM_Port_DeInitialize( TIMx ) ) != TIM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_SetTimestamp( TIM_t TIMx, TIM_Timestamp_t Timestamp )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( TIMx=%d, Timestamp={Weekday=%d, Year=%d, Month=%d, Day=%d, Hour=%d, Minute=%d, Second=%d, Millisecond=%d, Microsecond=%d} )", __FUNCTION__, TIMx, Timestamp.Weekday, Timestamp.Year, Timestamp.Month, Timestamp.Day, Timestamp.Hour, Timestamp.Minute, Timestamp.Second, Timestamp.Millisecond, Timestamp.Microsecond );

        if ( ( Status = TIM_Port_SetTimestamp( TIMx, Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_GetTimestamp( TIM_t TIMx, TIM_Timestamp_t * Timestamp )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( TIMx=%d, Timestamp=%p", __FUNCTION__, TIMx, Timestamp );

        if ( ( Status = TIM_Port_GetTimestamp( TIMx, Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_IsExpiredTimestamp( TIM_t TIMx, TIM_Timestamp_t * Timestamp )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( TIMx=%d, Timestamp=%p", __FUNCTION__, TIMx, Timestamp );

        if ( ( Status = TIM_Port_IsExpiredTimestamp( TIMx, Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_SetOnExpire( TIM_t TIMx, TIM_Timestamp_t * Timestamp, TIM_OnExpire_t OnExpire )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( TIMx=%d, Timestamp=%p, OnExpire={Callback=%p, Context=%p}", __FUNCTION__, TIMx, Timestamp, OnExpire.Callback, OnExpire.Context );

        if ( ( Status = TIM_Port_SetOnExpire( TIMx, Timestamp, OnExpire ) ) != TIM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char TIM_VERSION[] = "0.0.0.v20260913-1832";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
