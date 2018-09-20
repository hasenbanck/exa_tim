EESchema Schematic File Version 4
LIBS:exa_tim-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "exa_tim"
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 1950 1800 0    50   ~ 0
NRST
$Comp
L Device:R R1
U 1 1 5B799578
P 2050 2000
F 0 "R1" V 2150 1950 50  0000 L CNN
F 1 "1M" V 1950 1950 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1980 2000 50  0001 C CNN
F 3 "~" H 2050 2000 50  0001 C CNN
	1    2050 2000
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5B7997A3
P 1900 2000
F 0 "#PWR04" H 1900 1750 50  0001 C CNN
F 1 "GND" H 1905 1827 50  0000 C CNN
F 2 "" H 1900 2000 50  0001 C CNN
F 3 "" H 1900 2000 50  0001 C CNN
	1    1900 2000
	0    1    1    0   
$EndComp
$Comp
L Device:C C1
U 1 1 5B7998EE
P 1250 1250
F 0 "C1" H 1365 1296 50  0000 L CNN
F 1 "4.7uF" H 1365 1205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1288 1100 50  0001 C CNN
F 3 "~" H 1250 1250 50  0001 C CNN
	1    1250 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C9
U 1 1 5B799A8A
P 3400 1250
F 0 "C9" H 3515 1296 50  0000 L CNN
F 1 "100nF" H 3515 1205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3438 1100 50  0001 C CNN
F 3 "~" H 3400 1250 50  0001 C CNN
	1    3400 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5B799B13
P 1700 1250
F 0 "C4" H 1815 1296 50  0000 L CNN
F 1 "100nF" H 1815 1205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1738 1100 50  0001 C CNN
F 3 "~" H 1700 1250 50  0001 C CNN
	1    1700 1250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5B799D7E
P 2750 900
F 0 "#PWR07" H 2750 650 50  0001 C CNN
F 1 "GND" H 2755 727 50  0000 C CNN
F 2 "" H 2750 900 50  0001 C CNN
F 3 "" H 2750 900 50  0001 C CNN
	1    2750 900 
	-1   0    0    1   
$EndComp
Wire Wire Line
	2700 1400 2700 1600
Wire Wire Line
	2750 900  2750 1100
Connection ~ 1700 1100
Connection ~ 1700 1400
Wire Wire Line
	1250 1100 1700 1100
Wire Wire Line
	1250 1400 1700 1400
$Comp
L Device:Crystal_Small Y1
U 1 1 5B79A698
P 1700 2450
F 0 "Y1" V 1900 2450 50  0000 C CNN
F 1 "ST2012SB32768B0HPWBB" V 1450 2450 50  0000 C CNN
F 2 "exa_tim:Crystal_SMD_TXC_9HT11-2Pin_2.0x1.2mm_HandSoldering" H 1700 2450 50  0001 C CNN
F 3 "https://www.mouser.de/datasheet/2/909/st2012sb_e-1316888.pdf" H 1700 2450 50  0001 C CNN
	1    1700 2450
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C2
U 1 1 5B79A7F6
P 1400 2350
F 0 "C2" V 1700 2200 50  0000 L CNN
F 1 "4pF" V 1800 2200 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1400 2350 50  0001 C CNN
F 3 "~" H 1400 2350 50  0001 C CNN
	1    1400 2350
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C3
U 1 1 5B79BC65
P 1400 2550
F 0 "C3" V 1500 2600 50  0000 L CNN
F 1 "4pF" V 1600 2600 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1400 2550 50  0001 C CNN
F 3 "~" H 1400 2550 50  0001 C CNN
	1    1400 2550
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5B79BE68
P 1200 2450
F 0 "#PWR02" H 1200 2200 50  0001 C CNN
F 1 "GND" V 1205 2322 50  0000 R CNN
F 2 "" H 1200 2450 50  0001 C CNN
F 3 "" H 1200 2450 50  0001 C CNN
	1    1200 2450
	0    1    1    0   
$EndComp
Wire Wire Line
	1200 2450 1200 2350
Wire Wire Line
	1200 2350 1300 2350
Wire Wire Line
	1200 2450 1200 2550
Wire Wire Line
	1200 2550 1300 2550
Connection ~ 1200 2450
Connection ~ 1700 2350
Connection ~ 1700 2550
Wire Wire Line
	1500 2350 1700 2350
Wire Wire Line
	1500 2550 1700 2550
Text Label 4050 1800 2    50   ~ 0
WKUP1
Text Label 1900 2700 0    50   ~ 0
DC
Text Label 1900 2800 0    50   ~ 0
RESET
Text Label 4050 2300 2    50   ~ 0
SCK
Text Label 4050 2600 2    50   ~ 0
CS
Text Label 4050 2500 2    50   ~ 0
MOSI
Text Label 4050 2400 2    50   ~ 0
BUSY
Wire Wire Line
	4050 1800 3400 1800
Wire Wire Line
	3400 2000 4050 2000
Wire Wire Line
	4050 2200 3400 2200
Wire Wire Line
	3400 2300 4050 2300
Wire Wire Line
	4050 2400 3400 2400
Wire Wire Line
	3400 2500 4050 2500
Text Label 4050 3100 2    50   ~ 0
SWDIO
Text Label 4050 3200 2    50   ~ 0
SWCLK
Text Label 1900 3100 0    50   ~ 0
BTN4
Text Label 1900 3000 0    50   ~ 0
BTN1
Text Label 1900 3200 0    50   ~ 0
BTN3
Wire Wire Line
	4050 3100 3400 3100
Wire Wire Line
	3400 3200 4050 3200
