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

/**
 *  @file
 *
 *  @brief Platform TIM Service
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Service
 *
 *  @{
 */

/**
 *  @defgroup Platform_TIM TIM
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

#ifndef TIM_H_
    #define TIM_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include <stdint.h>

    #include "TIM_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief TIM Operation Status
     *
     *  @enum TIM_Status_t
     */
    typedef enum TIM_Status
    {
        TIM_Status_Success = 0,     ///< Success
        TIM_Status_ArgumentInvalid, ///< Argument Invalid
        TIM_Status_NotSupported,    ///< Not Supported
        TIM_Status_Error,           ///< General Error
        TIM_Status_Busy,            ///< Busy
        TIM_Status_Timeout,         ///< Timeout
    } TIM_Status_t;

    /**
     *  @brief TIM Year Type
     *
     *  @enum TIM_Year_t
     */
    typedef enum TIM_Year
    {
        TIM_Year_Unknown = -1, ///< Default
        TIM_Year_2000 = 2000,  ///< TIM Year 2000 (Minimum)
        TIM_Year_2001,
        TIM_Year_2002,
        TIM_Year_2003,
        TIM_Year_2004,
        TIM_Year_2005,
        TIM_Year_2006,
        TIM_Year_2007,
        TIM_Year_2008,
        TIM_Year_2009,
        TIM_Year_2010,
        TIM_Year_2011,
        TIM_Year_2012,
        TIM_Year_2013,
        TIM_Year_2014,
        TIM_Year_2015,
        TIM_Year_2016,
        TIM_Year_2017,
        TIM_Year_2018,
        TIM_Year_2019,
        TIM_Year_2020,
        TIM_Year_2021,
        TIM_Year_2022,
        TIM_Year_2023,
        TIM_Year_2024,
        TIM_Year_2025,
        TIM_Year_2026,
        TIM_Year_2027,
        TIM_Year_2028,
        TIM_Year_2029,
        TIM_Year_2030,
        TIM_Year_2031,
        TIM_Year_2032,
        TIM_Year_2033,
        TIM_Year_2034,
        TIM_Year_2035,
        TIM_Year_2036,
        TIM_Year_2037,
        TIM_Year_2038,
        TIM_Year_2039,
        TIM_Year_2040,
        TIM_Year_2041,
        TIM_Year_2042,
        TIM_Year_2043,
        TIM_Year_2044,
        TIM_Year_2045,
        TIM_Year_2046,
        TIM_Year_2047,
        TIM_Year_2048,
        TIM_Year_2049,
        TIM_Year_2050,
        TIM_Year_2051,
        TIM_Year_2052,
        TIM_Year_2053,
        TIM_Year_2054,
        TIM_Year_2055,
        TIM_Year_2056,
        TIM_Year_2057,
        TIM_Year_2058,
        TIM_Year_2059,
        TIM_Year_2060,
        TIM_Year_2061,
        TIM_Year_2062,
        TIM_Year_2063,
        TIM_Year_2064,
        TIM_Year_2065,
        TIM_Year_2066,
        TIM_Year_2067,
        TIM_Year_2068,
        TIM_Year_2069,
        TIM_Year_2070,
        TIM_Year_2071,
        TIM_Year_2072,
        TIM_Year_2073,
        TIM_Year_2074,
        TIM_Year_2075,
        TIM_Year_2076,
        TIM_Year_2077,
        TIM_Year_2078,
        TIM_Year_2079,
        TIM_Year_2080,
        TIM_Year_2081,
        TIM_Year_2082,
        TIM_Year_2083,
        TIM_Year_2084,
        TIM_Year_2085,
        TIM_Year_2086,
        TIM_Year_2087,
        TIM_Year_2088,
        TIM_Year_2089,
        TIM_Year_2090,
        TIM_Year_2091,
        TIM_Year_2092,
        TIM_Year_2093,
        TIM_Year_2094,
        TIM_Year_2095,
        TIM_Year_2096,
        TIM_Year_2097,
        TIM_Year_2098,
        TIM_Year_2099, ///< TIM Year 2099 (Maximum)
    } TIM_Year_t;

    /**
     *  @brief TIM Month Type
     *
     *  @enum TIM_Month_t
     */
    typedef enum TIM_Month
    {
        TIM_Month_Unknown = -1, ///< Default
        TIM_Month_January = 1,  ///< January
        TIM_Month_February,     ///< February
        TIM_Month_March,        ///< March
        TIM_Month_April,        ///< April
        TIM_Month_May,          ///< May
        TIM_Month_June,         ///< June
        TIM_Month_July,         ///< July
        TIM_Month_August,       ///< August
        TIM_Month_September,    ///< September
        TIM_Month_October,      ///< October
        TIM_Month_November,     ///< November
        TIM_Month_December,     ///< December
    } TIM_Month_t;

    /**
     *  @brief TIM Day Type
     *
     *  @enum TIM_Day_t
     */
    typedef enum TIM_Day
    {
        TIM_Day_Unknown = -1, ///< Default
        TIM_Day_1 = 1,        ///< Day 1 (Minimum)
        TIM_Day_2,            ///<
        TIM_Day_3,            ///<
        TIM_Day_4,            ///<
        TIM_Day_5,            ///<
        TIM_Day_6,            ///<
        TIM_Day_7,            ///<
        TIM_Day_8,            ///<
        TIM_Day_9,            ///<
        TIM_Day_10,           ///<
        TIM_Day_11,           ///<
        TIM_Day_12,           ///<
        TIM_Day_13,           ///<
        TIM_Day_14,           ///<
        TIM_Day_15,           ///<
        TIM_Day_16,           ///<
        TIM_Day_17,           ///<
        TIM_Day_18,           ///<
        TIM_Day_19,           ///<
        TIM_Day_20,           ///<
        TIM_Day_21,           ///<
        TIM_Day_22,           ///<
        TIM_Day_23,           ///<
        TIM_Day_24,           ///<
        TIM_Day_25,           ///<
        TIM_Day_26,           ///<
        TIM_Day_27,           ///<
        TIM_Day_28,           ///<
        TIM_Day_29,           ///<
        TIM_Day_30,           ///<
        TIM_Day_31,           ///< Day 31 (Maximum)
    } TIM_Day_t;

    /**
     *  @brief TIM Hour Type
     *
     *  @enum TIM_Hour_t
     */
    typedef enum TIM_Hour
    {
        TIM_Hour_Unknown = -1, ///< Default
        TIM_Hour_00 = 0,       ///< Hour 00 AM (Minimum)
        TIM_Hour_01,           ///<
        TIM_Hour_02,           ///<
        TIM_Hour_03,           ///<
        TIM_Hour_04,           ///<
        TIM_Hour_05,           ///<
        TIM_Hour_06,           ///<
        TIM_Hour_07,           ///<
        TIM_Hour_08,           ///<
        TIM_Hour_09,           ///<
        TIM_Hour_10,           ///<
        TIM_Hour_11,           ///<
        TIM_Hour_12,           ///<
        TIM_Hour_13,           ///<
        TIM_Hour_14,           ///<
        TIM_Hour_15,           ///<
        TIM_Hour_16,           ///<
        TIM_Hour_17,           ///<
        TIM_Hour_18,           ///<
        TIM_Hour_19,           ///<
        TIM_Hour_20,           ///<
        TIM_Hour_21,           ///<
        TIM_Hour_22,           ///<
        TIM_Hour_23,           ///< Hour 23 PM (Maximum)
    } TIM_Hour_t;

    /**
     *  @brief TIM Minute Type
     *
     *  @enum TIM_Minute_t
     */
    typedef enum TIM_Minute
    {
        TIM_Minute_Unknown = -1, ///< Default
        TIM_Minute_00 = 0,       ///< Minute 00 (Minimum)
        TIM_Minute_01,           ///<
        TIM_Minute_02,           ///<
        TIM_Minute_03,           ///<
        TIM_Minute_04,           ///<
        TIM_Minute_05,           ///<
        TIM_Minute_06,           ///<
        TIM_Minute_07,           ///<
        TIM_Minute_08,           ///<
        TIM_Minute_09,           ///<
        TIM_Minute_10,           ///<
        TIM_Minute_11,           ///<
        TIM_Minute_12,           ///<
        TIM_Minute_13,           ///<
        TIM_Minute_14,           ///<
        TIM_Minute_15,           ///<
        TIM_Minute_16,           ///<
        TIM_Minute_17,           ///<
        TIM_Minute_18,           ///<
        TIM_Minute_19,           ///<
        TIM_Minute_20,           ///<
        TIM_Minute_21,           ///<
        TIM_Minute_22,           ///<
        TIM_Minute_23,           ///<
        TIM_Minute_24,           ///<
        TIM_Minute_25,           ///<
        TIM_Minute_26,           ///<
        TIM_Minute_27,           ///<
        TIM_Minute_28,           ///<
        TIM_Minute_29,           ///<
        TIM_Minute_30,           ///<
        TIM_Minute_31,           ///<
        TIM_Minute_32,           ///<
        TIM_Minute_33,           ///<
        TIM_Minute_34,           ///<
        TIM_Minute_35,           ///<
        TIM_Minute_36,           ///<
        TIM_Minute_37,           ///<
        TIM_Minute_38,           ///<
        TIM_Minute_39,           ///<
        TIM_Minute_40,           ///<
        TIM_Minute_41,           ///<
        TIM_Minute_42,           ///<
        TIM_Minute_43,           ///<
        TIM_Minute_44,           ///<
        TIM_Minute_45,           ///<
        TIM_Minute_46,           ///<
        TIM_Minute_47,           ///<
        TIM_Minute_48,           ///<
        TIM_Minute_49,           ///<
        TIM_Minute_50,           ///<
        TIM_Minute_51,           ///<
        TIM_Minute_52,           ///<
        TIM_Minute_53,           ///<
        TIM_Minute_54,           ///<
        TIM_Minute_55,           ///<
        TIM_Minute_56,           ///<
        TIM_Minute_57,           ///<
        TIM_Minute_58,           ///<
        TIM_Minute_59,           ///< Minute 59 (Maximum)
    } TIM_Minute_t;

    /**
     *  @brief TIM Second Type
     *
     *  @enum TIM_Second_t
     */
    typedef enum TIM_Second
    {
        TIM_Second_Unknown = -1, ///< Default
        TIM_Second_00 = 0,       ///< Second 00 (Minimum)
        TIM_Second_01,           ///<
        TIM_Second_02,           ///<
        TIM_Second_03,           ///<
        TIM_Second_04,           ///<
        TIM_Second_05,           ///<
        TIM_Second_06,           ///<
        TIM_Second_07,           ///<
        TIM_Second_08,           ///<
        TIM_Second_09,           ///<
        TIM_Second_10,           ///<
        TIM_Second_11,           ///<
        TIM_Second_12,           ///<
        TIM_Second_13,           ///<
        TIM_Second_14,           ///<
        TIM_Second_15,           ///<
        TIM_Second_16,           ///<
        TIM_Second_17,           ///<
        TIM_Second_18,           ///<
        TIM_Second_19,           ///<
        TIM_Second_20,           ///<
        TIM_Second_21,           ///<
        TIM_Second_22,           ///<
        TIM_Second_23,           ///<
        TIM_Second_24,           ///<
        TIM_Second_25,           ///<
        TIM_Second_26,           ///<
        TIM_Second_27,           ///<
        TIM_Second_28,           ///<
        TIM_Second_29,           ///<
        TIM_Second_30,           ///<
        TIM_Second_31,           ///<
        TIM_Second_32,           ///<
        TIM_Second_33,           ///<
        TIM_Second_34,           ///<
        TIM_Second_35,           ///<
        TIM_Second_36,           ///<
        TIM_Second_37,           ///<
        TIM_Second_38,           ///<
        TIM_Second_39,           ///<
        TIM_Second_40,           ///<
        TIM_Second_41,           ///<
        TIM_Second_42,           ///<
        TIM_Second_43,           ///<
        TIM_Second_44,           ///<
        TIM_Second_45,           ///<
        TIM_Second_46,           ///<
        TIM_Second_47,           ///<
        TIM_Second_48,           ///<
        TIM_Second_49,           ///<
        TIM_Second_50,           ///<
        TIM_Second_51,           ///<
        TIM_Second_52,           ///<
        TIM_Second_53,           ///<
        TIM_Second_54,           ///<
        TIM_Second_55,           ///<
        TIM_Second_56,           ///<
        TIM_Second_57,           ///<
        TIM_Second_58,           ///<
        TIM_Second_59,           ///< Second 59 (Maximum)
    } TIM_Second_t;

    /**
     *  @brief TIM Millisecond Type
     *
     *  @enum TIM_Millisecond_t
     */
    typedef enum TIM_Millisecond
    {
        TIM_Millisecond_Unknown = -1, ///< Default
        TIM_Millisecond_000 = 0,      ///< Millisecond 000 (Minimum)
        TIM_Millisecond_001,          ///<
        TIM_Millisecond_002,          ///<
        TIM_Millisecond_003,          ///<
        TIM_Millisecond_004,          ///<
        TIM_Millisecond_005,          ///<
        TIM_Millisecond_006,          ///<
        TIM_Millisecond_007,          ///<
        TIM_Millisecond_008,          ///<
        TIM_Millisecond_009,          ///<
        TIM_Millisecond_010,          ///<
        TIM_Millisecond_011,          ///<
        TIM_Millisecond_012,          ///<
        TIM_Millisecond_013,          ///<
        TIM_Millisecond_014,          ///<
        TIM_Millisecond_015,          ///<
        TIM_Millisecond_016,          ///<
        TIM_Millisecond_017,          ///<
        TIM_Millisecond_018,          ///<
        TIM_Millisecond_019,          ///<
        TIM_Millisecond_020,          ///<
        TIM_Millisecond_021,          ///<
        TIM_Millisecond_022,          ///<
        TIM_Millisecond_023,          ///<
        TIM_Millisecond_024,          ///<
        TIM_Millisecond_025,          ///<
        TIM_Millisecond_026,          ///<
        TIM_Millisecond_027,          ///<
        TIM_Millisecond_028,          ///<
        TIM_Millisecond_029,          ///<
        TIM_Millisecond_030,          ///<
        TIM_Millisecond_031,          ///<
        TIM_Millisecond_032,          ///<
        TIM_Millisecond_033,          ///<
        TIM_Millisecond_034,          ///<
        TIM_Millisecond_035,          ///<
        TIM_Millisecond_036,          ///<
        TIM_Millisecond_037,          ///<
        TIM_Millisecond_038,          ///<
        TIM_Millisecond_039,          ///<
        TIM_Millisecond_040,          ///<
        TIM_Millisecond_041,          ///<
        TIM_Millisecond_042,          ///<
        TIM_Millisecond_043,          ///<
        TIM_Millisecond_044,          ///<
        TIM_Millisecond_045,          ///<
        TIM_Millisecond_046,          ///<
        TIM_Millisecond_047,          ///<
        TIM_Millisecond_048,          ///<
        TIM_Millisecond_049,          ///<
        TIM_Millisecond_050,          ///<
        TIM_Millisecond_051,          ///<
        TIM_Millisecond_052,          ///<
        TIM_Millisecond_053,          ///<
        TIM_Millisecond_054,          ///<
        TIM_Millisecond_055,          ///<
        TIM_Millisecond_056,          ///<
        TIM_Millisecond_057,          ///<
        TIM_Millisecond_058,          ///<
        TIM_Millisecond_059,          ///<
        TIM_Millisecond_060,          ///<
        TIM_Millisecond_061,          ///<
        TIM_Millisecond_062,          ///<
        TIM_Millisecond_063,          ///<
        TIM_Millisecond_064,          ///<
        TIM_Millisecond_065,          ///<
        TIM_Millisecond_066,          ///<
        TIM_Millisecond_067,          ///<
        TIM_Millisecond_068,          ///<
        TIM_Millisecond_069,          ///<
        TIM_Millisecond_070,          ///<
        TIM_Millisecond_071,          ///<
        TIM_Millisecond_072,          ///<
        TIM_Millisecond_073,          ///<
        TIM_Millisecond_074,          ///<
        TIM_Millisecond_075,          ///<
        TIM_Millisecond_076,          ///<
        TIM_Millisecond_077,          ///<
        TIM_Millisecond_078,          ///<
        TIM_Millisecond_079,          ///<
        TIM_Millisecond_080,          ///<
        TIM_Millisecond_081,          ///<
        TIM_Millisecond_082,          ///<
        TIM_Millisecond_083,          ///<
        TIM_Millisecond_084,          ///<
        TIM_Millisecond_085,          ///<
        TIM_Millisecond_086,          ///<
        TIM_Millisecond_087,          ///<
        TIM_Millisecond_088,          ///<
        TIM_Millisecond_089,          ///<
        TIM_Millisecond_090,          ///<
        TIM_Millisecond_091,          ///<
        TIM_Millisecond_092,          ///<
        TIM_Millisecond_093,          ///<
        TIM_Millisecond_094,          ///<
        TIM_Millisecond_095,          ///<
        TIM_Millisecond_096,          ///<
        TIM_Millisecond_097,          ///<
        TIM_Millisecond_098,          ///<
        TIM_Millisecond_099,          ///<
        TIM_Millisecond_100,          ///<
        TIM_Millisecond_101,          ///<
        TIM_Millisecond_102,          ///<
        TIM_Millisecond_103,          ///<
        TIM_Millisecond_104,          ///<
        TIM_Millisecond_105,          ///<
        TIM_Millisecond_106,          ///<
        TIM_Millisecond_107,          ///<
        TIM_Millisecond_108,          ///<
        TIM_Millisecond_109,          ///<
        TIM_Millisecond_110,          ///<
        TIM_Millisecond_111,          ///<
        TIM_Millisecond_112,          ///<
        TIM_Millisecond_113,          ///<
        TIM_Millisecond_114,          ///<
        TIM_Millisecond_115,          ///<
        TIM_Millisecond_116,          ///<
        TIM_Millisecond_117,          ///<
        TIM_Millisecond_118,          ///<
        TIM_Millisecond_119,          ///<
        TIM_Millisecond_120,          ///<
        TIM_Millisecond_121,          ///<
        TIM_Millisecond_122,          ///<
        TIM_Millisecond_123,          ///<
        TIM_Millisecond_124,          ///<
        TIM_Millisecond_125,          ///<
        TIM_Millisecond_126,          ///<
        TIM_Millisecond_127,          ///<
        TIM_Millisecond_128,          ///<
        TIM_Millisecond_129,          ///<
        TIM_Millisecond_130,          ///<
        TIM_Millisecond_131,          ///<
        TIM_Millisecond_132,          ///<
        TIM_Millisecond_133,          ///<
        TIM_Millisecond_134,          ///<
        TIM_Millisecond_135,          ///<
        TIM_Millisecond_136,          ///<
        TIM_Millisecond_137,          ///<
        TIM_Millisecond_138,          ///<
        TIM_Millisecond_139,          ///<
        TIM_Millisecond_140,          ///<
        TIM_Millisecond_141,          ///<
        TIM_Millisecond_142,          ///<
        TIM_Millisecond_143,          ///<
        TIM_Millisecond_144,          ///<
        TIM_Millisecond_145,          ///<
        TIM_Millisecond_146,          ///<
        TIM_Millisecond_147,          ///<
        TIM_Millisecond_148,          ///<
        TIM_Millisecond_149,          ///<
        TIM_Millisecond_150,          ///<
        TIM_Millisecond_151,          ///<
        TIM_Millisecond_152,          ///<
        TIM_Millisecond_153,          ///<
        TIM_Millisecond_154,          ///<
        TIM_Millisecond_155,          ///<
        TIM_Millisecond_156,          ///<
        TIM_Millisecond_157,          ///<
        TIM_Millisecond_158,          ///<
        TIM_Millisecond_159,          ///<
        TIM_Millisecond_160,          ///<
        TIM_Millisecond_161,          ///<
        TIM_Millisecond_162,          ///<
        TIM_Millisecond_163,          ///<
        TIM_Millisecond_164,          ///<
        TIM_Millisecond_165,          ///<
        TIM_Millisecond_166,          ///<
        TIM_Millisecond_167,          ///<
        TIM_Millisecond_168,          ///<
        TIM_Millisecond_169,          ///<
        TIM_Millisecond_170,          ///<
        TIM_Millisecond_171,          ///<
        TIM_Millisecond_172,          ///<
        TIM_Millisecond_173,          ///<
        TIM_Millisecond_174,          ///<
        TIM_Millisecond_175,          ///<
        TIM_Millisecond_176,          ///<
        TIM_Millisecond_177,          ///<
        TIM_Millisecond_178,          ///<
        TIM_Millisecond_179,          ///<
        TIM_Millisecond_180,          ///<
        TIM_Millisecond_181,          ///<
        TIM_Millisecond_182,          ///<
        TIM_Millisecond_183,          ///<
        TIM_Millisecond_184,          ///<
        TIM_Millisecond_185,          ///<
        TIM_Millisecond_186,          ///<
        TIM_Millisecond_187,          ///<
        TIM_Millisecond_188,          ///<
        TIM_Millisecond_189,          ///<
        TIM_Millisecond_190,          ///<
        TIM_Millisecond_191,          ///<
        TIM_Millisecond_192,          ///<
        TIM_Millisecond_193,          ///<
        TIM_Millisecond_194,          ///<
        TIM_Millisecond_195,          ///<
        TIM_Millisecond_196,          ///<
        TIM_Millisecond_197,          ///<
        TIM_Millisecond_198,          ///<
        TIM_Millisecond_199,          ///<
        TIM_Millisecond_200,          ///<
        TIM_Millisecond_201,          ///<
        TIM_Millisecond_202,          ///<
        TIM_Millisecond_203,          ///<
        TIM_Millisecond_204,          ///<
        TIM_Millisecond_205,          ///<
        TIM_Millisecond_206,          ///<
        TIM_Millisecond_207,          ///<
        TIM_Millisecond_208,          ///<
        TIM_Millisecond_209,          ///<
        TIM_Millisecond_210,          ///<
        TIM_Millisecond_211,          ///<
        TIM_Millisecond_212,          ///<
        TIM_Millisecond_213,          ///<
        TIM_Millisecond_214,          ///<
        TIM_Millisecond_215,          ///<
        TIM_Millisecond_216,          ///<
        TIM_Millisecond_217,          ///<
        TIM_Millisecond_218,          ///<
        TIM_Millisecond_219,          ///<
        TIM_Millisecond_220,          ///<
        TIM_Millisecond_221,          ///<
        TIM_Millisecond_222,          ///<
        TIM_Millisecond_223,          ///<
        TIM_Millisecond_224,          ///<
        TIM_Millisecond_225,          ///<
        TIM_Millisecond_226,          ///<
        TIM_Millisecond_227,          ///<
        TIM_Millisecond_228,          ///<
        TIM_Millisecond_229,          ///<
        TIM_Millisecond_230,          ///<
        TIM_Millisecond_231,          ///<
        TIM_Millisecond_232,          ///<
        TIM_Millisecond_233,          ///<
        TIM_Millisecond_234,          ///<
        TIM_Millisecond_235,          ///<
        TIM_Millisecond_236,          ///<
        TIM_Millisecond_237,          ///<
        TIM_Millisecond_238,          ///<
        TIM_Millisecond_239,          ///<
        TIM_Millisecond_240,          ///<
        TIM_Millisecond_241,          ///<
        TIM_Millisecond_242,          ///<
        TIM_Millisecond_243,          ///<
        TIM_Millisecond_244,          ///<
        TIM_Millisecond_245,          ///<
        TIM_Millisecond_246,          ///<
        TIM_Millisecond_247,          ///<
        TIM_Millisecond_248,          ///<
        TIM_Millisecond_249,          ///<
        TIM_Millisecond_250,          ///<
        TIM_Millisecond_251,          ///<
        TIM_Millisecond_252,          ///<
        TIM_Millisecond_253,          ///<
        TIM_Millisecond_254,          ///<
        TIM_Millisecond_255,          ///<
        TIM_Millisecond_256,          ///<
        TIM_Millisecond_257,          ///<
        TIM_Millisecond_258,          ///<
        TIM_Millisecond_259,          ///<
        TIM_Millisecond_260,          ///<
        TIM_Millisecond_261,          ///<
        TIM_Millisecond_262,          ///<
        TIM_Millisecond_263,          ///<
        TIM_Millisecond_264,          ///<
        TIM_Millisecond_265,          ///<
        TIM_Millisecond_266,          ///<
        TIM_Millisecond_267,          ///<
        TIM_Millisecond_268,          ///<
        TIM_Millisecond_269,          ///<
        TIM_Millisecond_270,          ///<
        TIM_Millisecond_271,          ///<
        TIM_Millisecond_272,          ///<
        TIM_Millisecond_273,          ///<
        TIM_Millisecond_274,          ///<
        TIM_Millisecond_275,          ///<
        TIM_Millisecond_276,          ///<
        TIM_Millisecond_277,          ///<
        TIM_Millisecond_278,          ///<
        TIM_Millisecond_279,          ///<
        TIM_Millisecond_280,          ///<
        TIM_Millisecond_281,          ///<
        TIM_Millisecond_282,          ///<
        TIM_Millisecond_283,          ///<
        TIM_Millisecond_284,          ///<
        TIM_Millisecond_285,          ///<
        TIM_Millisecond_286,          ///<
        TIM_Millisecond_287,          ///<
        TIM_Millisecond_288,          ///<
        TIM_Millisecond_289,          ///<
        TIM_Millisecond_290,          ///<
        TIM_Millisecond_291,          ///<
        TIM_Millisecond_292,          ///<
        TIM_Millisecond_293,          ///<
        TIM_Millisecond_294,          ///<
        TIM_Millisecond_295,          ///<
        TIM_Millisecond_296,          ///<
        TIM_Millisecond_297,          ///<
        TIM_Millisecond_298,          ///<
        TIM_Millisecond_299,          ///<
        TIM_Millisecond_300,          ///<
        TIM_Millisecond_301,          ///<
        TIM_Millisecond_302,          ///<
        TIM_Millisecond_303,          ///<
        TIM_Millisecond_304,          ///<
        TIM_Millisecond_305,          ///<
        TIM_Millisecond_306,          ///<
        TIM_Millisecond_307,          ///<
        TIM_Millisecond_308,          ///<
        TIM_Millisecond_309,          ///<
        TIM_Millisecond_310,          ///<
        TIM_Millisecond_311,          ///<
        TIM_Millisecond_312,          ///<
        TIM_Millisecond_313,          ///<
        TIM_Millisecond_314,          ///<
        TIM_Millisecond_315,          ///<
        TIM_Millisecond_316,          ///<
        TIM_Millisecond_317,          ///<
        TIM_Millisecond_318,          ///<
        TIM_Millisecond_319,          ///<
        TIM_Millisecond_320,          ///<
        TIM_Millisecond_321,          ///<
        TIM_Millisecond_322,          ///<
        TIM_Millisecond_323,          ///<
        TIM_Millisecond_324,          ///<
        TIM_Millisecond_325,          ///<
        TIM_Millisecond_326,          ///<
        TIM_Millisecond_327,          ///<
        TIM_Millisecond_328,          ///<
        TIM_Millisecond_329,          ///<
        TIM_Millisecond_330,          ///<
        TIM_Millisecond_331,          ///<
        TIM_Millisecond_332,          ///<
        TIM_Millisecond_333,          ///<
        TIM_Millisecond_334,          ///<
        TIM_Millisecond_335,          ///<
        TIM_Millisecond_336,          ///<
        TIM_Millisecond_337,          ///<
        TIM_Millisecond_338,          ///<
        TIM_Millisecond_339,          ///<
        TIM_Millisecond_340,          ///<
        TIM_Millisecond_341,          ///<
        TIM_Millisecond_342,          ///<
        TIM_Millisecond_343,          ///<
        TIM_Millisecond_344,          ///<
        TIM_Millisecond_345,          ///<
        TIM_Millisecond_346,          ///<
        TIM_Millisecond_347,          ///<
        TIM_Millisecond_348,          ///<
        TIM_Millisecond_349,          ///<
        TIM_Millisecond_350,          ///<
        TIM_Millisecond_351,          ///<
        TIM_Millisecond_352,          ///<
        TIM_Millisecond_353,          ///<
        TIM_Millisecond_354,          ///<
        TIM_Millisecond_355,          ///<
        TIM_Millisecond_356,          ///<
        TIM_Millisecond_357,          ///<
        TIM_Millisecond_358,          ///<
        TIM_Millisecond_359,          ///<
        TIM_Millisecond_360,          ///<
        TIM_Millisecond_361,          ///<
        TIM_Millisecond_362,          ///<
        TIM_Millisecond_363,          ///<
        TIM_Millisecond_364,          ///<
        TIM_Millisecond_365,          ///<
        TIM_Millisecond_366,          ///<
        TIM_Millisecond_367,          ///<
        TIM_Millisecond_368,          ///<
        TIM_Millisecond_369,          ///<
        TIM_Millisecond_370,          ///<
        TIM_Millisecond_371,          ///<
        TIM_Millisecond_372,          ///<
        TIM_Millisecond_373,          ///<
        TIM_Millisecond_374,          ///<
        TIM_Millisecond_375,          ///<
        TIM_Millisecond_376,          ///<
        TIM_Millisecond_377,          ///<
        TIM_Millisecond_378,          ///<
        TIM_Millisecond_379,          ///<
        TIM_Millisecond_380,          ///<
        TIM_Millisecond_381,          ///<
        TIM_Millisecond_382,          ///<
        TIM_Millisecond_383,          ///<
        TIM_Millisecond_384,          ///<
        TIM_Millisecond_385,          ///<
        TIM_Millisecond_386,          ///<
        TIM_Millisecond_387,          ///<
        TIM_Millisecond_388,          ///<
        TIM_Millisecond_389,          ///<
        TIM_Millisecond_390,          ///<
        TIM_Millisecond_391,          ///<
        TIM_Millisecond_392,          ///<
        TIM_Millisecond_393,          ///<
        TIM_Millisecond_394,          ///<
        TIM_Millisecond_395,          ///<
        TIM_Millisecond_396,          ///<
        TIM_Millisecond_397,          ///<
        TIM_Millisecond_398,          ///<
        TIM_Millisecond_399,          ///<
        TIM_Millisecond_400,          ///<
        TIM_Millisecond_401,          ///<
        TIM_Millisecond_402,          ///<
        TIM_Millisecond_403,          ///<
        TIM_Millisecond_404,          ///<
        TIM_Millisecond_405,          ///<
        TIM_Millisecond_406,          ///<
        TIM_Millisecond_407,          ///<
        TIM_Millisecond_408,          ///<
        TIM_Millisecond_409,          ///<
        TIM_Millisecond_410,          ///<
        TIM_Millisecond_411,          ///<
        TIM_Millisecond_412,          ///<
        TIM_Millisecond_413,          ///<
        TIM_Millisecond_414,          ///<
        TIM_Millisecond_415,          ///<
        TIM_Millisecond_416,          ///<
        TIM_Millisecond_417,          ///<
        TIM_Millisecond_418,          ///<
        TIM_Millisecond_419,          ///<
        TIM_Millisecond_420,          ///<
        TIM_Millisecond_421,          ///<
        TIM_Millisecond_422,          ///<
        TIM_Millisecond_423,          ///<
        TIM_Millisecond_424,          ///<
        TIM_Millisecond_425,          ///<
        TIM_Millisecond_426,          ///<
        TIM_Millisecond_427,          ///<
        TIM_Millisecond_428,          ///<
        TIM_Millisecond_429,          ///<
        TIM_Millisecond_430,          ///<
        TIM_Millisecond_431,          ///<
        TIM_Millisecond_432,          ///<
        TIM_Millisecond_433,          ///<
        TIM_Millisecond_434,          ///<
        TIM_Millisecond_435,          ///<
        TIM_Millisecond_436,          ///<
        TIM_Millisecond_437,          ///<
        TIM_Millisecond_438,          ///<
        TIM_Millisecond_439,          ///<
        TIM_Millisecond_440,          ///<
        TIM_Millisecond_441,          ///<
        TIM_Millisecond_442,          ///<
        TIM_Millisecond_443,          ///<
        TIM_Millisecond_444,          ///<
        TIM_Millisecond_445,          ///<
        TIM_Millisecond_446,          ///<
        TIM_Millisecond_447,          ///<
        TIM_Millisecond_448,          ///<
        TIM_Millisecond_449,          ///<
        TIM_Millisecond_450,          ///<
        TIM_Millisecond_451,          ///<
        TIM_Millisecond_452,          ///<
        TIM_Millisecond_453,          ///<
        TIM_Millisecond_454,          ///<
        TIM_Millisecond_455,          ///<
        TIM_Millisecond_456,          ///<
        TIM_Millisecond_457,          ///<
        TIM_Millisecond_458,          ///<
        TIM_Millisecond_459,          ///<
        TIM_Millisecond_460,          ///<
        TIM_Millisecond_461,          ///<
        TIM_Millisecond_462,          ///<
        TIM_Millisecond_463,          ///<
        TIM_Millisecond_464,          ///<
        TIM_Millisecond_465,          ///<
        TIM_Millisecond_466,          ///<
        TIM_Millisecond_467,          ///<
        TIM_Millisecond_468,          ///<
        TIM_Millisecond_469,          ///<
        TIM_Millisecond_470,          ///<
        TIM_Millisecond_471,          ///<
        TIM_Millisecond_472,          ///<
        TIM_Millisecond_473,          ///<
        TIM_Millisecond_474,          ///<
        TIM_Millisecond_475,          ///<
        TIM_Millisecond_476,          ///<
        TIM_Millisecond_477,          ///<
        TIM_Millisecond_478,          ///<
        TIM_Millisecond_479,          ///<
        TIM_Millisecond_480,          ///<
        TIM_Millisecond_481,          ///<
        TIM_Millisecond_482,          ///<
        TIM_Millisecond_483,          ///<
        TIM_Millisecond_484,          ///<
        TIM_Millisecond_485,          ///<
        TIM_Millisecond_486,          ///<
        TIM_Millisecond_487,          ///<
        TIM_Millisecond_488,          ///<
        TIM_Millisecond_489,          ///<
        TIM_Millisecond_490,          ///<
        TIM_Millisecond_491,          ///<
        TIM_Millisecond_492,          ///<
        TIM_Millisecond_493,          ///<
        TIM_Millisecond_494,          ///<
        TIM_Millisecond_495,          ///<
        TIM_Millisecond_496,          ///<
        TIM_Millisecond_497,          ///<
        TIM_Millisecond_498,          ///<
        TIM_Millisecond_499,          ///<
        TIM_Millisecond_500,          ///<
        TIM_Millisecond_501,          ///<
        TIM_Millisecond_502,          ///<
        TIM_Millisecond_503,          ///<
        TIM_Millisecond_504,          ///<
        TIM_Millisecond_505,          ///<
        TIM_Millisecond_506,          ///<
        TIM_Millisecond_507,          ///<
        TIM_Millisecond_508,          ///<
        TIM_Millisecond_509,          ///<
        TIM_Millisecond_510,          ///<
        TIM_Millisecond_511,          ///<
        TIM_Millisecond_512,          ///<
        TIM_Millisecond_513,          ///<
        TIM_Millisecond_514,          ///<
        TIM_Millisecond_515,          ///<
        TIM_Millisecond_516,          ///<
        TIM_Millisecond_517,          ///<
        TIM_Millisecond_518,          ///<
        TIM_Millisecond_519,          ///<
        TIM_Millisecond_520,          ///<
        TIM_Millisecond_521,          ///<
        TIM_Millisecond_522,          ///<
        TIM_Millisecond_523,          ///<
        TIM_Millisecond_524,          ///<
        TIM_Millisecond_525,          ///<
        TIM_Millisecond_526,          ///<
        TIM_Millisecond_527,          ///<
        TIM_Millisecond_528,          ///<
        TIM_Millisecond_529,          ///<
        TIM_Millisecond_530,          ///<
        TIM_Millisecond_531,          ///<
        TIM_Millisecond_532,          ///<
        TIM_Millisecond_533,          ///<
        TIM_Millisecond_534,          ///<
        TIM_Millisecond_535,          ///<
        TIM_Millisecond_536,          ///<
        TIM_Millisecond_537,          ///<
        TIM_Millisecond_538,          ///<
        TIM_Millisecond_539,          ///<
        TIM_Millisecond_540,          ///<
        TIM_Millisecond_541,          ///<
        TIM_Millisecond_542,          ///<
        TIM_Millisecond_543,          ///<
        TIM_Millisecond_544,          ///<
        TIM_Millisecond_545,          ///<
        TIM_Millisecond_546,          ///<
        TIM_Millisecond_547,          ///<
        TIM_Millisecond_548,          ///<
        TIM_Millisecond_549,          ///<
        TIM_Millisecond_550,          ///<
        TIM_Millisecond_551,          ///<
        TIM_Millisecond_552,          ///<
        TIM_Millisecond_553,          ///<
        TIM_Millisecond_554,          ///<
        TIM_Millisecond_555,          ///<
        TIM_Millisecond_556,          ///<
        TIM_Millisecond_557,          ///<
        TIM_Millisecond_558,          ///<
        TIM_Millisecond_559,          ///<
        TIM_Millisecond_560,          ///<
        TIM_Millisecond_561,          ///<
        TIM_Millisecond_562,          ///<
        TIM_Millisecond_563,          ///<
        TIM_Millisecond_564,          ///<
        TIM_Millisecond_565,          ///<
        TIM_Millisecond_566,          ///<
        TIM_Millisecond_567,          ///<
        TIM_Millisecond_568,          ///<
        TIM_Millisecond_569,          ///<
        TIM_Millisecond_570,          ///<
        TIM_Millisecond_571,          ///<
        TIM_Millisecond_572,          ///<
        TIM_Millisecond_573,          ///<
        TIM_Millisecond_574,          ///<
        TIM_Millisecond_575,          ///<
        TIM_Millisecond_576,          ///<
        TIM_Millisecond_577,          ///<
        TIM_Millisecond_578,          ///<
        TIM_Millisecond_579,          ///<
        TIM_Millisecond_580,          ///<
        TIM_Millisecond_581,          ///<
        TIM_Millisecond_582,          ///<
        TIM_Millisecond_583,          ///<
        TIM_Millisecond_584,          ///<
        TIM_Millisecond_585,          ///<
        TIM_Millisecond_586,          ///<
        TIM_Millisecond_587,          ///<
        TIM_Millisecond_588,          ///<
        TIM_Millisecond_589,          ///<
        TIM_Millisecond_590,          ///<
        TIM_Millisecond_591,          ///<
        TIM_Millisecond_592,          ///<
        TIM_Millisecond_593,          ///<
        TIM_Millisecond_594,          ///<
        TIM_Millisecond_595,          ///<
        TIM_Millisecond_596,          ///<
        TIM_Millisecond_597,          ///<
        TIM_Millisecond_598,          ///<
        TIM_Millisecond_599,          ///<
        TIM_Millisecond_600,          ///<
        TIM_Millisecond_601,          ///<
        TIM_Millisecond_602,          ///<
        TIM_Millisecond_603,          ///<
        TIM_Millisecond_604,          ///<
        TIM_Millisecond_605,          ///<
        TIM_Millisecond_606,          ///<
        TIM_Millisecond_607,          ///<
        TIM_Millisecond_608,          ///<
        TIM_Millisecond_609,          ///<
        TIM_Millisecond_610,          ///<
        TIM_Millisecond_611,          ///<
        TIM_Millisecond_612,          ///<
        TIM_Millisecond_613,          ///<
        TIM_Millisecond_614,          ///<
        TIM_Millisecond_615,          ///<
        TIM_Millisecond_616,          ///<
        TIM_Millisecond_617,          ///<
        TIM_Millisecond_618,          ///<
        TIM_Millisecond_619,          ///<
        TIM_Millisecond_620,          ///<
        TIM_Millisecond_621,          ///<
        TIM_Millisecond_622,          ///<
        TIM_Millisecond_623,          ///<
        TIM_Millisecond_624,          ///<
        TIM_Millisecond_625,          ///<
        TIM_Millisecond_626,          ///<
        TIM_Millisecond_627,          ///<
        TIM_Millisecond_628,          ///<
        TIM_Millisecond_629,          ///<
        TIM_Millisecond_630,          ///<
        TIM_Millisecond_631,          ///<
        TIM_Millisecond_632,          ///<
        TIM_Millisecond_633,          ///<
        TIM_Millisecond_634,          ///<
        TIM_Millisecond_635,          ///<
        TIM_Millisecond_636,          ///<
        TIM_Millisecond_637,          ///<
        TIM_Millisecond_638,          ///<
        TIM_Millisecond_639,          ///<
        TIM_Millisecond_640,          ///<
        TIM_Millisecond_641,          ///<
        TIM_Millisecond_642,          ///<
        TIM_Millisecond_643,          ///<
        TIM_Millisecond_644,          ///<
        TIM_Millisecond_645,          ///<
        TIM_Millisecond_646,          ///<
        TIM_Millisecond_647,          ///<
        TIM_Millisecond_648,          ///<
        TIM_Millisecond_649,          ///<
        TIM_Millisecond_650,          ///<
        TIM_Millisecond_651,          ///<
        TIM_Millisecond_652,          ///<
        TIM_Millisecond_653,          ///<
        TIM_Millisecond_654,          ///<
        TIM_Millisecond_655,          ///<
        TIM_Millisecond_656,          ///<
        TIM_Millisecond_657,          ///<
        TIM_Millisecond_658,          ///<
        TIM_Millisecond_659,          ///<
        TIM_Millisecond_660,          ///<
        TIM_Millisecond_661,          ///<
        TIM_Millisecond_662,          ///<
        TIM_Millisecond_663,          ///<
        TIM_Millisecond_664,          ///<
        TIM_Millisecond_665,          ///<
        TIM_Millisecond_666,          ///<
        TIM_Millisecond_667,          ///<
        TIM_Millisecond_668,          ///<
        TIM_Millisecond_669,          ///<
        TIM_Millisecond_670,          ///<
        TIM_Millisecond_671,          ///<
        TIM_Millisecond_672,          ///<
        TIM_Millisecond_673,          ///<
        TIM_Millisecond_674,          ///<
        TIM_Millisecond_675,          ///<
        TIM_Millisecond_676,          ///<
        TIM_Millisecond_677,          ///<
        TIM_Millisecond_678,          ///<
        TIM_Millisecond_679,          ///<
        TIM_Millisecond_680,          ///<
        TIM_Millisecond_681,          ///<
        TIM_Millisecond_682,          ///<
        TIM_Millisecond_683,          ///<
        TIM_Millisecond_684,          ///<
        TIM_Millisecond_685,          ///<
        TIM_Millisecond_686,          ///<
        TIM_Millisecond_687,          ///<
        TIM_Millisecond_688,          ///<
        TIM_Millisecond_689,          ///<
        TIM_Millisecond_690,          ///<
        TIM_Millisecond_691,          ///<
        TIM_Millisecond_692,          ///<
        TIM_Millisecond_693,          ///<
        TIM_Millisecond_694,          ///<
        TIM_Millisecond_695,          ///<
        TIM_Millisecond_696,          ///<
        TIM_Millisecond_697,          ///<
        TIM_Millisecond_698,          ///<
        TIM_Millisecond_699,          ///<
        TIM_Millisecond_700,          ///<
        TIM_Millisecond_701,          ///<
        TIM_Millisecond_702,          ///<
        TIM_Millisecond_703,          ///<
        TIM_Millisecond_704,          ///<
        TIM_Millisecond_705,          ///<
        TIM_Millisecond_706,          ///<
        TIM_Millisecond_707,          ///<
        TIM_Millisecond_708,          ///<
        TIM_Millisecond_709,          ///<
        TIM_Millisecond_710,          ///<
        TIM_Millisecond_711,          ///<
        TIM_Millisecond_712,          ///<
        TIM_Millisecond_713,          ///<
        TIM_Millisecond_714,          ///<
        TIM_Millisecond_715,          ///<
        TIM_Millisecond_716,          ///<
        TIM_Millisecond_717,          ///<
        TIM_Millisecond_718,          ///<
        TIM_Millisecond_719,          ///<
        TIM_Millisecond_720,          ///<
        TIM_Millisecond_721,          ///<
        TIM_Millisecond_722,          ///<
        TIM_Millisecond_723,          ///<
        TIM_Millisecond_724,          ///<
        TIM_Millisecond_725,          ///<
        TIM_Millisecond_726,          ///<
        TIM_Millisecond_727,          ///<
        TIM_Millisecond_728,          ///<
        TIM_Millisecond_729,          ///<
        TIM_Millisecond_730,          ///<
        TIM_Millisecond_731,          ///<
        TIM_Millisecond_732,          ///<
        TIM_Millisecond_733,          ///<
        TIM_Millisecond_734,          ///<
        TIM_Millisecond_735,          ///<
        TIM_Millisecond_736,          ///<
        TIM_Millisecond_737,          ///<
        TIM_Millisecond_738,          ///<
        TIM_Millisecond_739,          ///<
        TIM_Millisecond_740,          ///<
        TIM_Millisecond_741,          ///<
        TIM_Millisecond_742,          ///<
        TIM_Millisecond_743,          ///<
        TIM_Millisecond_744,          ///<
        TIM_Millisecond_745,          ///<
        TIM_Millisecond_746,          ///<
        TIM_Millisecond_747,          ///<
        TIM_Millisecond_748,          ///<
        TIM_Millisecond_749,          ///<
        TIM_Millisecond_750,          ///<
        TIM_Millisecond_751,          ///<
        TIM_Millisecond_752,          ///<
        TIM_Millisecond_753,          ///<
        TIM_Millisecond_754,          ///<
        TIM_Millisecond_755,          ///<
        TIM_Millisecond_756,          ///<
        TIM_Millisecond_757,          ///<
        TIM_Millisecond_758,          ///<
        TIM_Millisecond_759,          ///<
        TIM_Millisecond_760,          ///<
        TIM_Millisecond_761,          ///<
        TIM_Millisecond_762,          ///<
        TIM_Millisecond_763,          ///<
        TIM_Millisecond_764,          ///<
        TIM_Millisecond_765,          ///<
        TIM_Millisecond_766,          ///<
        TIM_Millisecond_767,          ///<
        TIM_Millisecond_768,          ///<
        TIM_Millisecond_769,          ///<
        TIM_Millisecond_770,          ///<
        TIM_Millisecond_771,          ///<
        TIM_Millisecond_772,          ///<
        TIM_Millisecond_773,          ///<
        TIM_Millisecond_774,          ///<
        TIM_Millisecond_775,          ///<
        TIM_Millisecond_776,          ///<
        TIM_Millisecond_777,          ///<
        TIM_Millisecond_778,          ///<
        TIM_Millisecond_779,          ///<
        TIM_Millisecond_780,          ///<
        TIM_Millisecond_781,          ///<
        TIM_Millisecond_782,          ///<
        TIM_Millisecond_783,          ///<
        TIM_Millisecond_784,          ///<
        TIM_Millisecond_785,          ///<
        TIM_Millisecond_786,          ///<
        TIM_Millisecond_787,          ///<
        TIM_Millisecond_788,          ///<
        TIM_Millisecond_789,          ///<
        TIM_Millisecond_790,          ///<
        TIM_Millisecond_791,          ///<
        TIM_Millisecond_792,          ///<
        TIM_Millisecond_793,          ///<
        TIM_Millisecond_794,          ///<
        TIM_Millisecond_795,          ///<
        TIM_Millisecond_796,          ///<
        TIM_Millisecond_797,          ///<
        TIM_Millisecond_798,          ///<
        TIM_Millisecond_799,          ///<
        TIM_Millisecond_800,          ///<
        TIM_Millisecond_801,          ///<
        TIM_Millisecond_802,          ///<
        TIM_Millisecond_803,          ///<
        TIM_Millisecond_804,          ///<
        TIM_Millisecond_805,          ///<
        TIM_Millisecond_806,          ///<
        TIM_Millisecond_807,          ///<
        TIM_Millisecond_808,          ///<
        TIM_Millisecond_809,          ///<
        TIM_Millisecond_810,          ///<
        TIM_Millisecond_811,          ///<
        TIM_Millisecond_812,          ///<
        TIM_Millisecond_813,          ///<
        TIM_Millisecond_814,          ///<
        TIM_Millisecond_815,          ///<
        TIM_Millisecond_816,          ///<
        TIM_Millisecond_817,          ///<
        TIM_Millisecond_818,          ///<
        TIM_Millisecond_819,          ///<
        TIM_Millisecond_820,          ///<
        TIM_Millisecond_821,          ///<
        TIM_Millisecond_822,          ///<
        TIM_Millisecond_823,          ///<
        TIM_Millisecond_824,          ///<
        TIM_Millisecond_825,          ///<
        TIM_Millisecond_826,          ///<
        TIM_Millisecond_827,          ///<
        TIM_Millisecond_828,          ///<
        TIM_Millisecond_829,          ///<
        TIM_Millisecond_830,          ///<
        TIM_Millisecond_831,          ///<
        TIM_Millisecond_832,          ///<
        TIM_Millisecond_833,          ///<
        TIM_Millisecond_834,          ///<
        TIM_Millisecond_835,          ///<
        TIM_Millisecond_836,          ///<
        TIM_Millisecond_837,          ///<
        TIM_Millisecond_838,          ///<
        TIM_Millisecond_839,          ///<
        TIM_Millisecond_840,          ///<
        TIM_Millisecond_841,          ///<
        TIM_Millisecond_842,          ///<
        TIM_Millisecond_843,          ///<
        TIM_Millisecond_844,          ///<
        TIM_Millisecond_845,          ///<
        TIM_Millisecond_846,          ///<
        TIM_Millisecond_847,          ///<
        TIM_Millisecond_848,          ///<
        TIM_Millisecond_849,          ///<
        TIM_Millisecond_850,          ///<
        TIM_Millisecond_851,          ///<
        TIM_Millisecond_852,          ///<
        TIM_Millisecond_853,          ///<
        TIM_Millisecond_854,          ///<
        TIM_Millisecond_855,          ///<
        TIM_Millisecond_856,          ///<
        TIM_Millisecond_857,          ///<
        TIM_Millisecond_858,          ///<
        TIM_Millisecond_859,          ///<
        TIM_Millisecond_860,          ///<
        TIM_Millisecond_861,          ///<
        TIM_Millisecond_862,          ///<
        TIM_Millisecond_863,          ///<
        TIM_Millisecond_864,          ///<
        TIM_Millisecond_865,          ///<
        TIM_Millisecond_866,          ///<
        TIM_Millisecond_867,          ///<
        TIM_Millisecond_868,          ///<
        TIM_Millisecond_869,          ///<
        TIM_Millisecond_870,          ///<
        TIM_Millisecond_871,          ///<
        TIM_Millisecond_872,          ///<
        TIM_Millisecond_873,          ///<
        TIM_Millisecond_874,          ///<
        TIM_Millisecond_875,          ///<
        TIM_Millisecond_876,          ///<
        TIM_Millisecond_877,          ///<
        TIM_Millisecond_878,          ///<
        TIM_Millisecond_879,          ///<
        TIM_Millisecond_880,          ///<
        TIM_Millisecond_881,          ///<
        TIM_Millisecond_882,          ///<
        TIM_Millisecond_883,          ///<
        TIM_Millisecond_884,          ///<
        TIM_Millisecond_885,          ///<
        TIM_Millisecond_886,          ///<
        TIM_Millisecond_887,          ///<
        TIM_Millisecond_888,          ///<
        TIM_Millisecond_889,          ///<
        TIM_Millisecond_890,          ///<
        TIM_Millisecond_891,          ///<
        TIM_Millisecond_892,          ///<
        TIM_Millisecond_893,          ///<
        TIM_Millisecond_894,          ///<
        TIM_Millisecond_895,          ///<
        TIM_Millisecond_896,          ///<
        TIM_Millisecond_897,          ///<
        TIM_Millisecond_898,          ///<
        TIM_Millisecond_899,          ///<
        TIM_Millisecond_900,          ///<
        TIM_Millisecond_901,          ///<
        TIM_Millisecond_902,          ///<
        TIM_Millisecond_903,          ///<
        TIM_Millisecond_904,          ///<
        TIM_Millisecond_905,          ///<
        TIM_Millisecond_906,          ///<
        TIM_Millisecond_907,          ///<
        TIM_Millisecond_908,          ///<
        TIM_Millisecond_909,          ///<
        TIM_Millisecond_910,          ///<
        TIM_Millisecond_911,          ///<
        TIM_Millisecond_912,          ///<
        TIM_Millisecond_913,          ///<
        TIM_Millisecond_914,          ///<
        TIM_Millisecond_915,          ///<
        TIM_Millisecond_916,          ///<
        TIM_Millisecond_917,          ///<
        TIM_Millisecond_918,          ///<
        TIM_Millisecond_919,          ///<
        TIM_Millisecond_920,          ///<
        TIM_Millisecond_921,          ///<
        TIM_Millisecond_922,          ///<
        TIM_Millisecond_923,          ///<
        TIM_Millisecond_924,          ///<
        TIM_Millisecond_925,          ///<
        TIM_Millisecond_926,          ///<
        TIM_Millisecond_927,          ///<
        TIM_Millisecond_928,          ///<
        TIM_Millisecond_929,          ///<
        TIM_Millisecond_930,          ///<
        TIM_Millisecond_931,          ///<
        TIM_Millisecond_932,          ///<
        TIM_Millisecond_933,          ///<
        TIM_Millisecond_934,          ///<
        TIM_Millisecond_935,          ///<
        TIM_Millisecond_936,          ///<
        TIM_Millisecond_937,          ///<
        TIM_Millisecond_938,          ///<
        TIM_Millisecond_939,          ///<
        TIM_Millisecond_940,          ///<
        TIM_Millisecond_941,          ///<
        TIM_Millisecond_942,          ///<
        TIM_Millisecond_943,          ///<
        TIM_Millisecond_944,          ///<
        TIM_Millisecond_945,          ///<
        TIM_Millisecond_946,          ///<
        TIM_Millisecond_947,          ///<
        TIM_Millisecond_948,          ///<
        TIM_Millisecond_949,          ///<
        TIM_Millisecond_950,          ///<
        TIM_Millisecond_951,          ///<
        TIM_Millisecond_952,          ///<
        TIM_Millisecond_953,          ///<
        TIM_Millisecond_954,          ///<
        TIM_Millisecond_955,          ///<
        TIM_Millisecond_956,          ///<
        TIM_Millisecond_957,          ///<
        TIM_Millisecond_958,          ///<
        TIM_Millisecond_959,          ///<
        TIM_Millisecond_960,          ///<
        TIM_Millisecond_961,          ///<
        TIM_Millisecond_962,          ///<
        TIM_Millisecond_963,          ///<
        TIM_Millisecond_964,          ///<
        TIM_Millisecond_965,          ///<
        TIM_Millisecond_966,          ///<
        TIM_Millisecond_967,          ///<
        TIM_Millisecond_968,          ///<
        TIM_Millisecond_969,          ///<
        TIM_Millisecond_970,          ///<
        TIM_Millisecond_971,          ///<
        TIM_Millisecond_972,          ///<
        TIM_Millisecond_973,          ///<
        TIM_Millisecond_974,          ///<
        TIM_Millisecond_975,          ///<
        TIM_Millisecond_976,          ///<
        TIM_Millisecond_977,          ///<
        TIM_Millisecond_978,          ///<
        TIM_Millisecond_979,          ///<
        TIM_Millisecond_980,          ///<
        TIM_Millisecond_981,          ///<
        TIM_Millisecond_982,          ///<
        TIM_Millisecond_983,          ///<
        TIM_Millisecond_984,          ///<
        TIM_Millisecond_985,          ///<
        TIM_Millisecond_986,          ///<
        TIM_Millisecond_987,          ///<
        TIM_Millisecond_988,          ///<
        TIM_Millisecond_989,          ///<
        TIM_Millisecond_990,          ///<
        TIM_Millisecond_991,          ///<
        TIM_Millisecond_992,          ///<
        TIM_Millisecond_993,          ///<
        TIM_Millisecond_994,          ///<
        TIM_Millisecond_995,          ///<
        TIM_Millisecond_996,          ///<
        TIM_Millisecond_997,          ///<
        TIM_Millisecond_998,          ///<
        TIM_Millisecond_999,          ///< Millisecond 999 (Maximum)
    } TIM_Millisecond_t;

    /**
     *  @brief TIM Microsecond Type
     *
     *  @enum TIM_Microsecond_t
     */
    typedef enum TIM_Microsecond
    {
        TIM_Microsecond_Unknown = -1, ///< Default
        TIM_Microsecond_000 = 0,      ///< Microsecond 000 (Minimum)
        TIM_Microsecond_001,          ///<
        TIM_Microsecond_002,          ///<
        TIM_Microsecond_003,          ///<
        TIM_Microsecond_004,          ///<
        TIM_Microsecond_005,          ///<
        TIM_Microsecond_006,          ///<
        TIM_Microsecond_007,          ///<
        TIM_Microsecond_008,          ///<
        TIM_Microsecond_009,          ///<
        TIM_Microsecond_010,          ///<
        TIM_Microsecond_011,          ///<
        TIM_Microsecond_012,          ///<
        TIM_Microsecond_013,          ///<
        TIM_Microsecond_014,          ///<
        TIM_Microsecond_015,          ///<
        TIM_Microsecond_016,          ///<
        TIM_Microsecond_017,          ///<
        TIM_Microsecond_018,          ///<
        TIM_Microsecond_019,          ///<
        TIM_Microsecond_020,          ///<
        TIM_Microsecond_021,          ///<
        TIM_Microsecond_022,          ///<
        TIM_Microsecond_023,          ///<
        TIM_Microsecond_024,          ///<
        TIM_Microsecond_025,          ///<
        TIM_Microsecond_026,          ///<
        TIM_Microsecond_027,          ///<
        TIM_Microsecond_028,          ///<
        TIM_Microsecond_029,          ///<
        TIM_Microsecond_030,          ///<
        TIM_Microsecond_031,          ///<
        TIM_Microsecond_032,          ///<
        TIM_Microsecond_033,          ///<
        TIM_Microsecond_034,          ///<
        TIM_Microsecond_035,          ///<
        TIM_Microsecond_036,          ///<
        TIM_Microsecond_037,          ///<
        TIM_Microsecond_038,          ///<
        TIM_Microsecond_039,          ///<
        TIM_Microsecond_040,          ///<
        TIM_Microsecond_041,          ///<
        TIM_Microsecond_042,          ///<
        TIM_Microsecond_043,          ///<
        TIM_Microsecond_044,          ///<
        TIM_Microsecond_045,          ///<
        TIM_Microsecond_046,          ///<
        TIM_Microsecond_047,          ///<
        TIM_Microsecond_048,          ///<
        TIM_Microsecond_049,          ///<
        TIM_Microsecond_050,          ///<
        TIM_Microsecond_051,          ///<
        TIM_Microsecond_052,          ///<
        TIM_Microsecond_053,          ///<
        TIM_Microsecond_054,          ///<
        TIM_Microsecond_055,          ///<
        TIM_Microsecond_056,          ///<
        TIM_Microsecond_057,          ///<
        TIM_Microsecond_058,          ///<
        TIM_Microsecond_059,          ///<
        TIM_Microsecond_060,          ///<
        TIM_Microsecond_061,          ///<
        TIM_Microsecond_062,          ///<
        TIM_Microsecond_063,          ///<
        TIM_Microsecond_064,          ///<
        TIM_Microsecond_065,          ///<
        TIM_Microsecond_066,          ///<
        TIM_Microsecond_067,          ///<
        TIM_Microsecond_068,          ///<
        TIM_Microsecond_069,          ///<
        TIM_Microsecond_070,          ///<
        TIM_Microsecond_071,          ///<
        TIM_Microsecond_072,          ///<
        TIM_Microsecond_073,          ///<
        TIM_Microsecond_074,          ///<
        TIM_Microsecond_075,          ///<
        TIM_Microsecond_076,          ///<
        TIM_Microsecond_077,          ///<
        TIM_Microsecond_078,          ///<
        TIM_Microsecond_079,          ///<
        TIM_Microsecond_080,          ///<
        TIM_Microsecond_081,          ///<
        TIM_Microsecond_082,          ///<
        TIM_Microsecond_083,          ///<
        TIM_Microsecond_084,          ///<
        TIM_Microsecond_085,          ///<
        TIM_Microsecond_086,          ///<
        TIM_Microsecond_087,          ///<
        TIM_Microsecond_088,          ///<
        TIM_Microsecond_089,          ///<
        TIM_Microsecond_090,          ///<
        TIM_Microsecond_091,          ///<
        TIM_Microsecond_092,          ///<
        TIM_Microsecond_093,          ///<
        TIM_Microsecond_094,          ///<
        TIM_Microsecond_095,          ///<
        TIM_Microsecond_096,          ///<
        TIM_Microsecond_097,          ///<
        TIM_Microsecond_098,          ///<
        TIM_Microsecond_099,          ///<
        TIM_Microsecond_100,          ///<
        TIM_Microsecond_101,          ///<
        TIM_Microsecond_102,          ///<
        TIM_Microsecond_103,          ///<
        TIM_Microsecond_104,          ///<
        TIM_Microsecond_105,          ///<
        TIM_Microsecond_106,          ///<
        TIM_Microsecond_107,          ///<
        TIM_Microsecond_108,          ///<
        TIM_Microsecond_109,          ///<
        TIM_Microsecond_110,          ///<
        TIM_Microsecond_111,          ///<
        TIM_Microsecond_112,          ///<
        TIM_Microsecond_113,          ///<
        TIM_Microsecond_114,          ///<
        TIM_Microsecond_115,          ///<
        TIM_Microsecond_116,          ///<
        TIM_Microsecond_117,          ///<
        TIM_Microsecond_118,          ///<
        TIM_Microsecond_119,          ///<
        TIM_Microsecond_120,          ///<
        TIM_Microsecond_121,          ///<
        TIM_Microsecond_122,          ///<
        TIM_Microsecond_123,          ///<
        TIM_Microsecond_124,          ///<
        TIM_Microsecond_125,          ///<
        TIM_Microsecond_126,          ///<
        TIM_Microsecond_127,          ///<
        TIM_Microsecond_128,          ///<
        TIM_Microsecond_129,          ///<
        TIM_Microsecond_130,          ///<
        TIM_Microsecond_131,          ///<
        TIM_Microsecond_132,          ///<
        TIM_Microsecond_133,          ///<
        TIM_Microsecond_134,          ///<
        TIM_Microsecond_135,          ///<
        TIM_Microsecond_136,          ///<
        TIM_Microsecond_137,          ///<
        TIM_Microsecond_138,          ///<
        TIM_Microsecond_139,          ///<
        TIM_Microsecond_140,          ///<
        TIM_Microsecond_141,          ///<
        TIM_Microsecond_142,          ///<
        TIM_Microsecond_143,          ///<
        TIM_Microsecond_144,          ///<
        TIM_Microsecond_145,          ///<
        TIM_Microsecond_146,          ///<
        TIM_Microsecond_147,          ///<
        TIM_Microsecond_148,          ///<
        TIM_Microsecond_149,          ///<
        TIM_Microsecond_150,          ///<
        TIM_Microsecond_151,          ///<
        TIM_Microsecond_152,          ///<
        TIM_Microsecond_153,          ///<
        TIM_Microsecond_154,          ///<
        TIM_Microsecond_155,          ///<
        TIM_Microsecond_156,          ///<
        TIM_Microsecond_157,          ///<
        TIM_Microsecond_158,          ///<
        TIM_Microsecond_159,          ///<
        TIM_Microsecond_160,          ///<
        TIM_Microsecond_161,          ///<
        TIM_Microsecond_162,          ///<
        TIM_Microsecond_163,          ///<
        TIM_Microsecond_164,          ///<
        TIM_Microsecond_165,          ///<
        TIM_Microsecond_166,          ///<
        TIM_Microsecond_167,          ///<
        TIM_Microsecond_168,          ///<
        TIM_Microsecond_169,          ///<
        TIM_Microsecond_170,          ///<
        TIM_Microsecond_171,          ///<
        TIM_Microsecond_172,          ///<
        TIM_Microsecond_173,          ///<
        TIM_Microsecond_174,          ///<
        TIM_Microsecond_175,          ///<
        TIM_Microsecond_176,          ///<
        TIM_Microsecond_177,          ///<
        TIM_Microsecond_178,          ///<
        TIM_Microsecond_179,          ///<
        TIM_Microsecond_180,          ///<
        TIM_Microsecond_181,          ///<
        TIM_Microsecond_182,          ///<
        TIM_Microsecond_183,          ///<
        TIM_Microsecond_184,          ///<
        TIM_Microsecond_185,          ///<
        TIM_Microsecond_186,          ///<
        TIM_Microsecond_187,          ///<
        TIM_Microsecond_188,          ///<
        TIM_Microsecond_189,          ///<
        TIM_Microsecond_190,          ///<
        TIM_Microsecond_191,          ///<
        TIM_Microsecond_192,          ///<
        TIM_Microsecond_193,          ///<
        TIM_Microsecond_194,          ///<
        TIM_Microsecond_195,          ///<
        TIM_Microsecond_196,          ///<
        TIM_Microsecond_197,          ///<
        TIM_Microsecond_198,          ///<
        TIM_Microsecond_199,          ///<
        TIM_Microsecond_200,          ///<
        TIM_Microsecond_201,          ///<
        TIM_Microsecond_202,          ///<
        TIM_Microsecond_203,          ///<
        TIM_Microsecond_204,          ///<
        TIM_Microsecond_205,          ///<
        TIM_Microsecond_206,          ///<
        TIM_Microsecond_207,          ///<
        TIM_Microsecond_208,          ///<
        TIM_Microsecond_209,          ///<
        TIM_Microsecond_210,          ///<
        TIM_Microsecond_211,          ///<
        TIM_Microsecond_212,          ///<
        TIM_Microsecond_213,          ///<
        TIM_Microsecond_214,          ///<
        TIM_Microsecond_215,          ///<
        TIM_Microsecond_216,          ///<
        TIM_Microsecond_217,          ///<
        TIM_Microsecond_218,          ///<
        TIM_Microsecond_219,          ///<
        TIM_Microsecond_220,          ///<
        TIM_Microsecond_221,          ///<
        TIM_Microsecond_222,          ///<
        TIM_Microsecond_223,          ///<
        TIM_Microsecond_224,          ///<
        TIM_Microsecond_225,          ///<
        TIM_Microsecond_226,          ///<
        TIM_Microsecond_227,          ///<
        TIM_Microsecond_228,          ///<
        TIM_Microsecond_229,          ///<
        TIM_Microsecond_230,          ///<
        TIM_Microsecond_231,          ///<
        TIM_Microsecond_232,          ///<
        TIM_Microsecond_233,          ///<
        TIM_Microsecond_234,          ///<
        TIM_Microsecond_235,          ///<
        TIM_Microsecond_236,          ///<
        TIM_Microsecond_237,          ///<
        TIM_Microsecond_238,          ///<
        TIM_Microsecond_239,          ///<
        TIM_Microsecond_240,          ///<
        TIM_Microsecond_241,          ///<
        TIM_Microsecond_242,          ///<
        TIM_Microsecond_243,          ///<
        TIM_Microsecond_244,          ///<
        TIM_Microsecond_245,          ///<
        TIM_Microsecond_246,          ///<
        TIM_Microsecond_247,          ///<
        TIM_Microsecond_248,          ///<
        TIM_Microsecond_249,          ///<
        TIM_Microsecond_250,          ///<
        TIM_Microsecond_251,          ///<
        TIM_Microsecond_252,          ///<
        TIM_Microsecond_253,          ///<
        TIM_Microsecond_254,          ///<
        TIM_Microsecond_255,          ///<
        TIM_Microsecond_256,          ///<
        TIM_Microsecond_257,          ///<
        TIM_Microsecond_258,          ///<
        TIM_Microsecond_259,          ///<
        TIM_Microsecond_260,          ///<
        TIM_Microsecond_261,          ///<
        TIM_Microsecond_262,          ///<
        TIM_Microsecond_263,          ///<
        TIM_Microsecond_264,          ///<
        TIM_Microsecond_265,          ///<
        TIM_Microsecond_266,          ///<
        TIM_Microsecond_267,          ///<
        TIM_Microsecond_268,          ///<
        TIM_Microsecond_269,          ///<
        TIM_Microsecond_270,          ///<
        TIM_Microsecond_271,          ///<
        TIM_Microsecond_272,          ///<
        TIM_Microsecond_273,          ///<
        TIM_Microsecond_274,          ///<
        TIM_Microsecond_275,          ///<
        TIM_Microsecond_276,          ///<
        TIM_Microsecond_277,          ///<
        TIM_Microsecond_278,          ///<
        TIM_Microsecond_279,          ///<
        TIM_Microsecond_280,          ///<
        TIM_Microsecond_281,          ///<
        TIM_Microsecond_282,          ///<
        TIM_Microsecond_283,          ///<
        TIM_Microsecond_284,          ///<
        TIM_Microsecond_285,          ///<
        TIM_Microsecond_286,          ///<
        TIM_Microsecond_287,          ///<
        TIM_Microsecond_288,          ///<
        TIM_Microsecond_289,          ///<
        TIM_Microsecond_290,          ///<
        TIM_Microsecond_291,          ///<
        TIM_Microsecond_292,          ///<
        TIM_Microsecond_293,          ///<
        TIM_Microsecond_294,          ///<
        TIM_Microsecond_295,          ///<
        TIM_Microsecond_296,          ///<
        TIM_Microsecond_297,          ///<
        TIM_Microsecond_298,          ///<
        TIM_Microsecond_299,          ///<
        TIM_Microsecond_300,          ///<
        TIM_Microsecond_301,          ///<
        TIM_Microsecond_302,          ///<
        TIM_Microsecond_303,          ///<
        TIM_Microsecond_304,          ///<
        TIM_Microsecond_305,          ///<
        TIM_Microsecond_306,          ///<
        TIM_Microsecond_307,          ///<
        TIM_Microsecond_308,          ///<
        TIM_Microsecond_309,          ///<
        TIM_Microsecond_310,          ///<
        TIM_Microsecond_311,          ///<
        TIM_Microsecond_312,          ///<
        TIM_Microsecond_313,          ///<
        TIM_Microsecond_314,          ///<
        TIM_Microsecond_315,          ///<
        TIM_Microsecond_316,          ///<
        TIM_Microsecond_317,          ///<
        TIM_Microsecond_318,          ///<
        TIM_Microsecond_319,          ///<
        TIM_Microsecond_320,          ///<
        TIM_Microsecond_321,          ///<
        TIM_Microsecond_322,          ///<
        TIM_Microsecond_323,          ///<
        TIM_Microsecond_324,          ///<
        TIM_Microsecond_325,          ///<
        TIM_Microsecond_326,          ///<
        TIM_Microsecond_327,          ///<
        TIM_Microsecond_328,          ///<
        TIM_Microsecond_329,          ///<
        TIM_Microsecond_330,          ///<
        TIM_Microsecond_331,          ///<
        TIM_Microsecond_332,          ///<
        TIM_Microsecond_333,          ///<
        TIM_Microsecond_334,          ///<
        TIM_Microsecond_335,          ///<
        TIM_Microsecond_336,          ///<
        TIM_Microsecond_337,          ///<
        TIM_Microsecond_338,          ///<
        TIM_Microsecond_339,          ///<
        TIM_Microsecond_340,          ///<
        TIM_Microsecond_341,          ///<
        TIM_Microsecond_342,          ///<
        TIM_Microsecond_343,          ///<
        TIM_Microsecond_344,          ///<
        TIM_Microsecond_345,          ///<
        TIM_Microsecond_346,          ///<
        TIM_Microsecond_347,          ///<
        TIM_Microsecond_348,          ///<
        TIM_Microsecond_349,          ///<
        TIM_Microsecond_350,          ///<
        TIM_Microsecond_351,          ///<
        TIM_Microsecond_352,          ///<
        TIM_Microsecond_353,          ///<
        TIM_Microsecond_354,          ///<
        TIM_Microsecond_355,          ///<
        TIM_Microsecond_356,          ///<
        TIM_Microsecond_357,          ///<
        TIM_Microsecond_358,          ///<
        TIM_Microsecond_359,          ///<
        TIM_Microsecond_360,          ///<
        TIM_Microsecond_361,          ///<
        TIM_Microsecond_362,          ///<
        TIM_Microsecond_363,          ///<
        TIM_Microsecond_364,          ///<
        TIM_Microsecond_365,          ///<
        TIM_Microsecond_366,          ///<
        TIM_Microsecond_367,          ///<
        TIM_Microsecond_368,          ///<
        TIM_Microsecond_369,          ///<
        TIM_Microsecond_370,          ///<
        TIM_Microsecond_371,          ///<
        TIM_Microsecond_372,          ///<
        TIM_Microsecond_373,          ///<
        TIM_Microsecond_374,          ///<
        TIM_Microsecond_375,          ///<
        TIM_Microsecond_376,          ///<
        TIM_Microsecond_377,          ///<
        TIM_Microsecond_378,          ///<
        TIM_Microsecond_379,          ///<
        TIM_Microsecond_380,          ///<
        TIM_Microsecond_381,          ///<
        TIM_Microsecond_382,          ///<
        TIM_Microsecond_383,          ///<
        TIM_Microsecond_384,          ///<
        TIM_Microsecond_385,          ///<
        TIM_Microsecond_386,          ///<
        TIM_Microsecond_387,          ///<
        TIM_Microsecond_388,          ///<
        TIM_Microsecond_389,          ///<
        TIM_Microsecond_390,          ///<
        TIM_Microsecond_391,          ///<
        TIM_Microsecond_392,          ///<
        TIM_Microsecond_393,          ///<
        TIM_Microsecond_394,          ///<
        TIM_Microsecond_395,          ///<
        TIM_Microsecond_396,          ///<
        TIM_Microsecond_397,          ///<
        TIM_Microsecond_398,          ///<
        TIM_Microsecond_399,          ///<
        TIM_Microsecond_400,          ///<
        TIM_Microsecond_401,          ///<
        TIM_Microsecond_402,          ///<
        TIM_Microsecond_403,          ///<
        TIM_Microsecond_404,          ///<
        TIM_Microsecond_405,          ///<
        TIM_Microsecond_406,          ///<
        TIM_Microsecond_407,          ///<
        TIM_Microsecond_408,          ///<
        TIM_Microsecond_409,          ///<
        TIM_Microsecond_410,          ///<
        TIM_Microsecond_411,          ///<
        TIM_Microsecond_412,          ///<
        TIM_Microsecond_413,          ///<
        TIM_Microsecond_414,          ///<
        TIM_Microsecond_415,          ///<
        TIM_Microsecond_416,          ///<
        TIM_Microsecond_417,          ///<
        TIM_Microsecond_418,          ///<
        TIM_Microsecond_419,          ///<
        TIM_Microsecond_420,          ///<
        TIM_Microsecond_421,          ///<
        TIM_Microsecond_422,          ///<
        TIM_Microsecond_423,          ///<
        TIM_Microsecond_424,          ///<
        TIM_Microsecond_425,          ///<
        TIM_Microsecond_426,          ///<
        TIM_Microsecond_427,          ///<
        TIM_Microsecond_428,          ///<
        TIM_Microsecond_429,          ///<
        TIM_Microsecond_430,          ///<
        TIM_Microsecond_431,          ///<
        TIM_Microsecond_432,          ///<
        TIM_Microsecond_433,          ///<
        TIM_Microsecond_434,          ///<
        TIM_Microsecond_435,          ///<
        TIM_Microsecond_436,          ///<
        TIM_Microsecond_437,          ///<
        TIM_Microsecond_438,          ///<
        TIM_Microsecond_439,          ///<
        TIM_Microsecond_440,          ///<
        TIM_Microsecond_441,          ///<
        TIM_Microsecond_442,          ///<
        TIM_Microsecond_443,          ///<
        TIM_Microsecond_444,          ///<
        TIM_Microsecond_445,          ///<
        TIM_Microsecond_446,          ///<
        TIM_Microsecond_447,          ///<
        TIM_Microsecond_448,          ///<
        TIM_Microsecond_449,          ///<
        TIM_Microsecond_450,          ///<
        TIM_Microsecond_451,          ///<
        TIM_Microsecond_452,          ///<
        TIM_Microsecond_453,          ///<
        TIM_Microsecond_454,          ///<
        TIM_Microsecond_455,          ///<
        TIM_Microsecond_456,          ///<
        TIM_Microsecond_457,          ///<
        TIM_Microsecond_458,          ///<
        TIM_Microsecond_459,          ///<
        TIM_Microsecond_460,          ///<
        TIM_Microsecond_461,          ///<
        TIM_Microsecond_462,          ///<
        TIM_Microsecond_463,          ///<
        TIM_Microsecond_464,          ///<
        TIM_Microsecond_465,          ///<
        TIM_Microsecond_466,          ///<
        TIM_Microsecond_467,          ///<
        TIM_Microsecond_468,          ///<
        TIM_Microsecond_469,          ///<
        TIM_Microsecond_470,          ///<
        TIM_Microsecond_471,          ///<
        TIM_Microsecond_472,          ///<
        TIM_Microsecond_473,          ///<
        TIM_Microsecond_474,          ///<
        TIM_Microsecond_475,          ///<
        TIM_Microsecond_476,          ///<
        TIM_Microsecond_477,          ///<
        TIM_Microsecond_478,          ///<
        TIM_Microsecond_479,          ///<
        TIM_Microsecond_480,          ///<
        TIM_Microsecond_481,          ///<
        TIM_Microsecond_482,          ///<
        TIM_Microsecond_483,          ///<
        TIM_Microsecond_484,          ///<
        TIM_Microsecond_485,          ///<
        TIM_Microsecond_486,          ///<
        TIM_Microsecond_487,          ///<
        TIM_Microsecond_488,          ///<
        TIM_Microsecond_489,          ///<
        TIM_Microsecond_490,          ///<
        TIM_Microsecond_491,          ///<
        TIM_Microsecond_492,          ///<
        TIM_Microsecond_493,          ///<
        TIM_Microsecond_494,          ///<
        TIM_Microsecond_495,          ///<
        TIM_Microsecond_496,          ///<
        TIM_Microsecond_497,          ///<
        TIM_Microsecond_498,          ///<
        TIM_Microsecond_499,          ///<
        TIM_Microsecond_500,          ///<
        TIM_Microsecond_501,          ///<
        TIM_Microsecond_502,          ///<
        TIM_Microsecond_503,          ///<
        TIM_Microsecond_504,          ///<
        TIM_Microsecond_505,          ///<
        TIM_Microsecond_506,          ///<
        TIM_Microsecond_507,          ///<
        TIM_Microsecond_508,          ///<
        TIM_Microsecond_509,          ///<
        TIM_Microsecond_510,          ///<
        TIM_Microsecond_511,          ///<
        TIM_Microsecond_512,          ///<
        TIM_Microsecond_513,          ///<
        TIM_Microsecond_514,          ///<
        TIM_Microsecond_515,          ///<
        TIM_Microsecond_516,          ///<
        TIM_Microsecond_517,          ///<
        TIM_Microsecond_518,          ///<
        TIM_Microsecond_519,          ///<
        TIM_Microsecond_520,          ///<
        TIM_Microsecond_521,          ///<
        TIM_Microsecond_522,          ///<
        TIM_Microsecond_523,          ///<
        TIM_Microsecond_524,          ///<
        TIM_Microsecond_525,          ///<
        TIM_Microsecond_526,          ///<
        TIM_Microsecond_527,          ///<
        TIM_Microsecond_528,          ///<
        TIM_Microsecond_529,          ///<
        TIM_Microsecond_530,          ///<
        TIM_Microsecond_531,          ///<
        TIM_Microsecond_532,          ///<
        TIM_Microsecond_533,          ///<
        TIM_Microsecond_534,          ///<
        TIM_Microsecond_535,          ///<
        TIM_Microsecond_536,          ///<
        TIM_Microsecond_537,          ///<
        TIM_Microsecond_538,          ///<
        TIM_Microsecond_539,          ///<
        TIM_Microsecond_540,          ///<
        TIM_Microsecond_541,          ///<
        TIM_Microsecond_542,          ///<
        TIM_Microsecond_543,          ///<
        TIM_Microsecond_544,          ///<
        TIM_Microsecond_545,          ///<
        TIM_Microsecond_546,          ///<
        TIM_Microsecond_547,          ///<
        TIM_Microsecond_548,          ///<
        TIM_Microsecond_549,          ///<
        TIM_Microsecond_550,          ///<
        TIM_Microsecond_551,          ///<
        TIM_Microsecond_552,          ///<
        TIM_Microsecond_553,          ///<
        TIM_Microsecond_554,          ///<
        TIM_Microsecond_555,          ///<
        TIM_Microsecond_556,          ///<
        TIM_Microsecond_557,          ///<
        TIM_Microsecond_558,          ///<
        TIM_Microsecond_559,          ///<
        TIM_Microsecond_560,          ///<
        TIM_Microsecond_561,          ///<
        TIM_Microsecond_562,          ///<
        TIM_Microsecond_563,          ///<
        TIM_Microsecond_564,          ///<
        TIM_Microsecond_565,          ///<
        TIM_Microsecond_566,          ///<
        TIM_Microsecond_567,          ///<
        TIM_Microsecond_568,          ///<
        TIM_Microsecond_569,          ///<
        TIM_Microsecond_570,          ///<
        TIM_Microsecond_571,          ///<
        TIM_Microsecond_572,          ///<
        TIM_Microsecond_573,          ///<
        TIM_Microsecond_574,          ///<
        TIM_Microsecond_575,          ///<
        TIM_Microsecond_576,          ///<
        TIM_Microsecond_577,          ///<
        TIM_Microsecond_578,          ///<
        TIM_Microsecond_579,          ///<
        TIM_Microsecond_580,          ///<
        TIM_Microsecond_581,          ///<
        TIM_Microsecond_582,          ///<
        TIM_Microsecond_583,          ///<
        TIM_Microsecond_584,          ///<
        TIM_Microsecond_585,          ///<
        TIM_Microsecond_586,          ///<
        TIM_Microsecond_587,          ///<
        TIM_Microsecond_588,          ///<
        TIM_Microsecond_589,          ///<
        TIM_Microsecond_590,          ///<
        TIM_Microsecond_591,          ///<
        TIM_Microsecond_592,          ///<
        TIM_Microsecond_593,          ///<
        TIM_Microsecond_594,          ///<
        TIM_Microsecond_595,          ///<
        TIM_Microsecond_596,          ///<
        TIM_Microsecond_597,          ///<
        TIM_Microsecond_598,          ///<
        TIM_Microsecond_599,          ///<
        TIM_Microsecond_600,          ///<
        TIM_Microsecond_601,          ///<
        TIM_Microsecond_602,          ///<
        TIM_Microsecond_603,          ///<
        TIM_Microsecond_604,          ///<
        TIM_Microsecond_605,          ///<
        TIM_Microsecond_606,          ///<
        TIM_Microsecond_607,          ///<
        TIM_Microsecond_608,          ///<
        TIM_Microsecond_609,          ///<
        TIM_Microsecond_610,          ///<
        TIM_Microsecond_611,          ///<
        TIM_Microsecond_612,          ///<
        TIM_Microsecond_613,          ///<
        TIM_Microsecond_614,          ///<
        TIM_Microsecond_615,          ///<
        TIM_Microsecond_616,          ///<
        TIM_Microsecond_617,          ///<
        TIM_Microsecond_618,          ///<
        TIM_Microsecond_619,          ///<
        TIM_Microsecond_620,          ///<
        TIM_Microsecond_621,          ///<
        TIM_Microsecond_622,          ///<
        TIM_Microsecond_623,          ///<
        TIM_Microsecond_624,          ///<
        TIM_Microsecond_625,          ///<
        TIM_Microsecond_626,          ///<
        TIM_Microsecond_627,          ///<
        TIM_Microsecond_628,          ///<
        TIM_Microsecond_629,          ///<
        TIM_Microsecond_630,          ///<
        TIM_Microsecond_631,          ///<
        TIM_Microsecond_632,          ///<
        TIM_Microsecond_633,          ///<
        TIM_Microsecond_634,          ///<
        TIM_Microsecond_635,          ///<
        TIM_Microsecond_636,          ///<
        TIM_Microsecond_637,          ///<
        TIM_Microsecond_638,          ///<
        TIM_Microsecond_639,          ///<
        TIM_Microsecond_640,          ///<
        TIM_Microsecond_641,          ///<
        TIM_Microsecond_642,          ///<
        TIM_Microsecond_643,          ///<
        TIM_Microsecond_644,          ///<
        TIM_Microsecond_645,          ///<
        TIM_Microsecond_646,          ///<
        TIM_Microsecond_647,          ///<
        TIM_Microsecond_648,          ///<
        TIM_Microsecond_649,          ///<
        TIM_Microsecond_650,          ///<
        TIM_Microsecond_651,          ///<
        TIM_Microsecond_652,          ///<
        TIM_Microsecond_653,          ///<
        TIM_Microsecond_654,          ///<
        TIM_Microsecond_655,          ///<
        TIM_Microsecond_656,          ///<
        TIM_Microsecond_657,          ///<
        TIM_Microsecond_658,          ///<
        TIM_Microsecond_659,          ///<
        TIM_Microsecond_660,          ///<
        TIM_Microsecond_661,          ///<
        TIM_Microsecond_662,          ///<
        TIM_Microsecond_663,          ///<
        TIM_Microsecond_664,          ///<
        TIM_Microsecond_665,          ///<
        TIM_Microsecond_666,          ///<
        TIM_Microsecond_667,          ///<
        TIM_Microsecond_668,          ///<
        TIM_Microsecond_669,          ///<
        TIM_Microsecond_670,          ///<
        TIM_Microsecond_671,          ///<
        TIM_Microsecond_672,          ///<
        TIM_Microsecond_673,          ///<
        TIM_Microsecond_674,          ///<
        TIM_Microsecond_675,          ///<
        TIM_Microsecond_676,          ///<
        TIM_Microsecond_677,          ///<
        TIM_Microsecond_678,          ///<
        TIM_Microsecond_679,          ///<
        TIM_Microsecond_680,          ///<
        TIM_Microsecond_681,          ///<
        TIM_Microsecond_682,          ///<
        TIM_Microsecond_683,          ///<
        TIM_Microsecond_684,          ///<
        TIM_Microsecond_685,          ///<
        TIM_Microsecond_686,          ///<
        TIM_Microsecond_687,          ///<
        TIM_Microsecond_688,          ///<
        TIM_Microsecond_689,          ///<
        TIM_Microsecond_690,          ///<
        TIM_Microsecond_691,          ///<
        TIM_Microsecond_692,          ///<
        TIM_Microsecond_693,          ///<
        TIM_Microsecond_694,          ///<
        TIM_Microsecond_695,          ///<
        TIM_Microsecond_696,          ///<
        TIM_Microsecond_697,          ///<
        TIM_Microsecond_698,          ///<
        TIM_Microsecond_699,          ///<
        TIM_Microsecond_700,          ///<
        TIM_Microsecond_701,          ///<
        TIM_Microsecond_702,          ///<
        TIM_Microsecond_703,          ///<
        TIM_Microsecond_704,          ///<
        TIM_Microsecond_705,          ///<
        TIM_Microsecond_706,          ///<
        TIM_Microsecond_707,          ///<
        TIM_Microsecond_708,          ///<
        TIM_Microsecond_709,          ///<
        TIM_Microsecond_710,          ///<
        TIM_Microsecond_711,          ///<
        TIM_Microsecond_712,          ///<
        TIM_Microsecond_713,          ///<
        TIM_Microsecond_714,          ///<
        TIM_Microsecond_715,          ///<
        TIM_Microsecond_716,          ///<
        TIM_Microsecond_717,          ///<
        TIM_Microsecond_718,          ///<
        TIM_Microsecond_719,          ///<
        TIM_Microsecond_720,          ///<
        TIM_Microsecond_721,          ///<
        TIM_Microsecond_722,          ///<
        TIM_Microsecond_723,          ///<
        TIM_Microsecond_724,          ///<
        TIM_Microsecond_725,          ///<
        TIM_Microsecond_726,          ///<
        TIM_Microsecond_727,          ///<
        TIM_Microsecond_728,          ///<
        TIM_Microsecond_729,          ///<
        TIM_Microsecond_730,          ///<
        TIM_Microsecond_731,          ///<
        TIM_Microsecond_732,          ///<
        TIM_Microsecond_733,          ///<
        TIM_Microsecond_734,          ///<
        TIM_Microsecond_735,          ///<
        TIM_Microsecond_736,          ///<
        TIM_Microsecond_737,          ///<
        TIM_Microsecond_738,          ///<
        TIM_Microsecond_739,          ///<
        TIM_Microsecond_740,          ///<
        TIM_Microsecond_741,          ///<
        TIM_Microsecond_742,          ///<
        TIM_Microsecond_743,          ///<
        TIM_Microsecond_744,          ///<
        TIM_Microsecond_745,          ///<
        TIM_Microsecond_746,          ///<
        TIM_Microsecond_747,          ///<
        TIM_Microsecond_748,          ///<
        TIM_Microsecond_749,          ///<
        TIM_Microsecond_750,          ///<
        TIM_Microsecond_751,          ///<
        TIM_Microsecond_752,          ///<
        TIM_Microsecond_753,          ///<
        TIM_Microsecond_754,          ///<
        TIM_Microsecond_755,          ///<
        TIM_Microsecond_756,          ///<
        TIM_Microsecond_757,          ///<
        TIM_Microsecond_758,          ///<
        TIM_Microsecond_759,          ///<
        TIM_Microsecond_760,          ///<
        TIM_Microsecond_761,          ///<
        TIM_Microsecond_762,          ///<
        TIM_Microsecond_763,          ///<
        TIM_Microsecond_764,          ///<
        TIM_Microsecond_765,          ///<
        TIM_Microsecond_766,          ///<
        TIM_Microsecond_767,          ///<
        TIM_Microsecond_768,          ///<
        TIM_Microsecond_769,          ///<
        TIM_Microsecond_770,          ///<
        TIM_Microsecond_771,          ///<
        TIM_Microsecond_772,          ///<
        TIM_Microsecond_773,          ///<
        TIM_Microsecond_774,          ///<
        TIM_Microsecond_775,          ///<
        TIM_Microsecond_776,          ///<
        TIM_Microsecond_777,          ///<
        TIM_Microsecond_778,          ///<
        TIM_Microsecond_779,          ///<
        TIM_Microsecond_780,          ///<
        TIM_Microsecond_781,          ///<
        TIM_Microsecond_782,          ///<
        TIM_Microsecond_783,          ///<
        TIM_Microsecond_784,          ///<
        TIM_Microsecond_785,          ///<
        TIM_Microsecond_786,          ///<
        TIM_Microsecond_787,          ///<
        TIM_Microsecond_788,          ///<
        TIM_Microsecond_789,          ///<
        TIM_Microsecond_790,          ///<
        TIM_Microsecond_791,          ///<
        TIM_Microsecond_792,          ///<
        TIM_Microsecond_793,          ///<
        TIM_Microsecond_794,          ///<
        TIM_Microsecond_795,          ///<
        TIM_Microsecond_796,          ///<
        TIM_Microsecond_797,          ///<
        TIM_Microsecond_798,          ///<
        TIM_Microsecond_799,          ///<
        TIM_Microsecond_800,          ///<
        TIM_Microsecond_801,          ///<
        TIM_Microsecond_802,          ///<
        TIM_Microsecond_803,          ///<
        TIM_Microsecond_804,          ///<
        TIM_Microsecond_805,          ///<
        TIM_Microsecond_806,          ///<
        TIM_Microsecond_807,          ///<
        TIM_Microsecond_808,          ///<
        TIM_Microsecond_809,          ///<
        TIM_Microsecond_810,          ///<
        TIM_Microsecond_811,          ///<
        TIM_Microsecond_812,          ///<
        TIM_Microsecond_813,          ///<
        TIM_Microsecond_814,          ///<
        TIM_Microsecond_815,          ///<
        TIM_Microsecond_816,          ///<
        TIM_Microsecond_817,          ///<
        TIM_Microsecond_818,          ///<
        TIM_Microsecond_819,          ///<
        TIM_Microsecond_820,          ///<
        TIM_Microsecond_821,          ///<
        TIM_Microsecond_822,          ///<
        TIM_Microsecond_823,          ///<
        TIM_Microsecond_824,          ///<
        TIM_Microsecond_825,          ///<
        TIM_Microsecond_826,          ///<
        TIM_Microsecond_827,          ///<
        TIM_Microsecond_828,          ///<
        TIM_Microsecond_829,          ///<
        TIM_Microsecond_830,          ///<
        TIM_Microsecond_831,          ///<
        TIM_Microsecond_832,          ///<
        TIM_Microsecond_833,          ///<
        TIM_Microsecond_834,          ///<
        TIM_Microsecond_835,          ///<
        TIM_Microsecond_836,          ///<
        TIM_Microsecond_837,          ///<
        TIM_Microsecond_838,          ///<
        TIM_Microsecond_839,          ///<
        TIM_Microsecond_840,          ///<
        TIM_Microsecond_841,          ///<
        TIM_Microsecond_842,          ///<
        TIM_Microsecond_843,          ///<
        TIM_Microsecond_844,          ///<
        TIM_Microsecond_845,          ///<
        TIM_Microsecond_846,          ///<
        TIM_Microsecond_847,          ///<
        TIM_Microsecond_848,          ///<
        TIM_Microsecond_849,          ///<
        TIM_Microsecond_850,          ///<
        TIM_Microsecond_851,          ///<
        TIM_Microsecond_852,          ///<
        TIM_Microsecond_853,          ///<
        TIM_Microsecond_854,          ///<
        TIM_Microsecond_855,          ///<
        TIM_Microsecond_856,          ///<
        TIM_Microsecond_857,          ///<
        TIM_Microsecond_858,          ///<
        TIM_Microsecond_859,          ///<
        TIM_Microsecond_860,          ///<
        TIM_Microsecond_861,          ///<
        TIM_Microsecond_862,          ///<
        TIM_Microsecond_863,          ///<
        TIM_Microsecond_864,          ///<
        TIM_Microsecond_865,          ///<
        TIM_Microsecond_866,          ///<
        TIM_Microsecond_867,          ///<
        TIM_Microsecond_868,          ///<
        TIM_Microsecond_869,          ///<
        TIM_Microsecond_870,          ///<
        TIM_Microsecond_871,          ///<
        TIM_Microsecond_872,          ///<
        TIM_Microsecond_873,          ///<
        TIM_Microsecond_874,          ///<
        TIM_Microsecond_875,          ///<
        TIM_Microsecond_876,          ///<
        TIM_Microsecond_877,          ///<
        TIM_Microsecond_878,          ///<
        TIM_Microsecond_879,          ///<
        TIM_Microsecond_880,          ///<
        TIM_Microsecond_881,          ///<
        TIM_Microsecond_882,          ///<
        TIM_Microsecond_883,          ///<
        TIM_Microsecond_884,          ///<
        TIM_Microsecond_885,          ///<
        TIM_Microsecond_886,          ///<
        TIM_Microsecond_887,          ///<
        TIM_Microsecond_888,          ///<
        TIM_Microsecond_889,          ///<
        TIM_Microsecond_890,          ///<
        TIM_Microsecond_891,          ///<
        TIM_Microsecond_892,          ///<
        TIM_Microsecond_893,          ///<
        TIM_Microsecond_894,          ///<
        TIM_Microsecond_895,          ///<
        TIM_Microsecond_896,          ///<
        TIM_Microsecond_897,          ///<
        TIM_Microsecond_898,          ///<
        TIM_Microsecond_899,          ///<
        TIM_Microsecond_900,          ///<
        TIM_Microsecond_901,          ///<
        TIM_Microsecond_902,          ///<
        TIM_Microsecond_903,          ///<
        TIM_Microsecond_904,          ///<
        TIM_Microsecond_905,          ///<
        TIM_Microsecond_906,          ///<
        TIM_Microsecond_907,          ///<
        TIM_Microsecond_908,          ///<
        TIM_Microsecond_909,          ///<
        TIM_Microsecond_910,          ///<
        TIM_Microsecond_911,          ///<
        TIM_Microsecond_912,          ///<
        TIM_Microsecond_913,          ///<
        TIM_Microsecond_914,          ///<
        TIM_Microsecond_915,          ///<
        TIM_Microsecond_916,          ///<
        TIM_Microsecond_917,          ///<
        TIM_Microsecond_918,          ///<
        TIM_Microsecond_919,          ///<
        TIM_Microsecond_920,          ///<
        TIM_Microsecond_921,          ///<
        TIM_Microsecond_922,          ///<
        TIM_Microsecond_923,          ///<
        TIM_Microsecond_924,          ///<
        TIM_Microsecond_925,          ///<
        TIM_Microsecond_926,          ///<
        TIM_Microsecond_927,          ///<
        TIM_Microsecond_928,          ///<
        TIM_Microsecond_929,          ///<
        TIM_Microsecond_930,          ///<
        TIM_Microsecond_931,          ///<
        TIM_Microsecond_932,          ///<
        TIM_Microsecond_933,          ///<
        TIM_Microsecond_934,          ///<
        TIM_Microsecond_935,          ///<
        TIM_Microsecond_936,          ///<
        TIM_Microsecond_937,          ///<
        TIM_Microsecond_938,          ///<
        TIM_Microsecond_939,          ///<
        TIM_Microsecond_940,          ///<
        TIM_Microsecond_941,          ///<
        TIM_Microsecond_942,          ///<
        TIM_Microsecond_943,          ///<
        TIM_Microsecond_944,          ///<
        TIM_Microsecond_945,          ///<
        TIM_Microsecond_946,          ///<
        TIM_Microsecond_947,          ///<
        TIM_Microsecond_948,          ///<
        TIM_Microsecond_949,          ///<
        TIM_Microsecond_950,          ///<
        TIM_Microsecond_951,          ///<
        TIM_Microsecond_952,          ///<
        TIM_Microsecond_953,          ///<
        TIM_Microsecond_954,          ///<
        TIM_Microsecond_955,          ///<
        TIM_Microsecond_956,          ///<
        TIM_Microsecond_957,          ///<
        TIM_Microsecond_958,          ///<
        TIM_Microsecond_959,          ///<
        TIM_Microsecond_960,          ///<
        TIM_Microsecond_961,          ///<
        TIM_Microsecond_962,          ///<
        TIM_Microsecond_963,          ///<
        TIM_Microsecond_964,          ///<
        TIM_Microsecond_965,          ///<
        TIM_Microsecond_966,          ///<
        TIM_Microsecond_967,          ///<
        TIM_Microsecond_968,          ///<
        TIM_Microsecond_969,          ///<
        TIM_Microsecond_970,          ///<
        TIM_Microsecond_971,          ///<
        TIM_Microsecond_972,          ///<
        TIM_Microsecond_973,          ///<
        TIM_Microsecond_974,          ///<
        TIM_Microsecond_975,          ///<
        TIM_Microsecond_976,          ///<
        TIM_Microsecond_977,          ///<
        TIM_Microsecond_978,          ///<
        TIM_Microsecond_979,          ///<
        TIM_Microsecond_980,          ///<
        TIM_Microsecond_981,          ///<
        TIM_Microsecond_982,          ///<
        TIM_Microsecond_983,          ///<
        TIM_Microsecond_984,          ///<
        TIM_Microsecond_985,          ///<
        TIM_Microsecond_986,          ///<
        TIM_Microsecond_987,          ///<
        TIM_Microsecond_988,          ///<
        TIM_Microsecond_989,          ///<
        TIM_Microsecond_990,          ///<
        TIM_Microsecond_991,          ///<
        TIM_Microsecond_992,          ///<
        TIM_Microsecond_993,          ///<
        TIM_Microsecond_994,          ///<
        TIM_Microsecond_995,          ///<
        TIM_Microsecond_996,          ///<
        TIM_Microsecond_997,          ///<
        TIM_Microsecond_998,          ///<
        TIM_Microsecond_999,          ///< Microsecond 999 (Maximum)
    } TIM_Microsecond_t;

    /**
     *  @brief TIM Weekday Type
     *
     *  @enum TIM_Weekday_t
     */
    typedef enum TIM_Weekday
    {
        TIM_Weekday_Unknown = -1, ///< Default
        TIM_Weekday_Saturday = 0, ///< Saturday
        TIM_Weekday_Sunday,       ///< Sunday
        TIM_Weekday_Monday,       ///< Monday
        TIM_Weekday_Tuesday,      ///< Tuesday
        TIM_Weekday_Wednesday,    ///< Wednesday
        TIM_Weekday_Thursday,     ///< Thursday
        TIM_Weekday_Friday,       ///< Friday
    } TIM_Weekday_t;

    // FIXME Resolve the time-stamp update side effects
    //       Possible solutions:
    //       - Solution 1: system-wide notification of the update event to re-sync.
    //       - Solution 2: having a low level timing that always being in sync.
    //       - Solution 3: centralize time based actions.
    //       - ...
    /**
     *  @brief TIM Timestamp Type
     *
     *  @struct TIM_Timestamp_t
     */
    typedef struct TIM_Timestamp
    {
        TIM_Year_t Year;               ///< Year
        TIM_Month_t Month;             ///< Month
        TIM_Day_t Day;                 ///< Day
        TIM_Hour_t Hour;               ///< Hour
        TIM_Minute_t Minute;           ///< Minute
        TIM_Second_t Second;           ///< Second
        TIM_Millisecond_t Millisecond; ///< Millisecond
        TIM_Microsecond_t Microsecond; ///< Microsecond
        TIM_Weekday_t Weekday;         ///< Weekday
    } TIM_Timestamp_t;

    // TODO Combine the following into TIM_Delta_t

    /**
     *  @brief TIM Year Delta Type
     */
    typedef int32_t TIM_YearDelta_t;

    /**
     *  @brief TIM Month Delta Type
     */
    typedef int32_t TIM_MonthDelta_t;

    /**
     *  @brief TIM Day Delta Type
     */
    typedef int32_t TIM_DayDelta_t;

    /**
     *  @brief TIM Hour Delta Type
     */
    typedef int32_t TIM_HourDelta_t;

    /**
     *  @brief TIM Minute Delta Type
     */
    typedef int32_t TIM_MinuteDelta_t;

    /**
     *  @brief TIM Second Delta Type
     */
    typedef int32_t TIM_SecondDelta_t;

    /**
     *  @brief TIM Millisecond Delta Type
     */
    typedef int32_t TIM_MillisecondDelta_t;

    /**
     *  @brief TIM Microsecond Delta Type
     */
    typedef int32_t TIM_MicrosecondDelta_t;

    /**
     *  @brief TIM Delta Type
     *
     *  @struct TIM_Delta_t
     */
    typedef struct TIM_Delta
    {
        TIM_YearDelta_t Year;               ///< Year
        TIM_MonthDelta_t Month;             ///< Month
        TIM_DayDelta_t Day;                 ///< Day
        TIM_HourDelta_t Hour;               ///< Hour
        TIM_MinuteDelta_t Minute;           ///< Minute
        TIM_SecondDelta_t Second;           ///< Second
        TIM_MillisecondDelta_t Millisecond; ///< Millisecond
        TIM_MicrosecondDelta_t Microsecond; ///< Microsecond
    } TIM_Delta_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize timing source
     *
     *  @note MUST BE called before using any TIM API
     *
     *  @param[in] TIMx Source
     *
     *  @return TIM_Status_t
     */
    TIM_Status_t TIM_Initialize( TIM_t TIMx );

    /**
     *  @brief Cycle timing source
     *
     *  @param[in] TIMx Source
     *
     *  @return TIM_Status_t
     */
    TIM_Status_t TIM_Cycle( TIM_t TIMx );

    /**
     *  @brief DeInitialize timing source
     *
     *  @param[in] TIMx Source
     *
     *  @return TIM_Status_t
     */
    TIM_Status_t TIM_DeInitialize( TIM_t TIMx );

    /**
     *  @brief Set Time-stamp to timing source
     *
     *  @param[in] TIMx      Source
     *  @param[in] Timestamp Time-stamp
     *
     *  @return TIM_Status_t
     */
    TIM_Status_t TIM_SetTimestamp( TIM_t TIMx, TIM_Timestamp_t Timestamp );

    /**
     *  @brief Get Time-stamp from timing source
     *
     *  @param[in]  TIMx      Source
     *  @param[out] Timestamp Time-stamp pointer
     *
     *  @return TIM_Status_t
     */
    TIM_Status_t TIM_GetTimestamp( TIM_t TIMx, TIM_Timestamp_t * Timestamp );

    /**
     *  @brief Check if time-stamp is expired compared to timing source
     *
     *  @param[in] TIMx      Source
     *  @param[in] Timestamp Time-stamp pointer
     *
     *  @return TIM_Status_t
     */
    TIM_Status_t TIM_IsExpiredTimestamp( TIM_t TIMx, TIM_Timestamp_t * Timestamp );

    /**
     *  @brief Add delta-years to time-stamp
     *
     *  @param[in] Timestamp Time-stamp pointer
     *  @param[in] YearDelta Delta years
     *
     *  @return TIM_Status_t
     */
    TIM_Status_t TIM_Timestamp_AddYear( TIM_Timestamp_t * Timestamp, TIM_YearDelta_t YearDelta );

    /**
     *  @brief Add delta-months to time-stamp
     *
     *  @param[in] Timestamp  Time-stamp pointer
     *  @param[in] MonthDelta Delta months
     *
     *  @return TIM_Status_t
     */
    TIM_Status_t TIM_Timestamp_AddMonth( TIM_Timestamp_t * Timestamp, TIM_MonthDelta_t MonthDelta );

    /**
     *  @brief Add delta-days to time-stamp
     *
     *  @param[in] Timestamp Time-stamp pointer
     *  @param[in] DayDelta  Delta days
     *
     *  @return TIM_Status_t
     */
    TIM_Status_t TIM_Timestamp_AddDay( TIM_Timestamp_t * Timestamp, TIM_DayDelta_t DayDelta );

    /**
     *  @brief Add delta-hours to time-stamp
     *
     *  @param[in] Timestamp Time-stamp pointer
     *  @param[in] HourDelta Delta hours
     *
     *  @return TIM_Status_t
     */
    TIM_Status_t TIM_Timestamp_AddHour( TIM_Timestamp_t * Timestamp, TIM_HourDelta_t HourDelta );

    /**
     *  @brief Add delta-minutes to time-stamp
     *
     *  @param[in] Timestamp   Time-stamp pointer
     *  @param[in] MinuteDelta Delta minutes
     *
     *  @return TIM_Status_t
     */
    TIM_Status_t TIM_Timestamp_AddMinute( TIM_Timestamp_t * Timestamp, TIM_MinuteDelta_t MinuteDelta );

    /**
     *  @brief Add delta-seconds to time-stamp
     *
     *  @param[in] Timestamp   Time-stamp pointer
     *  @param[in] SecondDelta Delta seconds
     *
     *  @return TIM_Status_t
     */
    TIM_Status_t TIM_Timestamp_AddSecond( TIM_Timestamp_t * Timestamp, TIM_SecondDelta_t SecondDelta );

    /**
     *  @brief Add delta-milliseconds to time-stamp
     *
     *  @param[in] Timestamp        Time-stamp pointer
     *  @param[in] MillisecondDelta Delta milliseconds
     *
     *  @return TIM_Status_t
     */
    TIM_Status_t TIM_Timestamp_AddMillisecond( TIM_Timestamp_t * Timestamp, TIM_MillisecondDelta_t MillisecondDelta );

    /**
     *  @brief Add delta-microseconds to time-stamp
     *
     *  @param[in] Timestamp        Time-stamp pointer
     *  @param[in] MicrosecondDelta Delta microseconds
     *
     *  @return TIM_Status_t
     */
    TIM_Status_t TIM_Timestamp_AddMicrosecond( TIM_Timestamp_t * Timestamp, TIM_MicrosecondDelta_t MicrosecondDelta );

    /**
     *  @brief Add delta-timestamp to time-stamp
     *
     *  @param[in,out] Timestamp Time-stamp pointer
     *  @param[in]     Delta     Delta time-stamp
     *
     *  @return TIM_Status_t
     */
    TIM_Status_t TIM_Timestamp_AddDelta( TIM_Timestamp_t * Timestamp, TIM_Delta_t Delta );

    // TODO What about getting delta between TWO time-stamps ?

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char TIM_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* TIM_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
