EESchema Schematic File Version 4
LIBS:mTouch_Test-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 2 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:GND #PWR0308
U 1 1 5A49B2FB
P 4750 7190
F 0 "#PWR0308" H 4750 6940 50  0001 C CNN
F 1 "GND" H 4750 7040 50  0000 C CNN
F 2 "" H 4750 7190 50  0000 C CNN
F 3 "" H 4750 7190 50  0000 C CNN
	1    4750 7190
	1    0    0    -1  
$EndComp
Wire Wire Line
	4430 6770 4430 6810
Connection ~ 4750 6770
Wire Wire Line
	5070 6770 5070 6810
Wire Wire Line
	4430 6770 4750 6770
Wire Wire Line
	4750 6730 4750 6770
Wire Wire Line
	4430 7150 4430 7110
Connection ~ 4750 7150
Wire Wire Line
	5070 7150 5070 7110
Wire Wire Line
	4430 7150 4750 7150
Wire Wire Line
	4750 7110 4750 7150
$Comp
L Custom-Library:C_Custom C305
U 1 1 5A49B30E
P 4430 6960
F 0 "C305" H 4455 7060 50  0000 L CNN
F 1 "0.1uF" H 4455 6860 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4468 6810 50  0001 C CNN
F 3 "" H 4455 7060 50  0001 C CNN
F 4 "0603" H 4280 7060 50  0000 R CNN "display_footprint"
F 5 "50V" H 4280 6960 50  0000 R CNN "Voltage"
F 6 "X7R" H 4280 6860 50  0000 R CNN "Dielectric"
F 7 "399-6856-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    4430 6960
	1    0    0    -1  
$EndComp
$Comp
L Custom-Library:C_Custom C307
U 1 1 5A49B318
P 5070 6960
F 0 "C307" H 5095 7060 50  0000 L CNN
F 1 "1nF" H 5095 6860 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5108 6810 50  0001 C CNN
F 3 "" H 5095 7060 50  0001 C CNN
F 4 "0603" H 4920 7060 50  0001 R CNN "display_footprint"
F 5 "50V" H 4920 6960 50  0001 R CNN "Voltage"
F 6 "X7R" H 4920 6860 50  0001 R CNN "Dielectric"
F 7 "399-1083-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    5070 6960
	1    0    0    -1  
$EndComp
$Comp
L Custom-Library:C_Custom C306
U 1 1 5A49B322
P 4750 6960
F 0 "C306" H 4775 7060 50  0000 L CNN
F 1 "10nF" H 4775 6860 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4788 6810 50  0001 C CNN
F 3 "" H 4775 7060 50  0001 C CNN
F 4 "0603" H 4600 7060 50  0001 R CNN "display_footprint"
F 5 "50V" H 4600 6960 50  0001 R CNN "Voltage"
F 6 "X7R" H 4600 6860 50  0001 R CNN "Dielectric"
F 7 "399-1092-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    4750 6960
	1    0    0    -1  
$EndComp
Text GLabel 6260 3530 2    40   Input ~ 0
~MCLR
Text GLabel 3760 2730 0    60   Input ~ 0
ICSPCLK
Text GLabel 3760 2830 0    60   BiDi ~ 0
ICSPDAT
$Comp
L Custom-Library:R_Custom R305
U 1 1 5A49C9A3
P 5690 7010
F 0 "R305" H 5630 7010 50  0000 R CNN
F 1 "10k" V 5690 7010 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 5690 7010 50  0001 C CNN
F 3 "" H 5690 7010 50  0001 C CNN
F 4 "0603" H 5760 7090 50  0000 L CNN "display_footprint"
F 5 "1%" H 5760 7010 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 5760 6940 50  0000 L CNN "Wattage"
F 7 "P10.0KHCT-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    5690 7010
	-1   0    0    1   