$Comp
L Connector_Generic:Conn_01x24 J2
U 1 1 5B7B0E50
P 10850 1950
F 0 "J2" H 10769 525 50  0000 C CNN
F 1 "FH12-24S-0.5SH(55)" H 10769 616 50  0000 C CNN
F 2 "exa_tim:Hirose_FH12-24S-0.5SH_1x24-1MP_P0.50mm_Horizontal" H 10850 1950 50  0001 C CNN
F 3 "https://www.mouser.de/datasheet/2/185/FH12_catalog-939276.pdf" H 10850 1950 50  0001 C CNN
	1    10850 1950
	1    0    0    -1  
$EndComp
Text Label 10250 950  0    50   ~ 0
GDR
Text Label 10250 1050 0    50   ~ 0
RESE
Text Label 10250 1650 0    50   ~ 0
BUSY
$Comp
L power:GND #PWR020
U 1 1 5B7B5AFB
P 10250 1550
F 0 "#PWR020" H 10250 1300 50  0001 C CNN
F 1 "GND" V 10255 1422 50  0000 R CNN
F 2 "" H 10250 1550 50  0001 C CNN
F 3 "" H 10250 1550 50  0001 C CNN
	1    10250 1550
	0    1    1    0   
$EndComp
Text Label 10250 1750 0    50   ~ 0
RESET
Text Label 10250 1850 0    50   ~ 0
DC
Text Label 10250 1950 0    50   ~ 0
CS
Text Label 10250 2050 0    50   ~ 0
SCK
Text Label 10250 2150 0    50   ~ 0
MOSI
$Comp
L Device:C C15
U 1 1 5B7B6BFD
P 9700 1150
F 0 "C15" V 9450 1150 50  0000 C CNN
F 1 "1uF" V 9550 1150 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9738 1000 50  0001 C CNN
F 3 "~" H 9700 1150 50  0001 C CNN
F 4 "25V" V 9700 1150 50  0001 C CNN "Notice"
	1    9700 1150
	0    1    1    0   
$EndComp
$Comp
L Device:C C16
U 1 1 5B7B6CB0
P 9700 1350
F 0 "C16" V 9550 1350 50  0000 C CNN
F 1 "1uF" V 9450 1350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9738 1200 50  0001 C CNN
F 3 "~" H 9700 1350 50  0001 C CNN
F 4 "25V" V 9700 1350 50  0001 C CNN "Notice"
	1    9700 1350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	10250 950  10650 950 
Wire Wire Line
	10650 1050 10250 1050
Wire Wire Line
	10250 1650 10650 1650
Wire Wire Line
	10650 1550 10250 1550
Wire Wire Line
	10250 1750 10650 1750
Wire Wire Line
	10250 1850 10650 1850
Wire Wire Line
	10650 1950 10250 1950
Wire Wire Line
	10250 2050 10650 2050
Wire Wire Line
	10650 2150 10250 2150
Wire Wire Line
	9850 1150 10650 1150
Wire Wire Line
	10650 1250 9850 1250
Wire Wire Line
	9850 1250 9850 1350
$Comp
L power:GND #PWR017
U 1 1 5B7C346F
P 9400 1250
F 0 "#PWR017" H 9400 1000 50  0001 C CNN
F 1 "GND" V 9405 1122 50  0000 R CNN
F 2 "" H 9400 1250 50  0001 C CNN
F 3 "" H 9400 1250 50  0001 C CNN
	1    9400 1250
	0    1    1    0   
$EndComp
Text GLabel 950  3850 2    50   Input ~ 0
3V
Text GLabel 1250 1400 0    50   Input ~ 0
3V
Text GLabel 3400 1400 2    50   Input ~ 0
3V
$Comp
L power:GND #PWR01
U 1 1 5B7D2F4F
P 900 4350
F 0 "#PWR01" H 900 4100 50  0001 C CNN
F 1 "GND" H 905 4177 50  0000 C CNN
F 2 "" H 900 4350 50  0001 C CNN
F 3 "" H 900 4350 50  0001 C CNN
	1    900  4350
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT1
U 1 1 5B7D3EFE
P 900 4150
F 0 "BT1" H 1018 4246 50  0000 L CNN
F 1 "3034TR" H 1018 4155 50  0000 L CNN
F 2 "exa_tim:BatteryHolder_Keystone_3034_1x20mm" V 900 4210 50  0001 C CNN
F 3 "http://www.keyelco.com/product-pdf.cfm?p=798" V 900 4210 50  0001 C CNN
F 4 "CR2032" H 900 4150 50  0001 C CNN "Notice"
	1    900  4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  3850 900  3850
Wire Wire Line
	900  3850 900  3950
Wire Wire Line
	900  4350 900  4250
Text GLabel 10400 2350 0    50   Input ~ 0
3V
Wire Wire Line
	10400 2350 10500 2350
Wire Wire Line
	10500 2250 10500 2350
Wire Wire Line
	10500 2250 10650 2250
Connection ~ 10500 2350
Wire Wire Line
	10500 2350 10650 2350
$Comp
L Device:C C18
U 1 1 5B7ED062
P 9700 2200
F 0 "C18" V 9600 2050 50  0000 C CNN
F 1 "1uF" V 9600 2350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9738 2050 50  0001 C CNN
F 3 "~" H 9700 2200 50  0001 C CNN
F 4 "6V" V 9700 2200 50  0001 C CNN "Notice"
	1    9700 2200
	0    1    1    0   
$EndComp
$Comp
L Device:C C17
U 1 1 5B7E4735
P 9700 1950
F 0 "C17" V 9600 1800 50  0000 C CNN
F 1 "100nF" V 9600 2150 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9738 1800 50  0001 C CNN
F 3 "~" H 9700 1950 50  0001 C CNN
F 4 "6V" V 9700 1950 50  0001 C CNN "Notice"
	1    9700 1950
	0    1    1    0   
