"""Assignment 3:

Write python code for blinking LED and Traffic lights for Raspberry pi.

Only python code is enough, no need to execute in raspberry pi.

Note: you are allowed to use web search and complete the assignment.

Assignment to be submitted in a week
"""

from gpiozero import Button, TrafficLights, Buzzer    
from time import sleep    
    
buzzer = Buzzer(15)    
button = Button(21)    
lights = TrafficLights(25, 8, 7)    
    
while True:    
           button.wait_for_press()   
           buzzer.on()   
           lights.green.on()    
           sleep(1)    
           lights.amber.on()    
           sleep(1)    
           lights.red.on()    
           sleep(1)    
           lights.off()   
           buzzer.off()
