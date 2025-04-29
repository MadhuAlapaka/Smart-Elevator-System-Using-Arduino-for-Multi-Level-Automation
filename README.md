![image](https://github.com/user-attachments/assets/8e2af9fc-2b1e-494f-a160-628e6dcdb761)# 🚀 Elevator System Using Arduino

This is a prototype model of a **multi-level elevator system** developed using the **Arduino platform**. It is designed to demonstrate core automation concepts, including real-time embedded control, electromechanical integration, and sensor-driven logic for floor navigation. This project is ideal for engineering students and hobbyists looking to learn automation systems using open-source hardware.

---

## 📘 Project Summary

The goal of this project is to **build and simulate a real-world elevator** mechanism that operates using programmable logic through **Arduino Mega and UNO** boards. It allows users to press buttons corresponding to different floors, and the elevator moves the cab to the selected level using a **stepper motor system**.

The elevator recognizes input signals, calculates motion direction, and drives a motor to simulate floor-to-floor movement. The system also includes **reed sensors**, **LED displays**, and **7-segment indicators** for user feedback.

---

## 👨‍💻 Team Members

- **Madhu Alapaka** (21MIS7022)  
- R. Rasagna (21MIC7025)  
- S. Amrutha (21MIC7048)  
- K.L. Bharadwaj (21MIC7050)  
- T. Sree (21MIC7058)  
- P. Nikilesh (21MIS7087)  

**Project Guide:** Prof. Ganesh Lakshmana Kumar Moganti  
**Institution:** VIT-AP University  
**Date:** November 30, 2022

---

## 🎯 Objectives

- Simulate elevator movement between multiple floors using stepper motors.
- Optimize control logic using Arduino programming.
- Enhance understanding of automation and embedded system principles.
- Implement real-world systems in a classroom/laboratory environment.
- Ensure safe, power-efficient and reliable cab operation.

---

## 🛠️ Key Features

- 🔘 Floor buttons simulate call system (Red = Down, Green = Up)
- 🔄 Stepper motor-driven cab movement via pulley system
- 📟 LED matrix and 7-segment display for user feedback
- 📍 Reed switches detect cab position and stop at floors
- ⚙️ Prototyping shield for durable wiring and component mounting
- 🔧 Screw terminals for modular connections

---

## 🧰 Hardware Components

| Component                | Quantity | Description                                       |
|-------------------------|----------|---------------------------------------------------|
| Arduino Mega            | 1        | Main controller board                             |
| Arduino Uno             | 1        | Secondary control (optional for expansion)        |
| Stepper Motor           | 1        | Drives cab movement via pulley                    |
| ULN2003 Motor Driver    | 1        | Interface between Arduino and stepper             |
| Reed Switch Modules     | 3        | Position sensors at each floor                    |
| Push Buttons            | 6+       | Floor selection (Call and Inside controls)        |
| LED Matrix & 7-Segment  | 1 each   | Visual floor indicators                           |
| Fiberboard (shaft)      | Custom   | Elevator frame and cab                            |
| Prototyping Shield      | 1        | Soldering and wiring reliability                  |
| Wires, Connectors, Screws| -        | Basic hardware components                         |

---

## 🏗️ System Construction

1. **Frame**: Built using fiberboard cut to 36" to form the elevator shaft.
2. **Elevator Cab**: Positioned in the shaft and connected to the motor via spool and belt.
3. **Motor Mounting**: Motor is fixed to the top using aluminum brackets.
4. **Button Panels**: Two sets — external call panel and internal car panel.
5. **Electrical Layout**: Used prototyping shield and screw terminals for safe, modular wiring.
6. **Indicators**: 7-segment display and LED matrix show the current floor level.
7. **Sensor Integration**: Reed switches detect cab position to trigger stops.
8. **Software Logic**: Written in Arduino IDE using C/C++, handles:
   - Directional control
   - Speed calculation
   - Interrupt-driven stopping
   - Button debounce logic

---

## 💡 Working Principle

- User presses a button (internal or external).
- The system identifies direction (up or down).
- Arduino activates the stepper motor to rotate spool.
- The cab moves and reed switch stops it at the correct floor.
- LED/7-Segment displays update the floor number.

---

## 🧪 Results

- Successfully demonstrated movement between 3 floors.
- Accurate stopping at requested floor using reed sensors.
- Safe and smooth motor control logic with no overshoot.
- Effective simulation of real-life elevator systems.
- Identified as useful for:
  - Hospitals & clinics
  - Small residential buildings
  - Educational and training models

---

## 🔮 Future Enhancements

- Add touch-screen display or voice interface.
- Expand to more floors using advanced scheduling logic.
- Integrate IoT (e.g., Blynk, MQTT) for wireless control.
- Enhance power optimization using sleep modes and solar panels.
- Implement safety mechanisms (e.g., door sensors, load detection).

---

## 🔧 Circuit Diagram
![image](https://github.com/user-attachments/assets/239cdf65-5271-45e2-8bbb-92ce124d9cdb)

![Elevator Circuit Diagram](images/circuit_diagram.png)

---

## 📂 Repository Structure

Elevator-Arduino-Project/
├── code/
│   └── elevator_code.ino
├── images/
│   ├── circuit_diagram.png
│   ├── elevator_front_view.jpg
│   └── elevator_internal_view.jpg
├── docs/
│   └── FINAL_REPORT.pdf
├── README.md

code/: Contains your Arduino sketch (elevator_code.ino).

images/: Stores visual assets like circuit diagrams and photographs of your elevator model.

docs/: Includes detailed documentation, such as your final project report.

README.md: The main documentation file that provides an overview and instructions.
---

## 🧾 References

- [Mini Elevator Arduino Project – Electrosal](https://www.electrosal.com/product/mini-elevator-using-arduino/)
- [Project Image Reference](https://images.app.goo.gl/rzdaJcT17jCLD7247)

---
📄 Final Report
Include your comprehensive project report in the docs/ folder. Ensure it's named appropriately, such as FINAL_REPORT.pdf, and provides in-depth details about your project's objectives, methodology, results, and conclusions.

## 🧠 Sample Code Snippet

```cpp
int pushButtons[] = {6, 7, 8, 9, 10, 11};
int directions[] = {CCW, CW, CCW, CW, CCW, CW};

void loop() {
  for (byte i = 0; i < sizeof(pushButtons) / sizeof(pushButtons[0]); i++) {
    if (digitalRead(pushButtons[i]) == LOW) {
      goToAngle = angles[i];
      dirStatus = directions[i];
      count = 0;
      activeButton = i;
    }
  }

  if (dirStatus == CCW || dirStatus == CW) {
    driveStepper(poleStep);
  } else {
    stopMotor();
  }
}

📜 License
This project is shared for educational purposes. Feel free to fork, learn, modify, and build on it. Contributions and feedback are welcome!
🙏 Acknowledgements
We thank our guide Prof. Ganesh Lakshmana Kumar Moganti for his support and VIT-AP University for providing resources to make this project possible.



