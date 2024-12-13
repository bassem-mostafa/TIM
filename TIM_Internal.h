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

    #include "TIM_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #define TIM_TIM TIM_1

    #ifndef TIM_LOG
        #define TIM_LOG LOG_1
    #endif

    #define TIM_NAME       "TIM"
    #define TIM_LOG_PREFIX UTIL_StringConcatenateConstant( TIM_NAME, "> " )

    #ifdef DEBUG
        #define TIM_Raw( Level, Format, ... ) TIM_LOG_Raw( Level, Format, ##__VA_ARGS__ )
        #define TIM_Trace( Format, ... )      TIM_LOG_Trace( UTIL_StringConcatenateConstant( TIM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TIM_Debug( Format, ... )      TIM_LOG_Debug( UTIL_StringConcatenateConstant( TIM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TIM_Info( Format, ... )       TIM_LOG_Info( UTIL_StringConcatenateConstant( TIM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TIM_Warning( Format, ... )    TIM_LOG_Warning( UTIL_StringConcatenateConstant( TIM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TIM_Error( Format, ... )      TIM_LOG_Error( UTIL_StringConcatenateConstant( TIM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define TIM_Fatal( Format, ... )      TIM_LOG_Fatal( UTIL_StringConcatenateConstant( TIM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
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

    typedef struct TIM_Instance_Context TIM_Instance_Context_t;

    typedef struct TIM_Instance
    {
        TIM_t TIMx;

        union
        {
            TIM_Instance_Context_t * Context;
        };
    } TIM_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    TIM_Status_t TIM_Year_IsValid( TIM_Year_t TIM_Year );
    TIM_Status_t TIM_Year_IsLeap( TIM_Year_t TIM_Year );

    TIM_Status_t TIM_Month_IsValid( TIM_Month_t TIM_Month );

    TIM_Status_t TIM_Day_IsValid( TIM_Day_t TIM_Day );

    TIM_Status_t TIM_Hour_IsValid( TIM_Hour_t TIM_Hour );

    TIM_Status_t TIM_Minute_IsValid( TIM_Minute_t TIM_Minute );

    TIM_Status_t TIM_Second_IsValid( TIM_Second_t TIM_Second );

    TIM_Status_t TIM_Millisecond_IsValid( TIM_Millisecond_t TIM_Millisecond );

    TIM_Status_t TIM_Microsecond_IsValid( TIM_Microsecond_t TIM_Microsecond );

    TIM_Status_t TIM_Weekday_IsValid( TIM_Weekday_t TIM_Weekday );

    TIM_Status_t TIM_Timestamp_IsValid( TIM_Timestamp_t * TIM_Timestamp );

    TIM_Status_t TIM_Timestamp_GetMonthLastDay( TIM_Timestamp_t * TIM_Timestamp, TIM_Day_t * TIM_Day );
    TIM_Status_t TIM_Timestamp_GetMonthLastDayDelta( TIM_Timestamp_t * TIM_Timestamp, TIM_DayDelta_t * TIM_DayDelta );

    // The following APIs MUST be provided by the port
    TIM_Status_t TIM_IsValid( TIM_t TIM );

    TIM_Status_t TIM_Instance_Initialize( TIM_Instance_t * TIM_Instance );
    TIM_Status_t TIM_Instance_Cycle( TIM_Instance_t * TIM_Instance );
    TIM_Status_t TIM_Instance_DeInitialize( TIM_Instance_t * TIM_Instance );

    TIM_Status_t TIM_Instance_SetTimestamp( TIM_Instance_t * TIM_Instance, TIM_Timestamp_t TIM_Timestamp );
    TIM_Status_t TIM_Instance_GetTimestamp( TIM_Instance_t * TIM_Instance, TIM_Timestamp_t * TIM_Timestamp );
    TIM_Status_t TIM_Instance_IsExpiredTimestamp( TIM_Instance_t * TIM_Instance, TIM_Timestamp_t * TIM_Timestamp );

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
