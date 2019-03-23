import sys
def gradiente(x):
	return 2*x - 8

if __name__ == '__main__':
	x = float(sys.argv[1])
	it = int(sys.argv[2])
	alpha = float(sys.argv[3])
	for i in range(it):
		x = x - alpha * gradiente(x)
		print x