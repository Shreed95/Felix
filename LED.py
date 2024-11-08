import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(16,GPIO.OUT)
GPIO.setwarnings(False)
try:
    while True:
        print("LED ON")
        GPIO.output(16,GPIO.HIGH)
        time.sleep(1)
        print("LED OFF")
        GPIO.output(16,GPIO.LOW)
        time.sleep(1)
except:
    GPIO.cleanup()
        
