# PID Tuning
PID stands for Proportional Intrgral Derivative controller. PID are the gains of the controller based on which necessary control action is taken. The error signal is the component used to calculate the control action. Error signal in this case is the difference between the center of the road (desired value) and the actual postion of thr car (current value).

The Proportional only controller takes corrective action based on the error. The control action is directly proportional to the error. The proportionality constant is the proportional gain (Kp) which has to be set by us, which will determine how sensitive will the control action be to the error. Similar is the case with the derivative gain (Kd) and integral gain (Ki). However, the P only controller on its own is not enough to keep up with the target value, because the car will oscillate because of its inertia (overshoot). To account for this the PD controller is useful. 

The derivative gain sort off predicts where the next position of the car would be based on currenrt and past measurements between two time steps and takes control action combined with the proportional control. This reduces the response time of the controller and corrects for the oscillation of the car. 

The integral gain reduces the steady state error (bias) by collecting the error over time or to compensate for any inherent bias or external disturbance. The bias here can be the steering drift as explained in the lessons. Since, there is no steering bias here the Ki gain is used to reduce the steady state error over few time steps once the current values is within 5% to 10% of the target value. This is especially evident during the turns on the track. The CTE in the only PD control tends to be somewhat constant, but with the PID control CTE converges towards zero.

I used manual tuning to selct the PID values. I first set Ki and Kd to 0 and played with the Kp valuse so the it showcases sustained oscillations and atleast reaches till the bridge or some distance before it. Then I started tuning Kd values to remove these oscillations and then again moved the Kp values a bit up and down and again played with the Kd to get a reasonable driving around the track and good driving along the middle of the road. PD control is sometimes kind of jerky, so the Kd value needs to be lowered accordingly. Then introduced the Ki term to redusce the steady state error of the steering value. The Ki term is typically very low of the order 0.001 since error accumulated over time would be high and we need to have a low Ki gain to reduce the large control output. 

I have included [videos](./writeup_video) for P only control, PD control and PID control.


# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).

