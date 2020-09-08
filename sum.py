#!/usr/bin/python3
# Author: Charles Truscott, github.com/r0ss1n1
fh = open('sum.txt', 'w')
for x in range(1,10):
	for y in range(1,10):
		for z in range(1,10):
			for p in range(1,10):
				for q in range(1,10):
					for r in range(1,10):
						for s in range(1,10):
							for a in range(1,10):
								for b in range(1,10):
									#print(str(x) + " + " + str(y) + " + " + str(z) + " + " + str(p) + " + " + str(q) + " + " + str(r) + " + " + str(s) + " + " + str(a) + " + " + str(b) + " = ")
									#print(x + y + z + p + q + r + s + a + b)
									fh.write(str(x) + " + " + str(y) + " + " + str(z) + " + " + str(p) + " + " + str(q) + " + " + str(r) + " + " + str(s) + " + " + str(a) + " + " + str(b) + " = " + str(int(x + y + z + p + q + r + s + a + b)))