$EndComp
Text GLabel 5690 7160 3    60   UnSpc ~ 0
~MCLR
Text GLabel 6260 2130 2    60   Output ~ 0
drive_Anode_A
Text GLabel 6260 2230 2    60   Output ~ 0
drive_Anode_B
Text GLabel 6260 2330 2    60   Output ~ 0
drive_Anode_C
Text GLabel 6260 2430 2    60   Output ~ 0
drive_Anode_D
Text GLabel 6260 2530 2    60   Output ~ 0
drive_Anode_E
Text GLabel 6260 2630 2    60   Output ~ 0
drive_Anode_F
Text GLabel 6260 2730 2    60   Output ~ 0
drive_Anode_G
Text GLabel 6260 2830 2    60   Output ~ 0
drive_Anode_DP
Text GLabel 3760 3930 0    60   Output ~ 0
drive_Grid_0
Text GLabel 3760 4030 0    60   Output ~ 0
drive_Grid_1
Text GLabel 3760 4130 0    60   Output ~ 0
drive_Grid_2
Text GLabel 3760 4230 0    60   Output ~ 0
drive_Grid_3
Text GLabel 3760 4330 0    60   Output ~ 0
drive_Grid_4
Text GLabel 3760 4430 0    60   Output ~ 0
drive_Grid_5
Text GLabel 6260 3730 2    60   Output ~ 0
USB_UART_TX
Text GLabel 6260 3630 2    60   Input ~ 0
USB_UART_RX
Text GLabel 3760 2330 0    60   Input ~ 0
USB_DTR
Text GLabel 6260 3430 2    60   Output ~ 0
DIM_PWM
Text GLabel 3760 1630 0    60   Input ~ 0
VAN_ADC
Text GLabel 3760 2630 0    60   Input ~ 0
VFF_ADC
Text GLabel 3760 1330 0    60   Input ~ 0
POS24_ADC
Wire Wire Line
	5010 900  5010 940 
Wire Wire Line
	4960 940  5010 940 
Wire Wire Line
	4960 940  4960 980 
Wire Wire Line
	5060 940  5060 980 
Connection ~ 5010 940 
Text GLabel 6260 1430 2    40   Input ~ 0
~Time
Text GLabel 6260 1530 2    40   Input ~ 0
~Date
Text GLabel 6260 1630 2    40   Input ~ 0
~Alarm
Text GLabel 6260 1730 2    40   Input ~ 0
~Display
Text GLabel 6260 1830 2    40   Input ~ 0
~Brightness
Text GLabel 6260 1930 2    40   Input ~ 0
~Encoder_PB
Text GLabel 3760 2530 0    60   Input ~ 0
VFF_PGOOD
Text GLabel 3760 1730 0    60   Input ~ 0
VAN_PGOOD
Text GLabel 6260 1230 2    60   Input ~ 0
POS3P3_PGOOD
Text GLabel 3760 1230 0    60   Input ~ 0
POS24_PGOOD
Text GLabel 6260 3930 2    60   Output ~ 0
VAN_RUN
Text GLabel 3760 2430 0    60   Output ~ 0
VFF_RUN
Text GLabel 8130 5520 1    60   UnSpc ~ 0
uC_SOSC-
Text GLabel 7430 5520 1    60   UnSpc ~ 0
uC_SOSC+
$Comp
L Custom-Library:C_Custom C308
U 1 1 5A55A45C
P 7430 5950
F 0 "C308" H 7455 6050 50  0000 L CNN
F 1 "9pF" H 7455 5850 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7468 5800 50  0001 C CNN
F 3 "" H 7455 6050 50  0001 C CNN
F 4 "0603" H 7280 6050 50  0000 R CNN "display_footprint"
F 5 "50V" H 7280 5950 50  0000 R CNN "Voltage"
F 6 "NP0" H 7280 5850 50  0000 R CNN "Dielectric"
F 7 "445-5046-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    7430 5950
	1    0    0    -1  
$EndComp
$Comp
L Device:Crystal Y301
U 1 1 5A55A462
P 7780 5600
F 0 "Y301" H 7780 5750 50  0000 C CNN
F 1 "32.768kHz" H 7780 5450 50  0000 C CNN
F 2 "Crystals:Crystal_SMD_2012-2pin_2.0x1.2mm" H 7780 5600 50  0001 C CNN
F 3 "" H 7780 5600 50  0001 C CNN
F 4 "XC2122CT-ND" H 7780 5600 60  0001 C CNN "Digi-Key PN"
	1    7780 5600
	1    0    0    1   
