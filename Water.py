import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(16,GPIO.IN)
while True:
    if GPIO.input(16):
        print("Water Detected")
        time.sleep(0.10)
    else:
        print("Water Not Detected")
        time.sleep(0.10)
