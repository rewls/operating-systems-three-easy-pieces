import random

workload = []

for i in range(8):
    workload.append(random.randint(0, 1))

for i in range(2):
    workload.append(random.randint(2, 9))

random.shuffle(workload)

print(workload)