$EndComp
$Comp
L Device:C C19
U 1 1 5B7F1D8F
P 9700 2450
F 0 "C19" V 9600 2300 50  0000 C CNN
F 1 "1uF" V 9600 2600 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9738 2300 50  0001 C CNN
F 3 "~" H 9700 2450 50  0001 C CNN
F 4 "6V" V 9700 2450 50  0001 C CNN "Notice"
	1    9700 2450
	0    1    1    0   
$EndComp
$Comp
L Device:C C20
U 1 1 5B7F306B
P 9700 2700
F 0 "C20" V 9600 2550 50  0000 C CNN
F 1 "1uF" V 9600 2850 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9738 2550 50  0001 C CNN
F 3 "~" H 9700 2700 50  0001 C CNN
F 4 "25V" V 9700 2700 50  0001 C CNN "Notice"
	1    9700 2700
	0    1    1    0   
$EndComp
$Comp
L Device:C C21
U 1 1 5B7F433C
P 9700 2950
F 0 "C21" V 9600 2800 50  0000 C CNN
F 1 "1uF" V 9600 3100 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9738 2800 50  0001 C CNN
F 3 "~" H 9700 2950 50  0001 C CNN
F 4 "50V" V 9700 2950 50  0001 C CNN "Notice"
	1    9700 2950
	0    1    1    0   
$EndComp
$Comp
L Device:C C22
U 1 1 5B7F560C
P 9700 3200
F 0 "C22" V 9600 3050 50  0000 C CNN
F 1 "1uF" V 9600 3350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9738 3050 50  0001 C CNN
F 3 "~" H 9700 3200 50  0001 C CNN
F 4 "25V" V 9700 3200 50  0001 C CNN "Notice"
	1    9700 3200
	0    1    1    0   
$EndComp
$Comp
L Device:C C23
U 1 1 5B7F68E5
P 9700 3450
F 0 "C23" V 9600 3300 50  0000 C CNN
F 1 "1uF" V 9600 3600 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9738 3300 50  0001 C CNN
F 3 "~" H 9700 3450 50  0001 C CNN
F 4 "50V" V 9700 3450 50  0001 C CNN "Notice"
	1    9700 3450
	0    1    1    0   
$EndComp
$Comp
L Device:C C24
U 1 1 5B7F7D57
P 9700 3700
F 0 "C24" V 9600 3550 50  0000 C CNN
F 1 "1uF" V 9600 3850 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9738 3550 50  0001 C CNN
F 3 "~" H 9700 3700 50  0001 C CNN
F 4 "6V" V 9700 3700 50  0001 C CNN "Notice"
	1    9700 3700
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR018
U 1 1 5B7F7D5E
P 9400 2700
F 0 "#PWR018" H 9400 2450 50  0001 C CNN
F 1 "GND" V 9405 2572 50  0000 R CNN
F 2 "" H 9400 2700 50  0001 C CNN
F 3 "" H 9400 2700 50  0001 C CNN
	1    9400 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	10500 2250 10200 2250
Wire Wire Line
	10200 2250 10200 1950
Wire Wire Line
	10200 1950 9850 1950
Connection ~ 10500 2250
Wire Wire Line
	10150 2200 9850 2200
$Comp
L power:GND #PWR021
U 1 1 5B7FD764
P 10650 2450
F 0 "#PWR021" H 10650 2200 50  0001 C CNN
F 1 "GND" V 10655 2322 50  0000 R CNN
F 2 "" H 10650 2450 50  0001 C CNN
F 3 "" H 10650 2450 50  0001 C CNN
	1    10650 2450
	0    1    1    0   
$EndComp
Wire Wire Line
	10650 2550 10150 2550
Wire Wire Line
	10150 2200 10150 2550
Wire Wire Line
	10650 2650 10100 2650
Wire Wire Line
	10100 2650 10100 2450
Wire Wire Line
	10100 2450 9850 2450
Wire Wire Line
	10650 2750 10400 2750
Wire Wire Line
	10400 2750 10400 2700
Wire Wire Line
	10400 2700 9850 2700
Wire Wire Line
	10650 2950 10300 2950
Wire Wire Line
	10300 2950 10300 3200
Wire Wire Line
	10300 3200 9850 3200
Wire Wire Line
	10650 2850 10250 2850
Wire Wire Line
	10250 2850 10250 2950
Wire Wire Line
	10250 2950 9850 2950
Text Label 10200 2950 2    50   ~ 0
PREVGH
Wire Wire Line
	9850 3450 10400 3450
Wire Wire Line
	10400 3450 10400 3050
Wire Wire Line
	10400 3050 10650 3050
Text Label 10200 3450 2    50   ~ 0
PREVGL
Wire Wire Line
	10650 3150 10550 3150
Wire Wire Line
	10550 3150 10550 3700
Wire Wire Line
	10550 3700 9850 3700
Wire Wire Line
	9400 1250 9400 1150
Wire Wire Line
	9400 1150 9550 1150
Wire Wire Line
	9400 1250 9400 1350
Wire Wire Line
	9400 1350 9550 1350
Connection ~ 9400 1250
Wire Wire Line
	9400 2700 9400 2450
Wire Wire Line
	9400 1950 9550 1950
Wire Wire Line
	9400 2700 9400 2950
Wire Wire Line
	9400 3700 9550 3700
Connection ~ 9400 2700
Wire Wire Line
	9550 3450 9400 3450
Connection ~ 9400 3450
Wire Wire Line
	9400 3450 9400 3700
Wire Wire Line
	9550 3200 9400 3200
Connection ~ 9400 3200
Wire Wire Line
	9400 3200 9400 3450
Wire Wire Line
	9550 2950 9400 2950
Connection ~ 9400 2950
Wire Wire Line
	9400 2950 9400 3200
Wire Wire Line
	9550 2700 9400 2700
Wire Wire Line
	9550 2200 9400 2200
