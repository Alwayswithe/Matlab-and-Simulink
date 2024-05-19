/*
 * File: Draw_Graph_Flex_Vol_SIMULINK.c
 *
 * Code generated for Simulink model 'Draw_Graph_Flex_Vol_SIMULINK'.
 *
 * Model version                  : 1.83
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Thu Mar 28 21:52:57 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Draw_Graph_Flex_Vol_SIMULINK.h"
#include "Draw_Graph_Flex_Vol_SIMULINK_types.h"
#include "rtwtypes.h"
#include "Draw_Graph_Flex_Vol_SIMULINK_private.h"

/* Block signals (default storage) */
B_Draw_Graph_Flex_Vol_SIMULIN_T Draw_Graph_Flex_Vol_SIMULINK_B;

/* Block states (default storage) */
DW_Draw_Graph_Flex_Vol_SIMULI_T Draw_Graph_Flex_Vol_SIMULINK_DW;

/* Real-time model */
static RT_MODEL_Draw_Graph_Flex_Vol__T Draw_Graph_Flex_Vol_SIMULINK_M_;
RT_MODEL_Draw_Graph_Flex_Vol__T *const Draw_Graph_Flex_Vol_SIMULINK_M =
  &Draw_Graph_Flex_Vol_SIMULINK_M_;

