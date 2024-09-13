# Acces_Lidar_and_Get_Distance_ROS
This page contains the programs and files to access the RPLidar A3M1 type lidar in ROS Noetic. There are two steps to get started, first accessing the lidar and visualizing it using RViz using the package from ROS and creating a program to get Distance, Angle, and Coordinate data programmed using the Cpp language.

**STEPS TO RUN**

*Make sure you already install ROS Noetic on yout computer*

**Create New Package in ROS**

1. For create new package in ROS, you can follow [Cretae ROS Package] (https://wiki.ros.org/ROS/Tutorials/CreatingPackage)
2. After create package, you have three derectory (build, devel, src)
3. Move your terminal to *your_package/src* with the command *cd ~/your_package/src*
4. At src directory, you can clone this repository

**Access Lidar**

*Make sure you run ros master with roscore*

1. Connect RPLidar A3M1 to your computer
2. Make sure your bash.rc connected t your package with add command *source ~/your_package/devel/setup.bash* in your bash.rc file
3. For lauch lidar, at *your_package* directory use command roslaunch *rplidar_ros view_rplidar_a3.launch*
4. Lidar will be executed and will be visualized in RViz

**Get Distance, Angle, Coordinate Data**

1. For read data lidar, at *your_package* directory use command *rosrun lidar_read node_lidar_read*

**NOTE**

1. If Any eror, try to build yout directory. Delete all directory "bild adn devel" dan run comman *catkin_make* to rebuild yout program






**                        GOOD LUCK                    **
