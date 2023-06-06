import sys
import os
import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np

if len(sys.argv) < 2:
    print(f"usage: {sys.argv[0]} <image name>")
    exit()

x = [i for i in range(14)]
x_size = [2**i for i in range(14)]

y = []
for i in [2**i for i in range(14)]:
    output = os.popen(f"./paging-policy.py -f vpn.txt -C {i} -N -c").readlines()[-2]
    y.append(float(output.split(" ")[-1]))

plt.plot(x,y)
plt.xlabel("Cache Size (bit)")
plt.ylabel("Hit Rate (%)")
plt.xticks(x, x_size)
plt.savefig(sys.argv[1])
plt.show()
