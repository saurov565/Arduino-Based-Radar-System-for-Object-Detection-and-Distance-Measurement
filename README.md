## Arduino-Based Radar System for Object Detection and Distance Measurement

This project demonstrates the development of an **Arduino-based radar system** for **short-range object detection** and **distance measurement**. The system integrates an **HC-SR04 ultrasonic sensor**, **servo motor**, and an **Arduino Uno** to detect objects within a **180° field of view**. Real-time data such as **distance** and **angle** of detected objects are visualized using the **Processing IDE**.

### Key Features:

* **Low-Cost and Portable**: The system uses affordable components like the Arduino Uno and ultrasonic sensor, making it ideal for educational projects and small-scale industrial applications.
* **High Accuracy**: Measures distances from 2 cm to 400 cm, with an accuracy of ±1 cm within 200 cm and ±3 cm at 400 cm.
* **Real-Time Visualization**: The radar's sweep and detected objects are displayed graphically via Processing IDE, providing a clear, interactive interface.
* **Wide Application Range**: Suitable for applications in **aviation**, **maritime navigation**, **meteorology**, and **education** (e.g., teaching radar technology and microcontroller programming).

### How It Works:

* The **ultrasonic sensor** emits sound waves and measures the time taken for the echo to return, calculating the distance to objects.
* The **servo motor** rotates the sensor 180° to scan the environment.
* Data is processed by the **Arduino Uno**, and the results are displayed on a **polar coordinate radar screen** through **Processing IDE**.

### Limitations:

* **Performance degradation** beyond 300 cm due to ultrasonic signal attenuation.
* **Slow update rate** (2 scans per second) due to the servo motor's movement.
* **Blind spot** directly behind the sensor.

### Future Enhancements:

* Integrating multiple sensors for extended range.
* Improving resolution using higher-frequency components.
* Expanding its use in **autonomous vehicles** and **smart home systems**.


