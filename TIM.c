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
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( TIM_Context );
    }
    while ( 0 );

    return Status;
}

static TIM_Status_t TIM_Context_Cycle( void )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( TIM_Context );
    }
    while ( 0 );

    return Status;
}

static TIM_Status_t TIM_Context_DeInitialize( void )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( TIM_Context );
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

TIM_Status_t TIM_Initialize( TIM_t TIMx )
{
    TIM_Status_t Status = TIM_Status_Success;
    TIM_Status_t TIM_Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( TIMx=%d )", __FUNCTION__, TIMx );

        if ( ( Status = TIM_Context_Initialize( ) ) != TIM_Status_Success )
        {
            break;
        }

        for ( TIM_t TIM_x = TIM_Null; TIM_x < TIM_Count; ++TIM_x )
        {
            if ( TIMx != TIM_All && TIMx != TIM_x )
            {
                continue;
            }

            if ( ( TIM_Status = TIM_Port_Initialize( TIM_x ) ) != TIM_Status_Success )
            {
                Status = TIM_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_Cycle( TIM_t TIMx )
{
    TIM_Status_t Status = TIM_Status_Success;
    TIM_Status_t TIM_Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( TIMx=%d )", __FUNCTION__, TIMx );

        if ( ( Status = TIM_Context_Cycle( ) ) != TIM_Status_Success )
        {
            break;
        }

        for ( TIM_t TIM_x = TIM_Null; TIM_x < TIM_Count; ++TIM_x )
        {
            if ( TIMx != TIM_All && TIMx != TIM_x )
            {
                continue;
            }

            if ( ( TIM_Status = TIM_Port_Cycle( TIM_x ) ) != TIM_Status_Success )
            {
                Status = TIM_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_DeInitialize( TIM_t TIMx )
{
    TIM_Status_t Status = TIM_Status_Success;
    TIM_Status_t TIM_Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( TIMx=%d )", __FUNCTION__, TIMx );

        for ( TIM_t TIM_x = TIM_Null; TIM_x < TIM_Count; ++TIM_x )
        {
            if ( TIMx != TIM_All && TIMx != TIM_x )
            {
                continue;
            }

            if ( ( TIM_Status = TIM_Port_DeInitialize( TIM_x ) ) != TIM_Status_Success )
            {
                Status = TIM_Status;
            }
        }

        if ( ( Status = TIM_Context_DeInitialize( ) ) != TIM_Status_Success )
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
    TIM_Status_t TIM_Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( TIMx=%d, Timestamp={Weekday=%d, Year=%d, Month=%d, Day=%d, Hour=%d, Minute=%d, Second=%d, Millisecond=%d, Microsecond=%d} )", __FUNCTION__, TIMx, Timestamp.Weekday, Timestamp.Year, Timestamp.Month, Timestamp.Day, Timestamp.Hour, Timestamp.Minute, Timestamp.Second, Timestamp.Millisecond, Timestamp.Microsecond );

        for ( TIM_t TIM_x = TIM_Null; TIM_x < TIM_Count; ++TIM_x )
        {
            if ( TIMx != TIM_All && TIMx != TIM_x )
            {
                continue;
            }

            if ( ( TIM_Status = TIM_Port_SetTimestamp( TIM_x, Timestamp ) ) != TIM_Status_Success )
            {
                Status = TIM_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_GetTimestamp( TIM_t TIMx, TIM_Timestamp_t * Timestamp )
{
    TIM_Status_t Status = TIM_Status_Success;
    TIM_Status_t TIM_Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( TIMx=%d, Timestamp=%p", __FUNCTION__, TIMx, Timestamp );

        if ( ( TIM_Status = TIM_Port_GetTimestamp( TIMx, Timestamp ) ) != TIM_Status_Success )
        {
            Status = TIM_Status;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_IsExpiredTimestamp( TIM_t TIMx, TIM_Timestamp_t * Timestamp )
{
    TIM_Status_t Status = TIM_Status_Success;
    TIM_Status_t TIM_Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( TIMx=%d, Timestamp=%p", __FUNCTION__, TIMx, Timestamp );

        if ( ( TIM_Status = TIM_Port_IsExpiredTimestamp( TIMx, Timestamp ) ) != TIM_Status_Success )
        {
            Status = TIM_Status;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_Timestamp_AddYear( TIM_Timestamp_t * Timestamp, TIM_YearDelta_t Delta )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Timestamp=%p, Delta=%d )", __FUNCTION__, Timestamp, Delta );

        if ( Timestamp->Year != TIM_Year_Unknown )
        {
            if ( Delta > TIM_Year_2099 - Timestamp->Year )
            {
                // MAX exceeded
                Timestamp->Year = TIM_Year_Unknown;
            }
            else
            {
                Timestamp->Year += Delta;
            }
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_Timestamp_AddMonth( TIM_Timestamp_t * Timestamp, TIM_MonthDelta_t Delta )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Timestamp=%p, Delta=%d )", __FUNCTION__, Timestamp, Delta );

        if ( ( Status = TIM_Timestamp_IsValid( Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }

        TIM_YearDelta_t YearDelta = UTIL_MonthToYear( Delta );
        if ( Timestamp->Month != TIM_Month_Unknown )
        {
            Timestamp->Month += UTIL_Modulus( Delta, 12 );
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

TIM_Status_t TIM_Timestamp_AddDay( TIM_Timestamp_t * Timestamp, TIM_DayDelta_t Delta )
{
    // TODO Support -ve Delta
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Timestamp=%p, Delta=%d )", __FUNCTION__, Timestamp, Delta );

        if ( ( Status = TIM_Timestamp_IsValid( Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }

        if ( Timestamp->Weekday != TIM_Weekday_Unknown )
        {
            Timestamp->Weekday += UTIL_Modulus( Delta, 7 );
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
                    Timestamp->Day += Delta;
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
                    if ( Delta > DayMonthEndDelta )
                    {
                        // Delta exceeds current month
                        Delta -= DayMonthEndDelta + 1;
                        Timestamp->Day = TIM_Day_1;
                        TIM_Timestamp_AddMonth( Timestamp, 1 );
                    }
                    else
                    {
                        // Delta exists in the current month
                        Timestamp->Day += Delta;
                        Delta = 0;
                    }
                }
                Status = TIM_Status_Success;
            }
            while ( Delta > 0 );
            // pass through last status reached
            break;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_Timestamp_AddHour( TIM_Timestamp_t * Timestamp, TIM_HourDelta_t Delta )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Timestamp=%p, Delta=%d )", __FUNCTION__, Timestamp, Delta );

        if ( ( Status = TIM_Timestamp_IsValid( Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }

        TIM_DayDelta_t DayDelta = UTIL_HourToDay( Delta );
        if ( Timestamp->Hour != TIM_Hour_Unknown )
        {
            Timestamp->Hour += Delta - UTIL_DayToHour( DayDelta );
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

TIM_Status_t TIM_Timestamp_AddMinute( TIM_Timestamp_t * Timestamp, TIM_MinuteDelta_t Delta )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Timestamp=%p, Delta=%d )", __FUNCTION__, Timestamp, Delta );

        if ( ( Status = TIM_Timestamp_IsValid( Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }

        TIM_HourDelta_t HourDelta = UTIL_MinuteToHour( Delta );
        if ( Timestamp->Minute != TIM_Minute_Unknown )
        {
            Timestamp->Minute += Delta - UTIL_HourToMinute( HourDelta );
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

TIM_Status_t TIM_Timestamp_AddSecond( TIM_Timestamp_t * Timestamp, TIM_SecondDelta_t Delta )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Timestamp=%p, Delta=%d )", __FUNCTION__, Timestamp, Delta );

        if ( ( Status = TIM_Timestamp_IsValid( Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }

        TIM_MinuteDelta_t MinuteDelta = UTIL_SecondToMinute( Delta );
        if ( Timestamp->Second != TIM_Second_Unknown )
        {
            Timestamp->Second += Delta - UTIL_MinuteToSecond( MinuteDelta );
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

TIM_Status_t TIM_Timestamp_AddMillisecond( TIM_Timestamp_t * Timestamp, TIM_MillisecondDelta_t Delta )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Timestamp=%p, Delta=%d )", __FUNCTION__, Timestamp, Delta );

        if ( ( Status = TIM_Timestamp_IsValid( Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }

        TIM_SecondDelta_t SecondDelta = UTIL_MillisecondToSecond( Delta );
        if ( Timestamp->Millisecond != TIM_Millisecond_Unknown )
        {
            Timestamp->Millisecond += Delta - UTIL_SecondToMillisecond( SecondDelta );
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

TIM_Status_t TIM_Timestamp_AddMicrosecond( TIM_Timestamp_t * Timestamp, TIM_MicrosecondDelta_t Delta )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Timestamp=%p, Delta=%d )", __FUNCTION__, Timestamp, Delta );

        if ( ( Status = TIM_Timestamp_IsValid( Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }

        TIM_MillisecondDelta_t MillisecondDelta = UTIL_MicrosecondToMillisecond( Delta );
        if ( Timestamp->Microsecond != TIM_Microsecond_Unknown )
        {
            Timestamp->Microsecond += Delta - UTIL_MillisecondToMicrosecond( MillisecondDelta );
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
    TIM_Status_t Status = TIM_Status_Success;

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

const char TIM_VERSION[] = "0.0.0.v20260524-1454";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
