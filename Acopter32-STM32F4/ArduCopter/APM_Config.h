// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

// User specific config file.  Any items listed in config.h can be overridden here.

// If you used to define your CONFIG_APM_HARDWARE setting here, it is no longer
// valid! You should switch to using a HAL_BOARD flag in your local config.mk.

//#define HIL_MODE              HIL_MODE_SENSORS    // build for hardware-in-the-loop simulation
//#define LOGGING_ENABLED       DISABLED            // disable logging to save code space
//#define DMP_ENABLED           ENABLED             // use MPU6000's DMP instead of DCM for attitude estimation
//#define SECONDARY_DMP_ENABLED ENABLED             // allows running DMP in parallel with DCM for testing purposes

//Autopilot rotate rate limits
#define AUTO_YAW_SLEW_RATE 45

/*-------------ENHANCED-----------------*/
/*To enable the enhanced mode (MPU6000 at 1KHz and gyro full scale at 1000dps) uncomment #define ENHANCED in:
 * APM_Config.h
 * and in
 * libraries/AP_InertialSensor/AP_InertialSensor_MPU6000.h
 */

//#define ENHANCED

/*--------------------------------------*/

//#define FRAME_CONFIG HEXA_FRAME
//#define FRAME_ORIENTATION      PLUS_FRAME

 //#define GPS_PROTOCOL           GPS_PROTOCOL_NONE
/*
 *  options:
 *  QUAD_FRAME
 *  TRI_FRAME
 *  HEXA_FRAME
 *  Y6_FRAME
 *  OCTA_FRAME
 *  OCTA_QUAD_FRAME
 *  HELI_FRAME
 */

// uncomment the lines below to save on flash space if compiling for the APM using Arduino IDE
//#define OPTFLOW               DISABLED            // disable optical flow sensor to save 5K of flash space
//#define LOGGING_ENABLED       DISABLED            // disable dataflash logging to save 11K of flash space
//#define MOUNT                 DISABLED            // disable the camera gimbal to save 8K of flash space
//#define CLI_ENABLED           DISABLED            // disable the CLI (command-line-interface) to save 21K of flash space
#define AUTOTUNE              DISABLED            // disable the auto tune functionality to save 7k of flash

// redefine size of throttle deadband in pwm (0 ~ 1000)
//#define THROTTLE_IN_DEADBAND   100

//#define HIL_MODE              HIL_MODE_SENSORS    // build for hardware-in-the-loop simulation

// User Hooks : For User Developed code that you wish to run
// Put your variable definitions into the UserVariables.h file (or another file name and then change the #define below).
//#define USERHOOK_VARIABLES "UserVariables.h"
// Put your custom code into the UserCode.pde with function names matching those listed below and ensure the appropriate #define below is uncommented below
//#define USERHOOK_INIT userhook_init();                      // for code to be run once at startup
//#define USERHOOK_FASTLOOP userhook_FastLoop();            // for code to be run at 100hz
//#define USERHOOK_50HZLOOP userhook_50Hz();                  // for code to be run at 50hz
//#define USERHOOK_MEDIUMLOOP userhook_MediumLoop();        // for code to be run at 10hz
//#define USERHOOK_SLOWLOOP userhook_SlowLoop();            // for code to be run at 3.3hz
//#define USERHOOK_SUPERSLOWLOOP userhook_SuperSlowLoop();  // for code to be run at 1hz
