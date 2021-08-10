# Imports
import pandas as pd
import matplotlib.pyplot as plt

# Para poder renderizar Latex
plt.rcParams.update({
    "text.usetex": True,
    "font.family": "sans-serif",
    "font.sans-serif": ["Helvetica"]})



data = pd.read_csv(r'TP_Integrador_Simulacion.txt',
                   sep='\t',
                   skiprows=1,
                   names=["time", "Vin", "Vc"])

t = data.time * 10e2
vc = data.Vc
vin = data.Vin


plt.figure()
plt.plot(t,vc,'-',label=r'$V_C$')
plt.plot(t,vin,'-',label=r'$V_{in}$')
plt.title(r'Tension del capacitor')
plt.xlabel(r'\textbf{Tiempo}  $[ms]$')
plt.ylabel(r'\textbf{Tension}  $[V]$')
plt.xlim([0,50])
plt.legend()
plt.grid()
plt.show()