Connection ~ 9400 2200
Wire Wire Line
	9400 2200 9400 1950
Wire Wire Line
	9550 2450 9400 2450
Connection ~ 9400 2450
Wire Wire Line
	9400 2450 9400 2200
$Comp
L Device:D_Schottky_ALT D5
U 1 1 5B84CDBF
P 10300 4000
F 0 "D5" H 10300 4216 50  0000 C CNN
F 1 "MBR0530" H 10300 4125 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 10300 4000 50  0001 C CNN
F 3 "https://www.fairchildsemi.com/datasheets/MB/MBR0530.pdf" H 10300 4000 50  0001 C CNN
	1    10300 4000
	-1   0    0    1   
$EndComp
$Comp
L Device:D_Schottky_ALT D6
U 1 1 5B85311F
P 10300 4550
F 0 "D6" H 10300 4766 50  0000 C CNN
F 1 "MBR0530" H 10300 4675 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 10300 4550 50  0001 C CNN
F 3 "https://www.fairchildsemi.com/datasheets/MB/MBR0530.pdf" H 10300 4550 50  0001 C CNN
	1    10300 4550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR022
U 1 1 5B85C572
P 10650 4000
F 0 "#PWR022" H 10650 3750 50  0001 C CNN
F 1 "GND" V 10655 3872 50  0000 R CNN
F 2 "" H 10650 4000 50  0001 C CNN
F 3 "" H 10650 4000 50  0001 C CNN
	1    10650 4000
	0    -1   -1   0   
$EndComp
Text Label 10650 4550 0    50   ~ 0
PREVGL
Wire Wire Line
	10650 4000 10450 4000
Wire Wire Line
	10650 4550 10450 4550
Wire Wire Line
	10150 4000 9950 4000
Wire Wire Line
	9950 4000 9950 4250
Wire Wire Line
	9950 4550 10150 4550
$Comp
L Device:C C14
U 1 1 5B866A6E
P 9550 4550
F 0 "C14" H 9665 4596 50  0000 L CNN
F 1 "100nF" H 9665 4505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9588 4400 50  0001 C CNN
F 3 "~" H 9550 4550 50  0001 C CNN
F 4 "50V" H 9550 4550 50  0001 C CNN "Notice"
	1    9550 4550
	1    0    0    -1  
$EndComp
Text Label 10650 4850 0    50   ~ 0
PREVGH
$Comp
L Device:D_Schottky_ALT D7
U 1 1 5B86AB68
P 10300 4850
F 0 "D7" H 10300 5066 50  0000 C CNN
F 1 "MBR0530" H 10300 4975 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 10300 4850 50  0001 C CNN
F 3 "https://www.fairchildsemi.com/datasheets/MB/MBR0530.pdf" H 10300 4850 50  0001 C CNN
	1    10300 4850
	-1   0    0    1   
$EndComp
Wire Wire Line
	10650 4850 10450 4850
$Comp
L Device:L_Core_Iron L1
U 1 1 5B887087
P 9050 4850
F 0 "L1" V 9275 4850 50  0000 C CNN
F 1 "LPS4018-683MRB" V 9184 4850 50  0000 C CNN
F 2 "exa_tim:L_Coilcraft_LPS4018" H 9050 4850 50  0001 C CNN
F 3 "https://www.mouser.de/datasheet/2/597/lps4018-270702.pdf" H 9050 4850 50  0001 C CNN
	1    9050 4850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9550 4700 9550 4850
Connection ~ 9550 4850
Wire Wire Line
	9550 4850 10150 4850
Wire Wire Line
	9550 4400 9550 4250
Wire Wire Line
	9550 4250 9950 4250
Connection ~ 9950 4250
Wire Wire Line
	9950 4250 9950 4550
Text GLabel 8250 4850 0    50   Input ~ 0
3V
$Comp
L Device:C C13
U 1 1 5B89DBF9
P 8500 5000
F 0 "C13" H 8615 5046 50  0000 L CNN
F 1 "4.7uF" H 8615 4955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8538 4850 50  0001 C CNN
F 3 "~" H 8500 5000 50  0001 C CNN
F 4 "6V" H 8500 5000 50  0001 C CNN "Notice"
	1    8500 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 4850 8500 4850
Connection ~ 8500 4850
$Comp
L power:GND #PWR016
U 1 1 5B8A5F93
P 8500 5150
F 0 "#PWR016" H 8500 4900 50  0001 C CNN
F 1 "GND" H 8505 4977 50  0000 C CNN
F 2 "" H 8500 5150 50  0001 C CNN
F 3 "" H 8500 5150 50  0001 C CNN
	1    8500 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q2
U 1 1 5B8A63F8
P 9450 5350
F 0 "Q2" H 9656 5396 50  0000 L CNN
F 1 "DMN3067LW-7" H 9656 5305 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-323_SC-70" H 9650 5450 50  0001 C CNN
F 3 "https://www.mouser.de/datasheet/2/115/DMN3067LW-335715.pdf" H 9450 5350 50  0001 C CNN
	1    9450 5350
	1    0    0    -1  
$EndComp
Text Label 9150 5650 0    50   ~ 0
GDR
$Comp
L Device:R R5
U 1 1 5B8A6DE8
P 9150 5850
F 0 "R5" H 9220 5896 50  0000 L CNN
F 1 "1M" H 9220 5805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9080 5850 50  0001 C CNN
F 3 "~" H 9150 5850 50  0001 C CNN
	1    9150 5850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5B8AB1E0
P 9550 5850
F 0 "R6" H 9620 5896 50  0000 L CNN
F 1 "3" H 9620 5805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9480 5850 50  0001 C CNN
F 3 "~" H 9550 5850 50  0001 C CNN
	1    9550 5850
	1    0    0    -1  
$EndComp
Text Label 9550 5650 0    50   ~ 0
RESE
Wire Wire Line
	9550 5550 9550 5700
