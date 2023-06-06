f_trace = open("trace.txt")
f_vpn = open("vpn.txt", "w")

lines = f_trace.readlines()

for line in lines:
    if not line.startswith("=="):
        vpn = int(line[3:11], 16) & 0xfffff000 >> 12
        f_vpn.write(f"{vpn}\n")

f_trace.close()
f_vpn.close()
