import sys

if __name__ == '__main__':
	print 'Theta 0 and 1 = 1.\n'
	theta = 1
	x0 = 1
	x1 = []
	y = []
	it = int(raw_input('Input the number of iterations: '))
	alpha = float(raw_input('Input a value for alpha: '))
	print "Input the number of points you wish to analyze. Then, input ALL points - following the model (x,y) - \n\
	from which you'd like to find a line using linear regression:"
	i = int(raw_input())
	for i2 in range(i):
		x1.insert(i2, int(raw_input()))
		y.insert(i2, int(raw_input()))
	print x1
	print "Linear regression"
	i2 = 0
	for k in range(it):
		for j in range(i):
			print 'Theta', theta, 'Alpha', alpha, 'x0', x0, 'x1', x1[j], 'y', y[j]
			theta = theta - alpha * (theta*x0 + theta*x1[j] - y[j]) * x1[j]
			print theta