Wire Wire Line
	9250 5350 9150 5350
Wire Wire Line
	9150 5350 9150 5700
$Comp
L power:GND #PWR019
U 1 1 5B8D2DD0
P 9550 6100
F 0 "#PWR019" H 9550 5850 50  0001 C CNN
F 1 "GND" H 9555 5927 50  0000 C CNN
F 2 "" H 9550 6100 50  0001 C CNN
F 3 "" H 9550 6100 50  0001 C CNN
	1    9550 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9550 6100 9150 6100
Wire Wire Line
	9150 6100 9150 6000
Wire Wire Line
	9550 6100 9550 6000
Connection ~ 9550 6100
Wire Wire Line
	9550 4850 9550 5150
$Comp
L Connector:Conn_ARM_JTAG_SWD_10 J1
U 1 1 5B8F5704
P 2350 6450
F 0 "J1" H 1910 6496 50  0000 R CNN
F 1 "20021112-00010T4LF" H 1910 6405 50  0000 R CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_2x05_P1.27mm_Horizontal" H 2400 5900 50  0001 L TNN
F 3 "http://infocenter.arm.com/help/topic/com.arm.doc.faqs/attached/13634/cortex_debug_connectors.pdf" V 2000 5200 50  0001 C CNN
	1    2350 6450
	1    0    0    -1  
$EndComp
Text Label 3150 6150 2    50   ~ 0
NRST
Text GLabel 2350 5850 1    50   Input ~ 0
3V
$Comp
L power:GND #PWR06
U 1 1 5B8F6BE0
P 2350 7050
F 0 "#PWR06" H 2350 6800 50  0001 C CNN
F 1 "GND" H 2355 6877 50  0000 C CNN
F 2 "" H 2350 7050 50  0001 C CNN
F 3 "" H 2350 7050 50  0001 C CNN
	1    2350 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 7050 2350 7050
Connection ~ 2350 7050
Text Label 3150 6450 2    50   ~ 0
SWDIO
Text Label 3150 6350 2    50   ~ 0
SWCLK
Wire Wire Line
	3150 6150 2850 6150
Wire Wire Line
	2850 6350 3150 6350
Wire Wire Line
	3150 6450 2850 6450
NoConn ~ 2850 6550
NoConn ~ 2850 6650
Wire Wire Line
	8500 4850 8900 4850
Wire Wire Line
	9200 4850 9550 4850
$Comp
L Switch:SW_SPST SW4
U 1 1 5B79FE2A
P 5650 6050
F 0 "SW4" H 5650 6285 50  0000 C CNN
F 1 "TL3305CF260QG" H 5650 6194 50  0000 C CNN
F 2 "exa_tim:TL3305" H 5650 6050 50  0001 C CNN
F 3 "https://www.mouser.de/datasheet/2/140/TL3305-844809.pdf" H 5650 6050 50  0001 C CNN
	1    5650 6050
	1    0    0    -1  
$EndComp
Text GLabel 4400 4850 0    50   Input ~ 0
3V
Text Label 6000 6050 0    50   ~ 0
BTN4
Text Label 6000 4450 0    50   ~ 0
BTN1
Text Label 6000 5550 0    50   ~ 0
BTN3
Text Label 6000 5000 0    50   ~ 0
BTN2
Wire Wire Line
	4850 4450 5450 4450
Wire Wire Line
	5450 5550 4850 5550
Wire Wire Line
	4850 5000 5450 5000
$Comp
L Switch:SW_SPST SW1
U 1 1 5B85171C
P 5650 4450
F 0 "SW1" H 5650 4685 50  0000 C CNN
F 1 "TL3305CF260QG" H 5650 4594 50  0000 C CNN
F 2 "exa_tim:TL3305" H 5650 4450 50  0001 C CNN
F 3 "https://www.mouser.de/datasheet/2/140/TL3305-844809.pdf" H 5650 4450 50  0001 C CNN
	1    5650 4450
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW3
U 1 1 5B8574B6
P 5650 5550
F 0 "SW3" H 5650 5785 50  0000 C CNN
F 1 "TL3305CF260QG" H 5650 5694 50  0000 C CNN
F 2 "exa_tim:TL3305" H 5650 5550 50  0001 C CNN
F 3 "https://www.mouser.de/datasheet/2/140/TL3305-844809.pdf" H 5650 5550 50  0001 C CNN
	1    5650 5550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW2
U 1 1 5B85D253
P 5650 5000
F 0 "SW2" H 5650 5235 50  0000 C CNN
F 1 "TL3305CF260QG" H 5650 5144 50  0000 C CNN
F 2 "exa_tim:TL3305" H 5650 5000 50  0001 C CNN
F 3 "https://www.mouser.de/datasheet/2/140/TL3305-844809.pdf" H 5650 5000 50  0001 C CNN
	1    5650 5000
	1    0    0    -1  
$EndComp
$Comp
L exa_tim:CAM-M8Q-0 U2
U 1 1 5B7BC488
P 6350 1800
F 0 "U2" H 6350 2667 50  0000 C CNN
F 1 "CAM-M8C-0" H 6350 2576 50  0000 C CNN
F 2 "exa_tim:LCC100P960X1400X210-31N" H 5800 800 50  0001 L BNN
F 3 "" H 5450 900 50  0001 L BNN
	1    6350 1800
	1    0    0    -1  
