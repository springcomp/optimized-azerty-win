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

<? Get-Content -Path .\KBFRZ71_base.inc ?>

<? .\automation\make-dead-tables.ps1 ?>

KEYNAME

01	"Échap."
0e	"Ret.Arr."
0f	"Tab"
1c	"Entrée"
1d	"Ctrl"
2a	"Maj"
36	"Maj Droite"
37	"* (Pavé Num.)"
38	"Alt"
39	"Espace"
3a	"Verr. Maj"
3b	"F1"
3c	"F2"
3d	"F3"
3e	"F4"
3f	"F5"
40	"F6"
41	"F7"
42	"F8"
43	"F9"
44	"F10"
45	"Pause"
46	"Défil."
47	"7 (Pavé Num.)"
48	"8 (Pavé Num.)"
49	"9 (Pavé Num.)"
4a	"- (Pavé Num.)"
4b	"4 (Pavé Num.)"
4c	"5 (Pavé Num.)"
4d	"6 (Pavé Num.)"
4e	"+ (Pavé Num.)"
4f	"1 (Pavé Num.)"
50	"2 (Pavé Num.)"
51	"3 (Pavé Num.)"
52	"0 (Pavé Num.)"
53	". (Pavé Num.)"
57	"F11"
58	"F12"
7c	"F13"
7d	"F14"
7e	"F15"
7f	"F16"
80	"F17"
81	"F18"
82	"F19"
83	"F20"
84	"F21"
85	"F22"
86	"F23"
87	"F24"

KEYNAME_EXT

1c	"Entrée (Pavé Num.)"
1d	"Ctrl Droite"
35	"/ (Pavé Num.)"
37	"Impr. Écran"
38	"AltGr"
45	"Verr. Num."
46	"Attn."
47	"Origine"
48	"Haut"
49	"Page Préc."
4b	"Gauche"
4d	"Droite"
4f	"Fin"
50	"Bas"
51	"Page Suiv."
52	"Insér."
53	"Suppr."
54	<00>
56	"Aide"
5b	"Windows Gauche"
5c	"Windows Droite"
5d	"Application"

<? .\automation\make-keynames-dead.ps1 ?>

DESCRIPTIONS

0409	French - AZERTY NF Z71-300
040c	Français - AZERTY NF Z71-300

LANGUAGENAMES

0409	French (France)
040c	Français

ENDKBD
