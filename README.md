# SCD30 - $CO_2$ Sensor Calibration 

![image](https://github.com/prasannaad/SCD30-Forced-Calibration-Server/assets/70738433/ae125eaa-394a-4c06-8c87-1e891a9891a1)

$CO_2$ sensors like the SCD30, which operate based on NDIR (Non-Dispersive Infrared) technology [@ndir], are intricate optical systems. 
It is crucial to handle these sensors with utmost care to avoid mechanical stress on the optical cavity, which can lead to changes in the sensor's physical properties, ultimately impacting calibration and resulting in reduced accuracy. To address such scenarios, the SCD30 incorporates two calibration algorithms, namely **ASC** (automatic self-calibration) and **FRC** (forced re-calibration), designed to restore full accuracy. This firmware is based on forced re-calibration. Multiple (around 8 at a time) sensors can be used for the calibration. 


## Forced Re-Calibration

In case of forced re-calibration (FRC), the user has to feed a reference value from the host side to SCD30. The value provided by the host is used for updating the calibration to restore full accuracy. The latest reference value is saved in non-volatile memory on the sensor device and will persist until it is overwritten either by a new reference value that is supplied via FRC.


## How to Calibrate

Providing a valid reference value is crucial for the correct manipulation of the calibration curve. The reference value can be generated in three ways - from a calibrated reference sensor; by exposing the SCD30 to an
environment with controlled CO2 concentration; or from fresh outside air (= 400~420 ppm). The effect of FRC takes place immediately. FRC can be executed **multiple times at arbitrary intervals**. Before applying FRC, SCD30 needs to be operated for **2 minutes** with the desired measurement period in continuous mode.


## Hardware Requirements.
1. TCA9548A-based I2C multiplexer (preferably from [Seeedstudio](https://www.seeedstudio.com/Grove-8-Channel-I2C-Hub-TCA9548A-p-4398.html)).
2. ESP32 (any variant. [ESP32 Xiao](https://www.seeedstudio.com/Seeed-XIAO-ESP32C3-p-5431.html?queryID=0ed4f7c78acc6053be3f599cb81fd784&objectID=5431&indexName=bazaar_retailer_products) preferred for compact size).