$EndComp
Text Label 7750 1600 2    50   ~ 0
RF
Text Label 4850 1600 0    50   ~ 0
RF
NoConn ~ 5250 1500
NoConn ~ 5250 1800
NoConn ~ 7450 2000
NoConn ~ 7450 2100
NoConn ~ 7450 2200
NoConn ~ 7450 1800
Text Label 7750 1700 2    50   ~ 0
TX_GNSS
Text Label 4850 1700 0    50   ~ 0
RX_GNSS
NoConn ~ 5250 1900
NoConn ~ 5250 2000
NoConn ~ 5250 2100
NoConn ~ 5250 2200
$Comp
L Device:R R3
U 1 1 5B819EC8
P 7050 3000
F 0 "R3" V 6843 3000 50  0000 C CNN
F 1 "220" V 6934 3000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6980 3000 50  0001 C CNN
F 3 "~" H 7050 3000 50  0001 C CNN
	1    7050 3000
	0    1    1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 5B81AB2F
P 7050 3350
F 0 "R4" V 6843 3350 50  0000 C CNN
F 1 "220" V 6934 3350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6980 3350 50  0001 C CNN
F 3 "~" H 7050 3350 50  0001 C CNN
	1    7050 3350
	0    1    1    0   
$EndComp
Wire Wire Line
	7450 1700 7750 1700
Wire Wire Line
	7450 1600 7750 1600
Wire Wire Line
	5250 1600 4850 1600
Wire Wire Line
	4850 1700 5250 1700
Text Label 6650 3000 0    50   ~ 0
RX
Text Label 6650 3350 0    50   ~ 0
TX
Text Label 7600 3000 2    50   ~ 0
TX_GNSS
Text Label 7600 3350 2    50   ~ 0
RX_GNSS
Wire Wire Line
	7600 3000 7200 3000
Wire Wire Line
	7600 3350 7200 3350
Wire Wire Line
	6900 3350 6650 3350
Wire Wire Line
	6650 3000 6900 3000
$Comp
L Device:C C12
U 1 1 5B87CF8F
P 7750 1050
F 0 "C12" H 7865 1096 50  0000 L CNN
F 1 "4.7uF" H 7865 1005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7788 900 50  0001 C CNN
F 3 "~" H 7750 1050 50  0001 C CNN
	1    7750 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 1200 7450 1200
Wire Wire Line
	7450 1300 7750 1300
Wire Wire Line
	7750 1300 7750 1200
Connection ~ 7750 1200
Wire Wire Line
	7750 1300 7750 1400
Wire Wire Line
	7750 1400 7450 1400
Connection ~ 7750 1300
$Comp
L power:GND #PWR015
U 1 1 5B8BB7BC
P 7750 900
F 0 "#PWR015" H 7750 650 50  0001 C CNN
F 1 "GND" H 7755 727 50  0000 C CNN
F 2 "" H 7750 900 50  0001 C CNN
F 3 "" H 7750 900 50  0001 C CNN
	1    7750 900 
	-1   0    0    1   
$EndComp
Text Label 4050 1900 2    50   ~ 0
ALARM
Wire Wire Line
	4050 1900 3400 1900
Wire Wire Line
	4050 2100 3400 2100
Text Label 4050 2000 2    50   ~ 0
TX
Text Label 4050 2100 2    50   ~ 0
RX
Text Label 4050 2200 2    50   ~ 0
GNSS_EN
$Comp
L Device:R R2
U 1 1 5B8F6DF3
P 5300 3400
F 0 "R2" H 5370 3446 50  0000 L CNN
F 1 "1M" H 5370 3355 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5230 3400 50  0001 C CNN
F 3 "~" H 5300 3400 50  0001 C CNN
	1    5300 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 3450 5800 3550
Text Label 4900 3250 0    50   ~ 0
GNSS_EN
Wire Wire Line
	4900 3250 5300 3250
Connection ~ 5300 3250
Wire Wire Line
	5300 3250 5500 3250
Text GLabel 5800 3650 2    50   Input ~ 0
3V
$Comp
L MCU_ST_STM32L0:STM32L071KZUx U1
U 1 1 5B9B430A
P 2800 2500
F 0 "U1" H 3150 1650 50  0000 C CNN
F 1 "STM32L071KZUx" H 3400 1550 50  0000 C CNN
F 2 "exa_tim:QFN-32-1EP_5x5mm_P0.5mm_EP3.45x3.45mm" H 2300 1700 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/DM00141136.pdf" H 2800 2500 50  0001 C CNN
	1    2800 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 2350 2200 2400
Wire Wire Line
	1700 2350 2200 2350
Wire Wire Line
	2200 2550 2200 2500
Wire Wire Line
	1700 2550 2200 2550
$Comp
L power:GND #PWR03
U 1 1 5BA5D584
P 1600 1800
F 0 "#PWR03" H 1600 1550 50  0001 C CNN
F 1 "GND" H 1605 1627 50  0000 C CNN
F 2 "" H 1600 1800 50  0001 C CNN
F 3 "" H 1600 1800 50  0001 C CNN
	1    1600 1800
	0    1    1    0   
$EndComp
Wire Wire Line
	1900 1800 2200 1800
$Comp
L power:GND #PWR08
U 1 1 5BA90C64
P 2850 3550
F 0 "#PWR08" H 2850 3300 50  0001 C CNN
F 1 "GND" H 2855 3377 50  0000 C CNN
F 2 "" H 2850 3550 50  0001 C CNN
F 3 "" H 2850 3550 50  0001 C CNN
	1    2850 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 3550 2900 3550
Wire Wire Line
	3000 3550 3000 3400
Wire Wire Line
	2900 3400 2900 3550
Connection ~ 2900 3550
Wire Wire Line
	2900 3550 3000 3550
Wire Wire Line
	2850 3550 2800 3550
Wire Wire Line
	2800 3550 2800 3400
Connection ~ 2850 3550
Wire Wire Line
	2700 3400 2700 3550
Wire Wire Line
	2700 3550 2800 3550
Connection ~ 2800 3550
Wire Wire Line
	2950 1400 3400 1400
Wire Wire Line
	2950 1400 2900 1400
Connection ~ 2950 1400
Wire Wire Line
	2950 1100 3400 1100
