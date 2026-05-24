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

TIM_Status_t TIM_Year_IsValid( TIM_Year_t Year )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Year=%d )", __FUNCTION__, Year );

        if ( Year != TIM_Year_Unknown && ( Year < TIM_Year_2000 || Year > TIM_Year_2099 ) )
        {
            Status = TIM_Status_ArgumentInvalid;
            break;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_Year_IsLeap( TIM_Year_t Year )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Year=%d )", __FUNCTION__, Year );

        if ( Year == TIM_Year_Unknown )
        {
            Status = TIM_Status_Error;
            break;
        }

        if ( UTIL_Modulus( Year - TIM_Year_2000, 4 ) != 0 )
        {
            Status = TIM_Status_Error;
            break;
        }

        if ( ( UTIL_Modulus( Year - TIM_Year_2000, 100 ) == 0 ) && ( UTIL_Modulus( Year - TIM_Year_2000, 400 ) != 0 ) )
        {
            Status = TIM_Status_Error;
            break;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_Month_IsValid( TIM_Month_t Month )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Month=%d )", __FUNCTION__, Month );

        if ( Month != TIM_Month_Unknown && ( Month < TIM_Month_January || Month > TIM_Month_December ) )
        {
            Status = TIM_Status_ArgumentInvalid;
            break;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_Day_IsValid( TIM_Day_t Day )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Day=%d )", __FUNCTION__, Day );

        if ( Day != TIM_Day_Unknown && ( Day < TIM_Day_1 || Day > TIM_Day_31 ) )
        {
            Status = TIM_Status_ArgumentInvalid;
            break;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_Hour_IsValid( TIM_Hour_t Hour )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Hour=%d )", __FUNCTION__, Hour );

        if ( Hour != TIM_Hour_Unknown && ( Hour < TIM_Hour_00 || Hour > TIM_Hour_23 ) )
        {
            Status = TIM_Status_ArgumentInvalid;
            break;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_Minute_IsValid( TIM_Minute_t Minute )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Minute=%d )", __FUNCTION__, Minute );

        if ( Minute != TIM_Minute_Unknown && ( Minute < TIM_Minute_00 || Minute > TIM_Minute_59 ) )
        {
            Status = TIM_Status_ArgumentInvalid;
            break;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_Second_IsValid( TIM_Second_t Second )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Second=%d )", __FUNCTION__, Second );

        if ( Second != TIM_Second_Unknown && ( Second < TIM_Second_00 || Second > TIM_Second_59 ) )
        {
            Status = TIM_Status_ArgumentInvalid;
            break;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_Millisecond_IsValid( TIM_Millisecond_t Millisecond )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Millisecond=%d )", __FUNCTION__, Millisecond );

        if ( Millisecond != TIM_Millisecond_Unknown && ( Millisecond < TIM_Millisecond_000 || Millisecond > TIM_Millisecond_999 ) )
        {
            Status = TIM_Status_ArgumentInvalid;
            break;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_Microsecond_IsValid( TIM_Microsecond_t Microsecond )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Microsecond=%d )", __FUNCTION__, Microsecond );

        if ( Microsecond != TIM_Microsecond_Unknown && ( Microsecond < TIM_Microsecond_000 || Microsecond > TIM_Microsecond_999 ) )
        {
            Status = TIM_Status_ArgumentInvalid;
            break;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_Weekday_IsValid( TIM_Weekday_t Weekday )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Weekday=%d )", __FUNCTION__, Weekday );

        if ( Weekday != TIM_Weekday_Unknown && ( Weekday < TIM_Weekday_Saturday || Weekday > TIM_Weekday_Friday ) )
        {
            Status = TIM_Status_ArgumentInvalid;
            break;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_Timestamp_IsValid( TIM_Timestamp_t * Timestamp )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Timestamp=%p )", __FUNCTION__, Timestamp );

        if ( Timestamp == NULL )
        {
            Status = TIM_Status_ArgumentInvalid;
            break;
        }

        if ( TIM_Year_IsValid( Timestamp->Year ) != TIM_Status_Success
             || TIM_Month_IsValid( Timestamp->Month ) != TIM_Status_Success
             || TIM_Day_IsValid( Timestamp->Day ) != TIM_Status_Success
             || TIM_Hour_IsValid( Timestamp->Hour ) != TIM_Status_Success
             || TIM_Minute_IsValid( Timestamp->Minute ) != TIM_Status_Success
             || TIM_Second_IsValid( Timestamp->Second ) != TIM_Status_Success
             || TIM_Millisecond_IsValid( Timestamp->Millisecond ) != TIM_Status_Success
             || TIM_Microsecond_IsValid( Timestamp->Microsecond ) != TIM_Status_Success
             || TIM_Weekday_IsValid( Timestamp->Weekday ) != TIM_Status_Success )
        {
            Status = TIM_Status_Error;
            break;
        }

        if ( Timestamp->Month != TIM_Month_Unknown && Timestamp->Day != TIM_Day_Unknown )
        {
            TIM_Day_t Day = TIM_Day_Unknown;
            if ( ( Status = TIM_Timestamp_GetMonthLastDay( Timestamp, &Day ) ) != TIM_Status_Success )
            {
                break;
            }
            if ( Timestamp->Day > Day )
            {
                Status = TIM_Status_Error;
                break;
            }
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_Timestamp_GetMonthLastDay( TIM_Timestamp_t * Timestamp, TIM_Day_t * Day )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Timestamp=%p, Day=%p )", __FUNCTION__, Timestamp, Day );

        if ( Day == NULL || Timestamp == NULL )
        {
            Status = TIM_Status_ArgumentInvalid;
            break;
        }

        // FIXME `TIM_Timestamp_IsValid` requires `TIM_Timestamp_GetMonthLastDay`
        //    if ( ( Status = TIM_Timestamp_IsValid( Timestamp ) ) != TIM_Status_Success )
        //    {
        //      break;
        //    }

        switch ( Timestamp->Month )
        {
            case TIM_Month_January:
            case TIM_Month_March:
            case TIM_Month_May:
            case TIM_Month_July:
            case TIM_Month_August:
            case TIM_Month_October:
            case TIM_Month_December:
                *Day = TIM_Day_31;
                break;
            case TIM_Month_April:
            case TIM_Month_June:
            case TIM_Month_September:
            case TIM_Month_November:
                *Day = TIM_Day_30;
                break;
            case TIM_Month_February:
                *Day = ( TIM_Year_IsLeap( Timestamp->Year ) == TIM_Status_Success ? TIM_Day_29 : TIM_Day_28 );
                break;
            case TIM_Month_Unknown:
            default:
                *Day = TIM_Day_Unknown;
                break;
        }
    }
    while ( 0 );

    return Status;
}

TIM_Status_t TIM_Timestamp_GetMonthLastDayDelta( TIM_Timestamp_t * Timestamp, TIM_DayDelta_t * Delta )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Timestamp=%p, DayDelta=%p )", __FUNCTION__, Timestamp, Delta );

        if ( Delta == NULL )
        {
            Status = TIM_Status_ArgumentInvalid;
            break;
        }

        if ( ( Status = TIM_Timestamp_IsValid( Timestamp ) ) != TIM_Status_Success )
        {
            break;
        }

        TIM_Day_t Day = TIM_Day_Unknown;
        if ( ( Status = TIM_Timestamp_GetMonthLastDay( Timestamp, &Day ) ) != TIM_Status_Success )
        {
            // Couldn't get month end day
            break;
        }

        if ( Day == TIM_Day_Unknown )
        {
            // Couldn't compute delta for unknown day
            Status = TIM_Status_Error;
            break;
        }

        *Delta = Day - Timestamp->Day;
    }
    while ( 0 );

    return Status;
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
