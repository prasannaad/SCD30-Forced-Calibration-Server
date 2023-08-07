---
title: 'A forced calibration system for SCD30 carbon dioxide sensor'
tags:
  - $CO_2$ Sensor
  - arduino
  - calibration
  - ESP32
authors:
 - name: Prasannaa Kumar D.
   orcid: 0000-0002-2308-7765
   affiliation: 1
   corresponding author: true
 - name: Saran Raj
   orcid: 0009-0002-9302-2446
   affiliation: "2"
 - name: Bavath D
   affiliation: "1"
   orcid: 0009-0001-7844-4985
affiliations:
 - name: Project Scientist, Indian Institute of Technology Delhi
   index: 1
 - name: Project Assistant, Indian Institute of Technology Delhi
   index: 2
date: 07 August 2023
bibliography: paper.bib
---

# Statement of need

Carbon dioxide ($CO_2$) sensors are vital components in various applications, such as indoor air quality assessment[@ABRAHAM2014165][@390298], climate control, and greenhouse gas monitoring. 
Accurate calibration of these sensors is critical to ensure reliable and consistent measurements [@10152133]. 
However, calibrating multiple sensors individually can be time-consuming and prone to human error, especially in scenarios where a large number of sensors are deployed across different locations. 
There is a pressing need for a robust, automated solution that can calibrate multiple SCD30 $CO_2$ sensors simultaneously at the same time using a web server interface. 


# Summary

$CO_2$ sensors like the SCD30, which operate based on NDIR (Non-Dispersive Infrared) technology [@ndir], are intricate optical systems. 
It is crucial to handle these sensors with utmost care to avoid mechanical stress on the optical cavity, which can lead to changes in the sensor's physical properties, ultimately impacting calibration and resulting in reduced accuracy. To address such scenarios, the SCD30 incorporates two calibration algorithms, namely ASC (automatic self-calibration) and FRC (forced re-calibration), designed to restore full accuracy. 

As previously stated, regular calibration is essential for the proper functioning of the SCD30 sensor. In research applications, multiple SCD30 sensors are used for various experiments. The SCD30 digital interface is compatible with the I2C protocol and the Modbus protocol. As shipped by Sensirion, SCD30 has a fixed I2C address of 0x61 [@scd30interfacedescription_2020]. To use multiple SCD30s, an I2C multiplexer is used here with an ESP32 microcontroller. Once connected to WiFi, a local web server can be accessed by entering the IP address. 

# Usage

This firmware requires an ESP32 and a TCA9548A multiplexer board. Once the firmware is uploaded, the ESP connects to the described WiFi credential. Upon accessing the web server through its IP address, the landing page prompts the user to provide information regarding the number of sensors connected as shown in (\autoref{fig:figure1}).  

![Selecting number of sensors in the setup.\label{fig:figure1}](figure1.png){ width=95% }

A reliable reference $CO_2$ value can be obtained by either of the methods:

1. Setting and controlling a known $CO_2$ concentration in a sealed environment with the set $CO_2$
concentration acting as the reference value.

2. Maintain a distance between the SCD30 and $CO_2$-emitting sources such as humans, open windows, and ventilation openings. A reference monitor can be used to obtain a value for FRC. 

Apart from $CO_2$ calibration, the SCD30 also consists of temperature offset. The SCD30 sensor module undergoes self-heating, leading to a temperature offset that influences both the temperature and relative humidity output signals. The temperature offset is primarily influenced by two factors: the encapsulation and environment of the SCD30 sensor and the power consumption of the sensor module. Consequently, variations in the sampling interval can affect the temperature offset. The temperature offset of the SCD30 is characterized by the variance between the temperature reading it provides and the true surrounding temperature. This can be changed by entering the offset value as shown in [image]

//temperature offset image. 


# Acknowledgements

We acknowledge contributions from Quest Lab, IIT Delhi. 

# References
