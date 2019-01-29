  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Experiment_P)
    ;%
      section.nData     = 27;
      section.data(27)  = dumData; %prealloc
      
	  ;% Experiment_P.ALPHA_MAX
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Experiment_P.K_AMP
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Experiment_P.K_CT
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Experiment_P.K_ENC
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% Experiment_P.K_ENC_2DIP
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% Experiment_P.L_CT
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
	  ;% Experiment_P.THETA_MAX
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 18;
	
	  ;% Experiment_P.VMAX_AMP
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 19;
	
	  ;% Experiment_P.VMAX_DAC
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 20;
	
	  ;% Experiment_P.HILInitialize_analog_input_maxi
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 21;
	
	  ;% Experiment_P.HILInitialize_analog_input_mini
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 22;
	
	  ;% Experiment_P.HILInitialize_analog_output_max
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 23;
	
	  ;% Experiment_P.HILInitialize_analog_output_min
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 24;
	
	  ;% Experiment_P.CompareToConstant_const
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 25;
	
	  ;% Experiment_P.HILInitialize_final_analog_outp
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 26;
	
	  ;% Experiment_P.HILInitialize_final_pwm_outputs
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 27;
	
	  ;% Experiment_P.HILInitialize_initial_analog_ou
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 28;
	
	  ;% Experiment_P.HILInitialize_initial_pwm_outpu
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 29;
	
	  ;% Experiment_P.HILInitialize_pwm_frequency
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 30;
	
	  ;% Experiment_P.HILInitialize_pwm_leading_deadb
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 31;
	
	  ;% Experiment_P.HILInitialize_pwm_trailing_dead
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 32;
	
	  ;% Experiment_P.HILInitialize_set_other_outputs
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 33;
	
	  ;% Experiment_P.HILInitialize_set_other_outpu_a
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 34;
	
	  ;% Experiment_P.HILInitialize_set_other_outpu_n
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 35;
	
	  ;% Experiment_P.HILInitialize_set_other_outp_nc
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 36;
	
	  ;% Experiment_P.HILInitialize_watchdog_analog_o
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 37;
	
	  ;% Experiment_P.HILInitialize_watchdog_pwm_outp
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% Experiment_P.HILReadEncoderTimebase_clock
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Experiment_P.HILSetEncoderCounts_counts
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Experiment_P.HILInitialize_hardware_clocks
	  section.data(3).logicalSrcIdx = 29;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Experiment_P.HILInitialize_initial_encoder_c
	  section.data(4).logicalSrcIdx = 30;
	  section.data(4).dtTransOffset = 5;
	
	  ;% Experiment_P.HILInitialize_pwm_alignment
	  section.data(5).logicalSrcIdx = 31;
	  section.data(5).dtTransOffset = 6;
	
	  ;% Experiment_P.HILInitialize_pwm_configuration
	  section.data(6).logicalSrcIdx = 32;
	  section.data(6).dtTransOffset = 7;
	
	  ;% Experiment_P.HILInitialize_pwm_modes
	  section.data(7).logicalSrcIdx = 33;
	  section.data(7).dtTransOffset = 8;
	
	  ;% Experiment_P.HILInitialize_pwm_polarity
	  section.data(8).logicalSrcIdx = 34;
	  section.data(8).dtTransOffset = 9;
	
	  ;% Experiment_P.HILInitialize_watchdog_digital_
	  section.data(9).logicalSrcIdx = 35;
	  section.data(9).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% Experiment_P.HILInitialize_analog_input_chan
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Experiment_P.HILInitialize_analog_output_cha
	  section.data(2).logicalSrcIdx = 37;
	  section.data(2).dtTransOffset = 8;
	
	  ;% Experiment_P.HILSetEncoderCounts_channels
	  section.data(3).logicalSrcIdx = 38;
	  section.data(3).dtTransOffset = 16;
	
	  ;% Experiment_P.HILReadEncoderTimebase_channels
	  section.data(4).logicalSrcIdx = 39;
	  section.data(4).dtTransOffset = 20;
	
	  ;% Experiment_P.HILWriteAnalog_channels
	  section.data(5).logicalSrcIdx = 40;
	  section.data(5).dtTransOffset = 24;
	
	  ;% Experiment_P.HILWriteDigital_channels
	  section.data(6).logicalSrcIdx = 41;
	  section.data(6).dtTransOffset = 26;
	
	  ;% Experiment_P.HILInitialize_digital_output_ch
	  section.data(7).logicalSrcIdx = 42;
	  section.data(7).dtTransOffset = 30;
	
	  ;% Experiment_P.HILInitialize_encoder_channels
	  section.data(8).logicalSrcIdx = 43;
	  section.data(8).dtTransOffset = 38;
	
	  ;% Experiment_P.HILInitialize_pwm_channels
	  section.data(9).logicalSrcIdx = 44;
	  section.data(9).dtTransOffset = 46;
	
	  ;% Experiment_P.HILInitialize_quadrature
	  section.data(10).logicalSrcIdx = 45;
	  section.data(10).dtTransOffset = 54;
	
	  ;% Experiment_P.HILReadEncoderTimebase_samples_
	  section.data(11).logicalSrcIdx = 46;
	  section.data(11).dtTransOffset = 55;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Experiment_P.StopwithMessage_message_icon
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Experiment_P.StopwithMessage_message_icon_g
	  section.data(2).logicalSrcIdx = 48;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Experiment_P.StopwithMessage_message_icon_k
	  section.data(3).logicalSrcIdx = 49;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Experiment_P.StopwithMessage_message_icon_a
	  section.data(4).logicalSrcIdx = 50;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% Experiment_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Experiment_P.HILInitialize_final_digital_out
	  section.data(2).logicalSrcIdx = 52;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Experiment_P.HILInitialize_initial_digital_o
	  section.data(3).logicalSrcIdx = 53;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Experiment_P.HILInitialize_set_analog_input_
	  section.data(4).logicalSrcIdx = 54;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Experiment_P.HILInitialize_set_analog_inpu_m
	  section.data(5).logicalSrcIdx = 55;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Experiment_P.HILInitialize_set_analog_output
	  section.data(6).logicalSrcIdx = 56;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Experiment_P.HILInitialize_set_analog_outp_c
	  section.data(7).logicalSrcIdx = 57;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Experiment_P.HILInitialize_set_analog_outp_i
	  section.data(8).logicalSrcIdx = 58;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Experiment_P.HILInitialize_set_analog_outp_l
	  section.data(9).logicalSrcIdx = 59;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Experiment_P.HILInitialize_set_analog_outp_f
	  section.data(10).logicalSrcIdx = 60;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Experiment_P.HILInitialize_set_analog_outp_g
	  section.data(11).logicalSrcIdx = 61;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Experiment_P.HILInitialize_set_analog_out_g3
	  section.data(12).logicalSrcIdx = 62;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Experiment_P.HILInitialize_set_clock_frequen
	  section.data(13).logicalSrcIdx = 63;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Experiment_P.HILInitialize_set_clock_frequ_c
	  section.data(14).logicalSrcIdx = 64;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Experiment_P.HILInitialize_set_clock_params_
	  section.data(15).logicalSrcIdx = 65;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Experiment_P.HILInitialize_set_clock_param_f
	  section.data(16).logicalSrcIdx = 66;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Experiment_P.HILInitialize_set_digital_outpu
	  section.data(17).logicalSrcIdx = 67;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Experiment_P.HILInitialize_set_digital_out_e
	  section.data(18).logicalSrcIdx = 68;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Experiment_P.HILInitialize_set_digital_out_j
	  section.data(19).logicalSrcIdx = 69;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Experiment_P.HILInitialize_set_digital_out_k
	  section.data(20).logicalSrcIdx = 70;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Experiment_P.HILInitialize_set_digital_ou_j0
	  section.data(21).logicalSrcIdx = 71;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Experiment_P.HILInitialize_set_digital_out_h
	  section.data(22).logicalSrcIdx = 72;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Experiment_P.HILInitialize_set_digital_out_p
	  section.data(23).logicalSrcIdx = 73;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Experiment_P.HILInitialize_set_encoder_count
	  section.data(24).logicalSrcIdx = 74;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Experiment_P.HILInitialize_set_encoder_cou_c
	  section.data(25).logicalSrcIdx = 75;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Experiment_P.HILInitialize_set_encoder_param
	  section.data(26).logicalSrcIdx = 76;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Experiment_P.HILInitialize_set_encoder_par_c
	  section.data(27).logicalSrcIdx = 77;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Experiment_P.HILInitialize_set_other_outpu_m
	  section.data(28).logicalSrcIdx = 78;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Experiment_P.HILInitialize_set_pwm_outputs_a
	  section.data(29).logicalSrcIdx = 79;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Experiment_P.HILInitialize_set_pwm_outputs_b
	  section.data(30).logicalSrcIdx = 80;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Experiment_P.HILInitialize_set_pwm_outputs_j
	  section.data(31).logicalSrcIdx = 81;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Experiment_P.HILInitialize_set_pwm_outputs_c
	  section.data(32).logicalSrcIdx = 82;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Experiment_P.HILInitialize_set_pwm_outputs_o
	  section.data(33).logicalSrcIdx = 83;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Experiment_P.HILInitialize_set_pwm_params_at
	  section.data(34).logicalSrcIdx = 84;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Experiment_P.HILInitialize_set_pwm_params__n
	  section.data(35).logicalSrcIdx = 85;
	  section.data(35).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 28;
      section.data(28)  = dumData; %prealloc
      
	  ;% Experiment_P.Constant_Value
	  section.data(1).logicalSrcIdx = 86;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Experiment_P.Constant_Value_k
	  section.data(2).logicalSrcIdx = 87;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Experiment_P.Constant_Value_m
	  section.data(3).logicalSrcIdx = 88;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Experiment_P.Constant_Value_p
	  section.data(4).logicalSrcIdx = 89;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Experiment_P.Integrator_IC
	  section.data(5).logicalSrcIdx = 90;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Experiment_P.Integrator_IC_e
	  section.data(6).logicalSrcIdx = 91;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Experiment_P.Integrator_IC_b
	  section.data(7).logicalSrcIdx = 92;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Experiment_P.Integrator_IC_o
	  section.data(8).logicalSrcIdx = 93;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Experiment_P.DirectionConventionRightHandsys
	  section.data(9).logicalSrcIdx = 94;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Experiment_P.EnableVoltPAQX2X4_Value
	  section.data(10).logicalSrcIdx = 95;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Experiment_P.Gain_Gain
	  section.data(11).logicalSrcIdx = 96;
	  section.data(11).dtTransOffset = 13;
	
	  ;% Experiment_P.Gain_Gain_j
	  section.data(12).logicalSrcIdx = 97;
	  section.data(12).dtTransOffset = 14;
	
	  ;% Experiment_P.Gain_Gain_l
	  section.data(13).logicalSrcIdx = 98;
	  section.data(13).dtTransOffset = 15;
	
	  ;% Experiment_P.Gain_Gain_m
	  section.data(14).logicalSrcIdx = 99;
	  section.data(14).dtTransOffset = 16;
	
	  ;% Experiment_P.Gain_Gain_g
	  section.data(15).logicalSrcIdx = 100;
	  section.data(15).dtTransOffset = 17;
	
	  ;% Experiment_P.Gain_Gain_jt
	  section.data(16).logicalSrcIdx = 101;
	  section.data(16).dtTransOffset = 18;
	
	  ;% Experiment_P.Gain_Gain_h
	  section.data(17).logicalSrcIdx = 102;
	  section.data(17).dtTransOffset = 19;
	
	  ;% Experiment_P.Gain_Gain_p
	  section.data(18).logicalSrcIdx = 103;
	  section.data(18).dtTransOffset = 20;
	
	  ;% Experiment_P.Gain_Gain_pk
	  section.data(19).logicalSrcIdx = 104;
	  section.data(19).dtTransOffset = 21;
	
	  ;% Experiment_P.Gain_Gain_g4
	  section.data(20).logicalSrcIdx = 105;
	  section.data(20).dtTransOffset = 22;
	
	  ;% Experiment_P.Gain_Gain_n
	  section.data(21).logicalSrcIdx = 106;
	  section.data(21).dtTransOffset = 23;
	
	  ;% Experiment_P.Gain_Gain_m3
	  section.data(22).logicalSrcIdx = 107;
	  section.data(22).dtTransOffset = 24;
	
	  ;% Experiment_P.syscc_x_Gain
	  section.data(23).logicalSrcIdx = 108;
	  section.data(23).dtTransOffset = 25;
	
	  ;% Experiment_P.syscb_x_Gain
	  section.data(24).logicalSrcIdx = 109;
	  section.data(24).dtTransOffset = 33;
	
	  ;% Experiment_P.sysca_x_Gain
	  section.data(25).logicalSrcIdx = 110;
	  section.data(25).dtTransOffset = 37;
	
	  ;% Experiment_P.sysdc_x_Gain
	  section.data(26).logicalSrcIdx = 111;
	  section.data(26).dtTransOffset = 53;
	
	  ;% Experiment_P.sysdb_x_Gain
	  section.data(27).logicalSrcIdx = 112;
	  section.data(27).dtTransOffset = 61;
	
	  ;% Experiment_P.sysda_x_Gain
	  section.data(28).logicalSrcIdx = 113;
	  section.data(28).dtTransOffset = 65;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Experiment_P.HILSetEncoderCounts_Active
	  section.data(1).logicalSrcIdx = 114;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Experiment_P.HILReadEncoderTimebase_Active
	  section.data(2).logicalSrcIdx = 115;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Experiment_P.HILWriteAnalog_Active
	  section.data(3).logicalSrcIdx = 116;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Experiment_P.HILWriteDigital_Active
	  section.data(4).logicalSrcIdx = 117;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Experiment_B)
    ;%
      section.nData     = 55;
      section.data(55)  = dumData; %prealloc
      
	  ;% Experiment_B.HILReadEncoderTimebase_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Experiment_B.HILReadEncoderTimebase_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Experiment_B.HILReadEncoderTimebase_o3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Experiment_B.HILReadEncoderTimebase_o4
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Experiment_B.EncoderCalibrationradcount
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Experiment_B.DIPEncoderCalibrationradcount
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Experiment_B.Integrator
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Experiment_B.Integrator_c
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 10;
	
	  ;% Experiment_B.TmpSignalConversionAtLQRGainXIn
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 11;
	
	  ;% Experiment_B.LQRGainX
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 16;
	
	  ;% Experiment_B.EncoderCalibrationYradcount
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 17;
	
	  ;% Experiment_B.DIPEncoderYCalibrationradcount
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 18;
	
	  ;% Experiment_B.Integrator_e
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 19;
	
	  ;% Experiment_B.Integrator_n
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 23;
	
	  ;% Experiment_B.TmpSignalConversionAtLQRGainYIn
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 24;
	
	  ;% Experiment_B.LQRGainY
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 29;
	
	  ;% Experiment_B.DirectionConventionRightHandsys
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 30;
	
	  ;% Experiment_B.AmplifierSaturationV
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 32;
	
	  ;% Experiment_B.InverseAmplifierGainVV
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 34;
	
	  ;% Experiment_B.DACBSaturationV
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 36;
	
	  ;% Experiment_B.AmplifierGainVV
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 38;
	
	  ;% Experiment_B.Clock
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 40;
	
	  ;% Experiment_B.Gain
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 41;
	
	  ;% Experiment_B.Gain_j
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 42;
	
	  ;% Experiment_B.Gain_l
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 43;
	
	  ;% Experiment_B.Gain_f
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 44;
	
	  ;% Experiment_B.Gain_d
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 45;
	
	  ;% Experiment_B.Gain_p
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 46;
	
	  ;% Experiment_B.Gain_g
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 47;
	
	  ;% Experiment_B.Gain_gf
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 48;
	
	  ;% Experiment_B.Gain_l5
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 49;
	
	  ;% Experiment_B.Gain_dr
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 50;
	
	  ;% Experiment_B.Sum
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 51;
	
	  ;% Experiment_B.Gain_b
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 53;
	
	  ;% Experiment_B.Gain_i
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 55;
	
	  ;% Experiment_B.syscc_x
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 57;
	
	  ;% Experiment_B.Sum1
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 59;
	
	  ;% Experiment_B.KalmanFilterGain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 61;
	
	  ;% Experiment_B.syscb_x
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 65;
	
	  ;% Experiment_B.sysca_x
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 69;
	
	  ;% Experiment_B.Sum_n
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 73;
	
	  ;% Experiment_B.sysdc_x
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 77;
	
	  ;% Experiment_B.Sum1_n
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 79;
	
	  ;% Experiment_B.KalmanFilterGain_a
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 81;
	
	  ;% Experiment_B.sysdb_x
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 85;
	
	  ;% Experiment_B.sysda_x
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 89;
	
	  ;% Experiment_B.Sum_b
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 93;
	
	  ;% Experiment_B.Abs
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 97;
	
	  ;% Experiment_B.CheckMaximumAllowedAngle
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 98;
	
	  ;% Experiment_B.Abs_c
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 99;
	
	  ;% Experiment_B.CheckMaximumAllowedAngle_g
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 100;
	
	  ;% Experiment_B.Abs_cx
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 101;
	
	  ;% Experiment_B.CheckMaximumAllowedAngle_gq
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 102;
	
	  ;% Experiment_B.Abs_i
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 103;
	
	  ;% Experiment_B.CheckMaximumAllowedAngle_j
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 104;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Experiment_B.Compare
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Experiment_B.Compare_f
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Experiment_B.Compare_h
	  section.data(2).logicalSrcIdx = 57;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Experiment_B.Compare_e
	  section.data(3).logicalSrcIdx = 58;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Experiment_B.Compare_i
	  section.data(4).logicalSrcIdx = 59;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
    sectIdxOffset = 3;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Experiment_DW)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% Experiment_DW.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Experiment_DW.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 8;
	
	  ;% Experiment_DW.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 16;
	
	  ;% Experiment_DW.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 24;
	
	  ;% Experiment_DW.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 32;
	
	  ;% Experiment_DW.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 40;
	
	  ;% Experiment_DW.HILInitialize_POSortedFreqs
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 48;
	
	  ;% Experiment_DW.HILInitialize_POValues
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 56;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Experiment_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Experiment_DW.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% Experiment_DW.HILWriteAnalog_PWORK
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Experiment_DW.HILWriteDigital_PWORK
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Experiment_DW.Plots_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Experiment_DW.Alphadeg_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 13;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Experiment_DW.Alpha_Dotdeg_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 14;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Experiment_DW.Integral_Thetadeg_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 15;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Experiment_DW.Thetadeg_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 16;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Experiment_DW.Theta_Dotdeg_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 17;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Experiment_DW.Alphadeg_PWORK_l.LoggedData
	  section.data(9).logicalSrcIdx = 18;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Experiment_DW.Alpha_Dotdeg_PWORK_h.LoggedData
	  section.data(10).logicalSrcIdx = 19;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Experiment_DW.Integral_Thetadeg_PWORK_e.LoggedData
	  section.data(11).logicalSrcIdx = 20;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Experiment_DW.Thetadeg_PWORK_c.LoggedData
	  section.data(12).logicalSrcIdx = 21;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Experiment_DW.Theta_Dotdeg_PWORK_i.LoggedData
	  section.data(13).logicalSrcIdx = 22;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Experiment_DW.VmV_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 23;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Experiment_DW.angleerror_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 24;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Experiment_DW.angleerror1_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 25;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Experiment_DW.angleerror2_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 26;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Experiment_DW.HILSetEncoderCounts_PWORK
	  section.data(18).logicalSrcIdx = 27;
	  section.data(18).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% Experiment_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Experiment_DW.HILInitialize_DOStates
	  section.data(2).logicalSrcIdx = 29;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Experiment_DW.HILInitialize_QuadratureModes
	  section.data(3).logicalSrcIdx = 30;
	  section.data(3).dtTransOffset = 11;
	
	  ;% Experiment_DW.HILInitialize_InitialEICounts
	  section.data(4).logicalSrcIdx = 31;
	  section.data(4).dtTransOffset = 19;
	
	  ;% Experiment_DW.HILInitialize_POModeValues
	  section.data(5).logicalSrcIdx = 32;
	  section.data(5).dtTransOffset = 27;
	
	  ;% Experiment_DW.HILInitialize_POAlignValues
	  section.data(6).logicalSrcIdx = 33;
	  section.data(6).dtTransOffset = 35;
	
	  ;% Experiment_DW.HILInitialize_POPolarityVals
	  section.data(7).logicalSrcIdx = 34;
	  section.data(7).dtTransOffset = 43;
	
	  ;% Experiment_DW.HILReadEncoderTimebase_Buffer
	  section.data(8).logicalSrcIdx = 35;
	  section.data(8).dtTransOffset = 51;
	
	  ;% Experiment_DW.HILSetEncoderCounts_Buffer
	  section.data(9).logicalSrcIdx = 36;
	  section.data(9).dtTransOffset = 55;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Experiment_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Experiment_DW.ResetEncoders_SubsysRanBC
	  section.data(1).logicalSrcIdx = 38;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Experiment_DW.HILInitialize_DOBits
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Experiment_DW.HILWriteDigital_Buffer
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1768262624;
  targMap.checksum1 = 2860920247;
  targMap.checksum2 = 2837659142;
  targMap.checksum3 = 1157651300;

