/**
 *****************************************************************************
 * @file    wm8994_RegisterDefines.h
 * @brief   Register defines for audio codec WM8994
 * @author  Daniel Lohmann
 ****************************************************************************** 
 * 
 */

#ifndef __WM8994_REGISTERDEFINES_H
#define __WM8994_REGISTERDEFINES_H

//Register R0 - Software Reset / FamilyID

#define R0 0x0000
#define SOFTWARE_RESET_REG R0
#define FAMILY_ID_REG R0

#define FAMILY_ID 0x8994

//Register R1 - Power Management (1)

#define R1 0x0001
#define POWER_MANAGEMENT_1_REG R1

#define SPKOUTR_ENA_bp 13
#define SPKOUTL_ENA_bp 12
#define HPOUT2_ENA_bp   11
#define HPOUT1L_ENA_bp  9
#define HPOUT1R_ENA_bp  8
#define MICB2_ENA_bp    5
#define MICB1_ENA_bp    4
#define VMID_SEL_bp     1   
#define BIAS_ENA_bp     0


#define SPKOUTR_ENA_bm  (1<<SPKOUTR_ENA_bp)
#define SPKOUTL_ENA_bm  (1<<SPKOUTL_ENA_bp)
#define HPOUT2_ENA_bm   (1<<HPOUT2_ENA_bp)
#define HPOUT1L_ENA_bm  (1<<HPOUT1L_ENA_bp)
#define HPOUT1R_ENA_bm  (1<<HPOUT1R_ENA_bp)
#define MICB2_ENA_bm    (1<<MICB2_ENA_bp)
#define MICB1_ENA_bm    (1<<MICB1_ENA_bp)
#define VMID_SEL_bm     (3<<VMID_SEL_bp)
#define BIAS_ENA_bm     (1<<BIAS_ENA_bp)

#define VMID_SEL_DISABKE    0
#define VMID_SEL_2X40K      1
#define VMID_SEL_2X240K     2

//Register R2 - Power Management (2)

#define R2 0x0002
#define POWER_MANAGEMENT_2_REG R2

#define TSHUT_ENA_bp        14
#define TSHUT_OPDIS_bp      13  
#define OPCLK_ENA_bp        11
#define MIXINL_ENA_bp       9
#define MIXINR_ENA_bp       8
#define IN2L_ENA_bp         7
#define IN1L_ENA_bp         6   
#define IN2R_ENA_bp         5
#define IN1R_ENA_bp         4

#define TSHUT_ENA_bm        (1<<TSHUT_ENA_bp)
#define TSHUT_OPDIS_bm      (1<<TSHUT_OPDIS_bp)
#define OPCLK_ENA_bm        (1<<OPCLK_ENA_bp)
#define MIXINL_ENA_bm       (1<<MIXINL_ENA_bp)
#define MIXINR_ENA_bm       (1<<MIXINR_ENA_bp)
#define IN2L_ENA_bm         (1<<IN2L_ENA_bp)
#define IN1L_ENA_bm         (1<<IN1L_ENA_bp)
#define IN2R_ENA_bm         (1<<IN2R_ENA_bp)
#define IN1R_ENA_bm         (1<<IN1R_ENA_bp)

//Register R3 - Power Mangement (3)

#define R3 0x0003
#define POWER_MANAGEMENT_3_REG R3

#define LINEOUT1N_ENA_bp    13
#define LINEOUT1P_ENA_bp    12
#define LINEOUT2N_ENA_bp    11
#define LINEOUT2P_ENA_bp    10
#define SPKRVOL_ENA_bp      9
#define SPKLVOL_ENA_bp      8
#define MIXOUTLVOL_ENA_bp   7
#define MIXOUTRVOL_ENA_bp   6
#define MIXOUTL_ENA_bp      5
#define MIXOUTR_ENA_bp      4


#define LINEOUT1N_ENA_bm    (1<<LINEOUT1N_ENA_bp)
#define LINEOUT1P_ENA_bm    (1<<LINEOUT1P_ENA_bp)
#define LINEOUT2N_ENA_bm    (1<<LINEOUT2N_ENA_bp)
#define LINEOUT2P_ENA_bm    (1<<LINEOUT2P_ENA_bp)
#define SPKRVOL_ENA_bm      (1<<SPKRVOL_ENA_bp)
#define SPKLVOL_ENA_bm      (1<<SPKRVOL_ENA_bp)
#define MIXOUTLVOL_ENA_bm   (1<<MIXOUTLVOL_ENA_bp)
#define MIXOUTRVOL_ENA_bm   (1<<MIXOUTRVOL_ENA_bp)
#define MIXOUTL_ENA_bm      (1<<MIXOUTL_ENA_bp)
#define MIXOUTR_ENA_bm      (1<<MIXOUTR_ENA_bp)

//Register R4 - Power Mangement (4)

#define R4 0x0004
#define POWER_MANAGEMENT_4_REG R4

#define AIF2ADCL_ENA_bp     13
#define AIF2ADCR_ENA_bp     12
#define AIF1ADC2L_ENA_bp    11
#define AIF1ADC2R_ENA_bp    10
#define AIF1ADC1L_ENA_bp    9
#define AIF1ADC1R_ENA_bp    8
#define DMIC2L_ENA_bp       5
#define DMIC2R_ENA_bp       4
#define DMIC1L_ENA_bp       3
#define DMIC1R_ENA_bp       2
#define ADCL_ENA_bp         1
#define ADCR_ENA_bp         0


#define AIF2ADCL_ENA_bm     (1<<AIF2ADCL_ENA_bp)
#define AIF2ADCR_ENA_bm     (1<<AIF2ADCR_ENA_bp)
#define AIF1ADC2L_ENA_bm    (1<<AIF1ADC2L_ENA_bp)
#define AIF1ADC2R_ENA_bm    (1<<AIF1ADC2R_ENA_bp)
#define AIF1ADC1L_ENA_bm    (1<<AIF1ADC1L_ENA_bp)
#define AIF1ADC1R_ENA_bm    (1<<AIF1ADC1R_ENA_bp)
#define DMIC2L_ENA_bm       (1<<DMIC2L_ENA_bp)
#define DMIC2R_ENA_bm       (1<<DMIC2R_ENA_bp)
#define DMIC1L_ENA_bm       (1<<DMIC1L_ENA_bp)
#define DMIC1R_ENA_bm       (1<<DMIC1R_ENA_bp)
#define ADCL_ENA_bm         (1<<ADCL_ENA_bp)
#define ADCR_ENA_bm         (1<<ADCR_ENA_bp)

//Register R5 - Power Mangement (5)

#define R5 0x0005
#define POWER_MANAGEMENT_5_REG R5

#define AIF2DACL_ENA_bp     13
#define AIF2DACR_ENA_bp     12
#define AIF1DAC2L_ENA_bp    11
#define AIF1DAC2R_ENA_bp    10
#define AIF1DAC1L_ENA_bp    9
#define AIF1DAC1R_ENA_bp    8
#define DAC2L_ENA_bp        3
#define DAC2R_ENA_bp        2
#define DAC1L_ENA_bp        1
#define DAC1R_ENA_bp        0


#define AIF2DACL_ENA_bm     (1<<AIF2DACL_ENA_bp)
#define AIF2DACR_ENA_bm     (1<<AIF2DACR_ENA_bp)
#define AIF1DAC2L_ENA_bm    (1<<AIF1DAC2L_ENA_bp)
#define AIF1DAC2R_ENA_bm    (1<<AIF1DAC2R_ENA_bp)
#define AIF1DAC1L_ENA_bm    (1<<AIF1DAC1L_ENA_bp)
#define AIF1DAC1R_ENA_bm    (1<<AIF1DAC1R_ENA_bp)
#define DAC2L_ENA_bm        (1<<DAC2L_ENA_bp)
#define DAC2R_ENA_bm        (1<<DAC2R_ENA_bp)
#define DAC1L_ENA_bm        (1<<DAC1L_ENA_bp)
#define DAC1R_ENA_bm        (1<<DAC1R_ENA_bp)

//Register R6 - Power Mangement (6)

#define R6 0x0006
#define POWER_MANAGEMENT_6_REG R6

#define AIF3_TRI_bp             5
#define AIF3_ADCDAT_SRC_bp      3
#define AIF2_ADCDAT_SRC_bp      2
#define AIF2_DACDAT_SRC_bp      1
#define AIF1_DACDAT_SRC_bp      0

#define AIF3_TRI_bm             (1<<AIF3_TRI_bp)
#define AIF3_ADCDAT_SRC_bm      (3<<AIF3_ADCDAT_SRC_bp)
#define AIF2_ADCDAT_SRC_bm      (1<<AIF2_ADCDAT_SRC_bp)
#define AIF2_DACDAR_SRC_bm      (1<<AIF2_DACDAT_SRC_bp)
#define AIF1_DACDAT_SRC_bms     (1<<AIF1_DACDAT_SRC_bp)

#define AIF3_ADCDAT_SRC_AIF1_ADCDAT1        0
#define AIF3_ADCDAT_SRC_AIF2_ADCDAT2        1
#define AIF3_ADCDAR_SRC_GPIO5_DACDAT2       2

//Register R21 - Input Mixer (!)

#define R21 0x0015
#define INPUT_MIXER_1_REG R21

#define IN1RP_MIXINR_BOOST_bp   8
#define IN1LP_MIXINL_BOOST_bp   7   
#define INPUTS_CLAMP_bp         6

#define IN1RP_MIXINR_BOOST_bm   (1<<IN1RP_MIXINR_BOOST_bp)
#define IN1LP_MIXINL_BOOST_bm   (1<<IN1LP_MIXINL_BOOST_bp)
#define INPUTS_CLAMP_bm         (1<<INPUTS_CLAMP_bp)

//Register R24 - Left Line Input 1&2 Volume

#define R24 0x0018
#define LEFT_LINE_INPUT_1_2_VOLUME_REG R24

#define IN1L_VU_bp      8
#define IN1L_MUTE_bp    7
#define IN1L_ZC_bp      6
#define IN1L_VOL_bp     0

#define IN1L_VU_bm      (1<<IN1L_VU_bp)
#define IN1L_MUTE_bm    (1<<IN1L_MUTE_bp)
#define IN1L_ZC_bm      (1<<IN1L_ZC_bp)
#define IN1L_VOL_bm     (0x1F<<IN1L_VOL_bp)

//Register R25 - Left Line Input 3&4 Volume

#define R25 0x0019
#define LEFT_LINE_INPUT_3_4_VOLUME_REG R25

#define IN2L_VU_bp      8
#define IN2L_MUTE_bp    7
#define IN2L_ZC_bp      6
#define IN2L_VOL_bp     0

#define IN2L_VU_bm      (1<<IN2L_VU_bp)
#define IN2L_MUTE_bm    (1<<IN2L_MUTE_bp)
#define IN2L_ZC_bm      (1<<IN2L_ZC_bp)
#define IN2L_VOL_bm     (0x1F<<IN2L_VOL_bp)

//Register R26 - Right Line Input 1&2 Volume

#define R26 0x001A
#define RIGHT_LINE_INPUT_1_2_VOLUME_REG R26

#define IN1R_VU_bp      8
#define IN1R_MUTE_bp    7
#define IN1R_ZC_bp      6
#define IN1R_VOL_bp     0

#define IN1R_VU_bm      (1<<IN1R_VU_bp)
#define IN1R_MUTE_bm    (1<<IN1R_MUTE_bp)
#define IN1R_ZC_bm      (1<<IN1R_ZC_bp)
#define IN1R_VOL_bm     (0x1F<<IN1R_VOL_bp)

//Register R27 - Right Line Input 3&4 Volume

#define R27 0x001B
#define RIGHT_LINE_INPUT_3_4_VOLUME_REG R27

#define IN2R_VU_bp      8
#define IN2R_MUTE_bp    7
#define IN2R_ZC_bp      6
#define IN2R_VOL_bp     0

#define IN2R_VU_bm      (1<<IN2R_VU_bp)
#define IN2R_MUTE_bm    (1<<IN2R_MUTE_bp)
#define IN2R_ZC_bm      (1<<IN12R_ZC_bp)
#define IN2R_VOL_bm     (0x1F<<IN2R_VOL_bp)

//Register R28 - Left Ouput Volume

#define R28 0x001C
#define LEFT_OUTPUT_VOLUME_REG R28

#define HPOUT1L_VU_bp       8
#define HPOUT1L_ZC_bp       7
#define HPOUT1L_MUTE_bp     6
#define HPOUT1L_VOL_bp      0

#define HPOUT1L_VU_bm       (1<<HPOUT1L_VU_bp)
#define HPOUT1L_ZC_bm       (1<<HPOUT1L_ZC_bp)
#define HPOUT1L_MUTE_bm     (1<<HPOUT1L_MUTE_bp)
#define HPOUT1L_VOL_bm      (0x3F<<HPOUT1L_VOL_bp)

//Register R29 - Right Ouput Volume

#define R29 0x001D
#define RIGHT_OUTPUT_VOLUME_REG R29

#define HPOUT1R_VU_bp       8
#define HPOUT1R_ZC_bp       7
#define HPOUT1R_MUTE_bp     6
#define HPOUT1R_VOL_bp      0

#define HPOUT1R_VU_bm       (1<<HPOUT1R_VU_bp)
#define HPOUT1R_ZC_bm       (1<<HPOUT1R_ZC_bp)
#define HPOUT1R_MUTE_bm     (1<<HPOUT1R_MUTE_bp)
#define HPOUT1R_VOL_bm      (0x3F<<HPOUT1R_VOL_bp)

//Register R30  - Line Outputs Volume

#define R30 0x001E
#define LINE_OUTPUTS_VOLUME_REG R30

#define LINEOUT1N_MUTE_bp   6
#define LINEOUT1P_MUTE_bp   5
#define LINEOUT1_VOL_bp     4
#define LINEOUT2N_MUTE_bp   2
#define LINEOUT2P_MUTE_bp   1
#define LINEOUT2_VOL_bp     0

#define LINEOUT1N_MUTE_bm   (1<<LINEOUT1N_MUTE_bp)
#define LINEOUT1P_MUTE_bm   (1<<LINEOUT1P_MUTE_bp)
#define LINEOUT1_VOL_bm     (1<<LINEOUT1_VOL_bp)
#define LINEOUT2N_MUTE_bm   (1<<LINEOUT2N_MUTE_bp)
#define LINEOUT2P_MUTE_bm   (1<<LINEOUT2P_MUTE_bp)
#define LINEOUT2_VOL_bm     (1<<LINEOUT2_VOL_bp)


//Register R31 - HPOUT2 Volume

#define R31 0x001F
#define HPOUT2_VOLUME_REG R31

#define HPOUT2_MUTE_bp  5
#define HPOUT2_VOL_bp   4

#define HPOUT2_MUTE_bm  (1<<HPOUT2_MUTE_bp)
#define HPOUT2_VOL_bm   (1<<HPOUT2_VOL_bp)

//Register R32 - Left OPGA Volume

#define R32 0x0020
#define LEFT_OPGA_VOLUME_REG R32

#define MIXOUTL_VU_bp       8
#define MIXOUTL_ZC_bp       7
#define MIXOUTL_MUTE_N_bp   6
#define MIXOUTL_VOL_bp      0

#define MIXOUTL_VU_bm       (1<<MIXOUTL_VU_bp)
#define MIXOUTL_ZC_bm       (1<<MIXOUTL_ZC_bp)
#define MIXOUTL_MUTE_N_bm   (1<<MIXOUTL_MUTE_N_bp)
#define MIXOUTL_VOL_bm      (1<<MIXOUTL_VOL_bp)

//Register R33 - Right OPGA Volume

#define R33 0x0021
#define RIGHT_OPGA_VOLUME_REG R33

#define MIXOUTR_VU_bp       8
#define MIXOUTR_ZC_bp       7
#define MIXOUTR_MUTE_N_bp   6
#define MIXOUTR_VOL_bp      0

#define MIXOUTR_VU_bm       (1<<MIXOUTR_VU_bp)
#define MIXOUTR_ZC_bm       (1<<MIXOUTR_ZC_bp)
#define MIXOUTR_MUTE_N_bm   (1<<MIXOUTR_MUTE_N_bp)
#define MIXOUTR_VOL_bm      (1<<MIXOUTR_VOL_bp)

//Register R34 - SPKMIXL Attenuation

#define R34 0x0022
#define SPKMIXL_ATTENUATION_REG R34

#define SPKAB_REF_SEL_bp        8
#define DAC2L_SPKMIXL_VOL_bp    6
#define MIXINL_SPKMIXL_VOL_bp   5
#define IN1LP_SPKMIXL_VOL_bp    4
#define MIXOUTL_SPKMIXL_VOL_bp  3
#define DAC1L_SPKMIXL_VOL_bp    2
#define SPKMIXL_VOL_bp          0

#define SPKAB_REF_SEL_bm        (1<<SPKAB_REF_SEL_bp)
#define DAC2L_SPKMIXL_VOL_bm    (1<<DAC2L_SPKMIXL_VOL_bp)
#define MIXINL_SPKMIXL_VOL_bm   (1<<MIXINL_SPKMIXL_VOL_bp)
#define IN1LP_SPKMIXL_VOL_bm    (1<<IN1LP_SPKMIXL_VOL_bp)
#define MIXOUTL_SPKMIXL_VOL_bm  (1<<MIXOUTL_SPKMIXL_VOL_bp)
#define DAC1L_SPKMIXL_VOL_bm    (1<<DAC1L_SPKMIXL_VOL_bp)
#define SPKMIXL_VOL_bm          (3<<SPKMIXL_VOL_bp)

#define SPLMIXL_VOL_0DB     0
#define SPLMIXL_VOL_6DB     1
#define SPLMIXL_VOL_12DB    2
#define SPLMIXL_VOL_MUTE    3

//Register R35 - SPKMIXR Attenuation

#define R35 0x0023
#define SPKMIXR_ATTENUATION_REG R35

#define SPKOUT_CLASSAB_bp       8
#define DAC2R_SPKMIXR_VOL_bp    6
#define MIXINR_SPKMIXR_VOL_bp   5
#define IN1RP_SPKMIXR_VOL_bp    4
#define MIXOUTR_SPKMIXR_VOL_bp  3
#define DAC1R_SPKMIXR_VOL_bp    2
#define SPKMIXR_VOL_bp          0

#define SPKOUT_CLASSAB_bm       (1<<SPKOUT_CLASSAB_bp)
#define DAC2R_SPKMIXR_VOL_bm    (1<<DAC2R_SPKMIXR_VOL_bp)
#define MIXINR_SPKMIXR_VOL_bm   (1<<MIXINR_SPKMIXR_VOL_bp)
#define IN1RP_SPKMIXR_VOL_bm    (1<<IN1RP_SPKMIXR_VOL_bp)
#define MIXOUTR_SPKMIXR_VOL_bm  (1<<MIXOUTR_SPKMIXR_VOL_bp)
#define DAC1R_SPKMIXR_VOL_bm    (1<<DAC1R_SPKMIXR_VOL_bp)
#define SPKMIXR_VOL_bm          (3<<SPKMIXR_VOL_bp)

#define SPLMIXR_VOL_0DB     0
#define SPLMIXR_VOL_6DB     1
#define SPLMIXR_VOL_12DB    2
#define SPLMIXR_VOL_MUTE    3

//Register R36 - SPKOUT Mixers

#define R36 0x0024
#define SPKOUT_MIXERS_REG R36

#define IN2LRP_TO_SPKOUTL_bp    5
#define SPKMIXL_TO_SPKOUTL_bp   4
#define SPKMIXR_TO_SPKOUTL_bp   3
#define IN2LRP_TO_SPKOUTR_bp    2
#define SPKMIXL_TO_SPKOUTR_bp   1
#define SPKMIXR_TO_SPKOUTR_bp   0

#define IN2LRP_TO_SPKOUTL_bm    (1<<IN2LRP_TO_SPKOUTL_bp)
#define SPKMIXL_TO_SPKOUTL_bm   (1<<SPKMIXL_TO_SPKOUTL_bp)
#define SPKMIXR_TO_SPKOUTL_bm   (1<<SPKMIXR_TO_SPKOUTL_bp)
#define IN2LRP_TO_SPKOUTR_bm    (1<<IN2LRP_TO_SPKOUTR_bp)
#define SPKMIXL_TO_SPKOUTR_bm   (1<<SPKMIXL_TO_SPKOUTR_bp)
#define SPKMIXR_TO_SPKOUTR_bm   (1<<SPKMIXR_TO_SPKOUTR_bp)

//Register R37 - ClassD

#define R37 0x0025
#define CLASSD_REG R37

#define SPKOUTL_BOOST_bp    3 
#define SPKOUTR_BOOST_bp    0

#define SPKOUTL_BOOST_bm    (7<<SPKOUTL_BOOST_bp)
#define SPKOUTR_BOOST_bm    (7<<SPKOUTR_BOOST_bp)

#define SPKOUT_BOOST_0DB        0
#define SPKOUT_BOOST_1_5DB      1
#define SPKOUT_BOOST_3DB        2
#define SPKOUT_BOOST_4_5DB      3
#define SPKOUT_BOOST_6DB        4
#define SPKOUT_BOOST_7_5DB      5
#define SPKOUT_BOOST_9DB        6
#define SPKOUT_BOOST_12DB       7

//Register R38 - Speaker Volume Left 

#define R38 0x0026
#define SPEAKER_VOLUME_LEFT_REG R38

#define SPKOUTL_VU_bp       8
#define SPKOUTL_ZC_bp       7
#define SPKOUTL_MUTE_bp     6
#define SPKOUTL_VOL_bp      0

#define SPKOUTL_VU_bm       (1<<SPKOUTL_VU_bp)
#define SPKOUTL_ZC_bm       (1<<SPKOUTL_ZC_bp)
#define SPKOUTL_MUTE_bm     (1<<SPKOUTL_MUTE_bp)
#define SPKOUTL_VOL_bm      (0x3F<<SPKOUTL_VOL_bp)

//Register R39 - Speaker Volume Right

#define R39 0x0027
#define SPEAKER_VOLUME_RIGHT_REG R39

#define SPKOUTR_VU_bp       8
#define SPKOUTR_ZC_bp       7
#define SPKOUTR_MUTE_bp     6
#define SPKOUTR_VOL_bp      0

#define SPKOUTR_VU_bm       (1<<SPKOUTR_VU_bp)
#define SPKOUTR_ZC_bm       (1<<SPKOUTR_ZC_bp)
#define SPKOUTR_MUTE_bm     (1<<SPKOUTR_MUTE_bp)
#define SPKOUTR_VOL_bm      (0x3F<<SPKOUTR_VOL_bp)

//Register R40 - Input Mixer (2)

#define R40 0x0028
#define INPUT_MIXER_2_REG R40

#define IN2LP_TO_IN2L_bp    7
#define IN2LN_TO_IN2L_bp    6
#define IN1LP_TO_IN1L_bp    5
#define IN1LN_TO_IN1L_bp    4
#define IN2RP_TO_IN2R_bp    3
#define IN2RN_TO_IN2R_bp    2
#define IN1RP_TO_IN1R_bp    1
#define IN1RN_TO_IN1R_bp    0

#define IN2LP_TO_IN2L_bm    (1<<IN2LP_TO_IN2L_bp)
#define IN2LN_TO_IN2L_bm    (1<<IN2LN_TO_IN2L_bp)
#define IN1LP_TO_IN1L_bm    (1<<IN1LP_TO_IN1L_bp
#define IN1LN_TO_IN1L_bm    (1<<IN1LN_TO_IN1L_bp)
#define IN2RP_TO_IN2R_bm    (1<<IN2RP_TO_IN2R_bp)
#define IN2RN_TO_IN2R_bm    (1<<IN2RN_TO_IN2R_bp)
#define IN1RP_TO_IN1R_bm    (1<<IN1RP_TO_IN1R_bp)
#define IN1RN_TO_IN1R_bm    (1<<IN1RN_TO_IN1R_bp)

//Register R41 - Input Mixer (3)

#define R41 0x0029
#define INPUT_MIXER_3_REG R41

