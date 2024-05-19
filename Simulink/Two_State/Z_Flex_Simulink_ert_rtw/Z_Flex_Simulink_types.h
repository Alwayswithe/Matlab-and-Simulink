/*
 * File: Z_Flex_Simulink_types.h
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

#ifndef RTW_HEADER_Z_Flex_Simulink_types_h_
#define RTW_HEADER_Z_Flex_Simulink_types_h_
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

#ifndef struct_tag_bwyIvMLu3vYFCS9I1VmbDE
#define struct_tag_bwyIvMLu3vYFCS9I1VmbDE

struct tag_bwyIvMLu3vYFCS9I1VmbDE
{
  int16_T S0_isInitialized;
  real_T W0_states[200];
  real_T P0_InitialStates;
  real_T P1_Coefficients[201];
};

#endif                                 /* struct_tag_bwyIvMLu3vYFCS9I1VmbDE */

#ifndef typedef_b_dsp_FIRFilter_0_Z_Flex_Simu_T
#define typedef_b_dsp_FIRFilter_0_Z_Flex_Simu_T

typedef struct tag_bwyIvMLu3vYFCS9I1VmbDE b_dsp_FIRFilter_0_Z_Flex_Simu_T;

#endif                             /* typedef_b_dsp_FIRFilter_0_Z_Flex_Simu_T */

#ifndef struct_tag_0ZdyeSlrANZ1uFtFTh0OMD
#define struct_tag_0ZdyeSlrANZ1uFtFTh0OMD

struct tag_0ZdyeSlrANZ1uFtFTh0OMD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_Z_Flex_Simu_T cSFunObject;
};

#endif                                 /* struct_tag_0ZdyeSlrANZ1uFtFTh0OMD */

#ifndef typedef_b_dspcodegen_FIRFilter_Z_Flex_T
#define typedef_b_dspcodegen_FIRFilter_Z_Flex_T

typedef struct tag_0ZdyeSlrANZ1uFtFTh0OMD b_dspcodegen_FIRFilter_Z_Flex_T;

#endif                             /* typedef_b_dspcodegen_FIRFilter_Z_Flex_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_Z_Flex_Simulink_T
#define typedef_cell_wrap_Z_Flex_Simulink_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_Z_Flex_Simulink_T;

#endif                                 /* typedef_cell_wrap_Z_Flex_Simulink_T */

#ifndef struct_tag_uysPo3ERbb95xEvq8dc4vD
#define struct_tag_uysPo3ERbb95xEvq8dc4vD

struct tag_uysPo3ERbb95xEvq8dc4vD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_Z_Flex_Simulink_T inputVarSize;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_Z_Flex_T *FilterObj;
  b_dspcodegen_FIRFilter_Z_Flex_T _pobj0;
};

#endif                                 /* struct_tag_uysPo3ERbb95xEvq8dc4vD */

#ifndef typedef_dsp_simulink_LowpassFilter_Z__T
#define typedef_dsp_simulink_LowpassFilter_Z__T

typedef struct tag_uysPo3ERbb95xEvq8dc4vD dsp_simulink_LowpassFilter_Z__T;

#endif                             /* typedef_dsp_simulink_LowpassFilter_Z__T */

/* Parameters (default storage) */
typedef struct P_Z_Flex_Simulink_T_ P_Z_Flex_Simulink_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Z_Flex_Simulink_T RT_MODEL_Z_Flex_Simulink_T;

#endif                                 /* RTW_HEADER_Z_Flex_Simulink_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
