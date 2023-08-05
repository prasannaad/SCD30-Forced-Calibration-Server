---
title: 'A forced re-calibration system for multiple SCD30 CO2 sensors'
tags:
  - CO2 Sensor
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

Carbon dioxide (CO2) sensors are vital components in various applications, such as indoor air quality assessment[@ABRAHAM2014165][@390298], climate control, and greenhouse gas monitoring. 
Accurate calibration of these sensors is critical to ensure reliable and consistent measurements [@10152133]. 
However, calibrating multiple sensors individually can be time-consuming and prone to human error, especially in scenarios where a large number of sensors are deployed across different locations. 
There is a pressing need for a robust, automated solution that can calibrate multiple SCD30 CO ^{exp} sensors simultaneously at the same time in a controlled environment, using a web server interface. 


# Summary

CO2 sensors like the SCD30, which operate based on NDIR (Non-Dispersive Infrared) technology [@ndir], are intricate optical systems. 
It is crucial to handle these sensors with utmost care to avoid mechanical stress on the optical cavity, which can lead to changes in the sensor's physical properties, ultimately impacting calibration and resulting in reduced accuracy. To address such scenarios, the SCD30 incorporates two calibration algorithms, namely ASC (automatic self-calibration) and FRC (forced re-calibration), designed to restore full accuracy. 

As previously stated, regular calibration is essential for the proper functioning of the SCD30 sensor. In research applications, multiple SCD30 sensors are used for various experiments. The SCD30 digital interface is compatible with the I2C protocol and the Modbus protocol. As shipped by Sensirion, SCD30 has a fixed I2C address of 0x61 [@scd30interfacedescription_2020]. To use multiple SCD30s, an I2C multiplexer is used here with an ESP32 microcontroller. Once connected to WiFi, a local web server can be accessed by entering the IP address. 

# Usage

This firmware requires an ESP32 and a TCA9548A multiplexer board. Once the firmware is uploaded, the ESP connects to the described WiFi credential. Upon accessing the web server through its IP address, the landing page prompts the user to provide information regarding the number of sensors connected as shown in (\autoref{fig:ferraris_gui}).  

//Landing page image.

Apart from CO 

Single dollars ($) are required for inline mathematics e.g. $f(x) = e^{\pi/x}$

Double dollars make self-standing equations:

$$\Theta(x) = \left\{\begin{array}{l}
0\textrm{ if } x < 0\cr
1\textrm{ else}
\end{array}\right.$$

# Acknowledgements

We acknowledge contributions from Quest Lab, IIT Delhi. 

# References
