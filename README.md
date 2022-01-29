# Delivery-Mobile-Robot
## Prerequisite
|Software|Link|
|--------|----|
|ROS Melodic|[Link](http://wiki.ros.org/melodic/Installation/Ubuntu)|
|Arduino IDE on Linux|[Link](https://www.arduino.cc/en/software)|
|Arduino Due Board Installed on IDE|[Link](https://forum.arduino.cc/t/installing-arduino-sam-boards-on-arduino-ide-for-arm64/550398)|
|ROS Serial|[Link](http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup)|

|Hardware|Alternative|Link|Comment|
|--------|-----------|----|-------|
|1 X Jetson Nano|||Running ROS|
|1 X Arduino Due|||Control DC Motor|
|1 X Custom Motor Diver|IBT-2||This driver is custom made. It has the same control method as IBT-2|
|1 X Custom Logic Level Converter|SparkFun Logic Level Converter|[Link](https://www.sparkfun.com/products/12009)|Use for shifting 3v and 5v power in Arduino Due|
|1 X IMU BNO055||[Link](https://learn.adafruit.com/adafruit-bno055-absolute-orientation-sensor)|Running ROS|
|2 X Gear DC Motor|||with Encoder|
|1 X Lidar||||
|1 X Camera||||
|2 X Lipo Battery|||1 X 12v for all electronic, 1 X 24v for motor driver only|




## Mobile Robot Parameter
<table>
<tr> <th>Robot Structure</th> <th>Left DC Motor</th> <th>Right DC Motor</th></tr>
<tr> <td>

|Parameter|Value|
|---------|-----|
|Type|Differential Drive|
|Width|...m|
|Length|...m|
|Height|...m|
|Weight|...kg|
|Base Length|0.44 m|
|Wheel Radius|0.07 m|
|Wheel Base to <br/>Caster Wheel|...m|
|Ground Clearance|...m|

</td><td>

|Parameter|Value|
|---------|-----|
|Motor Gear Box||
|Wheel Gear||
|Pulse Per Revolution||
|Kp||
|Ki||
|Kd||
|Lumped Parameter a||
|Lumped Parameter b,c||

</td><td>

|Parameter|Value|
|---------|-----|
|Motor Gear Box||
|Wheel Gear||
|Pulse Per Revolution||
|Kp||
|Ki||
|Kd||
|Lumped Parameter a||
|Lumped Parameter b,c||

</td></tr> </table>

## Connection
