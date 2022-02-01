import matplotlib.pyplot as plt 
import numpy as np 
import pandas as pd 

array_file = pd.read_csv("seno1.txt", header = 0, sep='\s+')

fig = plt.figure(figsize=(12,6))

x=np.arange(0,4,1)

axes = fig.add_axes([0.1,0.1,0.8,0.8])

axes.plot(array_file['i'], array_file['seno'], ls='-')             


#axes.set_ylim(-6, 6)
axes.set_title("Senoidal Curve")
#axes.legend(loc='upper right')

#plt.show()
plt.grid(linestyle='-', linewidth=0.5)
plt.savefig("seno1.pdf",dpi=600)