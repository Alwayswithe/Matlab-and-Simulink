/*
 * File: Z_Flex_Simulink.h
 *
 * Code generated for Simulink model 'Z_Flex_Simulink'.
 *
 * Model version                  : 1.73
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Mon Mar 18 15:42:52 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Z_Flex_Simulink_h_
#define RTW_HEADER_Z_Flex_Simulink_h_
#ifndef Z_Flex_Simulink_COMMON_INCLUDES_
#define Z_Flex_Simulink_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#endif                                 /* Z_Flex_Simulink_COMMON_INCLUDES_ */

#include "Z_Flex_Simulink_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T DataTypeConversion1;          /* '<Root>/Data Type Conversion1' */
  real_T Angle;                        /* '<Root>/MATLAB Function1' */
  real_T LowpassFilter3;               /* '<Root>/Lowpass Filter3' */
  real_T LowpassFilter1;               /* '<Root>/Lowpass Filter1' */
} B_Z_Flex_Simulink_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_LowpassFilter_Z__T obj; /* '<Root>/Lowpass Filter3' */
  dsp_simulink_LowpassFilter_Z__T obj_d;/* '<Root>/Lowpass Filter1' */
  codertarget_arduinobase_inter_T obj_a;/* '<Root>/Analog Input1' */
  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  uint8_T is_active_c1_Z_Flex_Simulink;/* '<Root>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/MATLAB Function1' */
  boolean_T isInitialized;             /* '<Root>/Lowpass Filter3' */
  boolean_T isInitialized_l;           /* '<Root>/Lowpass Filter1' */
} DW_Z_Flex_Simulink_T;

/* Parameters (default storage) */
struct P_Z_Flex_Simulink_T_ {
  real_T AnalogInput1_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Z_Flex_Simulink_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Z_Flex_Simulink_T Z_Flex_Simulink_P;

/* Block signals (default storage) */
extern B_Z_Flex_Simulink_T Z_Flex_Simulink_B;

/* Block states (default storage) */
extern DW_Z_Flex_Simulink_T Z_Flex_Simulink_DW;

/* Model entry point functions */
extern void Z_Flex_Simulink_initialize(void);
extern void Z_Flex_Simulink_step(void);
extern void Z_Flex_Simulink_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Z_Flex_Simulink_T *const Z_Flex_Simulink_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Z_Flex_Simulink'
 * '<S1>'   : 'Z_Flex_Simulink/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_Z_Flex_Simulink_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
