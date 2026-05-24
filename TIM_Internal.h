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

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef TIM_INTERNAL_H_
    #define TIM_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "TIM.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef TIM_TIM
        #define TIM_TIM PLATFORM_DEFAULT_TIM
    #endif

    #ifndef TIM_LOG
        #define TIM_LOG PLATFORM_DEFAULT_LOG
    #endif

    #define TIM_NAME       "TIM"
    #define TIM_LOG_PREFIX UTIL_StringConcatenateConstant( TIM_NAME, "> " )

    #ifdef DEBUG
        #define TIM_Raw( Level, Format, ... ) LOG_Raw( TIM_LOG, Level, Format, ##__VA_ARGS__ )
        #define TIM_Trace( Format, ... )      LOG_Trace( TIM_LOG, UTIL_StringConcatenateConstant( TIM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TIM_Debug( Format, ... )      LOG_Debug( TIM_LOG, UTIL_StringConcatenateConstant( TIM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TIM_Info( Format, ... )       LOG_Info( TIM_LOG, UTIL_StringConcatenateConstant( TIM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TIM_Warning( Format, ... )    LOG_Warning( TIM_LOG, UTIL_StringConcatenateConstant( TIM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TIM_Error( Format, ... )      LOG_Error( TIM_LOG, UTIL_StringConcatenateConstant( TIM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TIM_Fatal( Format, ... )      LOG_Fatal( TIM_LOG, UTIL_StringConcatenateConstant( TIM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define TIM_Raw( Level, Format, ... )
        #define TIM_Trace( Format, ... )
        #define TIM_Debug( Format, ... )
        #define TIM_Info( Format, ... )
        #define TIM_Warning( Format, ... )
        #define TIM_Error( Format, ... )
        #define TIM_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef enum TIM_Type
    {
        TIM_Type_Unknown = 0,
        TIM_Type_Null,
        TIM_Type_RTC,
    } TIM_Type_t;

    typedef struct TIM_Instance
    {
        TIM_Type_t Type;

        union
        {
            RTC_t RTCx;
        };

        TIM_Timestamp_t Timestamp;
    } TIM_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    TIM_Status_t TIM_Year_IsValid( TIM_Year_t Year );
    TIM_Status_t TIM_Year_IsLeap( TIM_Year_t Year );

    TIM_Status_t TIM_Month_IsValid( TIM_Month_t Month );

    TIM_Status_t TIM_Day_IsValid( TIM_Day_t Day );

    TIM_Status_t TIM_Hour_IsValid( TIM_Hour_t Hour );

    TIM_Status_t TIM_Minute_IsValid( TIM_Minute_t Minute );

    TIM_Status_t TIM_Second_IsValid( TIM_Second_t Second );

    TIM_Status_t TIM_Millisecond_IsValid( TIM_Millisecond_t Millisecond );

    TIM_Status_t TIM_Microsecond_IsValid( TIM_Microsecond_t Microsecond );

    TIM_Status_t TIM_Weekday_IsValid( TIM_Weekday_t Weekday );

    TIM_Status_t TIM_Timestamp_IsValid( TIM_Timestamp_t * Timestamp );

    TIM_Status_t TIM_Timestamp_GetMonthLastDay( TIM_Timestamp_t * Timestamp, TIM_Day_t * Day );
    TIM_Status_t TIM_Timestamp_GetMonthLastDayDelta( TIM_Timestamp_t * Timestamp, TIM_DayDelta_t * DayDelta );

    // The following APIs MUST be provided by the port
    TIM_Status_t TIM_Port_Initialize( TIM_t TIMx );
    TIM_Status_t TIM_Port_Cycle( TIM_t TIMx );
    TIM_Status_t TIM_Port_DeInitialize( TIM_t TIMx );

    TIM_Status_t TIM_Port_SetTimestamp( TIM_t TIMx, TIM_Timestamp_t Timestamp );
    TIM_Status_t TIM_Port_GetTimestamp( TIM_t TIMx, TIM_Timestamp_t * Timestamp );
    TIM_Status_t TIM_Port_IsExpiredTimestamp( TIM_t TIMx, TIM_Timestamp_t * Timestamp );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* TIM_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