#define IN2L_TO_MIXINL_bp       8
#define IN2L_MIXINL_VOL_bp      7
#define IN1L_TO_MIXINL_bp       5
#define IN1L_MIXINL_VOL_bp      4
#define MIXOUTL_MIXINL_VOL_bp   0

#define IN2L_TO_MIXINL_bm       (1<<IN2L_TO_MIXINL_bp)
#define IN2L_MIXINL_VOL_bm      (1<<IN2L_MIXNL_VOL_bp)
#define IN1L_TO_MIXINL_bm       (1<<IN1L_TO_MIXINL_bp)
#define IN1L_MIXINL_VOL_bm      (1<<IN1L_MIXINL_VOL_bp)
#define MIXOUTL_MIXINL_VOL_bm   (7<<MIXOUTL_MIXINL_VOL_bp)

//Register R42 - Input Mixer (4)

#define R42 0x002A
#define INPUT_MIXER_4_REG R42

#define IN2R_TO_MIXINR_bp       8
#define IN2R_MIXINR_VOL_bp      7
#define IN1R_TO_MIXINR_bp       5
#define IN1R_MIXINR_VOL_bp      4
#define MIXOUTR_MIXINR_VOL_bp   0

#define IN2R_TO_MIXINR_bm       (1<<IN2R_TO_MIXINR_bp)
#define IN2R_MIXINR_VOL_bm      (1<<IN2R_MIXNR_VOL_bp)
#define IN1R_TO_MIXINR_bm       (1<<IN1R_TO_MIXINR_bp)
#define IN1R_MIXINR_VOL_bm      (1<<IN1R_MIXINR_VOL_bp)
#define MIXOUTR_MIXINR_VOL_bm   (7<<MIXOUTR_MIXINR_VOL_bp)

//Register R43 - Input Mixer (5)

#define R43 0x002B
#define INPUT_MIXER_5_REG R43

#define IN1LP_MIXINL_VOL_bp     6 
#define IN2LRP_MIXINL_VOL_bp    0

#define IN1LP_MIXINL_VOL_bm     (7<<IN1LP_MIXINL_VOL_bp)
#define IN2LRP_MIXINL_VOL_bm    (7<<IN2LRP_MIXINL_VOL_bp)

//Register R44 - Input Mixer (6)

#define R44 0x002C
#define INPUT_MIXER_6_REG R44

#define IN1RP_MIXINR_VOL_bp     6 
#define IN2LRP_MIXINR_VOL_bp    0

#define IN1RP_MIXINR_VOL_bm     (7<<IN1RP_MIXINR_VOL_bp)
#define IN2LRP_MIXINR_VOL_bm    (7<<IN2LRP_MIXINR_VOL_bp)

//Register R45 - Output Mixer (1)

#define R45 0x002D
#define OUTPUT_MIXER_1_REG R45

#define DAC1L_TO_HPOUT1L_bp     8
#define MIXINR_TO_MIXOUTL_bp    7
#define MIXINL_TO_MIXOUTL_bp    6
#define IN2RN_TO_MIXOUTL_bp     5
#define IN2LN_TO_MIXOUTL_bp     4
#define IN1R_TO_MIXOUTL_bp      3
#define IN1L_TO_MIXOUTL_bp      2
#define IN2LP_TO_MIXOUTL_bp     1
#define DAC1L_TO_MIXOUTL_bp     0

#define DAC1L_TO_HPOUT1L_bm     (1<<DAC1L_TO_HPOUT1L_bp)
#define MIXINR_TO_MIXOUTL_bm    (1<<MIXINR_TO_MIXOUTL_bp)
#define MIXINL_TO_MIXOUTL_bm    (1<<MIXINL_TO_MIXOUTL_bp)
#define IN2RN_TO_MIXOUTL_bm     (1<<IN2RN_TO_MIXOUTL_bp)
#define IN2LN_TO_MIXOUTL_bm     (1<<IN2LN_TO_MIXOUTL_bp)
#define IN1R_TO_MIXOUTL_bm      (1<<IN1R_TO_MIXOUTL_bp)
#define IN1L_TO_MIXOUTL_bm      (1<<IN1L_TO_MIXOUTL_bp)
#define IN2LP_TO_MIXOUTL_bm     (1<<IN2LP_TO_MIXOUTL_bp)
#define DAC1L_TO_MIXOUTL_bm     (1<<DAC1L_TO_MIXOUTL_bp)

//Register R46 - Output Mixer (2)

#define R46 0x002E
#define OUTPUT_MIXER_2_REG R46

#define DAC1R_TO_HPOUT1R_bp     8
#define MIXINL_TO_MIXOUTR_bp    7
#define MIXINR_TO_MIXOUTR_bp    6
#define IN2LN_TO_MIXOUTR_bp     5
#define IN2RN_TO_MIXOUTR_bp     4
#define IN1L_TO_MIXOUTR_bp      3
#define IN1R_TO_MIXOUTR_bp      2
#define IN2RP_TO_MIXOUTR_bp     1
#define DAC1R_TO_MIXOUTR_bp     0

#define DAC1R_TO_HPOUT1R_bm     (1<<DAC1R_TO_HPOUT1R_bp)
#define MIXINL_TO_MIXOUTR_bm    (1<<MIXINL_TO_MIXOUTR_bp)
#define MIXINR_TO_MIXOUTR_bm    (1<<MIXINR_TO_MIXOUTR_bp)
#define IN2LN_TO_MIXOUTR_bm     (1<<IN2LN_TO_MIXOUTR_bp)
#define IN2RN_TO_MIXOUTR_bm     (1<<IN2RN_TO_MIXOUTR_bp)
#define IN1L_TO_MIXOUTR_bm      (1<<IN1L_TO_MIXOUTR_bp)
#define IN1R_TO_MIXOUTR_bm      (1<<IN1R_TO_MIXOUTR_bp)
#define IN2RP_TO_MIXOUTR_bm     (1<<IN2RP_TO_MIXOUTR_bp)
#define DAC1R_TO_MIXOUTR_bm     (1<<DAC1R_TO_MIXOUTR_bp)

//Register R47 - Output Mixer (3)

#define R47 0x002F
#define OUTPUT_MIXER_3_REG R47

#define IN2LP_MIXOUTL_VOL_bp    9
#define IN2LN_MIXOUTL_VOL_bp    6
#define IN1R_MIXOUTL_VOL_bp     3
#define IN1L_MIXOUTL_VOL_bp     0

#define IN2LP_MIXOUTL_VOL_bm    (7<<IN2LP_MIXOUTL_VOL_bp)
#define IN2LN_MIXOUTL_VOL_bm    (7<<IN2LN_MIXOUTL_VOL_bp)
#define IN1R_MIXOUTL_VOL_bm     (7<<IN1R_MIXOUTL_VOL_bp)
#define IN1L_MIXOUTL_VOL_bm     (7<<IN1L_MIXOUTL_VOL_bp)

//Register R48 - Output Mixer (4)

#define R48 0x0030
#define OUTPUT_MIXER_4_R48

#define IN2RP_MIXOUTR_VOL_bp    9
#define IN2RN_MIXOUTR_VOL_bp    6
#define IN1R_MIXOUTR_VOL_bp     3
#define IN1L_MIXOUTR_VOL_bp     0

#define IN2RP_MIXOUTR_VOL_bm    (7<<IN2RP_MIXOUTR_VOL_bp)
#define IN2RN_MIXOUTR_VOL_bm    (7<<IN2RN_MIXOUTR_VOL_bp)
#define IN1R_MIXOUTR_VOL_bm     (7<<IN1R_MIXOUTR_VOL_bp)
#define IN1L_MIXOUTR_VOL_bm     (7<<IN1L_MIXOUTR_VOL_bp)

//Register R49 - Output Mixer (5)

#define R49 0x0031
#define OUTPUT_MIXER_5_REG R49

#define DAC1L_MIXOUTL_VOL_bp    9
#define IN2RN_MIXOUTL_VOL_bp    6
#define MIXINR_MIXOUTL_VOL_bp   3
#define MIXINL_MIXOUTL_VOL_bp   0

#define DAC1L_MIXOUTL_VOL_bm    (7<<DAC1L_MIXOUTL_VOL_bp)
#define IN2RN_MIXOUTL_VOL_bm    (7<<IN2RN_MIXOUTL_VOL_bp)
#define MIXINR_MIXOUTL_VOL_bm   (7<<MIXINR_MIXOUTL_VOL_bp)
#define MIXINL_MIXOUTL_VOL_bm   (7<<MIXINL_MIXOUTL_VOL_bp)

//Register R50 - Output Mixer (6)

#define R50 0x0032
#define OUTPUT_MIXER_6_REG R50

#define DAC1R_MIXOUTR_VOL_bp    9
#define IN2LN_MIXOUTR_VOL_bp    6
#define MIXINL_MIXOUTR_VOL_bp   3
#define MIXINR_MIXOUTR_VOL_bp   0

#define DAC1R_MIXOUTR_VOL_bm    (7<<DAC1R_MIXOUTR_VOL_bp)
#define IN2LN_MIXOUTR_VOL_bm    (7<<IN2LN_MIXOUTR_VOL_bp)
#define MIXINL_MIXOUTR_VOL_bm   (7<<MIXINL_MIXOUTR_VOL_bp)
#define MIXINR_MIXOUTR_VOL_bm   (7<<MIXINR_MIXOUTR_VOL_bp)

//Register R51 - HPOUT2 Mixer

#define R51 0x0033
#define HPOUT2_MIXER_REG R51

#define IN2LRP_TO_HPOUT2_bp     5
#define MIXOUTLVOL_TO_HPOUT2_bp 4
#define MIXOUTRVOL_TO_HPOUT2_bp 3

#define IN2LRP_TO_HPOUT2_bm     (1<<IN2LRP_TO_HPOUT2_bp)
#define MIXOUTLVOL_TO_HPOUT2_bm (1<<MIXOUTLVOL_TO_HPOUT2_bp)
#define MIXOUTRVOL_TO_HPOUT2_bm (1<<MIXOUTRVOL_TO_HPOUT2_bp)

//Register R52 - Line Mixer (1)

#define R52 0x0034
#define LINE_MIXER_1_REG R52

#define MIXOUTL_TO_LINEOUT1N_bp     6
#define MIXOUTR_TO_LINEOUT1N_bp     5
#define LINEOUT1_MODE_bp            4
#define IN1R_TO_LINEOUT1P_bp        2
#define IN1L_TO_LINEOUT1P_bp        1
#define MIXOUTL_TO_LINEOUTP_bp      0

#define MIXOUTL_TO_LINEOUT1N_bm     (1<<MIXOUTL_TO_LINEOUT1N_bp)
#define MIXOUTR_TO_LINEOUT1N_bm     (1<<MIXOUTR_TO_LINEOUT1N_bp)
#define LINEOUT1_MODE_bm            (1<<LINEOUT1_MODE_bp)
#define IN1R_TO_LINEOUT1P_bm        (1<<IN1R_TO_LINEOUT1P_bp)
#define IN1L_TO_LINEOUT1P_bm        (1<<IN1L_TO_LINEOUT1P_bp)
#define MIXOUTL_TO_LINEOUTP_bm      (1<<MIXOUTL_TO_LINEOUTP_bp)

//Register R53 - Line Mixer (2)

#define R53 0x0035
#define LINE_MIXER_2_REG R53

#define MIXOUTR_TO_LINEOUT2N_bp     6
#define MIXOUTL_TO_LINEOUT2N_bp     5
#define LINEOUT2_MODE_bp            4
#define IN1L_TO_LINEOUT2P_bp        2
#define IN1R_TO_LINEOUT2P_bp        1
#define MIXOUTR_TO_LINEOUT2P_bp     0

#define MIXOUTR_TO_LINEOUT2N_bm     (1<<MIXOUTR_TO_LINEOUT2N_bp)
#define MIXOUTL_TO_LINEOUT2N_bm     (1<<MIXOUTL_TO_LINEOUT2N_bp)
#define LINEOUT2_MODE_bm            (1<<LINEOUT2_MODE_bp)
#define IN1L_TO_LINEOUT2P_bm        (1<<IN1L_TO_LINEOUT2P_bp)
#define IN1R_TO_LINEOUT2P_bm        (1<<IN1R_TO_LINEOUT2P_bp)
#define MIXOUTR_TO_LINEOUT2P_bm     (1<<MIXOUTR_TO_LINEOUT2P_bp)

//Register R54 - Speaker Mixer

#define R54 0x0036
#define SPEAKER_MIXER_REG R54

#define DAC2L_TO_SPKMIXL_bp     9
#define DAC2R_TO_SPKMIXR_bp     8
#define MIXINL_TO_SPKMIXL_bp    7
#define MIXINR_TO_SPKMIXR_bp    6
#define IN1LP_TO_SPKMIXL_bp     5
#define IN1RP_TO_SPKMIXR_bp     4
#define MIXOUTL_TO_SPKMIXL_bp   3
#define MIXOUTR_TO_SPKMIXR_bp   2
#define DAC1L_TO_SPKMIXL_bp     1
#define DAC1R_TO_SPKMIXR_bp     0

#define DAC2L_TO_SPKMIXL_bm     (1<<DAC2L_TO_SPKMIXL_bp)
#define DAC2R_TO_SPKMIXR_bm     (1<<DAC2R_TO_SPKMIXR_bp)
#define MIXINL_TO_SPKMIXL_bm    (1<<MIXINL_TO_SPKMIXL_bp)
#define MIXINR_TO_SPKMIXR_bm    (1<<MIXINR_TO_SPKMIXR_bp)
#define IN1LP_TO_SPKMIXL_bm     (1<<IN1LP_TO_SPKMIXL_bp)
#define IN1RP_TO_SPKMIXR_bm     (1<<IN1RP_TO_SPKMIXR_bp)
#define MIXOUTL_TO_SPKMIXL_bm   (1<<MIXOUTL_TO_SPKMIXL_bp)
#define MIXOUTR_TO_SPKMIXR_bm   (1<<MIXOUTR_TO_SPKMIXR_bp)
#define DAC1L_TO_SPKMIXL_bm     (1<<DAC1L_TO_SPKMIXL_bp)
#define DAC1R_TO_SPKMIXR_bm     (1<<DAC1R_TO_SPKMIXR_bp)

//Register R55 - Additional Control

#define R55 0x0037
#define ADDITIONAL_CONTROL_REG R55

#define LINEOUT1_FB_bp  7
#define LINEOUT2_FB_bp  6
#define VROI_bp         0


#define LINEOUT1_FB_bm  (1<<LINEOUT1_FB_bp)
#define LINEOUT2_FB_bm  (1<<LINEOUT2_FB_bp)
#define VROI_bm         (1<<VROI_bp)

//Register R56 - AntiPOP (1)

#define R56 0x0038
#define ANTIPOP_1_REG R56

#define LINEOUT_VMID_BUF_ENA_bp     7
#define HPOUT2_IN_ENA_bp            6
#define LINEOUT1_DISCH_bp           5
#define LINEOUT2_DISCH_bp           4

#define LINEOUT_VMID_BUF_ENA_bm     (1<<LINEOUT_VMID_BUF_ENA_bp)
#define HPOUT2_IN_ENA_bm            (1<<HPOUT2_IN_ENA_bp)
#define LINEOUT1_DISCH_bm           (1<<LINEOUT1_DISCH_bp)
#define LINEOUT2_DISCH_bm           (1<<LINEOUT2_DISCH_bp)

//Register R57 - AntiPOP (2)

#define R57 0x0039
#define ANTIPOP_2_REG R57

#define MICB2_DISCH_bp          8
#define MICB1_DISCH_bp          7
#define VMID_RAMP_bp            5
#define VMID_BUF_ENA_bp         3
#define STARTUP_BIAS_ENA_bp     2
#define BIAS_SRC_bp             1
#define VMID_DISCH_bp           0

#define MICB2_DISCH_bm          (1<<MICB2_DISCH_bp)
#define MICB1_DISCH_bm          (1<<MICB1_DISCH_bp)
#define VMID_RAMP_bm            (3<<VMID_RAMP_bp)
#define VMID_BUF_ENA_bm         (1<<VMID_BUF_ENA_bp)
#define STARTUP_BIAS_ENA_bm     (1<<STARTUP_BIAS_ENA_bp)
#define BIAS_SRC_bm             (1<<BIAS_SRC_bp)
#define VMID_DISCH_bm           (1<<VMID_DISCH_bp)

#define VMID_RAMP_NORMAL_SLOW_START 0
#define VMID_RAMP_NORMAL_FAST_START	1
#define VMID_RAMP_SOFT_SLOW_START	2
#define VMID_RAMP_SOFT_FAST_START 	3

//Register R58 - MICBIAS

#define R58 0x003A
#define MICBIAS_REG R58

#define MICD_SCTHR_bp   6
#define MICD_THR_bp     3
#define MICD_ENA_bp     2
#define MICB2_LVL_bp    1
#define MICB1_LVL_bp    0

#define MICD_SCTHR_bm   (3<<MICD_SCTHR_bp)
#define MICD_THR_bm     (7<<MICD_THR_bp)
#define MICD_ENA_bm     (1<<MICD_ENA_bp)
#define MICB2_LVL_bm    (1<<MICB2_LVL_bp)
#define MICB1_LVL_bm    (1<<MICB1_LVL_bp)

#define MICD_SCTHR_300UA    0
#define MICD_SCTHR_600UA    1
#define MICD_SCTHR_1200UA   2
#define MICD_SCTHR_2400UA   3

#define MICD_THR_150UA      0
#define MICD_THR_300UA      2
#define MICD_THR_600UA      4
#define MICD_THR_1200UA     6

//Register R59 - LDO1 

#define R59 0x003B
#define LDO1_REG R59

#define LDO1_VSEL_bp    1
#define LDO1_DISCH_bp   0

#define LDO1_VSEL_bm    (7<<LDO1_VSEL_bp)
#define LDO1_DISCH_bm   (1<<LDO1_DISCH_bp)

#define LDO1_VSEL_2_4   0
#define LDO1_VSEL_2_5   1
#define LDO1_VSEL_2_6   2
#define LDO1_VSEL_2_7   3
#define LDO1_VSEL_2_8   4   
#define LDO1_VSEL_2_9   5
#define LDO1_VSEL_3_0   6
#define LDO1_VSEL_3_1   7

//Register R60 - LDO2

#define R60 0x003C
#define LDO2_REG R60

#define LDO2_VSEL_bp    1
#define LDO2_DISCH_bp   0

#define LDO2_VSEL_bm    (3<<LDO2_VSEL_bp)
#define LDO2_DISCH_bm   (1<<LDO2_DISCH_bp)

#define LDO2_VSEL_0_9   0   
#define LDO2_VSEL_1_0   1
#define LDO2_VSEL_1_1   2
#define LDO2_VSEL_1_2   3

//Register R76 - Charge Pump (1)

#define R76 0x004C
#define CHARPE_PUMP_1_REG R76

#define CP_ENA_bp   15

#define CP_ENA_bm   (1<<CP_ENA_bp)

//Register R77 - Charge Pump (2)

#define R77 0x004D
#define CHARGE_PUMP_2_REG R77

#define CP_DISCH_bp 15

#define CP_DISCH_bm (1<<CP_DISCH_bp)

//Register R81 - Class W (1)

#define R81 0x0051
#define CLASSW_1_REG R81

#define CP_DYN_SRC_SEL_bp   8
#define CP_DYN_PWR_bp       0

#define CP_DYN_SRC_SEL_bm   (3<<CP_DYN_SRC_SEL_bp)
#define CP_DYN_PWM_bm       (1<<CP_DYN_PWR_bp)

//Register R84 - Servo (1)

#define R84 0x0054
#define SERVO_1_REG R84

#define DCS_TRIG_SINGLE_1_bp    13
#define DCS_TRIG_SINGLE_0_bp    12
#define DCS_TRIG_SERIES_1_bp    9
#define DCS_TRIG_SERIES_0_bp    8
#define DCS_TRIG_STARTUP_1_bp   5
#define DCS_TRIG_STARTUP_0_bp   4
#define DCS_TRIG_DAC_WR_1_bp    3
#define DCS_TRIG_DAC_WR_0_bp    2
#define DCS_ENA_CHAN_1_bp       1
#define DCS_ENA_CHAN_0_bp       0

#define DCS_TRIG_SINGLE_1_bm    (1<<DCS_TRIG_SINGLE_1_bp)
#define DCS_TRIG_SINGLE_0_bm    (1<<DCS_TRIG_SINGLE_0_bp)
#define DCS_TRIG_SERIES_1_bm    (1<<DCS_TRIG_SERIES_1_bp)
#define DCS_TRIG_SERIES_0_bm    (1<<DCS_TRIG_SERIES_0_bp)
#define DCS_TRIG_STARTUP_1_bm   (1<<DCS_TRIG_STARTUP_1_bp)
#define DCS_TRIG_STARTUP_0_bm   (1<<DCS_TRIG_STARTUP_0_bp)
#define DCS_TRIG_DAC_WR_1_bm    (1<<DCS_TRIG_DAC_WR_1_bp)
#define DCS_TRIG_DAC_WR_0_bm    (1<<DCS_TRIG_DAC_WR_0_bp)
#define DCS_ENA_CHAN_1_bm       (1<<DCS_ENA_CHAN_1_bp)
#define DCS_ENA_CHAN_0_bm       (1<<DCS_ENA_CHAN_0_bp) 

//Register R85 - Servo (2)

#define R85 0x0055
#define SERVO_2_REG R85

#define DCS_SERIES_NO_01_bp     5
#define DCS_TIMER_PERIOD_01_bp  0

#define DCS_SERIES_NO_01_bm     (0x7F<<DCS_SERIES_NO_01_bp)
#define DCS_TIMER_PERIOD_01_bm  (1<<DCS_TIMER_PERIOD_01_bp)

//Register R88 - Servo Readback

#define R88 0x0058 
#define SERVO_READBACK_REG R88

#define DCS_CAL_COMPLETE_bp         8
#define DCS_DAC_WR_COMPLETE_bp      4
#define DCS_STARTUP_COMPLETE_bp     0

#define DCS_CAL_COMPLETE_bm         (3<<DCS_CAL_COMPLETE_bp)
#define DCS_DAC_WR_COMPLETE_bm      (3<<DCS_DAC_WR_COMPLETE_bp)
#define DCS_STARTUP_COMPLETE_bm     (3<<DCS_STARTUP_COMPLETE_bp)

//Register R89 - Servo Write Val

#define R89 0x0059
#define SERVO_WRITE_VAL_REG R89

#define DCS_DAC_WR_VAL_1_bp     8
#define DCS_DAC_WR_VAL_0_bp     0

#define DCS_DAC_WR_VAL_1_bm     (0xFF<<DCS_DAC_WR_VAL_1_bp)
#define DCS_DAC_WR_VAL_0_bm     (0xFF<<DCS_DAC_WR_VAL_0_bp)

//Register R96 - Analogue HP (1)

#define R96 0x0060
#define ANALOGUE_HP_1_REG R96

#define HPOUT1L_RMV_SHORT_bp    7
#define HPOUT1L_OUTP_bp         6
#define HPOUT1L_DLY_bp          5
#define HPOUT1R_RMV_SHORT_bp    3
#define HPOUT1R_OUTP_bp         2
#define HPOUT1R_DLY_bp          1

#define HPOUT1L_RMV_SHORT_bm    (1<<HPOUT1L_RMV_SHORT_bp)
#define HPOUT1L_OUTP_bm         (1<<HPOUT1L_OUTP_bp)
#define HPOUT1L_DLY_bm          (1<<HPOUT1L_DLY_bp)
#define HPOUT1R_RMV_SHORT_bm    (1<<HPOUT1R_RMV_SHORT_bp)
#define HPOUT1R_OUTP_bm         (1<<HPOUT1R_OUTP_bp)
#define HPOUT1R_DLY_bm          (1<<HPOUT1R_DLY_bp)

//Register R256 - Chip Revision

#define R256 0x0100
#define CHIP_REVISION_REG R256

#define CHIP_REV_bp     0

#define CHIP_REV_bm     0x0F

