# auto_steering-cpp

####
Hello everyone! This is a Program to read a specific data log which contains four columns with accelerometer output and estimates its roll and pitch angles.
####

To understand how this task was performed, you need to take a look at Application Note 3461 from NXP.
####

This program is divided in four parts, in the first one the log is open and is counted how many lines it has, so I can allocate an int array with the right number of memory slots.

Than, I read the file again and parse its columns in four different arrays: time, x, y and z.

With the intuit of make this code more modular, I prefered to first allocate the data in arrays and estimate (do the math) later.

So, the data is extracted from the arrays, estimated and stored in two other arrays;

At the end, this two new arrays are write with the timestamp one in an output file named "roll_and_pitch_angles.txt"
####

IMPORTANT
This code was made in a windows 10 OS. There is no library except the gnu/gcc+ standart libraries, so, if you want to compile in windows just make sure you have gnu/gcc compiler obtained installing MinGW and you will need some IDE.

Although, I also tested this in Ubuntu 18 and wrote a Makefile to make it easier in this case, to compile you will need to install g++, it is easy: 'sudo apt-get install g++'. You will also need 'build-essentials' libraries, obtained by: 'sudo apt-get install build-essentials'.

If everything went ok you will run the command make all in the right repositorie and the program will be compiled.

To run the program, you need to garantee that the log will be in the same folder/repositorie, and named as attitude_exam.log





