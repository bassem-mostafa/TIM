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

TIM_Status_t TIM_Year_IsValid( TIM_Year_t TIM_Year )
{
    TIM_Status_t TIM_Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Year=%d )", __FUNCTION__, TIM_Year );
        if ( TIM_Year != TIM_Year_Unknown
             && ( TIM_Year < TIM_Year_2000
                  || TIM_Year > TIM_Year_2099 ) )
        {
            TIM_Status = TIM_Status_ArgumentInvalid;
            break;
        }
        TIM_Status = TIM_Status_Success;
    }
    while ( 0 );
    return TIM_Status;
}

TIM_Status_t TIM_Year_IsLeap( TIM_Year_t TIM_Year )
{
    TIM_Status_t TIM_Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Year=%d )", __FUNCTION__, TIM_Year );
        if ( TIM_Year == TIM_Year_Unknown )
        {
            TIM_Status = TIM_Status_Error;
            break;
        }
        if ( UTIL_Modulus( TIM_Year - TIM_Year_2000, 4 ) != 0 )
        {
            TIM_Status = TIM_Status_Error;
            break;
        }
        if ( ( UTIL_Modulus( TIM_Year - TIM_Year_2000, 100 ) == 0 )
             && ( UTIL_Modulus( TIM_Year - TIM_Year_2000, 400 ) != 0 ) )
        {
            TIM_Status = TIM_Status_Error;
            break;
        }
        TIM_Status = TIM_Status_Success;
    }
    while ( 0 );
    return TIM_Status;
}

TIM_Status_t TIM_Month_IsValid( TIM_Month_t TIM_Month )
{
    TIM_Status_t TIM_Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Month=%d )", __FUNCTION__, TIM_Month );
        if ( TIM_Month != TIM_Month_Unknown
             && ( TIM_Month < TIM_Month_January
                  || TIM_Month > TIM_Month_December ) )
        {
            TIM_Status = TIM_Status_ArgumentInvalid;
            break;
        }
        TIM_Status = TIM_Status_Success;
    }
    while ( 0 );
    return TIM_Status;
}

TIM_Status_t TIM_Day_IsValid( TIM_Day_t TIM_Day )
{
    TIM_Status_t TIM_Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Day=%d )", __FUNCTION__, TIM_Day );
        if ( TIM_Day != TIM_Day_Unknown
             && ( TIM_Day < TIM_Day_1
                  || TIM_Day > TIM_Day_31 ) )
        {
            TIM_Status = TIM_Status_ArgumentInvalid;
            break;
        }
        TIM_Status = TIM_Status_Success;
    }
    while ( 0 );
    return TIM_Status;
}

TIM_Status_t TIM_Hour_IsValid( TIM_Hour_t TIM_Hour )
{
    TIM_Status_t TIM_Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Hour=%d )", __FUNCTION__, TIM_Hour );
        if ( TIM_Hour != TIM_Hour_Unknown
             && ( TIM_Hour < TIM_Hour_00
                  || TIM_Hour > TIM_Hour_23 ) )
        {
            TIM_Status = TIM_Status_ArgumentInvalid;
            break;
        }
        TIM_Status = TIM_Status_Success;
    }
    while ( 0 );
    return TIM_Status;
}

TIM_Status_t TIM_Minute_IsValid( TIM_Minute_t TIM_Minute )
{
    TIM_Status_t TIM_Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Minute=%d )", __FUNCTION__, TIM_Minute );
        if ( TIM_Minute != TIM_Minute_Unknown
             && ( TIM_Minute < TIM_Minute_00
                  || TIM_Minute > TIM_Minute_59 ) )
        {
            TIM_Status = TIM_Status_ArgumentInvalid;
            break;
        }
        TIM_Status = TIM_Status_Success;
    }
    while ( 0 );
    return TIM_Status;
}

TIM_Status_t TIM_Second_IsValid( TIM_Second_t TIM_Second )
{
    TIM_Status_t TIM_Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Second=%d )", __FUNCTION__, TIM_Second );
        if ( TIM_Second != TIM_Second_Unknown
             && ( TIM_Second < TIM_Second_00
                  || TIM_Second > TIM_Second_59 ) )
        {
            TIM_Status = TIM_Status_ArgumentInvalid;
            break;
        }
        TIM_Status = TIM_Status_Success;
    }
    while ( 0 );
    return TIM_Status;
}

TIM_Status_t TIM_Millisecond_IsValid( TIM_Millisecond_t TIM_Millisecond )
{
    TIM_Status_t TIM_Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Millisecond=%d )", __FUNCTION__, TIM_Millisecond );
        if ( TIM_Millisecond != TIM_Millisecond_Unknown
             && ( TIM_Millisecond < TIM_Millisecond_000
                  || TIM_Millisecond > TIM_Millisecond_999 ) )
        {
            TIM_Status = TIM_Status_ArgumentInvalid;
            break;
        }
        TIM_Status = TIM_Status_Success;
    }
    while ( 0 );
    return TIM_Status;
}

TIM_Status_t TIM_Microsecond_IsValid( TIM_Microsecond_t TIM_Microsecond )
{
    TIM_Status_t TIM_Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Microsecond=%d )", __FUNCTION__, TIM_Microsecond );
        if ( TIM_Microsecond != TIM_Microsecond_Unknown
             && ( TIM_Microsecond < TIM_Microsecond_000
                  || TIM_Microsecond > TIM_Microsecond_999 ) )
        {
            TIM_Status = TIM_Status_ArgumentInvalid;
            break;
        }
        TIM_Status = TIM_Status_Success;
    }
    while ( 0 );
    return TIM_Status;
}

