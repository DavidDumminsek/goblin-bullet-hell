## Enemy movement
A simple way to give enemies varied movement is to asign a 4th degree polynomial.  
The constants are simply stored in the json file for the level and you can easily for example get a 
linear function by setting all but the last two constants to $´0´$.  
Example for how a 4th degree polynomial is built in this game (saving **e** variable for exceptions):
```math
ax^4+bx^3+cx^2+dx+f  
```
Enemy1(name tbd):   
```math
0x^4+0x^3+0x^2-4x+20  
```
https://gyazo.com/e6553be980c3b803aa25ae38338483dc
