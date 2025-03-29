This project was designed for the Arduino Nano Every using MegaCoreX (https://github.com/MCUdude/MegaCoreX)
The selected board is MegaCoreX->ATMega4809 and the selected programmer is JTAG2UPDI.

The serial settings are as follows:
Speed: 9600 baud
Data bits: 8
Stop bits: 1
Parity: None
Flow control XON/XOFF

The outputs are controlled by sending a single ASCII character to turn on or off a light on the christmas tree.
An uppercase letter turns on a light, a lowercase letter turns off a light.
A (a): Tower Ready
B (b): Left Pre-Stage
C (c): Left Stage
D (d): Left 1st Amber
E (e): Left 2nd Amber
F (f): Left 3rd Amber
G (g): Left Green
H (h): Left Red
I (i): Right Pre-Stage
J (j): Right Stage
K (k): Right 1st Amber
L (l): Right 2nd Amber
M (m): Right 3rd Amber
N (n): Right Green
O (o): Right Red

Brightness is configurable by sending the message #BRIGHT[0-255] with 0-255 being the PWM duty cycle. 0 is off and 255 is maximum brightness.
Examples:
#BRIGHT1 -- Lowest visible brightness 
#BRIGHT127 -- Medium brightness
