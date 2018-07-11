#RESOURCES MONITOR WIDGET  
###The work presented in this paper is new and was prepared only for the course COMP 3000 Operating Systems, Winter 2017, School of Computer Science, Carleton University.

###Programmers:
* Muhammad Farooqui
* Thuong Mai

![newResourceMonitoringWidget.PNG](https://bitbucket.org/repo/MrgxRB4/images/1428449373-newResourceMonitoringWidget.PNG)

**1. Context/Background**  
Resource Monitoring Widget (RMW) is a resource monitoring tool that provides real-time consumption of resources 
such as RAM and CPU by the system and programs that currently running on the Linux OS. It is targeted towards users 
who are familiar with the Task Manager on Linux OS but doesn’t need lots of information on their monitor. The goal 
of the Widget is to provide a lightweight, compact tool for users in Linux.

**2. Problem Statement**  
The project intends to support users who want to track their current RAM or CPU usage without opening the heavy 
Task Manager with lots of distract information. Our goal is to make the Widget to be a small tool that can be 
located anywhere on the screen and not taking much space.

**3. Result**  
There are shell commands that is included in the widget such as accessing cpuinfo and meminfo, 
retrieve specific values and display it on the widget. The result is the widget that provides 
real-time information of system resources to users; plus, it is easy to use since there is no
input needed. The widget can automatically update the current RAM and CPU for every 1 second. 

