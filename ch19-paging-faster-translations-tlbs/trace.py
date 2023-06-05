import os
import sys


if (len(sys.argv) < 2):
    print("usage: {sys.argv[0]} <executable file> <# trials>")
    exit();

for i in [2**j for j in range(1, 14)]:
    output = os.popen(f"{sys.argv[1]} {str(i)} {int(sys.argv[2])}").read()
    print(i, output)
