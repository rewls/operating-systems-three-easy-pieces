import os
import random
import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 1000, 20)

y = []
for i in range(0, 1000, 50):
    seed = random.randint(0, 1000);
    random.seed(seed);
    y.append(int(os.popen(
        "./relocation.py -n 1000 -l " + str(i) + " -c | grep VALID | wc -l"
        ).read()[:-1]))

plt.plot(x, y)
plt.xlabel("Value of the bounds register")
plt.ylabel("Valid fraction")
plt.show()