//Register R257 - Control Interface

#define R257 0x0101
#define CONTROL_INTERFACE R257

#define SPI_CONTRD_bp   6
#define SPI_4WIRE_bp    5
#define SPI_CFG_bp      4
#define AUTO_INC_bp     2

#define SPI_CONTRD_bm   (1<<SPI_CONTRD_bp)
#define SPI_4WIRE_bm    (1<<SPI_4WIRE_bp)
#define SPI_CFG_bm      (1<<SPI_CFG_bp)
#define AUTO_INC_bm     (1<<AUTO_INC_bp)

// Register R272 - Write Sequencer Control (1)

#define R272 0x0110
#define WRITE_SEQUENCER_CONTROL_1_REG R272

#define WSEQ_ENA_bp         15
#define WSEQ_ABORT_bp       9
#define WSEQ_START_bp       8
#define WSEQ_START_INDEX_bp 0

#define WSEQ_ENA_bm         (1<<WSEQ_ENA_bp)        
#define WSEQ_ABORT_bm       (1<<WSEQ_ABORT_bp)
#define WSEQ_START_bm       (1<<WSEQ_START_bp)
#define WSEQ_START_INDEX_bm (0x7F<<WSEQ_START_INDEX_bp)

// Register R273 -  Write Sequencer Control (2)

#define R273 0x0111
#define WRITE_SEQUENCER_CONTROL_2_REG R273

#define WSEQ_BUSY_bp            8
#define WSEQ_CURRENT_INDEX_bp   0

#define WSEQ_BUSY_bm            (1<<WSEQ_BUSY_bp)
#define WESQ_CURRENT_INDEX_bm   (0x7F<<WSEQ_CURRENT_INDEX_bp)

// Default Sequences
#define HEADPHONE_COLD_START_UP_START_INDEX                 0x8100
#define HEADPHONE_WARM_START_UP_START_INDEX                 0x8108
#define SPEAKER_STARP_UP_START_INDEX                        0x8110
#define EARPIECE_START_UP_START_INDEX                       0x8113
#define LINE_OUTPUT_START_UP_START_INDEX                    0x8119
#define SPEAKER_AND_HEADPHONE_FAST_SHUT_DOWN_START_INDEX    0x8122
#define GENERIC_SHUTDOWN_START_INDEX                        0x812A

//Register R512 - AIF1 Clocking (1)

#define R512 0x0200
#define AIF1_CLOCKING_1_REG R512

#define AIF1CLK_SRC_bp		3
#define AIF1CLK_INV_bp		2
#define AIF1CLK_DIV_bp		1
#define AIF1CLK_ENA_bp		0

#define AIF1CLK_SRC_bm		(0x03<<AIF1CLK_SRC_bp)
#define AIF1CLK_INV_bm      (1<<AIF1CLK_INV_bp)
#define AIF1CLK_DIV_bm      (1<<AIF1CLK_DIV_bp)
#define AIF1CLK_ENA_bm      (1<<AIF1CLK_ENA_bp)

#define AIF1CLK_SRC_MCLK1	0
#define AIF1CLK_SRC_MCLK2	1
#define AIF1CLK_SRC_FLL1	2
#define AIF1CLK_SRC_FLL2	3

//Register R513 - AIF1 Clocking (2)

#define R513 0x0201
#define AIF1_CLOCKING_2_REG R513

#define AIF1DAC_DIV_bp	3
#define AIF1ADC_DIV_bp  0

#define AIF1DAC_DIV_bm	(0x07<<AIF1DAC_DIV_bp)
#define AIF1ADC_DIV_bm  (0x07<<AIF1ADC_DIV_bp)

#define AIF1DIV_1	0
#define AIF1DIV_1_5	1
#define AIF1DIV_2	2
#define AIF1DIV_3	3
#define AIF1DIV_4	4
#define AIF1DIV_5_5	5
#define AIF1DIV_6	6

//Register R516 - AIF2 Clocking (1)

#define R516 0x0204
#define AIF2_CLOCKING_1_REG R516

#define AIF2CLK_SRC_bp		3
#define AIF2CLK_INV_bp		2
#define AIF2CLK_DIV_bp		1
#define AIF2CLK_ENA_bp		0

#define AIF2CLK_SRC_bm		(0x03<<AIF2CLK_SRC_bp)
#define AIF2CLK_INV_bm      (1<<AIF2CLK_INV_bp)
#define AIF2CLK_DIV_bm      (1<<AIF2CLK_DIV_bp)
#define AIF2CLK_ENA_bm      (1<<AIF2CLK_ENA_bp)

#define AIF2CLK_SRC_MCLK1	0
#define AIF2CLK_SRC_MCLK2	1
#define AIF2CLK_SRC_FLL1	2
#define AIF2CLK_SRC_FLL2	3

//Register R517 - AIF2 Clocking (2)

#define R517 0x0205
#define AIF2_CLOCKING_2_REG R517

#define AIF2DAC_DIV_bp	3
#define AIF2ADC_DIV_bp  0

#define AIF2DAC_DIV_bm	(0x07<<AIF2DAC_DIV_bp)
#define AIF2ADC_DIV_bm  (0x07<<AIF2ADC_DIV_bp)

#define AIF2DIV_1	0
#define AIF2DIV_1_5	1
#define AIF2DIV_2	2
#define AIF2DIV_3	3
#define AIF2DIV_4	4
#define AIF2DIV_5_5	5
#define AIF2DIV_6	6

//Register R520 - Clocking (1)

#define R520	0x0208
#define CLOCKING_1_REG R520

#define TOCLK_ENA_bp		4
#define AIF1DSPCLK_ENA_bp	3
#define AIF2DSPCLK_ENA_bp	2
#define SYSDSPCLK_ENA_bp	1
#define SYSCLK_SRC_bp		0

#define TOCLK_ENA_bm        (1<<TOCLK_ENA_bp)
#define AIF1DSPCLK_ENA_bm   (1<<AIF1DSPCLK_ENA_bp)
#define AIF2DSPCLK_ENA_bm   (1<<AIF2DSPCLK_ENA_bp
#define SYSDSPCLK_ENA_bm    (1<<SYSDSPCLK_ENA_bp)
#define SYSCLK_SRC_bm       (1<<SYSCLK_SRC_bp)

//Register R521 - Clocking (2)

#define R521	0x0209
#define CLOCKING_2_REG R521

#define TOCLK_DIV_bp	8
#define TOCLK_DIV_bm	(0x07<<TOCLK_DIV_bp)

#define TOCLK_DIV_256	0
#define TOCLK_DIV_512	1
#define TOCLK_DIV_1024	2
#define TOCLK_DIV_2048	3
#define TOCLK_DIV_4096	4
#define TOCLK_DIV_8192	5
#define TOCLK_DIV_16384	6
#define TOCLK_DIV_32768	7

#define DBCLK_DIV_bp	4
#define DBCLK_DIV_bm	(0x07<<DBCLK_DIV_bp)

#define DBCLK_DIV_256		0
#define DBCLK_DIV_2048		1
#define DBCLK_DIV_4096		2
#define DBCLK_DIV_8192		3
#define DBCLK_DIV_16384		4
#define DBCLK_DIV_32768		5
#define DBCLK_DIV_65536		6
#define DBCLK_DIV_131072	7

#define OPCLK_DIV_bp	0
#define OPCLK_DIV_bm	(0x07<<OPCLK_DIV_bp)

#define OPCLK_DIV_1		0
#define OPCLK_DIV_2		1
#define OPCLK_DIV_3		2
#define OPCLK_DIV_4		3
#define OPCLK_DIV_5_5	4
#define OPCLK_DIV_6		5
#define OPCLK_DIV_8		6
#define OPCLK_DIV_12	7
#define OPCLK_DIV_16	8

//Register R528 - AIF1 Rate

#define R528 0x0210
#define AIF1_RATE_REG R528

#define AIF1_SR_bp		4
#define AIF1_SR_bm		(0xF0<<AIF1_SR_bp)

#define AIF1_SR_8K		0
#define AIF1_SR_11_025K	1
#define AIF1_SR_12K		2
#define AIF1_SR_16K		3
#define AIF1_SR_22_025K	4
#define AIF1_SR_24K		5
#define AIF1_SR_32K		6
#define AIF1_SR_44_1K	7
#define AIF1_SR_48K		8
#define AIF1_SR_88_2K	9
#define AIF1_SR_96K		10

#define AIF1CLK_RATE_bp	0
#define AIF1CLK_RATE_bm	(0x0F<<AIF1CLK_RATE_bp)
#define AIF1CLK_RATE_128	1
#define AIF1CLK_RATE_192	2
#define AIF1CLK_RATE_256	3
#define AIF1CLK_RATE_384	4
#define AIF1CLK_RATE_512	5
#define AIF1CLK_RATE_768	6
#define AIF1CLK_RATE_1024	7
#define AIF1CLK_RATE_1406	8
#define AIF1CLK_RATE_1536	9

//Register R529 - AIF2 Rate

#define R529 0x0211
#define AIF2_RATE_REG R529

#define AIF2_SR_bp		4
#define AIF2_SR_bm		(0xF0<<AIF2_SR_bp)

#define AIF2_SR_8K		0
#define AIF2_SR_11_025K	1
#define AIF2_SR_12K		2
#define AIF2_SR_16K		3
#define AIF2_SR_22_025K	4
#define AIF2_SR_24K		5
#define AIF2_SR_32K		6
#define AIF2_SR_44_1K	7
#define AIF2_SR_48K		8
#define AIF2_SR_88_2K	9
#define AIF2_SR_96K		10

#define AIF2CLK_RATE_bp	0
#define AIF2CLK_RATE_bm	(0x0F<<AIF2CLK_RATE_bp)
#define AIF2CLK_RATE_128	1
#define AIF2CLK_RATE_192	2
#define AIF2CLK_RATE_256	3
#define AIF2CLK_RATE_384	4
#define AIF2CLK_RATE_512	5
#define AIF2CLK_RATE_768	6
#define AIF2CLK_RATE_1024	7
#define AIF2CLK_RATE_1406	8
#define AIF2CLK_RATE_1536	9

//Register R530 - Rate Status

#define R530 0x0212
#define RATE_STATUS_REG R530

#define SR_ERROR_bp 0
#define SR_ERROR_bm (0x0F<<SR_ERROR_bp)

#define SR_ERROR_NO_ERROR                                                                               0x0
#define SR_ERROR_INVALID_SAMPLE_RATE                                                                    0x1
#define SR_ERROR_INVALID_AIF_DIVIDE                                                                     0x2
#define SR_ERROR_ADC_AND_DAC_DIVIDES_BOTH_SET_IN_AN_INTERFACE                                           0x3
#define SR_ERROR_INVALID_COMBINATION_OF_AIF_DIVIDES_AND_SAMPLE_RATE                                     0x4
#define SR_ERROR_INVALID_SET_OF_ENABLES_FOR_96KHZ_MODE                                                  0x5
#define SR_ERROR_INVALID_SYSCLK_RATE                                                                    0x6
#define SR_ERROR_MIXED_ADC_DAC_RATES                                                                    0x7
#define SR_ERROR_INVALID_COMBINATION_OF_SAMPLE_RATES_WHEN_BOTH_AIFS_ARE_FORM_THE_SAME_CLOCK_SOURCE      0x8
#define SR_ERROR_INVALID_COMBINATION_OF_MIXED_ADC_DAC_AIFS_WHEN_BOTEN_FROM_THE_SAME_CLOCK_SOURCE        0x9
#define SR_ERROR_AIF1DAC2_PORTS_ENABLED_WHEN_SRCS_CONNECTED_TO_AIF1                                     0xA

//Register R544 - FLL1 Control (1)

#define R544 0x0220
#define FLL1_CONTROL_1_REG R544

#define FLL1_OSC_ENA_bp     1
#define FLL1_ENA_bp         0

#define FLL1_OSC_ENA_bm     (1<<FLL1_OSC_ENA_bp)
#define FLL1_ENA_bm         (1<<FLL1_ENA_bp)

//Register R545 - FLL1 Control (2)

#define R545 0x221
#define FLL1_CONTROL_2_REG R545

#define FLL1_OUTDIV_bp  8
#define FLL1_FRATIO_bp  0

#define FLL1_OUTDIV_bm  (0x3F<<FLL1_OUTDIV_bp)
#define FLL1_FRATIO_bm  (0x7<<FLL1_FRATIO_bp)

//Register R546 - FLL1 Control (3)

#define R546 0x0222
#define FLL1_CONTROL_3_REG R546
#define FLL1_CONTROL_3 R546
#define FLL1_K_REG R546

#define FLL1_K_bp 0

#define FLL1_K_bm (0xFFFF<<FLL1_K_bp)

//Register R547 - FLL1 Control (4)

#define R547 0x0223
#define FLL1_CONTROL_4_REG R547
#define FLL1_CONTROL_4 R547
#define FLL1_N_REG R547

#define FLL1_N_bp 0

#define FLL1_N_bm (0xFFFF<<FLL1_N_bp)

//Register R548 - FLL1 Control (5)

#define R548 0x0224
#define FLL1_CONTROL_5_REG R548
#define FLL1_CONTROL_5  R548

#define FLL1_FRC_NCO_VAL_bp     7
#define FLL1_FRC_NCO_bp         6
#define FLL1_REFCLK_DIV_bp      3
#define FLL1_REFCLK_SRC_bp      0

#define FLL1_FRC_NCO_VAL_bm     (0x3F<<FLL1_FRC_NCO_VAL_bp)
#define FLL1_FRC_NCO_bm         (1<<FLL1_FRC_NCO_bp)
#define FLL1_REFCLK_DIV_bm      (3<<FLL1_REFCLK_DIV_bp)
#define FLL1_REFCLK_SRC_bm      (3<<FLL1_REFCLK_SRC_bp)

#define FLL1_REFCLK_DIV_1   0
#define FLL1_REFCLK_DIV_2   1
#define FLL1_REFCLK_DIV_4   2
#define FLL1_REFCLK_DIV_8   3

#define FLL1_REFCLK_SRC_MCLK1   0
#define FLL1_REFCLK_SRC_MCLK2   1
#define FLL1_REFCLK_SRC_LRCLK2  2
#define FLL1_REFCLK_SRC_BCLK2   3

//Register R576 - FLL2 Control (1)

#define R576 0x0240
#define FLL2_CONTROL_1_REG R576

#define FLL2_OSC_ENA_bp     1
#define FLL2_ENA_bp         0

#define FLL2_OSC_ENA_bm     (1<<FLL2_OSC_ENA_bp)
#define FLL2_ENA_bm         (1<<FLL2_ENA_bp)

//Register R577 - FLL2 Control (2)

#define R577 0x0241
#define FLL2_CONTROL_2_REG R577

#define FLL2_OUTDIV_bp  8
#define FLL2_FRATIO_bp  0

#define FLL2_OUTDIV_bm  (0x3F<<FLL2_OUTDIV_bp)
#define FLL2_FRATIO_bm  (7<<FLL2_FRATIO_bp)

//Register R579 - FLL2 Control (3)

#define R578 0x0242
#define FLL2_CONTROL_3_REG R578
#define FLL2_CONTROL_3 R578
#define FLL2_K_REG R578

#define FLL2_K_bp   0

#define FLL2_K_bm   (0xFFFF<<FLL2_K_bp)

//Register R579 - FLL2 Control (4)

#define R579 0x0243
#define FLL2_CONTROL_4_REG R579
#define FLL2_CONTROL_4 R579
#define FLL2_N_REG R579

#define FLL2_N_bp   0

#define FLL2_N_bm   (0x03FF<<FLL2_N_bp)

//Register R580 - FLL2 Control (5)

#define R580 0x0244
#define FLL2_CONTROL_5_REG R580

#define FLL2_FRC_NCO_VAL_bp     7
#define FLL2_FRC_NCO_bp         6
#define FLL2_REFCLK_DIV_bp      3
#define FLL2_REFCLK_SRC_bp      0

#define FLL2_FRC_NCO_VAL_bm     (0x3F<<FLL2_FRC_NCO_VAL_bp)
#define FLL2_FRC_NCO_bm         (1<<FLL2_FRC_NCO_bp)
#define FLL2_REFCLK_DIV_bm      (3<<FLL2_REFCLK_DIV_bp)
#define FLL2_REFCLK_SRC_bm      (3<<FLL2_REFCLK_SRC_bp)

#define FLL2_REFCLK_DIV_1   0
#define FLL2_REFCLK_DIV_2   1
#define FLL2_REFCLK_DIV_4   2
#define FLL2_REFCLK_DIV_8   3

#define FLL2_REFCLK_SRC_MCLK1   0
#define FLL2_REFCLK_SRC_MCLK2   1
#define FLL2_REFCLK_SRC_LRCLK2  2
#define FLL2_REFCLK_SRC_BCLK2   3

//Register R768 - AIF1 Control (1)

#define R768 0x300
#define AIF1_CONTROL_1_REG R768

#define AIF1ADCL_SRC_bp     15

#define AIF1DACL_DAT_INV_bp     1
#define AIF1DACR_DAT_INV_bp     0

#define AIF1DACL_DAT_INV_bm     (1<<AIF1DACL_DAT_INV_bp)
#define AIF1DACR_DAT_INV_bm     (1<<AIF1DACR_DAT_INV_bp)
#define AIF1ADCR_SRC_bp     14
#define AIF1ADC_TDM_bp      13
#define AIF1_BCLK_INV_bp    8
#define AIF1_LRCLK_INV_bp   7
#define AIF1_WL_bp          5
#define AIF1_FMT_bp         3

#define AIF1ADCL_SRC_bm     (1<<AIF1ADCL_SRC_bp)
#define AIF1ADCR_SRC_bm     (1<<AIF1ADCR_SRC_bp)
#define AIF1ADC_TDM_bm      (1<<AIF1ADC_TDM_bp)
#define AIF1_BCLK_INV_bm    (1<<AIF1_BCLK_INV_bp)
#define AIF1_LRCLK_INV_bm   (1<<AIF1_LRCLK_INV_bp)
#define AIF1_WL_bm          (3<<AIF1_WL_bp)
#define AIF1_FMT_bm         (3<<AIF1_FMT_bp)

#define AIF1_WL_16BIT   0
#define AIF1_WL_20BIT   1    
#define AIF1_WL_24BIT   2    
#define AIF1_WL_32BIT   3    

#define AIF1_FMT_RIGHT_JUSTIFIED    0
#define AIF1_FMT_LEFT_JUSTIFIED     1
#define AIF1_FMT_I2S                2
#define AIF1_FMT_DSP                3

//Register R769 - AIF1 Control (2)

#define R769 0x0301
#define AIF1_CONTROL_2_REG R769

#define AIF1DACL_SRC_bp     15
#define AIF1DACR_SRC_bp     14
#define AIF1DAC_BOOST_bp    10
#define AIF1_MONO_bp        8
#define AIF1DAC_COMP_bp     4
#define AIF1DAC_COMPMODE_bp 3
#define AIF1ADC_COMP_bp     2
#define AIF1ADC_COMPMODE_bp 1
#define AIF1_LOOPBACK_bp    0

#define AIF1DACL_SRC_bm     (1<<AIF1DACL_SRC_bp)
#define AIF1DACR_SRC_bm     (1<<AIF1DACR_SRC_bp)
#define AIF1DAC_BOOST_bm    (3<<AIF1DAC_BOOST_bp)
#define AIF1_MONO_bm        (1<<AIF1_MONO_bp)
#define AIF1DAC_COMP_bm     (1<<AIF1DAC_COMP_bp)
#define AIF1DAC_COMPMODE_bm (1<<AIF1DAC_COMPMODE_bp)
#define AIF1ADC_COMP_bm     (1<<AIF1ADC_COMP_bp)
#define AIF1ADC_COMPMODE_bm (1<<AIF1ADC_COMPMODE_bp)
#define AIF1_LOOPBACK_bm    (1<<AIF1_LOOPBACK_bp)

//Register R770 - AIF1 Master/Slave

#define R770 0x0302
#define AIF1_MASTER_SLAVE_REG R770

#define AIF1_TRI_bp         15
#define AIF1_MSTR_bp        14
#define AIF1_CLK_FRC_bp     13
#define AIF1_LRCLK_FRC_bp   12

#define AIF1_TRI_bm         (1<<AIF1_TRI_bp)
#define AIF1_MSTR_bm        (1<<AIF1_MSTR_bp)
#define AIF1_CLK_FRC_bm     (1<<AIF1_CLK_FRC_bp)
#define AIF1_LRCLK_FRC_bm   (1<<AIF1_LRCLK_FRC_bp)

//Register R771 - AIF1 BCLK

#define R771 0x0303
#define AIF1_BCLK_REG R771

#define AIF1_BCLK_DIV_bp    4
#define AIF1_BCLK_DIV_bm    (0x1F<<AIF1_BCLK_DIV_bp)

#define AIF1_BCLK_DIV_1     0x00
#define AIF1_BCLK_DIV_1_5   0x01
#define AIF1_BCLK_DIV_2     0x02
#define AIF1_BCLK_DIV_3     0x03
#define AIF1_BCLK_DIV_4     0x04
#define AIF1_BCLK_DIV_5     0x05
#define AIF1_BCLK_DIV_6     0x06
#define AIF1_BCLK_DIV_8     0x07
#define AIF1_BCLK_DIV_11    0x08
#define AIF1_BCLK_DIV_12    0x09
#define AIF1_BCLK_DIV_16    0x0A
#define AIF1_BCLK_DIV_22    0x0B
#define AIF1_BCLK_DIV_24    0x0C
#define AIF1_BCLK_DIV_32    0x0D
#define AIF1_BCLK_DIV_44    0x0E
#define AIF1_BCLK_DIV_48    0x0F
#define AIF1_BCLK_DIV_64    0x10
#define AIF1_BCLK_DIV_88    0x11
#define AIF1_BCLK_DIV_96    0x12
#define AIF1_BCLK_DIV_128   0x13
#define AIF1_BCLK_DIV_176   0x14
#define AIF1_BCLK_DIV_192   0x15

//Register R772 - AIF1ADC LRCLK

#define R772 0x0304
#define AIF1ADC_LRCLK_REG R772

#define AIF1ADC_LRCLK_DIR_bp    11
#define AIF1ADC_RATE_bp         0

#define AIF1ADC_LRCLK_DIR_bm    (3<<AIF1ADC_LRCLK_DIR_bp)
#define AIF1ADC_RATE_bm         (0x07FF<<AIF1ADC_RATE_bp)

//Register R773 - AIF1DAC LRCLK

#define R773 0x0305
#define AIF1DAC_LRCLK_REG R773

#define AIF1DAC_LRCLK_DIR_bp    11
#define AIF1DAC_RATE_bp         0

#define AIF1DAC_LRCLK_DIR_bm    (3<<AIF1DAC_LRCLK_DIR_bp)
#define AIF1DAC_RATE_bm         (0x07FF<<AIF1DAC_RATE_bp)

//Register R774 - AIF1DAC Data

#define R774 0x0306
#define AIF1DAC_DATA_REG R774

#define AIF1DACL_DAT_INV_bp     1
#define AIF1DACR_DAT_INV_bp     0

#define AIF1DACL_DAT_INV_bm     (1<<AIF1DACL_DAT_INV_bp)
#define AIF1DACR_DAT_INV_bm     (1<<AIF1DACR_DAT_INV_bp)

//Register R775 - AIF1ADC Data

#define R775 0x0307
#define AIF1ADC_DATA_REG R775

#define AIF1ADCL_DAT_INV_bp     1
#define AIF1ADCR_DAT_INV_bp     0

#define AIF1ADCL_DAT_INV_bm     (1<<AIF1ADCL_DAT_INV_bp)
#define AIF1ADCR_DAT_INV_bm     (1<<AIF1ADCR_DAT_INV_bp)

//Register R784 - AIF2 Control (1)

#define R784 0x0310
#define AIF2_CONTROL_1_REG R784

