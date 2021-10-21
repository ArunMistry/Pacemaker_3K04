/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LED_DEMO.c
 *
 * Code generated for Simulink model 'LED_DEMO'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Oct  4 09:12:56 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LED_DEMO.h"
#include "LED_DEMO_private.h"

/* Named constants for Chart: '<Root>/LED LOGIC' */
#define LED_DEMO_IN_LED_BLUE_STATE     ((uint8_T)1U)
#define LED_DEMO_IN_LED_GREEN_STATE    ((uint8_T)2U)
#define LED_DEMO_IN_LED_RED_STATE      ((uint8_T)3U)

/* Block signals (default storage) */
B_LED_DEMO_T LED_DEMO_B;

/* Block states (default storage) */
DW_LED_DEMO_T LED_DEMO_DW;

/* Real-time model */
static RT_MODEL_LED_DEMO_T LED_DEMO_M_;
RT_MODEL_LED_DEMO_T *const LED_DEMO_M = &LED_DEMO_M_;

/* Model step function */
void LED_DEMO_step(void)
{
  /* Chart: '<Root>/LED LOGIC' */
  if (LED_DEMO_DW.temporalCounter_i1 < 7U) {
    LED_DEMO_DW.temporalCounter_i1++;
  }

  if (LED_DEMO_DW.is_active_c3_LED_DEMO == 0U) {
    LED_DEMO_DW.is_active_c3_LED_DEMO = 1U;
    LED_DEMO_DW.is_c3_LED_DEMO = LED_DEMO_IN_LED_RED_STATE;
    LED_DEMO_DW.temporalCounter_i1 = 0U;
    LED_DEMO_B.LED_BLUE = false;
    LED_DEMO_B.LED_RED = true;
  } else {
    switch (LED_DEMO_DW.is_c3_LED_DEMO) {
     case LED_DEMO_IN_LED_BLUE_STATE:
      LED_DEMO_B.LED_GREEN = false;
      LED_DEMO_B.LED_BLUE = true;
      if (LED_DEMO_DW.temporalCounter_i1 >= 5U) {
        LED_DEMO_DW.is_c3_LED_DEMO = LED_DEMO_IN_LED_RED_STATE;
        LED_DEMO_DW.temporalCounter_i1 = 0U;
        LED_DEMO_B.LED_BLUE = false;
        LED_DEMO_B.LED_RED = true;
      }
      break;

     case LED_DEMO_IN_LED_GREEN_STATE:
      LED_DEMO_B.LED_RED = false;
      LED_DEMO_B.LED_GREEN = true;
      if (LED_DEMO_DW.temporalCounter_i1 >= 5U) {
        LED_DEMO_DW.is_c3_LED_DEMO = LED_DEMO_IN_LED_BLUE_STATE;
        LED_DEMO_DW.temporalCounter_i1 = 0U;
        LED_DEMO_B.LED_GREEN = false;
        LED_DEMO_B.LED_BLUE = true;
      }
      break;

     default:
      /* case IN_LED_RED_STATE: */
      LED_DEMO_B.LED_BLUE = false;
      LED_DEMO_B.LED_RED = true;
      if (LED_DEMO_DW.temporalCounter_i1 >= 5U) {
        LED_DEMO_DW.is_c3_LED_DEMO = LED_DEMO_IN_LED_GREEN_STATE;
        LED_DEMO_DW.temporalCounter_i1 = 0U;
        LED_DEMO_B.LED_RED = false;
        LED_DEMO_B.LED_GREEN = true;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/LED LOGIC' */

  /* MATLABSystem: '<Root>/LED_BLUE' */
  MW_digitalIO_write(LED_DEMO_DW.obj_m.MW_DIGITALIO_HANDLE, LED_DEMO_B.LED_BLUE);

  /* MATLABSystem: '<Root>/LED_GREEN' */
  MW_digitalIO_write(LED_DEMO_DW.obj_j.MW_DIGITALIO_HANDLE, LED_DEMO_B.LED_GREEN);

  /* MATLABSystem: '<Root>/LED_RED' */
  MW_digitalIO_write(LED_DEMO_DW.obj.MW_DIGITALIO_HANDLE, LED_DEMO_B.LED_RED);
}

/* Model initialize function */
void LED_DEMO_initialize(void)
{
  {
    freedomk64f_DigitalWrite_LED__T *obj;

    /* Start for MATLABSystem: '<Root>/LED_BLUE' */
    LED_DEMO_DW.obj_m.matlabCodegenIsDeleted = true;
    LED_DEMO_DW.obj_m.isInitialized = 0;
    LED_DEMO_DW.obj_m.matlabCodegenIsDeleted = false;
    obj = &LED_DEMO_DW.obj_m;
    LED_DEMO_DW.obj_m.isSetupComplete = false;
    LED_DEMO_DW.obj_m.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    LED_DEMO_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/LED_GREEN' */
    LED_DEMO_DW.obj_j.matlabCodegenIsDeleted = true;
    LED_DEMO_DW.obj_j.isInitialized = 0;
    LED_DEMO_DW.obj_j.matlabCodegenIsDeleted = false;
    obj = &LED_DEMO_DW.obj_j;
    LED_DEMO_DW.obj_j.isSetupComplete = false;
    LED_DEMO_DW.obj_j.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    LED_DEMO_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/LED_RED' */
    LED_DEMO_DW.obj.matlabCodegenIsDeleted = true;
    LED_DEMO_DW.obj.isInitialized = 0;
    LED_DEMO_DW.obj.matlabCodegenIsDeleted = false;
    obj = &LED_DEMO_DW.obj;
    LED_DEMO_DW.obj.isSetupComplete = false;
    LED_DEMO_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    LED_DEMO_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void LED_DEMO_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/LED_BLUE' */
  if (!LED_DEMO_DW.obj_m.matlabCodegenIsDeleted) {
    LED_DEMO_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((LED_DEMO_DW.obj_m.isInitialized == 1) &&
        LED_DEMO_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(LED_DEMO_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED_BLUE' */

  /* Terminate for MATLABSystem: '<Root>/LED_GREEN' */
  if (!LED_DEMO_DW.obj_j.matlabCodegenIsDeleted) {
    LED_DEMO_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((LED_DEMO_DW.obj_j.isInitialized == 1) &&
        LED_DEMO_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(LED_DEMO_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED_GREEN' */

  /* Terminate for MATLABSystem: '<Root>/LED_RED' */
  if (!LED_DEMO_DW.obj.matlabCodegenIsDeleted) {
    LED_DEMO_DW.obj.matlabCodegenIsDeleted = true;
    if ((LED_DEMO_DW.obj.isInitialized == 1) && LED_DEMO_DW.obj.isSetupComplete)
    {
      MW_digitalIO_close(LED_DEMO_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED_RED' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
