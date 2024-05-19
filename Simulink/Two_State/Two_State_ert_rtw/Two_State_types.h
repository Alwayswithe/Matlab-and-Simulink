/*
 * File: Two_State_types.h
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

#ifndef RTW_HEADER_Two_State_types_h_
#define RTW_HEADER_Two_State_types_h_
#include "MW_SVD.h"
#include "rtwtypes.h"

/* Custom Type definition for MATLABSystem: '<Root>/PWM' */
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

#ifndef struct_tag_04b6x6tDldj9IrIH2gmbjG
#define struct_tag_04b6x6tDldj9IrIH2gmbjG

struct tag_04b6x6tDldj9IrIH2gmbjG
{
  int16_T __dummy;
};

#endif                                 /* struct_tag_04b6x6tDldj9IrIH2gmbjG */

#ifndef typedef_d_arduinodriver_ArduinoDigita_T
#define typedef_d_arduinodriver_ArduinoDigita_T

typedef struct tag_04b6x6tDldj9IrIH2gmbjG d_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_d_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_HaWnjzA2iiR2NMKNB2VNI
#define struct_tag_HaWnjzA2iiR2NMKNB2VNI

struct tag_HaWnjzA2iiR2NMKNB2VNI
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
  real_T SampleTime;
};

#endif                                 /* struct_tag_HaWnjzA2iiR2NMKNB2VNI */

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_HaWnjzA2iiR2NMKNB2VNI codertarget_arduinobase_block_T;

#endif                             /* typedef_codertarget_arduinobase_block_T */

#ifndef struct_tag_04b6x6tDldj9IrIH2gmbjG
#define struct_tag_04b6x6tDldj9IrIH2gmbjG

struct tag_04b6x6tDldj9IrIH2gmbjG
{
  int16_T __dummy;
};

#endif                                 /* struct_tag_04b6x6tDldj9IrIH2gmbjG */

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_04b6x6tDldj9IrIH2gmbjG b_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_b_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_AYWgtFscQm3mLUJYb3A20C
#define struct_tag_AYWgtFscQm3mLUJYb3A20C

struct tag_AYWgtFscQm3mLUJYb3A20C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /* struct_tag_AYWgtFscQm3mLUJYb3A20C */

#ifndef typedef_codertarget_arduinobase_blo_e_T
#define typedef_codertarget_arduinobase_blo_e_T

typedef struct tag_AYWgtFscQm3mLUJYb3A20C codertarget_arduinobase_blo_e_T;

#endif                             /* typedef_codertarget_arduinobase_blo_e_T */

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

#ifndef typedef_b_dsp_FIRFilter_0_Two_State_T
#define typedef_b_dsp_FIRFilter_0_Two_State_T

typedef struct tag_bwyIvMLu3vYFCS9I1VmbDE b_dsp_FIRFilter_0_Two_State_T;

#endif                               /* typedef_b_dsp_FIRFilter_0_Two_State_T */

#ifndef struct_tag_0ZdyeSlrANZ1uFtFTh0OMD
#define struct_tag_0ZdyeSlrANZ1uFtFTh0OMD

struct tag_0ZdyeSlrANZ1uFtFTh0OMD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_Two_State_T cSFunObject;
};

#endif                                 /* struct_tag_0ZdyeSlrANZ1uFtFTh0OMD */

#ifndef typedef_b_dspcodegen_FIRFilter_Two_St_T
#define typedef_b_dspcodegen_FIRFilter_Two_St_T

typedef struct tag_0ZdyeSlrANZ1uFtFTh0OMD b_dspcodegen_FIRFilter_Two_St_T;

#endif                             /* typedef_b_dspcodegen_FIRFilter_Two_St_T */

#ifndef struct_tag_g1WX34VPn8QzVKQriB4HN
#define struct_tag_g1WX34VPn8QzVKQriB4HN

struct tag_g1WX34VPn8QzVKQriB4HN
{
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_g1WX34VPn8QzVKQriB4HN */

#ifndef typedef_g_matlabshared_ioclient_perip_T
#define typedef_g_matlabshared_ioclient_perip_T

typedef struct tag_g1WX34VPn8QzVKQriB4HN g_matlabshared_ioclient_perip_T;

#endif                             /* typedef_g_matlabshared_ioclient_perip_T */

#ifndef struct_tag_4eDVzK5FiryyCjvjjvrZGB
#define struct_tag_4eDVzK5FiryyCjvjjvrZGB

struct tag_4eDVzK5FiryyCjvjjvrZGB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  g_matlabshared_ioclient_perip_T PWMDriverObj;
};

#endif                                 /* struct_tag_4eDVzK5FiryyCjvjjvrZGB */

#ifndef typedef_codertarget_arduinobase_int_e_T
#define typedef_codertarget_arduinobase_int_e_T

typedef struct tag_4eDVzK5FiryyCjvjjvrZGB codertarget_arduinobase_int_e_T;

#endif                             /* typedef_codertarget_arduinobase_int_e_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_Two_State_T
#define typedef_cell_wrap_Two_State_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_Two_State_T;

#endif                                 /* typedef_cell_wrap_Two_State_T */

#ifndef struct_tag_uysPo3ERbb95xEvq8dc4vD
#define struct_tag_uysPo3ERbb95xEvq8dc4vD

struct tag_uysPo3ERbb95xEvq8dc4vD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_Two_State_T inputVarSize;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_Two_St_T *FilterObj;
  b_dspcodegen_FIRFilter_Two_St_T _pobj0;
};

#endif                                 /* struct_tag_uysPo3ERbb95xEvq8dc4vD */

#ifndef typedef_dsp_simulink_LowpassFilter_Tw_T
#define typedef_dsp_simulink_LowpassFilter_Tw_T

typedef struct tag_uysPo3ERbb95xEvq8dc4vD dsp_simulink_LowpassFilter_Tw_T;

#endif                             /* typedef_dsp_simulink_LowpassFilter_Tw_T */

/* Parameters (default storage) */
typedef struct P_Two_State_T_ P_Two_State_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Two_State_T RT_MODEL_Two_State_T;

#endif                                 /* RTW_HEADER_Two_State_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
