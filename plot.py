import matplotlib.pyplot as plt 
import numpy as np 
import pandas as pd 

array_file = pd.read_csv("seno5.txt", header = 0, sep='\s+')

fig = plt.figure(figsize=(12,6))

x=np.arange(0,4,1)

axes = fig.add_axes([0.1,0.1,0.8,0.8])

axes.plot(array_file['i'], array_file['seno'], ls='-', marker='o',markersize=1)             

    
axes.set_xlabel('Real axis')
axes.set_ylabel("Imaginary axis")
axes.set_title("Frequency domain")
#axes.legend(loc='upper right')

#plt.show()
plt.grid(linestyle='-', linewidth=0.5)
plt.savefig("plotFrequency.pdf",dpi=600)

#########

array_file = pd.read_csv("fourier.dat", header = 0, sep='\s+')

fig = plt.figure(figsize=(12,6))

x=np.arange(0,4,1)

axes = fig.add_axes([0.1,0.1,0.8,0.8])

axes.plot(array_file['RX'], array_file['IX'], ls='-', marker='o',markersize=1)             


axes.set_title("Time Domain")
#axes.legend(loc='upper right')

#plt.show()
plt.grid(linestyle='-', linewidth=0.5)
plt.savefig("plotTime.pdf",dpi=600)


#######



array_file = pd.read_csv("kernel.dat", header = 0, sep='\s+')

fig = plt.figure(figsize=(12,6))

x=np.arange(0,4,1)

axes = fig.add_axes([0.1,0.1,0.8,0.8])

axes.plot(array_file['RX'], array_file['IX'], ls='-', marker='o',markersize=1)             

    
axes.set_xlabel('Real axis')
axes.set_ylabel("Imaginary axis")
axes.set_title("Fourier Transform")
#axes.legend(loc='upper right')

#plt.show()
plt.grid(linestyle='-', linewidth=0.5)
plt.savefig("plotFourier.pdf",dpi=600)
