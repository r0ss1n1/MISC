#!/usr/bin/python3
# Charles Truscott, github.com/r0ss1n1
fh = open('multiples3.txt', 'w')
for x in range(1,99):
	for y in range(1,99):
		for z in range(1,99):
			fh.write(str(x) + " * " + str(y) + " * " + str(z) + " = " + str(int(x * y * z)) + "\n")
