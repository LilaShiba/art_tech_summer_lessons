# Art and Tech

Changing how we view and interact with the world!


## Circuit Playground Cheat Sheet

Task         | Code 
------------ | -------------
Change Neopixels   | ``` CircuitPlayground.setPixelColor(pixel,red,green,blue);```
Change Brightness  | ``` CircuitPlayground.changeBrightness(brightness);```
Pause for a second | ``` delay(1000); ```
Light sensor       | ``` int value = CircuitPlayground.lightSensor();```
Sound Sensor       | ``` int value = CircuitPlayground.soundSensor();```
Touch Pads         | ``` int cap0 = CircuitPlayground.readCap(0);```
Accelerometer      | ``` int x = CircuitPlayground.motionX();```
Speaker            | ``` CircuitPlayground.playTone(500, 100); ```
Buttons            | ``` CircuitPlayground.leftButton();```
Slide Switch       | ``` CircuitPlayground.slideSwitch();```


Note for touch pads:
just set the pin to any of the pad #'s next to the pad (e.g. 0, 1, 2, 3, 6, 9, 10 and 12) The number returned will vary from about 0 to about 1000.


## Control Flow

#### For Loop
The for statement is useful for any repetitive operation. The for statement is used to repeat a block of statements enclosed in curly braces. An increment counter is usually used to increment and terminate the loop.

```c
      // for every neopixel
  for (int pixel = 0; pixel < 11; pixel+=2){
      // make it this color
    CircuitPlayground.setPixelColor(pixel,0,255,0);
    delay(100);
  }

```

#### reverse for loop
```c
  for (int pixel = 10; pixel > -1; pixel-=2){
    CircuitPlayground.setPixelColor(pixel,0,0,255);
    delay(50);
  }

```

#### Conditionals 
The if statement checks for a condition and executes the proceeding statement or set of statements if the condition is 'true'.

```c
if (condition1)
{
  // do Thing A
}
else if (condition2)
{
  // do Thing B
}
else
{
  // do Thing C
}
```
Operator     | Meaning 
------------ | ------------
x == y | (x is equal to y)
x != y | (x is not equal to y)
x <  y | (x is less than y)
x >  y | (x is greater than y)
x <= y | (x is less than or equal to y)
x >= y | (x is greater than or equal to y)

#### For Example:

```c
  if (something > something_else) {
    CircuitPlayground.setPixelColor(pixel,0,0,0);
  } else {
     CircuitPlayground.setPixelColor(pixel,255,255,255);
  }
```






## Hello World Program
### The goal is to make a light show!


```c
// gives us all the short cuts
#include <Adafruit_CircuitPlayground.h>

void setup() {
// tells the computer that a circuit playground is connected
  CircuitPlayground.begin();
}

void loop() {
//                                 light,red,green,blue
    CircuitPlayground.setPixelColor(pixel,255,255,255);
//                                  0 is off 255 is all the way on

}

```



## Program 2: Sensors
### Light Sensor & Speaker with Circuit Playground 
- [understanding mapping](https://www.arduino.cc/reference/en/language/functions/math/map/)

#### Light Sensor
The light sensor is on pin A5 and it will read between 0 and 1023 with higher values corresponding to brighter light levels. The range is approximately 0 Lux to 1500 Lux maximum. 300 is common for most indoor light levels.

You can request the raw analog reading (0 = no light, up to 1023 = ~1500 Lux) with CircuitPlayground.lightSensor()

#### Speaker
You can make your circuit playground sing with the built in buzzer. This is a miniature magnetic speaker connected to digital pin #5

You can play basic square wave beeps/tones with CircuitPlayground.playTone(frequency, duration_ms). Where frequency is the frequency in Hertz and duration is the time to play the beep for, in millisecods.

That means CircuitPlayground.playTone(440, 500) will play 440 Hz (middle A) for 500 milliseconds (half of a second). 


```c

#include <Adafruit_CircuitPlayground.h>

int maxValue = 100;

void setup() {
  CircuitPlayground.begin();
}

void loop() {
  // use the light sensor and save data into a variable
  int sensorReading = CircuitPlayground.lightSensor();
  
  // map light data into something that makes sense for sound
  int frequency = map(sensorReading, 0, maxValue, 500, 800);

  Serial.println(sensorReading);

  //CircuitPlayground.playTone(frequency, duration_ms)
  CircuitPlayground.playTone(frequency, 50);
}

```

## Other How To's for Circuit Playground

### Complie & Upload your Code

![code](https://kyle1james.gitbooks.io/sub-day/content/assets/Screen%20Shot%202017-05-09%20at%207.39.34%20PM.png)


### Then

![code2](https://kyle1james.gitbooks.io/sub-day/content/assets/Screen%20Shot%202017-05-09%20at%207.40.29%20PM.png)

### Now we verify the code, which will output any errors in the terminal. The check mark
Then upload. The arrow

![code3](https://kyle1james.gitbooks.io/sub-day/content/assets/Screen%20Shot%202017-05-09%20at%207.42.36%20PM.png)

### Even More Examples
[examples](https://github.com/kyle1james/examples)



#### The unconventional mixing and matching of subject areas

[itp](https://tisch.nyu.edu/itp)
[media lab](https://www.media.mit.edu/)
[eyebeam](https://www.eyebeam.org/)



## All About Data

### Analog & Digital
[resource](https://learn.sparkfun.com/tutorials/analog-vs-digital)

What? It's like two different languages in the electronic world and the languages are called signals?

Signals are passed between devices in order to send and receive information

#### analog

Analog Signals are time-varying quantities: Basically, voltage changing over time to relay information.

Problem: Interference, these little guys can easily be interfered with. Examples are static on the radio or old school tv sets.

![pic1](https://cdn.sparkfun.com/assets/3/7/6/6/0/51c48875ce395f745a000000.png)

```
void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);
```

#### digital
There at 10 types of people in the world. Those who get binary and those who don'- [ ]

Digital signals try to solve the problem of analog interference by having two signal states: on or off. It's binary.

![pic2](https://cdn.sparkfun.com/assets/c/8/5/b/e/51c495ebce395f1b5a000000.png)

```
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
```

### Long Story Short
There are ways around both digital and analog to do what you want! Digital tends to be easier but cost more, and analog is the opposite


## Example of LED Art + Tech

### Planning Stage

A ton of work goes into planning. It is the most important stage as it serves as the how-to when building!
![pic0](pic0.jpg)

This includes tech planning as well. Both Art + Tech need to merge.

![pic1](pic1.png)

The Art folk were priceless in this Stage
![pic00](pic00.JPG)

### We got data from the Sun

So, we built a little app that collects live solar data
![app1](ss0.png)

Then, we used the info from the sun to control LEDs in silicon skin with hand blown glass shards
![app2](ss1.png)

This is where art and tech meet!
![done](code.PNG)

### Building

This was the first of several prototypes. You can check out the program prototype [here](https://art-tech-example.herokuapp.com/)

![pic2](pic2.JPG)

![pic4](pic4.JPG)

### Testing
You have to test and refine. Failing is just a step towards the end goal!

![done](done.JPG)

https://www.youtube.com/embed/-cnLp1fHb-Y
