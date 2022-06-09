import RPi.GPIO as gpio
gpio.setwarnings(False)
gpio.setmode(gpio.BOARD)
gpio.setup(29, gpio.IN)
while True:
    if(gpio.input(29)):
        print("motion detected")
    else:
        print("motion not detected")