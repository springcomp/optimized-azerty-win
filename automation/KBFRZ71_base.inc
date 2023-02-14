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
1e	Q		5	q	Q	-1	-1	03b8	03f4		// q Q   θ ϴ  
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
56	OEM_102		0	003c	003e	-1	-1	2264	2265		// < >   ≤ ≥ 
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
39	SPACE		0	0020	0020	2003	-1	00a0	202f		//          
53	DECIMAL		0	002e	002e	-1	-1	-1	-1		// . . 

// The following three keys are specifically set last in the layout
// to prevent the Win32 VkKeyScanEx function to report an incorrect
// scan code for the '.', '/' and '°' characters that double as
//
// See https://github.com/springcomp/optimized-azerty-win/issues/73.

29	OEM_7		0	0040	0023	-1	-1	02d8@	00b0@		// @ #   ˘ 
17	I		1	i	I	-1	-1	02d9@	002e@		// i I   ˙ . 
25	K		1	k	K	-1	-1	002f@	-1		// k K   / 