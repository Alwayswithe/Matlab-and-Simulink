/*
 * File: Two_State_data.c
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

/* Block parameters (default storage) */
P_Two_State_T Two_State_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S31>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S34>/Integral Gain'
   */
  0.8,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S32>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_d
   * Referenced by: '<S37>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_Kb
   * Referenced by: '<S30>/Kb'
   */
  1.0,

  /* Mask Parameter: PIDController_LowerSaturationLi
   * Referenced by: '<S44>/Saturation'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S40>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S42>/Proportional Gain'
   */
  7.0,

  /* Mask Parameter: PIDController_UpperSaturationLi
   * Referenced by: '<S44>/Saturation'
   */
  160.0,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input1'
   */
  -1.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Input'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Input1'
   */
  0.1,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S37>/Integrator'
   */
  0.01,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S32>/Filter'
   */
  0.01,

  /* Computed Parameter: TmpRTBAtMATLABFunctionInport2_I
   * Referenced by:
   */
  false,

  /* Computed Parameter: TmpRTBAtMATLABFunction3Inport1_
   * Referenced by:
   */
  false
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