/* Model step function */
void Draw_Graph_Flex_Vol_SIMULINK_step(void)
{
  MW_AnalogIn_ResultDataType_Type datatype_id;
  b_dsp_FIRFilter_0_Draw_Graph__T *obj_1;
  b_dspcodegen_FIRFilter_Draw_G_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  real_T acc1;
  real_T zCurr;
  int16_T k;
  int16_T n;
  uint16_T b_varargout_1;

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (Draw_Graph_Flex_Vol_SIMULINK_DW.obj_a.SampleTime !=
      Draw_Graph_Flex_Vol_SIMULINK_P.AnalogInput1_SampleTime) {
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj_a.SampleTime =
      Draw_Graph_Flex_Vol_SIMULINK_P.AnalogInput1_SampleTime;
  }

  obj = &Draw_Graph_Flex_Vol_SIMULINK_DW.obj_a;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(69UL);
  datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult
    (Draw_Graph_Flex_Vol_SIMULINK_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, datatype_id);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  MATLABSystem: '<Root>/Analog Input1'
   */
  Draw_Graph_Flex_Vol_SIMULINK_B.DataTypeConversion1 = b_varargout_1;

  /* MATLABSystem: '<Root>/Lowpass Filter3' */
  obj_0 = Draw_Graph_Flex_Vol_SIMULINK_DW.obj.FilterObj;
  if (obj_0->isInitialized != 1L) {
    obj_0->isSetupComplete = false;
    obj_0->isInitialized = 1L;
    obj_0->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (k = 0; k < 20; k++) {
      obj_0->cSFunObject.W0_states[k] = obj_0->cSFunObject.P0_InitialStates;
    }
  }

  obj_1 = &obj_0->cSFunObject;

  /* System object Outputs function: dsp.FIRFilter */
  Draw_Graph_Flex_Vol_SIMULINK_B.Vol_Flex =
    Draw_Graph_Flex_Vol_SIMULINK_B.DataTypeConversion1;
  for (k = 0; k < 1; k++) {
    acc1 = 0.0;

    /* load input sample */
    for (n = 0; n < 20; n++) {
      /* shift state */
      zCurr = Draw_Graph_Flex_Vol_SIMULINK_B.Vol_Flex;
      Draw_Graph_Flex_Vol_SIMULINK_B.Vol_Flex = obj_1->W0_states[(int32_T)n];
      obj_1->W0_states[(int32_T)n] = zCurr;

      /* compute one tap */
      zCurr *= obj_1->P1_Coefficients[(int32_T)n];
      acc1 += zCurr;
    }

    /* compute last tap */
    zCurr = obj_1->P1_Coefficients[(int32_T)n] *
      Draw_Graph_Flex_Vol_SIMULINK_B.Vol_Flex;

    /* store output sample */
    Draw_Graph_Flex_Vol_SIMULINK_B.Vol_Flex = acc1 + zCurr;
  }

  /* End of MATLABSystem: '<Root>/Lowpass Filter3' */

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  Draw_Graph_Flex_Vol_SIMULINK_B.Angle = ((4.98 /
    (Draw_Graph_Flex_Vol_SIMULINK_B.Vol_Flex * 4.98 / 1023.0) - 1.0) * 47500.0 -
    24000.0) / 6000.0 * 90.0;

  /* MATLABSystem: '<Root>/Lowpass Filter1' */
  obj_0 = Draw_Graph_Flex_Vol_SIMULINK_DW.obj_m.FilterObj;
  if (obj_0->isInitialized != 1L) {
    obj_0->isSetupComplete = false;
    obj_0->isInitialized = 1L;
    obj_0->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (k = 0; k < 20; k++) {
      obj_0->cSFunObject.W0_states[k] = obj_0->cSFunObject.P0_InitialStates;
    }
  }

  obj_1 = &obj_0->cSFunObject;

  /* System object Outputs function: dsp.FIRFilter */
  Draw_Graph_Flex_Vol_SIMULINK_B.Angle_l = Draw_Graph_Flex_Vol_SIMULINK_B.Angle;
  for (k = 0; k < 1; k++) {
    acc1 = 0.0;

    /* load input sample */
    for (n = 0; n < 20; n++) {
      /* shift state */
      zCurr = Draw_Graph_Flex_Vol_SIMULINK_B.Angle_l;
      Draw_Graph_Flex_Vol_SIMULINK_B.Angle_l = obj_1->W0_states[(int32_T)n];
      obj_1->W0_states[(int32_T)n] = zCurr;

      /* compute one tap */
      zCurr *= obj_1->P1_Coefficients[(int32_T)n];
      acc1 += zCurr;
    }

    /* compute last tap */
    zCurr = obj_1->P1_Coefficients[(int32_T)n] *
      Draw_Graph_Flex_Vol_SIMULINK_B.Angle_l;

    /* store output sample */
    Draw_Graph_Flex_Vol_SIMULINK_B.Angle_l = acc1 + zCurr;
  }

  /* End of MATLABSystem: '<Root>/Lowpass Filter1' */
  {                                    /* Sample time: [0.01s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Draw_Graph_Flex_Vol_SIMULINK_M->Timing.taskTime0 =
    ((time_T)(++Draw_Graph_Flex_Vol_SIMULINK_M->Timing.clockTick0)) *
    Draw_Graph_Flex_Vol_SIMULINK_M->Timing.stepSize0;
}

/* Model initialize function */
void Draw_Graph_Flex_Vol_SIMULINK_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Draw_Graph_Flex_Vol_SIMULINK_M, -1);
  Draw_Graph_Flex_Vol_SIMULINK_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Draw_Graph_Flex_Vol_SIMULINK_M->Sizes.checksums[0] = (1209752908U);
  Draw_Graph_Flex_Vol_SIMULINK_M->Sizes.checksums[1] = (2811804676U);
  Draw_Graph_Flex_Vol_SIMULINK_M->Sizes.checksums[2] = (1137130558U);
  Draw_Graph_Flex_Vol_SIMULINK_M->Sizes.checksums[3] = (1822881980U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    Draw_Graph_Flex_Vol_SIMULINK_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Draw_Graph_Flex_Vol_SIMULINK_M->extModeInfo,
      &Draw_Graph_Flex_Vol_SIMULINK_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Draw_Graph_Flex_Vol_SIMULINK_M->extModeInfo,
                        Draw_Graph_Flex_Vol_SIMULINK_M->Sizes.checksums);
    rteiSetTPtr(Draw_Graph_Flex_Vol_SIMULINK_M->extModeInfo, rtmGetTPtr
                (Draw_Graph_Flex_Vol_SIMULINK_M));
  }

  {
    b_dspcodegen_FIRFilter_Draw_G_T *iobj_0;
    codertarget_arduinobase_inter_T *obj;
    int16_T i;
    static const real_T tmp[21] = { -0.0046651612761332267,
      -0.0084153117093450532, -0.011547100037608197, -0.0098655729549674623,
      0.00053801425910593426, 0.022091257330913841, 0.054113026799816395,
      0.092110621496526088, 0.12853088417596223, 0.15488396640872998,
      0.16450831564126006, 0.15488396640872998, 0.12853088417596223,
      0.092110621496526088, 0.054113026799816395, 0.022091257330913841,
      0.00053801425910593426, -0.0098655729549674623, -0.011547100037608197,
      -0.0084153117093450532, -0.0046651612761332267 };

    static const real_T tmp_0[21] = { 0.0043952460773981237,
      0.0085430553137236624, 0.015600251073604479, 0.02505474044651727,
      0.0365881910326634, 0.049482621228314844, 0.062673182965299043,
      0.074876919866897415, 0.0847782948710603, 0.091237743267163177,
      0.093482105865350718, 0.091237743267163177, 0.0847782948710603,
      0.074876919866897415, 0.062673182965299043, 0.049482621228314844,
      0.0365881910326634, 0.02505474044651727, 0.015600251073604479,
      0.0085430553137236624, 0.0043952460773981237 };

    /* Start for MATLABSystem: '<Root>/Analog Input1' */
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj_a.matlabCodegenIsDeleted = false;
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj_a.SampleTime =
      Draw_Graph_Flex_Vol_SIMULINK_P.AnalogInput1_SampleTime;
    obj = &Draw_Graph_Flex_Vol_SIMULINK_DW.obj_a;
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj_a.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(69UL);
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Lowpass Filter3' */
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj._pobj0.matlabCodegenIsDeleted = true;
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj.NumChannels = -1L;
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj.matlabCodegenIsDeleted = false;
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj.isInitialized = 1L;
    if (Draw_Graph_Flex_Vol_SIMULINK_DW.obj.NumChannels == -1L) {
      Draw_Graph_Flex_Vol_SIMULINK_DW.obj.NumChannels = 1L;
    }

    iobj_0 = &Draw_Graph_Flex_Vol_SIMULINK_DW.obj._pobj0;
    iobj_0->isInitialized = 0L;
    iobj_0->isInitialized = 0L;

    /* System object Constructor function: dsp.FIRFilter */
    iobj_0->cSFunObject.P0_InitialStates = 0.0;
    for (i = 0; i < 21; i++) {
      iobj_0->cSFunObject.P1_Coefficients[i] = tmp[i];
    }

    iobj_0->matlabCodegenIsDeleted = false;
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj.FilterObj = iobj_0;
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Lowpass Filter3' */

    /* InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter3' */
    iobj_0 = Draw_Graph_Flex_Vol_SIMULINK_DW.obj.FilterObj;
    if (iobj_0->isInitialized == 1L) {
      /* System object Initialization function: dsp.FIRFilter */
      for (i = 0; i < 20; i++) {
        iobj_0->cSFunObject.W0_states[i] = iobj_0->cSFunObject.P0_InitialStates;
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter3' */

    /* Start for MATLABSystem: '<Root>/Lowpass Filter1' */
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj_m._pobj0.matlabCodegenIsDeleted = true;
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj_m.NumChannels = -1L;
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj_m.matlabCodegenIsDeleted = false;
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj_m.isInitialized = 1L;
    if (Draw_Graph_Flex_Vol_SIMULINK_DW.obj_m.NumChannels == -1L) {
      Draw_Graph_Flex_Vol_SIMULINK_DW.obj_m.NumChannels = 1L;
    }

    iobj_0 = &Draw_Graph_Flex_Vol_SIMULINK_DW.obj_m._pobj0;
    iobj_0->isInitialized = 0L;
    iobj_0->isInitialized = 0L;

    /* System object Constructor function: dsp.FIRFilter */
    iobj_0->cSFunObject.P0_InitialStates = 0.0;
    for (i = 0; i < 21; i++) {
      iobj_0->cSFunObject.P1_Coefficients[i] = tmp_0[i];
    }

    iobj_0->matlabCodegenIsDeleted = false;
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj_m.FilterObj = iobj_0;
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj_m.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Lowpass Filter1' */

    /* InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter1' */
    iobj_0 = Draw_Graph_Flex_Vol_SIMULINK_DW.obj_m.FilterObj;
    if (iobj_0->isInitialized == 1L) {
      /* System object Initialization function: dsp.FIRFilter */
      for (i = 0; i < 20; i++) {
        iobj_0->cSFunObject.W0_states[i] = iobj_0->cSFunObject.P0_InitialStates;
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter1' */
  }
}

/* Model terminate function */
void Draw_Graph_Flex_Vol_SIMULINK_terminate(void)
{
  b_dspcodegen_FIRFilter_Draw_G_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  obj = &Draw_Graph_Flex_Vol_SIMULINK_DW.obj_a;
  if (!Draw_Graph_Flex_Vol_SIMULINK_DW.obj_a.matlabCodegenIsDeleted) {
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Draw_Graph_Flex_Vol_SIMULINK_DW.obj_a.isInitialized == 1L) &&
        Draw_Graph_Flex_Vol_SIMULINK_DW.obj_a.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(69UL);
      MW_AnalogIn_Close
        (Draw_Graph_Flex_Vol_SIMULINK_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */

  /* Terminate for MATLABSystem: '<Root>/Lowpass Filter3' */
  if (!Draw_Graph_Flex_Vol_SIMULINK_DW.obj.matlabCodegenIsDeleted) {
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj.matlabCodegenIsDeleted = true;
    if ((Draw_Graph_Flex_Vol_SIMULINK_DW.obj.isInitialized == 1L) &&
        Draw_Graph_Flex_Vol_SIMULINK_DW.obj.isSetupComplete) {
      obj_0 = Draw_Graph_Flex_Vol_SIMULINK_DW.obj.FilterObj;
      if (obj_0->isInitialized == 1L) {
        obj_0->isInitialized = 2L;
      }

      Draw_Graph_Flex_Vol_SIMULINK_DW.obj.NumChannels = -1L;
    }
  }

  obj_0 = &Draw_Graph_Flex_Vol_SIMULINK_DW.obj._pobj0;
  if (!obj_0->matlabCodegenIsDeleted) {
    obj_0->matlabCodegenIsDeleted = true;
    if (obj_0->isInitialized == 1L) {
      obj_0->isInitialized = 2L;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Lowpass Filter3' */

  /* Terminate for MATLABSystem: '<Root>/Lowpass Filter1' */
  if (!Draw_Graph_Flex_Vol_SIMULINK_DW.obj_m.matlabCodegenIsDeleted) {
    Draw_Graph_Flex_Vol_SIMULINK_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Draw_Graph_Flex_Vol_SIMULINK_DW.obj_m.isInitialized == 1L) &&
        Draw_Graph_Flex_Vol_SIMULINK_DW.obj_m.isSetupComplete) {
      obj_0 = Draw_Graph_Flex_Vol_SIMULINK_DW.obj_m.FilterObj;
      if (obj_0->isInitialized == 1L) {
        obj_0->isInitialized = 2L;
      }

      Draw_Graph_Flex_Vol_SIMULINK_DW.obj_m.NumChannels = -1L;
    }
  }

  obj_0 = &Draw_Graph_Flex_Vol_SIMULINK_DW.obj_m._pobj0;
  if (!obj_0->matlabCodegenIsDeleted) {
    obj_0->matlabCodegenIsDeleted = true;
    if (obj_0->isInitialized == 1L) {
      obj_0->isInitialized = 2L;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Lowpass Filter1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
