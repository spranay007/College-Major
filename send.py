import requests
import serial
import time
ser= serial.Serial('/dev/ttyACM0',9600)
while 1:
		ser.flushInput()
		textln=ser.readline()
		print (textln)
		r=requests.post('https://api.thingspeak.com/update.json',data={'field1':textln,'api_key':'1ZEKN2Q78EJJ4U2Q'})
		print r.text
		time.sleep(10)
