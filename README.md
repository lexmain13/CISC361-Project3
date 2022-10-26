# CISC361-Project3

Overview:

In this project we will be examining the process table and scheduler in xv6 and adding a system call and user program which tests the system.

Details:

This project can be done on the class VM where all required software except xv6 is installed for you.

Resources:

Xv6 Manual: https://pdos.csail.mit.edu/6.828/2018/xv6.htmlLinks to an external site.
Adding a system call:
https://medium.com/@viduniwickramarachchi/add-a-new-system-call-in-xv6-5486c2437573Links to an external site.
http://recolog.blogspot.com/2016/03/a-new-system-call-to-xv6.htmlLinks to an external site.
Adding a user program to xv6: http://recolog.blogspot.com/2016/03/adding-user-program-to-xv6.htmlLinks to an external site.
Required Software:

Modified Xv6 Public on gitlab server.
You can install by using the command:
git clone https://gitlab.eecis.udel.edu/silber/xv6-public.git
Once installed, you can run it by typing:
make qemu-nox
(Will take a while the first time to build everything).
Will boot the os, and launch a user shell for you (like bash, but simpler).
You can exit by pressing ctrl-a x
Note: If you try to run this on your own unix/linux system (wsl/mac) you will need to install qemu on your system in addition to the xv6 repository.

 

Part 1: Understanding Scheduler

Review the scheduler() function in proc.c. add a line to print out the current process name and pid in each loop of the scheduler (i.e. process [%s:%d] is running)

Part 2: Adding a system call

                This portion of the project involves adding the ‘crsp’ system call to xv6.

Add the system call crsp() into Xv6, which prints out the current running and sleeping processes. 
Review very carefully how the scheduler() function (line 2758) works, as system call crsp() will loop over the same process table looking for both 
RUNNING and SLEEPING processes. Given that the process table (ptable) is a shared data structure, defined inside proc.c, within the Xv6 kernel, 
it has to be protected by a lock! See how scheduler() uses the lock associated with ptable and access process state of processes in ptable. 
Refer to the above references for details.

 

Part 3: A user program in your xv6 operating system

Review the resource on Adding a user program to xv6.

Write a user program named ps.c to test the invocation of crsp() which outputs something like the following. 
You will need to modify the Makefile file to create the command (executable) ps from ps.c.  
(i.e. you have to write it outside of xv6, then it will get built with the reset of xv6 when you do make qemu.)

name     pid     state

---------------------------

init     1       SLEEPING

sh       2       SLEEPING

ps       5       RUNNING

 

IMPORTANT NOTE:  To exit qemu press ctrl-a x
