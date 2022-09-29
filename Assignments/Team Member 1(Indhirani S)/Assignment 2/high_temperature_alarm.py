
"""Assignment 2:

Build a python code, 
Assume u get temperature and humidity values (generated with random function to a variable) and 
write a condition to continuously detect alarm in case of high temperature.
"""

// Solution:

import random
Threshold=int(input("Enter threshold temperature (range 0,100): "))
choice=1
while(choice == 1):
    tempValue = random.randint(1,100)
    print("Current temperature  : ",tempValue)
    if(tempValue >= Threshold):
        print("Alert ! High temperature sensed .",tempValue," is greater than or equal to " ,Threshold)
    else:
        print("Normal temperature .",tempValue," is lesser than " ,Threshold)

    choice=int(input("Enter 1 to continue :"))
    
   

