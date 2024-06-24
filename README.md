Capstone Project: [Project Title]
Overview
[Project Title] aims to address [specific problem or challenge] by developing [brief description of the solution or product].

Objectives
Research and Analysis: Review literature and market.
Design and Development: Create [solution/product].
Testing and Validation: Ensure effectiveness and reliability.
Implementation and Deployment: Deploy to real-world use.
Evaluation and Feedback: Gather feedback and improve.
Accomplishments
Research and Analysis
Comprehensive literature review and market analysis.
Requirements gathering from stakeholders.
Design and Development
Designed and developed [solution/product] using [technologies/tools used].
Testing and Validation
Conducted extensive testing, including UAT.
Validated against requirements.
Implementation and Deployment
Deployed solution/product smoothly.
Provided user training and support.
Evaluation and Feedback
Collected and analyzed user feedback.
Evaluated success based on KPIs and user satisfaction.
Key Outcomes
Impact: [Describe impact, e.g., improved efficiency, reduced costs].
User Satisfaction: [Percentage] positive feedback.
Scalability: Solution/product designed for future expansion.
Innovation: Introduced features such as [list innovative features].
Conclusion
[Project Title] successfully addressed [problem/challenge] with a [solution/product] that meets user needs. We achieved our objectives and delivered a impactful solution in [field/industry]. Thanks to all who contributed.

Team Members
[Name 1] - [Role/Contribution]
[Name 2] - [Role/Contribution]
[Name 3] - [Role/Contribution]
[Name 4] - [Role/Contribution]
Contact Information
For questions or further information, please contact:

[Your Name]
Email: [Your Email]
LinkedIn: [Your LinkedIn Profile]

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

## Standard ESP Documentation

| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- |

# _Sample project_

(See the README.md file in the upper level 'examples' directory for more information about examples.)

This is the simplest buildable example. The example is used by command `idf.py create-project`
that copies the project to user specified path and set it's name. For more information follow the [docs page](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html#start-a-new-project)

## How to use example

We encourage the users to use the example as a template for the new projects.
A recommended way is to follow the instructions on a [docs page](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html#start-a-new-project).

## Example folder contents

The project **sample_project** contains one source file in C language [main.c](main/main.c). The file is located in folder [main](main).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt`
files that provide set of directives and instructions describing the project's source files and targets
(executable, library, or both).

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── main.c
└── README.md                  This is the file you are currently reading
```

Additionally, the sample project contains Makefile and component.mk files, used for the legacy Make based build system.
They are not used or needed when building with CMake and idf.py.
