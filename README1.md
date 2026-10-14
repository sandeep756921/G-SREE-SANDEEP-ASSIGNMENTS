# Two-Digit Counter (0 to 30) Using Arduino Uno and CD4511

## Project Overview

This project implements a two-digit digital counter using an Arduino Uno, two CD4511 BCD-to-7-segment decoder ICs, and two common-cathode 7-segment displays.

The counter displays numbers from **00 to 30**, increasing by one every second. After displaying 30, it automatically resets to 00 and starts counting again.

The project is designed and simulated using **Tinkercad Circuits**.

## Components Required

| Quantity | Component |
|---|---|
| 1 | Arduino Uno R3 |
| 2 | BCD-to-7-segment decoder IC (CD4511) |
| 2 | Common-cathode 7-segment displays |
| 2 | 220 Ω resistors for the basic common-cathode arrangement |
| 1 | Breadboard |
| As required | Jumper wires |

**Note:** For real hardware, individual current-limiting resistors on all seven segments of each display are recommended for better current control and uniform brightness.

## Pin Connections

### 1. Power and Control Connections

Connect the following pins on both CD4511 decoder ICs.

| CD4511 Pin | Name | Connection |
|---|---|---|
| 16 | VDD | 5V |
| 8 | VSS | GND |
| 3 | LT | 5V |
| 4 | BI | 5V |
| 5 | LE | GND |

### 2. Arduino to Units Decoder

| Arduino Pin | CD4511 Pin | BCD Input |
|---|---|---|
| D2 | 7 | A (LSB) |
| D3 | 1 | B |
| D4 | 2 | C |
| D5 | 6 | D (MSB) |

### 3. Arduino to Tens Decoder

| Arduino Pin | CD4511 Pin | BCD Input |
|---|---|---|
| D6 | 7 | A (LSB) |
| D7 | 1 | B |
| GND | 2 | C |
| GND | 6 | D |

The tens digit ranges from 0 to 3, so only two BCD input bits are required.

### 4. Decoder Outputs to Display Segments

Connect the following outputs to the corresponding segments of each display.

| CD4511 Pin | Display Segment |
|---|---|
| 13 | a |
| 12 | b |
| 11 | c |
| 10 | d |
| 9 | e |
| 15 | f |
| 14 | g |

Repeat these connections for both displays.

### 5. Common-Cathode Connections

Connect each display's common-cathode pin to GND through the appropriate current-limiting resistor arrangement. Check the display pinout before wiring.

## Circuit Setup

The circuit consists of an Arduino Uno connected to two CD4511 decoders and two common-cathode 7-segment displays.

Add a screenshot of your Tinkercad circuit to the `images` folder and name it `circuit_setup.png`.

![Circuit Setup](images/circuit_setup.png)


## How the Project Works

### 1. Counting Sequence

The Arduino generates numbers from 0 to 30. Each number remains displayed for one second.

### 2. Splitting the Number

The `showNumber()` function separates the number into tens and units.

For example, for the number 27:

- Tens digit = 27 / 10 = 2
- Units digit = 27 % 10 = 7

### 3. BCD Conversion

The Arduino sends each digit to its CD4511 decoder in binary-coded decimal (BCD) format.

| Decimal Digit | BCD (D C B A) |
|---|---|
| 0 | 0000 |
| 2 | 0010 |
| 7 | 0111 |
| 9 | 1001 |

The CD4511 converts the BCD input into the appropriate signals for the seven display segments.

### 4. Automatic Reset

When the counter reaches 30, the `for` loop finishes. The Arduino repeats the `loop()` function and starts counting again from 00.

## Example Output

```text
00
01
02
03
04
...
09
10
11
12
...
20
21
...
29
30
00
01
...
```

Each number is displayed for approximately one second.

