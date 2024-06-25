## Capstone Project: Elevation Tracking for Wearable Devices Using Machine Learning

### Problem Definition

Location tracking is vital in modern society and is used for everything from finding lost keys to successfully navigating urban landscapes. When using the Global Positioning System (GPS), location is accurate in the x and y directions. Where GPS falls short is in the z-direction. It is vital to address these inaccuracies in z-axis measurements for elevation statistics, such as floors climbed, in both emergency response as well as commercial use cases. 

Current wearable devices rely on pressure to determine elevation. Still, this variable alone fails to account for cases where the temperature is not constant, such as in an emergency scenario in a burning building, where accurate location tracking within a building can be the difference between life and death.

By using advancements in machine learning, accurate elevation tracking can be achieved with a multivariate model for both commercial and emergency response scenarios. This model should be able to correct for over-reliance on pressure as a metric for elevation tracking. This device will use pressure, temperature, rotation, and acceleration sensors to improve current elevation classification techniques.

### Methodology

This project implements a wearable device to accurately classify z-axis location. To accomplish this task, there are four subsystems, as detailed in Figure 1. This device runs a local machine-learning model to make predictions in real time. The device will be secured on the bicep and accompanied by a chest strap heart rate sensor. 

The first subsystem, the Hardware and Power Supply Subsystem, aims to integrate all sensors and the microcontroller within the hardware encasing. This subsystem also ensures that the proper power is supplied to all components of the system. The next subsystem, the Microcontroller and Database Subsystem, is responsible for data collection and data transmission using the microcontroller. All sensor data is collected and sent to the database so that this information can be accessed by the Machine Learning and Android Application Subsystems. The Machine Learning Subsystem uses the sensor data to train the machine learning model and classify elevation change locally. Lastly, the Android Application Subsystem hosts the data insights for user interaction and data visualization.

### Purpose

This Github contains the code necessary to satisfy the Microcontroller and Database, Machine Learning, and Android Application subsystems.


![Overall Subsystem Design](https://i.imgur.com/I2093Ua.png)

### System Accomplishments
- The ESP-32 Communications successfully utilize the following: I2C, Wi-Fi, Bluetooth, and HTTP operations
- The Machine Learning model runs in real-time on the ESP-32, it can distinguish between stair ascent/descent and elevator ascent/descent

We are gonna need seth to help at some point

### Team Members and Code Contributions
**Emiliano Sanchez - Hardware and Power Lead**  
**Anna Theodore - Microcontroller and Database Lead**
Anna contributed ESP-32 Communications code using C, ensuring consistent and synchronized data outputs as well as 
Anna implemented error catching for the disconnection of wired sensors and Bluetooth disconnection
Anna wrote pSQL query code for database posting using Python’s Flask library
**Salim Al Kharsa - Machine Learning Lead**  
Salim contributed the ESP-32 Machine Learning integration code, including a C wrapper for the model deployed in C++
Salim included data validation attributes within the machine learning integration, implementing a buffered sliding window to prevent inaccurate successive recordings. 
Salim handled the Wi-Fi reconnection protocol implementing a linear back-off algorithm to minimize local resource consumption
**Seth Keylon - Android Application Lead**

### Contact Information
For questions or further information, please contact:

- **Anna Theodore**  
  - Email: annattheodore@gmail.com  
  - LinkedIn: [Anna Theodore](https://www.linkedin.com/in/anna-theodore-2024/)
- **Anna Theodore**  
  - Email: annattheodore@gmail.com  
  - LinkedIn: [Anna Theodore](https://www.linkedin.com/in/anna-theodore-2024/)

---

Thank you for reading about our capstone project. We are excited to share our work with the community!


Should we remove below →
## Test Documentation

| Test Number | Test Name                               | Test Description                                                         | Test Method                                                                              | Expected Behavior                                                                        | Passed (y/n/tbd) | Notes                                                                                           |
| ----------- | --------------------------------------- | ------------------------------------------------------------------------ | ---------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------- | ---------------- | ----------------------------------------------------------------------------------------------- |
| 1           | Normal BMP280 Function                  | Ensures pressure and temperature data is correct                         | Run the program and observe printed numbers                                              | Prints realistic numbers                                                                 | Y                | Sensor connects and disconnects due to poor soldering                                           |
| 2           | Detached BMP 280 Function               | Ensures the pressure sensor still functions after it disconnects         | Run the program and observe printed numbers, then take out the sensor and put it back in | Functions like Test 1                                                                    | Y                | After reconnection, the sensor reads bad pressure values suspected to be due to a faulty sensor |
| 3           | Normal MPU6050                          | Ensures the gyro and acc. data is correct                                | Run the program and observe printed numbers                                              | Prints realistic numbers                                                                 | Y                | /                                                                                               |
| 4           | Detached MPU 6050 Function              | Ensures the gyro and acc data still functions after it disconnects       | Run the program and observe printed numbers, then take out the sensor and put it back in | Functions like Test 4                                                                    | Y                | /                                                                                               |
| 5           | Wi-Fi Initialization                    | The Wi-Fi can successfully run the code                                  | Run the program and see the print statement                                              | Prints "wifi initialized"                                                                | TBD              | Not fully tested on a second Wi-Fi                                                              |
| 6           | Post Requests Send                      | The data sends to the server                                             | Check the server webpage and see if the data shows there                                 | Data shows on the webpage                                                                | Y                | /                                                                                               |
| 7           | Time Stamp Sends Correctly              | The time stamp data is correctly coupled to collected data               | Check the server webpage and see if the data shows there                                 | Data shows on the webpage                                                                | Y                | /                                                                                               |
| 8           | Data is collected in a correct Interval | The data has to be collected at a constant rate                          | Check the server webpage and see if the time stamp is constant                           | Data shows at a constant time-interval                                                   | Y                | Currently at 5ms                                                                                |
| 9           | Data Slice Observations Fill up         | There are 5 slices of 40 data points each                                | Run the program and see the print statement                                              | After 40 iterations, the slices fill up                                                  | Y                | /                                                                                               |
| 10          | Data Slices Only Shift By One           | Make sure the FIFO is working right                                      | Run the program and see the print statement                                              | Once the data fills up, make sure slice one goes to slice 2 and so on after 5 iterations | Y                | /                                                                                               |
| 12          | Models Make Continuous Predictions      | The model continuously outputs something                                 | Run the program and see the print statement                                              | The model should predict something                                                       | Y                | The prediction does not have to be accurate                                                     |
| 13          | Frequency Is Over 2 Hz                  | Make sure the frequency is more than 2 Hz                                | Run the program and see the print statement                                              | More than 2Hz                                                                            | Y                | The closer to 8Hz, the better                                                                   |
| 14          | No memory leaks                         | Make sure the heap is at the same size when the loop starts and finishes | Run the program and see the print statement                                              | More than 2Hz                                                                            | Y                |

| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- |


