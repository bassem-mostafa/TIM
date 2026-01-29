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

typedef struct TIM_Context
{
    TIM_Instance_t Instance[ TIM_Count ];
} TIM_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static TIM_Status_t TIM_Context_Initialize( void );
static TIM_Status_t TIM_Context_Cycle( void );
static TIM_Status_t TIM_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static TIM_Context_t TIM_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static TIM_Status_t TIM_Context_Initialize( void )
{
    TIM_Status_t Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( void )", __FUNCTION__ );
        for ( TIM_t TIM_x = TIM_Null; TIM_x < TIM_Count; ++TIM_x )
        {
            TIM_Context.Instance[ TIM_x ].TIMx = TIM_x;
            if ( ( Status = TIM_Instance_Initialize( &TIM_Context.Instance[ TIM_x ] ) ) != TIM_Status_Success )
            {
                TIM_Warning( "TIM_%d Initialize Failed: Status %d", TIM_x, Status );
            }
        }
        Status = TIM_Status_Success;
    }
    while ( 0 );
    return Status;
}

static TIM_Status_t TIM_Context_Cycle( void )
{
    TIM_Status_t Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( void )", __FUNCTION__ );
        for ( TIM_t TIM_x = TIM_Null; TIM_x < TIM_Count; ++TIM_x )
        {
            if ( ( Status = TIM_Instance_Cycle( &TIM_Context.Instance[ TIM_x ] ) ) != TIM_Status_Success )
            {
                TIM_Warning( "TIM_%d Cycle Failed: Status %d", TIM_x, Status );
            }
        }
        Status = TIM_Status_Success;
    }
    while ( 0 );
    return Status;
}

static TIM_Status_t TIM_Context_DeInitialize( void )
{
    TIM_Status_t Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( void )", __FUNCTION__ );
        for ( TIM_t TIM_x = TIM_Null; TIM_x < TIM_Count; ++TIM_x )
        {
            if ( ( Status = TIM_Instance_DeInitialize( &TIM_Context.Instance[ TIM_x ] ) ) != TIM_Status_Success )
            {
                TIM_Warning( "TIM_%d DeInitialize Failed: Status %d", TIM_x, Status );
            }
        }
        Status = TIM_Status_Success;
    }
    while ( 0 );
    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

TIM_Status_t TIM_Initialize( TIM_t TIMx )
{
    TIM_Status_t Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( void )", __FUNCTION__ );
        Status = TIM_Context_Initialize( );
    }
    while ( 0 );
    return Status;
}

TIM_Status_t TIM_Cycle( TIM_t TIMx )
{
    TIM_Status_t Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( void )", __FUNCTION__ );
        Status = TIM_Context_Cycle( );
    }
    while ( 0 );
    return Status;
}

TIM_Status_t TIM_DeInitialize( TIM_t TIMx )
{
    TIM_Status_t Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( void )", __FUNCTION__ );
        Status = TIM_Context_DeInitialize( );
    }
    while ( 0 );
    return Status;
}

TIM_Status_t TIM_SetTimestamp( TIM_t TIMx, TIM_Timestamp_t Timestamp )
{
    TIM_Status_t Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( void )", __FUNCTION__ );
        if ( ( Status = TIM_IsValid( TIMx ) ) != TIM_Status_Success )
        {
            break;
        }
        TIM_Instance_t * Instance = &TIM_Context.Instance[ TIMx ];
        Status = TIM_Instance_SetTimestamp( Instance, Timestamp );
    }
    while ( 0 );
    return Status;
}

TIM_Status_t TIM_GetTimestamp( TIM_t TIMx, TIM_Timestamp_t * Timestamp )
{
    TIM_Status_t Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( void )", __FUNCTION__ );
        if ( ( Status = TIM_IsValid( TIMx ) ) != TIM_Status_Success )
        {
            break;
        }
        TIM_Instance_t * Instance = &TIM_Context.Instance[ TIMx ];
        Status = TIM_Instance_GetTimestamp( Instance, Timestamp );
    }
    while ( 0 );
    return Status;
}

