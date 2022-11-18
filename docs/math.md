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
<table align="center"><tr><td align="center" width="9999">

# Enemy1 Movement Graph

<img src="docs/img/enemy1graph.png"  width="250">
</td></tr></table>

