import matplotlib.pyplot as plt 
import numpy as np 
import pandas as pd 

i = 1

fig = plt.figure(figsize=(8,6))

x=np.arange(0,4,1)

axes = fig.add_axes([0.1,0.1,0.8,0.8])

while(i <= 18):
    if(i == 6):
        i = 7
    
    file = pd.read_csv(f'seno_{i}.000.dat', header = 0, sep='\s+')
    axes.plot(file['x'], file['y'], ls='-', marker='o',markersize=1, label=f'Frequency = {i} GHz')
    
    i = i + 1
    

axes.set_xlabel('Frequency')
axes.set_ylabel("Amplitude")

axes.set_title("Comparison senoidal curves")
plt.grid(linestyle='-', linewidth=0.5)
axes.legend(loc='upper right')

plt.savefig("PlotSenoide.pdf",dpi=600)