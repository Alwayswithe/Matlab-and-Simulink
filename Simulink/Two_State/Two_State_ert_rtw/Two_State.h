/*
 * File: Two_State.h
 *
 * Code generated for Simulink model 'Two_State'.
 *
 * Model version                  : 1.73
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Mon Mar 18 14:54:55 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Two_State_h_
#define RTW_HEADER_Two_State_h_
#ifndef Two_State_COMMON_INCLUDES_
#define Two_State_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                                 /* Two_State_COMMON_INCLUDES_ */

#include "Two_State_types.h"
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  MW_AnalogIn_ResultDataType_Type datatype_id;
  real_T Limit_angle;                  /* '<Root>/MATLAB Function2' */
  real_T Abs;                          /* '<Root>/Abs' */
  real_T Saturation;                   /* '<S44>/Saturation' */
  real_T DataTypeConversion1;          /* '<Root>/Data Type Conversion1' */
  real_T command_pwm_out;              /* '<Root>/MATLAB Function3' */
  real_T Limit_angle_m;                /* '<Root>/MATLAB Function2' */
  real_T LowpassFilter3;               /* '<Root>/Lowpass Filter3' */
  real_T zCurr;
  uint16_T AnalogInput;                /* '<Root>/Analog Input' */
  boolean_T TmpRTBAtMATLABFunctionInport2;/* '<Root>/Digital Input' */
  boolean_T TmpRTBAtMATLABFunction3Inport1;/* '<Root>/Digital Input1' */
} B_Two_State_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_LowpassFilter_Tw_T obj; /* '<Root>/Lowpass Filter3' */
  codertarget_arduinobase_inter_T obj_a;/* '<Root>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_b;/* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_b0;/* '<Root>/Digital Input1' */
  codertarget_arduinobase_block_T obj_bv;/* '<Root>/Digital Input' */
  codertarget_arduinobase_blo_e_T obj_k;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_blo_e_T obj_p;/* '<Root>/Digital Output' */
  codertarget_arduinobase_int_e_T obj_c;/* '<Root>/PWM' */
  real_T Integrator_DSTATE;            /* '<S37>/Integrator' */
  real_T Filter_DSTATE;                /* '<S32>/Filter' */
  real_T Limit_angle_Buffer0;          /* synthesized block */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  uint8_T is_active_c4_Two_State;      /* '<Root>/MATLAB Function3' */
  uint8_T is_active_c3_Two_State;      /* '<Root>/MATLAB Function2' */
  uint8_T is_active_c1_Two_State;      /* '<Root>/MATLAB Function1' */
  uint8_T is_active_c2_Two_State;      /* '<Root>/MATLAB Function' */
  boolean_T TmpRTBAtMATLABFunctionInport2_B;/* synthesized block */
  boolean_T TmpRTBAtMATLABFunction3Inport1_;/* synthesized block */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/MATLAB Function3' */
  boolean_T doneDoubleBufferReInit_p;  /* '<Root>/MATLAB Function2' */
  boolean_T doneDoubleBufferReInit_e;  /* '<Root>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit_l;  /* '<Root>/MATLAB Function' */
  boolean_T isInitialized;             /* '<Root>/Lowpass Filter3' */
} DW_Two_State_T;

/* Parameters (default storage) */
struct P_Two_State_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S31>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S34>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S32>/Filter'
                               */
  real_T PIDController_InitialConditio_d;
                              /* Mask Parameter: PIDController_InitialConditio_d
                               * Referenced by: '<S37>/Integrator'
                               */
  real_T PIDController_Kb;             /* Mask Parameter: PIDController_Kb
                                        * Referenced by: '<S30>/Kb'
                                        */
  real_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by: '<S44>/Saturation'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S40>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S42>/Proportional Gain'
                                        */
  real_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by: '<S44>/Saturation'
                               */
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T DigitalInput1_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input1'
                                        */
  real_T Limit_angle_InitialCondition; /* Expression: 0
                                        * Referenced by:
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S37>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S32>/Filter'
                                        */
  boolean_T TmpRTBAtMATLABFunctionInport2_I;
                          /* Computed Parameter: TmpRTBAtMATLABFunctionInport2_I
                           * Referenced by:
                           */
  boolean_T TmpRTBAtMATLABFunction3Inport1_;
                          /* Computed Parameter: TmpRTBAtMATLABFunction3Inport1_
                           * Referenced by:
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_Two_State_T {
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
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Two_State_T Two_State_P;

/* Block signals (default storage) */
extern B_Two_State_T Two_State_B;

