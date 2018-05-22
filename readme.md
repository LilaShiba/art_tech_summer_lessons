# Art & Tech
The unconventional mixing and matching of subject areas

[itp](https://tisch.nyu.edu/itp)
[media lab](https://www.media.mit.edu/)
[eyebeam](https://www.eyebeam.org/)

## Analog & Digital
[resource](https://learn.sparkfun.com/tutorials/analog-vs-digital)

What? It's like two different languages in the electronic world and the languages are called signals?

Signals are passed between devices in order to send and receive information

### analog

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

### digital
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

## Long Story Short
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
