# gpio_blink.py
# uses the Adafruit BBB python library (ships with default BBB Debian image)
# 2017 John Cottrell
# blinks GPIO P9_21, reads P9_22, hold P9_24 high

import Adafruit_BBIO.GPIO as GPIO
import time
 
GPIO.setup("P9_21", GPIO.OUT)
GPIO.setup("P9_22", GPIO.IN)
GPIO.setup("P9_24", GPIO.OUT)

while True:
    GPIO.output("P9_24", GPIO.HIGH)
    GPIO.output("P9_21", GPIO.HIGH)
    time.sleep(0.1)
    if GPIO.input("P9_22"):
        print("HIGH")
    else:
        print("LOW")
    time.sleep(0.4)
    GPIO.output("P9_21", GPIO.LOW)
    time.sleep(0.1)
    if GPIO.input("P9_22"):
        print("HIGH")
    else:
        print("LOW")
    time.sleep(0.4)
    
GPIO.cleanup()
