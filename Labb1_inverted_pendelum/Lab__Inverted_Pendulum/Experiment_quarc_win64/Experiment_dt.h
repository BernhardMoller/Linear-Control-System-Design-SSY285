/*
 * Experiment_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Experiment".
 *
 * Model version              : 1.599
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Nov 24 11:15:38 2016
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_card),
  sizeof(t_task),
  sizeof(t_boolean)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_card",
  "t_task",
  "t_boolean"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Experiment_B.HILReadEncoderTimebase_o1), 0, 0, 105 },

  { (char_T *)(&Experiment_B.Compare), 3, 0, 1 },

  { (char_T *)(&Experiment_B.Compare_f), 8, 0, 4 }
  ,

  { (char_T *)(&Experiment_DW.HILInitialize_AIMinimums[0]), 0, 0, 64 },

  { (char_T *)(&Experiment_DW.HILInitialize_Card), 14, 0, 1 },

  { (char_T *)(&Experiment_DW.HILReadEncoderTimebase_Task), 15, 0, 1 },

  { (char_T *)(&Experiment_DW.HILWriteAnalog_PWORK), 11, 0, 18 },

  { (char_T *)(&Experiment_DW.HILInitialize_ClockModes[0]), 6, 0, 59 },

  { (char_T *)(&Experiment_DW.HILInitialize_POSortedChans[0]), 7, 0, 8 },

  { (char_T *)(&Experiment_DW.ResetEncoders_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&Experiment_DW.HILInitialize_DOBits[0]), 8, 0, 8 },

  { (char_T *)(&Experiment_DW.HILWriteDigital_Buffer[0]), 16, 0, 4 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  12U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Experiment_P.ALPHA_MAX), 0, 0, 39 },

  { (char_T *)(&Experiment_P.HILReadEncoderTimebase_clock), 6, 0, 11 },

  { (char_T *)(&Experiment_P.HILInitialize_analog_input_chan[0]), 7, 0, 56 },

  { (char_T *)(&Experiment_P.StopwithMessage_message_icon), 2, 0, 4 },

  { (char_T *)(&Experiment_P.HILInitialize_active), 8, 0, 35 },

  { (char_T *)(&Experiment_P.Constant_Value), 0, 0, 81 },

  { (char_T *)(&Experiment_P.HILSetEncoderCounts_Active), 8, 0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] Experiment_dt.h */
