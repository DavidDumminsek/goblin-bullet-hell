## Enemy movement
A simple way to give enemies varied movement is to asign a 4th degree polynomial.  
The constants are simply stored in the json file for the level and you can easily for example get a 
<<<<<<< HEAD
linear function by setting all but the last two constants to $´0´$.  
Example for how a 4th degree polynomial is built in this game (saving **e** variable for exceptions):
```math
ax^4+bx^3+cx^2+dx+f  
```
Enemy1(name tbd):   
```math
0x^4+0x^3+0x^2-4x+20  
```
![enemy1 graph](https://gyazo.com/e6553be980c3b803aa25ae38338483dc)
=======
linear function by setting all but the last two constants to $0$.  
Example for how a 4th degree polynomial is built:
<figure>
$ax^4 + bx^3 + cx^2 + dx + f$
<figcaption align = "center"><b> Reason why $e$ is not used is i want i reserved for exceptions </b>
</figcaption>
</figure>
>>>>>>> 7f3c94f (Update docs/math.md)
