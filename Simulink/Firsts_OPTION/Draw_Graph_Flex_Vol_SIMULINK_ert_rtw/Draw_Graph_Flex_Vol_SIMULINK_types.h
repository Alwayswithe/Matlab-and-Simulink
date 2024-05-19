/*
 * File: Draw_Graph_Flex_Vol_SIMULINK_types.h
 *
 * Code generated for Simulink model 'Draw_Graph_Flex_Vol_SIMULINK'.
 *
 * Model version                  : 1.87
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Fri Mar 29 15:35:51 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Draw_Graph_Flex_Vol_SIMULINK_types_h_
#define RTW_HEADER_Draw_Graph_Flex_Vol_SIMULINK_types_h_
#include "MW_SVD.h"
#include "rtwtypes.h"

/* Custom Type definition for MATLABSystem: '<Root>/Analog Input1' */
#include "MW_SVD.h"
#ifndef struct_tag_UTG5XI0vJCsmjbgura8BP
#define struct_tag_UTG5XI0vJCsmjbgura8BP

struct tag_UTG5XI0vJCsmjbgura8BP
{
  MW_Handle_Type MW_ANALOGIN_HANDLE;
};

#endif                                 /* struct_tag_UTG5XI0vJCsmjbgura8BP */

#ifndef typedef_f_arduinodriver_ArduinoAnalog_T
#define typedef_f_arduinodriver_ArduinoAnalog_T

typedef struct tag_UTG5XI0vJCsmjbgura8BP f_arduinodriver_ArduinoAnalog_T;

#endif                             /* typedef_f_arduinodriver_ArduinoAnalog_T */

#ifndef struct_tag_8ohiN1FAOgR98njPNu14NC
#define struct_tag_8ohiN1FAOgR98njPNu14NC

struct tag_8ohiN1FAOgR98njPNu14NC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_arduinodriver_ArduinoAnalog_T AnalogInDriverObj;
  real_T SampleTime;
};

#endif                                 /* struct_tag_8ohiN1FAOgR98njPNu14NC */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_8ohiN1FAOgR98njPNu14NC codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

#ifndef struct_tag_iTbNcjUIKaAfHfHVrhKIJF
#define struct_tag_iTbNcjUIKaAfHfHVrhKIJF

struct tag_iTbNcjUIKaAfHfHVrhKIJF
{
  int16_T S0_isInitialized;
  real_T W0_states[20];
  real_T P0_InitialStates;
  real_T P1_Coefficients[21];
};

#endif                                 /* struct_tag_iTbNcjUIKaAfHfHVrhKIJF */

#ifndef typedef_b_dsp_FIRFilter_0_Draw_Graph__T
#define typedef_b_dsp_FIRFilter_0_Draw_Graph__T

typedef struct tag_iTbNcjUIKaAfHfHVrhKIJF b_dsp_FIRFilter_0_Draw_Graph__T;

#endif                             /* typedef_b_dsp_FIRFilter_0_Draw_Graph__T */

#ifndef struct_tag_3IL6Pow0Q5BFOw4cctM3lC
#define struct_tag_3IL6Pow0Q5BFOw4cctM3lC

struct tag_3IL6Pow0Q5BFOw4cctM3lC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_Draw_Graph__T cSFunObject;
};

#endif                                 /* struct_tag_3IL6Pow0Q5BFOw4cctM3lC */

#ifndef typedef_b_dspcodegen_FIRFilter_Draw_G_T
#define typedef_b_dspcodegen_FIRFilter_Draw_G_T

typedef struct tag_3IL6Pow0Q5BFOw4cctM3lC b_dspcodegen_FIRFilter_Draw_G_T;

#endif                             /* typedef_b_dspcodegen_FIRFilter_Draw_G_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_Draw_Graph_Flex_Vol_T
#define typedef_cell_wrap_Draw_Graph_Flex_Vol_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_Draw_Graph_Flex_Vol_T;

#endif                             /* typedef_cell_wrap_Draw_Graph_Flex_Vol_T */

#ifndef struct_tag_YJ16jb1hVEXAPNZKJAd5GF
#define struct_tag_YJ16jb1hVEXAPNZKJAd5GF

struct tag_YJ16jb1hVEXAPNZKJAd5GF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_Draw_Graph_Flex_Vol_T inputVarSize;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_Draw_G_T *FilterObj;
  b_dspcodegen_FIRFilter_Draw_G_T _pobj0;
};

#endif                                 /* struct_tag_YJ16jb1hVEXAPNZKJAd5GF */

#ifndef typedef_dsp_simulink_LowpassFilter_Dr_T
#define typedef_dsp_simulink_LowpassFilter_Dr_T

typedef struct tag_YJ16jb1hVEXAPNZKJAd5GF dsp_simulink_LowpassFilter_Dr_T;

#endif                             /* typedef_dsp_simulink_LowpassFilter_Dr_T */

/* Parameters (default storage) */
typedef struct P_Draw_Graph_Flex_Vol_SIMULIN_T_ P_Draw_Graph_Flex_Vol_SIMULIN_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Draw_Graph_Flex_Vol_S_T RT_MODEL_Draw_Graph_Flex_Vol__T;

#endif                    /* RTW_HEADER_Draw_Graph_Flex_Vol_SIMULINK_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
