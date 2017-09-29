import serial
# import struct
# import requests
# import traceback
import sys
import json

from mote import Mote

serial_connection = serial.Serial('/dev/ttyACM0', 115200, timeout=None)
mote = Mote(serial_connection)
i = 0
while True:
    data = mote.readline()
    print("Read from serial:", data)
    data = data + 1
    print("Enviando to serial:", data)
    mote.put(data)
    # make_request(data)
