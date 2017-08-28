# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program PID Controller Project

### Building and Running Instructions

To build the project follow instructions in (project link)[https://github.com/udacity/CarND-PID-Control-Project]

To run the pid controller with tuned controller gains use
```
./pid 
```

To the run the pid controller with externally supplied gains use
```
./pid Kp Ki Kd
```

### Final Result
Here's a youtube video link showing the performance of the controller with
```
Kp = 0.12
Kd = 0.7
Ki = 0
```

[![PID Control](https://img.youtube.com/vi/Bifu5XZ2bDc/0.jpg)](https://youtu.be/Bifu5XZ2bDc)

### PID controller equation
If cte is the current cross track error, [Kp, Ki, Kd] are the proportial, integral and differential gains, then the final gain is given by
```
gain = -(Kp * cte + Ki * (i_error + cte) + Kd * (cte - prev_cte)
```
This steering value is set to this gain every timestep within the loop.

### No use of Integral Control
In this project, I chose to not use any integral control after observing that the vehicle is able to achieve the commanded set-point with proportional control and there's no actuation issues in the underlying physics of the car in the simulator.

### Tuning PID controller

To tune a PID controller, generally one can use gradient descent/twiddle or other such variants. For this project however, I tuned the controller gains manually and verified visually. The reason I chose to tune manually was because the simulator cannot be run from the command line in a headless mode and provide the average cross track error. Had the ability to run the simulator within code without any visualizations been available, then the twiddle
algorithm could be used to find the right gains to minimize the cross track error in an automated manner.

I used a form the twiddle algorithm but with visual inspection to measure the performance of the controller in order to increase/decrease the gains until the controller performed well. I also decided to set the throttle to 0.2 so that it allowed the PID controller to remain stable while tuning the gains at the lower speed. In the long term, the throttle could also be controlled with another PID controller that uses the cross-track-error to decide the speed of the vehicle.

To start with I selected some gains Kp = 0.1, Ki = 0.0, Kd = 0.0. I then increased Kp gradually till the vehicle was able to correct itself to stay in the middle of the lane. At that point I noticed that the controller would overshoot quite a bit when turning. To control this I used the differential gain to make it achieve the set-point more smoothly so that it didn't overshoot by too much when it approached the goal. 

Finally I played around with the gains a little more to around the baseline values found with the above method to further fine-tune the performance of the controller.

### Future Improvements

- Adjust Throttle to be controlled by the crosstrack error so that the vehilce can run faster
- Try to automatically tune gains by using twiddle algorithm