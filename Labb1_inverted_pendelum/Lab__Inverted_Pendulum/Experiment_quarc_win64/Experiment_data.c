/*
 * Experiment_data.c
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

/* Block parameters (auto storage) */
P_Experiment_T Experiment_P = {
  0.087266462599716474,                /* Variable: ALPHA_MAX
                                        * Referenced by:
                                        *   '<S19>/X MAX'
                                        *   '<S25>/X MAX'
                                        */
  1.0,                                 /* Variable: K_AMP
                                        * Referenced by:
                                        *   '<S14>/Amplifier  Gain (V//V)'
                                        *   '<S14>/Inverse Amplifier  Gain (V//V)'
                                        */

  /*  Variable: K_CT
   * Referenced by:
   *   '<Root>/LQR Gain: X'
   *   '<Root>/LQR Gain: Y'
   */
  { -32.149807875133547, 176.63264868621582, -12.41975153553696,
    25.669895833738678, -1.41421356237327 },
  0.0015339807878856412,               /* Variable: K_ENC
                                        * Referenced by:
                                        *   '<S16>/Encoder Calibration  (rad//count)'
                                        *   '<S17>/Encoder Calibration Y (rad//count)'
                                        */

  /*  Variable: K_ENC_2DIP
   * Referenced by:
   *   '<S16>/2D IP Encoder Calibration (rad//count)'
   *   '<S17>/2D IP Encoder Y  Calibration (rad//count)'
   */
  { 0.0015339807878856412, 0.0015339807878856412 },

  /*  Variable: L_CT
   * Referenced by:
   *   '<S3>/Kalman Filter Gain'
   *   '<S4>/Kalman Filter Gain'
   */
  { 6.49697924216958, -0.19857130212532673, 21.125084917605029,
    -13.259005223216441, -0.19857130212532673, 16.764948139148732,
    8.6398540131634682, 140.55145833518668 },
  0.6108652381980153,                  /* Variable: THETA_MAX
                                        * Referenced by:
                                        *   '<S20>/X MAX'
                                        *   '<S26>/X MAX'
                                        */
  24.0,                                /* Variable: VMAX_AMP
                                        * Referenced by: '<S14>/Amplifier  Saturation (V)'
                                        */
  10.0,                                /* Variable: VMAX_DAC
                                        * Referenced by: '<S14>/DACB Saturation (V)'
                                        */
  10.0,                                /* Mask Parameter: HILInitialize_analog_input_maxi
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  -10.0,                               /* Mask Parameter: HILInitialize_analog_input_mini
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  10.0,                                /* Mask Parameter: HILInitialize_analog_output_max
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  -10.0,                               /* Mask Parameter: HILInitialize_analog_output_min
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0.25,                                /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S15>/Constant'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_final_analog_outp
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_final_pwm_outputs
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_initial_analog_ou
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_initial_pwm_outpu
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  24305.934065934067,                  /* Mask Parameter: HILInitialize_pwm_frequency
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_pwm_leading_deadb
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_pwm_trailing_dead
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outputs
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_a
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_n
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outp_nc
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_watchdog_analog_o
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_watchdog_pwm_outp
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILReadEncoderTimebase_clock
                                        * Referenced by: '<S7>/HIL Read Encoder Timebase'
                                        */
  0,                                   /* Mask Parameter: HILSetEncoderCounts_counts
                                        * Referenced by: '<S18>/HIL Set Encoder Counts'
                                        */

  /*  Mask Parameter: HILInitialize_hardware_clocks
   * Referenced by: '<S7>/HIL Initialize'
   */
  { 0, 1, 2 },
  0,                                   /* Mask Parameter: HILInitialize_initial_encoder_c
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_alignment
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_configuration
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_modes
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_pwm_polarity
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_watchdog_digital_
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */

  /*  Mask Parameter: HILInitialize_analog_input_chan
   * Referenced by: '<S7>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Mask Parameter: HILInitialize_analog_output_cha
   * Referenced by: '<S7>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Mask Parameter: HILSetEncoderCounts_channels
   * Referenced by: '<S18>/HIL Set Encoder Counts'
   */
  { 0U, 1U, 2U, 3U },

  /*  Mask Parameter: HILReadEncoderTimebase_channels
   * Referenced by: '<S7>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U, 3U },

  /*  Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S7>/HIL Write Analog'
   */
  { 0U, 1U },

  /*  Mask Parameter: HILWriteDigital_channels
   * Referenced by: '<S7>/HIL Write Digital'
   */
  { 0U, 1U, 2U, 3U },

  /*  Mask Parameter: HILInitialize_digital_output_ch
   * Referenced by: '<S7>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Mask Parameter: HILInitialize_encoder_channels
   * Referenced by: '<S7>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Mask Parameter: HILInitialize_pwm_channels
   * Referenced by: '<S7>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
  4U,                                  /* Mask Parameter: HILInitialize_quadrature
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  1000U,                               /* Mask Parameter: HILReadEncoderTimebase_samples_
                                        * Referenced by: '<S7>/HIL Read Encoder Timebase'
                                        */
  1,                                   /* Mask Parameter: StopwithMessage_message_icon
                                        * Referenced by: '<S21>/Show Message on Host'
                                        */
  1,                                   /* Mask Parameter: StopwithMessage_message_icon_g
                                        * Referenced by: '<S23>/Show Message on Host'
                                        */
  1,                                   /* Mask Parameter: StopwithMessage_message_icon_k
                                        * Referenced by: '<S27>/Show Message on Host'
                                        */
  1,                                   /* Mask Parameter: StopwithMessage_message_icon_a
                                        * Referenced by: '<S29>/Show Message on Host'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_final_digital_out
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_initial_digital_o
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_input_
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_inpu_m
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_output
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_c
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_outp_i
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_l
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_f
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_outp_g
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_out_g3
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequen
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequ_c
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_params_
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_param_f
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_outpu
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_e
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_j
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_k
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_ou_j0
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_h
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_p
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_count
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_cou_c
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_param
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_par_c
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_other_outpu_m
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_b
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_j
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_c
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_o
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_params_at
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_params__n
                                        * Referenced by: '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S22>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S24>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S30>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Integrator'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S14>/Direction Convention: (Right-Hand) system'
                                        */

  /*  Expression: [1 1 1 1]
   * Referenced by: '<S7>/Enable VoltPAQ-X2,X4'
   */
  { 1.0, 1.0, 1.0, 1.0 },
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S32>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S34>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S35>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S31>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S33>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S37>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S39>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S40>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S36>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S38>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S12>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain'
                                        */

  /*  Expression: sysc.c
   * Referenced by: '<S3>/-sysc.c_x'
   */
  { 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: sysc.b
   * Referenced by: '<S3>/sysc.b_x'
   */
  { 0.0, 0.0, 14.4784, 8.5012 },

  /*  Expression: sysc.a
   * Referenced by: '<S3>/sysc.a_x'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 12.8209, 52.8828, 1.0, 0.0, -7.7744, -4.5648,
    0.0, 1.0, 0.0, 0.0 },

  /*  Expression: sysc.c
   * Referenced by: '<S4>/-sysd.c_x'
   */
  { 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: sysc.b
   * Referenced by: '<S4>/sysd.b_x'
   */
  { 0.0, 0.0, 14.4784, 8.5012 },

  /*  Expression: sysc.a
   * Referenced by: '<S4>/sysd.a_x'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 12.8209, 52.8828, 1.0, 0.0, -7.7744, -4.5648,
    0.0, 1.0, 0.0, 0.0 },
  1,                                   /* Computed Parameter: HILSetEncoderCounts_Active
                                        * Referenced by: '<S18>/HIL Set Encoder Counts'
                                        */
  1,                                   /* Computed Parameter: HILReadEncoderTimebase_Active
                                        * Referenced by: '<S7>/HIL Read Encoder Timebase'
                                        */
  0,                                   /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<S7>/HIL Write Analog'
                                        */
  0                                    /* Computed Parameter: HILWriteDigital_Active
                                        * Referenced by: '<S7>/HIL Write Digital'
                                        */
};
