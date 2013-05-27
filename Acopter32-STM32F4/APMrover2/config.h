// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING
//
//  DO NOT EDIT this file to adjust your configuration.  Create your own
//  APM_Config.h and use APM_Config.h.example as a reference.
//
// WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING
///
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Default and automatic configuration details.
//
// Notes for maintainers:
//
// - Try to keep this file organised in the same order as APM_Config.h.example
//

#include "defines.h"

///
/// DO NOT EDIT THIS INCLUDE - if you want to make a local change, make that
/// change in your local copy of APM_Config.h.
///
#include "APM_Config.h"  // <== THIS INCLUDE, DO NOT EDIT IT. EVER.
///
/// DO NOT EDIT THIS INCLUDE - if you want to make a local change, make that
/// change in your local copy of APM_Config.h.
///

#if defined( __AVR_ATmega1280__ )
 // default choices for a 1280. We can't fit everything in, so we 
 // make some popular choices by default
 #define LOGGING_ENABLED DISABLED
 #ifndef CONFIG_RELAY
 # define CONFIG_RELAY DISABLED
 #endif
 #ifndef MOUNT2
 # define MOUNT2 DISABLED
 #endif
 #ifndef MOUNT
 # define MOUNT DISABLED
 #endif
 #ifndef CAMERA
 # define CAMERA DISABLED
 #endif
#endif

// Just so that it's completely clear...
#define ENABLED			1
#define DISABLED		0

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// HARDWARE CONFIGURATION AND CONNECTIONS
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// LED and IO Pins
//

////////////////////////////////////////////////////////
// LED and IO Pins
//

#if CONFIG_HAL_BOARD == HAL_BOARD_APM1
# define CONFIG_INS_TYPE   CONFIG_INS_OILPAN
# define CONFIG_COMPASS  AP_COMPASS_HMC5843
# define A_LED_PIN        37
# define B_LED_PIN        36
# define C_LED_PIN        35
# define LED_ON           HIGH
# define LED_OFF          LOW
# define SLIDE_SWITCH_PIN 40
# define PUSHBUTTON_PIN   41
# define USB_MUX_PIN      -1
# define CONFIG_RELAY     ENABLED
# define BATTERY_PIN_1	  0
# define CURRENT_PIN_1	  1
#elif CONFIG_HAL_BOARD == HAL_BOARD_VRBRAIN
 # define CONFIG_COMPASS  AP_COMPASS_HMC5843
 # define A_LED_PIN        19
 # define B_LED_PIN        20
 # define C_LED_PIN        21
 # define LED_ON           HIGH
 # define LED_OFF          LOW
 # define SLIDE_SWITCH_PIN (-1)
 # define PUSHBUTTON_PIN   (-1)
 #if USB == ENABLED
   # define USB_MUX_PIN      1
  #else
   # define USB_MUX_PIN      (-1)
 #endif
 # define CLI_SLIDER_ENABLED DISABLED
 # define OPTFLOW_CS_PIN   (-1)
 # define BATTERY_VOLT_PIN      D6      // Battery voltage on A0
 # define BATTERY_CURR_PIN      1      // Battery current on A1
 # define BATTERY_PIN_1      D6 // INPUT PC0 on VBRAIN
 # define CURRENT_PIN_1      1
 # define CONFIG_INS_TYPE   CONFIG_INS_MPU6000
 # define CONFIG_IMU_TYPE   CONFIG_IMU_MPU6000
 # define CONFIG_PUSHBUTTON DISABLED
 # define CONFIG_RELAY      DISABLED
 # define CONFIG_SONAR_SOURCE SONAR_SOURCE_ANALOG_PIN
 # define MAGNETOMETER ENABLED
 # define CONFIG_BARO     AP_BARO_MS5611
 # define CONFIG_MS5611_SERIAL AP_BARO_MS5611_SPI
 # define CONFIG_MAG MP32NAVYSENSOR
 # define LOGGING_ENABLED DISABLED
