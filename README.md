## Content

This repository contains a simple .klc file which can be used with [Microsoft Keyboard Layout Creator](https://www.microsoft.com/en-us/download/details.aspx?id=22339)
to add a custom layout on Windows supporting a new optimized azerty keyboard layout, currently under review.

![](./refs/main_layout.png)

## Installation

See the [release tab](https://github.com/tbolon/optimized-azerty-win/releases) to download the last setup.

When the keyboard layout is installed, you will certainly have to restart Windows to allow the new layout to be displayed on the language setup screen.

The keyboard is installed as « New Azerty Keyboard » layout.

## Known issues

Once installed, the keyboard layout supports most, but not all, of the norm.

### Unsupported currencies

The norm assigns some currency symbols to various key combinations that are currently not supported.

For instance, the `₼` MANAT SIGN (U+20BC) is assigned to the following key combination:

<kbd>AltGr</kbd>+<kbd>¤</kbd>, <kbd>AltGr</kbd>+<kbd>m</kbd>

Currently, currency signs that must be prefixed with <kbd>AltGr</kbd> are not supported.

These are:

- `₨` RUPEE SIGN (U+20A8)
- `₡` COLON SIGN (U+20A1)
- `₢` CRUZEIRO SIGN (U+20A2)
- `₰` GERMAN PENNY SIGN (U+20B0)
- `₼` MANAT SIGN (U+20BC)
- `₾` LARI SIGN (U+20BE)

Although assigned to <kbd>AltGr</kbd>+<kbd>¤</kbd>, <kbd>AltGr</kbd>+<kbd>E</kbd>, the `¤` CURRENCY SIGN (U+00A4) is available by pressing a <kbd>SPACE</kbd> instead. It is thus available by typing <kbd>AltGr</kbd>+<kbd>¤</kbd>, <kbd>SPACE</kbd>.


## Links

- [Le nouvel AZERTY](http://norme-azerty.fr/)
- [Annonce AFNOR](https://www.afnor.org/presse_avril2019/clavier-francais-norme-volontaire-pour-faciliter-ecriture/)
- [Norme AFNOR](https://www.boutique.afnor.org/norme/nf-z71-300/interfaces-utilisateurs-dispositions-de-clavier-bureautique-francais/article/901594/fa188960)