#define AIF2ADCL_SRC_bp         15
#define AIF2ADCR_SRC_bp         14
#define AIF2ADC_TDM_bp          13
#define AIF2ADC_TDM_CHAN_bp     12
#define AIF2_BCLK_INV_bp        8
#define AIF2_LRCLK_INV_bp       7
#define AIF2_WL_bp              5
#define AIF2_FMT_bp             3

#define AIF2ADCL_SRC_bm         (1<<AIF2ADCL_SRC_bp)
#define AIF2ADCR_SRC_bm         (1<<AIF2ADCR_SRC_bp)
#define AIF2ADC_TDM_bm          (1<<AIF2ADC_TDM_bp)
#define AIF2ADC_TDM_CHAN_bm     (1<<AIF2ADC_TDM_CHAN_bp)
#define AIF2_BCLK_INV_bm        (1<<AIF2_BCLK_INV_bp)
#define AIF2_LRCLK_INV_bm       (1<<AIF2_LRCLK_INV_bp)
#define AIF2_WL_bm              (3<<AIF2_WL_bp)
#define AIF2_FMT_bm             (3<<AIF2_FMT_bp)

#define AIF2_WL_16BITS  0
#define AIF2_WL_20BITS  1
#define AIF2_WL_24BITS  2
#define AIF2_WL_32BITS  3

#define AIF2_FMT_RIGHT_JUSTIFIED    0
#define AIF2_FMT_LEFT_JUSTIFIED     1
#define AIF2_FMT_I2S_FORMAT         2
#define AIF2_FMT_DSP_MODE           3

//Register R785 - AIF2 Control (2)

#define R785 0x0311
#define AIF2_CONTROL_2_REG R785

#define AIF2DACL_SRC_bp         15
#define AIF2DACR_SRC_bp         14
#define AIF2DAC_TDM_bp          13
#define AIF2DAC_TDM_CHAN_bp     12
#define AIF2DAC_BOOST_bp        10
#define AIF2_MONO_bp            8
#define AIF2DAC_COMP_bp         4
#define AIF2DAC_COMPMODE_bp     3
#define AIF2ADC_COMP_bp         2
#define AIF2ADC_COMPMODE_bp     1
#define AIF2_LOOPBACK_bp        0    

#define AIF2DACL_SRC_bm         (1<<AIF2DACL_SRC_bp)
#define AIF2DACR_SRC_bm         (1<<AIF2DACR_SRC_bp)
#define AIF2DAC_TDM_bm          (1<<AIF2DAC_TDM_bp)
#define AIF2DAC_TDM_CHAN_bm     (1<<AIF2DAC_TDM_CHAN_bp)
#define AIF2DAC_BOOST_bm        (3<<AIF2DAC_BOOST_bp)
#define AIF2_MONO_bm            (1<<AIF2_MONO_bp)
#define AIF2DAC_COMP_bm         (1<<AIF2DAC_COMP_bp)
#define AIF2DAC_COMPMODE_bm     (1<<AIF2DAC_COMPMODE_bp)
#define AIF2ADC_COMP_bm         (1<<AIF2ADC_COMP_bp)
#define AIF2ADC_COMPMODE_bm     (1<<AIF2ADC_COMPMODE_bp)
#define AIF2_LOOPBACK_bm        (1<<AIF2_LOOPBACK_bp)

//Register R786 - AIF2 Master/Slave

#define R786 0x0312
#define AIF2_MASTER_SLAVE_REG R786

#define AIF2_TRI_bp         15
#define AIF2_MSTR_bp        14
#define AIF2_CLK_FRC_bp     13
#define AIF2_LRCLK_FRC_bp   12

#define AIF2_TRI_bm         (1<<AIF2_TRI_bp)
#define AIF2_MSTR_bm        (1<<AIF2_MSTR_bp)
#define AIF2_CLK_FRC_bm     (1<<AIF2_CLK_FRC_bp)
#define AIF2_LRCLK_FRC_bm   (1<<AIF2_LRCLK_FRC_bp)

//Register R787 - AIF2 BCLK

#define R787 0x0313
#define AIF2_BCLK_REG R787

#define AIF2_BCLK_DIV_bp    4
#define AIF2_BCLK_DIV_bm    (0x1F<<AIF2_BCLK_DIV_bp)

#define AIF2_BCLK_DIV_1     0x00
#define AIF2_BCLK_DIV_1_5   0x01
#define AIF2_BCLK_DIV_2     0x02
#define AIF2_BCLK_DIV_3     0x03
#define AIF2_BCLK_DIV_4     0x04
#define AIF2_BCLK_DIV_5     0x05
#define AIF2_BCLK_DIV_6     0x06
#define AIF2_BCLK_DIV_8     0x07
#define AIF2_BCLK_DIV_11    0x08
#define AIF2_BCLK_DIV_12    0x09
#define AIF2_BCLK_DIV_16    0x0A
#define AIF2_BCLK_DIV_22    0x0B
#define AIF2_BCLK_DIV_24    0x0C
#define AIF2_BCLK_DIV_32    0x0D
#define AIF2_BCLK_DIV_44    0x0E
#define AIF2_BCLK_DIV_48    0x0F
#define AIF2_BCLK_DIV_64    0x10
#define AIF2_BCLK_DIV_88    0x11
#define AIF2_BCLK_DIV_96    0x12
#define AIF2_BCLK_DIV_128   0x13
#define AIF2_BCLK_DIV_176   0x14
#define AIF2_BCLK_DIV_192   0x15

//Register R788 - AIF2ADC LRCLK

#define R788 0x0314
#define AIF2ADC_LRCLK_REG R788

#define AIF2ADC_LRCLK_DIR_bp    11
#define AIF2ADC_RATE_bp         0

#define AIF2ADC_LRCLK_DIR_bm    (3<<AIF2ADC_LRCLK_DIR_bp)
#define AIF2ADC_RATE_bm         (0x07FF<<AIF2ADC_RATE_bp)

//Register R789 - AIF2DAC LRCLK

#define R789 0x0315
#define AIF2DAC_LRCLK_REG R789

#define AIF2DAC_LRCLK_DIR_bp    11
#define AIF2DAC_RATE_bp         0

#define AIF2DAC_LRCLK_DIR_bm    (3<<AIF2DAC_LRCLK_DIR_bp)
#define AIF2DAC_RATE_bm         (0x07FF<<AIF2DAC_RATE_bp)

//Register R790 - AIF2DAC Data

#define R790 0x0316
#define AIF2DAC_DATA_REG R790

#define AIF2DACL_DAT_INV_bp     1
#define AIF2DACR_DAT_INV_bp     0

#define AIF2DACL_DAT_INV_bm     (1<<AIF2DACL_DAT_INV_bp)
#define AIF2DACR_DAT_INV_bm     (1<<AIF2DACR_DAT_INV_bp)

//Register R791 - AIF2ADC Data

#define R791 0x0317
#define AIF2ADC_DATA_REG R791

#define AIF2ADCL_DAT_INV_bp     1
#define AIF2ADCR_DAT_INV_bp     0

#define AIF2ADCL_DAT_INV_bm     (1<<AIF2ADCL_DAT_INV_bp)
#define AIF2ADCR_DAT_INV_bm     (1<<AIF2ADCR_DAT_INV_bp)

//Register R1024 - AIF1 ADC1 Left Volume

#define R1024 0x0400
#define AIF1ADC1_LEFT_VOLUME_REG R1024

#define AIF1ADC1L_VU_bp     8
#define AIF1ADC1L_VOL_bp    0

#define AIF1ADC1L_VU_bm     (1<<AIF1ADC1L_VU_bp)
#define AIF1ADC1L_VOL_bm    (0xFF<<AIF1ADC1L_VOL_bp)

//Register R1025 - AIF1 ADC1 Right Volume

#define R1025 0x0401
#define AIF1ADC1_RIGHT_VOLUME_REG R1025

#define AIF1ADC1R_VU_bp     8
#define AIF1ADC1R_VOL_bp    0

#define AIF1ADC1R_VU_bm     (1<<AIF1ADC1R_VU_bp)
#define AIF1ADC1R_VOL_bm    (0xFF<<AIF1ADC1R_VOL_bp)

//Register R1026 - AIF1 DAC1 Left Volume

#define R1026 0x0402
#define AIF1DAC1_LEFT_VOLUME_REG R1026

#define AIF1DAC1L_VU_bp     8
#define AIF1DAC1L_VOL_bp    0

#define AIF1DAC1L_VU_bm     (1<<AIF1DAC1L_VU_bp)
#define AIF1DAC1L_VOL_bm    (0xFF<<AIF1DAC1L_VOL_bp)

//Register R1027 - AIF1 DAC1 Right Volume

#define R1027 0x0403
#define AIF1DAC1_RIGHT_VOLUME_REG R1027

#define AIF1DAC1R_VU_bp     8
#define AIF1DAC1R_VOL_bp    0

#define AIF1DAC1R_VU_bm     (1<<AIF1DAC1R_VU_bp)
#define AIF1DAC1R_VOL_bm    (0xFF<<AIF1DAC1R_VOL_bp)

//Register R1028 - AIF1 ADC2 Left Volume

#define R1028 0x0404
#define AIF1ADC2_LEFT_VOLUME_REG R1028

#define AIF1ADC2L_VU_bp     8
#define AIF1ADC2L_VOL_bp    0

#define AIF1ADC2L_VU_bm     (1<<AIF1ADC2L_VU_bp)
#define AIF1ADC2L_VOL_bm    (0xFF<<AIF1ADC2L_VOL_bp)

//Register R1029 - AIF1 ADC2 Right Volume

#define R1029 0x0405
#define AIF1ADC2_RIGHT_VOLUME_REG R1029

#define AIF1ADC2R_VU_bp     8
#define AIF1ADC2R_VOL_bp    0

#define AIF1ADC2R_VU_bm     (1<<AIF1ADC2R_VU_bp)
#define AIF1ADC2R_VOL_bm    (0xFF<<AIF1ADC2R_VOL_bp)

//Register R1030 - AIF1 DAC2 Left Volume

#define R1030 0x0406
#define AIF1DAC2_LEFT_VOLUME_REG R1030

#define AIF1DAC2L_VU_bp     8
#define AIF1DAC2L_VOL_bp    0

#define AIF1DAC2L_VU_bm     (1<<AIF1DAC2L_VU_bp)
#define AIF1DAC2L_VOL_bm    (0xFF<<AIF1DAC2L_VOL_bp)

//Register R1031 - AIF1 DAC2 Right Volume

#define R1031 0x0407
#define AIF1DAC2_RIGHT_VOLUME_REG R1031

#define AIF1DAC2R_VU_bp     8
#define AIF1DAC2R_VOL_bp    0

#define AIF1DAC2R_VU_bm     (1<<AIF1DAC2R_VU_bp)
#define AIF1DAC2R_VOL_bm    (0xFF<<AIF1DAC2R_VOL_bp)

//Register R1040 - AIF1 ADC1 Filters

#define R1040 0x0410
#define AIF1ADC1_FILTERS_REG R1040

#define AIF1ADC_4FS_bp          15
#define AIF1ADC1_HPF_CUT_bp     13
#define AIF1ADC1L_HPF_bp        12
#define AIF1ADC1R_HPF_bp        11

#define AIF1ADC_4FS_bm          (1<<AIF1ADC_4FS_bp)
#define AIF1ADC1_HPF_CUT_bm     (3<<AIF1ADC1_HPF_CUT_bp)
#define AIF1ADC1L_HPF_bm        (1<<AIF1ADC1L_HPF_bp)
#define AIF1ADC1R_HPF_bm        (1<<AIF1ADC1R_HPF_bp)

#define AIF1ADC1_HPF_CUT_HIFI_MODE      0
#define AIF1ADC1_HPF_CUT_VOICE_MODE_1   1
#define AIF1ADC1_HPF_CUT_VOICE_MODE_2   2
#define AIF1ADC1_HPF_CUT_VOICE_MODE_3   3

//Register R1041 - AIF1 ADC2 Filters

#define R1041 0x0411
#define AIF1ADC2_FILTERS_REG R1041

#define AIF1ADC2_HPF_CUT_bp     13
#define AIF1ADC2L_HPF_bp        12
#define AIF1ADC2R_HPF_bp        11

#define AIF1ADC2_HPF_CUT_bm     (3<<AIF1ADC2_HPF_CUT_bp)
#define AIF1ADC2L_HPF_bm        (1<<AIF1ADC2L_HPF_bp)
#define AIF1ADC2R_HPF_bm        (1<<AIF1ADC2R_HPF_bp)

#define AIF1ADC2_HPF_CUT_HIFI_MODE      0
#define AIF1ADC2_HPF_CUT_VOICE_MODE_1   1
#define AIF1ADC2_HPF_CUT_VOICE_MODE_2   2
#define AIF1ADC2_HPF_CUT_VOICE_MODE_3   3

//Register R1056 - AIF1 DAC1 Filters (1)

#define R1056 0x0420
#define AIF1DAC1_FILTERS_1_REG R1056

#define AIF1DAC1_MUTE_bp            9
#define AIF1DAC1_MONO_bp            7
#define AIF1DAC1_MUTERATE_bp        5
#define AIF1DAC1_UNMUTE_RAMP_bp     4
#define AIF1DAC1_DEEMP_bp           1

#define AIF1DAC1_MUTE_bm            (1<<AIF1DAC1_MUTE_bp)
#define AIF1DAC1_MONO_bm            (1<<AIF1DAC1_MONO_bp)
#define AIF1DAC1_MUTERATE_bm        (1<<AIF1DAC1_MUTERATE_bp)
#define AIF1DAC1_UNMUTE_RAMP_bm     (1<<AIF1DAC1_UNMUTE_RAMP_bp)
#define AIF1DAC1_DEEMP_bm           (3<<AIF1DAC1_DEEMP)

#define AIF1DAC1_DEEMP_NO       0
#define AIF1DAC1_DEEMP_33KHZ    1
#define AIF1DAC1_DEEMP_44_1KHZ  2
#define AIF1DAC1_DEEMP_48KHZ    3

//Register R1057 - AIF1 DAC1 Filters (2)

#define R1057 0x0421
#define AIF1DAC1_FILTERS_2_REG R1057

#define AIF1DAC1_3D_GAIN_bp 9
#define AIF1DAC1_3D_ENA_bp  8

#define AIF1DAC1_3D_GAIN_bm (0x1F<<AIF1DAC1_3D_GAIN_bp)
#define AIF1DAC1_3D_ENA_bm  (1<<AIF1DAC1_3D_ENA_bp)

//Register R1058 - AIF1 DAC2 Filters (1)

#define R1058 0x0422
#define AIF1DAC2_FILTERS_1_REG R1058

#define AIF1DAC2_MUTE_bp            9
#define AIF1DAC2_MONO_bp            7
#define AIF1DAC2_MUTERATE_bp        5
#define AIF1DAC2_UNMUTE_RAMP_bp     4
#define AIF1DAC2_DEEMP_bp           1

#define AIF1DAC2_MUTE_bm            (1<<AIF1DAC2_MUTE_bp)
#define AIF1DAC2_MONO_bm            (1<<AIF1DAC2_MONO_bp)
#define AIF1DAC2_MUTERATE_bm        (1<<AIF1DAC2_MUTERATE_bp)
#define AIF1DAC2_UNMUTE_RAMP_bm     (1<<AIF1DAC2_UNMUTE_RAMP_bp)
#define AIF1DAC2_DEEMP_bm           (3<<AIF1DAC2_DEEMP)

#define AIF1DAC2_DEEMP_NO       0
#define AIF1DAC2_DEEMP_33KHZ    1
#define AIF1DAC2_DEEMP_44_1KHZ  2
#define AIF1DAC2_DEEMP_48KHZ    3

//Register R1059 - AIF1 DAC2 Filters (2)

#define R1059 0x0423
#define AIF1DAC2_FILTERS_2_REG R1059

#define AIF1DAC2_3D_GAIN_bp 9
#define AIF1DAC2_3D_ENA_bp  8

#define AIF1DAC2_3D_GAIN_bm (0x1F<<AIF1DAC2_3D_GAIN_bp)
#define AIF1DAC2_3D_ENA_bm  (1<<AIF1DAC2_3D_ENA_bp)

//Register R1088 - AIF1 DRC1 (1)

#define R1088 0x0440
#define AIF1DRC1_1_REG R1088

#define AIF1DRC1_SIG_DET_RMS_bp     11
#define AIF1DRC1_SIG_DET_PK_bp      9
#define AIF1DRC1_NG_ENA_bp          8
#define AIF1DRC1_SIG_DET_MODE_bp    7
#define AIF1DRC1_SIG_DET_bp         6
#define AIF1DRC1_KNEE2_OP_ENA_bp   5
#define AIF1DRC1_QR_bp              4
#define AIF1DRC1_ANTICLIP_bp        3
#define AIF1DAC1_DRC_ENA_bp         2
#define AIF1ADC1L_DRC_ENA_bp        1
#define AIF1ADC1R_DRC_ENA_bp        0

#define AIF1DRC1_SIG_DET_RMS_bm     (0x1F<<AIF1DRC1_SIG_DET_RMS_bp)
#define AIF1DRC1_SIG_DET_PK_bm      (3<<AIF1DRC1_SIG_DET_PK_bp)
#define AIF1DRC1_NG_ENA_bm          (1<<AIF1DRC1_NG_ENA_bp)
#define AIF1DRC1_SIG_DET_MODE_bm    (1<<AIF1DRC1_SIG_DET_MODE_bp)
#define AIF1DRC1_SIG_DET_bm         (1<<AIF1DRC1_SIG_DET_bp)
#define AIF1DRC1_KNEE2_OP_ENA_bm    (1<<AIF1DRC1_KNEE2_OP_ENA_bp)
#define AIF1DRC1_QR_bm              (1<<AIF1DRC1_QR_bp)
#define AIF1DRC1_ANTICLIP_bm        (1<<AIF1DRC1_ANTICLIP_bp)
#define AIF1DAC1_DRC_ENA_bm         (1<<AIF1DAC1_DRC_ENA_bp)
#define AIF1ADC1L_DRC_ENA_bm        (1<<AIF1ADC1L_DRC_ENA_bp)
#define AIF1ADC1R_DRC_ENA_bm        (1<<AIF1ADC1R_DRC_ENA_bp)

#define AIF1DRC1_SIG_DET_PK_12  0
#define AIF1DRC1_SIG_DET_PK_18  1
#define AIF1DRC1_SIG_DET_PK_24  2
#define AIF1DRC1_SIG_DET_PK_30  3

//Register R1089 - AIF1 DRC1 (2) 

#define R1089 0x0441
#define AIF1DRC1_2_REG R1089

#define AIF1DRC1_ATK_bp         9
#define AIF1DRC1_DCY_bp         5
#define AIF1DRC1_MINGAIN_bp     2
#define AIF1DRC1_MAXGAIN_bp     0

#define AIF1DRC1_ATK_bm         (0xF<<AIF1DRC1_ATK_bp)
#define AIF1DRC1_DCY_bm         (0xF<<AIF1DRC1_DCY_bp)
#define AIF1DRC1_MINGAIN_bm     (7<<AIF1DRC1_MINGAIN_bp)
#define AIF1DRC1_MAXGAIN_bm     (3<<AIF1DRC1_MAXGAIN_bp)

#define AIF1DRC1_ATK_181US      0x01
#define AIF1DRC1_ATK_363US      0x02
#define AIF1DRC1_ATK_726US      0x03
#define AIF1DRC1_ATK_1_45MS     0x04
#define AIF1DRC1_ATK_2_9MS      0x05
#define AIF1DRC1_ATK_5_8MS      0x06
#define AIF1DRC1_ATK_11_6MS     0x07
#define AIF1DRC1_ATK_23_2MS     0x08
#define AIF1DRC1_ATK_46_4MS     0x09
#define AIF1DRC1_ATK_92_8MS     0x0A
#define AIF1DRC1_ATK_185_6MS    0x0B

#define AIF1DRC1_DCY_186MS      0x00
#define AIF1DRC1_DCY_372MS      0x01
#define AIF1DRC1_DCY_743MS      0x02
#define AIF1DRC1_DCY_1_49S      0x03
#define AIF1DRC1_DCY_2_97S      0x04
#define AIF1DRC1_DCY_5_94S      0x05
#define AIF1DRC1_DCY_11_89S     0x06
#define AIF1DRC1_DCY_23_78S     0x07
#define AIF1DRC1_DCY_47_56S     0x08

#define AIF1DRC1_MINGAIN_0DB    0
#define AIF1DRC1_MINGAIN_12DB   1
#define AIF1DRC1_MINGAIN_18DB   2
#define AIF1DRC1_MINGAIN_24DB   3
#define AIF1DRC1_MINGAIN_36DB   4

#define AIF1DRC1_MAXGAIN_12DB   0
#define AIF1DRC1_MAXGAIN_18DB   1
#define AIF1DRC1_MAXGAIN_24DB   2
#define AIF1DRC1_MAXGAIN_36DB   3

//Register R1090 - AIF1 DRC1 (3)

#define R1090 0x0442
#define AIF1DRC1_3_REG R1090

#define AIF1DRC1_NG_MINGAIN_bp  12
#define AIF1DRC1_NG_EXP_bp      10
#define AIF1DRC1_QR_THR_bp      8
#define AIF1DRC1_QR_DCY_bp      6
#define AIF1DRC1_HICOMP_bp      3
#define AIF1DRC1_LOCOMP_bp      0

#define AIF1DRC1_NG_MINGAIN_bm  (0x0F<<AIF1DRC1_NG_MINGAIN_bp)
#define AIF1DRC1_NG_EXP_bm      (3<<AIF1DRC1_NG_EXP_bp)
#define AIF1DRC1_QR_THR_bm      (3<<AIF1DRC1_QR_THR_bp)
#define AIF1DRC1_QR_DCY_bm      (3<<AIF1DRC1_QR_DCY_bp)
#define AIF1DRC1_HICOMP_bm      (7<<AIF1DRC1_HICOMP_bp)
#define AIF1DRC1_LOCOMP_bm      (7<<AIF1DRC1_LOCOMP_bp)

#define AIF1DRC1_NG_MINGAIN_M36DB   0
#define AIF1DRC1_NG_MINGAIN_M30DB   1
#define AIF1DRC1_NG_MINGAIN_M24DB   2
#define AIF1DRC1_NG_MINGAIN_M18DB   3
#define AIF1DRC1_NG_MINGAIN_M12DB   4
#define AIF1DRC1_NG_MINGAIN_M6DB    5
#define AIF1DRC1_NG_MINGAIN_0DB     6
#define AIF1DRC1_NG_MINGAIN_6DB     7
#define AIF1DRC1_NG_MINGAIN_12DB    8
#define AIF1DRC1_NG_MINGAIN_18DB    9
#define AIF1DRC1_NG_MINGAIN_24DB    10
#define AIF1DRC1_NG_MINGAIN_30DB    11
#define AIF1DRC1_NG_MINGAIN_36DB    12

#define AIF1DRC1_NG_EXP_1   0
#define AIF1DRC1_NG_EXP_2   1
#define AIF1DRC1_NG_EXP_4   2
#define AIF1DRC1_NG_EXP_8   3

#define AIF1DRC1_QR_THR_12DB    0
#define AIF1DRC1_QR_THR_18DB    1
#define AIF1DRC1_QR_THR_24DB    2
#define AIF1DRC1_QR_THR_30DB    3

#define AIF1DRC1_QR_DCY_0_725MS 0
#define AIF1DRC1_QR_DCY_1_45MS  1
#define AIF1DRC1_QR_DCY_5_8MS   2

#define AIF1DRC1_HICOMP_1       0
#define AIF1DRC1_HICOMP_1_2     1
#define AIF1DRC1_HICOMP_1_4     2
#define AIF1DRC1_HICOMP_1_8     3
#define AIF1DRC1_HICOMP_1_16    4
#define AIF1DRC1_HICOMP_0       5

#define AIF1DRC1_LOCOMP_1       0
#define AIF1DRC1_LOCOMP_1_2     1
#define AIF1DRC1_LOCOMP_1_4     2
#define AIF1DRC1_LOCOMP_1_8     3
#define AIF1DRC1_LOCOMP_0       4

//Register R1091 - AIF1 DRC1 (4)

