# RP2040/Pico Hiwonder library

Library to connect one or multiple Hiwonder servos to a Raspberry Pi Pico (RP2040).

Connect RX and TX together and connect the serial pin of the servo to that pair.

Library copied from [madhephaestus/lx16a-servo](https://github.com/madhephaestus/lx16a-servo).

No need for a 74HC126 buffer chip, as that did not seem to work.

Tested with LX225 & HTD-45H servos.


## Pinout:
![pinout servo connector](https://github.com/Hephaestus-Arm/HephaestusArm2/raw/0.1.1/photos/motor_cable.jpg)