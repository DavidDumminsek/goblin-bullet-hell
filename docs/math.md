<script src="https://polyfill.io/v3/polyfill.min.js?features=es6"></script>
<script id="MathJax-script" async src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-mml-chtml.js"></script>
## Enemy movement
A simple way to give enemies varied movement is to asign a 4th degree polynomial.  
The constants are simply stored in the json file for the level and you can easily for example get a 
linear function by setting all but the last two constants to $0$.  
Example for how a 4th degree polynomial is built:
<figure>
$ax^4 + bx^3 + cx^2 + dx + f$
<figcaption align = "center"><b> Reason why $e$ is not used is i want i reserved for exceptions </b>
</figcaption>
</figure>