$EndComp
$Comp
L Custom-Library:C_Custom C309
U 1 1 5A55A46B
P 8130 5950
F 0 "C309" H 8155 6050 50  0000 L CNN
F 1 "9pF" H 8155 5850 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 8168 5800 50  0001 C CNN
F 3 "" H 8155 6050 50  0001 C CNN
F 4 "0603" H 7980 6050 50  0000 R CNN "display_footprint"
F 5 "50V" H 7980 5950 50  0000 R CNN "Voltage"
F 6 "NP0" H 7980 5850 50  0000 R CNN "Dielectric"
F 7 "445-5046-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    8130 5950
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR0313
U 1 1 5A55A471
P 8130 6100
F 0 "#PWR0313" H 8130 5850 50  0001 C CNN
F 1 "GND" H 8130 5950 50  0000 C CNN
F 2 "" H 8130 6100 50  0001 C CNN
F 3 "" H 8130 6100 50  0001 C CNN
	1    8130 6100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0312
U 1 1 5A55A477
P 7430 6100
F 0 "#PWR0312" H 7430 5850 50  0001 C CNN
F 1 "GND" H 7430 5950 50  0000 C CNN
F 2 "" H 7430 6100 50  0001 C CNN
F 3 "" H 7430 6100 50  0001 C CNN
	1    7430 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7430 5520 7430 5600
Wire Wire Line
	7430 5600 7630 5600
Wire Wire Line
	7930 5600 8130 5600
Wire Wire Line
	8130 5520 8130 5600
Connection ~ 7430 5600
Connection ~ 8130 5600
Text GLabel 3760 3130 0    60   UnSpc ~ 0
uC_SOSC+
Text GLabel 3760 3030 0    60   UnSpc ~ 0
uC_SOSC-
$Comp
L Custom-Library:+3.3V_MNG #PWR0309
U 1 1 5A55ED44
P 5010 900
F 0 "#PWR0309" H 5010 750 50  0001 C CNN
F 1 "+3.3V_MNG" H 5010 1040 50  0000 C CNN
F 2 "" H 5010 900 50  0000 C CNN
F 3 "" H 5010 900 50  0000 C CNN
	1    5010 900 
	1    0    0    -1  
$EndComp
$Comp
L Custom-Library:+3.3V_MNG #PWR0307
U 1 1 5A55F38D
P 4750 6730
F 0 "#PWR0307" H 4750 6580 50  0001 C CNN
F 1 "+3.3V_MNG" H 4750 6870 50  0000 C CNN
F 2 "" H 4750 6730 50  0000 C CNN
F 3 "" H 4750 6730 50  0000 C CNN
	1    4750 6730
	1    0    0    -1  
$EndComp
$Comp
L Custom-Library:+3.3V_MNG #PWR0311
U 1 1 5A55F458
P 5690 6860
F 0 "#PWR0311" H 5690 6710 50  0001 C CNN
F 1 "+3.3V_MNG" H 5690 7000 50  0000 C CNN
F 2 "" H 5690 6860 50  0000 C CNN
F 3 "" H 5690 6860 50  0000 C CNN
	1    5690 6860
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0306
U 1 1 5AEE8EC0
P 3230 7190
F 0 "#PWR0306" H 3230 6940 50  0001 C CNN
F 1 "GND" H 3230 7040 50  0000 C CNN
F 2 "" H 3230 7190 50  0000 C CNN
F 3 "" H 3230 7190 50  0000 C CNN
	1    3230 7190
	1    0    0    -1  
$EndComp
Wire Wire Line
	2910 6770 2910 6810
Connection ~ 3230 6770
Wire Wire Line
	3550 6770 3550 6810
Wire Wire Line
	2910 6770 3230 6770
Wire Wire Line
	3230 6730 3230 6770
Wire Wire Line
	2910 7150 2910 7110
Connection ~ 3230 7150
Wire Wire Line
	3550 7150 3550 7110
