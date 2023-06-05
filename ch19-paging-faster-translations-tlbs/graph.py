import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np
import os
import sys


if (len(sys.argv) < 3):
    print("usage: {sys.argv[0]} <executable file> <image name> <# trials>")
    exit();

x = [i for i in range(1, 14)]
x_page = [2**i for i in x] 
y = []
for i in x_page:
    output = os.popen(f"{sys.argv[1]} {str(i)} {int(sys.argv[3])}").read()
    y.append(float(output.split(': ')[1]))
    print(i, output)

plt.plot(x, y)
plt.xlabel("Number of Pages")
plt.ylabel("Time per Access (ns)")
plt.xticks(x, x_page)
plt.savefig(sys.argv[2])
plt.show()
