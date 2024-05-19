/*
 * File: Two_State.c
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

#include "Two_State.h"
#include <math.h>
#include "Two_State_types.h"
#include "rtwtypes.h"
#include "Two_State_private.h"

/* Block signals (default storage) */
B_Two_State_T Two_State_B;

/* Block states (default storage) */
DW_Two_State_T Two_State_DW;

/* Real-time model */
static RT_MODEL_Two_State_T Two_State_M_;
RT_MODEL_Two_State_T *const Two_State_M = &Two_State_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Two_State_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Two_State_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  Two_State_M->Timing.RateInteraction.TID0_1 =
    (Two_State_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Two_State_M->Timing.TaskCounters.TID[1])++;
  if ((Two_State_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    Two_State_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void Two_State_step0(void)             /* Sample time: [0.01s, 0.0s] */
{
  b_dsp_FIRFilter_0_Two_State_T *obj_2;
  b_dspcodegen_FIRFilter_Two_St_T *obj_1;
  codertarget_arduinobase_int_e_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  real_T rtb_FilterCoefficient;
  real_T rtb_Sum;
  real_T y;
  int16_T IN1;
  int16_T IN2;
  uint16_T b_varargout_1;

  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<Root>/Analog Input' */
  if (Two_State_DW.obj_b.SampleTime != Two_State_P.AnalogInput_SampleTime) {
    Two_State_DW.obj_b.SampleTime = Two_State_P.AnalogInput_SampleTime;
  }

  obj = &Two_State_DW.obj_b;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(69UL);
  Two_State_B.datatype_id = MW_ANALOGIN_UINT16;

  /* MATLABSystem: '<Root>/Analog Input' */
  MW_AnalogInSingle_ReadResult
    (Two_State_DW.obj_b.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &Two_State_B.AnalogInput, Two_State_B.datatype_id);

  /* RateTransition generated from: '<Root>/Sum' */
  if (Two_State_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<Root>/Sum' */
    Two_State_B.Limit_angle = Two_State_DW.Limit_angle_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Sum' */

  /* Abs: '<Root>/Abs' incorporates:
   *  Sum: '<Root>/Sum'
   */
  Two_State_B.Abs = fabs(Two_State_B.Limit_angle - (real_T)
    Two_State_B.AnalogInput);

  /* Gain: '<S40>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S32>/Filter'
   *  Gain: '<S31>/Derivative Gain'
   *  Sum: '<S32>/SumD'
   */
  rtb_FilterCoefficient = (Two_State_P.PIDController_D * Two_State_B.Abs -
    Two_State_DW.Filter_DSTATE) * Two_State_P.PIDController_N;

  /* Sum: '<S46>/Sum' incorporates:
   *  DiscreteIntegrator: '<S37>/Integrator'
   *  Gain: '<S42>/Proportional Gain'
   */
  rtb_Sum = (Two_State_P.PIDController_P * Two_State_B.Abs +
             Two_State_DW.Integrator_DSTATE) + rtb_FilterCoefficient;

  /* Saturate: '<S44>/Saturation' */
  if (rtb_Sum > Two_State_P.PIDController_UpperSaturationLi) {
    /* Saturate: '<S44>/Saturation' */
    Two_State_B.Saturation = Two_State_P.PIDController_UpperSaturationLi;
  } else if (rtb_Sum < Two_State_P.PIDController_LowerSaturationLi) {
    /* Saturate: '<S44>/Saturation' */
    Two_State_B.Saturation = Two_State_P.PIDController_LowerSaturationLi;
  } else {
    /* Saturate: '<S44>/Saturation' */
    Two_State_B.Saturation = rtb_Sum;
  }

  /* End of Saturate: '<S44>/Saturation' */

  /* RateTransition generated from: '<Root>/MATLAB Function' */
  if (Two_State_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<Root>/MATLAB Function' */
    Two_State_B.TmpRTBAtMATLABFunctionInport2 =
      Two_State_DW.TmpRTBAtMATLABFunctionInport2_B;
  }

  /* End of RateTransition generated from: '<Root>/MATLAB Function' */

  /* MATLAB Function: '<Root>/MATLAB Function' */
  if (Two_State_B.TmpRTBAtMATLABFunctionInport2) {
    IN1 = 1;
    IN2 = 0;
  } else {
    IN1 = 0;
    IN2 = 1;
  }

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(10, (uint8_T)IN1);

  /* MATLABSystem: '<Root>/Digital Output1' */
  writeDigitalPin(9, (uint8_T)IN2);

  /* RateTransition generated from: '<Root>/MATLAB Function3' */
  if (Two_State_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<Root>/MATLAB Function3' */
    Two_State_B.TmpRTBAtMATLABFunction3Inport1 =
      Two_State_DW.TmpRTBAtMATLABFunction3Inport1_;
  }

  /* End of RateTransition generated from: '<Root>/MATLAB Function3' */

  /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  if (Two_State_B.TmpRTBAtMATLABFunction3Inport1) {
    Two_State_B.command_pwm_out = fabs(Two_State_B.Saturation);
  } else {
    Two_State_B.command_pwm_out = 0.0;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function3' */

  /* MATLABSystem: '<Root>/PWM' */
  obj_0 = &Two_State_DW.obj_c;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
  if (Two_State_B.command_pwm_out <= 255.0) {
    y = Two_State_B.command_pwm_out;
  } else {
    y = 255.0;
  }

  if (!(y >= 0.0)) {
    y = 0.0;
  }

  MW_PWM_SetDutyCycle(Two_State_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE, y);

  /* End of MATLABSystem: '<Root>/PWM' */
  /* MATLABSystem: '<Root>/Analog Input1' */
  if (Two_State_DW.obj_a.SampleTime != Two_State_P.AnalogInput1_SampleTime) {
    Two_State_DW.obj_a.SampleTime = Two_State_P.AnalogInput1_SampleTime;
  }

  obj = &Two_State_DW.obj_a;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(62UL);
  Two_State_B.datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult
    (Two_State_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     Two_State_B.datatype_id);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  MATLABSystem: '<Root>/Analog Input1'
   */
  Two_State_B.DataTypeConversion1 = b_varargout_1;

  /* MATLABSystem: '<Root>/Lowpass Filter3' */
  obj_1 = Two_State_DW.obj.FilterObj;
  if (obj_1->isInitialized != 1L) {
    obj_1->isSetupComplete = false;
    obj_1->isInitialized = 1L;
    obj_1->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (IN1 = 0; IN1 < 200; IN1++) {
      obj_1->cSFunObject.W0_states[IN1] = obj_1->cSFunObject.P0_InitialStates;
    }
  }

  obj_2 = &obj_1->cSFunObject;

  /* System object Outputs function: dsp.FIRFilter */
  Two_State_B.LowpassFilter3 = Two_State_B.DataTypeConversion1;
  for (IN1 = 0; IN1 < 1; IN1++) {
    y = 0.0;

    /* load input sample */
    for (IN2 = 0; IN2 < 200; IN2++) {
      /* shift state */
      Two_State_B.zCurr = Two_State_B.LowpassFilter3;
      Two_State_B.LowpassFilter3 = obj_2->W0_states[(int32_T)IN2];
      obj_2->W0_states[(int32_T)IN2] = Two_State_B.zCurr;

      /* compute one tap */
      Two_State_B.zCurr *= obj_2->P1_Coefficients[(int32_T)IN2];
      y += Two_State_B.zCurr;
    }

    /* compute last tap */
    Two_State_B.zCurr = obj_2->P1_Coefficients[(int32_T)IN2] *
      Two_State_B.LowpassFilter3;

    /* store output sample */
    Two_State_B.LowpassFilter3 = y + Two_State_B.zCurr;
  }

  /* End of MATLABSystem: '<Root>/Lowpass Filter3' */
  /* Update for DiscreteIntegrator: '<S37>/Integrator' incorporates:
   *  Gain: '<S30>/Kb'
   *  Gain: '<S34>/Integral Gain'
   *  Sum: '<S30>/SumI2'
   *  Sum: '<S30>/SumI4'
   */
  Two_State_DW.Integrator_DSTATE += ((Two_State_B.Saturation - rtb_Sum) *
    Two_State_P.PIDController_Kb + Two_State_P.PIDController_I * Two_State_B.Abs)
    * Two_State_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S32>/Filter' */
  Two_State_DW.Filter_DSTATE += Two_State_P.Filter_gainval *
    rtb_FilterCoefficient;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Two_State_M->Timing.taskTime0 =
    ((time_T)(++Two_State_M->Timing.clockTick0)) * Two_State_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void Two_State_step1(void)             /* Sample time: [0.1s, 0.0s] */
{
  boolean_T rtb_DigitalInput;

  /* MATLABSystem: '<Root>/Digital Input' */
  if (Two_State_DW.obj_bv.SampleTime != Two_State_P.DigitalInput_SampleTime) {
    Two_State_DW.obj_bv.SampleTime = Two_State_P.DigitalInput_SampleTime;
  }

  rtb_DigitalInput = readDigitalPin(26);

  /* End of MATLABSystem: '<Root>/Digital Input' */

  /* MATLAB Function: '<Root>/MATLAB Function2' */
  if (!rtb_DigitalInput) {
    Two_State_B.Limit_angle_m = 1023.0;
  } else {
    Two_State_B.Limit_angle_m = -3.0;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function2' */
  /* RateTransition generated from: '<Root>/Sum' */
  Two_State_DW.Limit_angle_Buffer0 = Two_State_B.Limit_angle_m;

  /* RateTransition generated from: '<Root>/MATLAB Function' */
  Two_State_DW.TmpRTBAtMATLABFunctionInport2_B = rtb_DigitalInput;

  /* MATLABSystem: '<Root>/Digital Input1' */
  if (Two_State_DW.obj_b0.SampleTime != Two_State_P.DigitalInput1_SampleTime) {
    Two_State_DW.obj_b0.SampleTime = Two_State_P.DigitalInput1_SampleTime;
  }

  rtb_DigitalInput = readDigitalPin(27);

  /* End of MATLABSystem: '<Root>/Digital Input1' */

  /* RateTransition generated from: '<Root>/MATLAB Function3' */
  Two_State_DW.TmpRTBAtMATLABFunction3Inport1_ = rtb_DigitalInput;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Two_State_M->Timing.clockTick1++;
}

/* Model initialize function */
void Two_State_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Two_State_M, -1);
  Two_State_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Two_State_M->Sizes.checksums[0] = (3751867317U);
  Two_State_M->Sizes.checksums[1] = (4052876086U);
  Two_State_M->Sizes.checksums[2] = (4009576864U);
  Two_State_M->Sizes.checksums[3] = (1266694030U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    Two_State_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Two_State_M->extModeInfo,
      &Two_State_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Two_State_M->extModeInfo, Two_State_M->Sizes.checksums);
    rteiSetTPtr(Two_State_M->extModeInfo, rtmGetTPtr(Two_State_M));
  }

  {
    b_dspcodegen_FIRFilter_Two_St_T *iobj_0;
    codertarget_arduinobase_int_e_T *obj_0;
    codertarget_arduinobase_inter_T *obj;
    int16_T i;
    static const real_T tmp[201] = { 0.00095042449612864691,
      -0.0010491836924644013, -0.00073503199373740869, -0.00059048096151002752,
      -0.00053724922566342507, -0.00053361913156318769, -0.00055731337493643166,
      -0.00059638520593041427, -0.000644371424964507, -0.0006977130001912784,
      -0.00075438281039932843, -0.00081315568154040677, -0.00087322024524886166,
      -0.00093397263941437869, -0.00099490700184421766, -0.0010555575391851628,
      -0.0011154681370704083, -0.0011741767129602387, -0.0012312074902953354,
      -0.0012860675648928425, -0.0013382458376811415, -0.0013872132905648933,
      -0.0014324240562209785, -0.0014733169851019455, -0.0015093175483701263,
      -0.0015398399885973391, -0.00156428966723297, -0.0015820655767443124,
      -0.0015925629946403111, -0.0015951762617317695, -0.001589301669200457,
      -0.0015743404398588026, -0.0015497017887762922, -0.0015148060481390078,
      -0.0014690878407016294, -0.0014119992857585507, -0.0013430132210072181,
      -0.0012616264232536956, -0.0011673628104984645, -0.0010597766076951151,
      -0.00093845545826662543, -0.00080302346339680578, -0.00065314413110786288,
      -0.00048852321727653838, -0.0003089114409544639, -0.00011410705671472273,
      9.6041732824230861E-5, 0.00032163454057632606, 0.00056271675030572206,
      0.0008192776785446342, 0.0010912489571269675, 0.0013785031493819117,
      0.0016808526119987427, 0.0019980486134261038, 0.0023297807184682003,
      0.0026756764474391462, 0.0030353012168918688, 0.0034081585675121407,
      0.0037936906833073614, 0.0041912792047019759, 0.0046002463366061281,
      0.0050198562509468723, 0.0054493167815615855, 0.0058877814077485224,
      0.0063343515211744979, 0.006788078969246083, 0.0072479688664865661,
      0.0077129826639195116, 0.0081820414649621011, 0.00865402957487995,
      0.00912779826946451, 0.009602169767264003, 0.010075941388452738,
      0.010547889882250271, 0.011016775903727774, 0.011481348619857308,
      0.011940350423784236, 0.012392521735536939, 0.01283660586673843,
      0.013271353926354193, 0.013695529744103091, 0.01410791478788209,
      0.014507313051402288, 0.014892555888219543, 0.015262506768454488,
      0.015616065934743404, 0.015952174934339387, 0.016269821004790387,
      0.016568041291255227, 0.016845926874278338, 0.017102626587723012,
      0.017337350607557676, 0.017549373793297074, 0.017738038765107211,
      0.017902758700892526, 0.018043019839080382, 0.018158383674297177,
      0.018248488834684176, 0.018313052631221228, 0.018351872271098447,
      0.018364825728897173, 0.018351872271098447, 0.018313052631221228,
      0.018248488834684176, 0.018158383674297177, 0.018043019839080382,
      0.017902758700892526, 0.017738038765107211, 0.017549373793297074,
      0.017337350607557676, 0.017102626587723012, 0.016845926874278338,
      0.016568041291255227, 0.016269821004790387, 0.015952174934339387,
      0.015616065934743404, 0.015262506768454488, 0.014892555888219543,
      0.014507313051402288, 0.01410791478788209, 0.013695529744103091,
      0.013271353926354193, 0.01283660586673843, 0.012392521735536939,
      0.011940350423784236, 0.011481348619857308, 0.011016775903727774,
      0.010547889882250271, 0.010075941388452738, 0.009602169767264003,
      0.00912779826946451, 0.00865402957487995, 0.0081820414649621011,
      0.0077129826639195116, 0.0072479688664865661, 0.006788078969246083,
      0.0063343515211744979, 0.0058877814077485224, 0.0054493167815615855,
      0.0050198562509468723, 0.0046002463366061281, 0.0041912792047019759,
      0.0037936906833073614, 0.0034081585675121407, 0.0030353012168918688,
      0.0026756764474391462, 0.0023297807184682003, 0.0019980486134261038,
      0.0016808526119987427, 0.0013785031493819117, 0.0010912489571269675,
      0.0008192776785446342, 0.00056271675030572206, 0.00032163454057632606,
      9.6041732824230861E-5, -0.00011410705671472273, -0.0003089114409544639,
      -0.00048852321727653838, -0.00065314413110786288, -0.00080302346339680578,
      -0.00093845545826662543, -0.0010597766076951151, -0.0011673628104984645,
      -0.0012616264232536956, -0.0013430132210072181, -0.0014119992857585507,
      -0.0014690878407016294, -0.0015148060481390078, -0.0015497017887762922,
      -0.0015743404398588026, -0.001589301669200457, -0.0015951762617317695,
      -0.0015925629946403111, -0.0015820655767443124, -0.00156428966723297,
      -0.0015398399885973391, -0.0015093175483701263, -0.0014733169851019455,
      -0.0014324240562209785, -0.0013872132905648933, -0.0013382458376811415,
      -0.0012860675648928425, -0.0012312074902953354, -0.0011741767129602387,
      -0.0011154681370704083, -0.0010555575391851628, -0.00099490700184421766,
      -0.00093397263941437869, -0.00087322024524886166, -0.00081315568154040677,
      -0.00075438281039932843, -0.0006977130001912784, -0.000644371424964507,
      -0.00059638520593041427, -0.00055731337493643166, -0.00053361913156318769,
      -0.00053724922566342507, -0.00059048096151002752, -0.00073503199373740869,
      -0.0010491836924644013, 0.00095042449612864691 };

    /* Start for RateTransition generated from: '<Root>/Sum' */
    Two_State_B.Limit_angle = Two_State_P.Limit_angle_InitialCondition;

    /* Start for RateTransition generated from: '<Root>/MATLAB Function' */
    Two_State_B.TmpRTBAtMATLABFunctionInport2 =
      Two_State_P.TmpRTBAtMATLABFunctionInport2_I;

    /* Start for RateTransition generated from: '<Root>/MATLAB Function3' */
    Two_State_B.TmpRTBAtMATLABFunction3Inport1 =
      Two_State_P.TmpRTBAtMATLABFunction3Inport1_;

    /* InitializeConditions for RateTransition generated from: '<Root>/Sum' */
    Two_State_DW.Limit_angle_Buffer0 = Two_State_P.Limit_angle_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S37>/Integrator' */
    Two_State_DW.Integrator_DSTATE = Two_State_P.PIDController_InitialConditio_d;

    /* InitializeConditions for DiscreteIntegrator: '<S32>/Filter' */
    Two_State_DW.Filter_DSTATE = Two_State_P.PIDController_InitialConditionF;

    /* InitializeConditions for RateTransition generated from: '<Root>/MATLAB Function' */
    Two_State_DW.TmpRTBAtMATLABFunctionInport2_B =
      Two_State_P.TmpRTBAtMATLABFunctionInport2_I;

    /* InitializeConditions for RateTransition generated from: '<Root>/MATLAB Function3' */
    Two_State_DW.TmpRTBAtMATLABFunction3Inport1_ =
      Two_State_P.TmpRTBAtMATLABFunction3Inport1_;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    Two_State_DW.obj_b.matlabCodegenIsDeleted = false;
    Two_State_DW.obj_b.SampleTime = Two_State_P.AnalogInput_SampleTime;
    obj = &Two_State_DW.obj_b;
    Two_State_DW.obj_b.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(69UL);
    Two_State_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    Two_State_DW.obj_p.matlabCodegenIsDeleted = false;
    Two_State_DW.obj_p.isInitialized = 1L;
    digitalIOSetup(10, 1);
    Two_State_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output1' */
    Two_State_DW.obj_k.matlabCodegenIsDeleted = false;
    Two_State_DW.obj_k.isInitialized = 1L;
    digitalIOSetup(9, 1);
    Two_State_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    Two_State_DW.obj_c.matlabCodegenIsDeleted = false;
    obj_0 = &Two_State_DW.obj_c;
    Two_State_DW.obj_c.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(8UL, 0.0, 0.0);
    Two_State_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input1' */
    Two_State_DW.obj_a.matlabCodegenIsDeleted = false;
    Two_State_DW.obj_a.SampleTime = Two_State_P.AnalogInput1_SampleTime;
    obj = &Two_State_DW.obj_a;
    Two_State_DW.obj_a.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(62UL);
    Two_State_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Lowpass Filter3' */
    Two_State_DW.obj._pobj0.matlabCodegenIsDeleted = true;
    Two_State_DW.obj.NumChannels = -1L;
    Two_State_DW.obj.matlabCodegenIsDeleted = false;
    Two_State_DW.obj.isInitialized = 1L;
    if (Two_State_DW.obj.NumChannels == -1L) {
      Two_State_DW.obj.NumChannels = 1L;
    }

    iobj_0 = &Two_State_DW.obj._pobj0;
    iobj_0->isInitialized = 0L;
    iobj_0->isInitialized = 0L;

    /* System object Constructor function: dsp.FIRFilter */
    iobj_0->cSFunObject.P0_InitialStates = 0.0;
    for (i = 0; i < 201; i++) {
      iobj_0->cSFunObject.P1_Coefficients[i] = tmp[i];
    }

    iobj_0->matlabCodegenIsDeleted = false;
    Two_State_DW.obj.FilterObj = iobj_0;
    Two_State_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Lowpass Filter3' */

    /* InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter3' */
    iobj_0 = Two_State_DW.obj.FilterObj;
    if (iobj_0->isInitialized == 1L) {
      /* System object Initialization function: dsp.FIRFilter */
      for (i = 0; i < 200; i++) {
        iobj_0->cSFunObject.W0_states[i] = iobj_0->cSFunObject.P0_InitialStates;
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter3' */

    /* Start for MATLABSystem: '<Root>/Digital Input' */
    Two_State_DW.obj_bv.matlabCodegenIsDeleted = false;
    Two_State_DW.obj_bv.SampleTime = Two_State_P.DigitalInput_SampleTime;
    Two_State_DW.obj_bv.isInitialized = 1L;
    digitalIOSetup(26, 0);
    Two_State_DW.obj_bv.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input1' */
    Two_State_DW.obj_b0.matlabCodegenIsDeleted = false;
    Two_State_DW.obj_b0.SampleTime = Two_State_P.DigitalInput1_SampleTime;
    Two_State_DW.obj_b0.isInitialized = 1L;
    digitalIOSetup(27, 0);
    Two_State_DW.obj_b0.isSetupComplete = true;
  }
}

/* Model terminate function */
void Two_State_terminate(void)
{
  b_dspcodegen_FIRFilter_Two_St_T *obj_1;
  codertarget_arduinobase_int_e_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  obj = &Two_State_DW.obj_b;
  if (!Two_State_DW.obj_b.matlabCodegenIsDeleted) {
    Two_State_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Two_State_DW.obj_b.isInitialized == 1L) &&
        Two_State_DW.obj_b.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(69UL);
      MW_AnalogIn_Close(Two_State_DW.obj_b.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!Two_State_DW.obj_p.matlabCodegenIsDeleted) {
    Two_State_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!Two_State_DW.obj_k.matlabCodegenIsDeleted) {
    Two_State_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  obj_0 = &Two_State_DW.obj_c;
  if (!Two_State_DW.obj_c.matlabCodegenIsDeleted) {
    Two_State_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((Two_State_DW.obj_c.isInitialized == 1L) &&
        Two_State_DW.obj_c.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_SetDutyCycle(Two_State_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_Close(Two_State_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  obj = &Two_State_DW.obj_a;
  if (!Two_State_DW.obj_a.matlabCodegenIsDeleted) {
    Two_State_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Two_State_DW.obj_a.isInitialized == 1L) &&
        Two_State_DW.obj_a.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(62UL);
      MW_AnalogIn_Close(Two_State_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */

  /* Terminate for MATLABSystem: '<Root>/Lowpass Filter3' */
  if (!Two_State_DW.obj.matlabCodegenIsDeleted) {
    Two_State_DW.obj.matlabCodegenIsDeleted = true;
    if ((Two_State_DW.obj.isInitialized == 1L) &&
        Two_State_DW.obj.isSetupComplete) {
      obj_1 = Two_State_DW.obj.FilterObj;
      if (obj_1->isInitialized == 1L) {
        obj_1->isInitialized = 2L;
      }

      Two_State_DW.obj.NumChannels = -1L;
    }
  }

  obj_1 = &Two_State_DW.obj._pobj0;
  if (!obj_1->matlabCodegenIsDeleted) {
    obj_1->matlabCodegenIsDeleted = true;
    if (obj_1->isInitialized == 1L) {
      obj_1->isInitialized = 2L;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Lowpass Filter3' */
  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  if (!Two_State_DW.obj_bv.matlabCodegenIsDeleted) {
    Two_State_DW.obj_bv.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input' */
  /* Terminate for MATLABSystem: '<Root>/Digital Input1' */
  if (!Two_State_DW.obj_b0.matlabCodegenIsDeleted) {
    Two_State_DW.obj_b0.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