#define R1091 0x0443
#define AIF1DRC1_4_REG R1091

#define AIF1DRC1_KNEE_IP_bp     5
#define AIF1DRC1_KNEE_OP_bp     0

#define AIF1DRC1_KNEE_IP_bm     (0x3F<<AIF1DRC1_KNEE_IP_bp)
#define AIF1DRC1_KNEE_OP_bm     (0x1F<<AIF1DRC1_KNEE_OP_bp)

//Register R1092 - AIF1 DRC1 (5)

#define R1092 0x0444
#define AIF1DRC1_5_REG R1092

#define AIF1DRC1_KNEE2_IP_bp     5
#define AIF1DRC1_KNEE2_OP_bp     0

#define AIF1DRC1_KNEE2_IP_bm     (0x3F<<AIF1DRC1_KNEE2_IP_bp)
#define AIF1DRC1_KNEE2_OP_bm     (0x1F<<AIF1DRC1_KNEE2_OP_bp)

//Register R1104 - AIF1 DRC2 (1)

#define R1104 0x0450
#define AIF1DRC2_1_REG R1104

#define AIF1DRC2_SIG_DET_RMS_bp     11
#define AIF1DRC2_SIG_DET_PK_bp      9
#define AIF1DRC2_NG_ENA_bp          8
#define AIF1DRC2_SIG_DET_MODE_bp    7
#define AIF1DRC2_SIG_DET_bp         6
#define AIF1DRC2_KNEE2_OP_ENA_bp   5
#define AIF1DRC2_QR_bp              4
#define AIF1DRC2_ANTICLIP_bp        3
#define AIF1DAC2_DRC_ENA_bp         2
#define AIF1ADC2L_DRC_ENA_bp        1
#define AIF1ADC2R_DRC_ENA_bp        0

#define AIF1DRC2_SIG_DET_RMS_bm     (0x1F<<AIF1DRC2_SIG_DET_RMS_bp)
#define AIF1DRC2_SIG_DET_PK_bm      (3<<AIF1DRC2_SIG_DET_PK_bp)
#define AIF1DRC2_NG_ENA_bm          (1<<AIF1DRC2_NG_ENA_bp)
#define AIF1DRC2_SIG_DET_MODE_bm    (1<<AIF1DRC2_SIG_DET_MODE_bp)
#define AIF1DRC2_SIG_DET_bm         (1<<AIF1DRC2_SIG_DET_bp)
#define AIF1DRC2_KNEE2_OP_ENA_bm    (1<<AIF1DRC2_KNEE2_OP_ENA_bp)
#define AIF1DRC2_QR_bm              (1<<AIF1DRC2_QR_bp)
#define AIF1DRC2_ANTICLIP_bm        (1<<AIF1DRC2_ANTICLIP_bp)
#define AIF1DAC2_DRC_ENA_bm         (1<<AIF1DAC2_DRC_ENA_bp)
#define AIF1ADC2L_DRC_ENA_bm        (1<<AIF1ADC2L_DRC_ENA_bp)
#define AIF1ADC2R_DRC_ENA_bm        (1<<AIF1ADC2R_DRC_ENA_bp)

#define AIF1DRC2_SIG_DET_PK_12  0
#define AIF1DRC2_SIG_DET_PK_18  1
#define AIF1DRC2_SIG_DET_PK_24  2
#define AIF1DRC2_SIG_DET_PK_30  3

//Register R1105 - AIF1 DRC2 (2) 

#define R1105 0x0451
#define AIF1DRC2_2_REG R1105

#define AIF1DRC2_ATK_bp         9
#define AIF1DRC2_DCY_bp         5
#define AIF1DRC2_MINGAIN_bp     2
#define AIF1DRC2_MAXGAIN_bp     0

#define AIF1DRC2_ATK_bm         (0xF<<AIF1DRC2_ATK_bp)
#define AIF1DRC2_DCY_bm         (0xF<<AIF1DRC2_DCY_bp)
#define AIF1DRC2_MINGAIN_bm     (7<<AIF1DRC2_MINGAIN_bp)
#define AIF1DRC2_MAXGAIN_bm     (3<<AIF1DRC2_MAXGAIN_bp)

#define AIF1DRC2_ATK_181US      0x01
#define AIF1DRC2_ATK_363US      0x02
#define AIF1DRC2_ATK_726US      0x03
#define AIF1DRC2_ATK_1_45MS     0x04
#define AIF1DRC2_ATK_2_9MS      0x05
#define AIF1DRC2_ATK_5_8MS      0x06
#define AIF1DRC2_ATK_11_6MS     0x07
#define AIF1DRC2_ATK_23_2MS     0x08
#define AIF1DRC2_ATK_46_4MS     0x09
#define AIF1DRC2_ATK_92_8MS     0x0A
#define AIF1DRC2_ATK_185_6MS    0x0B

#define AIF1DRC2_DCY_186MS      0x00
#define AIF1DRC2_DCY_372MS      0x01
#define AIF1DRC2_DCY_743MS      0x02
#define AIF1DRC2_DCY_1_49S      0x03
#define AIF1DRC2_DCY_2_97S      0x04
#define AIF1DRC2_DCY_5_94S      0x05
#define AIF1DRC2_DCY_11_89S     0x06
#define AIF1DRC2_DCY_23_78S     0x07
#define AIF1DRC2_DCY_47_56S     0x08

#define AIF1DRC2_MINGAIN_0DB    0
#define AIF1DRC2_MINGAIN_12DB   1
#define AIF1DRC2_MINGAIN_18DB   2
#define AIF1DRC2_MINGAIN_24DB   3
#define AIF1DRC2_MINGAIN_36DB   4

#define AIF1DRC2_MAXGAIN_12DB   0
#define AIF1DRC2_MAXGAIN_18DB   1
#define AIF1DRC2_MAXGAIN_24DB   2
#define AIF1DRC2_MAXGAIN_36DB   3

//Register R1106 - AIF1 DRC2 (3)

#define R1106 0x0452
#define AIF1DRC2_3_REG R1106

#define AIF1DRC2_NG_MINGAIN_bp  12
#define AIF1DRC2_NG_EXP_bp      10
#define AIF1DRC2_QR_THR_bp      8
#define AIF1DRC2_QR_DCY_bp      6
#define AIF1DRC2_HICOMP_bp      3
#define AIF1DRC2_LOCOMP_bp      0

#define AIF1DRC2_NG_MINGAIN_bm  (0x0F<<AIF1DRC2_NG_MINGAIN_bp)
#define AIF1DRC2_NG_EXP_bm      (3<<AIF1DRC2_NG_EXP_bp)
#define AIF1DRC2_QR_THR_bm      (3<<AIF1DRC2_QR_THR_bp)
#define AIF1DRC2_QR_DCY_bm      (3<<AIF1DRC2_QR_DCY_bp)
#define AIF1DRC2_HICOMP_bm      (7<<AIF1DRC2_HICOMP_bp)
#define AIF1DRC2_LOCOMP_bm      (7<<AIF1DRC2_LOCOMP_bp)

#define AIF1DRC2_NG_MINGAIN_M36DB   0
#define AIF1DRC2_NG_MINGAIN_M30DB   1
#define AIF1DRC2_NG_MINGAIN_M24DB   2
#define AIF1DRC2_NG_MINGAIN_M18DB   3
#define AIF1DRC2_NG_MINGAIN_M12DB   4
#define AIF1DRC2_NG_MINGAIN_M6DB    5
#define AIF1DRC2_NG_MINGAIN_0DB     6
#define AIF1DRC2_NG_MINGAIN_6DB     7
#define AIF1DRC2_NG_MINGAIN_12DB    8
#define AIF1DRC2_NG_MINGAIN_18DB    9
#define AIF1DRC2_NG_MINGAIN_24DB    10
#define AIF1DRC2_NG_MINGAIN_30DB    11
#define AIF1DRC2_NG_MINGAIN_36DB    12

#define AIF1DRC2_NG_EXP_1   0
#define AIF1DRC2_NG_EXP_2   1
#define AIF1DRC2_NG_EXP_4   2
#define AIF1DRC2_NG_EXP_8   3

#define AIF1DRC2_QR_THR_12DB    0
#define AIF1DRC2_QR_THR_18DB    1
#define AIF1DRC2_QR_THR_24DB    2
#define AIF1DRC2_QR_THR_30DB    3

#define AIF1DRC2_QR_DCY_0_725MS 0
#define AIF1DRC2_QR_DCY_1_45MS  1
#define AIF1DRC2_QR_DCY_5_8MS   2

#define AIF1DRC2_HICOMP_1       0
#define AIF1DRC2_HICOMP_1_2     1
#define AIF1DRC2_HICOMP_1_4     2
#define AIF1DRC2_HICOMP_1_8     3
#define AIF1DRC2_HICOMP_1_16    4
#define AIF1DRC2_HICOMP_0       5

#define AIF1DRC2_LOCOMP_1       0
#define AIF1DRC2_LOCOMP_1_2     1
#define AIF1DRC2_LOCOMP_1_4     2
#define AIF1DRC2_LOCOMP_1_8     3
#define AIF1DRC2_LOCOMP_0       4

//Register R1107 - AIF1 DRC2 (4)

#define R1107 0x0453
#define AIF1DRC2_4_REG R1107

#define AIF1DRC2_KNEE_IP_bp     5
#define AIF1DRC2_KNEE_OP_bp     0

#define AIF1DRC2_KNEE_IP_bm     (0x3F<<AIF1DRC2_KNEE_IP_bp)
#define AIF1DRC2_KNEE_OP_bm     (0x1F<<AIF1DRC2_KNEE_OP_bp)

//Register R1108 - AIF1 DRC2 (5)

#define R1108 0x0454
#define AIF1DRC2_5_REG R1108

#define AIF1DRC2_KNEE2_IP_bp     5
#define AIF1DRC2_KNEE2_OP_bp     0

#define AIF1DRC2_KNEE2_IP_bm     (0x3F<<AIF1DRC2_KNEE2_IP_bp)
#define AIF1DRC2_KNEE2_OP_bm     (0x1F<<AIF1DRC2_KNEE2_OP_bp)

//Register R1152 - AIF1 DAC1 EQ Gains (1)

#define R1152 0x0480
#define AIF1DAC1_EQ_GAINS_1_REG R1152

#define AIF1DAC1_EQ_B1_GAIN_bp  11
#define AIF1DAC1_EQ_B2_GAIN_bp  6
#define AIF1DAC1_EQ_B3_GAIN_bp  1
#define AIF1DAC1_EQ_ENA_bp      0

#define AIF1DAC1_EQ_B1_GAIN_bm  (0x1F<<AIF1DAC1_EQ_B1_GAIN_bp)
#define AIF1DAC1_EQ_B2_GAIN_bm  (0x1F<<AIF1DAC1_EQ_B2_GAIN_bp)
#define AIF1DAC1_EQ_B3_GAIN_bm  (0x1F<<AIF1DAC1_EQ_B3_GAIN_bp)
#define AIF1DAC1_EQ_ENA_bm      (1<<AIF1DAC1_EQ_ENA_bp)

//Register R1153 - AIF1 DAC1 EQ Gains (2)

#define R1153 0x0481
#define AIF1DAC1_EQ_GAINS_2_REG R1153

#define AIF1DAC1_EQ_B4_GAIN_bp  11
#define AIF1DAC1_EQ_B5_GAIN_bp  6

#define AIF1DAC1_EQ_B4_GAIN_bm  (0x1F<<AIF1DAC1_EQ_B4_GAIN_bp)
#define AIF1DAC1_EQ_B5_GAIN_bm  (0x1F<<AIF1DAC1_EQ_B5_GAIN_bp)

//Register R1154 - AIF1 DAC1 EQ Band 1 A

#define R1154 0x0482
#define AIF1DAC1_EQ_B1_A_REG R1154

#define AIF1DAC1_EQ_B1_A_bp 0
#define AIF1DAC1_EQ_B1_A_bm 0xFFFF

//Register R1155 - AIF1 DAC1 EQ Band 1 B

#define R1155 0x0483
#define AIF1DAC1_EQ_B1_B_REG R1155

#define AIF1DAC1_EQ_B1_B_bp 0
#define AIF1DAC1_EQ_B1_B_bm 0xFFFF

//Register R1156 - AIF1 DAC1 EQ Band 1 PG

#define R1156 0x0484
#define AIF1DAC1_EQ_B1_PG_REG R1156

#define AIF1DAC1_EQ_B1_PG_bp 0
#define AIF1DAC1_EQ_B1_PG_bm 0xFFFF

//Register R1157 - AIF1 DAC1 EQ Band 2 A

#define R1157 0x0485
#define AIF1DAC1_EQ_B2_A_REG R1157

#define AIF1DAC1_EQ_B2_A_bp 0
#define AIF1DAC1_EQ_B2_A_bm 0xFFFF

//Register R1158 - AIF1 DAC1 EQ Band 2 B

#define R1158 0x0486
#define AIF1DAC1_EQ_B2_B_REG R1158

#define AIF1DAC1_EQ_B2_B_bp 0
#define AIF1DAC1_EQ_B2_B_bm 0xFFFF

//Register R1159 - AIF1 DAC1 EQ Band 2 C

#define R1159 0x0487
#define AIF1DAC1_EQ_B2_C_REG R1159

#define AIF1DAC1_EQ_B2_C_bp 0
#define AIF1DAC1_EQ_B2_C_bm 0xFFFF

//Register R1160 - AIF1 DAC1 EQ Band 2 PG

#define R1160 0x0488
#define AIF1DAC1_EQ_B2_PG_REG R1160

#define AIF1DAC1_EQ_B2_PG_bp 0
#define AIF1DAC1_EQ_B2_PG_bm 0xFFFF

//Register R1161 - AIF1 DAC1 EQ Band 3 A

#define R1161 0x0489
#define AIF1DAC1_EQ_B3_A_REG R1161

#define AIF1DAC1_EQ_B3_A_bp 0
#define AIF1DAC1_EQ_B3_A_bm 0xFFFF

//Register R1162 - AIF1 DAC1 EQ Band 3 B

#define R1162 0x048A
#define AIF1DAC1_EQ_B3_B_REG R1162

#define AIF1DAC1_EQ_B3_B_bp 0
#define AIF1DAC1_EQ_B3_B_bm 0xFFFF

//Register R1163 - AIF1 DAC1 EQ Band 3 C

#define R1163 0x048B
#define AIF1DAC1_EQ_B3_C_REG R1163

#define AIF1DAC1_EQ_B3_C_bp 0
#define AIF1DAC1_EQ_B3_C_bm 0xFFFF

//Register R1164 - AIF1 DAC1 EQ Band 3 PG

#define R1164 0x048C
#define AIF1DAC1_EQ_B3_PG_REG R1164

#define AIF1DAC1_EQ_B3_PG_bp 0
#define AIF1DAC1_EQ_B3_PG_bm 0xFFFF

//Register R1165 - AIF1 DAC1 EQ Band 4 A

#define R1165 0x048D
#define AIF1DAC1_EQ_B4_A_REG R1165

#define AIF1DAC1_EQ_B4_A_bp 0
#define AIF1DAC1_EQ_B4_A_bm 0xFFFF

//Register R1166 - AIF1 DAC1 EQ Band 4 B

#define R1166 0x048E
#define AIF1DAC1_EQ_B4_B_REG R1166

#define AIF1DAC1_EQ_B4_B_bp 0
#define AIF1DAC1_EQ_B4_B_bm 0xFFFF

//Register R1167 - AIF1 DAC1 EQ Band 4 C

#define R1167 0x048F
#define AIF1DAC1_EQ_B4_C_REG R1167

#define AIF1DAC1_EQ_B4_C_bp 0
#define AIF1DAC1_EQ_B4_C_bm 0xFFFF

//Register R1168 - AIF1 DAC1 EQ Band 4 PG

#define R1168 0x0490
#define AIF1DAC1_EQ_B4_PG_REG R1168

#define AIF1DAC1_EQ_B4_PG_bp 0
#define AIF1DAC1_EQ_B4_PG_bm 0xFFFF

//Register R1169 - AIF1 DAC1 EQ Band 5 A

#define R1169 0x0491
#define AIF1DAC1_EQ_B5_A_REG R1169

#define AIF1DAC1_EQ_B5_A_bp 0
#define AIF1DAC1_EQ_B5_A_bm 0xFFFF

//Register R1170 - AIF1 DAC1 EQ Band 5 B

#define R1170 0x0492
#define AIF1DAC1_EQ_B5_B_REG R1170

#define AIF1DAC1_EQ_B5_B_bp 0
#define AIF1DAC1_EQ_B5_B_bm 0xFFFF

//Register R1171 - AIF1 DAC1 EQ Band 5 PG

#define R1171 0x0493
#define AIF1DAC1_EQ_B5_PG_REG R1171

#define AIF1DAC1_EQ_B5_PG_bp 0
#define AIF1DAC1_EQ_B5_PG_bm 0xFFFF

//Register R1184 - AIF1 DAC2 EQ Gains (1)

#define R1184 0x04A0
#define AIF1DAC2_EQ_GAINS_1_REG R1184

#define AIF1DAC2_EQ_B1_GAIN_bp  11
#define AIF1DAC2_EQ_B2_GAIN_bp  6
#define AIF1DAC2_EQ_B3_GAIN_bp  1
#define AIF1DAC2_EQ_ENA_bp      0

#define AIF1DAC2_EQ_B1_GAIN_bm  (0x1F<<AIF1DAC2_EQ_B1_GAIN_bp)
#define AIF1DAC2_EQ_B2_GAIN_bm  (0x1F<<AIF1DAC2_EQ_B2_GAIN_bp)
#define AIF1DAC2_EQ_B3_GAIN_bm  (0x1F<<AIF1DAC2_EQ_B3_GAIN_bp)
#define AIF1DAC2_EQ_ENA_bm      (1<<AIF1DAC2_EQ_ENA_bp)

//Register R1185 - AIF1 DAC2 EQ Gains (2)

#define R1185 0x04A1
#define AIF1DAC2_EQ_GAINS_2_REG R1185

#define AIF1DAC2_EQ_B4_GAIN_bp  11
#define AIF1DAC2_EQ_B5_GAIN_bp  6

#define AIF1DAC2_EQ_B4_GAIN_bm  (0x1F<<AIF1DAC2_EQ_B4_GAIN_bp)
#define AIF1DAC2_EQ_B5_GAIN_bm  (0x1F<<AIF1DAC2_EQ_B5_GAIN_bp)

//Register R1186 - AIF1 DAC2 EQ Band 1 A

#define R1186 0x04A2
#define AIF1DAC2_EQ_B1_A_REG R1186

#define AIF1DAC2_EQ_B1_A_bp 0
#define AIF1DAC2_EQ_B1_A_bm 0xFFFF

//Register R1187 - AIF1 DAC2 EQ Band 1 B

#define R1187 0x04A3
#define AIF1DAC2_EQ_B1_B_REG R1187

#define AIF1DAC2_EQ_B1_B_bp 0
#define AIF1DAC2_EQ_B1_B_bm 0xFFFF

//Register R1188 - AIF1 DAC2 EQ Band 1 PG

#define R1188 0x04A4
#define AIF1DAC2_EQ_B1_PG_REG R1188

#define AIF1DAC2_EQ_B1_PG_bp 0
#define AIF1DAC2_EQ_B1_PG_bm 0xFFFF

//Register R1189 - AIF1 DAC2 EQ Band 2 A

#define R1189 0x04A5
#define AIF1DAC2_EQ_B2_A_REG R1189

#define AIF1DAC2_EQ_B2_A_bp 0
#define AIF1DAC2_EQ_B2_A_bm 0xFFFF

//Register R1190 - AIF1 DAC2 EQ Band 2 B

#define R1190 0x04A6
#define AIF1DAC2_EQ_B2_B_REG R1190

#define AIF1DAC2_EQ_B2_B_bp 0
#define AIF1DAC2_EQ_B2_B_bm 0xFFFF

//Register R1191 - AIF1 DAC2 EQ Band 2 C

#define R1191 0x04A7
#define AIF1DAC2_EQ_B2_C_REG R1191

#define AIF1DAC2_EQ_B2_C_bp 0
#define AIF1DAC2_EQ_B2_C_bm 0xFFFF

//Register R1192 - AIF1 DAC2 EQ Band 2 PG

#define R1192 0x04A8
#define AIF1DAC2_EQ_B2_PG_REG R1192

#define AIF1DAC2_EQ_B2_PG_bp 0
#define AIF1DAC2_EQ_B2_PG_bm 0xFFFF

//Register R1193 - AIF1 DAC2 EQ Band 3 A

#define R1193 0x04A9
#define AIF1DAC2_EQ_B3_A_REG R1193

#define AIF1DAC2_EQ_B3_A_bp 0
#define AIF1DAC2_EQ_B3_A_bm 0xFFFF

//Register R1194 - AIF1 DAC2 EQ Band 3 B

#define R1194 0x04AA
#define AIF1DAC2_EQ_B3_B_REG R1194

#define AIF1DAC2_EQ_B3_B_bp 0
#define AIF1DAC2_EQ_B3_B_bm 0xFFFF

//Register R1195 - AIF1 DAC2 EQ Band 3 C

#define R1195 0x04AB
#define AIF1DAC2_EQ_B3_C_REG R1195

#define AIF1DAC2_EQ_B3_C_bp 0
#define AIF1DAC2_EQ_B3_C_bm 0xFFFF

//Register R1196 - AIF1 DAC2 EQ Band 3 PG

#define R1196 0x04AC
#define AIF1DAC2_EQ_B3_PG_REG R1196

#define AIF1DAC2_EQ_B3_PG_bp 0
#define AIF1DAC2_EQ_B3_PG_bm 0xFFFF

//Register R1197 - AIF1 DAC2 EQ Band 4 A

#define R1197 0x04AD
#define AIF1DAC2_EQ_B4_A_REG R1197

#define AIF1DAC2_EQ_B4_A_bp 0
#define AIF1DAC2_EQ_B4_A_bm 0xFFFF

//Register R1198 - AIF1 DAC2 EQ Band 4 B

#define R1198 0x04AE
#define AIF1DAC2_EQ_B4_B_REG R1198

#define AIF1DAC2_EQ_B4_B_bp 0
#define AIF1DAC2_EQ_B4_B_bm 0xFFFF

//Register R1199 - AIF1 DAC2 EQ Band 4 C

#define R1199 0x04AF
#define AIF1DAC2_EQ_B4_C_REG R1199

#define AIF1DAC2_EQ_B4_C_bp 0
#define AIF1DAC2_EQ_B4_C_bm 0xFFFF

//Register R1200 - AIF1 DAC2 EQ Band 4 PG

#define R1200 0x04B0
#define AIF1DAC2_EQ_B4_PG_REG R1200

#define AIF1DAC2_EQ_B4_PG_bp 0
#define AIF1DAC2_EQ_B4_PG_bm 0xFFFF

//Register R1201 - AIF1 DAC2 EQ Band 5 A

#define R1201 0x04B1
#define AIF1DAC2_EQ_B5_A_REG R1201

#define AIF1DAC2_EQ_B5_A_bp 0
#define AIF1DAC2_EQ_B5_A_bm 0xFFFF

//Register R1202 - AIF1 DAC2 EQ Band 5 B

#define R1202 0x04B2
#define AIF1DAC2_EQ_B5_B_REG R1202

#define AIF1DAC2_EQ_B5_B_bp 0
#define AIF1DAC2_EQ_B5_B_bm 0xFFFF

//Register R1203 - AIF1 DAC2 EQ Band 5 PG

#define R1203 0x04B3
#define AIF1DAC2_EQ_B5_PG_REG R1203

#define AIF1DAC2_EQ_B5_PG_bp 0
#define AIF1DAC2_EQ_B5_PG_bm 0xFFFF

//Register R1280 - AIF2 ADC Left

#define R1280 0x0500
#define AIF2ADC_LEFT_REG R1280

#define AIF2ADCL_VU_bp      8   
#define AIF2ADCL_VOL_bp     0

