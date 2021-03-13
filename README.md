# L298PMotorShield
An Arduino library for the L298P Motor Shield

The L298P motor shield drives up to two DC Motors, controls one servo motor, connects to HC-06 Bluetooth modules, implemenets an Ultrasonic Rangefinder, and has an Analog/Digital Sensor interface.

|         | Speed Pins | Speed Control | Direction Pins | Direction Control              |
|---------|------------|---------------|----------------|--------------------------------|
| Motor A | D10        | PWM 0-100     | D12            | HIGH = Forward / LOW = Reverse |
| Motor B | D11        | PWM 0-100     | D13            | HIGH = Forward / LOW = Reverse |


**Shield Functions and Pin Numbers**
| Function                  | Pin Number(s)          | Notes                                                                                                                   |
|---------------------------|------------------------|-------------------------------------------------------------------------------------------------------------------------|
| Servo Motor               | D9                     | Available when DC Motors not in use 'Servo' Header (White): '9' Header (D9=PWM), '+5V' Header (5V), 'G' Header (Ground) |
| Ultrasonic Sensor         | D7, D8                 | 'Ping' 1x4 Header (Yellow): 'T' Header (D7=Trigger), 'R' Header (D8=Return), '+' Header (5V), 'G' Header (Ground)       |
| Bluetooth                 | D0,D1                  | 'BT2' 1x4 Female Header (Black): 'R' Header (RX=D0), 'T' Header (D1), '+' Header (3.3V), '-' Header (Ground             |
| Buzzer                    | D4                     | Active HIGH                                                                                                             |
| RGB LED  or Other PWM out | D3, D5, D6             | Red (D3), Green (D5), Blue (D6), Unmarked Header (5V), '-' Header (Ground)                                              |
| Digital Sensor            | D2                     | 'Pin 2 I/O' Header (Blue): 'S' Header (Digital I/O), 'G' Header (Ground), '+' Header (5V)                               |
| Analog Sensors            | A0, A1, A2, A3, A4, A5 | 'Analog In' 3x6 Header (White/Red/Black): White headers (Signal), Red headers (5V), Black headers (Ground)              |

buzz() function wraps the Arduino "Tone" Library for ease of use on the shield, with pin default pin pre-assigned.
