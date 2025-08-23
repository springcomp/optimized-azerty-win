/***************************************************************************\
* Module Name: KBFRZ71N.C
*
* keyboard layout
*
* Copyright (c) 1985-2001, Microsoft Corporation
*
* History:
* KBDTOOL v3.40 - Created  Sat Aug 23 13:05:16 2025
\***************************************************************************/

#include <windows.h>
#include "kbd.h"
#include "KBFRZ71N.h"

#if defined(_M_IA64)
#pragma section(".data")
#define ALLOC_SECTION_LDATA __declspec(allocate(".data"))
#else
#pragma data_seg(".data")
#define ALLOC_SECTION_LDATA
#endif

/***************************************************************************\
* ausVK[] - Virtual Scan Code to Virtual Key conversion table
\***************************************************************************/

static ALLOC_SECTION_LDATA USHORT ausVK[] = {
    T00, T01, T02, T03, T04, T05, T06, T07,
    T08, T09, T0A, T0B, T0C, T0D, T0E, T0F,
    T10, T11, T12, T13, T14, T15, T16, T17,
    T18, T19, T1A, T1B, T1C, T1D, T1E, T1F,
    T20, T21, T22, T23, T24, T25, T26, T27,
    T28, T29, T2A, T2B, T2C, T2D, T2E, T2F,
    T30, T31, T32, T33, T34, T35,

    /*
     * Right-hand Shift key must have KBDEXT bit set.
     */
    T36 | KBDEXT,

    T37 | KBDMULTIVK,               // numpad_* + Shift/Alt -> SnapShot

    T38, T39, T3A, T3B, T3C, T3D, T3E,
    T3F, T40, T41, T42, T43, T44,

    /*
     * NumLock Key:
     *     KBDEXT     - VK_NUMLOCK is an Extended key
     *     KBDMULTIVK - VK_NUMLOCK or VK_PAUSE (without or with CTRL)
     */
    T45 | KBDEXT | KBDMULTIVK,

    T46 | KBDMULTIVK,

    /*
     * Number Pad keys:
     *     KBDNUMPAD  - digits 0-9 and decimal point.
     *     KBDSPECIAL - require special processing by Windows
     */
    T47 | KBDNUMPAD | KBDSPECIAL,   // Numpad 7 (Home)
    T48 | KBDNUMPAD | KBDSPECIAL,   // Numpad 8 (Up),
    T49 | KBDNUMPAD | KBDSPECIAL,   // Numpad 9 (PgUp),
    T4A,
    T4B | KBDNUMPAD | KBDSPECIAL,   // Numpad 4 (Left),
    T4C | KBDNUMPAD | KBDSPECIAL,   // Numpad 5 (Clear),
    T4D | KBDNUMPAD | KBDSPECIAL,   // Numpad 6 (Right),
    T4E,
    T4F | KBDNUMPAD | KBDSPECIAL,   // Numpad 1 (End),
    T50 | KBDNUMPAD | KBDSPECIAL,   // Numpad 2 (Down),
    T51 | KBDNUMPAD | KBDSPECIAL,   // Numpad 3 (PgDn),
    T52 | KBDNUMPAD | KBDSPECIAL,   // Numpad 0 (Ins),
    T53 | KBDNUMPAD | KBDSPECIAL,   // Numpad . (Del),

    T54, T55, T56, T57, T58, T59, T5A, T5B,
    T5C, T5D, T5E, T5F, T60, T61, T62, T63,
    T64, T65, T66, T67, T68, T69, T6A, T6B,
    T6C, T6D, T6E, T6F, T70, T71, T72, T73,
    T74, T75, T76, T77, T78, T79, T7A, T7B,
    T7C, T7D, T7E

};

static ALLOC_SECTION_LDATA VSC_VK aE0VscToVk[] = {
        { 0x10, X10 | KBDEXT              },  // Speedracer: Previous Track
        { 0x19, X19 | KBDEXT              },  // Speedracer: Next Track
        { 0x1D, X1D | KBDEXT              },  // RControl
        { 0x20, X20 | KBDEXT              },  // Speedracer: Volume Mute
        { 0x21, X21 | KBDEXT              },  // Speedracer: Launch App 2
        { 0x22, X22 | KBDEXT              },  // Speedracer: Media Play/Pause
        { 0x24, X24 | KBDEXT              },  // Speedracer: Media Stop
        { 0x2E, X2E | KBDEXT              },  // Speedracer: Volume Down
        { 0x30, X30 | KBDEXT              },  // Speedracer: Volume Up
        { 0x32, X32 | KBDEXT              },  // Speedracer: Browser Home
        { 0x35, X35 | KBDEXT              },  // Numpad Divide
        { 0x37, X37 | KBDEXT              },  // Snapshot
        { 0x38, X38 | KBDEXT              },  // RMenu
        { 0x47, X47 | KBDEXT              },  // Home
        { 0x48, X48 | KBDEXT              },  // Up
        { 0x49, X49 | KBDEXT              },  // Prior
        { 0x4B, X4B | KBDEXT              },  // Left
        { 0x4D, X4D | KBDEXT              },  // Right
        { 0x4F, X4F | KBDEXT              },  // End
        { 0x50, X50 | KBDEXT              },  // Down
        { 0x51, X51 | KBDEXT              },  // Next
        { 0x52, X52 | KBDEXT              },  // Insert
        { 0x53, X53 | KBDEXT              },  // Delete
        { 0x5B, X5B | KBDEXT              },  // Left Win
        { 0x5C, X5C | KBDEXT              },  // Right Win
        { 0x5D, X5D | KBDEXT              },  // Application
        { 0x5F, X5F | KBDEXT              },  // Speedracer: Sleep
        { 0x65, X65 | KBDEXT              },  // Speedracer: Browser Search
        { 0x66, X66 | KBDEXT              },  // Speedracer: Browser Favorites
        { 0x67, X67 | KBDEXT              },  // Speedracer: Browser Refresh
        { 0x68, X68 | KBDEXT              },  // Speedracer: Browser Stop
        { 0x69, X69 | KBDEXT              },  // Speedracer: Browser Forward
        { 0x6A, X6A | KBDEXT              },  // Speedracer: Browser Back
        { 0x6B, X6B | KBDEXT              },  // Speedracer: Launch App 1
        { 0x6C, X6C | KBDEXT              },  // Speedracer: Launch Mail
        { 0x6D, X6D | KBDEXT              },  // Speedracer: Launch Media Selector
        { 0x1C, X1C | KBDEXT              },  // Numpad Enter
        { 0x46, X46 | KBDEXT              },  // Break (Ctrl + Pause)
        { 0,      0                       }
};

static ALLOC_SECTION_LDATA VSC_VK aE1VscToVk[] = {
        { 0x1D, Y1D                       },  // Pause
        { 0   ,   0                       }
};

/***************************************************************************\
* aVkToBits[]  - map Virtual Keys to Modifier Bits
*
* See kbd.h for a full description.
*
* The keyboard has only three shifter keys:
*     SHIFT (L & R) affects alphabnumeric keys,
*     CTRL  (L & R) is used to generate control characters
*     ALT   (L & R) used for generating characters by number with numpad
\***************************************************************************/
#define KBDRMENU 0x08
static ALLOC_SECTION_LDATA VK_TO_BIT aVkToBits[] = {
    { VK_SHIFT    ,   KBDSHIFT     },
    { VK_CONTROL  ,   KBDCTRL      },
    { VK_MENU     ,   KBDALT       },
    { VK_RMENU    ,   KBDRMENU     },
    { 0           ,   0           }
};

/***************************************************************************\
* aModification[]  - map character modifier bits to modification number
*
* See kbd.h for a full description.
*
\***************************************************************************/

static ALLOC_SECTION_LDATA MODIFIERS CharModifiers = {
    &aVkToBits[0],
    7,
    {
    //  Modification# //  Keys Pressed
    //  ============= // =============
        0,            // 
        1,            // Shift 
        2,            // Control 
        3,            // Shift + Control 
        SHFT_INVALID, // Menu 
        SHFT_INVALID, // Shift + Menu 
        SHFT_INVALID, // Control + Menu 
        SHFT_INVALID, // Shift + Control + Menu 
        8,            // RMenu
        9,            // Shift + RMenu
     }
};

/***************************************************************************\
*
* aVkToWch2[]  - Virtual Key to WCHAR translation for 2 shift states
* aVkToWch3[]  - Virtual Key to WCHAR translation for 3 shift states
* aVkToWch4[]  - Virtual Key to WCHAR translation for 4 shift states
* aVkToWch5[]  - Virtual Key to WCHAR translation for 5 shift states
* aVkToWch6[]  - Virtual Key to WCHAR translation for 6 shift states
*
* Table attributes: Unordered Scan, null-terminated
*
* Search this table for an entry with a matching Virtual Key to find the
* corresponding unshifted and shifted WCHAR characters.
*
* Special values for VirtualKey (column 1)
*     0xff          - dead chars for the previous entry
*     0             - terminate the list
*
* Special values for Attributes (column 2)
*     CAPLOK bit    - CAPS-LOCK affect this key like SHIFT
*
* Special values for wch[*] (column 3 & 4)
*     WCH_NONE      - No character
*     WCH_DEAD      - Dead Key (diaresis) or invalid (US keyboard has none)
*     WCH_LGTR      - Ligature (generates multiple characters)
*
\***************************************************************************/

static ALLOC_SECTION_LDATA VK_TO_WCHARS2 aVkToWch2[] = {
//                      |         |  Shift  |
//                      |=========|=========|
  {VK_TAB       ,0      ,'\t'     ,'\t'     },
  {VK_ADD       ,0      ,'+'      ,'+'      },
  {VK_DIVIDE    ,0      ,'/'      ,'/'      },
  {VK_MULTIPLY  ,0      ,'*'      ,'*'      },
  {VK_SUBTRACT  ,0      ,'-'      ,'-'      },
  {0            ,0      ,0        ,0        }
};

static ALLOC_SECTION_LDATA VK_TO_WCHARS3 aVkToWch3[] = {
//                      |         |  Shift  |  Ctrl   |
//                      |=========|=========|=========|
  {VK_BACK      ,0      ,'\b'     ,'\b'     ,0x007f   },
  {VK_ESCAPE    ,0      ,0x001b   ,0x001b   ,0x001b   },
  {VK_RETURN    ,0      ,'\r'     ,'\r'     ,'\n'     },
  {VK_CANCEL    ,0      ,0x0003   ,0x0003   ,0x0003   },
  {0            ,0      ,0        ,0        ,0        }
};

