# Tiny_mdt
A useful tiny gadget! <br>  
Youtube video: https://www.youtube.com/embed/fY5Y1o6QoCc?si=GF92eTSO-mVCjJeZ <br> 
<br> 
Tiny mdt is a small electronic gadget that measures environmental data and shows it on a small 0.96" OLED display. 
The data is acquired and processed by an ATtiny85 microcontroller.<br> 
![alt-text](https://github.com/Green-bms/Tiny_mdt/blob/master/Pictures/componenti%20frontali.png)) <br> 
The device is powered by a 3v CR2032 coin cell
the card only works when the power button is pressed and turns off when released.
So most of the time the device stays off, saving energy.
According to my calculations, with moderate use, the battery should last about 10-12 months.
I created the software with Arduino IDE. The big challenge was to find the lightest libraries to fit in the limited memory of the ATtiny85.
The project is available in 2 versions, with the same PCB (only the sensors to be used and the software to be loaded into the microcontroller change) <br>
## Type 1: htt
![alt-text](https://github.com/Green-bms/Tiny_mdt/blob/master/Pictures/fronte%20type1.png)) <br> 
This variant uses the HTU21D sensor which measures humidity and ambient temperature.
Furthermore, the temperature of an object is also detected using the MLX90614 infrared thermometer. <br> 
![alt-text](https://github.com/Green-bms/Tiny_mdt/blob/master/Pictures/retro%20type1.png)) <br>
## Type 2: htp
![alt-text](https://github.com/Green-bms/Tiny_mdt/blob/master/Pictures/fronte%20type2.png)) <br> 
This is a small portable weather station in the palm of your hand!
The board uses the excellent BME280 sensor which measures humidity, temperature and barometric pressure.<br> 
![alt-text](https://github.com/Green-bms/Tiny_mdt/blob/master/Pictures/retro%20type2.png)) <br>
## Do it yourself
This project is completely open source and is very simple to create. <br>
![alt-text](https://github.com/Green-bms/Tiny_mdt/blob/master/Pictures/pcb_design.png)) <br>
I deliberately used tht components to facilitate soldering.<br>
![alt-text](https://github.com/Green-bms/Tiny_mdt/blob/master/Pictures/soldering.png)) <br>
The ATtiny85 microcontroller is socket mounted, so it can be easily removed and programmed using the maker's favorite programmer.
For example, I used the "Wemos as ISP" programmer that you find here: https://github.com/Green-bms/Wemos-as-ISP <br>
![alt-text](https://github.com/Green-bms/Tiny_mdt/blob/master/Pictures/cover3d.png)) <br>