Wire Wire Line
	2950 1100 2750 1100
Connection ~ 2950 1100
$Comp
L Device:C C8
U 1 1 5B799B1A
P 2950 1250
F 0 "C8" H 3065 1296 50  0000 L CNN
F 1 "1uF" H 3065 1205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2988 1100 50  0001 C CNN
F 3 "~" H 2950 1250 50  0001 C CNN
	1    2950 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 1600 2900 1400
$Comp
L Device:C C10
U 1 1 5BAE050D
P 3850 1250
F 0 "C10" H 3965 1296 50  0000 L CNN
F 1 "100nF" H 3965 1205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3888 1100 50  0001 C CNN
F 3 "~" H 3850 1250 50  0001 C CNN
	1    3850 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 1400 3850 1600
Wire Wire Line
	3850 1600 3000 1600
Wire Wire Line
	3850 1100 3400 1100
Connection ~ 3400 1100
Text GLabel 3850 1400 2    50   Input ~ 0
3V
Wire Wire Line
	2700 1400 2800 1400
Wire Wire Line
	2800 1400 2800 1600
Wire Wire Line
	1900 2700 2200 2700
Wire Wire Line
	2200 2800 1900 2800
$Comp
L power:GND #PWR010
U 1 1 5BC4EFB6
P 3400 2800
F 0 "#PWR010" H 3400 2550 50  0001 C CNN
F 1 "GND" V 3405 2672 50  0000 R CNN
F 2 "" H 3400 2800 50  0001 C CNN
F 3 "" H 3400 2800 50  0001 C CNN
	1    3400 2800
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR011
U 1 1 5BC4F0C9
P 3400 2900
F 0 "#PWR011" H 3400 2650 50  0001 C CNN
F 1 "GND" V 3405 2772 50  0000 R CNN
F 2 "" H 3400 2900 50  0001 C CNN
F 3 "" H 3400 2900 50  0001 C CNN
	1    3400 2900
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5BC58E50
P 3400 3000
F 0 "#PWR012" H 3400 2750 50  0001 C CNN
F 1 "GND" V 3405 2872 50  0000 R CNN
F 2 "" H 3400 3000 50  0001 C CNN
F 3 "" H 3400 3000 50  0001 C CNN
	1    3400 3000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4050 2600 3400 2600
$Comp
L Device:C C7
U 1 1 5BC8BB8F
P 2500 1250
F 0 "C7" H 2615 1296 50  0000 L CNN
F 1 "100nF" H 2615 1205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2538 1100 50  0001 C CNN
F 3 "~" H 2500 1250 50  0001 C CNN
	1    2500 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 1100 2150 1100
Connection ~ 2750 1100
Wire Wire Line
	2500 1100 2750 1100
Wire Wire Line
	1700 1400 2150 1400
Connection ~ 2700 1400
Wire Wire Line
	2500 1400 2700 1400
$Comp
L Device:D_Schottky_ALT D4
U 1 1 5BCC1FAE
P 6750 6050
F 0 "D4" H 6750 6266 50  0000 C CNN
F 1 "MBR0530" H 6750 6175 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 6750 6050 50  0001 C CNN
F 3 "https://www.fairchildsemi.com/datasheets/MB/MBR0530.pdf" H 6750 6050 50  0001 C CNN
	1    6750 6050
	-1   0    0    1   
$EndComp
$Comp
L Device:D_Schottky_ALT D1
U 1 1 5BCCD658
P 6750 4450
F 0 "D1" H 6750 4666 50  0000 C CNN
F 1 "MBR0530" H 6750 4575 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 6750 4450 50  0001 C CNN
F 3 "https://www.fairchildsemi.com/datasheets/MB/MBR0530.pdf" H 6750 4450 50  0001 C CNN
	1    6750 4450
	-1   0    0    1   
$EndComp
$Comp
L Device:D_Schottky_ALT D3
U 1 1 5BCE28FC
P 6750 5550
F 0 "D3" H 6750 5766 50  0000 C CNN
F 1 "MBR0530" H 6750 5675 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 6750 5550 50  0001 C CNN
F 3 "https://www.fairchildsemi.com/datasheets/MB/MBR0530.pdf" H 6750 5550 50  0001 C CNN
	1    6750 5550
	-1   0    0    1   
$EndComp
$Comp
L Device:D_Schottky_ALT D2
U 1 1 5BCED23B
P 6750 5000
F 0 "D2" H 6750 5216 50  0000 C CNN
F 1 "MBR0530" H 6750 5125 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 6750 5000 50  0001 C CNN
F 3 "https://www.fairchildsemi.com/datasheets/MB/MBR0530.pdf" H 6750 5000 50  0001 C CNN
	1    6750 5000
	-1   0    0    1   
$EndComp
Text Label 7750 5350 2    50   ~ 0
WKUP1
Wire Wire Line
	7200 4450 6900 4450
Wire Wire Line
	6900 6050 7200 6050
Wire Wire Line
	6900 5550 7200 5550
Wire Wire Line
	7200 5550 7200 5350
Connection ~ 7200 5350
Wire Wire Line
	6900 5000 7200 5000
Connection ~ 7200 5550
$Comp
L Device:C C11
U 1 1 5BD98F54
P 7450 5500
F 0 "C11" H 7565 5546 50  0000 L CNN
F 1 "100nF" H 7565 5455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7488 5350 50  0001 C CNN
F 3 "~" H 7450 5500 50  0001 C CNN
	1    7450 5500
	1    0    0    -1  
$EndComp
Connection ~ 7450 5350
Wire Wire Line
	7450 5350 7200 5350
