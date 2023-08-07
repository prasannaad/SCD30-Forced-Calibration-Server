# SCD30 - $CO_2$ Sensor Calibration 

![image](https://github.com/prasannaad/SCD30-Forced-Calibration-Server/assets/70738433/ae125eaa-394a-4c06-8c87-1e891a9891a1)

$CO_2$ sensors like the SCD30, which operate based on NDIR (Non-Dispersive Infrared) technology [@ndir], are intricate optical systems. 
It is crucial to handle these sensors with utmost care to avoid mechanical stress on the optical cavity, which can lead to changes in the sensor's physical properties, ultimately impacting calibration and resulting in reduced accuracy. To address such scenarios, the SCD30 incorporates two calibration algorithms, namely ASC (automatic self-calibration) and FRC (forced re-calibration), designed to restore full accuracy. 
![image](https://github.com/prasannaad/SCD30-Forced-Calibration-Server/assets/70738433/2137ba15-71ee-489e-b9f6-2ea3eb24bd0c)
This firmware is based on forced re-calibration. Multiple (around 8 at a time) sensors can be used for the calibration. 


## Hardware Requirements.
1. TCA9548A-based I2C multiplexer (preferably from Seeedstudio).
2. ESP32 (any variant. ESP32S3 Xiao preferred for compact size). ![image](https://github.com/prasannaad/SCD30-Forced-Calibration-Server/assets/70738433/6c0b607e-37ff-4099-b103-69af675788d9)