import serial
ser = serial

try:
    ser = serial.Serial('/dev/ttyACM0', 9600)
    ser.write(999)
except serial.serialutil.SerialException:
    ser = serial.Serial('/dev/ttyACM1', 9600)
    ser.write(999)
#temp = "999"
#ser.write(temp.encode())