/* Block states (default storage) */
extern DW_Two_State_T Two_State_DW;

/* External function called from main */
extern void Two_State_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Two_State_initialize(void);
extern void Two_State_step0(void);
extern void Two_State_step1(void);
extern void Two_State_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Two_State_T *const Two_State_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant2' : Unused code path elimination
 */

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
 * '<Root>' : 'Two_State'
 * '<S1>'   : 'Two_State/MATLAB Function'
 * '<S2>'   : 'Two_State/MATLAB Function1'
 * '<S3>'   : 'Two_State/MATLAB Function2'
 * '<S4>'   : 'Two_State/MATLAB Function3'
 * '<S5>'   : 'Two_State/PID Controller'
 * '<S6>'   : 'Two_State/PID Controller/Anti-windup'
 * '<S7>'   : 'Two_State/PID Controller/D Gain'
 * '<S8>'   : 'Two_State/PID Controller/Filter'
 * '<S9>'   : 'Two_State/PID Controller/Filter ICs'
 * '<S10>'  : 'Two_State/PID Controller/I Gain'
 * '<S11>'  : 'Two_State/PID Controller/Ideal P Gain'
 * '<S12>'  : 'Two_State/PID Controller/Ideal P Gain Fdbk'
 * '<S13>'  : 'Two_State/PID Controller/Integrator'
 * '<S14>'  : 'Two_State/PID Controller/Integrator ICs'
 * '<S15>'  : 'Two_State/PID Controller/N Copy'
 * '<S16>'  : 'Two_State/PID Controller/N Gain'
 * '<S17>'  : 'Two_State/PID Controller/P Copy'
 * '<S18>'  : 'Two_State/PID Controller/Parallel P Gain'
 * '<S19>'  : 'Two_State/PID Controller/Reset Signal'
 * '<S20>'  : 'Two_State/PID Controller/Saturation'
 * '<S21>'  : 'Two_State/PID Controller/Saturation Fdbk'
 * '<S22>'  : 'Two_State/PID Controller/Sum'
 * '<S23>'  : 'Two_State/PID Controller/Sum Fdbk'
 * '<S24>'  : 'Two_State/PID Controller/Tracking Mode'
 * '<S25>'  : 'Two_State/PID Controller/Tracking Mode Sum'
 * '<S26>'  : 'Two_State/PID Controller/Tsamp - Integral'
 * '<S27>'  : 'Two_State/PID Controller/Tsamp - Ngain'
 * '<S28>'  : 'Two_State/PID Controller/postSat Signal'
 * '<S29>'  : 'Two_State/PID Controller/preSat Signal'
 * '<S30>'  : 'Two_State/PID Controller/Anti-windup/Back Calculation'
 * '<S31>'  : 'Two_State/PID Controller/D Gain/Internal Parameters'
 * '<S32>'  : 'Two_State/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S33>'  : 'Two_State/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S34>'  : 'Two_State/PID Controller/I Gain/Internal Parameters'
 * '<S35>'  : 'Two_State/PID Controller/Ideal P Gain/Passthrough'
 * '<S36>'  : 'Two_State/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S37>'  : 'Two_State/PID Controller/Integrator/Discrete'
 * '<S38>'  : 'Two_State/PID Controller/Integrator ICs/Internal IC'
 * '<S39>'  : 'Two_State/PID Controller/N Copy/Disabled'
 * '<S40>'  : 'Two_State/PID Controller/N Gain/Internal Parameters'
 * '<S41>'  : 'Two_State/PID Controller/P Copy/Disabled'
 * '<S42>'  : 'Two_State/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S43>'  : 'Two_State/PID Controller/Reset Signal/Disabled'
 * '<S44>'  : 'Two_State/PID Controller/Saturation/Enabled'
 * '<S45>'  : 'Two_State/PID Controller/Saturation Fdbk/Disabled'
 * '<S46>'  : 'Two_State/PID Controller/Sum/Sum_PID'
 * '<S47>'  : 'Two_State/PID Controller/Sum Fdbk/Disabled'
 * '<S48>'  : 'Two_State/PID Controller/Tracking Mode/Disabled'
 * '<S49>'  : 'Two_State/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S50>'  : 'Two_State/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S51>'  : 'Two_State/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S52>'  : 'Two_State/PID Controller/postSat Signal/Forward_Path'
 * '<S53>'  : 'Two_State/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_Two_State_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
