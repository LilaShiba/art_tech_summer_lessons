# Light the Way

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

# Now you try!


# Loops

```c
      // for every neopixel
  for (int pixel = 0; pixel < 11; pixel+=2){
      // make it this color
    CircuitPlayground.setPixelColor(pixel,0,255,0);
    delay(100);
  }

```

# Complie & Upload your Code

![code](https://kyle1james.gitbooks.io/sub-day/content/assets/Screen%20Shot%202017-05-09%20at%207.39.34%20PM.png)


# Then

![code2](https://kyle1james.gitbooks.io/sub-day/content/assets/Screen%20Shot%202017-05-09%20at%207.40.29%20PM.png)

# Now we verify the code, which will output any errors in the terminal. The check mark
Then upload. The arrow

![code3](https://kyle1james.gitbooks.io/sub-day/content/assets/Screen%20Shot%202017-05-09%20at%207.42.36%20PM.png)

# Even More Examples
[examples](https://github.com/kyle1james/examples)

# reverse loop
```c
  for (int pixel = 10; pixel > -1; pixel-=2){
    CircuitPlayground.setPixelColor(pixel,0,0,255);
    delay(50);
  }

```