Wire Wire Line
	2910 7150 3230 7150
Wire Wire Line
	3230 7110 3230 7150
$Comp
L Custom-Library:C_Custom C302
U 1 1 5AEE8ED3
P 2910 6960
F 0 "C302" H 2935 7060 50  0000 L CNN
F 1 "0.1uF" H 2935 6860 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2948 6810 50  0001 C CNN
F 3 "" H 2935 7060 50  0001 C CNN
F 4 "0603" H 2760 7060 50  0000 R CNN "display_footprint"
F 5 "50V" H 2760 6960 50  0000 R CNN "Voltage"
F 6 "X7R" H 2760 6860 50  0000 R CNN "Dielectric"
F 7 "399-6856-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    2910 6960
	1    0    0    -1  
$EndComp
$Comp
L Custom-Library:C_Custom C304
U 1 1 5AEE8EDC
P 3550 6960
F 0 "C304" H 3575 7060 50  0000 L CNN
F 1 "1nF" H 3575 6860 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3588 6810 50  0001 C CNN
F 3 "" H 3575 7060 50  0001 C CNN
F 4 "0603" H 3400 7060 50  0001 R CNN "display_footprint"
F 5 "50V" H 3400 6960 50  0001 R CNN "Voltage"
F 6 "X7R" H 3400 6860 50  0001 R CNN "Dielectric"
F 7 "399-1083-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    3550 6960
	1    0    0    -1  
$EndComp
$Comp
L Custom-Library:C_Custom C303
U 1 1 5AEE8EE5
P 3230 6960
F 0 "C303" H 3255 7060 50  0000 L CNN
F 1 "10nF" H 3255 6860 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3268 6810 50  0001 C CNN
F 3 "" H 3255 7060 50  0001 C CNN
F 4 "0603" H 3080 7060 50  0001 R CNN "display_footprint"
F 5 "50V" H 3080 6960 50  0001 R CNN "Voltage"
F 6 "X7R" H 3080 6860 50  0001 R CNN "Dielectric"
F 7 "399-1092-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    3230 6960
	1    0    0    -1  
$EndComp
$Comp
L Custom-Library:+3.3V_MNG #PWR0305
U 1 1 5AEE8EEB
P 3230 6730
F 0 "#PWR0305" H 3230 6580 50  0001 C CNN
F 1 "+3.3V_MNG" H 3230 6870 50  0000 C CNN
F 2 "" H 3230 6730 50  0000 C CNN
F 3 "" H 3230 6730 50  0000 C CNN
	1    3230 6730
	1    0    0    -1  
$EndComp
Text GLabel 3760 1830 0    40   UnSpc ~ 0
~Status_COM_Error
Text GLabel 6260 4030 2    60   Output ~ 0
Buzzer
Text GLabel 6260 3030 2    60   Input ~ 0
Ambient_Temp
Text GLabel 6260 3130 2    60   Input ~ 0
VFF_Temp
Text GLabel 6260 3330 2    60   Input ~ 0
POS3P3_TEMP
Text GLabel 6260 3230 2    60   Input ~ 0
VAN_Temp
Wire Wire Line
	4750 6770 5070 6770
Wire Wire Line
	4750 6770 4750 6810
Wire Wire Line
	4750 7150 5070 7150
Wire Wire Line
	4750 7150 4750 7190
Wire Wire Line
	5010 940  5060 940 
Wire Wire Line
	7430 5600 7430 5800
Wire Wire Line
	8130 5600 8130 5800
Wire Wire Line
	3230 6770 3550 6770
Wire Wire Line
	3230 6770 3230 6810
Wire Wire Line
	3230 7150 3550 7150
Wire Wire Line
	3230 7150 3230 7190