#elif CONFIG_HAL_BOARD == HAL_BOARD_APM2
# define CONFIG_INS_TYPE   CONFIG_INS_MPU6000
# define CONFIG_COMPASS  AP_COMPASS_HMC5843
# define CONFIG_PUSHBUTTON DISABLED
# define CONFIG_RELAY      DISABLED
# define MAG_ORIENTATION   AP_COMPASS_APM2_SHIELD
# define CONFIG_SONAR_SOURCE SONAR_SOURCE_ANALOG_PIN
# define A_LED_PIN        27
# define B_LED_PIN        26
# define C_LED_PIN        25
# define LED_ON           LOW
# define LED_OFF          HIGH
# define SLIDE_SWITCH_PIN (-1)
# define PUSHBUTTON_PIN   (-1)
# define CLI_SLIDER_ENABLED DISABLED
# define USB_MUX_PIN 23
# define BATTERY_PIN_1	  1
# define CURRENT_PIN_1	  2
#elif CONFIG_HAL_BOARD == HAL_BOARD_AVR_SITL
# define CONFIG_INS_TYPE CONFIG_INS_STUB
# define CONFIG_COMPASS  AP_COMPASS_HIL
# define CONFIG_PUSHBUTTON DISABLED
# define CONFIG_RELAY      DISABLED
# define CONFIG_SONAR_SOURCE SONAR_SOURCE_ANALOG_PIN
# define A_LED_PIN        27
# define B_LED_PIN        26
# define C_LED_PIN        25
# define LED_ON           LOW
# define LED_OFF          HIGH
# define SLIDE_SWITCH_PIN (-1)
# define PUSHBUTTON_PIN   (-1)
# define CLI_SLIDER_ENABLED DISABLED
# define USB_MUX_PIN -1
# define BATTERY_PIN_1	  1
# define CURRENT_PIN_1	  2
#elif CONFIG_HAL_BOARD == HAL_BOARD_PX4
# define CONFIG_INS_TYPE   CONFIG_INS_PX4
# define CONFIG_COMPASS  AP_COMPASS_PX4
# define CONFIG_PUSHBUTTON DISABLED
# define CONFIG_RELAY      DISABLED
# define CONFIG_SONAR_SOURCE SONAR_SOURCE_ANALOG_PIN
# define A_LED_PIN        27
# define B_LED_PIN        26
# define C_LED_PIN        25
# define LED_ON           LOW
# define LED_OFF          HIGH
# define SLIDE_SWITCH_PIN (-1)
# define PUSHBUTTON_PIN   (-1)
# define CLI_SLIDER_ENABLED DISABLED
# define USB_MUX_PIN -1
# define BATTERY_PIN_1	  -1
# define CURRENT_PIN_1	  -1
#endif

//////////////////////////////////////////////////////////////////////////////
// IMU Selection
//
#ifndef CONFIG_INS_TYPE
# define CONFIG_INS_TYPE CONFIG_INS_OILPAN
#endif

//////////////////////////////////////////////////////////////////////////////
// ADC Enable - used to eliminate for systems which don't have ADC.
//
#ifndef CONFIG_ADC
# if CONFIG_INS_TYPE == CONFIG_INS_OILPAN
#   define CONFIG_ADC ENABLED
# else
#   define CONFIG_ADC DISABLED
# endif
#endif

#ifndef SONAR_TYPE
# define SONAR_TYPE             MAX_SONAR_LV	// MAX_SONAR_XL,
#endif

//////////////////////////////////////////////////////////////////////////////
// Sonar
//

#ifndef CONFIG_SONAR_SOURCE
# define CONFIG_SONAR_SOURCE SONAR_SOURCE_ADC
#endif

#if CONFIG_SONAR_SOURCE == SONAR_SOURCE_ADC && CONFIG_ADC == DISABLED
# warning Cannot use ADC for CONFIG_SONAR_SOURCE, becaude CONFIG_ADC is DISABLED
# warning Defaulting CONFIG_SONAR_SOURCE to ANALOG_PIN
# undef CONFIG_SONAR_SOURCE
# define CONFIG_SONAR_SOURCE SONAR_SOURCE_ANALOG_PIN
#endif

#if CONFIG_SONAR_SOURCE == SONAR_SOURCE_ADC
# ifndef CONFIG_SONAR_SOURCE_ADC_CHANNEL
#  define CONFIG_SONAR_SOURCE_ADC_CHANNEL 7
# endif
#elif CONFIG_SONAR_SOURCE == SONAR_SOURCE_ANALOG_PIN
# ifndef CONFIG_SONAR_SOURCE_ANALOG_PIN
#  define CONFIG_SONAR_SOURCE_ANALOG_PIN 0
# endif
#else
# warning Invalid value for CONFIG_SONAR_SOURCE, disabling sonar
# undef SONAR_ENABLED
# define SONAR_ENABLED DISABLED
#endif