static ALLOC_SECTION_LDATA VK_TO_WCHARS6 aVkToWch6[] = {
//                      |         |  Shift  |  Ctrl   |S+Ctrl   |  Ctl+Alt|S+Ctl+Alt|
//                      |=========|=========|=========|=========|=========|=========|
  {'1'          ,SGCAPS ,0x00e0   ,'1'      ,WCH_NONE ,WCH_NONE ,0x00a7   ,0x00c0   },
  {'1'          ,0      ,'1'      ,0x00e0   },
  {'2'          ,SGCAPS ,0x00e9   ,'2'      ,WCH_NONE ,WCH_NONE ,WCH_DEAD ,0x00c9   },
  {0xff         ,0      ,'2'      ,0x00e9   ,WCH_NONE ,WCH_NONE ,0x00b4   ,WCH_NONE },
  {'3'          ,SGCAPS ,0x00e8   ,'3'      ,WCH_NONE ,WCH_NONE ,WCH_DEAD ,0x00c8   },
  {0xff         ,0      ,'3'      ,0x00e8   ,WCH_NONE ,WCH_NONE ,'`'      ,WCH_NONE },
  {'4'          ,SGCAPS ,0x00ea   ,'4'      ,WCH_NONE ,WCH_NONE ,'&'      ,0x00ca   },
  {'4'          ,0      ,'4'      ,0x00ea   },
  {'5'          ,SGCAPS ,'('      ,'5'      ,WCH_NONE ,WCH_NONE ,'['      ,WCH_DEAD },
  {0xff         ,0      ,'5'      ,'('      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x02dd   },
  {'6'          ,SGCAPS ,')'      ,'6'      ,WCH_NONE ,WCH_NONE ,']'      ,WCH_DEAD },
  {0xff         ,0      ,'6'      ,')'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x02f5   },
  {'7'          ,SGCAPS ,0x2018   ,'7'      ,WCH_NONE ,WCH_NONE ,WCH_DEAD ,WCH_NONE },
  {0xff         ,0      ,'7'      ,0x2018   ,WCH_NONE ,WCH_NONE ,0x00af   ,WCH_NONE },
  {'8'          ,SGCAPS ,0x2019   ,'8'      ,WCH_NONE ,WCH_NONE ,'_'      ,0x2014   },
  {'8'          ,0      ,'8'      ,0x2019   },
  {'9'          ,SGCAPS ,0x00ab   ,'9'      ,WCH_NONE ,WCH_NONE ,0x201c   ,0x2039   },
  {'9'          ,0      ,'9'      ,0x00ab   },
  {'0'          ,SGCAPS ,0x00bb   ,'0'      ,WCH_NONE ,0x0000   ,0x201d   ,0x203a   },
  {'0'          ,0      ,'0'      ,0x00bb   },
  {VK_OEM_4     ,0      ,'\''     ,'\"'     ,WCH_NONE ,WCH_NONE ,0x00b0   ,WCH_DEAD },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x02da   },
  {VK_OEM_6     ,0      ,WCH_DEAD ,WCH_DEAD ,WCH_NONE ,0x001e   ,WCH_DEAD ,WCH_NONE },
  {0xff         ,0      ,'^'      ,0x00a8   ,WCH_NONE ,WCH_NONE ,0x02c7   ,WCH_NONE },
  {'A'          ,CAPLOK | CAPLOKALTGR,'a'      ,'A'      ,WCH_NONE ,WCH_NONE ,0x00e6   ,0x00c6   },
  {'Z'          ,CAPLOK ,'z'      ,'Z'      ,WCH_NONE ,WCH_NONE ,0x00a3   ,WCH_NONE },
  {'E'          ,CAPLOK ,'e'      ,'E'      ,WCH_NONE ,WCH_NONE ,0x20ac   ,WCH_NONE },
  {'R'          ,CAPLOK ,'r'      ,'R'      ,WCH_NONE ,WCH_NONE ,0x00ae   ,WCH_NONE },
  {'T'          ,CAPLOK ,'t'      ,'T'      ,WCH_NONE ,WCH_NONE ,'{'      ,0x2122   },
  {'Y'          ,CAPLOK ,'y'      ,'Y'      ,WCH_NONE ,WCH_NONE ,'}'      ,WCH_NONE },
  {'U'          ,CAPLOK | CAPLOKALTGR,'u'      ,'U'      ,WCH_NONE ,WCH_NONE ,0x00f9   ,0x00d9   },
  {'O'          ,CAPLOK | CAPLOKALTGR,'o'      ,'O'      ,WCH_NONE ,WCH_NONE ,0x0153   ,0x0152   },
  {'P'          ,CAPLOK ,'p'      ,'P'      ,WCH_NONE ,WCH_NONE ,'%'      ,0x2030   },
  {VK_OEM_MINUS ,0      ,'-'      ,0x2013   ,0x001b   ,0x001f   ,0x2212   ,0x2011   },
  {VK_OEM_PLUS  ,0      ,'+'      ,0x00b1   ,0x001d   ,WCH_NONE ,0x2020   ,0x2021   },
  {'Q'          ,CAPLOK | CAPLOKALTGR,'q'      ,'Q'      ,WCH_NONE ,WCH_NONE ,0x03b8   ,0x03f4   },
  {'S'          ,CAPLOK | CAPLOKALTGR,'s'      ,'S'      ,WCH_NONE ,WCH_NONE ,0x00df   ,0x1e9e   },
  {'D'          ,CAPLOK ,'d'      ,'D'      ,WCH_NONE ,WCH_NONE ,'$'      ,WCH_NONE },
  {'F'          ,CAPLOK ,'f'      ,'F'      ,WCH_NONE ,WCH_NONE ,WCH_DEAD ,WCH_NONE },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00a4   ,WCH_NONE },
  {'G'          ,CAPLOK ,'g'      ,'G'      ,WCH_NONE ,WCH_NONE ,WCH_DEAD ,WCH_NONE },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00b5   ,WCH_NONE },
  {'H'          ,CAPLOK ,'h'      ,'H'      ,WCH_NONE ,WCH_NONE ,WCH_DEAD ,WCH_DEAD },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x017f   ,0x02cd   },
  {'J'          ,CAPLOK ,'j'      ,'J'      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,CAPLOK ,'l'      ,'L'      ,WCH_NONE ,WCH_NONE ,'|'      ,WCH_NONE },
  {'M'          ,CAPLOK ,'m'      ,'M'      ,WCH_NONE ,WCH_NONE ,0x221e   ,WCH_NONE },
  {VK_OEM_3     ,0      ,'/'      ,'\\'     ,WCH_NONE ,WCH_NONE ,0x00f7   ,0x221a   },
  {VK_OEM_5     ,0      ,'*'      ,0x00bd   ,0x001c   ,WCH_NONE ,0x00d7   ,0x00bc   },
  {VK_OEM_102   ,0      ,'<'      ,'>'      ,0x001c   ,WCH_NONE ,0x2a7d   ,0x2a7e   },
  {'W'          ,CAPLOK | CAPLOKALTGR,'w'      ,'W'      ,WCH_NONE ,WCH_NONE ,0x0292   ,0x01b7   },
  {'X'          ,CAPLOK ,'x'      ,'X'      ,WCH_NONE ,WCH_NONE ,0x00a9   ,WCH_NONE },
  {'C'          ,CAPLOK | CAPLOKALTGR,'c'      ,'C'      ,WCH_NONE ,WCH_NONE ,0x00e7   ,0x00c7   },
  {'V'          ,CAPLOK ,'v'      ,'V'      ,WCH_NONE ,WCH_NONE ,WCH_DEAD ,WCH_DEAD },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x00b8   ,0x02db   },
  {'B'          ,CAPLOK ,'b'      ,'B'      ,WCH_NONE ,WCH_NONE ,WCH_DEAD ,WCH_NONE },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,'-'      ,WCH_NONE },
  {'N'          ,CAPLOK ,'n'      ,'N'      ,WCH_NONE ,WCH_NONE ,WCH_DEAD ,WCH_NONE },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,'~'      ,WCH_NONE },
  {VK_OEM_PERIOD,0      ,'.'      ,'?'      ,WCH_NONE ,WCH_NONE ,0x00bf   ,WCH_NONE },
  {VK_OEM_COMMA ,0      ,','      ,'!'      ,WCH_NONE ,WCH_NONE ,0x00a1   ,WCH_DEAD },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,','      },
  {VK_OEM_2     ,0      ,':'      ,0x2026   ,WCH_NONE ,WCH_NONE ,0x00b7   ,WCH_NONE },
  {VK_OEM_8     ,0      ,';'      ,'='      ,WCH_NONE ,WCH_NONE ,0x2243   ,0x2260   },
  {VK_SPACE     ,0      ,' '      ,' '      ,0x2003   ,WCH_NONE ,0x00a0   ,0x202f   },
  {VK_DECIMAL   ,0      ,','      ,','      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_7     ,0      ,'@'      ,'#'      ,WCH_NONE ,WCH_NONE ,WCH_DEAD ,WCH_DEAD },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x02d8   ,0x00b0   },
  {'I'          ,CAPLOK ,'i'      ,'I'      ,WCH_NONE ,WCH_NONE ,WCH_DEAD ,WCH_DEAD },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x02d9   ,'.'      },
  {'K'          ,CAPLOK ,'k'      ,'K'      ,WCH_NONE ,WCH_NONE ,WCH_DEAD ,WCH_NONE },
  {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,WCH_NONE ,'/'      ,WCH_NONE },
  {0            ,0      ,0        ,0        ,0        ,0        ,0        ,0        }
};

// Put this last so that VkKeyScan interprets number characters
// as coming from the main section of the kbd (aVkToWch2 and
// aVkToWch5) before considering the numpad (aVkToWch1).

static ALLOC_SECTION_LDATA VK_TO_WCHARS1 aVkToWch1[] = {
    { VK_NUMPAD0   , 0      ,  '0'   },
    { VK_NUMPAD1   , 0      ,  '1'   },
    { VK_NUMPAD2   , 0      ,  '2'   },
    { VK_NUMPAD3   , 0      ,  '3'   },
    { VK_NUMPAD4   , 0      ,  '4'   },
    { VK_NUMPAD5   , 0      ,  '5'   },
    { VK_NUMPAD6   , 0      ,  '6'   },
    { VK_NUMPAD7   , 0      ,  '7'   },
    { VK_NUMPAD8   , 0      ,  '8'   },
    { VK_NUMPAD9   , 0      ,  '9'   },
    { 0            , 0      ,  '\0'  }
};

static ALLOC_SECTION_LDATA VK_TO_WCHAR_TABLE aVkToWcharTable[] = {
    {  (PVK_TO_WCHARS1)aVkToWch3, 3, sizeof(aVkToWch3[0]) },
    {  (PVK_TO_WCHARS1)aVkToWch6, 6, sizeof(aVkToWch6[0]) },
    {  (PVK_TO_WCHARS1)aVkToWch2, 2, sizeof(aVkToWch2[0]) },
    {  (PVK_TO_WCHARS1)aVkToWch1, 1, sizeof(aVkToWch1[0]) },
    {                       NULL, 0, 0                    },
};

/***************************************************************************\
* aKeyNames[], aKeyNamesExt[]  - Virtual Scancode to Key Name tables
*
* Table attributes: Ordered Scan (by scancode), null-terminated
*
* Only the names of Extended, NumPad, Dead and Non-Printable keys are here.
* (Keys producing printable characters are named by that character)
\***************************************************************************/

static ALLOC_SECTION_LDATA VSC_LPWSTR aKeyNames[] = {
    0x01,    L"Échap.",
    0x0e,    L"Ret.Arr.",
    0x0f,    L"Tab",
    0x1c,    L"Entrée",
    0x1d,    L"Ctrl",
    0x2a,    L"Maj",
    0x36,    L"Maj Droite",
    0x37,    L"* (Pavé Num.)",
    0x38,    L"Alt",
    0x39,    L"Espace",
    0x3a,    L"Verr. Maj",
    0x3b,    L"F1",
    0x3c,    L"F2",
    0x3d,    L"F3",
    0x3e,    L"F4",
    0x3f,    L"F5",
    0x40,    L"F6",
    0x41,    L"F7",
    0x42,    L"F8",
    0x43,    L"F9",
    0x44,    L"F10",
    0x45,    L"Pause",
    0x46,    L"Défil.",
    0x47,    L"7 (Pavé Num.)",
    0x48,    L"8 (Pavé Num.)",
    0x49,    L"9 (Pavé Num.)",
    0x4a,    L"- (Pavé Num.)",
    0x4b,    L"4 (Pavé Num.)",
    0x4c,    L"5 (Pavé Num.)",
    0x4d,    L"6 (Pavé Num.)",
    0x4e,    L"+ (Pavé Num.)",
    0x4f,    L"1 (Pavé Num.)",
    0x50,    L"2 (Pavé Num.)",
    0x51,    L"3 (Pavé Num.)",
    0x52,    L"0 (Pavé Num.)",
    0x53,    L". (Pavé Num.)",
    0x57,    L"F11",
    0x58,    L"F12",
    0x7c,    L"F13",
    0x7d,    L"F14",
    0x7e,    L"F15",
    0x7f,    L"F16",
    0x80,    L"F17",
    0x81,    L"F18",
    0x82,    L"F19",
    0x83,    L"F20",
    0x84,    L"F21",
    0x85,    L"F22",
    0x86,    L"F23",
    0x87,    L"F24",
    0   ,    NULL
};