Text GLabel 6260 4130 2    60   Output ~ 0
Colon_1
Text GLabel 6260 4230 2    60   Output ~ 0
Colon_2
Text GLabel 3760 1930 0    40   UnSpc ~ 0
~Status_Heartbeat
Text GLabel 3760 3230 0    60   Input ~ 0
HOLDUP_PGOOD
Text GLabel 6260 1330 2    60   Input ~ 0
POS3P3_ADC
Text GLabel 3760 3330 0    60   Input ~ 0
HOLDUP_ADC
$Comp
L Connector_Generic:Conn_01x03 TP301
U 1 1 5B5039B1
P 1930 5460
F 0 "TP301" H 1930 5660 50  0000 C CNN
F 1 "I2C" H 1930 5260 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 1930 5460 50  0001 C CNN
F 3 "~" H 1930 5460 50  0001 C CNN
	1    1930 5460
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0316
U 1 1 5B504108
P 1730 5560
F 0 "#PWR0316" H 1730 5310 50  0001 C CNN
F 1 "GND" H 1730 5410 50  0000 C CNN
F 2 "" H 1730 5560 50  0001 C CNN
F 3 "" H 1730 5560 50  0001 C CNN
	1    1730 5560
	1    0    0    -1  
$EndComp
Text GLabel 1730 5360 0    60   UnSpc ~ 0
IIC_SCL
Text GLabel 1730 5460 0    60   UnSpc ~ 0
IIC_SDA
Text GLabel 3760 1530 0    40   UnSpc ~ 0
~Status_Power_Error
Text GLabel 3760 2230 0    60   Input ~ 0
Encoder_DIR
Text GLabel 3760 2130 0    60   Input ~ 0
Encoder_STEP
Text GLabel 3760 3430 0    40   Input ~ 0
~POS3P3_UV
Text GLabel 3760 3530 0    60   Output ~ 0
ACCUM
Text GLabel 3760 3630 0    60   Output ~ 0
REF_CLK
NoConn ~ 3760 1430
NoConn ~ 3760 3730
$Comp
L Connector_Generic:Conn_01x03 TP302
U 1 1 5B5F52C3
P 3430 5460
F 0 "TP302" H 3430 5660 50  0000 C CNN
F 1 "USB_UART" H 3430 5260 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 3430 5460 50  0001 C CNN
F 3 "~" H 3430 5460 50  0001 C CNN
	1    3430 5460
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0301
U 1 1 5B5F52CA
P 3230 5560
F 0 "#PWR0301" H 3230 5310 50  0001 C CNN
F 1 "GND" H 3230 5410 50  0000 C CNN
F 2 "" H 3230 5560 50  0001 C CNN
F 3 "" H 3230 5560 50  0001 C CNN
	1    3230 5560
	1    0    0    -1  
$EndComp
Text GLabel 3230 5460 0    60   UnSpc ~ 0
USB_UART_TX
Text GLabel 3230 5360 0    60   UnSpc ~ 0
USB_UART_RX
Text Notes 5710 750  0    100  ~ 20
8 Bit High Performance Microcontroller
$Comp
L Custom_Library:PIC18(L)F67K40-I_PT U301
U 1 1 5B668926
P 5010 2980
F 0 "U301" H 6060 1180 50  0000 R CNN
F 1 "PIC18LF67K40-I_PT" H 5010 3030 50  0000 C CNN
F 2 "Housings_QFP:TQFP-64_10x10mm_Pitch0.5mm" H 5010 5080 50  0001 C CNN
F 3 "" H 4360 3630 50  0001 C CNN
F 4 "PIC18LF67K40T-I/PTCT-ND" H 5010 2980 50  0001 C CNN "Digi-Key PN"
	1    5010 2980
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5B66A6B7
P 5010 4960
F 0 "#PWR?" H 5010 4710 50  0001 C CNN
F 1 "GND" H 5010 4810 50  0000 C CNN
F 2 "" H 5010 4960 50  0001 C CNN
F 3 "" H 5010 4960 50  0001 C CNN
	1    5010 4960
	1    0    0    -1  
$EndComp
Wire Wire Line
	5010 4960 5010 4920
Wire Wire Line
	5010 4920 4960 4920
Wire Wire Line
	4960 4920 4960 4880
Wire Wire Line
	5010 4920 5060 4920
Wire Wire Line
	5060 4920 5060 4880
Connection ~ 5010 4920
$EndSCHEMATC