TIM_Status_t TIM_IsExpiredTimestamp( TIM_t TIMx, TIM_Timestamp_t * Timestamp )
{
    TIM_Status_t Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( void )", __FUNCTION__ );
        if ( ( Status = TIM_IsValid( TIMx ) ) != TIM_Status_Success )
        {
            break;
        }
        TIM_Instance_t * Instance = &TIM_Context.Instance[ TIMx ];
        Status = TIM_Instance_IsExpiredTimestamp( Instance, Timestamp );
    }
    while ( 0 );
    return Status;
}

TIM_Status_t TIM_Timestamp_AddYear( TIM_Timestamp_t * Timestamp, TIM_YearDelta_t YearDelta )
{
    TIM_Status_t Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Timestamp=%p, YearDelta=%d )", __FUNCTION__, Timestamp, YearDelta );
        if ( ( Status = TIM_Timestamp_IsValid( Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }
        if ( Timestamp->Year != TIM_Year_Unknown )
        {
            if ( YearDelta > TIM_Year_2099 - Timestamp->Year )
            {
                // MAX exceeded
                Timestamp->Year = TIM_Year_Unknown;
            }
            else
            {
                Timestamp->Year += YearDelta;
            }
        }
        Status = TIM_Status_Success;
    }
    while ( 0 );
    return Status;
}

TIM_Status_t TIM_Timestamp_AddMonth( TIM_Timestamp_t * Timestamp, TIM_MonthDelta_t MonthDelta )
{
    TIM_Status_t Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Timestamp=%p, MonthDelta=%d )", __FUNCTION__, Timestamp, MonthDelta );
        if ( ( Status = TIM_Timestamp_IsValid( Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }
        TIM_YearDelta_t YearDelta = UTIL_MonthToYear( MonthDelta );
        if ( Timestamp->Month != TIM_Month_Unknown )
        {
            Timestamp->Month += UTIL_Modulus( MonthDelta, 12 );
            if ( Timestamp->Month > TIM_Month_December )
            {
                Timestamp->Month -= TIM_Month_December;
                YearDelta++;
            }
        }
        Status = TIM_Timestamp_AddYear( Timestamp, YearDelta );
    }
    while ( 0 );
    return Status;
}

TIM_Status_t TIM_Timestamp_AddDay( TIM_Timestamp_t * Timestamp, TIM_DayDelta_t DayDelta )
{
    // TODO Support -ve DayDelta
    TIM_Status_t Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Timestamp=%p, DayDelta=%d )", __FUNCTION__, Timestamp, DayDelta );
        if ( ( Status = TIM_Timestamp_IsValid( Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }
        if ( Timestamp->Weekday != TIM_Weekday_Unknown )
        {
            Timestamp->Weekday += UTIL_Modulus( DayDelta, 7 );
            if ( Timestamp->Weekday > TIM_Weekday_Friday )
            {
                Timestamp->Weekday -= 1 + TIM_Weekday_Friday;
            }
        }
        if ( Timestamp->Day != TIM_Day_Unknown )
        {
            do
            {
                TIM_Day_t DayMonthEnd = TIM_Day_Unknown;
                if ( ( Status = TIM_Timestamp_GetMonthLastDay( Timestamp, &DayMonthEnd ) ) != TIM_Status_Success )
                {
                    break;
                }
                if ( DayMonthEnd == TIM_Day_Unknown )
                {
                    // Couldn't determine the end day of the month
                    // (ex: year or/and month is/are unknown )
                    Timestamp->Day += DayDelta;
                    if ( Timestamp->Day > TIM_Day_31 )
                    {
                        // MAX exceeded
                        Timestamp->Day = TIM_Day_Unknown;
                    }
                }
                else
                {
                    TIM_DayDelta_t DayMonthEndDelta = 0;
                    if ( ( Status = TIM_Timestamp_GetMonthLastDayDelta( Timestamp, &DayMonthEndDelta ) ) != TIM_Status_Success )
                    {
                        // Shouldn't fail !!
                        break;
                    }
                    if ( DayDelta > DayMonthEndDelta )
                    {
                        // Delta exceeds current month
                        DayDelta -= DayMonthEndDelta + 1;
                        Timestamp->Day = TIM_Day_1;
                        TIM_Timestamp_AddMonth( Timestamp, 1 );
                    }
                    else
                    {
                        // Delta exists in the current month
                        Timestamp->Day += DayDelta;
                        DayDelta = 0;
                    }
                }
                Status = TIM_Status_Success;
            }
            while ( DayDelta > 0 );
            // pass through last status reached
            break;
        }
        Status = TIM_Status_Success;
    }
    while ( 0 );
    return Status;
}