#define AIF2ADCL_VU_bm      (1<<AIF2ADCL_VU_bp)   
#define AIF2ADCL_VOL_bm     (0xFF<<AIF2ADCL_VOL_bp)

//Register R1281 - AIF2 DAC Right

#define R1281 0x0501
#define AIF2DAC_RIGHT_REG R1281

#define AIF2ADCR_VU_bp      8   
#define AIF2ADCR_VOL_bp     0

#define AIF2ADCR_VU_bm      (1<<AIF2ADCR_VU_bp)   
#define AIF2ADCR_VOL_bm     (0xFF<<AIF2ADCR_VOL_bp)

//Register R1282 - AIF2 DAC Left

#define R1282 0x0502
#define AIF2DAC_LEFT_REG R1282

#define AIF2DACL_VU_bp      8   
#define AIF2DACL_VOL_bp     0

#define AIF2DACL_VU_bm      (1<<AIF2DACL_VU_bp)   
#define AIF2DACL_VOL_bm     (0xFF<<AIF2DACL_VOL_bp)

//Register R1283 - AIF2 ADC Right

#define R1283 0x0503
#define AIF2ADC_RIGHT_REG R1283

#define AIF2DACR_VU_bp      8   
#define AIF2DACR_VOL_bp     0

#define AIF2DACR_VU_bm      (1<<AIF2DACR_VU_bp)   
#define AIF2DACR_VOL_bm     (0xFF<<AIF2DACR_VOL_bp)

//Register R1296 - AIF2 ADC Filters 

#define R1296 0x0510
#define AIF2ADC_FILTERS_REG R1296

#define AIF2ADC_HPF_CUT_bp  13
#define AIF2ADCL_HPF_bp     12
#define AIF2ADCR_HPF_bp     11

#define AIF2ADC_HPF_CUT_bm  (3<<AIF2ADC_HPF_CUT_bp)
#define AIF2ADCL_HPF_bm     (1<<AIF2ADCL_HPF_bp)
#define AIF2ADCR_HPF_bm     (1<<AIF2ADCR_HPF_bp)

//Register R1312 - AIF2 DAC Filters (1)

#define R1312 0x0520
#define AIF2DAC_FILTERS_1_REG R1312

#define AIF2DAC_MUTE_bp         9
#define AIF2DAC_MONO_bp         7
#define AIF2DAC_MUTERATE_bp     5
#define AIF2DAC_UNMUTE_RAMP_bp  4
#define AIF2DAC_DEEMP_bp        1

#define AIF2DAC_MUTE_bm         (1<<AIF2DAC_MUTE_bp)
#define AIF2DAC_MONO_bm         (1<<AIF2DAC_MONO_bp)
#define AIF2DAC_MUTERATE_bm     (1<<AIF2DAC_MUTERATE_bp)
#define AIF2DAC_UNMUTE_RAMP_bm  (1<<AIF2DAC_UNMUTE_RAMP_bp)
#define AIF2DAC_DEEMP_bm        (3<<AIF2DAC_DEEMP_bp)

#define AIF2DAC_DEEMP_NO       0
#define AIF2DAC_DEEMP_33KHZ    1
#define AIF2DAC_DEEMP_44_1KHZ  2
#define AIF2DAC_DEEMP_48KHZ    3

//Register R1313 - AIF2 DAC Filters (2)

#define R1313 0x0521
#define AIF2DAC_FILTERS_2_REG R1313

#define AIF2DAC_3D_GAIN_bp 9
#define AIF2DAC_3D_ENA_bp  8

#define AIF2DAC_3D_GAIN_bm (0x1F<<AIF2DAC_3D_GAIN_bp)
#define AIF2DAC_3D_ENA_bm  (1<<AIF2DAC_3D_ENA_bp)

//Register R1344 - AIF2 DRC (1)

#define R1344 0x0540
#define AIF2DRC_1_REG R1344

#define AIF2DRC_SIG_DET_RMS_bp     11
#define AIF2DRC_SIG_DET_PK_bp      9
#define AIF2DRC_NG_ENA_bp          8
#define AIF2DRC_SIG_DET_MODE_bp    7
#define AIF2DRC_SIG_DET_bp         6
#define AIF2DRC_KNEE2_OP_ENA_bp    5
#define AIF2DRC_QR_bp              4
#define AIF2DRC_ANTICLIP_bp        3
#define AIF2DAC_DRC_ENA_bp         2
#define AIF2ADCL_DRC_ENA_bp        1
#define AIF2ADCR_DRC_ENA_bp        0

#define AIF2DRC_SIG_DET_RMS_bm     (0x1F<<AIF2DRC_SIG_DET_RMS_bp)
#define AIF2DRC_SIG_DET_PK_bm      (3<<AIF2DRC_SIG_DET_PK_bp)
#define AIF2DRC_NG_ENA_bm          (1<<AIF2DRC_NG_ENA_bp)
#define AIF2DRC_SIG_DET_MODE_bm    (1<<AIF2DRC_SIG_DET_MODE_bp)
#define AIF2DRC_SIG_DET_bm         (1<<AIF2DRC_SIG_DET_bp)
#define AIF2DRC_KNEE2_OP_ENA_bm    (1<<AIF2DRC_KNEE2_OP_ENA_bp)
#define AIF2DRC_QR_bm              (1<<AIF2DRC_QR_bp)
#define AIF2DRC_ANTICLIP_bm        (1<<AIF2DRC_ANTICLIP_bp)
#define AIF2DAC_DRC_ENA_bm         (1<<AIF2DAC_DRC_ENA_bp)
#define AIF2ADCL_DRC_ENA_bm        (1<<AIF2ADCL_DRC_ENA_bp)
#define AIF2ADCR_DRC_ENA_bm        (1<<AIF2ADCR_DRC_ENA_bp)

#define AIF2DRC_SIG_DET_PK_12  0
#define AIF2DRC_SIG_DET_PK_18  1
#define AIF2DRC_SIG_DET_PK_24  2
#define AIF2DRC_SIG_DET_PK_30  3

//Register R1345 - AIF2 DRC (2) 

#define R1345 0x0541
#define AIF2DRC_2_REG R1345

#define AIF2DRC_ATK_bp         9
#define AIF2DRC_DCY_bp         5
#define AIF2DRC_MINGAIN_bp     2
#define AIF2DRC_MAXGAIN_bp     0

#define AIF2DRC_ATK_bm         (0xF<<AIF2DRC_ATK_bp)
#define AIF2DRC_DCY_bm         (0xF<<AIF2DRC_DCY_bp)
#define AIF2DRC_MINGAIN_bm     (7<<AIF2DRC_MINGAIN_bp)
#define AIF2DRC_MAXGAIN_bm     (3<<AIF2DRC_MAXGAIN_bp)

#define AIF2DRC_ATK_181US      0x01
#define AIF2DRC_ATK_363US      0x02
#define AIF2DRC_ATK_726US      0x03
#define AIF2DRC_ATK_1_45MS     0x04
#define AIF2DRC_ATK_2_9MS      0x05
#define AIF2DRC_ATK_5_8MS      0x06
#define AIF2DRC_ATK_11_6MS     0x07
#define AIF2DRC_ATK_23_2MS     0x08
#define AIF2DRC_ATK_46_4MS     0x09
#define AIF2DRC_ATK_92_8MS     0x0A
#define AIF2DRC_ATK_185_6MS    0x0B

#define AIF2DRC_DCY_186MS      0x00
#define AIF2DRC_DCY_372MS      0x01
#define AIF2DRC_DCY_743MS      0x02
#define AIF2DRC_DCY_1_49S      0x03
#define AIF2DRC_DCY_2_97S      0x04
#define AIF2DRC_DCY_5_94S      0x05
#define AIF2DRC_DCY_11_89S     0x06
#define AIF2DRC_DCY_23_78S     0x07
#define AIF2DRC_DCY_47_56S     0x08

#define AIF2DRC_MINGAIN_0DB    0
#define AIF2DRC_MINGAIN_12DB   1
#define AIF2DRC_MINGAIN_18DB   2
#define AIF2DRC_MINGAIN_24DB   3
#define AIF2DRC_MINGAIN_36DB   4

#define AIF2DRC_MAXGAIN_12DB   0
#define AIF2DRC_MAXGAIN_18DB   1
#define AIF2DRC_MAXGAIN_24DB   2
#define AIF2DRC_MAXGAIN_36DB   3

//Register R1346 - AIF2 DRC (3)

#define R1346 0x0542
#define AIF2DRC_3_REG R1346

#define AIF2DRC_NG_MINGAIN_bp  12
#define AIF2DRC_NG_EXP_bp      10
#define AIF2DRC_QR_THR_bp      8
#define AIF2DRC_QR_DCY_bp      6
#define AIF2DRC_HICOMP_bp      3
#define AIF2DRC_LOCOMP_bp      0

#define AIF2DRC_NG_MINGAIN_bm  (0x0F<<AIF2DRC_NG_MINGAIN_bp)
#define AIF2DRC_NG_EXP_bm      (3<<AIF2DRC_NG_EXP_bp)
#define AIF2DRC_QR_THR_bm      (3<<AIF2DRC_QR_THR_bp)
#define AIF2DRC_QR_DCY_bm      (3<<AIF2DRC_QR_DCY_bp)
#define AIF2DRC_HICOMP_bm      (7<<AIF2DRC_HICOMP_bp)
#define AIF2DRC_LOCOMP_bm      (7<<AIF2DRC_LOCOMP_bp)

#define AIF2DRC_NG_MINGAIN_M36DB   0
#define AIF2DRC_NG_MINGAIN_M30DB   1
#define AIF2DRC_NG_MINGAIN_M24DB   2
#define AIF2DRC_NG_MINGAIN_M18DB   3
#define AIF2DRC_NG_MINGAIN_M12DB   4
#define AIF2DRC_NG_MINGAIN_M6DB    5
#define AIF2DRC_NG_MINGAIN_0DB     6
#define AIF2DRC_NG_MINGAIN_6DB     7
#define AIF2DRC_NG_MINGAIN_12DB    8
#define AIF2DRC_NG_MINGAIN_18DB    9
#define AIF2DRC_NG_MINGAIN_24DB    10
#define AIF2DRC_NG_MINGAIN_30DB    11
#define AIF2DRC_NG_MINGAIN_36DB    12

#define AIF2DRC_NG_EXP_1   0
#define AIF2DRC_NG_EXP_2   1
#define AIF2DRC_NG_EXP_4   2
#define AIF2DRC_NG_EXP_8   3

#define AIF2DRC_QR_THR_12DB    0
#define AIF2DRC_QR_THR_18DB    1
#define AIF2DRC_QR_THR_24DB    2
#define AIF2DRC_QR_THR_30DB    3

#define AIF2DRC_QR_DCY_0_725MS 0
#define AIF2DRC_QR_DCY_1_45MS  1
#define AIF2DRC_QR_DCY_5_8MS   2

#define AIF2DRC_HICOMP_1       0
#define AIF2DRC_HICOMP_1_2     1
#define AIF2DRC_HICOMP_1_4     2
#define AIF2DRC_HICOMP_1_8     3
#define AIF2DRC_HICOMP_1_16    4
#define AIF2DRC_HICOMP_0       5

#define AIF2DRC_LOCOMP_1       0
#define AIF2DRC_LOCOMP_1_2     1
#define AIF2DRC_LOCOMP_1_4     2
#define AIF2DRC_LOCOMP_1_8     3
#define AIF2DRC_LOCOMP_0       4

//Register R1347 - AIF2 DRC (4)

#define R1347 0x0543
#define AIF2DRC_4_REG R1347

#define AIF2DRC_KNEE_IP_bp     5
#define AIF2DRC_KNEE_OP_bp     0

#define AIF2DRC_KNEE_IP_bm     (0x3F<<AIF2DRC_KNEE_IP_bp)
#define AIF2DRC_KNEE_OP_bm     (0x1F<<AIF2DRC_KNEE_OP_bp)

//Register R1348 - AIF2 DRC (5)

#define R1348 0x0544
#define AIF2DRC_5_REG R1348

#define AIF2DRC_KNEE2_IP_bp     5
#define AIF2DRC_KNEE2_OP_bp     0

#define AIF2DRC_KNEE2_IP_bm     (0x3F<<AIF2DRC_KNEE2_IP_bp)
#define AIF2DRC_KNEE2_OP_bm     (0x1F<<AIF2DRC_KNEE2_OP_bp)

//Register R1408 - AIF2 DAC EQ Gains (1)

#define R1408 0x0580
#define AIF2DAC_EQ_GAINS_1_REG R1408

#define AIF2DAC_EQ_B1_GAIN_bp  11
#define AIF2DAC_EQ_B2_GAIN_bp  6
#define AIF2DAC_EQ_B3_GAIN_bp  1
#define AIF2DAC_EQ_ENA_bp      0

#define AIF2DAC_EQ_B1_GAIN_bm  (0x1F<<AIF2DAC_EQ_B1_GAIN_bp)
#define AIF2DAC_EQ_B2_GAIN_bm  (0x1F<<AIF2DAC_EQ_B2_GAIN_bp)
#define AIF2DAC_EQ_B3_GAIN_bm  (0x1F<<AIF2DAC_EQ_B3_GAIN_bp)
#define AIF2DAC_EQ_ENA_bm      (1<<AIF2DAC_EQ_ENA_bp)

//Register R1409 - AIF2 DAC EQ Gains (2)

#define R1409 0x0581
#define AIF2DAC_EQ_GAINS_2_REG R1409

#define AIF2DAC_EQ_B4_GAIN_bp  11
#define AIF2DAC_EQ_B5_GAIN_bp  6

#define AIF2DAC_EQ_B4_GAIN_bm  (0x1F<<AIF2DAC_EQ_B4_GAIN_bp)
#define AIF2DAC_EQ_B5_GAIN_bm  (0x1F<<AIF2DAC_EQ_B5_GAIN_bp)

//Register R1410 - AIF2 DAC EQ Band 1 A

#define R1410 0x0582
#define AIF2DAC_EQ_B1_A_REG R1410

#define AIF2DAC_EQ_B1_A_bp 0
#define AIF2DAC_EQ_B1_A_bm 0xFFFF

//Register R1411 - AIF2 DAC EQ Band 1 B

#define R1411 0x0583
#define AIF2DAC_EQ_B1_B_REG R1411

#define AIF2DAC_EQ_B1_B_bp 0
#define AIF2DAC_EQ_B1_B_bm 0xFFFF

//Register R1412 - AIF2 DAC EQ Band 1 PG

#define R1412 0x0584
#define AIF2DAC_EQ_B1_PG_REG R1412

#define AIF2DAC_EQ_B1_PG_bp 0
#define AIF2DAC_EQ_B1_PG_bm 0xFFFF

//Register R1413 - AIF2 DAC EQ Band 2 A

#define R1413 0x0585
#define AIF2DAC_EQ_B2_A_REG R1413

#define AIF2DAC_EQ_B2_A_bp 0
#define AIF2DAC_EQ_B2_A_bm 0xFFFF

//Register R1414 - AIF2 DAC EQ Band 2 B

#define R1414 0x0586
#define AIF2DAC_EQ_B2_B_REG R1414

#define AIF2DAC_EQ_B2_B_bp 0
#define AIF2DAC_EQ_B2_B_bm 0xFFFF

//Register R1415 - AIF2 DAC EQ Band 2 C

#define R1415 0x0587
#define AIF2DAC_EQ_B2_C_REG R1415

#define AIF2DAC_EQ_B2_C_bp 0
#define AIF2DAC_EQ_B2_C_bm 0xFFFF

//Register R1416 - AIF2 DAC EQ Band 2 PG

#define R1416 0x0588
#define AIF2DAC_EQ_B2_PG_REG R1416

#define AIF2DAC_EQ_B2_PG_bp 0
#define AIF2DAC_EQ_B2_PG_bm 0xFFFF

//Register R1417 - AIF2 DAC EQ Band 3 A

#define R1417 0x0589
#define AIF2DAC_EQ_B3_A_REG R1417

#define AIF2DAC_EQ_B3_A_bp 0
#define AIF2DAC_EQ_B3_A_bm 0xFFFF

//Register R1418 - AIF2 DAC EQ Band 3 B

#define R1418 0x058A
#define AIF2DAC_EQ_B3_B_REG R1418

#define AIF2DAC_EQ_B3_B_bp 0
#define AIF2DAC_EQ_B3_B_bm 0xFFFF

//Register R1419 - AIF2 DAC EQ Band 3 C

#define R1419 0x058B
#define AIF2DAC_EQ_B3_C_REG R1419

#define AIF2DAC_EQ_B3_C_bp 0
#define AIF2DAC_EQ_B3_C_bm 0xFFFF

//Register R1420 - AIF2 DAC EQ Band 3 PG

#define R1420 0x058C
#define AIF2DAC_EQ_B3_PG_REG R1420

#define AIF2DAC_EQ_B3_PG_bp 0
#define AIF2DAC_EQ_B3_PG_bm 0xFFFF

//Register R1421 - AIF2 DAC EQ Band 4 A

#define R1421 0x058D
#define AIF2DAC_EQ_B4_A_REG R1421

#define AIF2DAC_EQ_B4_A_bp 0
#define AIF2DAC_EQ_B4_A_bm 0xFFFF

//Register R1422 - AIF2 DAC EQ Band 4 B

#define R1422 0x058E
#define AIF2DAC_EQ_B4_B_REG R1422

#define AIF2DAC_EQ_B4_B_bp 0
#define AIF2DAC_EQ_B4_B_bm 0xFFFF

//Register R1423 - AIF2 DAC EQ Band 4 C

#define R1423 0x058F
#define AIF2DAC_EQ_B4_C_REG R1423

#define AIF2DAC_EQ_B4_C_bp 0
#define AIF2DAC_EQ_B4_C_bm 0xFFFF

//Register R1424 - AIF2 DAC EQ Band 4 PG

#define R1424 0x0590
#define AIF2DAC_EQ_B4_PG_REG R1424

#define AIF2DAC_EQ_B4_PG_bp 0
#define AIF2DAC_EQ_B4_PG_bm 0xFFFF

//Register R1425 - AIF2 DAC EQ Band 5 A

#define R1425 0x0591
#define AIF2DAC_EQ_B5_A_REG R1425

#define AIF2DAC_EQ_B5_A_bp 0
#define AIF2DAC_EQ_B5_A_bm 0xFFFF

//Register R1426 - AIF2 DAC EQ Band 5 B

#define R1426 0x0592
#define AIF2DAC_EQ_B5_B_REG R1426

#define AIF2DAC_EQ_B5_B_bp 0
#define AIF2DAC_EQ_B5_B_bm 0xFFFF

//Register R1427 - AIF2 DAC EQ Band 5 PG

#define R1427 0x0593
#define AIF2DAC_EQ_B5_PG_REG R1427

#define AIF2DAC_EQ_B5_PG_bp 0
#define AIF2DAC_EQ_B5_PG_bm 0xFFFF

//Register R1536 - DAC1 Mixer

#define R1536 0x0600
#define DAC1_MIXER_REG R1536

#define ADCR_DAC1_VOL_bp    5
#define ADCL_DAC1_VOL_bp    0

#define ADCL_DAC1_VOL_bm    (0x0F<<ADCL_DAC1_VOL_bp)
#define ADCR_DAC1_VOL_bm    (0x0F<<ADCR_DAC1_VOL_bp)

//Register R1537 - DAC1 Left Mixer Routing

#define R1537 0x0601
#define DAC1_LEFT_MIXER_ROUTING_REG R1537

#define ADCR_TO_DAC1L_bp        5
#define ADCL_TO_DAC1L_bp        4
#define AIF2DACL_TO_DAC1L_bp    2
#define AIF1DAC2L_TO_DAC1L_bp   1
#define AIF1DAC1L_TO_DAC1L_bp   0

#define ADCR_TO_DAC1L_bm        (1<<ADCR_TO_DAC1L_bp)
#define ADCL_TO_DAC1L_bm        (1<<ADCL_TO_DAC1L_bp)
#define AIF2DACL_TO_DAC1L_bm    (1<<AIF2DACL_TO_DAC1L_bp)
#define AIF1DAC2L_TO_DAC1L_bm   (1<<AIF1DAC2L_TO_DAC1L_bp)
#define AIF1DAC1L_TO_DAC1L_bm   (1<<AIF1DAC1L_TO_DAC1L_bp)

//Register R1538 - DAC1 Right Mixer Routing

#define R1538 0x0602
#define DAC1_RIGHT_MIXER_ROUTING_REG R1538

#define ADCR_TO_DAC1R_bp        5
#define ADCL_TO_DAC1R_bp        4
#define AIF2DACR_TO_DAC1R_bp    2
#define AIF1DAC2R_TO_DAC1R_bp   1
#define AIF1DAC1R_TO_DAC1R_bp   0

#define ADCR_TO_DAC1R_bm        (1<<ADCR_TO_DAC1R_bp)
#define ADCL_TO_DAC1R_bm        (1<<ADCL_TO_DAC1R_bp)
#define AIF2DACR_TO_DAC1R_bm    (1<<AIF2DACR_TO_DAC1R_bp)
#define AIF1DAC2R_TO_DAC1R_bm   (1<<AIF1DAC2R_TO_DAC1R_bp)
#define AIF1DAC1R_TO_DAC1R_bm   (1<<AIF1DAC1R_TO_DAC1R_bp)

//Register R1539 - DAC2 Mixer Volumes

#define R1539 0x0603
#define DAC2_MIXER_VOLUMES_REG R1539

#define ADCR_DAC2_VOL_bp    5
#define ADCL_DAC2_VOL_bp    0

#define ADCR_DAC2_VOL_bm    (0x0F<<ADCR_DAC2_VOL_bp)
#define ADCL_DAC2_VOL_bm    (0x0F<<ADCL_DAC2_VOL_bp)

//Register R1540 - DAC2 Left Mixer Routing

#define R1540 0x0604
#define DAC2_LEFT_MIXER_ROUTING_REG R1540

#define ADCR_TO_DAC2L_bp        5
#define ADCL_TO_DAC2L_bp        4
#define AIF2DACL_TO_DAC2L_bp    2
#define AIF1DAC2L_TO_DAC2L_bp   1
#define AIF1DAC1L_TO_DAC2L_bp   0

#define ADCR_TO_DAC2L_bm        (1<<ADCR_TO_DAC2L_bp)
#define ADCL_TO_DAC2L_bm        (1<<ADCL_TO_DAC2L_bp)
#define AIF2DACL_TO_DAC2L_bm    (1<<AIF2DACL_TO_DAC2L_bp)
#define AIF1DAC2L_TO_DAC2L_bm   (1<<AIF1DAC2L_TO_DAC2L_bp)
#define AIF1DAC1L_TO_DAC2L_bm   (1<<AIF1DAC1L_TO_DAC2L_bp)

//Register R1541 - DAC2 Right Mixer Routing

#define R1541 0x0605
#define DAC2_RIGHT_MIXER_ROUTING_REG R1541

#define ADCR_TO_DAC2R_bp        5
#define ADCL_TO_DAC2R_bp        4
#define AIF2DACR_TO_DAC2R_bp    2
#define AIF1DAC2R_TO_DAC2R_bp   1
#define AIF1DAC1R_TO_DAC2R_bp   0

#define ADCR_TO_DAC2R_bm        (1<<ADCR_TO_DAC2R_bp)
#define ADCL_TO_DAC2R_bm        (1<<ADCL_TO_DAC2R_bp)
#define AIF2DACR_TO_DAC2R_bm    (1<<AIF2DACR_TO_DAC2R_bp)
#define AIF1DAC2R_TO_DAC2R_bm   (1<<AIF1DAC2R_TO_DAC2R_bp)
#define AIF1DAC1R_TO_DAC2R_bm   (1<<AIF1DAC1R_TO_DAC2R_bp)

//Register R1542 - ADC1 Left Mixer Routing

#define R1542 0x0606
#define ADC1_LEFT_MIXER_ROUTING_REG R1542

#define ADC1L_TO_AIF1ADC1L_bp       1
#define AIF2DACL_TO_AIF1ADC1L_bp    0

