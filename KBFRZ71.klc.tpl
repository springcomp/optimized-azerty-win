KBD	KBFRZ71	"Français - AZERTY NF Z71-300"

COPYRIGHT	"© 2019 Creative Commons"

COMPANY	"Creative Commons"

LOCALENAME	"fr-FR"

LOCALEID	"0000040c"

VERSION	1.0

SHIFTSTATE

0	//Column 4
1	//Column 5 : Shft
2	//Column 6 :       Ctrl
3	//Column 7 : Shft  Ctrl
6	//Column 8 :       Ctrl Alt
7	//Column 9 : Shft  Ctrl Alt

LAYOUT		;an extra '@' at the end is a dead key

//SC	VK_		Cap	4	5	6	7	8	9
//--	----		----	----	----	----	----	----	----

02	1		SGCap	00e0	1	-1	-1	00a7	00c0		// à 1   § À 
-1	-1		0	00c0	1						// À 1 
03	2		SGCap	00e9	2	-1	-1	00b4@	00c9		// é 2   ´ É 
-1	-1		0	00c9	2						// É 2 
04	3		SGCap	00e8	3	-1	-1	0060@	00c8		// è 3   ` È 
-1	-1		0	00c8	3						// È 3 
05	4		SGCap	00ea	4	-1	-1	0026	00ca		// ê 4   & Ê 
-1	-1		0	00ca	4						// Ê 4 
06	5		0	0028	5	-1	001b	005b	02dd@		// ( 5   [ 
07	6		0	0029	6	-1	001d	005d	02f5@		// ) 6   ] 
08	7		0	2018	7	-1	-1	00af@	-1		// ‘ 7   ¯   
09	8		0	2019	8	-1	001f	005f	2014		// ’ 8   _ — 
0a	9		0	00ab	9	-1	-1	201c	2039		// « 9   “ ‹ 
0b	0		0	00bb	0	-1	-1	201d	203a		// » 0   ” › 
0c	OEM_4		0	0027	0022	-1	-1	00b0	02da@		// ' "   ° ˚ 
0d	OEM_6		0	005e@	00a8@	-1	001e	02c7@	-1		// ^ ¨   ˇ   

<? .\automation\make-base-layout.ps1 ?>

<? .\automation\make-dead-tables.ps1 ?>

<? .\automation\make-keynames.ps1 ?>

<? .\automation\make-keynames-dead.ps1 ?>

DESCRIPTIONS

0409	French - AZERTY NF Z71-300
040c	Français - AZERTY NF Z71-300

LANGUAGENAMES

0409	French (France)
040c	Français

ENDKBD
