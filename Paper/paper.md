---
title: 'A forced re-calibration system for multiple SCD30 carbon dioxide sensors'
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
 - name: Gulshan Kumar
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
There is a pressing need for a robust, automated solution that can calibrate multiple SCD30 CO2 sensors simultaneously at the same time in a controlled environment, using a centralized web server interface. 


# Summary

CO2 sensors like the SCD30, which operate based on NDIR (Non-Dispersive Infrared) technology [@ndir], are intricate optical systems. 
It is crucial to handle these sensors with utmost care to avoid mechanical stress on the optical cavity, which can lead to changes in the sensor's physical properties, ultimately impacting calibration and resulting in reduced accuracy. To address such scenarios, the SCD30 incorporates two calibration algorithms, namely ASC (automatic self-calibration) and FRC (forced re-calibration), designed to restore full accuracy [@calibration]. 



# Acknowledgements

We acknowledge contributions from Brigitta Sipocz, Syrtis Major, and Semyeong
Oh, and support from Kathryn Johnston during the genesis of this project.

# References
