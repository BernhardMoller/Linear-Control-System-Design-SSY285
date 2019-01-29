/*
 * Experiment.c
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

#include "Experiment.h"
#include "Experiment_private.h"
#include "Experiment_dt.h"

/* Block signals (auto storage) */
B_Experiment_T Experiment_B;

/* Continuous states */
X_Experiment_T Experiment_X;

/* Block states (auto storage) */
DW_Experiment_T Experiment_DW;

/* Real-time model */
RT_MODEL_Experiment_T Experiment_M_;
RT_MODEL_Experiment_T *const Experiment_M = &Experiment_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 10;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Experiment_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Experiment_output(void)
{
  real_T y;
  int32_T i;
  real_T u0;
  real_T u2;
  if (rtmIsMajorTimeStep(Experiment_M)) {
    /* set solver stop time */
    if (!(Experiment_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Experiment_M->solverInfo,
                            ((Experiment_M->Timing.clockTickH0 + 1) *
        Experiment_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Experiment_M->solverInfo,
                            ((Experiment_M->Timing.clockTick0 + 1) *
        Experiment_M->Timing.stepSize0 + Experiment_M->Timing.clockTickH0 *
        Experiment_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Experiment_M)) {
    Experiment_M->Timing.t[0] = rtsiGetT(&Experiment_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(Experiment_DW.ResetEncoders_SubsysRanBC);
  if (rtmIsMajorTimeStep(Experiment_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S7>/HIL Read Encoder Timebase' */

    /* S-Function Block: Experiment/SRV02+2DIP-E/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(Experiment_DW.HILReadEncoderTimebase_Task,
        1, &Experiment_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment_M, _rt_error_message);
      } else {
        Experiment_B.HILReadEncoderTimebase_o1 =
          Experiment_DW.HILReadEncoderTimebase_Buffer[0];
        Experiment_B.HILReadEncoderTimebase_o2 =
          Experiment_DW.HILReadEncoderTimebase_Buffer[1];
        Experiment_B.HILReadEncoderTimebase_o3 =
          Experiment_DW.HILReadEncoderTimebase_Buffer[2];
        Experiment_B.HILReadEncoderTimebase_o4 =
          Experiment_DW.HILReadEncoderTimebase_Buffer[3];
      }
    }

    /* Gain: '<S16>/Encoder Calibration  (rad//count)' */
    Experiment_B.EncoderCalibrationradcount = Experiment_P.K_ENC *
      Experiment_B.HILReadEncoderTimebase_o1;

    /* Gain: '<S16>/2D IP Encoder Calibration (rad//count)' */
    y = Experiment_P.K_ENC_2DIP[0];
    Experiment_B.DIPEncoderCalibrationradcount = y *
      Experiment_B.HILReadEncoderTimebase_o3;
  }

  /* Integrator: '<S3>/Integrator' */
  Experiment_B.Integrator[0] = Experiment_X.Integrator_CSTATE[0];
  Experiment_B.Integrator[1] = Experiment_X.Integrator_CSTATE[1];
  Experiment_B.Integrator[2] = Experiment_X.Integrator_CSTATE[2];
  Experiment_B.Integrator[3] = Experiment_X.Integrator_CSTATE[3];

  /* Integrator: '<S16>/Integrator' */
  Experiment_B.Integrator_c = Experiment_X.Integrator_CSTATE_a;

  /* SignalConversion: '<Root>/TmpSignal ConversionAtLQR Gain: XInport1' */
  Experiment_B.TmpSignalConversionAtLQRGainXIn[0] =
    Experiment_B.EncoderCalibrationradcount;
  Experiment_B.TmpSignalConversionAtLQRGainXIn[1] =
    Experiment_B.DIPEncoderCalibrationradcount;
  Experiment_B.TmpSignalConversionAtLQRGainXIn[2] = Experiment_B.Integrator[2];
  Experiment_B.TmpSignalConversionAtLQRGainXIn[3] = Experiment_B.Integrator[3];
  Experiment_B.TmpSignalConversionAtLQRGainXIn[4] = Experiment_B.Integrator_c;

  /* Gain: '<Root>/LQR Gain: X' */
  u0 = 0.0;
  for (i = 0; i < 5; i++) {
    y = -Experiment_P.K_CT[i];
    u0 += y * Experiment_B.TmpSignalConversionAtLQRGainXIn[i];
  }

  Experiment_B.LQRGainX = u0;

  /* End of Gain: '<Root>/LQR Gain: X' */
  if (rtmIsMajorTimeStep(Experiment_M)) {
    /* Gain: '<S17>/Encoder Calibration Y (rad//count)' */
    Experiment_B.EncoderCalibrationYradcount = Experiment_P.K_ENC *
      Experiment_B.HILReadEncoderTimebase_o2;

    /* Gain: '<S17>/2D IP Encoder Y  Calibration (rad//count)' */
    y = Experiment_P.K_ENC_2DIP[1];
    Experiment_B.DIPEncoderYCalibrationradcount = y *
      Experiment_B.HILReadEncoderTimebase_o4;
  }

  /* Integrator: '<S4>/Integrator' */
  Experiment_B.Integrator_e[0] = Experiment_X.Integrator_CSTATE_m[0];
  Experiment_B.Integrator_e[1] = Experiment_X.Integrator_CSTATE_m[1];
  Experiment_B.Integrator_e[2] = Experiment_X.Integrator_CSTATE_m[2];
  Experiment_B.Integrator_e[3] = Experiment_X.Integrator_CSTATE_m[3];

  /* Integrator: '<S17>/Integrator' */
  Experiment_B.Integrator_n = Experiment_X.Integrator_CSTATE_b;

  /* SignalConversion: '<Root>/TmpSignal ConversionAtLQR Gain: YInport1' */
  Experiment_B.TmpSignalConversionAtLQRGainYIn[0] =
    Experiment_B.EncoderCalibrationYradcount;
  Experiment_B.TmpSignalConversionAtLQRGainYIn[1] =
    Experiment_B.DIPEncoderYCalibrationradcount;
  Experiment_B.TmpSignalConversionAtLQRGainYIn[2] = Experiment_B.Integrator_e[2];
  Experiment_B.TmpSignalConversionAtLQRGainYIn[3] = Experiment_B.Integrator_e[3];
  Experiment_B.TmpSignalConversionAtLQRGainYIn[4] = Experiment_B.Integrator_n;

  /* Gain: '<Root>/LQR Gain: Y' */
  u0 = 0.0;
  for (i = 0; i < 5; i++) {
    y = -Experiment_P.K_CT[i];
    u0 += y * Experiment_B.TmpSignalConversionAtLQRGainYIn[i];
  }

  Experiment_B.LQRGainY = u0;

  /* End of Gain: '<Root>/LQR Gain: Y' */

  /* Gain: '<S14>/Direction Convention: (Right-Hand) system' */
  Experiment_B.DirectionConventionRightHandsys[0] =
    Experiment_P.DirectionConventionRightHandsys * Experiment_B.LQRGainX;
  Experiment_B.DirectionConventionRightHandsys[1] =
    Experiment_P.DirectionConventionRightHandsys * Experiment_B.LQRGainY;

  /* Saturate: '<S14>/Amplifier  Saturation (V)' */
  y = -Experiment_P.VMAX_AMP;
  u0 = Experiment_B.DirectionConventionRightHandsys[0];
  u2 = Experiment_P.VMAX_AMP;
  if (u0 > u2) {
    u0 = u2;
  } else {
    if (u0 < y) {
      u0 = y;
    }
  }

  Experiment_B.AmplifierSaturationV[0] = u0;
  u0 = Experiment_B.DirectionConventionRightHandsys[1];
  u2 = Experiment_P.VMAX_AMP;
  if (u0 > u2) {
    u0 = u2;
  } else {
    if (u0 < y) {
      u0 = y;
    }
  }

  Experiment_B.AmplifierSaturationV[1] = u0;

  /* End of Saturate: '<S14>/Amplifier  Saturation (V)' */

  /* Gain: '<S14>/Inverse Amplifier  Gain (V//V)' */
  u0 = Experiment_P.K_AMP;
  y = 1.0 / u0;
  Experiment_B.InverseAmplifierGainVV[0] = y *
    Experiment_B.AmplifierSaturationV[0];
  Experiment_B.InverseAmplifierGainVV[1] = y *
    Experiment_B.AmplifierSaturationV[1];

  /* Saturate: '<S14>/DACB Saturation (V)' */
  y = -Experiment_P.VMAX_DAC;
  u0 = Experiment_B.InverseAmplifierGainVV[0];
  u2 = Experiment_P.VMAX_DAC;
  if (u0 > u2) {
    u0 = u2;
  } else {
    if (u0 < y) {
      u0 = y;
    }
  }

  Experiment_B.DACBSaturationV[0] = u0;
  u0 = Experiment_B.InverseAmplifierGainVV[1];
  u2 = Experiment_P.VMAX_DAC;
  if (u0 > u2) {
    u0 = u2;
  } else {
    if (u0 < y) {
      u0 = y;
    }
  }

  Experiment_B.DACBSaturationV[1] = u0;

  /* End of Saturate: '<S14>/DACB Saturation (V)' */
  if (rtmIsMajorTimeStep(Experiment_M)) {
    /* S-Function (hil_write_analog_block): '<S7>/HIL Write Analog' */

    /* S-Function Block: Experiment/SRV02+2DIP-E/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(Experiment_DW.HILInitialize_Card,
        Experiment_P.HILWriteAnalog_channels, 2, &Experiment_B.DACBSaturationV[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment_M, _rt_error_message);
      }
    }
  }

  /* Gain: '<S14>/Amplifier  Gain (V//V)' */
  y = -Experiment_P.K_AMP;
  Experiment_B.AmplifierGainVV[0] = y * Experiment_B.DACBSaturationV[0];
  Experiment_B.AmplifierGainVV[1] = y * Experiment_B.DACBSaturationV[1];
  if (rtmIsMajorTimeStep(Experiment_M)) {
    /* Outputs for Atomic SubSystem: '<S16>/Pendulum Angle Watchdog: X' */
    /* Abs: '<S19>/Abs' */
    Experiment_B.Abs_i = fabs(Experiment_B.DIPEncoderCalibrationradcount);

    /* RelationalOperator: '<S19>/Check Maximum Allowed Angle' incorporates:
     *  Constant: '<S19>/X MAX'
     */
    Experiment_B.CheckMaximumAllowedAngle_j = (Experiment_P.ALPHA_MAX <
      Experiment_B.Abs_i);

    /* RelationalOperator: '<S22>/Compare' incorporates:
     *  Constant: '<S22>/Constant'
     */
    Experiment_B.Compare_i = (Experiment_B.CheckMaximumAllowedAngle_j !=
      Experiment_P.Constant_Value);

    /* Stop: '<S21>/Stop Simulation' */
    if (Experiment_B.Compare_i) {
      rtmSetStopRequested(Experiment_M, 1);
    }

    /* End of Stop: '<S21>/Stop Simulation' */
    /* End of Outputs for SubSystem: '<S16>/Pendulum Angle Watchdog: X' */

    /* Outputs for Atomic SubSystem: '<S16>/SRV02 X Angle Watchdog' */
    /* Abs: '<S20>/Abs' */
    Experiment_B.Abs_cx = fabs(Experiment_B.EncoderCalibrationradcount);

    /* RelationalOperator: '<S20>/Check Maximum Allowed Angle' incorporates:
     *  Constant: '<S20>/X MAX'
     */
    Experiment_B.CheckMaximumAllowedAngle_gq = (Experiment_P.THETA_MAX <
      Experiment_B.Abs_cx);

    /* RelationalOperator: '<S24>/Compare' incorporates:
     *  Constant: '<S24>/Constant'
     */
    Experiment_B.Compare_e = (Experiment_B.CheckMaximumAllowedAngle_gq !=
      Experiment_P.Constant_Value_k);

    /* Stop: '<S23>/Stop Simulation' */
    if (Experiment_B.Compare_e) {
      rtmSetStopRequested(Experiment_M, 1);
    }

    /* End of Stop: '<S23>/Stop Simulation' */
    /* End of Outputs for SubSystem: '<S16>/SRV02 X Angle Watchdog' */

    /* Outputs for Atomic SubSystem: '<S17>/Pendulum Angle Watchdog: Y' */
    /* Abs: '<S25>/Abs' */
    Experiment_B.Abs_c = fabs(Experiment_B.DIPEncoderYCalibrationradcount);

    /* RelationalOperator: '<S25>/Check Maximum Allowed Angle' incorporates:
     *  Constant: '<S25>/X MAX'
     */
    Experiment_B.CheckMaximumAllowedAngle_g = (Experiment_P.ALPHA_MAX <
      Experiment_B.Abs_c);

    /* RelationalOperator: '<S28>/Compare' incorporates:
     *  Constant: '<S28>/Constant'
     */
    Experiment_B.Compare_h = (Experiment_B.CheckMaximumAllowedAngle_g !=
      Experiment_P.Constant_Value_m);

    /* Stop: '<S27>/Stop Simulation' */
    if (Experiment_B.Compare_h) {
      rtmSetStopRequested(Experiment_M, 1);
    }

    /* End of Stop: '<S27>/Stop Simulation' */
    /* End of Outputs for SubSystem: '<S17>/Pendulum Angle Watchdog: Y' */

    /* Outputs for Atomic SubSystem: '<S17>/SRV02 Y Angle Watchdog' */
    /* Abs: '<S26>/Abs' */
    Experiment_B.Abs = fabs(Experiment_B.EncoderCalibrationYradcount);

    /* RelationalOperator: '<S26>/Check Maximum Allowed Angle' incorporates:
     *  Constant: '<S26>/X MAX'
     */
    Experiment_B.CheckMaximumAllowedAngle = (Experiment_P.THETA_MAX <
      Experiment_B.Abs);

    /* RelationalOperator: '<S30>/Compare' incorporates:
     *  Constant: '<S30>/Constant'
     */
    Experiment_B.Compare_f = (Experiment_B.CheckMaximumAllowedAngle !=
      Experiment_P.Constant_Value_p);

    /* Stop: '<S29>/Stop Simulation' */
    if (Experiment_B.Compare_f) {
      rtmSetStopRequested(Experiment_M, 1);
    }

    /* End of Stop: '<S29>/Stop Simulation' */
    /* End of Outputs for SubSystem: '<S17>/SRV02 Y Angle Watchdog' */
  }

  /* Clock: '<S7>/Clock' */
  Experiment_B.Clock = Experiment_M->Timing.t[0];

  /* RelationalOperator: '<S15>/Compare' incorporates:
   *  Constant: '<S15>/Constant'
   */
  Experiment_B.Compare = (uint8_T)(Experiment_B.Clock <=
    Experiment_P.CompareToConstant_const);
  if (rtmIsMajorTimeStep(Experiment_M)) {
    /* Outputs for Enabled SubSystem: '<S7>/Reset Encoders' incorporates:
     *  EnablePort: '<S18>/Enable'
     */
    if (Experiment_B.Compare > 0) {
      /* S-Function (hil_set_encoder_counts_block): '<S18>/HIL Set Encoder Counts' */

      /* S-Function Block: Experiment/SRV02+2DIP-E/Reset Encoders/HIL Set Encoder Counts (hil_set_encoder_counts_block) */
      {
        t_error result;
        Experiment_DW.HILSetEncoderCounts_Buffer[0] =
          Experiment_P.HILSetEncoderCounts_counts;
        Experiment_DW.HILSetEncoderCounts_Buffer[1] =
          Experiment_P.HILSetEncoderCounts_counts;
        Experiment_DW.HILSetEncoderCounts_Buffer[2] =
          Experiment_P.HILSetEncoderCounts_counts;
        Experiment_DW.HILSetEncoderCounts_Buffer[3] =
          Experiment_P.HILSetEncoderCounts_counts;
        result = hil_set_encoder_counts(Experiment_DW.HILInitialize_Card,
          Experiment_P.HILSetEncoderCounts_channels, 4,
          &Experiment_DW.HILSetEncoderCounts_Buffer[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Experiment_M, _rt_error_message);
        }
      }

      if (rtmIsMajorTimeStep(Experiment_M)) {
        srUpdateBC(Experiment_DW.ResetEncoders_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S7>/Reset Encoders' */

    /* S-Function (hil_write_digital_block): '<S7>/HIL Write Digital' */

    /* S-Function Block: Experiment/SRV02+2DIP-E/HIL Write Digital (hil_write_digital_block) */
    {
      t_error result;
      Experiment_DW.HILWriteDigital_Buffer[0] =
        (Experiment_P.EnableVoltPAQX2X4_Value[0] != 0);
      Experiment_DW.HILWriteDigital_Buffer[1] =
        (Experiment_P.EnableVoltPAQX2X4_Value[1] != 0);
      Experiment_DW.HILWriteDigital_Buffer[2] =
        (Experiment_P.EnableVoltPAQX2X4_Value[2] != 0);
      Experiment_DW.HILWriteDigital_Buffer[3] =
        (Experiment_P.EnableVoltPAQX2X4_Value[3] != 0);
      result = hil_write_digital(Experiment_DW.HILInitialize_Card,
        Experiment_P.HILWriteDigital_channels, 4,
        &Experiment_DW.HILWriteDigital_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment_M, _rt_error_message);
      }
    }

    /* Gain: '<S32>/Gain' */
    Experiment_B.Gain = Experiment_P.Gain_Gain *
      Experiment_B.DIPEncoderCalibrationradcount;
  }

  /* Gain: '<S34>/Gain' */
  Experiment_B.Gain_j = Experiment_P.Gain_Gain_j * Experiment_B.Integrator[3];
  if (rtmIsMajorTimeStep(Experiment_M)) {
  }

  /* Gain: '<S35>/Gain' */
  Experiment_B.Gain_l = Experiment_P.Gain_Gain_l * Experiment_B.Integrator_c;
  if (rtmIsMajorTimeStep(Experiment_M)) {
    /* Gain: '<S31>/Gain' */
    Experiment_B.Gain_f = Experiment_P.Gain_Gain_m *
      Experiment_B.EncoderCalibrationradcount;
  }

  /* Gain: '<S33>/Gain' */
  Experiment_B.Gain_d = Experiment_P.Gain_Gain_g * Experiment_B.Integrator[2];
  if (rtmIsMajorTimeStep(Experiment_M)) {
    /* Gain: '<S37>/Gain' */
    Experiment_B.Gain_p = Experiment_P.Gain_Gain_jt *
      Experiment_B.DIPEncoderYCalibrationradcount;
  }

  /* Gain: '<S39>/Gain' */
  Experiment_B.Gain_g = Experiment_P.Gain_Gain_h * Experiment_B.Integrator_e[3];
  if (rtmIsMajorTimeStep(Experiment_M)) {
  }

  /* Gain: '<S40>/Gain' */
  Experiment_B.Gain_gf = Experiment_P.Gain_Gain_p * Experiment_B.Integrator_n;
  if (rtmIsMajorTimeStep(Experiment_M)) {
    /* Gain: '<S36>/Gain' */
    Experiment_B.Gain_l5 = Experiment_P.Gain_Gain_pk *
      Experiment_B.EncoderCalibrationYradcount;
  }

  /* Gain: '<S38>/Gain' */
  Experiment_B.Gain_dr = Experiment_P.Gain_Gain_g4 * Experiment_B.Integrator_e[2];
  if (rtmIsMajorTimeStep(Experiment_M)) {
  }

  /* Sum: '<Root>/Sum' */
  Experiment_B.Sum[0] = Experiment_B.EncoderCalibrationradcount -
    Experiment_B.Integrator[0];
  Experiment_B.Sum[1] = Experiment_B.DIPEncoderCalibrationradcount -
    Experiment_B.Integrator[1];

  /* Gain: '<S12>/Gain' */
  Experiment_B.Gain_b[0] = Experiment_P.Gain_Gain_n * Experiment_B.Sum[0];
  Experiment_B.Gain_b[1] = Experiment_P.Gain_Gain_n * Experiment_B.Sum[1];
  if (rtmIsMajorTimeStep(Experiment_M)) {
  }

  /* Gain: '<S13>/Gain' */
  Experiment_B.Gain_i[0] = Experiment_P.Gain_Gain_m3 * Experiment_B.Integrator[0];
  Experiment_B.Gain_i[1] = Experiment_P.Gain_Gain_m3 * Experiment_B.Integrator[1];
  if (rtmIsMajorTimeStep(Experiment_M)) {
  }

  /* Gain: '<S3>/-sysc.c_x' */
  for (i = 0; i < 2; i++) {
    Experiment_B.syscc_x[i] = 0.0;
    Experiment_B.syscc_x[i] += Experiment_P.syscc_x_Gain[i] *
      Experiment_B.Integrator[0];
    Experiment_B.syscc_x[i] += Experiment_P.syscc_x_Gain[i + 2] *
      Experiment_B.Integrator[1];
    Experiment_B.syscc_x[i] += Experiment_P.syscc_x_Gain[i + 4] *
      Experiment_B.Integrator[2];
    Experiment_B.syscc_x[i] += Experiment_P.syscc_x_Gain[i + 6] *
      Experiment_B.Integrator[3];
  }

  /* End of Gain: '<S3>/-sysc.c_x' */

  /* Sum: '<S3>/Sum1' */
  Experiment_B.Sum1[0] = Experiment_B.EncoderCalibrationradcount -
    Experiment_B.syscc_x[0];
  Experiment_B.Sum1[1] = Experiment_B.DIPEncoderCalibrationradcount -
    Experiment_B.syscc_x[1];

  /* Gain: '<S3>/Kalman Filter Gain' */
  for (i = 0; i < 4; i++) {
    Experiment_B.KalmanFilterGain[i] = 0.0;
    Experiment_B.KalmanFilterGain[i] += Experiment_P.L_CT[i] *
      Experiment_B.Sum1[0];
    Experiment_B.KalmanFilterGain[i] += Experiment_P.L_CT[i + 4] *
      Experiment_B.Sum1[1];
  }

  /* End of Gain: '<S3>/Kalman Filter Gain' */

  /* Gain: '<S3>/sysc.b_x' */
  Experiment_B.syscb_x[0] = Experiment_P.syscb_x_Gain[0] * Experiment_B.LQRGainX;
  Experiment_B.syscb_x[1] = Experiment_P.syscb_x_Gain[1] * Experiment_B.LQRGainX;
  Experiment_B.syscb_x[2] = Experiment_P.syscb_x_Gain[2] * Experiment_B.LQRGainX;
  Experiment_B.syscb_x[3] = Experiment_P.syscb_x_Gain[3] * Experiment_B.LQRGainX;

  /* Gain: '<S3>/sysc.a_x' */
  for (i = 0; i < 4; i++) {
    Experiment_B.sysca_x[i] = 0.0;
    Experiment_B.sysca_x[i] += Experiment_P.sysca_x_Gain[i] *
      Experiment_B.Integrator[0];
    Experiment_B.sysca_x[i] += Experiment_P.sysca_x_Gain[i + 4] *
      Experiment_B.Integrator[1];
    Experiment_B.sysca_x[i] += Experiment_P.sysca_x_Gain[i + 8] *
      Experiment_B.Integrator[2];
    Experiment_B.sysca_x[i] += Experiment_P.sysca_x_Gain[i + 12] *
      Experiment_B.Integrator[3];
  }

  /* End of Gain: '<S3>/sysc.a_x' */

  /* Sum: '<S3>/Sum' */
  Experiment_B.Sum_n[0] = (Experiment_B.KalmanFilterGain[0] +
    Experiment_B.syscb_x[0]) + Experiment_B.sysca_x[0];
  Experiment_B.Sum_n[1] = (Experiment_B.KalmanFilterGain[1] +
    Experiment_B.syscb_x[1]) + Experiment_B.sysca_x[1];
  Experiment_B.Sum_n[2] = (Experiment_B.KalmanFilterGain[2] +
    Experiment_B.syscb_x[2]) + Experiment_B.sysca_x[2];
  Experiment_B.Sum_n[3] = (Experiment_B.KalmanFilterGain[3] +
    Experiment_B.syscb_x[3]) + Experiment_B.sysca_x[3];

  /* Gain: '<S4>/-sysd.c_x' */
  for (i = 0; i < 2; i++) {
    Experiment_B.sysdc_x[i] = 0.0;
    Experiment_B.sysdc_x[i] += Experiment_P.sysdc_x_Gain[i] *
      Experiment_B.Integrator_e[0];
    Experiment_B.sysdc_x[i] += Experiment_P.sysdc_x_Gain[i + 2] *
      Experiment_B.Integrator_e[1];
    Experiment_B.sysdc_x[i] += Experiment_P.sysdc_x_Gain[i + 4] *
      Experiment_B.Integrator_e[2];
    Experiment_B.sysdc_x[i] += Experiment_P.sysdc_x_Gain[i + 6] *
      Experiment_B.Integrator_e[3];
  }

  /* End of Gain: '<S4>/-sysd.c_x' */

  /* Sum: '<S4>/Sum1' */
  Experiment_B.Sum1_n[0] = Experiment_B.EncoderCalibrationYradcount -
    Experiment_B.sysdc_x[0];
  Experiment_B.Sum1_n[1] = Experiment_B.DIPEncoderYCalibrationradcount -
    Experiment_B.sysdc_x[1];

  /* Gain: '<S4>/Kalman Filter Gain' */
  for (i = 0; i < 4; i++) {
    Experiment_B.KalmanFilterGain_a[i] = 0.0;
    Experiment_B.KalmanFilterGain_a[i] += Experiment_P.L_CT[i] *
      Experiment_B.Sum1_n[0];
    Experiment_B.KalmanFilterGain_a[i] += Experiment_P.L_CT[i + 4] *
      Experiment_B.Sum1_n[1];
  }

  /* End of Gain: '<S4>/Kalman Filter Gain' */

  /* Gain: '<S4>/sysd.b_x' */
  Experiment_B.sysdb_x[0] = Experiment_P.sysdb_x_Gain[0] * Experiment_B.LQRGainY;
  Experiment_B.sysdb_x[1] = Experiment_P.sysdb_x_Gain[1] * Experiment_B.LQRGainY;
  Experiment_B.sysdb_x[2] = Experiment_P.sysdb_x_Gain[2] * Experiment_B.LQRGainY;
  Experiment_B.sysdb_x[3] = Experiment_P.sysdb_x_Gain[3] * Experiment_B.LQRGainY;

  /* Gain: '<S4>/sysd.a_x' */
  for (i = 0; i < 4; i++) {
    Experiment_B.sysda_x[i] = 0.0;
    Experiment_B.sysda_x[i] += Experiment_P.sysda_x_Gain[i] *
      Experiment_B.Integrator_e[0];
    Experiment_B.sysda_x[i] += Experiment_P.sysda_x_Gain[i + 4] *
      Experiment_B.Integrator_e[1];
    Experiment_B.sysda_x[i] += Experiment_P.sysda_x_Gain[i + 8] *
      Experiment_B.Integrator_e[2];
    Experiment_B.sysda_x[i] += Experiment_P.sysda_x_Gain[i + 12] *
      Experiment_B.Integrator_e[3];
  }

  /* End of Gain: '<S4>/sysd.a_x' */

  /* Sum: '<S4>/Sum' */
  Experiment_B.Sum_b[0] = (Experiment_B.KalmanFilterGain_a[0] +
    Experiment_B.sysdb_x[0]) + Experiment_B.sysda_x[0];
  Experiment_B.Sum_b[1] = (Experiment_B.KalmanFilterGain_a[1] +
    Experiment_B.sysdb_x[1]) + Experiment_B.sysda_x[1];
  Experiment_B.Sum_b[2] = (Experiment_B.KalmanFilterGain_a[2] +
    Experiment_B.sysdb_x[2]) + Experiment_B.sysda_x[2];
  Experiment_B.Sum_b[3] = (Experiment_B.KalmanFilterGain_a[3] +
    Experiment_B.sysdb_x[3]) + Experiment_B.sysda_x[3];
}

/* Model update function */
void Experiment_update(void)
{
  if (rtmIsMajorTimeStep(Experiment_M)) {
    rt_ertODEUpdateContinuousStates(&Experiment_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Experiment_M->Timing.clockTick0)) {
    ++Experiment_M->Timing.clockTickH0;
  }

  Experiment_M->Timing.t[0] = rtsiGetSolverStopTime(&Experiment_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Experiment_M->Timing.clockTick1)) {
      ++Experiment_M->Timing.clockTickH1;
    }

    Experiment_M->Timing.t[1] = Experiment_M->Timing.clockTick1 *
      Experiment_M->Timing.stepSize1 + Experiment_M->Timing.clockTickH1 *
      Experiment_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Experiment_derivatives(void)
{
  XDot_Experiment_T *_rtXdot;
  _rtXdot = ((XDot_Experiment_T *) Experiment_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = Experiment_B.Sum_n[0];
  _rtXdot->Integrator_CSTATE[1] = Experiment_B.Sum_n[1];
  _rtXdot->Integrator_CSTATE[2] = Experiment_B.Sum_n[2];
  _rtXdot->Integrator_CSTATE[3] = Experiment_B.Sum_n[3];

  /* Derivatives for Integrator: '<S16>/Integrator' */
  _rtXdot->Integrator_CSTATE_a = Experiment_B.EncoderCalibrationradcount;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE_m[0] = Experiment_B.Sum_b[0];
  _rtXdot->Integrator_CSTATE_m[1] = Experiment_B.Sum_b[1];
  _rtXdot->Integrator_CSTATE_m[2] = Experiment_B.Sum_b[2];
  _rtXdot->Integrator_CSTATE_m[3] = Experiment_B.Sum_b[3];

  /* Derivatives for Integrator: '<S17>/Integrator' */
  _rtXdot->Integrator_CSTATE_b = Experiment_B.EncoderCalibrationYradcount;
}

/* Model initialize function */
void Experiment_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S7>/HIL Initialize' */

  /* S-Function Block: Experiment/SRV02+2DIP-E/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &Experiment_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Experiment_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(Experiment_DW.HILInitialize_Card,
      "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Experiment_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Experiment_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Experiment_M, _rt_error_message);
      return;
    }

    if ((Experiment_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (Experiment_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &Experiment_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = Experiment_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &Experiment_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = Experiment_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(Experiment_DW.HILInitialize_Card,
        Experiment_P.HILInitialize_analog_input_chan, 8U,
        &Experiment_DW.HILInitialize_AIMinimums[0],
        &Experiment_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment_M, _rt_error_message);
        return;
      }
    }

    if ((Experiment_P.HILInitialize_set_analog_output && !is_switching) ||
        (Experiment_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &Experiment_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = Experiment_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &Experiment_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = Experiment_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(Experiment_DW.HILInitialize_Card,
        Experiment_P.HILInitialize_analog_output_cha, 8U,
        &Experiment_DW.HILInitialize_AOMinimums[0],
        &Experiment_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment_M, _rt_error_message);
        return;
      }
    }

    if ((Experiment_P.HILInitialize_set_analog_outp_i && !is_switching) ||
        (Experiment_P.HILInitialize_set_analog_outp_l && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Experiment_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Experiment_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(Experiment_DW.HILInitialize_Card,
        Experiment_P.HILInitialize_analog_output_cha, 8U,
        &Experiment_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment_M, _rt_error_message);
        return;
      }
    }

    if (Experiment_P.HILInitialize_set_analog_out_g3) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Experiment_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Experiment_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (Experiment_DW.HILInitialize_Card,
         Experiment_P.HILInitialize_analog_output_cha, 8U,
         &Experiment_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(Experiment_DW.HILInitialize_Card, NULL,
      0U, Experiment_P.HILInitialize_digital_output_ch, 8U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Experiment_M, _rt_error_message);
      return;
    }

    if ((Experiment_P.HILInitialize_set_digital_out_j && !is_switching) ||
        (Experiment_P.HILInitialize_set_digital_out_k && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &Experiment_DW.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = Experiment_P.HILInitialize_initial_digital_o;
        }
      }

      result = hil_write_digital(Experiment_DW.HILInitialize_Card,
        Experiment_P.HILInitialize_digital_output_ch, 8U, (t_boolean *)
        &Experiment_DW.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment_M, _rt_error_message);
        return;
      }
    }

    if (Experiment_P.HILInitialize_set_digital_out_p) {
      {
        int_T i1;
        int32_T *dw_DOStates = &Experiment_DW.HILInitialize_DOStates[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOStates[i1] = Experiment_P.HILInitialize_watchdog_digital_;
        }
      }

      result = hil_watchdog_set_digital_expiration_state
        (Experiment_DW.HILInitialize_Card,
         Experiment_P.HILInitialize_digital_output_ch, 8U, (const
          t_digital_state *) &Experiment_DW.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment_M, _rt_error_message);
        return;
      }
    }

    if ((Experiment_P.HILInitialize_set_encoder_param && !is_switching) ||
        (Experiment_P.HILInitialize_set_encoder_par_c && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &Experiment_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = Experiment_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(Experiment_DW.HILInitialize_Card,
        Experiment_P.HILInitialize_encoder_channels, 8U,
        (t_encoder_quadrature_mode *)
        &Experiment_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment_M, _rt_error_message);
        return;
      }
    }

    if ((Experiment_P.HILInitialize_set_encoder_count && !is_switching) ||
        (Experiment_P.HILInitialize_set_encoder_cou_c && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &Experiment_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = Experiment_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(Experiment_DW.HILInitialize_Card,
        Experiment_P.HILInitialize_encoder_channels, 8U,
        &Experiment_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment_M, _rt_error_message);
        return;
      }
    }

    if ((Experiment_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (Experiment_P.HILInitialize_set_pwm_params__n && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &Experiment_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = Experiment_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(Experiment_DW.HILInitialize_Card,
        Experiment_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &Experiment_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          Experiment_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &Experiment_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            Experiment_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            Experiment_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              Experiment_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            Experiment_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              p_HILInitialize_pwm_channels[i1];
            Experiment_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              Experiment_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(Experiment_DW.HILInitialize_Card,
          &Experiment_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &Experiment_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Experiment_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(Experiment_DW.HILInitialize_Card,
          &Experiment_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &Experiment_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Experiment_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &Experiment_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = Experiment_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &Experiment_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = Experiment_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &Experiment_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = Experiment_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(Experiment_DW.HILInitialize_Card,
        Experiment_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &Experiment_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &Experiment_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &Experiment_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &Experiment_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = Experiment_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &Experiment_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Experiment_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(Experiment_DW.HILInitialize_Card,
        Experiment_P.HILInitialize_pwm_channels, 8U,
        &Experiment_DW.HILInitialize_POSortedFreqs[0],
        &Experiment_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment_M, _rt_error_message);
        return;
      }
    }

    if ((Experiment_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (Experiment_P.HILInitialize_set_pwm_outputs_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Experiment_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Experiment_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(Experiment_DW.HILInitialize_Card,
        Experiment_P.HILInitialize_pwm_channels, 8U,
        &Experiment_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment_M, _rt_error_message);
        return;
      }
    }

    if (Experiment_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &Experiment_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Experiment_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (Experiment_DW.HILInitialize_Card,
         Experiment_P.HILInitialize_pwm_channels, 8U,
         &Experiment_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S7>/HIL Read Encoder Timebase' */

  /* S-Function Block: Experiment/SRV02+2DIP-E/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(Experiment_DW.HILInitialize_Card,
      Experiment_P.HILReadEncoderTimebase_samples_,
      Experiment_P.HILReadEncoderTimebase_channels, 4,
      &Experiment_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Experiment_M, _rt_error_message);
    }
  }

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  Experiment_X.Integrator_CSTATE[0] = Experiment_P.Integrator_IC;
  Experiment_X.Integrator_CSTATE[1] = Experiment_P.Integrator_IC;
  Experiment_X.Integrator_CSTATE[2] = Experiment_P.Integrator_IC;
  Experiment_X.Integrator_CSTATE[3] = Experiment_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S16>/Integrator' */
  Experiment_X.Integrator_CSTATE_a = Experiment_P.Integrator_IC_e;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  Experiment_X.Integrator_CSTATE_m[0] = Experiment_P.Integrator_IC_b;
  Experiment_X.Integrator_CSTATE_m[1] = Experiment_P.Integrator_IC_b;
  Experiment_X.Integrator_CSTATE_m[2] = Experiment_P.Integrator_IC_b;
  Experiment_X.Integrator_CSTATE_m[3] = Experiment_P.Integrator_IC_b;

  /* InitializeConditions for Integrator: '<S17>/Integrator' */
  Experiment_X.Integrator_CSTATE_b = Experiment_P.Integrator_IC_o;
}

/* Model terminate function */
void Experiment_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S7>/HIL Initialize' */

  /* S-Function Block: Experiment/SRV02+2DIP-E/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(Experiment_DW.HILInitialize_Card);
    hil_monitor_stop_all(Experiment_DW.HILInitialize_Card);
    is_switching = false;
    if ((Experiment_P.HILInitialize_set_analog_outp_g && !is_switching) ||
        (Experiment_P.HILInitialize_set_analog_outp_f && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Experiment_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Experiment_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((Experiment_P.HILInitialize_set_digital_out_h && !is_switching) ||
        (Experiment_P.HILInitialize_set_digital_ou_j0 && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &Experiment_DW.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = Experiment_P.HILInitialize_final_digital_out;
        }
      }

      num_final_digital_outputs = 8U;
    }

    if ((Experiment_P.HILInitialize_set_pwm_outputs_c && !is_switching) ||
        (Experiment_P.HILInitialize_set_pwm_outputs_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Experiment_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Experiment_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        || num_final_digital_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(Experiment_DW.HILInitialize_Card
                         , Experiment_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , Experiment_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , Experiment_P.HILInitialize_digital_output_ch,
                         num_final_digital_outputs
                         , NULL, 0
                         , &Experiment_DW.HILInitialize_AOVoltages[0]
                         , &Experiment_DW.HILInitialize_POValues[0]
                         , (t_boolean *) &Experiment_DW.HILInitialize_DOBits[0]
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(Experiment_DW.HILInitialize_Card,
            Experiment_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs, &Experiment_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(Experiment_DW.HILInitialize_Card,
            Experiment_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &Experiment_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(Experiment_DW.HILInitialize_Card,
            Experiment_P.HILInitialize_digital_output_ch,
            num_final_digital_outputs, (t_boolean *)
            &Experiment_DW.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Experiment_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Experiment_DW.HILInitialize_Card);
    hil_monitor_delete_all(Experiment_DW.HILInitialize_Card);
    hil_close(Experiment_DW.HILInitialize_Card);
    Experiment_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Experiment_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Experiment_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Experiment_initialize();
}

void MdlTerminate(void)
{
  Experiment_terminate();
}

/* Registration function */
RT_MODEL_Experiment_T *Experiment(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Experiment_M, 0,
                sizeof(RT_MODEL_Experiment_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Experiment_M->solverInfo,
                          &Experiment_M->Timing.simTimeStep);
    rtsiSetTPtr(&Experiment_M->solverInfo, &rtmGetTPtr(Experiment_M));
    rtsiSetStepSizePtr(&Experiment_M->solverInfo,
                       &Experiment_M->Timing.stepSize0);
    rtsiSetdXPtr(&Experiment_M->solverInfo, &Experiment_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Experiment_M->solverInfo, (real_T **)
                         &Experiment_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Experiment_M->solverInfo,
      &Experiment_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Experiment_M->solverInfo, (&rtmGetErrorStatus
      (Experiment_M)));
    rtsiSetRTModelPtr(&Experiment_M->solverInfo, Experiment_M);
  }

  rtsiSetSimTimeStep(&Experiment_M->solverInfo, MAJOR_TIME_STEP);
  Experiment_M->ModelData.intgData.f[0] = Experiment_M->ModelData.odeF[0];
  Experiment_M->ModelData.contStates = ((real_T *) &Experiment_X);
  rtsiSetSolverData(&Experiment_M->solverInfo, (void *)
                    &Experiment_M->ModelData.intgData);
  rtsiSetSolverName(&Experiment_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Experiment_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Experiment_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Experiment_M->Timing.sampleTimes = (&Experiment_M->Timing.sampleTimesArray[0]);
    Experiment_M->Timing.offsetTimes = (&Experiment_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Experiment_M->Timing.sampleTimes[0] = (0.0);
    Experiment_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Experiment_M->Timing.offsetTimes[0] = (0.0);
    Experiment_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Experiment_M, &Experiment_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Experiment_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Experiment_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Experiment_M, -1);
  Experiment_M->Timing.stepSize0 = 0.001;
  Experiment_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  Experiment_M->Sizes.checksums[0] = (1768262624U);
  Experiment_M->Sizes.checksums[1] = (2860920247U);
  Experiment_M->Sizes.checksums[2] = (2837659142U);
  Experiment_M->Sizes.checksums[3] = (1157651300U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    Experiment_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)&Experiment_DW.ResetEncoders_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Experiment_M->extModeInfo,
      &Experiment_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Experiment_M->extModeInfo, Experiment_M->Sizes.checksums);
    rteiSetTPtr(Experiment_M->extModeInfo, rtmGetTPtr(Experiment_M));
  }

  Experiment_M->solverInfoPtr = (&Experiment_M->solverInfo);
  Experiment_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Experiment_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Experiment_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Experiment_M->ModelData.blockIO = ((void *) &Experiment_B);
  (void) memset(((void *) &Experiment_B), 0,
                sizeof(B_Experiment_T));

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      Experiment_B.TmpSignalConversionAtLQRGainXIn[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      Experiment_B.TmpSignalConversionAtLQRGainYIn[i] = 0.0;
    }

    Experiment_B.HILReadEncoderTimebase_o1 = 0.0;
    Experiment_B.HILReadEncoderTimebase_o2 = 0.0;
    Experiment_B.HILReadEncoderTimebase_o3 = 0.0;
    Experiment_B.HILReadEncoderTimebase_o4 = 0.0;
    Experiment_B.EncoderCalibrationradcount = 0.0;
    Experiment_B.DIPEncoderCalibrationradcount = 0.0;
    Experiment_B.Integrator[0] = 0.0;
    Experiment_B.Integrator[1] = 0.0;
    Experiment_B.Integrator[2] = 0.0;
    Experiment_B.Integrator[3] = 0.0;
    Experiment_B.Integrator_c = 0.0;
    Experiment_B.LQRGainX = 0.0;
    Experiment_B.EncoderCalibrationYradcount = 0.0;
    Experiment_B.DIPEncoderYCalibrationradcount = 0.0;
    Experiment_B.Integrator_e[0] = 0.0;
    Experiment_B.Integrator_e[1] = 0.0;
    Experiment_B.Integrator_e[2] = 0.0;
    Experiment_B.Integrator_e[3] = 0.0;
    Experiment_B.Integrator_n = 0.0;
    Experiment_B.LQRGainY = 0.0;
    Experiment_B.DirectionConventionRightHandsys[0] = 0.0;
    Experiment_B.DirectionConventionRightHandsys[1] = 0.0;
    Experiment_B.AmplifierSaturationV[0] = 0.0;
    Experiment_B.AmplifierSaturationV[1] = 0.0;
    Experiment_B.InverseAmplifierGainVV[0] = 0.0;
    Experiment_B.InverseAmplifierGainVV[1] = 0.0;
    Experiment_B.DACBSaturationV[0] = 0.0;
    Experiment_B.DACBSaturationV[1] = 0.0;
    Experiment_B.AmplifierGainVV[0] = 0.0;
    Experiment_B.AmplifierGainVV[1] = 0.0;
    Experiment_B.Clock = 0.0;
    Experiment_B.Gain = 0.0;
    Experiment_B.Gain_j = 0.0;
    Experiment_B.Gain_l = 0.0;
    Experiment_B.Gain_f = 0.0;
    Experiment_B.Gain_d = 0.0;
    Experiment_B.Gain_p = 0.0;
    Experiment_B.Gain_g = 0.0;
    Experiment_B.Gain_gf = 0.0;
    Experiment_B.Gain_l5 = 0.0;
    Experiment_B.Gain_dr = 0.0;
    Experiment_B.Sum[0] = 0.0;
    Experiment_B.Sum[1] = 0.0;
    Experiment_B.Gain_b[0] = 0.0;
    Experiment_B.Gain_b[1] = 0.0;
    Experiment_B.Gain_i[0] = 0.0;
    Experiment_B.Gain_i[1] = 0.0;
    Experiment_B.syscc_x[0] = 0.0;
    Experiment_B.syscc_x[1] = 0.0;
    Experiment_B.Sum1[0] = 0.0;
    Experiment_B.Sum1[1] = 0.0;
    Experiment_B.KalmanFilterGain[0] = 0.0;
    Experiment_B.KalmanFilterGain[1] = 0.0;
    Experiment_B.KalmanFilterGain[2] = 0.0;
    Experiment_B.KalmanFilterGain[3] = 0.0;
    Experiment_B.syscb_x[0] = 0.0;
    Experiment_B.syscb_x[1] = 0.0;
    Experiment_B.syscb_x[2] = 0.0;
    Experiment_B.syscb_x[3] = 0.0;
    Experiment_B.sysca_x[0] = 0.0;
    Experiment_B.sysca_x[1] = 0.0;
    Experiment_B.sysca_x[2] = 0.0;
    Experiment_B.sysca_x[3] = 0.0;
    Experiment_B.Sum_n[0] = 0.0;
    Experiment_B.Sum_n[1] = 0.0;
    Experiment_B.Sum_n[2] = 0.0;
    Experiment_B.Sum_n[3] = 0.0;
    Experiment_B.sysdc_x[0] = 0.0;
    Experiment_B.sysdc_x[1] = 0.0;
    Experiment_B.Sum1_n[0] = 0.0;
    Experiment_B.Sum1_n[1] = 0.0;
    Experiment_B.KalmanFilterGain_a[0] = 0.0;
    Experiment_B.KalmanFilterGain_a[1] = 0.0;
    Experiment_B.KalmanFilterGain_a[2] = 0.0;
    Experiment_B.KalmanFilterGain_a[3] = 0.0;
    Experiment_B.sysdb_x[0] = 0.0;
    Experiment_B.sysdb_x[1] = 0.0;
    Experiment_B.sysdb_x[2] = 0.0;
    Experiment_B.sysdb_x[3] = 0.0;
    Experiment_B.sysda_x[0] = 0.0;
    Experiment_B.sysda_x[1] = 0.0;
    Experiment_B.sysda_x[2] = 0.0;
    Experiment_B.sysda_x[3] = 0.0;
    Experiment_B.Sum_b[0] = 0.0;
    Experiment_B.Sum_b[1] = 0.0;
    Experiment_B.Sum_b[2] = 0.0;
    Experiment_B.Sum_b[3] = 0.0;
    Experiment_B.Abs = 0.0;
    Experiment_B.CheckMaximumAllowedAngle = 0.0;
    Experiment_B.Abs_c = 0.0;
    Experiment_B.CheckMaximumAllowedAngle_g = 0.0;
    Experiment_B.Abs_cx = 0.0;
    Experiment_B.CheckMaximumAllowedAngle_gq = 0.0;
    Experiment_B.Abs_i = 0.0;
    Experiment_B.CheckMaximumAllowedAngle_j = 0.0;
  }

  /* parameters */
  Experiment_M->ModelData.defaultParam = ((real_T *)&Experiment_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Experiment_X;
    Experiment_M->ModelData.contStates = (x);
    (void) memset((void *)&Experiment_X, 0,
                  sizeof(X_Experiment_T));
  }

  /* states (dwork) */
  Experiment_M->ModelData.dwork = ((void *) &Experiment_DW);
  (void) memset((void *)&Experiment_DW, 0,
                sizeof(DW_Experiment_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Experiment_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Experiment_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Experiment_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Experiment_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Experiment_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Experiment_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Experiment_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Experiment_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Experiment_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  Experiment_M->Sizes.numContStates = (10);/* Number of continuous states */
  Experiment_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Experiment_M->Sizes.numY = (0);      /* Number of model outputs */
  Experiment_M->Sizes.numU = (0);      /* Number of model inputs */
  Experiment_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Experiment_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Experiment_M->Sizes.numBlocks = (99);/* Number of blocks */
  Experiment_M->Sizes.numBlockIO = (60);/* Number of block outputs */
  Experiment_M->Sizes.numBlockPrms = (230);/* Sum of parameter "widths" */
  return Experiment_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