//////////////////////////////////////////////////////////////////////////////
// HIL_MODE                                 OPTIONAL

#ifndef HIL_MODE
#define HIL_MODE	HIL_MODE_DISABLED
#endif

#if HIL_MODE != HIL_MODE_DISABLED       // we are in HIL mode
 #undef GPS_PROTOCOL
 #define GPS_PROTOCOL GPS_PROTOCOL_HIL
 #undef CONFIG_INS_TYPE
 #define CONFIG_INS_TYPE CONFIG_INS_STUB
 #undef CONFIG_ADC
 #define CONFIG_ADC DISABLED
 #undef  CONFIG_COMPASS
 #define CONFIG_COMPASS  AP_COMPASS_HIL
#endif

//////////////////////////////////////////////////////////////////////////////
// GPS_PROTOCOL
//
// Note that this test must follow the HIL_PROTOCOL block as the HIL
// setup may override the GPS configuration.
//
#ifndef GPS_PROTOCOL
# define GPS_PROTOCOL GPS_PROTOCOL_AUTO
#endif

#ifndef MAV_SYSTEM_ID
# define MAV_SYSTEM_ID		1
#endif

//////////////////////////////////////////////////////////////////////////////
// Serial port speeds.
//
#ifndef SERIAL0_BAUD
# define SERIAL0_BAUD			115200
#endif
#ifndef SERIAL3_BAUD
# define SERIAL3_BAUD			 57600
#endif

#ifndef CH7_OPTION
# define CH7_OPTION		          CH7_SAVE_WP
#endif

#ifndef TUNING_OPTION
# define TUNING_OPTION		          TUN_NONE
#endif

//////////////////////////////////////////////////////////////////////////////
// Battery monitoring
//
#ifndef BATTERY_EVENT
# define BATTERY_EVENT			DISABLED
#endif
#ifndef LOW_VOLTAGE
# define LOW_VOLTAGE			9.6
#endif
#ifndef VOLT_DIV_RATIO
# define VOLT_DIV_RATIO			3.56	// This is the proper value for an on-board APM1 voltage divider with a 3.9kOhm resistor
#endif

#ifndef CURR_AMP_PER_VOLT
# define CURR_AMP_PER_VOLT		27.32	// This is the proper value for the AttoPilot 50V/90A sensor
#endif

#ifndef CURR_AMPS_OFFSET
# define CURR_AMPS_OFFSET		0.0
#endif
#ifndef HIGH_DISCHARGE
# define HIGH_DISCHARGE		1760
#endif

//////////////////////////////////////////////////////////////////////////////
// INPUT_VOLTAGE
//
#ifndef INPUT_VOLTAGE
# define INPUT_VOLTAGE			4.68	//  4.68 is the average value for a sample set.  This is the value at the processor with 5.02 applied at the servo rail
#endif

//////////////////////////////////////////////////////////////////////////////
//  MAGNETOMETER
#ifndef MAGNETOMETER
# define MAGNETOMETER			ENABLED
#endif

//////////////////////////////////////////////////////////////////////////////
// MODE
// MODE_CHANNEL
//
#ifndef MODE_CHANNEL
# define MODE_CHANNEL	8
#endif
#if (MODE_CHANNEL != 5) && (MODE_CHANNEL != 6) && (MODE_CHANNEL != 7) && (MODE_CHANNEL != 8)
# error XXX
# error XXX You must set MODE_CHANNEL to 5, 6, 7 or 8
# error XXX
#endif

#if !defined(MODE_1)
# define MODE_1			LEARNING
#endif
#if !defined(MODE_2)
# define MODE_2			LEARNING
#endif
#if !defined(MODE_3)
# define MODE_3			LEARNING
#endif
#if !defined(MODE_4)
# define MODE_4			LEARNING
#endif
#if !defined(MODE_5)
# define MODE_5			LEARNING
#endif
#if !defined(MODE_6)
# define MODE_6			MANUAL
#endif


//////////////////////////////////////////////////////////////////////////////
// failsafe defaults
#ifndef THROTTLE_FAILSAFE
# define THROTTLE_FAILSAFE		ENABLED
#endif
#ifndef THROTTLE_FS_VALUE
# define THROTTLE_FS_VALUE		950
#endif
#ifndef LONG_FAILSAFE_ACTION
# define LONG_FAILSAFE_ACTION		0
#endif
#ifndef GCS_HEARTBEAT_FAILSAFE
# define GCS_HEARTBEAT_FAILSAFE		DISABLED
#endif


