# Art and Tech

Changing how we view and interact with the world!

## CP MIDI
[link to cp midi](https://kyle1james.github.io/cp_midi_2018/)


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




# DJ Circuit Playground

Boards to download or update:
- Ardunio AVR
- Adafruit AVR
- MIDIUSB
- TeeOnArdu

Board Link: 
https://adafruit.github.io/arduino-board-index/package_adafruit_index.json


We will be following this: [link](https://learn.adafruit.com/circuit-playground-pizza-box-dj-controller/pz-1-pizza-box-dj-code)

FIrst things first, we have to install additional libraries. This is so that the CP can learn some new commands. Like how to be a MIDI

#### To Add Additional Boards
Go to Arduino >> Preferences and add the link below to the 'Additional Boards Manager URL'

https://adafruit.github.io/arduino-board-index/package_adafruit_index.json

![link](https://cdn-learn.adafruit.com/assets/assets/000/033/278/medium800/flora_urls.png?1466733189)

Nice! Now, search for Adafruit TeeOnArdu. Click on the board entry and then click the Install button.

#### How to Use It

- In the Arduino IDE, select the new entry under Tools > Board > Circuit Playground (TeensyCore)
- Then, select Tools > USB Type > MIDI
- To upload new sketches you just have to double-press the reset button on the Circuit Playground each time you hit the upload button 
- If you decide to use your Circuit Playground as a regular Circuit Playground again, just select it under Tools > Board >Circuit Playground and upload an Arduino sketch like Blink File > Examples > Basics > Digital > Blink. The first time you have to double-press the reset button, but after that your Circuit Playground behaves like out of the box.

Look up notes: [midi note numbers](http://www.inspiredacoustics.com/en/MIDI_note_numbers_and_center_frequencies)

#### Process
- create threshold value. How hard do you have to touch the sensor for it to trigger?
```c
const int CAPMIN = 25; // it is 25 to cancel noise
```

- create your cap variables
```c
int cap1 = CircuitPlayground.readCap(1);
```
- use variable in conditional
```c
 if (cap1 > CAPMIN){
      magic code here
 }
```
- use MIDI methods to play notes: usb.MIDI.sendNoteOn(note,velocity,channel)
```c
 if (cap1 > CAPMIN){
     usbMIDI.sendNoteOn(42,127,0);
     delay(100);
     usbMIDI.sendNoteOff(61,0,0);
 }
```
- Customize code. Does a light pattern happen for a certain note?

#### Example Code

```c
#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
}

void loop() {
  const int CAPMIN = 25; // it is 25 to cancel noise
  int cap1 = CircuitPlayground.readCap(1);
  
  if (CircuitPlayground.leftButton()) {
    CircuitPlayground.redLED(HIGH);
                    //(note,velocity,channel)
    usbMIDI.sendNoteOn(60, 127, 0);  // 60 = C4 velocity 127 (max)
    delay(100);
    usbMIDI.sendNoteOff(60, 0, 0);
    CircuitPlayground.redLED(LOW);
  }
  if (CircuitPlayground.rightButton()) {
    CircuitPlayground.redLED(HIGH);
    usbMIDI.sendNoteOn(61, 127, 0);
    delay(100);
    usbMIDI.sendNoteOff(61, 0, 0);
    CircuitPlayground.redLED(LOW); 
  }
  
  if (cap1 > CAPMIN){
     usbMIDI.sendNoteOn(42,127,0);
     delay(100);
     usbMIDI.sendNoteOff(61,0,0);
  }

  // dont listen to any incoming MIDI!
  while (usbMIDI.read()) {
  }
}

```
#### Debugging
If you still run into errors, try updateing arduino and adafruit avr boards


## DJ Code

```c

//Circuit Playground PZ-1 Pizza Box DJ
// by John Park
// a.k.a. DJ Sternocleidomastoid
// for Adafruit Industries
// MIT License
///////////////////////////////////////////////////////////////////////////////
// MIDI controller for Traktor, Mixxx and other DJ software
// Uses Circuit Playground (Teensy Core) to send MIDI over
// USB
// 
// MIDI controller command mapping must be set up in your DJ software, check
// below for MIDI signal outputs
///////////////////////////////////////////////////////////////////////////////

#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>

///////////////////////////////////////////////////////////////////////////////
//MIDI CC (change control) assignments
const int CHANNEL         = 14; //MIDI channel 
const int LEFT_BUTTON_CC  =  4; //Play/Pause Deck A
const int RIGHT_BUTTON_CC = 19; //MIDI CC for left button: FX 1 On
const int CAP1_CONTROL    = 1;  //Select/Set+Store Hotcue 2 (1 is load point)
const int CAP0_CONTROL    = 0;  //Left fader mixes Deck B volume down
const int CAP2_CONTROL    = 2;  //Delete hotcue 2 point       
const int CAP3_CONTROL    = 3;  //Remix Trigger 6-1 or Loop Size /2  
const int CAP12_CONTROL   = 12; //Right fader mixes Deck A volume down
const int CAP6_CONTROL    = 6;  //Scratch (jog turn) Deck B     
const int CAP9_CONTROL    = 9;  //Play/Pause Deck B
const int CAP10_CONTROL   = 10; //Remix Trigger 6-4 or Loop Set 4 bar

int leftButtonState = 0;
int rightButtonState = 0;
int leftButtonLastState = 0;
int rightButtonLastState = 0;
int cap0State = 0;
int cap0LastState = 0;
int cap1State = 0;
int cap1LastState = 0;
int cap2State = 0;
int cap2LastState = 0;
int cap3State = 0;
int cap3LastState = 0;
int cap12State = 0;
int cap12LastState = 0;
int cap6State = 0;
int cap6LastState = 0;
int cap9State = 0;
int cap9LastState = 0;
int cap10State = 0;
int cap10LastState = 0;
bool cap1ON = false; //prevents off command from being spewed
bool cap12ON = false; //prevents off command from being spewed
bool cap6ON = false; //prevents off command from being spewed

const int CAPMIN = 25; //lowest value that's considered an intentional touch to minimize crosstalk
const int CAPSLOP = 0; //value of capacitive pad variance that's considered noise


///////////////////////////////////////////////////////////////////////////////
//mic_meter code
// To keep the display 'lively,' an upper and lower range of volume
// levels are dynamically adjusted based on recent audio history, and
// the graph is fit into this range.
#define  FRAMES 8
uint16_t lvl[FRAMES],           // Audio level for the prior #FRAMES frames
         avgLo  = 6,            // Audio volume lower end of range
         avgHi  = 512,          // Audio volume upper end of range
         sum    = 256 * FRAMES; // Sum of lvl[] array
uint8_t  lvlIdx = 0;            // Counter into lvl[] array
int16_t  peak   = 0;            // Falling dot shows recent max
int8_t   peakV  = 0;            // Velocity of peak dot

///////////////////////////////////////////////////////////////////////////////
void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30); //make brighter for performance, up to 255
  CircuitPlayground.clearPixels();
  for(uint8_t i=0; i<FRAMES; i++) lvl[i] = 256;

}

///////////////////////////////////////////////////////////////////////////////
// COLOR TABLES for animation ----------------------------------------------

const uint8_t PROGMEM
  reds[]   = { 0x9A, 0x75, 0x00, 0x00, 0x00, 0x65, 0x84, 0x9A, 0xAD, 0xAD },
  greens[] = { 0x00, 0x00, 0x00, 0x87, 0xB1, 0x9E, 0x87, 0x66, 0x00, 0x00 },
  blues[]  = { 0x95, 0xD5, 0xFF, 0xC3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
  gamma8[] = { // Gamma correction improves the appearance of midrange colors
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03,
    0x03, 0x03, 0x04, 0x04, 0x04, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x06,
    0x06, 0x06, 0x06, 0x07, 0x07, 0x07, 0x08, 0x08, 0x08, 0x09, 0x09, 0x09,
    0x0A, 0x0A, 0x0A, 0x0B, 0x0B, 0x0B, 0x0C, 0x0C, 0x0D, 0x0D, 0x0D, 0x0E,
    0x0E, 0x0F, 0x0F, 0x10, 0x10, 0x11, 0x11, 0x12, 0x12, 0x13, 0x13, 0x14,
    0x14, 0x15, 0x15, 0x16, 0x16, 0x17, 0x18, 0x18, 0x19, 0x19, 0x1A, 0x1B,
    0x1B, 0x1C, 0x1D, 0x1D, 0x1E, 0x1F, 0x1F, 0x20, 0x21, 0x22, 0x22, 0x23,
    0x24, 0x25, 0x26, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2A, 0x2B, 0x2C, 0x2D,
    0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39,
    0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x44, 0x45, 0x46,
    0x47, 0x48, 0x49, 0x4B, 0x4C, 0x4D, 0x4E, 0x50, 0x51, 0x52, 0x54, 0x55,
    0x56, 0x58, 0x59, 0x5A, 0x5C, 0x5D, 0x5E, 0x60, 0x61, 0x63, 0x64, 0x66,
    0x67, 0x69, 0x6A, 0x6C, 0x6D, 0x6F, 0x70, 0x72, 0x73, 0x75, 0x77, 0x78,
    0x7A, 0x7C, 0x7D, 0x7F, 0x81, 0x82, 0x84, 0x86, 0x88, 0x89, 0x8B, 0x8D,
    0x8F, 0x91, 0x92, 0x94, 0x96, 0x98, 0x9A, 0x9C, 0x9E, 0xA0, 0xA2, 0xA4,
    0xA6, 0xA8, 0xAA, 0xAC, 0xAE, 0xB0, 0xB2, 0xB4, 0xB6, 0xB8, 0xBA, 0xBC,
    0xBF, 0xC1, 0xC3, 0xC5, 0xC7, 0xCA, 0xCC, 0xCE, 0xD1, 0xD3, 0xD5, 0xD7,
    0xDA, 0xDC, 0xDF, 0xE1, 0xE3, 0xE6, 0xE8, 0xEB, 0xED, 0xF0, 0xF2, 0xF5,
    0xF7, 0xFA, 0xFC, 0xFF };
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
void loop() {

  //Sound activated lights
  uint8_t  i, r, g, b;
    uint16_t minLvl, maxLvl, a, scaled;

    a           = CircuitPlayground.mic.peak(10); // 10 ms of audio
    sum        -= lvl[lvlIdx];
    lvl[lvlIdx] = a;
    sum        += a;                              // Sum of lvl[] array
    minLvl = maxLvl = lvl[0];                     // Calc min, max of lvl[]...
    for(i=1; i<FRAMES; i++) {
      if(lvl[i] < minLvl)      minLvl = lvl[i];
      else if(lvl[i] > maxLvl) maxLvl = lvl[i];
    }

    // Keep some minimum distance between min & max levels,
    // else the display gets "jumpy."
    if((maxLvl - minLvl) < 40) {
      maxLvl = (minLvl < (512-40)) ? minLvl + 40 : 512;
    }
    avgLo = (avgLo * 7 + minLvl + 2) / 8; // Dampen min/max levels
    avgHi = (maxLvl >= avgHi) ?           // (fake rolling averages)
      (avgHi *  3 + maxLvl + 1) /  4 :    // Fast rise
      (avgHi * 31 + maxLvl + 8) / 32;     // Slow decay

    a = sum / FRAMES; // Average of lvl[] array
    if(a <= avgLo) {  // Below min?
      scaled = 0;     // Bargraph = zero
    } else {          // Else scale to fixed-point coordspace 0-2560
      scaled = 2560L * (a - avgLo) / (avgHi - avgLo);
      if(scaled > 2560) scaled = 2560;
    }
    if(scaled >= peak) {            // New peak
      peakV = (scaled - peak) / 4;  // Give it an upward nudge
      peak  = scaled;
    }

    uint8_t  whole  = scaled / 256,    // Full-brightness pixels (0-10)
             frac   = scaled & 255;    // Brightness of fractional pixel
    int      whole2 = peak / 256,      // Index of peak pixel
             frac2  = peak & 255;      // Between-pixels position of peak
    uint16_t a1, a2;                   // Scaling factors for color blending

    for(i=0; i<10; i++) {              // For each NeoPixel...
      if(i <= whole) {                 // In currently-lit area?
        r = pgm_read_byte(&reds[i]),   // Look up pixel color
        g = pgm_read_byte(&greens[i]),
        b = pgm_read_byte(&blues[i]);
        if(i == whole) {               // Fraction pixel at top of range?
          a1 = (uint16_t)frac + 1;     // Fade toward black
          r  = (r * a1) >> 8;
          g  = (g * a1) >> 8;
          b  = (b * a1) >> 8;
        }
      } else {
        r = g = b = 0;                 // In unlit area
      }
      // Composite the peak pixel atop whatever else is happening...
      if(i == whole2) {                // Peak pixel?
        a1 = 256 - frac2;              // Existing pixel blend factor 1-256
        a2 = frac2 + 1;                // Peak pixel blend factor 1-256
        r  = ((r * a1) + (0x84 * a2)) >> 8; // Will
        g  = ((g * a1) + (0x87 * a2)) >> 8; // it
        b  = ((b * a1) + (0xC3 * a2)) >> 8; // blend?
      } else if(i == (whole2-1)) {     // Just below peak pixel
        a1 = frac2 + 1;                // Opposite blend ratios to above,
        a2 = 256 - frac2;              // but same idea
        r  = ((r * a1) + (0x84 * a2)) >> 8;
        g  = ((g * a1) + (0x87 * a2)) >> 8;
        b  = ((b * a1) + (0xC3 * a2)) >> 8;
      }
      CircuitPlayground.strip.setPixelColor(i,
        pgm_read_byte(&gamma8[r]),
        pgm_read_byte(&gamma8[g]),
        pgm_read_byte(&gamma8[b]));
    }
    CircuitPlayground.strip.show();

    peak += peakV;
    if(peak <= 0) {
      peak  = 0;
      peakV = 0;
    } else if(peakV >= -126) {
      peakV -= 2;
    }

    if(++lvlIdx >= FRAMES) lvlIdx = 0;

///////////////////////////////////////////////////////////////////////////////
//BUTTONS
//
//read the buttons
  leftButtonState =  (CircuitPlayground.leftButton());  
  //not pressed = 0, pressed = 1
  rightButtonState = (CircuitPlayground.rightButton());
  
//Left Button
//compare current button states to previous button states
  if(leftButtonState != leftButtonLastState){           //the state has changed
    if(leftButtonState == 1){                           //went from off to on, it's pressed
      usbMIDI.sendControlChange(LEFT_BUTTON_CC, 1, CHANNEL); //send MIDI note ON command
      CircuitPlayground.redLED(HIGH); //turn on the red LED
    }
    else{                   //the button went from on to off, it isn't pressed
      usbMIDI.sendControlChange(LEFT_BUTTON_CC, 0, CHANNEL);  //send MIDI note OFF 
      CircuitPlayground.redLED(LOW);                    //turn off the red LED
    }
    leftButtonLastState = leftButtonState;       //toggle
  }


//Right Button
  if(rightButtonState != rightButtonLastState){           
    if(rightButtonState == 1){                           
      usbMIDI.sendControlChange(RIGHT_BUTTON_CC, 1, CHANNEL); 
      CircuitPlayground.redLED(HIGH); 
    }
    else{                                              
      usbMIDI.sendControlChange(RIGHT_BUTTON_CC, 0, CHANNEL);  
      CircuitPlayground.redLED(LOW);                    
    }
    rightButtonLastState = rightButtonState;              
  }
///////////////////////////////////////////////////////////////////////////////
//Cap sense pads
//
//read the capacative pads
  int cap1  = CircuitPlayground.readCap(1);
  int cap0  = CircuitPlayground.readCap(0);
  int cap2  = CircuitPlayground.readCap(2);
  int cap3  = CircuitPlayground.readCap(3);
  int cap12 = CircuitPlayground.readCap(12);
  int cap6  = CircuitPlayground.readCap(6);
  int cap9  = CircuitPlayground.readCap(9);
  int cap10 = CircuitPlayground.readCap(10);



  //cap1 Crossfader Deck B
  
  if(cap1 > CAPMIN){
       cap1State=1;
    }
    else{
       cap1State=0;
    }
    if(cap1State != cap1LastState){
      if(cap1State==1){
        usbMIDI.sendControlChange(CAP1_CONTROL, 127, CHANNEL);
        CircuitPlayground.redLED(HIGH); 
      }
      else {
        usbMIDI.sendControlChange(CAP1_CONTROL, 0, CHANNEL);
        CircuitPlayground.redLED(LOW);                    
      }
      cap1LastState = cap1State;
    }
    
  //cap0 
    if(cap0 > CAPMIN){
       cap0State=1;
    }
    else{
       cap0State=0;
    }
    if(cap0State != cap0LastState){
      if(cap0State==1){
        usbMIDI.sendControlChange(CAP0_CONTROL, 1, CHANNEL);
        CircuitPlayground.redLED(HIGH); 
      }
      else {
        usbMIDI.sendControlChange(CAP0_CONTROL, 0, CHANNEL);
        CircuitPlayground.redLED(LOW);                    
      }
      cap0LastState = cap0State;
    }

//cap2
      if(cap2 > CAPMIN){
         cap2State=1;
      }
      else{
         cap2State=0;
      }
      if(cap2State != cap2LastState){
        if(cap2State==1){
          usbMIDI.sendControlChange(CAP2_CONTROL, 1, CHANNEL);
          CircuitPlayground.redLED(HIGH); 
        }
        else {
          usbMIDI.sendControlChange(CAP2_CONTROL, 0, CHANNEL);
          CircuitPlayground.redLED(LOW);                    
        }
      cap2LastState = cap2State;
      }
   
//cap3
      if(cap3 > CAPMIN){
         cap3State=1;
      }
      else{
         cap3State=0;
      }
      if(cap3State != cap3LastState){
        if(cap3State==1){
          usbMIDI.sendControlChange(CAP3_CONTROL, 1, CHANNEL);
          CircuitPlayground.redLED(HIGH); 
        }
        else {
          usbMIDI.sendControlChange(CAP3_CONTROL, 0, CHANNEL);
          CircuitPlayground.redLED(LOW);                    
        }
      cap3LastState = cap3State;
      }
    
//cap12 Crossfader Deck B

  if(cap12 > CAPMIN){
       cap12State=1;
    }
    else{
       cap12State=0;
    }
    if(cap12State != cap12LastState){
      if(cap12State==1){
        usbMIDI.sendControlChange(CAP12_CONTROL, 127, CHANNEL);
        CircuitPlayground.redLED(HIGH); 
      }
      else {
        usbMIDI.sendControlChange(CAP12_CONTROL, 0, CHANNEL);
        CircuitPlayground.redLED(LOW);                    
      }
      cap12LastState = cap12State;
    }
    
//cap6
  if (cap6>CAPMIN){
      int cap6NewVal = map(CircuitPlayground.readCap(6),0,200,0,127);
      if (abs(cap6 - cap6NewVal>CAPSLOP)) {
          cap6 = cap6NewVal;
          usbMIDI.sendControlChange(CAP6_CONTROL, cap6, CHANNEL);
          CircuitPlayground.redLED(HIGH); 
          cap6ON = true;
      }
      else{
        if (cap6ON==true){
           usbMIDI.sendControlChange(CAP6_CONTROL, 0, CHANNEL); //send a 0
          CircuitPlayground.redLED(LOW); 
           cap6ON=false;
        }
      }
    }
//cap9
      if(cap9 > CAPMIN){
         cap9State=1;
      }
      else{
         cap9State=0;
      }
      if(cap9State != cap9LastState){
        if(cap9State==1){
          usbMIDI.sendControlChange(CAP9_CONTROL, 1, CHANNEL);
          CircuitPlayground.redLED(HIGH); 
        }
        else {
          usbMIDI.sendControlChange(CAP9_CONTROL, 0, CHANNEL);
          CircuitPlayground.redLED(LOW);                    
        }
      cap9LastState = cap9State;
      }
    
//cap10
      if(cap10 > CAPMIN){
         cap10State=1;
      }
      else{
         cap10State=0;
      }
      if(cap10State != cap10LastState){
        if(cap10State==1){
          usbMIDI.sendControlChange(CAP10_CONTROL, 1, CHANNEL);
          CircuitPlayground.redLED(HIGH); 
        }
        else {
          usbMIDI.sendControlChange(CAP10_CONTROL, 0, CHANNEL);
          CircuitPlayground.redLED(LOW);                    
        }
      cap10LastState = cap10State;
      }
    

  // MIDI Controllers should discard incoming MIDI messages.
    while (usbMIDI.read()) {
  }
  
  ```
