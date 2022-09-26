
"""Assignment 2:

Build a python code, 
Assume u get temperature and humidity values (generated with random function to a variable) and 
write a condition to continuously detect alarm in case of high temperature.
"""
import random
x = int(input("Enter Threshold Temperature(Range 0,50):"))
a=1
while(a==1):
    value=random.randint(0,50)
    print("Random Temperature: ",value)
    if value>x:
        print("Random Temp:",value,"higher than",x,"(Threshold Temperature)")
    elif x>value:
        print("Random Temp:",value,"less than",x,"(Threshold Temperature)")
    else:
        print("Random Temp:",value,"equals to",x,"(Threshold Temperature)")
    a=int(input("Enter 1 to Repeat:"))
