/*Assignment 2:

Build a python code, 
Assume u get temperature and humidity values (generated with random function to a variable) and 
write a condition to continuously detect alarm in case of high temperature.
*/

//Solution
import random

tempValue = random.randint(1,100)
print("Current temperature  : ",tempValue)
if(tempValue >= 70):
    print("Alert ! High temperature sensed .")
else:
    print("Normal temperature")
    
