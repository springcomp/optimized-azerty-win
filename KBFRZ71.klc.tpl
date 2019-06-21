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
10	A		5	a	A	-1	-1	00e6	00c6		// a A   æ Æ
11	Z		1	z	Z	-1	-1	00a3	-1		// z Z   £   
12	E		1	e	E	-1	-1	20ac	0000@		// e E   €   
13	R		1	r	R	-1	-1	00ae	-1		// r R   ®   
14	T		1	t	T	-1	-1	007b	2122		// t T   { ™ 
15	Y		1	y	Y	-1	-1	007d	-1		// y Y   }   
16	U		5	u	U	-1	-1	00f9	00d9		// u U   ù Ù 
18	O		5	o	O	-1	-1	0153	0152		// o O   œ Œ 
19	P		1	p	P	-1	-1	0025	2030		// p P   % ‰ 
1a	OEM_MINUS	0	002d	2013	-1	-1	2212	2011		// - –   − ‑ 
1b	OEM_PLUS	0	002b	00b1	-1	-1	2020	2021		// + ±   † ‡ 
1e	Q		5	q	Q	-1	-1	03b8	0398		// q Q   θ Θ  
1f	S		5	s	S	-1	-1	00df	1e9e		// s S   ß ẞ
20	D		1	d	D	-1	-1	0024	-1		// d D   $   
21	F		1	f	F	-1	-1	00a4@	-1		// f F   ¤   
22	G		1	g	G	-1	-1	00b5@	-1		// g G   µ   
23	H		1	h	H	-1	-1	017f@	02cd@		// h H   
24	J		1	j	J	-1	-1	-1	-1		// j J       
26	L		1	l	L	-1	-1	007c	-1		// l L   |   
27	M		1	m	M	-1	-1	221e	-1		// m M   ∞   
28	OEM_3		0	002f	005c	-1	001c	00f7	221a		// / \   ÷ √ 
2b	OEM_5		0	002a	00bd	-1	-1	00d7	00bc		// * ½   × ¼ 
56	OEM_102		0	003c	003e	-1	-1	2a7d	2a7e		// < >   ⩽ ⩾ 
2c	W		5	w	W	-1	-1	0292	01b7		// w W   ʒ Ʒ 
2d	X		1	x	X	-1	-1	00a9	-1		// x X   ©   
2e	C		5	c	C	-1	-1	00e7	00c7		// c C   ç Ç 
2f	V		1	v	V	-1	-1	00b8@	02db@		// v V   ¸ ˛ 
30	B		1	b	B	-1	-1	002d@	-1		// b B     
31	N		1	n	N	-1	-1	007e@	-1		// n N   ~   
32	OEM_PERIOD	0	002e	003f	-1	-1	00bf	-1		// . ?   ¿   
33	OEM_COMMA	0	002c	0021	-1	-1	00a1	002c@		// , !   ¡ , 
34	OEM_2		0	003a	2026	-1	-1	00b7	-1		// : …   ·   
35	OEM_8		0	003b	003d	-1	-1	2243	2260		// ; =   ≃ ≠ 
39	SPACE		0	0020	0020	2003	-1	202f	00a0		//         
53	DECIMAL		0	002e	002e	-1	-1	-1	-1		// . . 

// The following three keys are specifically set last in the layout
// to prevent the Win32 VkKeyScanEx function to report an incorrect
// scan code for the '.', '/' and '°' characters that double as
//
// See https://github.com/springcomp/optimized-azerty-win/issues/73.

29	OEM_7		0	0040	0023	-1	-1	02d8@	00b0@		// @ #   ˘ 
17	I		1	i	I	-1	-1	02d9@	002e@		// i I   ˙ . 
25	K		1	k	K	-1	-1	002f@	-1		// k K   / 

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