#define ADC1L_TO_AIF1ADC1L_bm       (1<<ADC1L_TO_AIF1ADC1L_bp)
#define AIF2DACL_TO_AIF1ADC1L_bm    (1<<AIF2DACL_TO_AIF1ADC1L_bp)

//Register R1543 - ADC1 Right Mixer Routing

#define R1543 0x0607
#define ADC1_RIGHT_MIXER_ROUTING_REG R1543

#define ADC1R_TO_AIF1ADC1R_bp       1
#define AIF2DACR_TO_AIF1ADC1R_bp    0

#define ADC1R_TO_AIF1ADC1R_bm       (1<<ADC1R_TO_AIF1ADC1R_bp)
#define AIF2DACR_TO_AIF1ADC1R_bm    (1<<AIF2DACR_TO_AIF1ADC1R_bp)


//Register R1544 - ADC2 Left Mixer Routing

#define R1544 0x0608
#define ADC2_LEFT_MIXER_ROUTING_REG R1544

#define ADC2L_TO_AIF1ADC2L_bp       1
#define AIF2DACL_TO_AIF1ADC2L_bp    0

#define ADC2L_TO_AIF1ADC2L_bm       (1<<ADC2L_TO_AIF1ADC2L_bp)
#define AIF2DACL_TO_AIF1ADC2L_bm    (1<<AIF2DACL_TO_AIF1ADC2L_bp)

//Register R1545 - ADC2 Right Mixer Routing

#define R1545 0x0609
#define ADC2_RIGHT_MIXER_ROUTING_REG R1545

#define ADC2R_TO_AIF1ADC2R_bp       1
#define AIF2DACR_TO_AIF1ADC2R_bp    0

#define ADC2R_TO_AIF1ADC2R_bm       (1<<ADC2R_TO_AIF1ADC2R_bp)
#define AIF2DACR_TO_AIF1ADC2R_bm    (1<<AIF2DACR_TO_AIF1ADC2R_bp)

//Register R1552 - DAC1 Left

#define R1552 0x0610
#define DAC1_LEFT_REG R1552

#define DAC1L_MUTE_bp   9
#define DAC1L_VU_bp     8
#define DAC1L_VOL_bp    0

#define DAC1L_MUTE_bm   (1<<DAC1L_MUTE_bp)
#define DAC1L_VU_bm     (1<<DAC1L_VU_bp)
#define DAC1L_VOL_bm    (0xFF<<DAC1L_VOL_bp)

//Register R1553 - DAC1 Right

#define R1553 0x0611
#define DAC1_RIGHT_REG R1553

#define DAC1R_MUTE_bp   9
#define DAC1R_VU_bp     8
#define DAC1R_VOL_bp    0

#define DAC1R_MUTE_bm   (1<<DAC1R_MUTE_bp)
#define DAC1R_VU_bm     (1<<DAC1R_VU_bp)
#define DAC1R_VOL_bm    (0xFF<<DAC1R_VOL_bp)

//Register R1554 - DAC2 Left

#define R1554 0x0612
#define DAC2_LEFT_REG R1554

#define DAC2L_MUTE_bp   9
#define DAC2L_VU_bp     8
#define DAC2L_VOL_bp    0

#define DAC2L_MUTE_bm   (1<<DAC2L_MUTE_bp)
#define DAC2L_VU_bm     (1<<DAC2L_VU_bp)
#define DAC2L_VOL_bm    (0xFF<<DAC2L_VOL_bp)

//Register R1555 - DAC2 Right

#define R1555 0x0613
#define DAC2_RIGHT_REG R1555

#define DAC2R_MUTE_bp   9
#define DAC2R_VU_bp     8
#define DAC2R_VOL_bp    0

#define DAC2R_MUTE_bm   (1<<DAC2R_MUTE_bp)
#define DAC2R_VU_bm     (1<<DAC2R_VU_bp)
#define DAC2R_VOL_bm    (0xFF<<DAC2R_VOL_bp)

//Register R1556 - DAC Softmute

#define R1556 0x0614
#define DAC_SOFTMUTE_REG R1556

#define DAC_SOFTMUTEMODE_bp     1
#define DAC_MUTERATE_bp         0

#define DAC_SOFTMUTEMODE_bm     (1<<DAC_SOFTMUTEMODE_bp)
#define DAC_MUTERATE_bm         (1<<DAC_MUTERATE_bp)

//Register R1568 - Oversampling

#define R1568 0x0620
#define OVERSAMPLING_REG R1568

#define ADC_OSR128_bp   1
#define DAC_OSR128_bp   0

#define ADC_OSR128_bm   (1<<ADC_OSR128_bp)
#define DAC_OSR128_bm   (1<<DAC_OSR128_bp)

//Register R1569 - Sidetone

#define R1569 0x0621
#define SIDETONE_REG R1569

#define ST_HPF_CUT_bp   7
#define ST_HPF_bp       6
#define STR_SEL_bp      1
#define STL_SEL_bp      0   

#define ST_HPF_CUT_bm   (0x7<<ST_HPF_CUT_bp)
#define ST_HPF_bm       (1<<ST_HPF_bp)
#define STR_SEL_bm      (1<<STR_SEL_bp)
#define STL_SEL_bm      (1<<STL_SEL_bp)

//Register R1792 - GPIO 1

#define R1792 0x0700
#define GPIO_1_REG R1792

#define GP1_DIR_bp      15
#define GP1_PU_bp       14
#define GP1_PD_bp       13
#define GP1_POL_bp      10
#define GP1_OP_CFG_bp   9
#define GP1_DB_bp       8
#define GP1_LVL_bp      6
#define GP1_FN_bp       0

#define GP1_DIR_bm      (1<<GP1_DIR_bp)
#define GP1_PU_bm       (1<<GP1_PU_bp)
#define GP1_PD_bm       (1<<GP1_PD_bp)
#define GP1_POL_bm      (1<<GP1_POL_bp)
#define GP1_OP_CFG_bm   (1<<GP1_OP_CFG_bp)
#define GP1_DB_bm       (1<<GP1_DB_bp)
#define GP1_LVL_bm      (1<<GP1_LVL_bp)
#define GP1_FN_bm       (1<<GP1_FN_bp)

#define GP1_FN_ADCLRCLK1                        0x00
#define GP1_FN_GPIO                             0x01
#define GP1_FN_SDOUT                            0x02
#define GP1_FN_IRQ                              0x03    
#define GP1_FN_TEMPERATURE_SHUTDOWN_STATUS      0x04    
#define GP1_FN_MICBIAS1_CURRENT_DETECT          0x05        
#define GP1_FN_MICBIAS1_SHORT_CIRCUIT_DETECT    0x06        
#define GP1_FN_MICBIAS2_CURRENT_DETECT          0x07    
#define GP1_FN_MICBIAS2_SHORT_CIRCUIT_DETECT    0x08        
#define GP1_FN_FLL1_LOCK                        0x09    
#define GP1_FN_FLL2_LOCK                        0x0A    
#define GP1_FN_SRC1_LOCK                        0x0B
#define GP1_FN_SRC2_LOCK                        0x0C
#define GP1_FN_AIF1_DRC1_SIGNAL_DETECT          0x0D    
#define GP1_FN_AIF1_DRC2_SIGNAL_DETECT          0x0E
#define GP1_FN_AIF2_DRC_SIGNAL_DETECT           0x0F
#define GP1_FN_WRITE_SEQUENCER_STATUS           0x10
#define GP1_FN_FIFO_ERROR                       0x11
#define GP1_FN_OPCLK_CLOCK_OUTPUT               0x12
#define GP1_FN_TEMPEREATURE_WARNING_STATUS      0x13
#define GP1_FN_DC_SERVO_DONE                    0x14
#define GP1_FN_FLL1_CLOCK_OUTPUT                0x15
#define GP1_FN_FLL2_CLOCK_OUTPUT                0x16

//Register R1793 - GPIO 2

#define R1793 0x0701
#define GPIO_2_REG R1793

#define GP2_DIR_bp      15
#define GP2_PU_bp       14
#define GP2_PD_bp       13
#define GP2_POL_bp      10
#define GP2_DB_bp       8
#define GP2_LVL_bp      6
#define GP2_FN_bp       0

#define GP2_DIR_bm      (1<<GP2_DIR_bp)
#define GP2_PU_bm       (1<<GP2_PU_bp)
#define GP2_PD_bm       (1<<GP2_PD_bp)
#define GP2_POL_bm      (1<<GP2_POL_bp)
#define GP2_DB_bm       (1<<GP2_DB_bp)
#define GP2_LVL_bm      (1<<GP2_LVL_bp)
#define GP2_FN_bm       (1<<GP2_FN_bp)

#define GP2_FN_ADCLRCLK1                        0x00
#define GP2_FN_GPIO                             0x01
#define GP2_FN_SDOUT                            0x02
#define GP2_FN_IRQ                              0x03    
#define GP2_FN_TEMPERATURE_SHUTDOWN_STATUS      0x04    
#define GP2_FN_MICBIAS1_CURRENT_DETECT          0x05        
#define GP2_FN_MICBIAS1_SHORT_CIRCUIT_DETECT    0x06        
#define GP2_FN_MICBIAS2_CURRENT_DETECT          0x07    
#define GP2_FN_MICBIAS2_SHORT_CIRCUIT_DETECT    0x08        
#define GP2_FN_FLL1_LOCK                        0x09    
#define GP2_FN_FLL2_LOCK                        0x0A    
#define GP2_FN_SRC1_LOCK                        0x0B
#define GP2_FN_SRC2_LOCK                        0x0C
#define GP2_FN_AIF1_DRC1_SIGNAL_DETECT          0x0D    
#define GP2_FN_AIF1_DRC2_SIGNAL_DETECT          0x0E
#define GP2_FN_AIF2_DRC_SIGNAL_DETECT           0x0F
#define GP2_FN_WRITE_SEQUENCER_STATUS           0x10
#define GP2_FN_FIFO_ERROR                       0x11
#define GP2_FN_OPCLK_CLOCK_OUTPUT               0x12
#define GP2_FN_TEMPEREATURE_WARNING_STATUS      0x13
#define GP2_FN_DC_SERVO_DONE                    0x14
#define GP2_FN_FLL1_CLOCK_OUTPUT                0x15
#define GP2_FN_FLL2_CLOCK_OUTPUT                0x16

//Register R1794 - GPIO 3

#define R1794 0x0702
#define GPIO_3_REG R1794

#define GP3_DIR_bp      15
#define GP3_PU_bp       14
#define GP3_PD_bp       13
#define GP3_POL_bp      10
#define GP3_OP_CFG_bp   9
#define GP3_DB_bp       8
#define GP3_LVL_bp      6
#define GP3_FN_bp       0

#define GP3_DIR_bm      (1<<GP3_DIR_bp)
#define GP3_PU_bm       (1<<GP3_PU_bp)
#define GP3_PD_bm       (1<<GP3_PD_bp)
#define GP3_POL_bm      (1<<GP3_POL_bp)
#define GP3_OP_CFG_bm   (1<<GP3_OP_CFG_bp)
#define GP3_DB_bm       (1<<GP3_DB_bp)
#define GP3_LVL_bm      (1<<GP3_LVL_bp)
#define GP3_FN_bm       (1<<GP3_FN_bp)

#define GP3_FN_ADCLRCLK1                        0x00
#define GP3_FN_GPIO                             0x01
#define GP3_FN_SDOUT                            0x02
#define GP3_FN_IRQ                              0x03    
#define GP3_FN_TEMPERATURE_SHUTDOWN_STATUS      0x04    
#define GP3_FN_MICBIAS1_CURRENT_DETECT          0x05        
#define GP3_FN_MICBIAS1_SHORT_CIRCUIT_DETECT    0x06        
#define GP3_FN_MICBIAS2_CURRENT_DETECT          0x07    
#define GP3_FN_MICBIAS2_SHORT_CIRCUIT_DETECT    0x08        
#define GP3_FN_FLL1_LOCK                        0x09    
#define GP3_FN_FLL2_LOCK                        0x0A    
#define GP3_FN_SRC1_LOCK                        0x0B
#define GP3_FN_SRC2_LOCK                        0x0C
#define GP3_FN_AIF1_DRC1_SIGNAL_DETECT          0x0D    
#define GP3_FN_AIF1_DRC2_SIGNAL_DETECT          0x0E
#define GP3_FN_AIF2_DRC_SIGNAL_DETECT           0x0F
#define GP3_FN_WRITE_SEQUENCER_STATUS           0x10
#define GP3_FN_FIFO_ERROR                       0x11
#define GP3_FN_OPCLK_CLOCK_OUTPUT               0x12
#define GP3_FN_TEMPEREATURE_WARNING_STATUS      0x13
#define GP3_FN_DC_SERVO_DONE                    0x14
#define GP3_FN_FLL1_CLOCK_OUTPUT                0x15
#define GP3_FN_FLL2_CLOCK_OUTPUT                0x16

//Register R1795 - GPIO 4

#define R1795 0x0703
#define GPIO_4_REG R1795

#define GP4_DIR_bp      15
#define GP4_PU_bp       14
#define GP4_PD_bp       13
#define GP4_POL_bp      10
#define GP4_OP_CFG_bp   9
#define GP4_DB_bp       8
#define GP4_LVL_bp      6
#define GP4_FN_bp       0

#define GP4_DIR_bm      (1<<GP4_DIR_bp)
#define GP4_PU_bm       (1<<GP4_PU_bp)
#define GP4_PD_bm       (1<<GP4_PD_bp)
#define GP4_POL_bm      (1<<GP4_POL_bp)
#define GP4_OP_CFG_bm   (1<<GP4_OP_CFG_bp)
#define GP4_DB_bm       (1<<GP4_DB_bp)
#define GP4_LVL_bm      (1<<GP4_LVL_bp)
#define GP4_FN_bm       (1<<GP4_FN_bp)

#define GP4_FN_ADCLRCLK1                        0x00
#define GP4_FN_GPIO                             0x01
#define GP4_FN_SDOUT                            0x02
#define GP4_FN_IRQ                              0x03    
#define GP4_FN_TEMPERATURE_SHUTDOWN_STATUS      0x04    
#define GP4_FN_MICBIAS1_CURRENT_DETECT          0x05        
#define GP4_FN_MICBIAS1_SHORT_CIRCUIT_DETECT    0x06        
#define GP4_FN_MICBIAS2_CURRENT_DETECT          0x07    
#define GP4_FN_MICBIAS2_SHORT_CIRCUIT_DETECT    0x08        
#define GP4_FN_FLL1_LOCK                        0x09    
#define GP4_FN_FLL2_LOCK                        0x0A    
#define GP4_FN_SRC1_LOCK                        0x0B
#define GP4_FN_SRC2_LOCK                        0x0C
#define GP4_FN_AIF1_DRC1_SIGNAL_DETECT          0x0D    
#define GP4_FN_AIF1_DRC2_SIGNAL_DETECT          0x0E
#define GP4_FN_AIF2_DRC_SIGNAL_DETECT           0x0F
#define GP4_FN_WRITE_SEQUENCER_STATUS           0x10
#define GP4_FN_FIFO_ERROR                       0x11
#define GP4_FN_OPCLK_CLOCK_OUTPUT               0x12
#define GP4_FN_TEMPEREATURE_WARNING_STATUS      0x13
#define GP4_FN_DC_SERVO_DONE                    0x14
#define GP4_FN_FLL1_CLOCK_OUTPUT                0x15
#define GP4_FN_FLL2_CLOCK_OUTPUT                0x16

//Register R1796 - GPIO 5

#define R1796 0x0704
#define GPIO_5_REG R1796

#define GP5_DIR_bp      15
#define GP5_PU_bp       14
#define GP5_PD_bp       13
#define GP5_POL_bp      10
#define GP5_OP_CFG_bp   9
#define GP5_DB_bp       8
#define GP5_LVL_bp      6
#define GP5_FN_bp       0

#define GP5_DIR_bm      (1<<GP5_DIR_bp)
#define GP5_PU_bm       (1<<GP5_PU_bp)
#define GP5_PD_bm       (1<<GP5_PD_bp)
#define GP5_POL_bm      (1<<GP5_POL_bp)
#define GP5_OP_CFG_bm   (1<<GP5_OP_CFG_bp)
#define GP5_DB_bm       (1<<GP5_DB_bp)
#define GP5_LVL_bm      (1<<GP5_LVL_bp)
#define GP5_FN_bm       (1<<GP5_FN_bp)

#define GP5_FN_ADCLRCLK1                        0x00
#define GP5_FN_GPIO                             0x01
#define GP5_FN_SDOUT                            0x02
#define GP5_FN_IRQ                              0x03    
#define GP5_FN_TEMPERATURE_SHUTDOWN_STATUS      0x04    
#define GP5_FN_MICBIAS1_CURRENT_DETECT          0x05        
#define GP5_FN_MICBIAS1_SHORT_CIRCUIT_DETECT    0x06        
#define GP5_FN_MICBIAS2_CURRENT_DETECT          0x07    
#define GP5_FN_MICBIAS2_SHORT_CIRCUIT_DETECT    0x08        
#define GP5_FN_FLL1_LOCK                        0x09    
#define GP5_FN_FLL2_LOCK                        0x0A    
#define GP5_FN_SRC1_LOCK                        0x0B
#define GP5_FN_SRC2_LOCK                        0x0C
#define GP5_FN_AIF1_DRC1_SIGNAL_DETECT          0x0D    
#define GP5_FN_AIF1_DRC2_SIGNAL_DETECT          0x0E
#define GP5_FN_AIF2_DRC_SIGNAL_DETECT           0x0F
#define GP5_FN_WRITE_SEQUENCER_STATUS           0x10
#define GP5_FN_FIFO_ERROR                       0x11
#define GP5_FN_OPCLK_CLOCK_OUTPUT               0x12
#define GP5_FN_TEMPEREATURE_WARNING_STATUS      0x13
#define GP5_FN_DC_SERVO_DONE                    0x14
#define GP5_FN_FLL1_CLOCK_OUTPUT                0x15
#define GP5_FN_FLL2_CLOCK_OUTPUT                0x16

//Register R1797 - GPIO 6

#define R1797 0x0705
#define GPIO_6_REG R1797

#define GP6_DIR_bp      15
#define GP6_PU_bp       14
#define GP6_PD_bp       13
#define GP6_POL_bp      10
#define GP6_OP_CFG_bp   9
#define GP6_DB_bp       8
#define GP6_LVL_bp      6
#define GP6_FN_bp       0

#define GP6_DIR_bm      (1<<GP6_DIR_bp)
#define GP6_PU_bm       (1<<GP6_PU_bp)
#define GP6_PD_bm       (1<<GP6_PD_bp)
#define GP6_POL_bm      (1<<GP6_POL_bp)
#define GP6_OP_CFG_bm   (1<<GP6_OP_CFG_bp)
#define GP6_DB_bm       (1<<GP6_DB_bp)
#define GP6_LVL_bm      (1<<GP6_LVL_bp)
#define GP6_FN_bm       (1<<GP6_FN_bp)

#define GP6_FN_ADCLRCLK1                        0x00
#define GP6_FN_GPIO                             0x01
#define GP6_FN_SDOUT                            0x02
#define GP6_FN_IRQ                              0x03    
#define GP6_FN_TEMPERATURE_SHUTDOWN_STATUS      0x04    
#define GP6_FN_MICBIAS1_CURRENT_DETECT          0x05        
#define GP6_FN_MICBIAS1_SHORT_CIRCUIT_DETECT    0x06        
#define GP6_FN_MICBIAS2_CURRENT_DETECT          0x07    
#define GP6_FN_MICBIAS2_SHORT_CIRCUIT_DETECT    0x08        
#define GP6_FN_FLL1_LOCK                        0x09    
#define GP6_FN_FLL2_LOCK                        0x0A    
#define GP6_FN_SRC1_LOCK                        0x0B
#define GP6_FN_SRC2_LOCK                        0x0C
#define GP6_FN_AIF1_DRC1_SIGNAL_DETECT          0x0D    
#define GP6_FN_AIF1_DRC2_SIGNAL_DETECT          0x0E
#define GP6_FN_AIF2_DRC_SIGNAL_DETECT           0x0F
#define GP6_FN_WRITE_SEQUENCER_STATUS           0x10
#define GP6_FN_FIFO_ERROR                       0x11
#define GP6_FN_OPCLK_CLOCK_OUTPUT               0x12
#define GP6_FN_TEMPEREATURE_WARNING_STATUS      0x13
#define GP6_FN_DC_SERVO_DONE                    0x14
#define GP6_FN_FLL1_CLOCK_OUTPUT                0x15
#define GP6_FN_FLL2_CLOCK_OUTPUT                0x16

//Register R1798 - GPIO 7

#define R1798 0x0706
#define GPIO_7_REG R1798

#define GP7_DIR_bp      15
#define GP7_PU_bp       14
#define GP7_PD_bp       13
#define GP7_POL_bp      10
#define GP7_OP_CFG_bp   9
#define GP7_DB_bp       8
#define GP7_LVL_bp      6
#define GP7_FN_bp       0

#define GP7_DIR_bm      (1<<GP7_DIR_bp)
#define GP7_PU_bm       (1<<GP7_PU_bp)
#define GP7_PD_bm       (1<<GP7_PD_bp)
#define GP7_POL_bm      (1<<GP7_POL_bp)
#define GP7_OP_CFG_bm   (1<<GP7_OP_CFG_bp)
#define GP7_DB_bm       (1<<GP7_DB_bp)
#define GP7_LVL_bm      (1<<GP7_LVL_bp)
#define GP7_FN_bm       (1<<GP7_FN_bp)

#define GP7_FN_ADCLRCLK1                        0x00
#define GP7_FN_GPIO                             0x01
#define GP7_FN_SDOUT                            0x02
#define GP7_FN_IRQ                              0x03    
#define GP7_FN_TEMPERATURE_SHUTDOWN_STATUS      0x04    
#define GP7_FN_MICBIAS1_CURRENT_DETECT          0x05        
#define GP7_FN_MICBIAS1_SHORT_CIRCUIT_DETECT    0x06        
#define GP7_FN_MICBIAS2_CURRENT_DETECT          0x07    
#define GP7_FN_MICBIAS2_SHORT_CIRCUIT_DETECT    0x08        
#define GP7_FN_FLL1_LOCK                        0x09    
#define GP7_FN_FLL2_LOCK                        0x0A    
#define GP7_FN_SRC1_LOCK                        0x0B
#define GP7_FN_SRC2_LOCK                        0x0C
#define GP7_FN_AIF1_DRC1_SIGNAL_DETECT          0x0D    
#define GP7_FN_AIF1_DRC2_SIGNAL_DETECT          0x0E
#define GP7_FN_AIF2_DRC_SIGNAL_DETECT           0x0F
#define GP7_FN_WRITE_SEQUENCER_STATUS           0x10
#define GP7_FN_FIFO_ERROR                       0x11
#define GP7_FN_OPCLK_CLOCK_OUTPUT               0x12
#define GP7_FN_TEMPEREATURE_WARNING_STATUS      0x13
#define GP7_FN_DC_SERVO_DONE                    0x14
#define GP7_FN_FLL1_CLOCK_OUTPUT                0x15
#define GP7_FN_FLL2_CLOCK_OUTPUT                0x16

//Register R1799 - GPIO 8

#define R1799 0x0707
#define GPIO_8_REG R1799

#define GP8_DIR_bp      15
#define GP8_PU_bp       14
#define GP8_PD_bp       13
#define GP8_POL_bp      10
#define GP8_OP_CFG_bp   9
#define GP8_DB_bp       8
#define GP8_LVL_bp      6
#define GP8_FN_bp       0

#define GP8_DIR_bm      (1<<GP8_DIR_bp)
#define GP8_PU_bm       (1<<GP8_PU_bp)
#define GP8_PD_bm       (1<<GP8_PD_bp)
#define GP8_POL_bm      (1<<GP8_POL_bp)
#define GP8_OP_CFG_bm   (1<<GP8_OP_CFG_bp)
#define GP8_DB_bm       (1<<GP8_DB_bp)
#define GP8_LVL_bm      (1<<GP8_LVL_bp)
#define GP8_FN_bm       (1<<GP8_FN_bp)

