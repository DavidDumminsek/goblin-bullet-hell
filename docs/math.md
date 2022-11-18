<script src="https://polyfill.io/v3/polyfill.min.js?features=es6"></script>
<script id="MathJax-script" async src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-mml-chtml.js"></script>
## Enemy movement
A simple way to give enemies varied movement is to asign a 4th degree polynomial.  
The constants are simply stored in the json file for the level and you can easily for example get a 
linear function by setting all but the last two constants to <img src="https://rawgit.com/in	git@gitlab.liu.se:davdu153/tdp005_dogeater/main/svgs/29632a9bf827ce0200454dd32fc3be82.svg?invert_in_darkmode" align=middle width=8.219209349999991pt height=21.18721440000001pt/>.  
Example for how a 4th degree polynomial is built:
<figure>
<img src="https://rawgit.com/in	git@gitlab.liu.se:davdu153/tdp005_dogeater/main/svgs/32eb0404f1f155144c886f369abc66e8.svg?invert_in_darkmode" align=middle width=181.29923129999997pt height=26.76175259999998pt/>
<figcaption align = "center"><b> Reason why <img src="https://rawgit.com/in	git@gitlab.liu.se:davdu153/tdp005_dogeater/main/svgs/8cd34385ed61aca950a6b06d09fb50ac.svg?invert_in_darkmode" align=middle width=7.654137149999991pt height=14.15524440000002pt/> is not used is i want i reserved for exceptions </b>
</figcaption>
</figure>