TIM_Status_t TIM_Timestamp_AddHour( TIM_Timestamp_t * Timestamp, TIM_HourDelta_t HourDelta )
{
    TIM_Status_t Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Timestamp=%p, HourDelta=%d )", __FUNCTION__, Timestamp, HourDelta );
        if ( ( Status = TIM_Timestamp_IsValid( Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }
        TIM_DayDelta_t DayDelta = UTIL_HourToDay( HourDelta );
        if ( Timestamp->Hour != TIM_Hour_Unknown )
        {
            Timestamp->Hour += HourDelta - UTIL_DayToHour( DayDelta );
            if ( Timestamp->Hour > TIM_Hour_23 )
            {
                Timestamp->Hour -= 1 + TIM_Hour_23;
                DayDelta++;
            }

            if ( Timestamp->Hour < TIM_Hour_00 )
            {
                Timestamp->Hour += 1 + TIM_Hour_23;
                DayDelta--;
            }
        }
        Status = TIM_Timestamp_AddDay( Timestamp, DayDelta );
    }
    while ( 0 );
    return Status;
}

TIM_Status_t TIM_Timestamp_AddMinute( TIM_Timestamp_t * Timestamp, TIM_MinuteDelta_t MinuteDelta )
{
    TIM_Status_t Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Timestamp=%p, MinuteDelta=%d )", __FUNCTION__, Timestamp, MinuteDelta );
        if ( ( Status = TIM_Timestamp_IsValid( Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }
        TIM_HourDelta_t HourDelta = UTIL_MinuteToHour( MinuteDelta );
        if ( Timestamp->Minute != TIM_Minute_Unknown )
        {
            Timestamp->Minute += MinuteDelta - UTIL_HourToMinute( HourDelta );
            if ( Timestamp->Minute > TIM_Minute_59 )
            {
                Timestamp->Minute -= 1 + TIM_Minute_59;
                HourDelta++;
            }

            if ( Timestamp->Minute < TIM_Minute_00 )
            {
                Timestamp->Minute += 1 + TIM_Minute_59;
                HourDelta--;
            }
        }
        Status = TIM_Timestamp_AddHour( Timestamp, HourDelta );
    }
    while ( 0 );
    return Status;
}

TIM_Status_t TIM_Timestamp_AddSecond( TIM_Timestamp_t * Timestamp, TIM_SecondDelta_t SecondDelta )
{
    TIM_Status_t Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Timestamp=%p, SecondDelta=%d )", __FUNCTION__, Timestamp, SecondDelta );
        if ( ( Status = TIM_Timestamp_IsValid( Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }
        TIM_MinuteDelta_t MinuteDelta = UTIL_SecondToMinute( SecondDelta );
        if ( Timestamp->Second != TIM_Second_Unknown )
        {
            Timestamp->Second += SecondDelta - UTIL_MinuteToSecond( MinuteDelta );
            if ( Timestamp->Second > TIM_Second_59 )
            {
                Timestamp->Second -= 1 + TIM_Second_59;
                MinuteDelta++;
            }

            if ( Timestamp->Second < TIM_Second_00 )
            {
                Timestamp->Second += 1 + TIM_Second_59;
                MinuteDelta--;
            }
        }
        Status = TIM_Timestamp_AddMinute( Timestamp, MinuteDelta );
    }
    while ( 0 );
    return Status;
}

