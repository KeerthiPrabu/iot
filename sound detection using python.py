from time import sleep
import RPi.GPIO as gpio
gpio.setwarnings(False)
gpio.setmode(gpio.BOARD)
gpio.setup(11, gpio.IN)
gpio.setup(3, gpio.OUT)
while True:
    if(gpio.input(11)==True):
        gpio.output(3, False)
        print("no sound")
        sleep(1)
    if(gpio.input(11)==False):
        gpio.output(3, True)
        print("sound")
        sleep(1)