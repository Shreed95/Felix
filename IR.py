import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(16,GPIO.IN)
GPIO.setup(25,GPIO.OUT)
while True:
    if GPIO.input(16):
        GPIO.output(25,0)
        print("Object not Detected")
        time.sleep(0.10)
    else:
        GPIO.output(25,1)
        print("Object Detected")
        time.sleep(0.10)
