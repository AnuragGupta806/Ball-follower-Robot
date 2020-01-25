# Ball-follower-Robot
This project was assigned to me by the Robotics Club of MNNIT,Allahabad.

A simple bot that can track a ball in three dimensions, using a 2D video input and then follow it. No machine learning involved.

Features:-
This bot uses pure computer vision concepts. Compared to conventional ML models, it:

1.Has a higher FPS.
2.Has a lower computational complexity. (Works well on edge devices like the Raspberry Pi)
3.Need not be trained.


A brief note on the working is given below:
1.We need to calibrate a HSV threshold such that we can mask out our target ball.
2.Once a mask is created, we perform a couple of erosions and dilations to remove noise.
3.The largest contour in the mask is identified. The centre and radius of the smallest circle that can enclose this contour is calculated.
4.By comparing the centre value with the camera's midpoint, we can detect motion in the XY direction.
5.Distance of object is calculated using triangle similarity method.
6.Then we return these values to arduino using serial communication.
7.Arduino process these values and takes necessary motion by controling the motors.

Requirements:

OpenCV+Python
NumPy
pyserial

Instructions:
1.Upload the arduino code into the Arduino Uno .
2.install opencv,pyserial and run the python code using the line given on top of the python code.
