# Console Game Othello

## Rules 

Starting position:

 <img width="295" height="246" alt="Zrzut ekranu 2025-10-21 125053" src="https://github.com/user-attachments/assets/d4c03b98-1c31-4fc0-a4e9-3033ad689af6" />

First player enters coordinates of where he wants to play his disc. The disc must outflank at least one opponent disc.

<img width="291" height="85" alt="Zrzut ekranu 2025-10-21 130239" src="https://github.com/user-attachments/assets/ecbd24e7-a847-4081-aeb9-74e69c15804c" /> ,

<img width="232" height="191" alt="Zrzut ekranu 2025-10-21 130300" src="https://github.com/user-attachments/assets/cb5755c9-26c3-4881-9be6-cbed730c1425" />


The outflanked discs change color to opposite. <br />
  Then the game continues untill the board is full or no player can make a legal move. (If a player can't make a legal move his turn is skipped)
Player with more discs of his color at the end wins.


The game has input validation:
<br />
<img width="275" height="58" alt="Zrzut ekranu 2025-10-21 130352" src="https://github.com/user-attachments/assets/4c42bd4d-0ee0-405e-9675-b69a4cb6d443" />
<br />

## Playing the game

The best way to play the game is to open Othello folder in vscode and compile it with it's debugger (by hitting F5 key).
Symbols used in the game are not synchronized with the usual terminal font, so if you have problems with symbols you can compile OthelloSymbols.cpp which uses letters.

This should work on windows as well as linux.
 
Othello.cpp must be in the same directory as Grid8x8.hpp, rules.txt and saveFile.txt for it to work properly.<br />
OthelloSymbols.cpp must be in the same directory as Grid8x8Symbols.hpp, rules.txt and saveFile.txt for it to work properly.