//////////////////////////////////////////////////////////////////////////////
// THROTTLE_OUT
//
#ifndef THROTTE_OUT
# define THROTTLE_OUT			ENABLED
#endif


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// STARTUP BEHAVIOUR
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// GROUND_START_DELAY
//
#ifndef GROUND_START_DELAY
# define GROUND_START_DELAY		0
#endif

//////////////////////////////////////////////////////////////////////////////
// MOUNT (ANTENNA OR CAMERA)
//
#ifndef MOUNT
# define MOUNT		DISABLED
#endif

//////////////////////////////////////////////////////////////////////////////
// AIRSPEED_CRUISE
//
#ifndef SPEED_CRUISE
# define SPEED_CRUISE		3 // 3 m/s
#endif

#ifndef GSBOOST
# define GSBOOST		0
#endif
#ifndef GSBOOST
# define GSBOOST		0
#endif
#ifndef NUDGE_OFFSET
# define NUDGE_OFFSET		0
#endif

#ifndef E_GLIDER
# define E_GLIDER		ENABLED
#endif

#ifndef TURN_GAIN
# define TURN_GAIN		5
#endif

//////////////////////////////////////////////////////////////////////////////
// Servo Mapping
//
#ifndef THROTTLE_MIN
# define THROTTLE_MIN			0 // percent
#endif
#ifndef THROTTLE_CRUISE
# define THROTTLE_CRUISE		45
#endif
#ifndef THROTTLE_MAX
# define THROTTLE_MAX			100
#endif

//////////////////////////////////////////////////////////////////////////////
// Attitude control gains
//
#ifndef SERVO_STEER_P
# define SERVO_STEER_P         0.4
#endif
#ifndef SERVO_STEER_I
# define SERVO_STEER_I         0.0
#endif
#ifndef SERVO_STEER_D
# define SERVO_STEER_D         0.0
#endif
#ifndef SERVO_STEER_INT_MAX
# define SERVO_STEER_INT_MAX   5
#endif
#define SERVO_STEER_INT_MAX_CENTIDEGREE SERVO_STEER_INT_MAX*100


//////////////////////////////////////////////////////////////////////////////
// Crosstrack compensation
//
#ifndef XTRACK_GAIN
# define XTRACK_GAIN          1 // deg/m
#endif
#ifndef XTRACK_ENTRY_ANGLE
# define XTRACK_ENTRY_ANGLE   50 // deg
#endif
# define XTRACK_GAIN_SCALED XTRACK_GAIN*100
# define XTRACK_ENTRY_ANGLE_CENTIDEGREE XTRACK_ENTRY_ANGLE*100

//////////////////////////////////////////////////////////////////////////////
// Dataflash logging control
//
#ifndef LOGGING_ENABLED
# define LOGGING_ENABLED		ENABLED
#endif

#define DEFAULT_LOG_BITMASK     \
    MASK_LOG_ATTITUDE_MED | \
    MASK_LOG_GPS | \
    MASK_LOG_PM | \
    MASK_LOG_NTUN | \
    MASK_LOG_MODE | \
    MASK_LOG_CMD | \
    MASK_LOG_SONAR | \
    MASK_LOG_COMPASS | \
    MASK_LOG_CURRENT



//////////////////////////////////////////////////////////////////////////////
// Developer Items
//

#ifndef STANDARD_SPEED
# define STANDARD_SPEED		3.0
#define STANDARD_SPEED_SQUARED (STANDARD_SPEED * STANDARD_SPEED)
#endif
#define STANDARD_THROTTLE_SQUARED (THROTTLE_CRUISE * THROTTLE_CRUISE)

// use this to enable servos in HIL mode
#ifndef HIL_SERVOS
# define HIL_SERVOS DISABLED
#endif

// use this to completely disable the CLI
#ifndef CLI_ENABLED
# define CLI_ENABLED ENABLED
#endif

// if RESET_SWITCH_CH is not zero, then this is the PWM value on
// that channel where we reset the control mode to the current switch
// position (to for example return to switched mode after failsafe or
// fence breach)
#ifndef RESET_SWITCH_CHAN_PWM
# define RESET_SWITCH_CHAN_PWM 1750
#endif

#ifndef BOOSTER
# define BOOSTER              2    // booster factor x1 = 1 or x2 = 2
#endif

#ifndef SONAR_ENABLED
# define SONAR_ENABLED       DISABLED
#endif