static ALLOC_SECTION_LDATA VSC_LPWSTR aKeyNamesExt[] = {
    0x1c,    L"Entrée (Pavé Num.)",
    0x1d,    L"Ctrl Droite",
    0x35,    L"/ (Pavé Num.)",
    0x37,    L"Impr. écran",
    0x38,    L"AltGr",
    0x45,    L"Verr. Num.",
    0x46,    L"Attn.",
    0x47,    L"Origine",
    0x48,    L"Haut",
    0x49,    L"Page Préc.",
    0x4b,    L"Gauche",
    0x4d,    L"Droite",
    0x4f,    L"Fin",
    0x50,    L"Bas",
    0x51,    L"Page Suiv.",
    0x52,    L"Insér.",
    0x53,    L"Suppr.",
    0x54,    L"<00>",
    0x56,    L"Aide",
    0x5b,    L"Windows Gauche",
    0x5c,    L"Windows Droite",
    0x5d,    L"Application",
    0   ,    NULL
};

static ALLOC_SECTION_LDATA DEADKEY_LPWSTR aKeyNamesDead[] = {
    L","	L"COMMA BELOW",
    L"-"	L"SHORT STROKE OVERLAY",
    L"."	L"DOT BELOW",
    L"/"	L"SHORT SOLIDUS OVERLAY",
    L"^"	L"CIRCUMFLEX ACCENT",
    L"`"	L"GRAVE ACCENT",
    L"~"	L"TILDE",
    L"\x00a4"	L"CURRENCY SIGN",
    L"\x00a8"	L"DIAERESIS",
    L"\x00af"	L"MACRON",
    L"\x00b0"	L"INVERTED BREVE",
    L"\x00b4"	L"ACUTE ACCENT",
    L"\x00b5"	L"MICRO SIGN",
    L"\x00b8"	L"CEDILLA",
    L"\x017f"	L"LATIN SMALL LETTER LONG S",
    L"\x02c7"	L"CARON",
    L"\x02cd"	L"MACRON BELOW",
    L"\x02d8"	L"BREVE",
    L"\x02d9"	L"DOT ABOVE",
    L"\x02da"	L"RING ABOVE",
    L"\x02db"	L"OGONEK",
    L"\x02dd"	L"DOUBLE ACUTE ACCENT",
    L"\x02f5"	L"DOUBLE GRAVE ACCENT",
    NULL
};

