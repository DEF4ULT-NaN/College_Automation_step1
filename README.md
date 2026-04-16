# College Bell System

An Arduino-based automatic college bell system using an RTC module and LCD display to ring a buzzer at scheduled class times throughout the day.

## Hardware Requirements

- Arduino Uno (or compatible board)
- DS1307 RTC Module
- 16x2 I2C LCD Display
- Active buzzer
- Jumper wires
- USB cable for programming

## Circuit Diagram

```
Arduino Uno        DS1307 RTC        16x2 LCD (I2C)       Buzzer
──────────        ──────────        ──────────────       ──────
  A4  ────────────── SDA  ──────────── SDA                 │
  A5  ────────────── SCL  ──────────── SCL                 │
  5V  ────────────── VCC              VCC                  │
  GND ────────────── GND              GND                   │
                                               2 ─────────┤(+) │
  GND ────────────────────────────────────────────────┤COM │
```

### Pin Configuration

| Component      | Pin      | Notes                            |
|----------------|----------|----------------------------------|
| RTC (SDA)      | A4       | I2C data line                   |
| RTC (SCL)      | A5       | I2C clock line                  |
| LCD (I2C)      | A4/A5    | Shares I2C bus with RTC         |
| Buzzer         | Pin 2    | Active buzzer, positive terminal |
| VCC            | 5V       | Power for RTC and LCD           |
| GND            | GND      | Common ground                    |

## Software Requirements

### Arduino Libraries

Install the following libraries via Arduino IDE Library Manager:

| Library                | Version  | Author                | Install Command                  |
|------------------------|----------|-----------------------|----------------------------------|
| LiquidCrystal I2C      | 1.1.2    | Frank de Brabander    | Library Manager → "LiquidCrystal I2C" |
| RTClib                 | 2.1.4    | Adafruit              | Library Manager → "RTClib"       |
| Adafruit BusIO         | 1.17.4   | Adafruit              | (Auto-installed with RTClib)     |

### Board Support

- **Board:** Arduino Uno (or AVR-based board)
- **Programmer:** AVRISP mkII (or default USB)
- **Port:** Select your Arduino's COM port

## Installation

### 1. Install Libraries

**Via Arduino IDE:**
1. Open **Sketch → Include Library → Manage Libraries**
2. Search for and install:
   - `LiquidCrystal I2C` by Frank de Brabander
   - `RTClib` by Adafruit

**Via arduino-cli:**
```bash
arduino-cli lib install "LiquidCrystal I2C"
arduino-cli lib install "RTClib"
```

### 2. Configure the Sketch

1. Open `COLLEGE_BELL.ino` in the Arduino IDE
2. Set your desired class schedule times in the `loop()` function
3. Update the default time in `RTC.adjust()` if needed

### 3. Upload to Arduino

1. Connect your Arduino board via USB
2. Select **Tools → Board → Arduino Uno**
3. Select the correct **Port**
4. Click **Upload** (Ctrl+U)

## Class Schedule

The current schedule rings the buzzer at these times:

| Time      | Event         | Duration |
|-----------|---------------|----------|
| 09:30:00  | Class 1 Starts| 3 sec   |
| 10:20:00  | Class 2 Ends  | 3 sec   |
| 11:10:00  | Class 3 Ends  | 3 sec   |
| 12:00:00  | Lunch Break   | 3 sec   |
| 12:50:00  | Class 4 Starts| 3 sec   |
| 13:40:00  | Class 5 Ends  | 3 sec   |
| 14:20:00  | Class 6 Ends  | 3 sec   |
| 15:00:00  | Class 7 Starts| 3 sec   |
| 15:40:00  | Day Ends      | 3 sec   |

## Customizing the Schedule

Edit the times in `COLLEGE_BELL.ino`:

```cpp
if (now.hour() == HH && now.minute() == MM && now.second() == 0) {
  digitalWrite(buzzer, LOW);
  delay(3000);  // Buzzer duration (3 seconds)
  digitalWrite(buzzer, HIGH);
  Serial.println("Message");
}
```

- Replace `HH` and `MM` with your desired hour (0–23) and minute (0–59)
- Adjust `delay(3000)` to change buzzer duration (in milliseconds)
- Update `Serial.println()` message as needed

## LCD I2C Address

The default I2C address is `0x3F`. If your LCD doesn't display anything:

1. Run an I2C scanner sketch to find your LCD's address
2. Update the address in the sketch:
   ```cpp
   LiquidCrystal_I2C lcd(0x3F, 16, 2);  // Change 0x3F to your address
   ```

Common addresses: `0x27`, `0x3F`

## Troubleshooting

| Issue                       | Solution                                           |
|-----------------------------|----------------------------------------------------|
| LCD shows nothing           | Check I2C address, try `0x27` instead of `0x3F`    |
| RTC loses time              | Ensure RTC module has a coin cell battery         |
| Buzzer doesn't ring         | Verify pin 2 connection, check polarity           |
| "Libraries not found" error| Reinstall LiquidCrystal I2C and RTClib             |

## Serial Monitor Output

The sketch outputs date, time, and bell events to Serial Monitor at 9600 baud. Open **Tools → Serial Monitor** to view.

## License

MIT License