TIM_Status_t TIM_Weekday_IsValid( TIM_Weekday_t TIM_Weekday )
{
    TIM_Status_t TIM_Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Weekday=%d )", __FUNCTION__, TIM_Weekday );
        if ( TIM_Weekday != TIM_Weekday_Unknown
             && ( TIM_Weekday < TIM_Weekday_Saturday
                  || TIM_Weekday > TIM_Weekday_Friday ) )
        {
            TIM_Status = TIM_Status_ArgumentInvalid;
            break;
        }
        TIM_Status = TIM_Status_Success;
    }
    while ( 0 );
    return TIM_Status;
}

TIM_Status_t TIM_Timestamp_IsValid( TIM_Timestamp_t * TIM_Timestamp )
{
    TIM_Status_t TIM_Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Timestamp=%p )", __FUNCTION__, TIM_Timestamp );
        if ( TIM_Timestamp == NULL )
        {
            TIM_Error( "Invalid Argument" );
            TIM_Status = TIM_Status_ArgumentInvalid;
            break;
        }
        if ( TIM_Year_IsValid( TIM_Timestamp->Year ) != TIM_Status_Success
             || TIM_Month_IsValid( TIM_Timestamp->Month ) != TIM_Status_Success
             || TIM_Day_IsValid( TIM_Timestamp->Day ) != TIM_Status_Success
             || TIM_Hour_IsValid( TIM_Timestamp->Hour ) != TIM_Status_Success
             || TIM_Minute_IsValid( TIM_Timestamp->Minute ) != TIM_Status_Success
             || TIM_Second_IsValid( TIM_Timestamp->Second ) != TIM_Status_Success
             || TIM_Millisecond_IsValid( TIM_Timestamp->Millisecond ) != TIM_Status_Success
             || TIM_Microsecond_IsValid( TIM_Timestamp->Microsecond ) != TIM_Status_Success
             || TIM_Weekday_IsValid( TIM_Timestamp->Weekday ) != TIM_Status_Success )
        {
            TIM_Status = TIM_Status_Error;
            break;
        }
        if ( TIM_Timestamp->Month != TIM_Month_Unknown
             && TIM_Timestamp->Day != TIM_Day_Unknown )
        {
            TIM_Day_t TIM_Day = TIM_Day_Unknown;
            if ( ( TIM_Status = TIM_Timestamp_GetMonthLastDay( TIM_Timestamp, &TIM_Day ) ) != TIM_Status_Success )
            {
                break;
            }
            if ( TIM_Timestamp->Day > TIM_Day )
            {
                TIM_Status = TIM_Status_Error;
                break;
            }
        }
        TIM_Status = TIM_Status_Success;
    }
    while ( 0 );
    return TIM_Status;
}

TIM_Status_t TIM_Timestamp_GetMonthLastDay( TIM_Timestamp_t * TIM_Timestamp, TIM_Day_t * TIM_Day )
{
    TIM_Status_t TIM_Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Timestamp=%p, Day=%p )", __FUNCTION__, TIM_Timestamp, TIM_Day );
        if ( TIM_Day == NULL
             || TIM_Timestamp == NULL )
        {
            TIM_Status = TIM_Status_ArgumentInvalid;
            break;
        }
        // FIXME `TIM_Timestamp_IsValid` requires `TIM_Timestamp_GetMonthLastDay`
        //    if ( ( TIM_Status = TIM_Timestamp_IsValid( TIM_Timestamp ) ) != TIM_Status_Success )
        //    {
        //      break;
        //    }
        switch ( TIM_Timestamp->Month )
        {
            case TIM_Month_January:
            case TIM_Month_March:
            case TIM_Month_May:
            case TIM_Month_July:
            case TIM_Month_August:
            case TIM_Month_October:
            case TIM_Month_December:
                *TIM_Day = TIM_Day_31;
                break;
            case TIM_Month_April:
            case TIM_Month_June:
            case TIM_Month_September:
            case TIM_Month_November:
                *TIM_Day = TIM_Day_30;
                break;
            case TIM_Month_February:
                *TIM_Day = ( TIM_Year_IsLeap( TIM_Timestamp->Year ) == TIM_Status_Success ? TIM_Day_29 : TIM_Day_28 );
                break;
            case TIM_Month_Unknown:
            default:
                *TIM_Day = TIM_Day_Unknown;
                break;
        }
        TIM_Status = TIM_Status_Success;
    }
    while ( 0 );
    return TIM_Status;
}

TIM_Status_t TIM_Timestamp_GetMonthLastDayDelta( TIM_Timestamp_t * TIM_Timestamp, TIM_DayDelta_t * TIM_DayDelta )
{
    TIM_Status_t TIM_Status = TIM_Status_Error;
    do
    {
        TIM_Trace( "%s( Timestamp=%p, DayDelta=%p )", __FUNCTION__, TIM_Timestamp, TIM_DayDelta );
        if ( TIM_DayDelta == NULL )
        {
            TIM_Status = TIM_Status_ArgumentInvalid;
            break;
        }
        if ( ( TIM_Status = TIM_Timestamp_IsValid( TIM_Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }
        TIM_Day_t TIM_Day = TIM_Day_Unknown;
        if ( ( TIM_Status = TIM_Timestamp_GetMonthLastDay( TIM_Timestamp, &TIM_Day ) ) != TIM_Status_Success )
        {
            // Couldn't get month end day
            break;
        }
        if ( TIM_Day == TIM_Day_Unknown )
        {
            // Couldn't compute delta for unknown day
            TIM_Status = TIM_Status_Error;
            break;
        }
        *TIM_DayDelta = TIM_Day - TIM_Timestamp->Day;
        TIM_Status = TIM_Status_Success;
    }
    while ( 0 );
    return TIM_Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