static ALLOC_SECTION_LDATA DEADKEY aDeadKey[] = {
    DEADTRANS( L'S'   , L','   , 0x0218 , 0x0000),
    DEADTRANS( L'T'   , L','   , 0x021a , 0x0000),
    DEADTRANS( L's'   , L','   , 0x0219 , 0x0000),
    DEADTRANS( L't'   , L','   , 0x021b , 0x0000),
    DEADTRANS( L','   , L','   , 0x0326 , 0x0000),
    DEADTRANS( 0x00a4 , L','   , L','   , 0x0000),
    DEADTRANS( 0x00b5 , L','   , L','   , 0x0000),
    DEADTRANS( 0x017f , L','   , L','   , 0x0000),
    DEADTRANS( 0x00a0 , L','   , L','   , 0x0000),
    DEADTRANS( 0x2003 , L','   , L','   , 0x0000),
    DEADTRANS( 0x202f , L','   , L','   , 0x0000),
    DEADTRANS( L' '   , L','   , L','   , 0x0000),

    DEADTRANS( L'B'   , L'-'   , 0x0243 , 0x0000),
    DEADTRANS( L'D'   , L'-'   , 0x0110 , 0x0000),
    DEADTRANS( L'G'   , L'-'   , 0x01e4 , 0x0000),
    DEADTRANS( L'H'   , L'-'   , 0x0126 , 0x0000),
    DEADTRANS( L'I'   , L'-'   , 0x0197 , 0x0000),
    DEADTRANS( L'J'   , L'-'   , 0x0248 , 0x0000),
    DEADTRANS( L'L'   , L'-'   , 0x023d , 0x0000),
    DEADTRANS( L'R'   , L'-'   , 0x024c , 0x0000),
    DEADTRANS( L'T'   , L'-'   , 0x0166 , 0x0000),
    DEADTRANS( L'U'   , L'-'   , 0x0244 , 0x0000),
    DEADTRANS( L'Y'   , L'-'   , 0x024e , 0x0000),
    DEADTRANS( L'Z'   , L'-'   , 0x01b5 , 0x0000),
    DEADTRANS( L'b'   , L'-'   , 0x0180 , 0x0000),
    DEADTRANS( L'd'   , L'-'   , 0x0111 , 0x0000),
    DEADTRANS( L'g'   , L'-'   , 0x01e5 , 0x0000),
    DEADTRANS( L'h'   , L'-'   , 0x0127 , 0x0000),
    DEADTRANS( L'j'   , L'-'   , 0x0249 , 0x0000),
    DEADTRANS( L'l'   , L'-'   , 0x019a , 0x0000),
    DEADTRANS( L'r'   , L'-'   , 0x024d , 0x0000),
    DEADTRANS( L't'   , L'-'   , 0x0167 , 0x0000),
    DEADTRANS( L'y'   , L'-'   , 0x024f , 0x0000),
    DEADTRANS( L'z'   , L'-'   , 0x01b6 , 0x0000),
    DEADTRANS( L'-'   , L'-'   , 0x0335 , 0x0000),
    DEADTRANS( 0x00a4 , L'-'   , L'-'   , 0x0000),
    DEADTRANS( 0x00b5 , L'-'   , L'-'   , 0x0000),
    DEADTRANS( 0x017f , L'-'   , L'-'   , 0x0000),
    DEADTRANS( 0x00a0 , L'-'   , L'-'   , 0x0000),
    DEADTRANS( 0x2003 , L'-'   , L'-'   , 0x0000),
    DEADTRANS( 0x202f , L'-'   , L'-'   , 0x0000),
    DEADTRANS( L' '   , L'-'   , L'-'   , 0x0000),

    DEADTRANS( L'A'   , L'.'   , 0x1ea0 , 0x0000),
    DEADTRANS( L'B'   , L'.'   , 0x1e04 , 0x0000),
    DEADTRANS( L'D'   , L'.'   , 0x1e0c , 0x0000),
    DEADTRANS( L'E'   , L'.'   , 0x1eb8 , 0x0000),
    DEADTRANS( L'H'   , L'.'   , 0x1e24 , 0x0000),
    DEADTRANS( L'I'   , L'.'   , 0x1eca , 0x0000),
    DEADTRANS( L'K'   , L'.'   , 0x1e32 , 0x0000),
    DEADTRANS( L'L'   , L'.'   , 0x1e36 , 0x0000),
    DEADTRANS( L'M'   , L'.'   , 0x1e42 , 0x0000),
    DEADTRANS( L'N'   , L'.'   , 0x1e46 , 0x0000),
    DEADTRANS( L'O'   , L'.'   , 0x1ecc , 0x0000),
    DEADTRANS( L'R'   , L'.'   , 0x1e5a , 0x0000),
    DEADTRANS( L'S'   , L'.'   , 0x1e62 , 0x0000),
    DEADTRANS( L'T'   , L'.'   , 0x1e6c , 0x0000),
    DEADTRANS( L'U'   , L'.'   , 0x1ee4 , 0x0000),
    DEADTRANS( L'V'   , L'.'   , 0x1e7e , 0x0000),
    DEADTRANS( L'W'   , L'.'   , 0x1e88 , 0x0000),
    DEADTRANS( L'Y'   , L'.'   , 0x1ef4 , 0x0000),
    DEADTRANS( L'Z'   , L'.'   , 0x1e92 , 0x0000),
    DEADTRANS( L'a'   , L'.'   , 0x1ea1 , 0x0000),
    DEADTRANS( L'b'   , L'.'   , 0x1e05 , 0x0000),
    DEADTRANS( L'd'   , L'.'   , 0x1e0d , 0x0000),
    DEADTRANS( L'e'   , L'.'   , 0x1eb9 , 0x0000),
    DEADTRANS( L'h'   , L'.'   , 0x1e25 , 0x0000),
    DEADTRANS( L'i'   , L'.'   , 0x1ecb , 0x0000),
    DEADTRANS( L'k'   , L'.'   , 0x1e33 , 0x0000),
    DEADTRANS( L'l'   , L'.'   , 0x1e37 , 0x0000),
    DEADTRANS( L'm'   , L'.'   , 0x1e43 , 0x0000),
    DEADTRANS( L'n'   , L'.'   , 0x1e47 , 0x0000),
    DEADTRANS( L'o'   , L'.'   , 0x1ecd , 0x0000),
    DEADTRANS( L'r'   , L'.'   , 0x1e5b , 0x0000),
    DEADTRANS( L's'   , L'.'   , 0x1e63 , 0x0000),
    DEADTRANS( L't'   , L'.'   , 0x1e6d , 0x0000),
    DEADTRANS( L'u'   , L'.'   , 0x1ee5 , 0x0000),
    DEADTRANS( L'v'   , L'.'   , 0x1e7f , 0x0000),
    DEADTRANS( L'w'   , L'.'   , 0x1e89 , 0x0000),
    DEADTRANS( L'y'   , L'.'   , 0x1ef5 , 0x0000),
    DEADTRANS( L'z'   , L'.'   , 0x1e93 , 0x0000),
    DEADTRANS( 0x00ca , L'.'   , 0x1ec6 , 0x0000),
    DEADTRANS( 0x00ea , L'.'   , 0x1ec7 , 0x0000),
    DEADTRANS( L'.'   , L'.'   , 0x0323 , 0x0000),
    DEADTRANS( 0x00a4 , L'.'   , L'.'   , 0x0000),
    DEADTRANS( 0x00b5 , L'.'   , L'.'   , 0x0000),
    DEADTRANS( 0x017f , L'.'   , L'.'   , 0x0000),
    DEADTRANS( 0x00a0 , L'.'   , L'.'   , 0x0000),
    DEADTRANS( 0x2003 , L'.'   , L'.'   , 0x0000),
    DEADTRANS( 0x202f , L'.'   , L'.'   , 0x0000),
    DEADTRANS( L' '   , L'.'   , L'.'   , 0x0000),

    DEADTRANS( L'<'   , L'/'   , 0x226e , 0x0000),
    DEADTRANS( L'='   , L'/'   , 0x2260 , 0x0000),
    DEADTRANS( L'>'   , L'/'   , 0x226f , 0x0000),
    DEADTRANS( L'A'   , L'/'   , 0x023a , 0x0000),
    DEADTRANS( L'C'   , L'/'   , 0x023b , 0x0000),
    DEADTRANS( L'E'   , L'/'   , 0x0246 , 0x0000),
    DEADTRANS( L'L'   , L'/'   , 0x0141 , 0x0000),
    DEADTRANS( L'O'   , L'/'   , 0x00d8 , 0x0000),
    DEADTRANS( L'T'   , L'/'   , 0x023e , 0x0000),
    DEADTRANS( L'c'   , L'/'   , 0x023c , 0x0000),
    DEADTRANS( L'e'   , L'/'   , 0x0247 , 0x0000),
    DEADTRANS( L'l'   , L'/'   , 0x0142 , 0x0000),
    DEADTRANS( L'o'   , L'/'   , 0x00f8 , 0x0000),
    DEADTRANS( 0x017f , L'/'   , 0x1e9c , 0x0000),
    DEADTRANS( 0x2243 , L'/'   , 0x2244 , 0x0000),
    DEADTRANS( 0x2a7d , L'/'   , 0x2270 , 0x0000),
    DEADTRANS( 0x2a7e , L'/'   , 0x2271 , 0x0000),
    DEADTRANS( L'/'   , L'/'   , 0x0337 , 0x0000),
    DEADTRANS( 0x00a4 , L'/'   , L'/'   , 0x0000),
    DEADTRANS( 0x00b5 , L'/'   , L'/'   , 0x0000),
    DEADTRANS( 0x00a0 , L'/'   , L'/'   , 0x0000),
    DEADTRANS( 0x2003 , L'/'   , L'/'   , 0x0000),
    DEADTRANS( 0x202f , L'/'   , L'/'   , 0x0000),
    DEADTRANS( L' '   , L'/'   , L'/'   , 0x0000),

    DEADTRANS( L'('   , L'^'   , 0x207d , 0x0000),
    DEADTRANS( L')'   , L'^'   , 0x207e , 0x0000),
    DEADTRANS( L'+'   , L'^'   , 0x207a , 0x0000),
    DEADTRANS( L'-'   , L'^'   , 0x207b , 0x0000),
    DEADTRANS( L'0'   , L'^'   , 0x2070 , 0x0000),
    DEADTRANS( L'1'   , L'^'   , 0x00b9 , 0x0000),
    DEADTRANS( L'2'   , L'^'   , 0x00b2 , 0x0000),
    DEADTRANS( L'3'   , L'^'   , 0x00b3 , 0x0000),
    DEADTRANS( L'4'   , L'^'   , 0x2074 , 0x0000),
    DEADTRANS( L'5'   , L'^'   , 0x2075 , 0x0000),
    DEADTRANS( L'6'   , L'^'   , 0x2076 , 0x0000),
    DEADTRANS( L'7'   , L'^'   , 0x2077 , 0x0000),
    DEADTRANS( L'8'   , L'^'   , 0x2078 , 0x0000),
    DEADTRANS( L'9'   , L'^'   , 0x2079 , 0x0000),
    DEADTRANS( L'='   , L'^'   , 0x207c , 0x0000),
    DEADTRANS( L'A'   , L'^'   , 0x00c2 , 0x0000),
    DEADTRANS( L'C'   , L'^'   , 0x0108 , 0x0000),
    DEADTRANS( L'E'   , L'^'   , 0x00ca , 0x0000),
    DEADTRANS( L'G'   , L'^'   , 0x011c , 0x0000),
    DEADTRANS( L'H'   , L'^'   , 0x0124 , 0x0000),
    DEADTRANS( L'I'   , L'^'   , 0x00ce , 0x0000),
    DEADTRANS( L'J'   , L'^'   , 0x0134 , 0x0000),
    DEADTRANS( L'O'   , L'^'   , 0x00d4 , 0x0000),
    DEADTRANS( L'S'   , L'^'   , 0x015c , 0x0000),
    DEADTRANS( L'U'   , L'^'   , 0x00db , 0x0000),
    DEADTRANS( L'W'   , L'^'   , 0x0174 , 0x0000),
    DEADTRANS( L'Y'   , L'^'   , 0x0176 , 0x0000),
    DEADTRANS( L'Z'   , L'^'   , 0x1e90 , 0x0000),
    DEADTRANS( L'a'   , L'^'   , 0x00e2 , 0x0000),
    DEADTRANS( L'c'   , L'^'   , 0x0109 , 0x0000),
    DEADTRANS( L'e'   , L'^'   , 0x00ea , 0x0000),
    DEADTRANS( L'g'   , L'^'   , 0x011d , 0x0000),
    DEADTRANS( L'h'   , L'^'   , 0x0125 , 0x0000),
    DEADTRANS( L'i'   , L'^'   , 0x00ee , 0x0000),
    DEADTRANS( L'j'   , L'^'   , 0x0135 , 0x0000),
    DEADTRANS( L'o'   , L'^'   , 0x00f4 , 0x0000),
    DEADTRANS( L's'   , L'^'   , 0x015d , 0x0000),
    DEADTRANS( L'u'   , L'^'   , 0x00fb , 0x0000),
    DEADTRANS( L'w'   , L'^'   , 0x0175 , 0x0000),
    DEADTRANS( L'x'   , L'^'   , 0x02e3 , 0x0000),
    DEADTRANS( L'y'   , L'^'   , 0x0177 , 0x0000),
    DEADTRANS( L'z'   , L'^'   , 0x1e91 , 0x0000),
    DEADTRANS( 0x00c0 , L'^'   , 0x1ea6 , 0x0000),
    DEADTRANS( 0x00c8 , L'^'   , 0x1ec0 , 0x0000),
    DEADTRANS( 0x00c9 , L'^'   , 0x1ebe , 0x0000),
    DEADTRANS( 0x00e0 , L'^'   , 0x1ea7 , 0x0000),
    DEADTRANS( 0x00e8 , L'^'   , 0x1ec1 , 0x0000),
    DEADTRANS( 0x00e9 , L'^'   , 0x1ebf , 0x0000),
    DEADTRANS( 0x2212 , L'^'   , 0x207b , 0x0000),
    DEADTRANS( L'^'   , L'^'   , 0x0302 , 0x0000),
    DEADTRANS( 0x00a4 , L'^'   , L'^'   , 0x0000),
    DEADTRANS( 0x00b5 , L'^'   , L'^'   , 0x0000),
    DEADTRANS( 0x017f , L'^'   , L'^'   , 0x0000),
    DEADTRANS( 0x00a0 , L'^'   , L'^'   , 0x0000),
    DEADTRANS( 0x2003 , L'^'   , L'^'   , 0x0000),
    DEADTRANS( 0x202f , L'^'   , L'^'   , 0x0000),
    DEADTRANS( L' '   , L'^'   , L'^'   , 0x0000),

    DEADTRANS( L'A'   , L'`'   , 0x00c0 , 0x0000),
    DEADTRANS( L'E'   , L'`'   , 0x00c8 , 0x0000),
    DEADTRANS( L'I'   , L'`'   , 0x00cc , 0x0000),
    DEADTRANS( L'N'   , L'`'   , 0x01f8 , 0x0000),
    DEADTRANS( L'O'   , L'`'   , 0x00d2 , 0x0000),
    DEADTRANS( L'U'   , L'`'   , 0x00d9 , 0x0000),
    DEADTRANS( L'W'   , L'`'   , 0x1e80 , 0x0000),
    DEADTRANS( L'Y'   , L'`'   , 0x1ef2 , 0x0000),
    DEADTRANS( L'a'   , L'`'   , 0x00e0 , 0x0000),
    DEADTRANS( L'e'   , L'`'   , 0x00e8 , 0x0000),
    DEADTRANS( L'i'   , L'`'   , 0x00ec , 0x0000),
    DEADTRANS( L'n'   , L'`'   , 0x01f9 , 0x0000),
    DEADTRANS( L'o'   , L'`'   , 0x00f2 , 0x0000),
    DEADTRANS( L'u'   , L'`'   , 0x00f9 , 0x0000),
    DEADTRANS( L'w'   , L'`'   , 0x1e81 , 0x0000),
    DEADTRANS( L'y'   , L'`'   , 0x1ef3 , 0x0000),
    DEADTRANS( 0x00ca , L'`'   , 0x1ec0 , 0x0000),
    DEADTRANS( 0x00ea , L'`'   , 0x1ec1 , 0x0000),
    DEADTRANS( L'`'   , L'`'   , 0x0300 , 0x0000),
    DEADTRANS( 0x00a4 , L'`'   , L'`'   , 0x0000),
    DEADTRANS( 0x00b5 , L'`'   , L'`'   , 0x0000),
    DEADTRANS( 0x017f , L'`'   , L'`'   , 0x0000),
    DEADTRANS( 0x00a0 , L'`'   , L'`'   , 0x0000),
    DEADTRANS( 0x2003 , L'`'   , L'`'   , 0x0000),
    DEADTRANS( 0x202f , L'`'   , L'`'   , 0x0000),
    DEADTRANS( L' '   , L'`'   , L'`'   , 0x0000),

    DEADTRANS( L'-'   , L'~'   , 0x2243 , 0x0000),
    DEADTRANS( L'<'   , L'~'   , 0x2272 , 0x0000),
    DEADTRANS( L'='   , L'~'   , 0x2248 , 0x0000),
    DEADTRANS( L'>'   , L'~'   , 0x2273 , 0x0000),
    DEADTRANS( L'A'   , L'~'   , 0x00c3 , 0x0000),
    DEADTRANS( L'E'   , L'~'   , 0x1ebc , 0x0000),
    DEADTRANS( L'I'   , L'~'   , 0x0128 , 0x0000),
    DEADTRANS( L'N'   , L'~'   , 0x00d1 , 0x0000),
    DEADTRANS( L'O'   , L'~'   , 0x00d5 , 0x0000),
    DEADTRANS( L'U'   , L'~'   , 0x0168 , 0x0000),
    DEADTRANS( L'V'   , L'~'   , 0x1e7c , 0x0000),
    DEADTRANS( L'Y'   , L'~'   , 0x1ef8 , 0x0000),
    DEADTRANS( L'a'   , L'~'   , 0x00e3 , 0x0000),
    DEADTRANS( L'e'   , L'~'   , 0x1ebd , 0x0000),
    DEADTRANS( L'i'   , L'~'   , 0x0129 , 0x0000),
    DEADTRANS( L'n'   , L'~'   , 0x00f1 , 0x0000),
    DEADTRANS( L'o'   , L'~'   , 0x00f5 , 0x0000),
    DEADTRANS( L'u'   , L'~'   , 0x0169 , 0x0000),
    DEADTRANS( L'v'   , L'~'   , 0x1e7d , 0x0000),
    DEADTRANS( L'y'   , L'~'   , 0x1ef9 , 0x0000),
    DEADTRANS( 0x00ca , L'~'   , 0x1ec4 , 0x0000),
    DEADTRANS( 0x00ea , L'~'   , 0x1ec5 , 0x0000),
    DEADTRANS( L'~'   , L'~'   , 0x0303 , 0x0000),
    DEADTRANS( 0x00a4 , L'~'   , L'~'   , 0x0000),
    DEADTRANS( 0x00b5 , L'~'   , L'~'   , 0x0000),
    DEADTRANS( 0x017f , L'~'   , L'~'   , 0x0000),
    DEADTRANS( 0x00a0 , L'~'   , L'~'   , 0x0000),
    DEADTRANS( 0x2003 , L'~'   , L'~'   , 0x0000),
    DEADTRANS( 0x202f , L'~'   , L'~'   , 0x0000),
    DEADTRANS( L' '   , L'~'   , L'~'   , 0x0000),

    DEADTRANS( L'%'   , 0x00a4 , 0x20b0 , 0x0000),
    DEADTRANS( L'A'   , 0x00a4 , 0x20b3 , 0x0000),
    DEADTRANS( L'B'   , 0x00a4 , 0x0e3f , 0x0000),
    DEADTRANS( L'C'   , 0x00a4 , 0x20b5 , 0x0000),
    DEADTRANS( L'D'   , 0x00a4 , 0x20af , 0x0000),
    DEADTRANS( L'F'   , 0x00a4 , 0x20a3 , 0x0000),
    DEADTRANS( L'L'   , 0x00a4 , 0x20a4 , 0x0000),
    DEADTRANS( L'M'   , 0x00a4 , 0x2133 , 0x0000),
    DEADTRANS( L'P'   , 0x00a4 , 0x20a7 , 0x0000),
    DEADTRANS( L'R'   , 0x00a4 , 0x20b9 , 0x0000),
    DEADTRANS( L'S'   , 0x00a4 , 0x20b7 , 0x0000),
    DEADTRANS( L'T'   , 0x00a4 , 0x20ae , 0x0000),
    DEADTRANS( L'b'   , 0x00a4 , 0x20bf , 0x0000),
    DEADTRANS( L'c'   , 0x00a4 , 0x00a2 , 0x0000),
    DEADTRANS( L'd'   , 0x00a4 , 0x20ab , 0x0000),
    DEADTRANS( L'e'   , 0x00a4 , 0x20a0 , 0x0000),
    DEADTRANS( L'f'   , 0x00a4 , 0x0192 , 0x0000),
    DEADTRANS( L'g'   , 0x00a4 , 0x20b2 , 0x0000),
    DEADTRANS( L'h'   , 0x00a4 , 0x20b4 , 0x0000),
    DEADTRANS( L'k'   , 0x00a4 , 0x20ad , 0x0000),
    DEADTRANS( L'l'   , 0x00a4 , 0x20ba , 0x0000),
    DEADTRANS( L'm'   , 0x00a4 , 0x20a5 , 0x0000),
    DEADTRANS( L'n'   , 0x00a4 , 0x20a6 , 0x0000),
    DEADTRANS( L'p'   , 0x00a4 , 0x20b1 , 0x0000),
    DEADTRANS( L'r'   , 0x00a4 , 0x20bd , 0x0000),
    DEADTRANS( L's'   , 0x00a4 , 0x20aa , 0x0000),
    DEADTRANS( L't'   , 0x00a4 , 0x20b8 , 0x0000),
    DEADTRANS( L'w'   , 0x00a4 , 0x20a9 , 0x0000),
    DEADTRANS( L'y'   , 0x00a4 , 0x00a5 , 0x0000),
    DEADTRANS( L'|'   , 0x00a4 , 0x20be , 0x0000),
    DEADTRANS( 0x00a4 , 0x00a4 , 0x00a4 , 0x0000),
    DEADTRANS( 0x00ae , 0x00a4 , 0x20a8 , 0x0000),
    DEADTRANS( 0x00c7 , 0x00a4 , 0x20a1 , 0x0000),
    DEADTRANS( 0x00e7 , 0x00a4 , 0x20a2 , 0x0000),
    DEADTRANS( 0x221e , 0x00a4 , 0x20bc , 0x0000),
    DEADTRANS( 0x00b5 , 0x00a4 , 0x00a4 , 0x0000),
    DEADTRANS( 0x017f , 0x00a4 , 0x00a4 , 0x0000),
    DEADTRANS( 0x00a0 , 0x00a4 , 0x00a4 , 0x0000),
    DEADTRANS( 0x2003 , 0x00a4 , 0x00a4 , 0x0000),
    DEADTRANS( 0x202f , 0x00a4 , 0x00a4 , 0x0000),
    DEADTRANS( L' '   , 0x00a4 , 0x00a4 , 0x0000),

    DEADTRANS( L'A'   , 0x00a8 , 0x00c4 , 0x0000),
    DEADTRANS( L'E'   , 0x00a8 , 0x00cb , 0x0000),
    DEADTRANS( L'H'   , 0x00a8 , 0x1e26 , 0x0000),
    DEADTRANS( L'I'   , 0x00a8 , 0x00cf , 0x0000),
    DEADTRANS( L'O'   , 0x00a8 , 0x00d6 , 0x0000),
    DEADTRANS( L'U'   , 0x00a8 , 0x00dc , 0x0000),
    DEADTRANS( L'W'   , 0x00a8 , 0x1e84 , 0x0000),
    DEADTRANS( L'X'   , 0x00a8 , 0x1e8c , 0x0000),
    DEADTRANS( L'Y'   , 0x00a8 , 0x0178 , 0x0000),
    DEADTRANS( L'a'   , 0x00a8 , 0x00e4 , 0x0000),
    DEADTRANS( L'e'   , 0x00a8 , 0x00eb , 0x0000),
    DEADTRANS( L'h'   , 0x00a8 , 0x1e27 , 0x0000),
    DEADTRANS( L'i'   , 0x00a8 , 0x00ef , 0x0000),
    DEADTRANS( L'o'   , 0x00a8 , 0x00f6 , 0x0000),
    DEADTRANS( L't'   , 0x00a8 , 0x1e97 , 0x0000),
    DEADTRANS( L'u'   , 0x00a8 , 0x00fc , 0x0000),
    DEADTRANS( L'w'   , 0x00a8 , 0x1e85 , 0x0000),
    DEADTRANS( L'x'   , 0x00a8 , 0x1e8d , 0x0000),
    DEADTRANS( L'y'   , 0x00a8 , 0x00ff , 0x0000),
    DEADTRANS( 0x00d9 , 0x00a8 , 0x01db , 0x0000),
    DEADTRANS( 0x00f9 , 0x00a8 , 0x01dc , 0x0000),
    DEADTRANS( 0x00a8 , 0x00a8 , 0x0308 , 0x0000),
    DEADTRANS( 0x00a4 , 0x00a8 , 0x00a8 , 0x0000),
    DEADTRANS( 0x00b5 , 0x00a8 , 0x00a8 , 0x0000),
    DEADTRANS( 0x017f , 0x00a8 , 0x00a8 , 0x0000),
    DEADTRANS( 0x00a0 , 0x00a8 , 0x00a8 , 0x0000),
    DEADTRANS( 0x2003 , 0x00a8 , 0x00a8 , 0x0000),
    DEADTRANS( 0x202f , 0x00a8 , 0x00a8 , 0x0000),
    DEADTRANS( L' '   , 0x00a8 , 0x00a8 , 0x0000),

    DEADTRANS( L'A'   , 0x00af , 0x0100 , 0x0000),
    DEADTRANS( L'E'   , 0x00af , 0x0112 , 0x0000),
    DEADTRANS( L'G'   , 0x00af , 0x1e20 , 0x0000),
    DEADTRANS( L'I'   , 0x00af , 0x012a , 0x0000),
    DEADTRANS( L'O'   , 0x00af , 0x014c , 0x0000),
    DEADTRANS( L'U'   , 0x00af , 0x016a , 0x0000),
    DEADTRANS( L'Y'   , 0x00af , 0x0232 , 0x0000),
    DEADTRANS( L'a'   , 0x00af , 0x0101 , 0x0000),
    DEADTRANS( L'e'   , 0x00af , 0x0113 , 0x0000),
    DEADTRANS( L'g'   , 0x00af , 0x1e21 , 0x0000),
    DEADTRANS( L'i'   , 0x00af , 0x012b , 0x0000),
    DEADTRANS( L'o'   , 0x00af , 0x014d , 0x0000),
    DEADTRANS( L'u'   , 0x00af , 0x016b , 0x0000),
    DEADTRANS( L'y'   , 0x00af , 0x0233 , 0x0000),
    DEADTRANS( 0x00c6 , 0x00af , 0x01e2 , 0x0000),
    DEADTRANS( 0x00c8 , 0x00af , 0x1e14 , 0x0000),
    DEADTRANS( 0x00c9 , 0x00af , 0x1e16 , 0x0000),
    DEADTRANS( 0x00e6 , 0x00af , 0x01e3 , 0x0000),
    DEADTRANS( 0x00e8 , 0x00af , 0x1e15 , 0x0000),
    DEADTRANS( 0x00e9 , 0x00af , 0x1e17 , 0x0000),
    DEADTRANS( 0x00af , 0x00af , 0x0304 , 0x0000),
    DEADTRANS( 0x00a4 , 0x00af , 0x00af , 0x0000),
    DEADTRANS( 0x00b5 , 0x00af , 0x00af , 0x0000),
    DEADTRANS( 0x017f , 0x00af , 0x00af , 0x0000),
    DEADTRANS( 0x00a0 , 0x00af , 0x00af , 0x0000),
    DEADTRANS( 0x2003 , 0x00af , 0x00af , 0x0000),
    DEADTRANS( 0x202f , 0x00af , 0x00af , 0x0000),
    DEADTRANS( L' '   , 0x00af , 0x00af , 0x0000),

    DEADTRANS( L'A'   , 0x00b0 , 0x0202 , 0x0000),
    DEADTRANS( L'E'   , 0x00b0 , 0x0206 , 0x0000),
    DEADTRANS( L'I'   , 0x00b0 , 0x020a , 0x0000),
    DEADTRANS( L'O'   , 0x00b0 , 0x020e , 0x0000),
    DEADTRANS( L'R'   , 0x00b0 , 0x0212 , 0x0000),
    DEADTRANS( L'U'   , 0x00b0 , 0x0216 , 0x0000),
    DEADTRANS( L'a'   , 0x00b0 , 0x0203 , 0x0000),
    DEADTRANS( L'e'   , 0x00b0 , 0x0207 , 0x0000),
    DEADTRANS( L'i'   , 0x00b0 , 0x020b , 0x0000),
    DEADTRANS( L'o'   , 0x00b0 , 0x020f , 0x0000),
    DEADTRANS( L'r'   , 0x00b0 , 0x0213 , 0x0000),
    DEADTRANS( L'u'   , 0x00b0 , 0x0217 , 0x0000),
    DEADTRANS( 0x00c0 , 0x00b0 , 0x1ea6 , 0x0000),
    DEADTRANS( 0x00c8 , 0x00b0 , 0x1ec0 , 0x0000),
    DEADTRANS( 0x00e0 , 0x00b0 , 0x1ea7 , 0x0000),
    DEADTRANS( 0x00e8 , 0x00b0 , 0x1ec1 , 0x0000),
    DEADTRANS( 0x00b0 , 0x00b0 , 0x0311 , 0x0000),
    DEADTRANS( 0x00a4 , 0x00b0 , 0x00b0 , 0x0000),
    DEADTRANS( 0x00b5 , 0x00b0 , 0x00b0 , 0x0000),
    DEADTRANS( 0x017f , 0x00b0 , 0x00b0 , 0x0000),
    DEADTRANS( 0x00a0 , 0x00b0 , 0x00b0 , 0x0000),
    DEADTRANS( 0x2003 , 0x00b0 , 0x00b0 , 0x0000),
    DEADTRANS( 0x202f , 0x00b0 , 0x00b0 , 0x0000),
    DEADTRANS( L' '   , 0x00b0 , 0x00b0 , 0x0000),

    DEADTRANS( L'A'   , 0x00b4 , 0x00c1 , 0x0000),
    DEADTRANS( L'C'   , 0x00b4 , 0x0106 , 0x0000),
    DEADTRANS( L'E'   , 0x00b4 , 0x00c9 , 0x0000),
    DEADTRANS( L'G'   , 0x00b4 , 0x01f4 , 0x0000),
    DEADTRANS( L'I'   , 0x00b4 , 0x00cd , 0x0000),
    DEADTRANS( L'K'   , 0x00b4 , 0x1e30 , 0x0000),
    DEADTRANS( L'L'   , 0x00b4 , 0x0139 , 0x0000),
    DEADTRANS( L'M'   , 0x00b4 , 0x1e3e , 0x0000),
    DEADTRANS( L'N'   , 0x00b4 , 0x0143 , 0x0000),
    DEADTRANS( L'O'   , 0x00b4 , 0x00d3 , 0x0000),
    DEADTRANS( L'P'   , 0x00b4 , 0x1e54 , 0x0000),
    DEADTRANS( L'R'   , 0x00b4 , 0x0154 , 0x0000),
    DEADTRANS( L'S'   , 0x00b4 , 0x015a , 0x0000),
    DEADTRANS( L'U'   , 0x00b4 , 0x00da , 0x0000),
    DEADTRANS( L'W'   , 0x00b4 , 0x1e82 , 0x0000),
    DEADTRANS( L'Y'   , 0x00b4 , 0x00dd , 0x0000),
    DEADTRANS( L'Z'   , 0x00b4 , 0x0179 , 0x0000),
    DEADTRANS( L'a'   , 0x00b4 , 0x00e1 , 0x0000),
    DEADTRANS( L'c'   , 0x00b4 , 0x0107 , 0x0000),
    DEADTRANS( L'e'   , 0x00b4 , 0x00e9 , 0x0000),
    DEADTRANS( L'g'   , 0x00b4 , 0x01f5 , 0x0000),
    DEADTRANS( L'i'   , 0x00b4 , 0x00ed , 0x0000),
    DEADTRANS( L'k'   , 0x00b4 , 0x1e31 , 0x0000),
    DEADTRANS( L'l'   , 0x00b4 , 0x013a , 0x0000),
    DEADTRANS( L'm'   , 0x00b4 , 0x1e3f , 0x0000),
    DEADTRANS( L'n'   , 0x00b4 , 0x0144 , 0x0000),
    DEADTRANS( L'o'   , 0x00b4 , 0x00f3 , 0x0000),
    DEADTRANS( L'p'   , 0x00b4 , 0x1e55 , 0x0000),
    DEADTRANS( L'r'   , 0x00b4 , 0x0155 , 0x0000),
    DEADTRANS( L's'   , 0x00b4 , 0x015b , 0x0000),
    DEADTRANS( L'u'   , 0x00b4 , 0x00fa , 0x0000),
    DEADTRANS( L'w'   , 0x00b4 , 0x1e83 , 0x0000),
    DEADTRANS( L'y'   , 0x00b4 , 0x00fd , 0x0000),
    DEADTRANS( L'z'   , 0x00b4 , 0x017a , 0x0000),
    DEADTRANS( 0x00c6 , 0x00b4 , 0x01fc , 0x0000),
    DEADTRANS( 0x00c7 , 0x00b4 , 0x1e08 , 0x0000),
    DEADTRANS( 0x00ca , 0x00b4 , 0x1ebe , 0x0000),
    DEADTRANS( 0x00e6 , 0x00b4 , 0x01fd , 0x0000),
    DEADTRANS( 0x00e7 , 0x00b4 , 0x1e09 , 0x0000),
    DEADTRANS( 0x00ea , 0x00b4 , 0x1ebf , 0x0000),
    DEADTRANS( 0x00b4 , 0x00b4 , 0x0301 , 0x0000),
    DEADTRANS( 0x00a4 , 0x00b4 , 0x00b4 , 0x0000),
    DEADTRANS( 0x00b5 , 0x00b4 , 0x00b4 , 0x0000),
    DEADTRANS( 0x017f , 0x00b4 , 0x00b4 , 0x0000),
    DEADTRANS( 0x00a0 , 0x00b4 , 0x00b4 , 0x0000),
    DEADTRANS( 0x2003 , 0x00b4 , 0x00b4 , 0x0000),
    DEADTRANS( 0x202f , 0x00b4 , 0x00b4 , 0x0000),
    DEADTRANS( L' '   , 0x00b4 , 0x00b4 , 0x0000),

    DEADTRANS( L'A'   , 0x00b5 , 0x0391 , 0x0000),
    DEADTRANS( L'B'   , 0x00b5 , 0x0392 , 0x0000),
    DEADTRANS( L'C'   , 0x00b5 , 0x03a8 , 0x0000),
    DEADTRANS( L'D'   , 0x00b5 , 0x0394 , 0x0000),
    DEADTRANS( L'E'   , 0x00b5 , 0x0395 , 0x0000),
    DEADTRANS( L'F'   , 0x00b5 , 0x03a6 , 0x0000),
    DEADTRANS( L'G'   , 0x00b5 , 0x0393 , 0x0000),
    DEADTRANS( L'H'   , 0x00b5 , 0x0397 , 0x0000),
    DEADTRANS( L'I'   , 0x00b5 , 0x0399 , 0x0000),
    DEADTRANS( L'J'   , 0x00b5 , 0x039e , 0x0000),
    DEADTRANS( L'K'   , 0x00b5 , 0x039a , 0x0000),
    DEADTRANS( L'L'   , 0x00b5 , 0x039b , 0x0000),
    DEADTRANS( L'M'   , 0x00b5 , 0x039c , 0x0000),
    DEADTRANS( L'N'   , 0x00b5 , 0x039d , 0x0000),
    DEADTRANS( L'O'   , 0x00b5 , 0x039f , 0x0000),
    DEADTRANS( L'P'   , 0x00b5 , 0x03a0 , 0x0000),
    DEADTRANS( L'R'   , 0x00b5 , 0x03a1 , 0x0000),
    DEADTRANS( L'S'   , 0x00b5 , 0x03a3 , 0x0000),
    DEADTRANS( L'T'   , 0x00b5 , 0x03a4 , 0x0000),
    DEADTRANS( L'U'   , 0x00b5 , 0x0398 , 0x0000),
    DEADTRANS( L'V'   , 0x00b5 , 0x03a9 , 0x0000),
    DEADTRANS( L'X'   , 0x00b5 , 0x03a7 , 0x0000),
    DEADTRANS( L'Y'   , 0x00b5 , 0x03a5 , 0x0000),
    DEADTRANS( L'Z'   , 0x00b5 , 0x0396 , 0x0000),
    DEADTRANS( L'a'   , 0x00b5 , 0x03b1 , 0x0000),
    DEADTRANS( L'b'   , 0x00b5 , 0x03b2 , 0x0000),
    DEADTRANS( L'c'   , 0x00b5 , 0x03c8 , 0x0000),
    DEADTRANS( L'd'   , 0x00b5 , 0x03b4 , 0x0000),
    DEADTRANS( L'e'   , 0x00b5 , 0x03b5 , 0x0000),
    DEADTRANS( L'f'   , 0x00b5 , 0x03c6 , 0x0000),
    DEADTRANS( L'g'   , 0x00b5 , 0x03b3 , 0x0000),
    DEADTRANS( L'h'   , 0x00b5 , 0x03b7 , 0x0000),
    DEADTRANS( L'i'   , 0x00b5 , 0x03b9 , 0x0000),
    DEADTRANS( L'j'   , 0x00b5 , 0x03be , 0x0000),
    DEADTRANS( L'k'   , 0x00b5 , 0x03ba , 0x0000),
    DEADTRANS( L'l'   , 0x00b5 , 0x03bb , 0x0000),
    DEADTRANS( L'm'   , 0x00b5 , 0x03bc , 0x0000),
    DEADTRANS( L'n'   , 0x00b5 , 0x03bd , 0x0000),
    DEADTRANS( L'o'   , 0x00b5 , 0x03bf , 0x0000),
    DEADTRANS( L'p'   , 0x00b5 , 0x03c0 , 0x0000),
    DEADTRANS( L'r'   , 0x00b5 , 0x03c1 , 0x0000),
    DEADTRANS( L's'   , 0x00b5 , 0x03c3 , 0x0000),
    DEADTRANS( L't'   , 0x00b5 , 0x03c4 , 0x0000),
    DEADTRANS( L'u'   , 0x00b5 , 0x03b8 , 0x0000),
    DEADTRANS( L'v'   , 0x00b5 , 0x03c9 , 0x0000),
    DEADTRANS( L'w'   , 0x00b5 , 0x03c2 , 0x0000),
    DEADTRANS( L'x'   , 0x00b5 , 0x03c7 , 0x0000),
    DEADTRANS( L'y'   , 0x00b5 , 0x03c5 , 0x0000),
    DEADTRANS( L'z'   , 0x00b5 , 0x03b6 , 0x0000),
    DEADTRANS( 0x00b5 , 0x00b5 , 0x00b5 , 0x0000),
    DEADTRANS( 0x00a4 , 0x00b5 , 0x00b5 , 0x0000),
    DEADTRANS( 0x017f , 0x00b5 , 0x00b5 , 0x0000),
    DEADTRANS( 0x00a0 , 0x00b5 , 0x00b5 , 0x0000),
    DEADTRANS( 0x2003 , 0x00b5 , 0x00b5 , 0x0000),
    DEADTRANS( 0x202f , 0x00b5 , 0x00b5 , 0x0000),
    DEADTRANS( L' '   , 0x00b5 , 0x00b5 , 0x0000),

    DEADTRANS( L'C'   , 0x00b8 , 0x00c7 , 0x0000),
    DEADTRANS( L'D'   , 0x00b8 , 0x1e10 , 0x0000),
    DEADTRANS( L'E'   , 0x00b8 , 0x0228 , 0x0000),
    DEADTRANS( L'G'   , 0x00b8 , 0x0122 , 0x0000),
    DEADTRANS( L'H'   , 0x00b8 , 0x1e28 , 0x0000),
    DEADTRANS( L'K'   , 0x00b8 , 0x0136 , 0x0000),
    DEADTRANS( L'L'   , 0x00b8 , 0x013b , 0x0000),
    DEADTRANS( L'N'   , 0x00b8 , 0x0145 , 0x0000),
    DEADTRANS( L'R'   , 0x00b8 , 0x0156 , 0x0000),
    DEADTRANS( L'S'   , 0x00b8 , 0x015e , 0x0000),
    DEADTRANS( L'T'   , 0x00b8 , 0x0162 , 0x0000),
    DEADTRANS( L'c'   , 0x00b8 , 0x00e7 , 0x0000),
    DEADTRANS( L'd'   , 0x00b8 , 0x1e11 , 0x0000),
    DEADTRANS( L'e'   , 0x00b8 , 0x0229 , 0x0000),
    DEADTRANS( L'g'   , 0x00b8 , 0x0123 , 0x0000),
    DEADTRANS( L'h'   , 0x00b8 , 0x1e29 , 0x0000),
    DEADTRANS( L'k'   , 0x00b8 , 0x0137 , 0x0000),
    DEADTRANS( L'l'   , 0x00b8 , 0x013c , 0x0000),
    DEADTRANS( L'n'   , 0x00b8 , 0x0146 , 0x0000),
    DEADTRANS( L'r'   , 0x00b8 , 0x0157 , 0x0000),
    DEADTRANS( L's'   , 0x00b8 , 0x015f , 0x0000),
    DEADTRANS( L't'   , 0x00b8 , 0x0163 , 0x0000),
    DEADTRANS( 0x00b8 , 0x00b8 , 0x0327 , 0x0000),
    DEADTRANS( 0x00a4 , 0x00b8 , 0x00b8 , 0x0000),
    DEADTRANS( 0x00b5 , 0x00b8 , 0x00b8 , 0x0000),
    DEADTRANS( 0x017f , 0x00b8 , 0x00b8 , 0x0000),
    DEADTRANS( 0x00a0 , 0x00b8 , 0x00b8 , 0x0000),
    DEADTRANS( 0x2003 , 0x00b8 , 0x00b8 , 0x0000),
    DEADTRANS( 0x202f , 0x00b8 , 0x00b8 , 0x0000),
    DEADTRANS( L' '   , 0x00b8 , 0x00b8 , 0x0000),

    DEADTRANS( '\''   , 0x017f , 0x02bc , 0x0000),
    DEADTRANS( L'0'   , 0x017f , 0x00ab , 0x0000),
    DEADTRANS( L'7'   , 0x017f , 0x203a , 0x0000),
    DEADTRANS( L'8'   , 0x017f , 0x2039 , 0x0000),
    DEADTRANS( L'9'   , 0x017f , 0x00bb , 0x0000),
    DEADTRANS( L'<'   , 0x017f , 0x2264 , 0x0000),
    DEADTRANS( L'>'   , 0x017f , 0x2265 , 0x0000),
    DEADTRANS( L'D'   , 0x017f , 0x00d0 , 0x0000),
    DEADTRANS( L'E'   , 0x017f , 0x018f , 0x0000),
    DEADTRANS( L'G'   , 0x017f , 0x014a , 0x0000),
    DEADTRANS( L'I'   , 0x017f , 0x0130 , 0x0000),
    DEADTRANS( L'J'   , 0x017f , 0x0132 , 0x0000),
    DEADTRANS( L'T'   , 0x017f , 0x00de , 0x0000),
    DEADTRANS( L'a'   , 0x017f , 0x00aa , 0x0000),
    DEADTRANS( L'd'   , 0x017f , 0x00f0 , 0x0000),
    DEADTRANS( L'e'   , 0x017f , 0x0259 , 0x0000),
    DEADTRANS( L'g'   , 0x017f , 0x014b , 0x0000),
    DEADTRANS( L'i'   , 0x017f , 0x0131 , 0x0000),
    DEADTRANS( L'j'   , 0x017f , 0x0133 , 0x0000),
    DEADTRANS( L'o'   , 0x017f , 0x00ba , 0x0000),
    DEADTRANS( L's'   , 0x017f , 0x017f , 0x0000),
    DEADTRANS( L't'   , 0x017f , 0x00fe , 0x0000),
    DEADTRANS( 0x00a0 , 0x017f , 0x2003 , 0x0000),
    DEADTRANS( 0x00ab , 0x017f , 0x201e , 0x0000),
    DEADTRANS( 0x00bb , 0x017f , 0x201f , 0x0000),
    DEADTRANS( 0x017f , 0x017f , 0x0000 , 0x0000),
    DEADTRANS( 0x2018 , 0x017f , 0x201a , 0x0000),
    DEADTRANS( 0x2019 , 0x017f , 0x201b , 0x0000),
    DEADTRANS( 0x202f , 0x017f , 0x2002 , 0x0000),
    DEADTRANS( 0x00a4 , 0x017f , 0x0000 , 0x0000),
    DEADTRANS( 0x00b5 , 0x017f , 0x0000 , 0x0000),
    DEADTRANS( 0x00a0 , 0x017f , 0x0000 , 0x0000),
    DEADTRANS( 0x2003 , 0x017f , 0x0000 , 0x0000),
    DEADTRANS( 0x202f , 0x017f , 0x0000 , 0x0000),
    DEADTRANS( L' '   , 0x017f , 0x0000 , 0x0000),

    DEADTRANS( L'('   , 0x02c7 , 0x208d , 0x0000),
    DEADTRANS( L')'   , 0x02c7 , 0x208e , 0x0000),
    DEADTRANS( L'+'   , 0x02c7 , 0x208a , 0x0000),
    DEADTRANS( L'-'   , 0x02c7 , 0x208b , 0x0000),
    DEADTRANS( L'0'   , 0x02c7 , 0x2080 , 0x0000),
    DEADTRANS( L'1'   , 0x02c7 , 0x2081 , 0x0000),
    DEADTRANS( L'2'   , 0x02c7 , 0x2082 , 0x0000),
    DEADTRANS( L'3'   , 0x02c7 , 0x2083 , 0x0000),
    DEADTRANS( L'4'   , 0x02c7 , 0x2084 , 0x0000),
    DEADTRANS( L'5'   , 0x02c7 , 0x2085 , 0x0000),
    DEADTRANS( L'6'   , 0x02c7 , 0x2086 , 0x0000),
    DEADTRANS( L'7'   , 0x02c7 , 0x2087 , 0x0000),
    DEADTRANS( L'8'   , 0x02c7 , 0x2088 , 0x0000),
    DEADTRANS( L'9'   , 0x02c7 , 0x2089 , 0x0000),
    DEADTRANS( L'='   , 0x02c7 , 0x208c , 0x0000),
    DEADTRANS( L'A'   , 0x02c7 , 0x01cd , 0x0000),
    DEADTRANS( L'C'   , 0x02c7 , 0x010c , 0x0000),
    DEADTRANS( L'D'   , 0x02c7 , 0x010e , 0x0000),
    DEADTRANS( L'E'   , 0x02c7 , 0x011a , 0x0000),
    DEADTRANS( L'G'   , 0x02c7 , 0x01e6 , 0x0000),
    DEADTRANS( L'H'   , 0x02c7 , 0x021e , 0x0000),
    DEADTRANS( L'I'   , 0x02c7 , 0x01cf , 0x0000),
    DEADTRANS( L'K'   , 0x02c7 , 0x01e8 , 0x0000),
    DEADTRANS( L'L'   , 0x02c7 , 0x013d , 0x0000),
    DEADTRANS( L'N'   , 0x02c7 , 0x0147 , 0x0000),
    DEADTRANS( L'O'   , 0x02c7 , 0x01d1 , 0x0000),
    DEADTRANS( L'R'   , 0x02c7 , 0x0158 , 0x0000),
    DEADTRANS( L'S'   , 0x02c7 , 0x0160 , 0x0000),
    DEADTRANS( L'T'   , 0x02c7 , 0x0164 , 0x0000),
    DEADTRANS( L'U'   , 0x02c7 , 0x01d3 , 0x0000),
    DEADTRANS( L'Z'   , 0x02c7 , 0x017d , 0x0000),
    DEADTRANS( L'a'   , 0x02c7 , 0x01ce , 0x0000),
    DEADTRANS( L'c'   , 0x02c7 , 0x010d , 0x0000),
    DEADTRANS( L'd'   , 0x02c7 , 0x010f , 0x0000),
    DEADTRANS( L'e'   , 0x02c7 , 0x011b , 0x0000),
    DEADTRANS( L'g'   , 0x02c7 , 0x01e7 , 0x0000),
    DEADTRANS( L'h'   , 0x02c7 , 0x021f , 0x0000),
    DEADTRANS( L'i'   , 0x02c7 , 0x01d0 , 0x0000),
    DEADTRANS( L'j'   , 0x02c7 , 0x01f0 , 0x0000),
    DEADTRANS( L'k'   , 0x02c7 , 0x01e9 , 0x0000),
    DEADTRANS( L'l'   , 0x02c7 , 0x013e , 0x0000),
    DEADTRANS( L'n'   , 0x02c7 , 0x0148 , 0x0000),
    DEADTRANS( L'o'   , 0x02c7 , 0x01d2 , 0x0000),
    DEADTRANS( L'r'   , 0x02c7 , 0x0159 , 0x0000),
    DEADTRANS( L's'   , 0x02c7 , 0x0161 , 0x0000),
    DEADTRANS( L't'   , 0x02c7 , 0x0165 , 0x0000),
    DEADTRANS( L'u'   , 0x02c7 , 0x01d4 , 0x0000),
    DEADTRANS( L'x'   , 0x02c7 , 0x2093 , 0x0000),
    DEADTRANS( L'z'   , 0x02c7 , 0x017e , 0x0000),
    DEADTRANS( 0x01b7 , 0x02c7 , 0x01ee , 0x0000),
    DEADTRANS( 0x0292 , 0x02c7 , 0x01ef , 0x0000),
    DEADTRANS( 0x02c7 , 0x02c7 , 0x030c , 0x0000),
    DEADTRANS( 0x00a4 , 0x02c7 , 0x02c7 , 0x0000),
    DEADTRANS( 0x00b5 , 0x02c7 , 0x02c7 , 0x0000),
    DEADTRANS( 0x017f , 0x02c7 , 0x02c7 , 0x0000),
    DEADTRANS( 0x00a0 , 0x02c7 , 0x02c7 , 0x0000),
    DEADTRANS( 0x2003 , 0x02c7 , 0x02c7 , 0x0000),
    DEADTRANS( 0x202f , 0x02c7 , 0x02c7 , 0x0000),
    DEADTRANS( L' '   , 0x02c7 , 0x02c7 , 0x0000),

    DEADTRANS( L'B'   , 0x02cd , 0x1e06 , 0x0000),
    DEADTRANS( L'D'   , 0x02cd , 0x1e0e , 0x0000),
    DEADTRANS( L'K'   , 0x02cd , 0x1e34 , 0x0000),
    DEADTRANS( L'L'   , 0x02cd , 0x1e3a , 0x0000),
    DEADTRANS( L'N'   , 0x02cd , 0x1e48 , 0x0000),
    DEADTRANS( L'R'   , 0x02cd , 0x1e5e , 0x0000),
    DEADTRANS( L'T'   , 0x02cd , 0x1e6e , 0x0000),
    DEADTRANS( L'Z'   , 0x02cd , 0x1e94 , 0x0000),
    DEADTRANS( L'b'   , 0x02cd , 0x1e07 , 0x0000),
    DEADTRANS( L'd'   , 0x02cd , 0x1e0f , 0x0000),
    DEADTRANS( L'h'   , 0x02cd , 0x1e96 , 0x0000),
    DEADTRANS( L'k'   , 0x02cd , 0x1e35 , 0x0000),
    DEADTRANS( L'l'   , 0x02cd , 0x1e3b , 0x0000),
    DEADTRANS( L'n'   , 0x02cd , 0x1e49 , 0x0000),
    DEADTRANS( L'r'   , 0x02cd , 0x1e5f , 0x0000),
    DEADTRANS( L't'   , 0x02cd , 0x1e6f , 0x0000),
    DEADTRANS( L'z'   , 0x02cd , 0x1e95 , 0x0000),
    DEADTRANS( 0x02cd , 0x02cd , 0x0331 , 0x0000),
    DEADTRANS( 0x00a4 , 0x02cd , 0x02cd , 0x0000),
    DEADTRANS( 0x00b5 , 0x02cd , 0x02cd , 0x0000),
    DEADTRANS( 0x017f , 0x02cd , 0x02cd , 0x0000),
    DEADTRANS( 0x00a0 , 0x02cd , 0x02cd , 0x0000),
    DEADTRANS( 0x2003 , 0x02cd , 0x02cd , 0x0000),
    DEADTRANS( 0x202f , 0x02cd , 0x02cd , 0x0000),
    DEADTRANS( L' '   , 0x02cd , 0x02cd , 0x0000),

    DEADTRANS( L'A'   , 0x02d8 , 0x0102 , 0x0000),
    DEADTRANS( L'E'   , 0x02d8 , 0x0114 , 0x0000),
    DEADTRANS( L'G'   , 0x02d8 , 0x011e , 0x0000),
    DEADTRANS( L'I'   , 0x02d8 , 0x012c , 0x0000),
    DEADTRANS( L'O'   , 0x02d8 , 0x014e , 0x0000),
    DEADTRANS( L'U'   , 0x02d8 , 0x016c , 0x0000),
    DEADTRANS( L'a'   , 0x02d8 , 0x0103 , 0x0000),
    DEADTRANS( L'e'   , 0x02d8 , 0x0115 , 0x0000),
    DEADTRANS( L'g'   , 0x02d8 , 0x011f , 0x0000),
    DEADTRANS( L'i'   , 0x02d8 , 0x012d , 0x0000),
    DEADTRANS( L'o'   , 0x02d8 , 0x014f , 0x0000),
    DEADTRANS( L'u'   , 0x02d8 , 0x016d , 0x0000),
    DEADTRANS( 0x00c0 , 0x02d8 , 0x1eb0 , 0x0000),
    DEADTRANS( 0x00e0 , 0x02d8 , 0x1eb1 , 0x0000),
    DEADTRANS( 0x02d8 , 0x02d8 , 0x0306 , 0x0000),
    DEADTRANS( 0x00a4 , 0x02d8 , 0x02d8 , 0x0000),
    DEADTRANS( 0x00b5 , 0x02d8 , 0x02d8 , 0x0000),
    DEADTRANS( 0x017f , 0x02d8 , 0x02d8 , 0x0000),
    DEADTRANS( 0x00a0 , 0x02d8 , 0x02d8 , 0x0000),
    DEADTRANS( 0x2003 , 0x02d8 , 0x02d8 , 0x0000),
    DEADTRANS( 0x202f , 0x02d8 , 0x02d8 , 0x0000),
    DEADTRANS( L' '   , 0x02d8 , 0x02d8 , 0x0000),

    DEADTRANS( L'A'   , 0x02d9 , 0x0226 , 0x0000),
    DEADTRANS( L'B'   , 0x02d9 , 0x1e02 , 0x0000),
    DEADTRANS( L'C'   , 0x02d9 , 0x010a , 0x0000),
    DEADTRANS( L'D'   , 0x02d9 , 0x1e0a , 0x0000),
    DEADTRANS( L'E'   , 0x02d9 , 0x0116 , 0x0000),
    DEADTRANS( L'F'   , 0x02d9 , 0x1e1e , 0x0000),
    DEADTRANS( L'G'   , 0x02d9 , 0x0120 , 0x0000),
    DEADTRANS( L'H'   , 0x02d9 , 0x1e22 , 0x0000),
    DEADTRANS( L'I'   , 0x02d9 , 0x0130 , 0x0000),
    DEADTRANS( L'L'   , 0x02d9 , 0x013f , 0x0000),
    DEADTRANS( L'M'   , 0x02d9 , 0x1e40 , 0x0000),
    DEADTRANS( L'N'   , 0x02d9 , 0x1e44 , 0x0000),
    DEADTRANS( L'O'   , 0x02d9 , 0x022e , 0x0000),
    DEADTRANS( L'P'   , 0x02d9 , 0x1e56 , 0x0000),
    DEADTRANS( L'R'   , 0x02d9 , 0x1e58 , 0x0000),
    DEADTRANS( L'S'   , 0x02d9 , 0x1e60 , 0x0000),
    DEADTRANS( L'T'   , 0x02d9 , 0x1e6a , 0x0000),
    DEADTRANS( L'W'   , 0x02d9 , 0x1e86 , 0x0000),
    DEADTRANS( L'X'   , 0x02d9 , 0x1e8a , 0x0000),
    DEADTRANS( L'Y'   , 0x02d9 , 0x1e8e , 0x0000),
    DEADTRANS( L'Z'   , 0x02d9 , 0x017b , 0x0000),
    DEADTRANS( L'a'   , 0x02d9 , 0x0227 , 0x0000),
    DEADTRANS( L'b'   , 0x02d9 , 0x1e03 , 0x0000),
    DEADTRANS( L'c'   , 0x02d9 , 0x010b , 0x0000),
    DEADTRANS( L'd'   , 0x02d9 , 0x1e0b , 0x0000),
    DEADTRANS( L'e'   , 0x02d9 , 0x0117 , 0x0000),
    DEADTRANS( L'f'   , 0x02d9 , 0x1e1f , 0x0000),
    DEADTRANS( L'g'   , 0x02d9 , 0x0121 , 0x0000),
    DEADTRANS( L'h'   , 0x02d9 , 0x1e23 , 0x0000),
    DEADTRANS( L'i'   , 0x02d9 , 0x0131 , 0x0000),
    DEADTRANS( L'l'   , 0x02d9 , 0x0140 , 0x0000),
    DEADTRANS( L'm'   , 0x02d9 , 0x1e41 , 0x0000),
    DEADTRANS( L'n'   , 0x02d9 , 0x1e45 , 0x0000),
    DEADTRANS( L'o'   , 0x02d9 , 0x022f , 0x0000),
    DEADTRANS( L'p'   , 0x02d9 , 0x1e57 , 0x0000),
    DEADTRANS( L'r'   , 0x02d9 , 0x1e59 , 0x0000),
    DEADTRANS( L's'   , 0x02d9 , 0x1e61 , 0x0000),
    DEADTRANS( L't'   , 0x02d9 , 0x1e6b , 0x0000),
    DEADTRANS( L'w'   , 0x02d9 , 0x1e87 , 0x0000),
    DEADTRANS( L'x'   , 0x02d9 , 0x1e8b , 0x0000),
    DEADTRANS( L'y'   , 0x02d9 , 0x1e8f , 0x0000),
    DEADTRANS( L'z'   , 0x02d9 , 0x017c , 0x0000),
    DEADTRANS( 0x017f , 0x02d9 , 0x1e9b , 0x0000),
    DEADTRANS( 0x02d9 , 0x02d9 , 0x0307 , 0x0000),
    DEADTRANS( 0x00a4 , 0x02d9 , 0x02d9 , 0x0000),
    DEADTRANS( 0x00b5 , 0x02d9 , 0x02d9 , 0x0000),
    DEADTRANS( 0x00a0 , 0x02d9 , 0x02d9 , 0x0000),
    DEADTRANS( 0x2003 , 0x02d9 , 0x02d9 , 0x0000),
    DEADTRANS( 0x202f , 0x02d9 , 0x02d9 , 0x0000),
    DEADTRANS( L' '   , 0x02d9 , 0x02d9 , 0x0000),

    DEADTRANS( L'A'   , 0x02da , 0x00c5 , 0x0000),
    DEADTRANS( L'U'   , 0x02da , 0x016e , 0x0000),
    DEADTRANS( L'a'   , 0x02da , 0x00e5 , 0x0000),
    DEADTRANS( L'u'   , 0x02da , 0x016f , 0x0000),
    DEADTRANS( L'w'   , 0x02da , 0x1e98 , 0x0000),
    DEADTRANS( L'y'   , 0x02da , 0x1e99 , 0x0000),
    DEADTRANS( 0x02da , 0x02da , 0x030a , 0x0000),
    DEADTRANS( 0x00a4 , 0x02da , 0x02da , 0x0000),
    DEADTRANS( 0x00b5 , 0x02da , 0x02da , 0x0000),
    DEADTRANS( 0x017f , 0x02da , 0x02da , 0x0000),
    DEADTRANS( 0x00a0 , 0x02da , 0x02da , 0x0000),
    DEADTRANS( 0x2003 , 0x02da , 0x02da , 0x0000),
    DEADTRANS( 0x202f , 0x02da , 0x02da , 0x0000),
    DEADTRANS( L' '   , 0x02da , 0x02da , 0x0000),

    DEADTRANS( L'A'   , 0x02db , 0x0104 , 0x0000),
    DEADTRANS( L'E'   , 0x02db , 0x0118 , 0x0000),
    DEADTRANS( L'I'   , 0x02db , 0x012e , 0x0000),
    DEADTRANS( L'O'   , 0x02db , 0x01ea , 0x0000),
    DEADTRANS( L'U'   , 0x02db , 0x0172 , 0x0000),
    DEADTRANS( L'a'   , 0x02db , 0x0105 , 0x0000),
    DEADTRANS( L'e'   , 0x02db , 0x0119 , 0x0000),
    DEADTRANS( L'i'   , 0x02db , 0x012f , 0x0000),
    DEADTRANS( L'o'   , 0x02db , 0x01eb , 0x0000),
    DEADTRANS( L'u'   , 0x02db , 0x0173 , 0x0000),
    DEADTRANS( 0x02db , 0x02db , 0x0328 , 0x0000),
    DEADTRANS( 0x00a4 , 0x02db , 0x02db , 0x0000),
    DEADTRANS( 0x00b5 , 0x02db , 0x02db , 0x0000),
    DEADTRANS( 0x017f , 0x02db , 0x02db , 0x0000),
    DEADTRANS( 0x00a0 , 0x02db , 0x02db , 0x0000),
    DEADTRANS( 0x2003 , 0x02db , 0x02db , 0x0000),
    DEADTRANS( 0x202f , 0x02db , 0x02db , 0x0000),
    DEADTRANS( L' '   , 0x02db , 0x02db , 0x0000),

    DEADTRANS( L'O'   , 0x02dd , 0x0150 , 0x0000),
    DEADTRANS( L'U'   , 0x02dd , 0x0170 , 0x0000),
    DEADTRANS( L'o'   , 0x02dd , 0x0151 , 0x0000),
    DEADTRANS( L'u'   , 0x02dd , 0x0171 , 0x0000),
    DEADTRANS( 0x02dd , 0x02dd , 0x030b , 0x0000),
    DEADTRANS( 0x00a4 , 0x02dd , 0x02dd , 0x0000),
    DEADTRANS( 0x00b5 , 0x02dd , 0x02dd , 0x0000),
    DEADTRANS( 0x017f , 0x02dd , 0x02dd , 0x0000),
    DEADTRANS( 0x00a0 , 0x02dd , 0x02dd , 0x0000),
    DEADTRANS( 0x2003 , 0x02dd , 0x02dd , 0x0000),
    DEADTRANS( 0x202f , 0x02dd , 0x02dd , 0x0000),
    DEADTRANS( L' '   , 0x02dd , 0x02dd , 0x0000),

    DEADTRANS( L'A'   , 0x02f5 , 0x0200 , 0x0000),
    DEADTRANS( L'E'   , 0x02f5 , 0x0204 , 0x0000),
    DEADTRANS( L'I'   , 0x02f5 , 0x0208 , 0x0000),
    DEADTRANS( L'O'   , 0x02f5 , 0x020c , 0x0000),
    DEADTRANS( L'R'   , 0x02f5 , 0x0210 , 0x0000),
    DEADTRANS( L'U'   , 0x02f5 , 0x0214 , 0x0000),
    DEADTRANS( L'a'   , 0x02f5 , 0x0201 , 0x0000),
    DEADTRANS( L'e'   , 0x02f5 , 0x0205 , 0x0000),
    DEADTRANS( L'i'   , 0x02f5 , 0x0209 , 0x0000),
    DEADTRANS( L'o'   , 0x02f5 , 0x020d , 0x0000),
    DEADTRANS( L'r'   , 0x02f5 , 0x0211 , 0x0000),
    DEADTRANS( L'u'   , 0x02f5 , 0x0215 , 0x0000),
    DEADTRANS( 0x02f5 , 0x02f5 , 0x030f , 0x0000),
    DEADTRANS( 0x00a4 , 0x02f5 , 0x02f5 , 0x0000),
    DEADTRANS( 0x00b5 , 0x02f5 , 0x02f5 , 0x0000),
    DEADTRANS( 0x017f , 0x02f5 , 0x02f5 , 0x0000),
    DEADTRANS( 0x00a0 , 0x02f5 , 0x02f5 , 0x0000),
    DEADTRANS( 0x2003 , 0x02f5 , 0x02f5 , 0x0000),
    DEADTRANS( 0x202f , 0x02f5 , 0x02f5 , 0x0000),
    DEADTRANS( L' '   , 0x02f5 , 0x02f5 , 0x0000),

    0, 0
};

static ALLOC_SECTION_LDATA KBDTABLES KbdTables = {
    /*
     * Modifier keys
     */
    &CharModifiers,

    /*
     * Characters tables
     */
    aVkToWcharTable,

    /*
     * Diacritics
     */
    aDeadKey,

    /*
     * Names of Keys
     */
    aKeyNames,
    aKeyNamesExt,
    aKeyNamesDead,

    /*
     * Scan codes to Virtual Keys
     */
    ausVK,
    sizeof(ausVK) / sizeof(ausVK[0]),
    aE0VscToVk,
    aE1VscToVk,

    /*
     * Locale-specific special processing
     */
    MAKELONG(KLLF_ALTGR | KLLF_ALTGR, KBD_VERSION),

    /*
     * Ligatures
     */
    0,
    0,
    NULL
};

PKBDTABLES KbdLayerDescriptor(VOID)
{
    return &KbdTables;
}