#define GP8_FN_ADCLRCLK1                        0x00
#define GP8_FN_GPIO                             0x01
#define GP8_FN_SDOUT                            0x02
#define GP8_FN_IRQ                              0x03    
#define GP8_FN_TEMPERATURE_SHUTDOWN_STATUS      0x04    
#define GP8_FN_MICBIAS1_CURRENT_DETECT          0x05        
#define GP8_FN_MICBIAS1_SHORT_CIRCUIT_DETECT    0x06        
#define GP8_FN_MICBIAS2_CURRENT_DETECT          0x07    
#define GP8_FN_MICBIAS2_SHORT_CIRCUIT_DETECT    0x08        
#define GP8_FN_FLL1_LOCK                        0x09    
#define GP8_FN_FLL2_LOCK                        0x0A    
#define GP8_FN_SRC1_LOCK                        0x0B
#define GP8_FN_SRC2_LOCK                        0x0C
#define GP8_FN_AIF1_DRC1_SIGNAL_DETECT          0x0D    
#define GP8_FN_AIF1_DRC2_SIGNAL_DETECT          0x0E
#define GP8_FN_AIF2_DRC_SIGNAL_DETECT           0x0F
#define GP8_FN_WRITE_SEQUENCER_STATUS           0x10
#define GP8_FN_FIFO_ERROR                       0x11
#define GP8_FN_OPCLK_CLOCK_OUTPUT               0x12
#define GP8_FN_TEMPEREATURE_WARNING_STATUS      0x13
#define GP8_FN_DC_SERVO_DONE                    0x14
#define GP8_FN_FLL1_CLOCK_OUTPUT                0x15
#define GP8_FN_FLL2_CLOCK_OUTPUT                0x16

//Register R1800 - GPIO 9

#define R1800 0x0708
#define GPIO_9_REG R1800

#define GP9_DIR_bp      15
#define GP9_PU_bp       14
#define GP9_PD_bp       13
#define GP9_POL_bp      10
#define GP9_OP_CFG_bp   9
#define GP9_DB_bp       8
#define GP9_LVL_bp      6
#define GP9_FN_bp       0

#define GP9_DIR_bm      (1<<GP9_DIR_bp)
#define GP9_PU_bm       (1<<GP9_PU_bp)
#define GP9_PD_bm       (1<<GP9_PD_bp)
#define GP9_POL_bm      (1<<GP9_POL_bp)
#define GP9_OP_CFG_bm   (1<<GP9_OP_CFG_bp)
#define GP9_DB_bm       (1<<GP9_DB_bp)
#define GP9_LVL_bm      (1<<GP9_LVL_bp)
#define GP9_FN_bm       (1<<GP9_FN_bp)

#define GP9_FN_ADCLRCLK1                        0x00
#define GP9_FN_GPIO                             0x01
#define GP9_FN_SDOUT                            0x02
#define GP9_FN_IRQ                              0x03    
#define GP9_FN_TEMPERATURE_SHUTDOWN_STATUS      0x04    
#define GP9_FN_MICBIAS1_CURRENT_DETECT          0x05        
#define GP9_FN_MICBIAS1_SHORT_CIRCUIT_DETECT    0x06        
#define GP9_FN_MICBIAS2_CURRENT_DETECT          0x07    
#define GP9_FN_MICBIAS2_SHORT_CIRCUIT_DETECT    0x08        
#define GP9_FN_FLL1_LOCK                        0x09    
#define GP9_FN_FLL2_LOCK                        0x0A    
#define GP9_FN_SRC1_LOCK                        0x0B
#define GP9_FN_SRC2_LOCK                        0x0C
#define GP9_FN_AIF1_DRC1_SIGNAL_DETECT          0x0D    
#define GP9_FN_AIF1_DRC2_SIGNAL_DETECT          0x0E
#define GP9_FN_AIF2_DRC_SIGNAL_DETECT           0x0F
#define GP9_FN_WRITE_SEQUENCER_STATUS           0x10
#define GP9_FN_FIFO_ERROR                       0x11
#define GP9_FN_OPCLK_CLOCK_OUTPUT               0x12
#define GP9_FN_TEMPEREATURE_WARNING_STATUS      0x13
#define GP9_FN_DC_SERVO_DONE                    0x14
#define GP9_FN_FLL1_CLOCK_OUTPUT                0x15
#define GP9_FN_FLL2_CLOCK_OUTPUT                0x16

//Register R1801 - GPIO 10

#define R1801 0x0709
#define GPIO_10_REG R1801

#define GP10_DIR_bp      15
#define GP10_PU_bp       14
#define GP10_PD_bp       13
#define GP10_POL_bp      10
#define GP10_OP_CFG_bp   9
#define GP10_DB_bp       8
#define GP10_LVL_bp      6
#define GP10_FN_bp       0

#define GP10_DIR_bm      (1<<GP10_DIR_bp)
#define GP10_PU_bm       (1<<GP10_PU_bp)
#define GP10_PD_bm       (1<<GP10_PD_bp)
#define GP10_POL_bm      (1<<GP10_POL_bp)
#define GP10_OP_CFG_bm   (1<<GP10_OP_CFG_bp)
#define GP10_DB_bm       (1<<GP10_DB_bp)
#define GP10_LVL_bm      (1<<GP10_LVL_bp)
#define GP10_FN_bm       (1<<GP10_FN_bp)

#define GP10_FN_ADCLRCLK1                        0x00
#define GP10_FN_GPIO                             0x01
#define GP10_FN_SDOUT                            0x02
#define GP10_FN_IRQ                              0x03    
#define GP10_FN_TEMPERATURE_SHUTDOWN_STATUS      0x04    
#define GP10_FN_MICBIAS1_CURRENT_DETECT          0x05        
#define GP10_FN_MICBIAS1_SHORT_CIRCUIT_DETECT    0x06        
#define GP10_FN_MICBIAS2_CURRENT_DETECT          0x07    
#define GP10_FN_MICBIAS2_SHORT_CIRCUIT_DETECT    0x08        
#define GP10_FN_FLL1_LOCK                        0x09    
#define GP10_FN_FLL2_LOCK                        0x0A    
#define GP10_FN_SRC1_LOCK                        0x0B
#define GP10_FN_SRC2_LOCK                        0x0C
#define GP10_FN_AIF1_DRC1_SIGNAL_DETECT          0x0D    
#define GP10_FN_AIF1_DRC2_SIGNAL_DETECT          0x0E
#define GP10_FN_AIF2_DRC_SIGNAL_DETECT           0x0F
#define GP10_FN_WRITE_SEQUENCER_STATUS           0x10
#define GP10_FN_FIFO_ERROR                       0x11
#define GP10_FN_OPCLK_CLOCK_OUTPUT               0x12
#define GP10_FN_TEMPEREATURE_WARNING_STATUS      0x13
#define GP10_FN_DC_SERVO_DONE                    0x14
#define GP10_FN_FLL1_CLOCK_OUTPUT                0x15
#define GP10_FN_FLL2_CLOCK_OUTPUT                0x16

//Register R1802 - GPIO 11

#define R1802 0x070A
#define GPIO_11_REG R1802

#define GP11_DIR_bp      15
#define GP11_PU_bp       14
#define GP11_PD_bp       13
#define GP11_POL_bp      10
#define GP11_OP_CFG_bp   9
#define GP11_DB_bp       8
#define GP11_LVL_bp      6
#define GP11_FN_bp       0

#define GP11_DIR_bm      (1<<GP11_DIR_bp)
#define GP11_PU_bm       (1<<GP11_PU_bp)
#define GP11_PD_bm       (1<<GP11_PD_bp)
#define GP11_POL_bm      (1<<GP11_POL_bp)
#define GP11_OP_CFG_bm   (1<<GP11_OP_CFG_bp)
#define GP11_DB_bm       (1<<GP11_DB_bp)
#define GP11_LVL_bm      (1<<GP11_LVL_bp)
#define GP11_FN_bm       (1<<GP11_FN_bp)

#define GP11_FN_ADCLRCLK1                        0x00
#define GP11_FN_GPIO                             0x01
#define GP11_FN_SDOUT                            0x02
#define GP11_FN_IRQ                              0x03    
#define GP11_FN_TEMPERATURE_SHUTDOWN_STATUS      0x04    
#define GP11_FN_MICBIAS1_CURRENT_DETECT          0x05        
#define GP11_FN_MICBIAS1_SHORT_CIRCUIT_DETECT    0x06        
#define GP11_FN_MICBIAS2_CURRENT_DETECT          0x07    
#define GP11_FN_MICBIAS2_SHORT_CIRCUIT_DETECT    0x08        
#define GP11_FN_FLL1_LOCK                        0x09    
#define GP11_FN_FLL2_LOCK                        0x0A    
#define GP11_FN_SRC1_LOCK                        0x0B
#define GP11_FN_SRC2_LOCK                        0x0C
#define GP11_FN_AIF1_DRC1_SIGNAL_DETECT          0x0D    
#define GP11_FN_AIF1_DRC2_SIGNAL_DETECT          0x0E
#define GP11_FN_AIF2_DRC_SIGNAL_DETECT           0x0F
#define GP11_FN_WRITE_SEQUENCER_STATUS           0x10
#define GP11_FN_FIFO_ERROR                       0x11
#define GP11_FN_OPCLK_CLOCK_OUTPUT               0x12
#define GP11_FN_TEMPEREATURE_WARNING_STATUS      0x13
#define GP11_FN_DC_SERVO_DONE                    0x14
#define GP11_FN_FLL1_CLOCK_OUTPUT                0x15
#define GP11_FN_FLL2_CLOCK_OUTPUT                0x16

//Register R1824 - Pull Control (1)

#define R1824 0x0720
#define PULL_CONTROL_1_REG R1824

#define DMICDAT2_PU_bp  11
#define DMICDAT2_PD_bp  10
#define DMICDAT1_PU_bp  9
#define DMICDAT1_PD_bp  8
#define MCLK1_PU_bp     7
#define MCLK1_PD_bp     6
#define DACDAT1_PU_bp   5
#define DACDAT1_PD_bp   4
#define DACLRCLK1_PU_bp 3
#define DACLRCLK1_PD_bp 2   
#define BCLK1_PU_bp     1
#define BCLK1_PD_bp     0

#define DMICDAT2_PU_bm  (1<<DMICDAT2_PU_bp)
#define DMICDAT2_PD_bm  (1<<DMICDAT2_PD_bp)
#define DMICDAT1_PU_bm  (1<<DMICDAT1_PU_bp)
#define DMICDAT1_PD_bm  (1<<DMICDAT1_PD_bp)
#define MCLK1_PU_bm     (1<<MCLK1_PU_bp)
#define MCLK1_PD_bm     (1<<MCLK1_PD_bp)
#define DACDAT1_PU_bm   (1<<DACDAT1_PU_bp)
#define DACDAT1_PD_bm   (1<<DACDAT1_PD_bp)
#define DACLRCLK1_PU_bm (1<<DACLRCLK1_PU_bp)
#define DACLRCLK1_PD_bm (1<<DACLRCLK1_PD_bp)
#define BCLK1_PU_bm     (1<<BCLK1_PU_bp)
#define BCLK1_PD_bm     (1<<BCLK1_PD_bp)

//Register R1825 - Pull Control (2)

#define R1825 0x0721
#define PULL_CONTROL_2_REG R1825

#define CSNADDR_PD_bp   8
#define LDO2ENA_PD_bp   6
#define LDO1ENA_PD_bp   4
#define CIFMODE_PD_bp   2   
#define SPKMODE_PU_bp   1

#define CSNADDR_PD_bm   (1<<CSNADDR_PD_bp)
#define LDO2ENA_PD_bm   (1<<LDO2ENA_PD_bp)
#define LDO1ENA_PD_bm   (1<<LOD1END_PD_bp)
#define CIFMODE_PD_bm   (1<<CIFMODE_PD_bp)
#define SPKMODE_PU_bm   (1<<SPKMODE_PU_bp)

//Register R1840 - Interrupt Status 1

#define R1840 0x0730
#define INTERRUPT_STATUS_1_REG R1840

#define GP11_EINT_bp    10
#define GP10_EINT_bp    9
#define GP9_EINT_bp     8
#define GP8_EINT_bp     7
#define GP7_EINT_bp     6
#define GP6_EINT_bp     5
#define GP5_EINT_bp     4
#define GP4_EINT_bp     3
#define GP3_EINT_bp     2
#define GP2_EINT_bp     1
#define GP1_EINT_bp     0

#define GP11_EINT_bm    (1<<GP11_EINT_bp)
#define GP10_EINT_bm    (1<<GP10_EINT_bp)
#define GP9_EINT_bm     (1<<GP9_EINT_bp)
#define GP8_EINT_bm     (1<<GP8_EINT_bp)
#define GP7_EINT_bm     (1<<GP7_EINT_bp)
#define GP6_EINT_bm     (1<<GP6_EINT_bp)
#define GP5_EINT_bm     (1<<GP5_EINT_bp)
#define GP4_EINT_bm     (1<<GP4_EINT_bp)
#define GP3_EINT_bm     (1<<GP3_EINT_bp)
#define GP2_EINT_bm     (1<<GP2_EINT_bp)
#define GP1_EINT_bm     (1<<GP1_EINT_bp)

//Register R1841 - Interrupt Status 2

#define R1841 0x0731
#define INTERRUPT_STATUS_2_REG R1841

#define TEMP_WARN_EINT_bp           15
#define DCS_DONE_EINT_bp            14
#define WSEQ_DONE_EINT_bp           13
#define FIFOS_ERR_EINT_bp           12
#define AIF2DRC_SIG_DET_EINT_bp     11  
#define AIF1DRC2_SIG_DET_EINT_bp    10
#define AIF1DRC1_SIG_DET_EINT_bp    9
#define SRC2_LOCK_EINT_bp           8
#define SRC1_LOCK_EINT_bp           7
#define FLL2_LOCK_EINT_bp           6
#define FLL1_LOCK_EINT_bp           5
#define MIC2_SHRT_EINT_bp           4
#define MIC2_DET_EINT_bp            3
#define MIC1_SHORT_EINT_bp          2
#define MIC1_DET_EINT_bp            1
#define TEMP_SHUT_EINT_bp           0

#define TEMP_WARN_EINT_bm           (1<<TEMP_WARN_EINT_bp)
#define DCS_DONE_EINT_bm            (1<<DCS_DONE_EINT_bp)
#define WSEQ_DONE_EINT_bm           (1<<WSEQ_DONE_EINT_bp)
#define FIFOS_ERR_EINT_bm           (1<<FIFOS_ERR_EINT_bp)
#define AIF2DRC_SIG_DET_EINT_bm     (1<<AIF2DRC_SIG_DET_EINT_bp)
#define AIF1DRC2_SIG_DET_EINT_bm    (1<<AIF1DRC2_SIG_DET_EINT_bp)
#define AIF1DRC1_SIG_DET_EINT_bm    (1<<AIF1DRC1_SIG_DET_EINT_bp)
#define SRC2_LOCK_EINT_bm           (1<<SRC2_LOCK_EINT_bp)
#define SRC1_LOCK_EINT_bm           (1<<SRC1_LOCK_EINT_bp)
#define FLL2_LOCK_EINT_bm           (1<<FLL2_LOCK_EINT_bp)
#define FLL1_LOCK_EINT_bm           (1<<FLL1_LOCK_EINT_bp)
#define MIC2_SHRT_EINT_bm           (1<<MIC2_SHRT_EINT_bp)
#define MIC2_DET_EINT_bm            (1<<MIC2_DET_EINT_bp)
#define MIC1_SHORT_EINT_bm          (1<<MIC1_SHORT_EINT_bp)
#define MIC1_DET_EINT_bm            (1<<MIC1_DET_EINT_bp)
#define TEMP_SHUT_EINT_bm           (1<<TEMP_SHUT_EINT_bp)

//Register R1842 - Interrupt Raw Status 2

#define R1842 0x0732
#define INTERRUPT_RAW_STATUS_2_REG R1842

#define TEMP_WARN_STS_bp        15
#define DCS_DONE_STS_bp         14
#define WSEQ_DONE_STS_bp        13
#define FIFOS_ERR_STS_bp        12
#define AIF2DRC_SIG_DET_STS_bp  11
#define AIF1DRC2_SIG_DET_STS_bp 10
#define AIF1DRC1_SIG_DET_STS_bp 9
#define SRC2_LOCK_STS_bp        8
#define SRC1_LOCK_STS_bp        7
#define FLL2_LOCK_STS_bp        6
#define FLL1_LOCK_STS_bp        5
#define MIC2_SHRT_STS_bp        4
#define MIC2_DET_STS_bp         3
#define MIC1_SHRT_STS_bp        2
#define MIC1_DET_STS_bp         1
#define TEMP_SHUT_STS_bp        0

#define TEMP_WARN_STS_bm        (1<<TEMP_WARN_STS_bp)
#define DCS_DONE_STS_bm         (1<<DCS_DONE_STS_bp)
#define WSEQ_DONE_STS_bm        (1<<WSEQ_DONE_STS_bp)
#define FIFOS_ERR_STS_bm        (1<<FIFOS_ERR_STS_bp)
#define AIF2DRC_SIG_DET_STS_bm  (1<<AIF2DRC_SIG_DET_STS_bp)
#define AIF1DRC2_SIG_DET_STS_bm (1<<AIF1DRC2_SIG_DET_STS_bp)
#define AIF1DRC1_SIG_DET_STS_bm (1<<AIF1DRC1_SIG_DET_STS_bp)
#define SRC2_LOCK_STS_bm        (1<<SRC2_LOCK_STS_bp)
#define SRC1_LOCK_STS_bm        (1<<SRC1_LOCK_STS_bp)
#define FLL2_LOCK_STS_bm        (1<<FLL2_LOCK_STS_bp)
#define FLL1_LOCK_STS_bm        (1<<FLL1_LOCK_STS_bp)
#define MIC2_SHRT_STS_bm        (1<<MIC_SHRT_STS_bp)
#define MIC2_DET_STS_bm         (1<<MIC_DET_STS_bp)
#define MIC1_SHRT_STS_bm        (1<<MIC1_SHORT_STS_bp)
#define MIC1_DET_STS_bm         (1<<MIC1_DET_STS_bp)
#define TEMP_SHUT_STS_bm        (1<<TEMP_SHUT_STS_bp)

//Register R1848 - Interrupt Status 1 Mask

#define R1848 0x0738
#define INTERRUPT_STATUS_1_MASK_REG R1848

#define IM_GP11_EINT_bp     10
#define IM_GP10_EINT_bp     9
#define IM_GP9_EINT_bp      8
#define IN_GP8_EINT_bp      7
#define IN_GP7_EINT_bp      6
#define IN_GP6_EINT_bp      5
#define IN_GP5_EINT_bp      4
#define IN_GP4_EINT_bp      3
#define IN_GP3_EINT_bp      2
#define IN_GP2_EINT_bp      1
#define IN_GP1_EITN_bp      0

#define IN_GP11_EINT_bm     (1<<IN_GP11_EINT_bp)
#define IN_GP10_EINT_bm     (1<<IN_GP10_EINT_bp)
#define IN_GP9_EINT_bm      (1<<IN_GP9_EINT_bp)
#define IN_GP8_EINT_bm      (1<<IN_GP8_EINT_bp)
#define IN_GP7_EINT_bm      (1<<IN_GP7_EINT_bp)
#define IN_GP6_EINT_bm      (1<<IN_GP6_EINT_bp)
#define IN_GP5_EINT_bm      (1<<IN_GP5_EINT_bp)
#define IN_GP4_EINT_bm      (1<<IN_GP4_EINT_bp)
#define IN_GP3_EINT_bm      (1<<IN_GP3_EINT_bp)
#define IN_GP2_EINT_bm      (1<<IN_GP2_EINT_bp)
#define IN_GP1_EINT_bm      (1<<IM_GP1_EINT_bp)

//Register R1849 - Interrupt Status 2 Mask 

#define R1849 0x0739
#define INTERRUPT_STATUS_2_MASK_REG R1849

#define IM_TEMP_WARN_EINT_bp            15
#define IM_DCS_DONE_EINT_bp             14
#define IM_WSEQ_DONE_EINT_bp            13
#define IM_FIFOS_ERR_EINT_bp            12
#define IM_AIF2DRC_SIG_DET_EINT_bp      11
#define IM_AIF1DRC2_SIG_DET_EINT_bp     10
#define IM_AIF1DRC1_SIG_DET_EINT_bp     9
#define IM_SRC2_LOCK_EINT_bp            8
#define IM_SRC1_LOCK_EINT_bp            7
#define IM_FLL2_LOCK_EINT_bp            6
#define IM_FLL1_LOCK_EINT_bp            5
#define IM_MIC2_SHRT_EINT_bp            4
#define IM_MIC2_DET_EINT_bp             3
#define IM_MIC1_SHRT_EINT_bp            2
#define IM_MIC1_DET_EINT_bp             1
#define IM_TEMP_SHUT_EINT_bp            0

#define IM_TEMP_WARN_EINT_bm            (1<<IM_TEMP_WARN_EINT_bp)
#define IM_DCS_DONE_EINT_bm             (1<<IM_DCS_DONE_EINT_bp)
#define IM_WSEQ_DONE_EINT_bm            (1<<IM_WSEQ_DONE_EINT_bp)
#define IM_FIFOS_ERR_EINT_bm            (1<<IM_FIFOS_ERR_EINT_bp)
#define IM_AIF2DRC_SIG_DET_EINT_bm      (1<<IM_AIF2DRC_SIG_DET_EINT_bp)
#define IM_AIF1DRC2_SIG_DET_EINT_bm     (1<<IM_AIF1DRC2_SIG_DET_EINT_bp)
#define IM_AIF1DRC1_SIG_DET_EINT_bm     (1<<IM_AIF1DRC1_SIG_DET_EINT_bp)
#define IM_SRC2_LOCK_EINT_bm            (1<<IM_SRC2_LOCK_EINT_bp)
#define IM_SRC1_LOCK_EINT_bm            (1<<IM_SRC1_LOCK_EINT_bp)
#define IM_FLL2_LOCK_EINT_bm            (1<<IM_FLL2_LOCK_EINT_bp)
#define IM_FLL1_LOCK_EINT_bm            (1<<IM_FLL1_LOCK_EINT_bp)
#define IM_MIC2_SHRT_EINT_bm            (1<<IM_MIC2_SHRT_EINT_bp)
#define IM_MIC2_DET_EINT_bm             (1<<IM_MIC2_DET_EINT_bp)
#define IM_MIC1_SHRT_EINT_bm            (1<<IM_MIC1_SHRT_EINT_bp)
#define IM_MIC1_DET_EINT_bm             (1<<IM_MIC1_DET_EINT_bp)
#define IM_TEMP_SHUT_EINT_bm            (1<<IM_TEMP_SHUT_EINT_bp)

//Register R1856 - Interrupt Control

#define R1856 0x0740
#define INTERRUPT_CONTROL_REG R1856

#define IM_IRQ_bp 0

#define IM_IRQ_bm (1<<IM_IRQ_bp)

//Register R1864 - IRQ Debounce

#define R1864 0x0748
#define IRQ_DEBUOUNCE_REG R1864

#define TEMP_WARN_DB_bp     5
#define MIC2_SHRT_DB_bp     4
#define MIC2_DET_DB_bp      3
#define MIC1_SHRT_DB_bp     2
#define MIC1_DET_DB_bp      1
#define TEMP_SHUT_DB_bp     0

#define TEMP_WARN_DB_bm     (1<<TEMP_WARN_DB_bp)
#define MIC2_SHRT_DB_bm     (1<<MIC2_SHRT_DB_bp)
#define MIC2_DET_DB_bm      (1<<MIC2_DET_DB_bp)
#define MIC1_SHRT_DB_bm     (1<<MIC1_SHRT_DB_bp)
#define MIC1_DET_DB_bm      (1<<MIC1_DET_DB_bp)
#define TEMP_SHUT_DB_bm     (1<<TEMP_SHUT_DB_bp)

#endif