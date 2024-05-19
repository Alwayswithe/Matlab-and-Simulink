/*
 * File: Z_Flex_Simulink.c
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

#include "Z_Flex_Simulink.h"
#include "Z_Flex_Simulink_types.h"
#include "rtwtypes.h"
#include "Z_Flex_Simulink_private.h"

/* Block signals (default storage) */
B_Z_Flex_Simulink_T Z_Flex_Simulink_B;

/* Block states (default storage) */
DW_Z_Flex_Simulink_T Z_Flex_Simulink_DW;

/* Real-time model */
static RT_MODEL_Z_Flex_Simulink_T Z_Flex_Simulink_M_;
RT_MODEL_Z_Flex_Simulink_T *const Z_Flex_Simulink_M = &Z_Flex_Simulink_M_;

/* Model step function */
void Z_Flex_Simulink_step(void)
{
  MW_AnalogIn_ResultDataType_Type datatype_id;
  b_dsp_FIRFilter_0_Z_Flex_Simu_T *obj_1;
  b_dspcodegen_FIRFilter_Z_Flex_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  real_T acc1;
  real_T zCurr;
  int16_T k;
  int16_T n;
  uint16_T b_varargout_1;

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (Z_Flex_Simulink_DW.obj_a.SampleTime !=
      Z_Flex_Simulink_P.AnalogInput1_SampleTime) {
    Z_Flex_Simulink_DW.obj_a.SampleTime =
      Z_Flex_Simulink_P.AnalogInput1_SampleTime;
  }

  obj = &Z_Flex_Simulink_DW.obj_a;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(69UL);
  datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult
    (Z_Flex_Simulink_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, datatype_id);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  MATLABSystem: '<Root>/Analog Input1'
   */
  Z_Flex_Simulink_B.DataTypeConversion1 = b_varargout_1;

  /* MATLABSystem: '<Root>/Lowpass Filter3' */
  obj_0 = Z_Flex_Simulink_DW.obj.FilterObj;
  if (obj_0->isInitialized != 1L) {
    obj_0->isSetupComplete = false;
    obj_0->isInitialized = 1L;
    obj_0->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (k = 0; k < 200; k++) {
      obj_0->cSFunObject.W0_states[k] = obj_0->cSFunObject.P0_InitialStates;
    }
  }

  obj_1 = &obj_0->cSFunObject;

  /* System object Outputs function: dsp.FIRFilter */
  Z_Flex_Simulink_B.LowpassFilter3 = Z_Flex_Simulink_B.DataTypeConversion1;
  for (k = 0; k < 1; k++) {
    acc1 = 0.0;

    /* load input sample */
    for (n = 0; n < 200; n++) {
      /* shift state */
      zCurr = Z_Flex_Simulink_B.LowpassFilter3;
      Z_Flex_Simulink_B.LowpassFilter3 = obj_1->W0_states[(int32_T)n];
      obj_1->W0_states[(int32_T)n] = zCurr;

      /* compute one tap */
      zCurr *= obj_1->P1_Coefficients[(int32_T)n];
      acc1 += zCurr;
    }

    /* compute last tap */
    zCurr = obj_1->P1_Coefficients[(int32_T)n] *
      Z_Flex_Simulink_B.LowpassFilter3;

    /* store output sample */
    Z_Flex_Simulink_B.LowpassFilter3 = acc1 + zCurr;
  }

  /* End of MATLABSystem: '<Root>/Lowpass Filter3' */

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  Z_Flex_Simulink_B.Angle = ((4.98 / (Z_Flex_Simulink_B.LowpassFilter3 * 4.98 /
    1023.0) - 1.0) * 47500.0 - 24000.0) / 6000.0 * 90.0;

  /* MATLABSystem: '<Root>/Lowpass Filter1' */
  obj_0 = Z_Flex_Simulink_DW.obj_d.FilterObj;
  if (obj_0->isInitialized != 1L) {
    obj_0->isSetupComplete = false;
    obj_0->isInitialized = 1L;
    obj_0->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (k = 0; k < 200; k++) {
      obj_0->cSFunObject.W0_states[k] = obj_0->cSFunObject.P0_InitialStates;
    }
  }

  obj_1 = &obj_0->cSFunObject;

  /* System object Outputs function: dsp.FIRFilter */
  Z_Flex_Simulink_B.LowpassFilter1 = Z_Flex_Simulink_B.Angle;
  for (k = 0; k < 1; k++) {
    acc1 = 0.0;

    /* load input sample */
    for (n = 0; n < 200; n++) {
      /* shift state */
      zCurr = Z_Flex_Simulink_B.LowpassFilter1;
      Z_Flex_Simulink_B.LowpassFilter1 = obj_1->W0_states[(int32_T)n];
      obj_1->W0_states[(int32_T)n] = zCurr;

      /* compute one tap */
      zCurr *= obj_1->P1_Coefficients[(int32_T)n];
      acc1 += zCurr;
    }

    /* compute last tap */
    zCurr = obj_1->P1_Coefficients[(int32_T)n] *
      Z_Flex_Simulink_B.LowpassFilter1;

    /* store output sample */
    Z_Flex_Simulink_B.LowpassFilter1 = acc1 + zCurr;
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
  Z_Flex_Simulink_M->Timing.taskTime0 =
    ((time_T)(++Z_Flex_Simulink_M->Timing.clockTick0)) *
    Z_Flex_Simulink_M->Timing.stepSize0;
}

/* Model initialize function */
void Z_Flex_Simulink_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Z_Flex_Simulink_M, -1);
  Z_Flex_Simulink_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Z_Flex_Simulink_M->Sizes.checksums[0] = (1959695620U);
  Z_Flex_Simulink_M->Sizes.checksums[1] = (1698225773U);
  Z_Flex_Simulink_M->Sizes.checksums[2] = (137270450U);
  Z_Flex_Simulink_M->Sizes.checksums[3] = (2448436004U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    Z_Flex_Simulink_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Z_Flex_Simulink_M->extModeInfo,
      &Z_Flex_Simulink_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Z_Flex_Simulink_M->extModeInfo,
                        Z_Flex_Simulink_M->Sizes.checksums);
    rteiSetTPtr(Z_Flex_Simulink_M->extModeInfo, rtmGetTPtr(Z_Flex_Simulink_M));
  }

  {
    b_dspcodegen_FIRFilter_Z_Flex_T *iobj_0;
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

    static const real_T tmp_0[201] = { 0.0017543871395068404,
      0.00036463248016373965, 0.00040195676565274978, 0.00044141051186972661,
      0.00048304142231848219, 0.00052689519303616647, 0.00057301536439893731,
      0.00062144317424390463, 0.00067221741268235716, 0.00072537427898081207,
      0.00078094724088767183, 0.00083896689678239879, 0.00089946084102307772,
      0.00096245353286679, 0.0010279661693319057, 0.0010960165623699935,
      0.0011666190207070596, 0.0012397842367088587, 0.0013155191786182224,
      0.0013938269885018996, 0.0014747068862377688, 0.0015581540798609774,
      0.0016441596825770587, 0.0017327106367381144, 0.0018237896450647626,
      0.0019173751093825066, 0.0020134410771263851, 0.0021119571958530961,
      0.0022128886759811158, 0.0023161962619648595, 0.0024218362120889086,
      0.0025297602870511795, 0.0026399157474834376, 0.0027522453605394333,
      0.0028666874156588426, 0.0029831757495960586, 0.003101639780780251,
      0.0032220045530527786, 0.0033441907888053838, 0.0034681149515201014,
      0.0035936893176910368, 0.0037208220580834156, 0.0038494173282647513,
      0.00397937536831842, 0.00411059261162944, 0.0042429618026072974,
      0.0043763721231907934, 0.0045107093279551915, 0.0046458558876219021,
      0.0047816911407493048, 0.0049180914533595819, 0.0050549303862400174,
      0.0051920788696325354, 0.0053294053850087971, 0.0054667761536072758,
      0.005604055331390711, 0.0057411052100659332, 0.0058777864237883936,
      0.0060139581611606437, 0.0061494783821166065, 0.0062842040392707254,
      0.0064179913032956356, 0.0065506957918829278, 0.0066821728018261837,
      0.006812277543758738, 0.0069408653790676818, 0.0070677920584973413,
      0.0071929139619500721, 0.007316088338984751, 0.00743717354951035,
      0.00755602930416756, 0.0076725169038903956, 0.0077864994781374191,
      0.0078978422212849439, 0.0080064126266735682, 0.0081120807178046046,
      0.0082147192761855021, 0.00831420406533044, 0.0084104140504267458,
      0.00850323161318825, 0.0085925427614226453, 0.0086782373328545548,
      0.0087602091927520432, 0.0088383564249212253, 0.00891258151564593,
      0.00898279153016234, 0.0090488982812779919, 0.00911081848975648,
      0.0091684739361125762, 0.0092217916034750026, 0.0092707038111991252,
      0.0093151483389284015, 0.0093550685408256024, 0.00939041344971828,
      0.00942113787092172, 0.00944720246552958, 0.0094685738229837012,
      0.00948522452275902, 0.0094971331850243444, 0.0095042845101646969,
      0.00950666930707567, 0.0095042845101646969, 0.0094971331850243444,
      0.00948522452275902, 0.0094685738229837012, 0.00944720246552958,
      0.00942113787092172, 0.00939041344971828, 0.0093550685408256024,
      0.0093151483389284015, 0.0092707038111991252, 0.0092217916034750026,
      0.0091684739361125762, 0.00911081848975648, 0.0090488982812779919,
      0.00898279153016234, 0.00891258151564593, 0.0088383564249212253,
      0.0087602091927520432, 0.0086782373328545548, 0.0085925427614226453,
      0.00850323161318825, 0.0084104140504267458, 0.00831420406533044,
      0.0082147192761855021, 0.0081120807178046046, 0.0080064126266735682,
      0.0078978422212849439, 0.0077864994781374191, 0.0076725169038903956,
      0.00755602930416756, 0.00743717354951035, 0.007316088338984751,
      0.0071929139619500721, 0.0070677920584973413, 0.0069408653790676818,
      0.006812277543758738, 0.0066821728018261837, 0.0065506957918829278,
      0.0064179913032956356, 0.0062842040392707254, 0.0061494783821166065,
      0.0060139581611606437, 0.0058777864237883936, 0.0057411052100659332,
      0.005604055331390711, 0.0054667761536072758, 0.0053294053850087971,
      0.0051920788696325354, 0.0050549303862400174, 0.0049180914533595819,
      0.0047816911407493048, 0.0046458558876219021, 0.0045107093279551915,
      0.0043763721231907934, 0.0042429618026072974, 0.00411059261162944,
      0.00397937536831842, 0.0038494173282647513, 0.0037208220580834156,
      0.0035936893176910368, 0.0034681149515201014, 0.0033441907888053838,
      0.0032220045530527786, 0.003101639780780251, 0.0029831757495960586,
      0.0028666874156588426, 0.0027522453605394333, 0.0026399157474834376,
      0.0025297602870511795, 0.0024218362120889086, 0.0023161962619648595,
      0.0022128886759811158, 0.0021119571958530961, 0.0020134410771263851,
      0.0019173751093825066, 0.0018237896450647626, 0.0017327106367381144,
      0.0016441596825770587, 0.0015581540798609774, 0.0014747068862377688,
      0.0013938269885018996, 0.0013155191786182224, 0.0012397842367088587,
      0.0011666190207070596, 0.0010960165623699935, 0.0010279661693319057,
      0.00096245353286679, 0.00089946084102307772, 0.00083896689678239879,
      0.00078094724088767183, 0.00072537427898081207, 0.00067221741268235716,
      0.00062144317424390463, 0.00057301536439893731, 0.00052689519303616647,
      0.00048304142231848219, 0.00044141051186972661, 0.00040195676565274978,
      0.00036463248016373965, 0.0017543871395068404 };

    /* Start for MATLABSystem: '<Root>/Analog Input1' */
    Z_Flex_Simulink_DW.obj_a.matlabCodegenIsDeleted = false;
    Z_Flex_Simulink_DW.obj_a.SampleTime =
      Z_Flex_Simulink_P.AnalogInput1_SampleTime;
    obj = &Z_Flex_Simulink_DW.obj_a;
    Z_Flex_Simulink_DW.obj_a.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(69UL);
    Z_Flex_Simulink_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Lowpass Filter3' */
    Z_Flex_Simulink_DW.obj._pobj0.matlabCodegenIsDeleted = true;
    Z_Flex_Simulink_DW.obj.NumChannels = -1L;
    Z_Flex_Simulink_DW.obj.matlabCodegenIsDeleted = false;
    Z_Flex_Simulink_DW.obj.isInitialized = 1L;
    if (Z_Flex_Simulink_DW.obj.NumChannels == -1L) {
      Z_Flex_Simulink_DW.obj.NumChannels = 1L;
    }

    iobj_0 = &Z_Flex_Simulink_DW.obj._pobj0;
    iobj_0->isInitialized = 0L;
    iobj_0->isInitialized = 0L;

    /* System object Constructor function: dsp.FIRFilter */
    iobj_0->cSFunObject.P0_InitialStates = 0.0;
    for (i = 0; i < 201; i++) {
      iobj_0->cSFunObject.P1_Coefficients[i] = tmp[i];
    }

    iobj_0->matlabCodegenIsDeleted = false;
    Z_Flex_Simulink_DW.obj.FilterObj = iobj_0;
    Z_Flex_Simulink_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Lowpass Filter3' */

    /* InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter3' */
    iobj_0 = Z_Flex_Simulink_DW.obj.FilterObj;
    if (iobj_0->isInitialized == 1L) {
      /* System object Initialization function: dsp.FIRFilter */
      for (i = 0; i < 200; i++) {
        iobj_0->cSFunObject.W0_states[i] = iobj_0->cSFunObject.P0_InitialStates;
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter3' */

    /* Start for MATLABSystem: '<Root>/Lowpass Filter1' */
    Z_Flex_Simulink_DW.obj_d._pobj0.matlabCodegenIsDeleted = true;
    Z_Flex_Simulink_DW.obj_d.NumChannels = -1L;
    Z_Flex_Simulink_DW.obj_d.matlabCodegenIsDeleted = false;
    Z_Flex_Simulink_DW.obj_d.isInitialized = 1L;
    if (Z_Flex_Simulink_DW.obj_d.NumChannels == -1L) {
      Z_Flex_Simulink_DW.obj_d.NumChannels = 1L;
    }

    iobj_0 = &Z_Flex_Simulink_DW.obj_d._pobj0;
    iobj_0->isInitialized = 0L;
    iobj_0->isInitialized = 0L;

    /* System object Constructor function: dsp.FIRFilter */
    iobj_0->cSFunObject.P0_InitialStates = 0.0;
    for (i = 0; i < 201; i++) {
      iobj_0->cSFunObject.P1_Coefficients[i] = tmp_0[i];
    }

    iobj_0->matlabCodegenIsDeleted = false;
    Z_Flex_Simulink_DW.obj_d.FilterObj = iobj_0;
    Z_Flex_Simulink_DW.obj_d.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Lowpass Filter1' */

    /* InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter1' */
    iobj_0 = Z_Flex_Simulink_DW.obj_d.FilterObj;
    if (iobj_0->isInitialized == 1L) {
      /* System object Initialization function: dsp.FIRFilter */
      for (i = 0; i < 200; i++) {
        iobj_0->cSFunObject.W0_states[i] = iobj_0->cSFunObject.P0_InitialStates;
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter1' */
  }
}

/* Model terminate function */
void Z_Flex_Simulink_terminate(void)
{
  b_dspcodegen_FIRFilter_Z_Flex_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  obj = &Z_Flex_Simulink_DW.obj_a;
  if (!Z_Flex_Simulink_DW.obj_a.matlabCodegenIsDeleted) {
    Z_Flex_Simulink_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Z_Flex_Simulink_DW.obj_a.isInitialized == 1L) &&
        Z_Flex_Simulink_DW.obj_a.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(69UL);
      MW_AnalogIn_Close
        (Z_Flex_Simulink_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */

  /* Terminate for MATLABSystem: '<Root>/Lowpass Filter3' */
  if (!Z_Flex_Simulink_DW.obj.matlabCodegenIsDeleted) {
    Z_Flex_Simulink_DW.obj.matlabCodegenIsDeleted = true;
    if ((Z_Flex_Simulink_DW.obj.isInitialized == 1L) &&
        Z_Flex_Simulink_DW.obj.isSetupComplete) {
      obj_0 = Z_Flex_Simulink_DW.obj.FilterObj;
      if (obj_0->isInitialized == 1L) {
        obj_0->isInitialized = 2L;
      }

      Z_Flex_Simulink_DW.obj.NumChannels = -1L;
    }
  }

  obj_0 = &Z_Flex_Simulink_DW.obj._pobj0;
  if (!obj_0->matlabCodegenIsDeleted) {
    obj_0->matlabCodegenIsDeleted = true;
    if (obj_0->isInitialized == 1L) {
      obj_0->isInitialized = 2L;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Lowpass Filter3' */

  /* Terminate for MATLABSystem: '<Root>/Lowpass Filter1' */
  if (!Z_Flex_Simulink_DW.obj_d.matlabCodegenIsDeleted) {
    Z_Flex_Simulink_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Z_Flex_Simulink_DW.obj_d.isInitialized == 1L) &&
        Z_Flex_Simulink_DW.obj_d.isSetupComplete) {
      obj_0 = Z_Flex_Simulink_DW.obj_d.FilterObj;
      if (obj_0->isInitialized == 1L) {
        obj_0->isInitialized = 2L;
      }

      Z_Flex_Simulink_DW.obj_d.NumChannels = -1L;
    }
  }

  obj_0 = &Z_Flex_Simulink_DW.obj_d._pobj0;
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
