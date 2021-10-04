/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LED_DEMO.h
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

#ifndef RTW_HEADER_LED_DEMO_h_
#define RTW_HEADER_LED_DEMO_h_
#include <stddef.h>
#ifndef LED_DEMO_COMMON_INCLUDES_
#define LED_DEMO_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#endif                                 /* LED_DEMO_COMMON_INCLUDES_ */

#include "LED_DEMO_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  boolean_T LED_RED;                   /* '<Root>/LED LOGIC' */
  boolean_T LED_GREEN;                 /* '<Root>/LED LOGIC' */
  boolean_T LED_BLUE;                  /* '<Root>/LED LOGIC' */
} B_LED_DEMO_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalWrite_LED__T obj; /* '<Root>/LED_RED' */
  freedomk64f_DigitalWrite_LED__T obj_j;/* '<Root>/LED_GREEN' */
  freedomk64f_DigitalWrite_LED__T obj_m;/* '<Root>/LED_BLUE' */
  uint8_T is_active_c3_LED_DEMO;       /* '<Root>/LED LOGIC' */
  uint8_T is_c3_LED_DEMO;              /* '<Root>/LED LOGIC' */
  uint8_T temporalCounter_i1;          /* '<Root>/LED LOGIC' */
} DW_LED_DEMO_T;

/* Real-time Model Data Structure */
struct tag_RTM_LED_DEMO_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_LED_DEMO_T LED_DEMO_B;

/* Block states (default storage) */
extern DW_LED_DEMO_T LED_DEMO_DW;

/* Model entry point functions */
extern void LED_DEMO_initialize(void);
extern void LED_DEMO_step(void);
extern void LED_DEMO_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LED_DEMO_T *const LED_DEMO_M;

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
 * '<Root>' : 'LED_DEMO'
 * '<S1>'   : 'LED_DEMO/LED LOGIC'
 */
#endif                                 /* RTW_HEADER_LED_DEMO_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