$Comp
L power:GND #PWR014
U 1 1 5BD9905F
P 7450 5650
F 0 "#PWR014" H 7450 5400 50  0001 C CNN
F 1 "GND" H 7455 5477 50  0000 C CNN
F 2 "" H 7450 5650 50  0001 C CNN
F 3 "" H 7450 5650 50  0001 C CNN
	1    7450 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 5350 7750 5350
Wire Wire Line
	5850 6050 6600 6050
Wire Wire Line
	5850 4450 6600 4450
Wire Wire Line
	5850 5550 6600 5550
Wire Wire Line
	5850 5000 6600 5000
Wire Wire Line
	4400 4850 4850 4850
Wire Wire Line
	4850 6050 5450 6050
Connection ~ 4850 5550
$Comp
L Device:Speaker LS1
U 1 1 5BEA6795
P 3000 5150
F 0 "LS1" H 3170 5146 50  0000 L CNN
F 1 "CUI_CSS-0575A-SMT" H 3170 5055 50  0000 L CNN
F 2 "exa_tim:CUI_CSS-0575A-SMT" H 3000 4950 50  0001 C CNN
F 3 "~" H 2990 5100 50  0001 C CNN
	1    3000 5150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5BEA69F0
P 1950 5250
F 0 "#PWR05" H 1950 5000 50  0001 C CNN
F 1 "GND" V 1955 5122 50  0000 R CNN
F 2 "" H 1950 5250 50  0001 C CNN
F 3 "" H 1950 5250 50  0001 C CNN
	1    1950 5250
	0    1    1    0   
$EndComp
Text Label 1950 5150 0    50   ~ 0
ALARM
Wire Wire Line
	2800 5250 1950 5250
Wire Wire Line
	1900 3100 2200 3100
Wire Wire Line
	2200 3000 1900 3000
Wire Wire Line
	1900 2900 2200 2900
NoConn ~ 10650 850 
NoConn ~ 10650 1350
NoConn ~ 10650 1450
Text Label 1900 2900 0    50   ~ 0
BTN2
Wire Wire Line
	1900 3200 2200 3200
$Comp
L Device:C C6
U 1 1 5B7C7CBE
P 2150 1250
F 0 "C6" H 2265 1296 50  0000 L CNN
F 1 "4.7uF" H 2265 1205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2188 1100 50  0001 C CNN
F 3 "~" H 2150 1250 50  0001 C CNN
	1    2150 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 1100 2500 1100
Connection ~ 2150 1100
Connection ~ 2500 1100
Wire Wire Line
	2500 1400 2150 1400
Connection ~ 2500 1400
Connection ~ 2150 1400
Wire Wire Line
	4850 4850 4850 5000
Connection ~ 4850 5000
Wire Wire Line
	4850 5000 4850 5550
Connection ~ 7200 5000
Wire Wire Line
	7200 5000 7200 5350
Wire Wire Line
	4850 4850 4850 4450
Connection ~ 4850 4850
Wire Wire Line
	7200 4450 7200 5000
Wire Wire Line
	7200 5550 7200 6050
Wire Wire Line
	4850 5550 4850 6050
$Comp
L Device:C C5
U 1 1 5B8A0259
P 1750 1800
F 0 "C5" V 2002 1800 50  0000 C CNN
F 1 "100nF" V 1911 1800 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1788 1650 50  0001 C CNN
F 3 "~" H 1750 1800 50  0001 C CNN
	1    1750 1800
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR09
U 1 1 5B8876BC
P 3400 2700
F 0 "#PWR09" H 3400 2450 50  0001 C CNN
F 1 "GND" V 3405 2572 50  0000 R CNN
F 2 "" H 3400 2700 50  0001 C CNN
F 3 "" H 3400 2700 50  0001 C CNN
	1    3400 2700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1950 5150 2800 5150
$Comp
L Device:Q_PMOS_GSD Q1
U 1 1 5B9F4C7F
P 5700 3250
F 0 "Q1" H 5906 3296 50  0000 L CNN
F 1 "SI2333DS-T1-E3" H 5906 3205 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5900 3350 50  0001 C CNN
F 3 "https://www.vishay.com/docs/72023/72023.pdf" H 5700 3250 50  0001 C CNN
	1    5700 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 3550 5800 3550
Connection ~ 5800 3550
Wire Wire Line
	5800 3550 5800 3650
$Comp
L power:GND #PWR024
U 1 1 5BA03A7E
P 7450 2400
F 0 "#PWR024" H 7450 2150 50  0001 C CNN
F 1 "GND" H 7455 2227 50  0000 C CNN
F 2 "" H 7450 2400 50  0001 C CNN
F 3 "" H 7450 2400 50  0001 C CNN
	1    7450 2400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5800 3050 5800 2850
Text Label 5800 2850 0    50   ~ 0
VDD_GNSS
Text Label 7750 1300 0    50   ~ 0
VDD_GNSS
$Comp
L power:GNDD #PWR013
U 1 1 5BA24559
P 10650 6400
F 0 "#PWR013" H 10650 6150 50  0001 C CNN
F 1 "GNDD" H 10654 6245 50  0000 C CNN
F 2 "" H 10650 6400 50  0001 C CNN
F 3 "" H 10650 6400 50  0001 C CNN
	1    10650 6400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR023
U 1 1 5BA24653
P 10950 6400
F 0 "#PWR023" H 10950 6150 50  0001 C CNN
F 1 "GND" H 10955 6227 50  0000 C CNN
F 2 "" H 10950 6400 50  0001 C CNN
F 3 "" H 10950 6400 50  0001 C CNN
	1    10950 6400
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R7
U 1 1 5BA6FAC8
P 10800 6400
F 0 "R7" V 10593 6400 50  0000 C CNN
F 1 "0" V 10684 6400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 10730 6400 50  0001 C CNN
F 3 "~" H 10800 6400 50  0001 C CNN
	1    10800 6400
	0    1    1    0   
$EndComp
$EndSCHEMATC
