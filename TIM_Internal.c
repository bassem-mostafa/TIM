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

TIM_Status_t TIM_Timestamp_IsAfter( TIM_Timestamp_t * Timestamp_1, TIM_Timestamp_t * Timestamp_2 )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Timestamp_1=%p, Timestamp_2=%p", __FUNCTION__, Timestamp_1, Timestamp_2 );

        if ( Timestamp_1->Year < Timestamp_2->Year )
        {
            Status = TIM_Status_Error;
            break;
        }

        if ( Timestamp_1->Year > Timestamp_2->Year )
        {
            break;
        }

        if ( Timestamp_1->Month < Timestamp_2->Month )
        {
            Status = TIM_Status_Error;
            break;
        }

        if ( Timestamp_1->Month > Timestamp_2->Month )
        {
            break;
        }

        if ( Timestamp_1->Day < Timestamp_2->Day )
        {
            Status = TIM_Status_Error;
            break;
        }

        if ( Timestamp_1->Day > Timestamp_2->Day )
        {
            break;
        }

        if ( Timestamp_1->Hour < Timestamp_2->Hour )
        {
            Status = TIM_Status_Error;
            break;
        }

        if ( Timestamp_1->Hour > Timestamp_2->Hour )
        {
            break;
        }

        if ( Timestamp_1->Minute < Timestamp_2->Minute )
        {
            Status = TIM_Status_Error;
            break;
        }

        if ( Timestamp_1->Minute > Timestamp_2->Minute )
        {
            break;
        }

        if ( Timestamp_1->Second < Timestamp_2->Second )
        {
            Status = TIM_Status_Error;
            break;
        }

        if ( Timestamp_1->Second > Timestamp_2->Second )
        {
            break;
        }

        if ( Timestamp_1->Millisecond < Timestamp_2->Millisecond )
        {
            Status = TIM_Status_Error;
            break;
        }

        if ( Timestamp_1->Millisecond > Timestamp_2->Millisecond )
        {
            break;
        }

        if ( Timestamp_1->Microsecond < Timestamp_2->Microsecond )
        {
            Status = TIM_Status_Error;
            break;
        }

        if ( Timestamp_1->Microsecond > Timestamp_2->Microsecond )
        {
            break;
        }

        // Timestamps are equal
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

TIM_Status_t TIM_Timestamp_GetDelta( TIM_Timestamp_t * Timestamp_1, TIM_Timestamp_t * Timestamp_2, TIM_Delta_t * Delta )
{
    TIM_Status_t Status = TIM_Status_Success;

    do
    {
        TIM_Trace( "%s( Timestamp_1=%p, Timestamp_2=%p, Delta=%p )", __FUNCTION__, Timestamp_1, Timestamp_2, Delta );

        if ( Timestamp_1 == NULL
             || Timestamp_2 == NULL
             || Delta == NULL
             || TIM_Timestamp_IsValid( Timestamp_1 ) != TIM_Status_Success
             || TIM_Timestamp_IsValid( Timestamp_2 ) != TIM_Status_Success )
        {
            Status = TIM_Status_ArgumentInvalid;
            break;
        }

        if ( Timestamp_1->Year == TIM_Year_Unknown
             || Timestamp_1->Month == TIM_Month_Unknown
             || Timestamp_1->Day == TIM_Day_Unknown
             || Timestamp_1->Hour == TIM_Hour_Unknown
             || Timestamp_1->Minute == TIM_Minute_Unknown
             || Timestamp_1->Second == TIM_Second_Unknown
             || Timestamp_1->Millisecond == TIM_Millisecond_Unknown
             || Timestamp_1->Microsecond == TIM_Microsecond_Unknown
             || Timestamp_2->Year == TIM_Year_Unknown
             || Timestamp_2->Month == TIM_Month_Unknown
             || Timestamp_2->Day == TIM_Day_Unknown
             || Timestamp_2->Hour == TIM_Hour_Unknown
             || Timestamp_2->Minute == TIM_Minute_Unknown
             || Timestamp_2->Second == TIM_Second_Unknown
             || Timestamp_2->Millisecond == TIM_Millisecond_Unknown
             || Timestamp_2->Microsecond == TIM_Microsecond_Unknown )
        {
            Status = TIM_Status_Error;
            break;
        }

        // FIXME Delta days might be incorrect
        // FIXME Delta might contain +ve and -ve deltas at the same time
        Delta->Year = Timestamp_1->Year - Timestamp_2->Year;
        Delta->Month = Timestamp_1->Month - Timestamp_2->Month;
        Delta->Day = Timestamp_1->Day - Timestamp_2->Day;
        Delta->Hour = Timestamp_1->Hour - Timestamp_2->Hour;
        Delta->Minute = Timestamp_1->Minute - Timestamp_2->Minute;
        Delta->Second = Timestamp_1->Second - Timestamp_2->Second;
        Delta->Millisecond = Timestamp_1->Millisecond - Timestamp_2->Millisecond;
        Delta->Microsecond = Timestamp_1->Microsecond - Timestamp_2->Microsecond;
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
