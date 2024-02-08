| Test Number | Test Name                               | Test Description                                                   | Test Method                                                                              | Expected Behavior                                                 | Passed (y/n/tbd) | Notes                                                                                           |
| ----------- | --------------------------------------- | ------------------------------------------------------------------ | ---------------------------------------------------------------------------------------- | ----------------------------------------------------------------- | ---------------- | ----------------------------------------------------------------------------------------------- |
| 1           | Normal BMP280 Function                  | Ensures pressure and temperature data is correct                   | Run the program and observe printed numbers                                              | Prints realistic numbers                                          | Y                | Sensor connects and disconnects due to poor soldering                                           |
| 2           | Detached BMP 280 Function               | Ensures the pressure sensor still functions after it disconnects   | Run the program and observe printed numbers, then take out the sensor and put it back in | Functions like Test 1                                             | Y                | After reconnection, the sensor reads bad pressure values suspected to be due to a faulty sensor |
| 3           | Normal MPU6050                          | Ensures the gyro and acc. data is correct                          | Run the program and observe printed numbers                                              | Prints realistic numbers                                          | Y                | /                                                                                               |
| 4           | Detached MPU 6050 Function              | Ensures the gyro and acc data still functions after it disconnects | Run the program and observe printed numbers, then take out the sensor and put it back in | Functions like Test 4                                             | Y                | /                                                                                               |
| 5           | Wi-Fi Initialization                    | The Wi-Fi can successfully run the code                            | Run the program and see the print statement                                              | Prints "wifi initialized"                                         | TBD              | Not fully tested on a second Wi-Fi                                                              |
| 6           | Post Requests Send                      | The data sends to the server                                       | Check the server webpage and see if the data shows there                                 | Data shows on the webpage                                         | Y                | /                                                                                               |
| 7           | Time Stamp Sends Correctly              | The time stamp data is correctly coupled to collected data         | Check the server webpage and see if the data shows there                                 | Data shows on the webpage                                         | Y                | /                                                                                               |
| 8           | Data is collected in a correct Interval | The data has to be collected at a constant rate                    | Check the server webpage and see if the time stamp is constant                           | Data shows at a constant time-interval                            | Y                | Currently at 5ms                                                                                |
| 9           | Data Window Observations Fill up        | The data is added to the window as it is collected                 | Run the program and see the print statement                                              | After 13 iterations, the data is printed to show each observation | Y                | Self-contained test, no need to redo                                                            |
| 10          | Window Fills Up                         | The window fills at its capacity                                   | Run the program and see the print statement                                              | After 13 iterations, the data is printed to show each observation | Y                | Self-contained test, no need to redo                                                            |
| 11          | Window Clears Unimportant Data          | The window only stores metrics in its final iteration              | Run the program and see the print statement                                              | The output should only be metrics                                 | Y                | Self-contained test, no need to redo                                                            |
| 12          | Window Calculates Proper Data           | The metrics in the window are correct                              | Run the program and see the print statement                                              | Calculate the metrics by hand and ensure they are correct         | TBD              | Self-contained test, no need to redo, currently the data in there is placeholder data           |
| 13          | Queue properly fills up                 | The queue keeps expanding                                          | Run the program and see the print statement                                              | Ensure the queue has different values in it                       | Y                | Self-contained test, no need to redo                                                            |

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
