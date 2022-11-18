## Enemy movement
A simple way to give enemies varied movement is to asign a 4th degree polynomial.  
The constants are simply stored in the json file for the level and you can easily for example get a 
linear function by setting all but the last two constants to <img src="svgs/29632a9bf827ce0200454dd32fc3be82.svg?invert_in_darkmode" align=middle width=8.219209349999991pt height=21.18721440000001pt/>.  
Example for how a 4th degree polynomial is built:
<figure>
<img src="svgs/32eb0404f1f155144c886f369abc66e8.svg?invert_in_darkmode" align=middle width=181.29923129999997pt height=26.76175259999998pt/>
<figcaption align = "center"><b> Reason why <img src="svgs/8cd34385ed61aca950a6b06d09fb50ac.svg?invert_in_darkmode" align=middle width=7.654137149999991pt height=14.15524440000002pt/> is not used is i want i reserved for exceptions </b>
</figcaption>
</figure>