TIM_Status_t TIM_Timestamp_AddMillisecond( TIM_Timestamp_t * Timestamp, TIM_MillisecondDelta_t MillisecondDelta )
{
    TIM_Status_t Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Timestamp=%p, MillisecondDelta=%d )", __FUNCTION__, Timestamp, MillisecondDelta );
        if ( ( Status = TIM_Timestamp_IsValid( Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }
        TIM_SecondDelta_t SecondDelta = UTIL_MillisecondToSecond( MillisecondDelta );
        if ( Timestamp->Millisecond != TIM_Millisecond_Unknown )
        {
            Timestamp->Millisecond += MillisecondDelta - UTIL_SecondToMillisecond( SecondDelta );
            if ( Timestamp->Millisecond > TIM_Millisecond_999 )
            {
                Timestamp->Millisecond -= 1 + TIM_Millisecond_999;
                SecondDelta++;
            }

            if ( Timestamp->Millisecond < TIM_Millisecond_000 )
            {
                Timestamp->Millisecond += 1 + TIM_Millisecond_999;
                SecondDelta--;
            }
        }
        Status = TIM_Timestamp_AddSecond( Timestamp, SecondDelta );
    }
    while ( 0 );
    return Status;
}

TIM_Status_t TIM_Timestamp_AddMicrosecond( TIM_Timestamp_t * Timestamp, TIM_MicrosecondDelta_t MicrosecondDelta )
{
    TIM_Status_t Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Timestamp=%p, MicrosecondDelta=%d )", __FUNCTION__, Timestamp, MicrosecondDelta );
        if ( ( Status = TIM_Timestamp_IsValid( Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }
        TIM_MillisecondDelta_t MillisecondDelta = UTIL_MicrosecondToMillisecond( MicrosecondDelta );
        if ( Timestamp->Microsecond != TIM_Microsecond_Unknown )
        {
            Timestamp->Microsecond += MicrosecondDelta - UTIL_MillisecondToMicrosecond( MillisecondDelta );
            if ( Timestamp->Microsecond > TIM_Microsecond_999 )
            {
                Timestamp->Microsecond -= 1 + TIM_Microsecond_999;
                MillisecondDelta++;
            }

            if ( Timestamp->Microsecond < TIM_Microsecond_000 )
            {
                Timestamp->Microsecond += 1 + TIM_Microsecond_999;
                MillisecondDelta--;
            }
        }
        Status = TIM_Timestamp_AddMillisecond( Timestamp, MillisecondDelta );
    }
    while ( 0 );
    return Status;
}

TIM_Status_t TIM_Timestamp_AddDelta( TIM_Timestamp_t * Timestamp, TIM_Delta_t Delta )
{
    TIM_Status_t Status = TIM_Status_Error;

    do
    {
        TIM_Trace( "%s( Timestamp=%p, Delta=%d )", __FUNCTION__, Timestamp, Delta );

        if ( ( Status = TIM_Timestamp_IsValid( Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }

        if ( ( Status = TIM_Timestamp_AddMicrosecond( Timestamp, Delta.Microsecond ) ) != TIM_Status_Success )
        {
            break;
        }

        if ( ( Status = TIM_Timestamp_AddMillisecond( Timestamp, Delta.Millisecond ) ) != TIM_Status_Success )
        {
            break;
        }

        if ( ( Status = TIM_Timestamp_AddSecond( Timestamp, Delta.Second ) ) != TIM_Status_Success )
        {
            break;
        }

        if ( ( Status = TIM_Timestamp_AddMinute( Timestamp, Delta.Minute ) ) != TIM_Status_Success )
        {
            break;
        }

        if ( ( Status = TIM_Timestamp_AddHour( Timestamp, Delta.Hour ) ) != TIM_Status_Success )
        {
            break;
        }

        if ( ( Status = TIM_Timestamp_AddDay( Timestamp, Delta.Day ) ) != TIM_Status_Success )
        {
            break;
        }

        if ( ( Status = TIM_Timestamp_AddMonth( Timestamp, Delta.Month ) ) != TIM_Status_Success )
        {
            break;
        }

        if ( ( Status = TIM_Timestamp_AddYear( Timestamp, Delta.Year ) ) != TIM_Status_Success )
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

const char TIM_VERSION[] = "0.0.0.v20260130-0032";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
