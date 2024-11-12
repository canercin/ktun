import random
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

xlist = []
ylist = []

# creating random numbers
for i in range(0, 1000):
    xlist.append(random.randrange(0, 1000))

for j in range(0, 1000):
    ylist.append(random.randrange(0, 1000))

# creating data frame
df = pd.DataFrame({'x': xlist, 'y': ylist})

# save datas to excel with pandas
df.to_excel('hw6.xlsx', index=False)

# read data from excel and assign attributes
df = pd.read_excel('hw6.xlsx')
xlist = df['x']
ylist = df['y']

# set grid size
gridsize = 200

# choose colors
colors = ('r', 'g', 'b', 'c', 'm', 'y', 'k')

# visualization data
plt.figure(figsize=(10, 10))
plt.title('Koordinat Noktaları Izgaraya Bölünmüş')
plt.xlabel('X Koordinatları')
plt.ylabel('Y Koordinatları')

for i in range(0, 1000, gridsize):
    for j in range(0, 1000, gridsize):
        in_grid = (xlist >= i) & (xlist < i + gridsize) & (ylist >= j) & (ylist < j + gridsize)
        plt.scatter(xlist[in_grid], ylist[in_grid], color=np.random.choice(colors), label=f'Grid ({i},{j})')

for i in range(0, 1000, gridsize):
    plt.axvline(x=i, color='k', linestyle='--', linewidth=0.5)  # Dikey çizgiler
    plt.axhline(y=i, color='k', linestyle='--', linewidth=0.5)  # Yatay çizgiler

# Son çizgiye ek olarak sınır çizgilerini de ekleyelim
plt.axvline(x=1000, color='k', linestyle='--', linewidth=0.5)
plt.axhline(y=1000, color='k', linestyle='--', linewidth=0.5)

plt.savefig('hw6.jpeg')
plt.show()
