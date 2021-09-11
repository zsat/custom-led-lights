# Custom LED Lights Using Arduino

---

## Hardware

Using an Arduino Nano, I'm able to upload code and control an addressable LED light strip to do whatever I can imagine. I upload code from the Arduino IDE to the Arduino Nano, which will normally get power from the external power supply that is routed to the breadboard. The strip of addressable LED lights has a data line in addition to its power lines, which is how the strip of lights knows what to do. The schematic below points out these points of interest.

(room for schematic)

(list of items used, maybe with pictures or just include final product picture)

All put together, we get a system something like this. When running on the external power supply, there won't be a need for the Mini-USB port that we use to upload code from our computer.

---

## Software

---

The actual programming of the LED lights takes place in the form of C++ code in the Arduino IDE. Arduino programs use two foundational functions, `setup()` and `loop()`, which do as they say. `setup()` runs once, allowing us to set up any variables we need during the actual program's execution. `loop()` runs infinitely (unless programmed to quit), which is what allows us to produce patterns on our LED lights over time.

> What are some things we can do with this on our lights with this structure?
> > test

Here's a list of programs (or sketches) that this repo has:
-one
-two

