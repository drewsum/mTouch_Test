EESchema Schematic File Version 4
LIBS:mTouch_Test-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 2 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 6260 3530 2    40   Input ~ 0
~MCLR
Text GLabel 3760 2730 0    60   Input ~ 0
ICSPCLK
Text GLabel 3760 2830 0    60   BiDi ~ 0
ICSPDAT
Text GLabel 5690 7160 3    60   UnSpc ~ 0
~MCLR
Text GLabel 6260 3730 2    60   Output ~ 0
USB_UART_TX
Text GLabel 6260 3630 2    60   Input ~ 0
USB_UART_RX
Text GLabel 3760 2330 0    60   Input ~ 0
USB_DTR
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
Text GLabel 6260 1230 2    60   Input ~ 0
POS3P3_PGOOD
$Comp
L power:GND #PWR?
U 1 1 5AEE8EC0
P 3230 7190
F 0 "#PWR?" H 3230 6940 50  0001 C CNN
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
Wire Wire Line
	5010 940  5060 940 
Wire Wire Line
	3230 6770 3550 6770
Wire Wire Line
	3230 6770 3230 6810
Wire Wire Line
	3230 7150 3550 7150
Wire Wire Line
	3230 7150 3230 7190
Text GLabel 6260 1330 2    60   Input ~ 0
POS3P3_ADC
NoConn ~ 3760 3730
Text Notes 5710 750  0    100  ~ 20
8 Bit High Performance Microcontroller
$Comp
L Custom_Library:PIC18(L)F67K40-I_PT U?
U 1 1 5B668926
P 5010 2980
F 0 "U?" H 6060 1180 50  0000 R CNN
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
$Comp
L Custom_Library:+3.3V #PWR?
U 1 1 5B701982
P 5010 900
F 0 "#PWR?" H 5010 750 50  0001 C CNN
F 1 "+3.3V" H 5010 1040 50  0000 C CNN
F 2 "" H 5010 900 50  0000 C CNN
F 3 "" H 5010 900 50  0000 C CNN
	1    5010 900 
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5B7039A8
P 2910 6960
AR Path="/5B6F6CF0/5B7039A8" Ref="C?"  Part="1" 
AR Path="/5B6F6CC2/5B7039A8" Ref="C?"  Part="1" 
F 0 "C?" H 2935 7060 50  0000 L CNN
F 1 "0.1uF" H 2935 6860 50  0000 L CNN
F 2 "" H 2948 6810 50  0001 C CNN
F 3 "" H 2935 7060 50  0001 C CNN
F 4 "0603" H 2760 7060 50  0000 R CNN "display_footprint"
F 5 "50V" H 2760 6960 50  0000 R CNN "Voltage"
F 6 "X7R" H 2760 6860 50  0000 R CNN "Dielectric"
F 7 "PN" H 3335 7460 60  0001 C CNN "Digi-Key PN"
	1    2910 6960
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5B704457
P 3230 6960
AR Path="/5B6F6CF0/5B704457" Ref="C?"  Part="1" 
AR Path="/5B6F6CC2/5B704457" Ref="C?"  Part="1" 
F 0 "C?" H 3255 7060 50  0000 L CNN
F 1 "10nF" H 3255 6860 50  0000 L CNN
F 2 "" H 3268 6810 50  0001 C CNN
F 3 "" H 3255 7060 50  0001 C CNN
F 4 "0603" H 3080 7060 50  0001 R CNN "display_footprint"
F 5 "50V" H 3080 6960 50  0001 R CNN "Voltage"
F 6 "X7R" H 3080 6860 50  0001 R CNN "Dielectric"
F 7 "PN" H 3655 7460 60  0001 C CNN "Digi-Key PN"
	1    3230 6960
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5B7044E3
P 3550 6960
AR Path="/5B6F6CF0/5B7044E3" Ref="C?"  Part="1" 
AR Path="/5B6F6CC2/5B7044E3" Ref="C?"  Part="1" 
F 0 "C?" H 3575 7060 50  0000 L CNN
F 1 "1nF" H 3575 6860 50  0000 L CNN
F 2 "" H 3588 6810 50  0001 C CNN
F 3 "" H 3575 7060 50  0001 C CNN
F 4 "0603" H 3400 7060 50  0001 R CNN "display_footprint"
F 5 "50V" H 3400 6960 50  0001 R CNN "Voltage"
F 6 "X7R" H 3400 6860 50  0001 R CNN "Dielectric"
F 7 "PN" H 3975 7460 60  0001 C CNN "Digi-Key PN"
	1    3550 6960
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V #PWR?
U 1 1 5B704709
P 3230 6730
F 0 "#PWR?" H 3230 6580 50  0001 C CNN
F 1 "+3.3V" H 3230 6870 50  0000 C CNN
F 2 "" H 3230 6730 50  0000 C CNN
F 3 "" H 3230 6730 50  0000 C CNN
	1    3230 6730
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5B7047DC
P 4750 7190
F 0 "#PWR?" H 4750 6940 50  0001 C CNN
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
Wire Wire Line
	4750 6770 5070 6770
