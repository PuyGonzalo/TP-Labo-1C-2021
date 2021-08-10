# Imports
import serial
import matplotlib.pyplot as plt
import numpy as np

# Declaracion de variables usadas
size_Periodo = 2
size_ADC = 1
f_osc = 16e6
N = 8 #Prescaler (Timer1)
f_timer = f_osc/N
T_timer = 1/f_timer
step_size = 19.53e-3


# Abro puerto
serial_port = serial.Serial(port = "COM4",
baudrate = 9600,
parity=serial.PARITY_NONE ,
bytesize=serial.EIGHTBITS, 
stopbits=serial.STOPBITS_ONE,
timeout=2
)
 

# Recibo dato y calculo la frecuencia
data = serial_port.read(size_Periodo)
data =int.from_bytes(data, 'little',signed=False)



T = data*T_timer
f = 1/T

print("Frecuencia (PWM): ",f, "Hz")

# Tension del capacitor (ADC)
plt.close('all')
plt.figure()
plt.ion()
plt.show()

adc_data = np.array([])
i = 0

while i < 60:
    a = serial_port.read(size_ADC)
    a = int.from_bytes(a, 'big',signed=False)
    a = float(a)
    adc_data = np.append(adc_data, a)
    plt.cla()
    plt.plot(adc_data*step_size)
    plt.title('Tension del capacitor')
    plt.ylabel('Tension [V]')
    plt.xlabel('Tiempo')
    plt.grid()
    i = i+1

# Cierro puerto    
serial_port.close()

