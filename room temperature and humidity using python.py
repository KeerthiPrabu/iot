import Adafruit_DHT
sensor = Adafruit_DHT.DHT11
while True:
    humidity, temperature = Adafruit_DHT.read(sensor, 4)
    if humidity is not None and temperature is not None:
        print("Temp={}*C Humidity={}%".format(temperature, humidity))
    else:
        print("no input")