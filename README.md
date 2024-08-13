# Project A.L.I.E.N. Shift Register Test Code

<!-- Harry Boyd - 31/07/2024 - github.com/hboyd255 -->

This repository contains code that allows me to test the shift register for both
the NES controller and the bumpers on the Project A.L.I.E.N. robot.

Both shift registers are 4021 shift registers, which are 8-bit
parallel-in/serial-out.

## Breadboard Layout

This is the way that I set the hardware up on a breadboard.

Top: ![Breadboard from above](/photos/BreadboardTop.jpg)

Side: ![Breadboard from the side](/photos/BreadboardSide.jpg)

## Notes

### For the bumper button shift register

The state of the 8 buttons around the robot are read in as a byte. The lsb is
the value of the front button, then the ascending bits represent the subsequent
buttons rotating clockwise.

## Pull up vs pull down resistors

The NES controller uses pull up resistors, while the bumper buttons use pull
down resistors.

This means that for the nes controller, a 1 represents a button not being
pressed and a 0 represents a button being pressed. For the bumper buttons, a 0
represents a button not being pressed and a 1 represents a button being pressed.

I don't fully remember why I designed the bumpers using pull down resistors,
pull up resistors would have been easier to implement. Maybe I was thinking that
0 representing not pressed would be more intuitive. Or maybe I had an excess of
red wire to make a 5V rail.

This difference in pull up vs pull down resistors isn't a problem, but is
something that must be accounted for in the code.
