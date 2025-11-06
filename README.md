# Li-Fi Data Transmission using Arduino

Proof-of-concept optical link: ARD1 transmits data, ARD2 receives it.
We validate the logic in **Tinkercad (wired TX→RX)** and then build the **hardware optical link** with LED + LDR/photodiode.

## Repo structure

## Quick start (Tinkercad)
1) Wire ARD1 **TX (D1) → ARD2 RX (D0)** and **GND↔GND**.  
2) Upload `/src/ARD1_Transmitter/ARD1_Transmitter.ino` to ARD1.  
3) Upload `/src/ARD2_Receiver/ARD2_Receiver.ino` to ARD2.  
4) Open both Serial Monitors at **9600 baud**. Type in ARD1 → text appears on ARD2.

## Hardware optical build (summary)
- **TX:** D8 → 1kΩ → NPN base; LED anode → +5V; LED cathode → 220Ω → collector; emitter → GND.  
- **RX:** +5V → LDR → **A0** → 10kΩ → GND.  
- Use `/src/Receiver_Optical/Receiver_Optical.ino` (threshold + hysteresis).

## 🖼️ Circuit Diagrams & Simulation

### 1️⃣ Tinkercad 3D Breadboard View  
This shows the real connection between ARD1 (Transmitter) and ARD2 (Receiver).

![Tinkercad Breadboard](docs/tinker.png)

---

### 2️⃣ Circuit Schematic  
Generated from Tinkercad — clearly shows wiring and components.

![Schematic](docs/Schematic.png)

---

### 3️⃣ Block Diagram / System Overview  
High-level representation of binary data flow from PC → Transmitter → Light → Receiver → PC.

![System Diagram](docs/System Diagram.png)

## License
MIT.