Wire Wire Line
	4750 6770 4750 6810
Wire Wire Line
	4750 7150 5070 7150
Wire Wire Line
	4750 7150 4750 7190
$Comp
L Custom_Library:C_Custom C?
U 1 1 5B7047F4
P 4430 6960
AR Path="/5B6F6CF0/5B7047F4" Ref="C?"  Part="1" 
AR Path="/5B6F6CC2/5B7047F4" Ref="C?"  Part="1" 
F 0 "C?" H 4455 7060 50  0000 L CNN
F 1 "0.1uF" H 4455 6860 50  0000 L CNN
F 2 "" H 4468 6810 50  0001 C CNN
F 3 "" H 4455 7060 50  0001 C CNN
F 4 "0603" H 4280 7060 50  0000 R CNN "display_footprint"
F 5 "50V" H 4280 6960 50  0000 R CNN "Voltage"
F 6 "X7R" H 4280 6860 50  0000 R CNN "Dielectric"
F 7 "PN" H 4855 7460 60  0001 C CNN "Digi-Key PN"
	1    4430 6960
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5B7047FF
P 4750 6960
AR Path="/5B6F6CF0/5B7047FF" Ref="C?"  Part="1" 
AR Path="/5B6F6CC2/5B7047FF" Ref="C?"  Part="1" 
F 0 "C?" H 4775 7060 50  0000 L CNN
F 1 "10nF" H 4775 6860 50  0000 L CNN
F 2 "" H 4788 6810 50  0001 C CNN
F 3 "" H 4775 7060 50  0001 C CNN
F 4 "0603" H 4600 7060 50  0001 R CNN "display_footprint"
F 5 "50V" H 4600 6960 50  0001 R CNN "Voltage"
F 6 "X7R" H 4600 6860 50  0001 R CNN "Dielectric"
F 7 "PN" H 5175 7460 60  0001 C CNN "Digi-Key PN"
	1    4750 6960
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5B70480A
P 5070 6960
AR Path="/5B6F6CF0/5B70480A" Ref="C?"  Part="1" 
AR Path="/5B6F6CC2/5B70480A" Ref="C?"  Part="1" 
F 0 "C?" H 5095 7060 50  0000 L CNN
F 1 "1nF" H 5095 6860 50  0000 L CNN
F 2 "" H 5108 6810 50  0001 C CNN
F 3 "" H 5095 7060 50  0001 C CNN
F 4 "0603" H 4920 7060 50  0001 R CNN "display_footprint"
F 5 "50V" H 4920 6960 50  0001 R CNN "Voltage"
F 6 "X7R" H 4920 6860 50  0001 R CNN "Dielectric"
F 7 "PN" H 5495 7460 60  0001 C CNN "Digi-Key PN"
	1    5070 6960
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V #PWR?
U 1 1 5B704811
P 4750 6730
F 0 "#PWR?" H 4750 6580 50  0001 C CNN
F 1 "+3.3V" H 4750 6870 50  0000 C CNN
F 2 "" H 4750 6730 50  0000 C CNN
F 3 "" H 4750 6730 50  0000 C CNN
	1    4750 6730
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5B7055B0
P 5690 7010
F 0 "R?" V 5790 7010 50  0000 C CNN
F 1 "10k" V 5690 7010 50  0000 C CNN
F 2 "" H 5690 7010 50  0001 C CNN
F 3 "" H 5690 7010 50  0001 C CNN
F 4 "0603" H 5491 7010 50  0000 C CNN "display_footprint"
F 5 "1%" H 5491 6919 50  0000 C CNN "Tolerance"
F 6 "1/10W" H 5490 7090 50  0000 C CNN "Wattage"
F 7 "PN" H 5990 7410 60  0001 C CNN "Digi-Key PN"
	1    5690 7010
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V #PWR?
U 1 1 5B705C01
P 5690 6860
F 0 "#PWR?" H 5690 6710 50  0001 C CNN
F 1 "+3.3V" H 5690 7000 50  0000 C CNN
F 2 "" H 5690 6860 50  0000 C CNN
F 3 "" H 5690 6860 50  0000 C CNN
	1    5690 6860
	1    0    0    -1  
$EndComp
$EndSCHEMATC
