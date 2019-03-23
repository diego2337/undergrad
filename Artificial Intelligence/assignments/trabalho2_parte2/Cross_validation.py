#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import os
import math
import numpy as np
from sklearn.metrics import precision_recall_fscore_support
from CameraNEW import Camera
from Gestures import Gestures
from RearrangeNEW import Rearrange
from PreprocessingNEW import Preprocessing

class Cross:
	def __init__(self):
		# Com o rearrange iremos arrumar o conjunto de pontos de maneira a manipulá-lo com mais facilidade
		rearrange = Rearrange()
		rearrange.rearrange()
		# Agora iremos aplicar as transformações necessárias sobre as séries - translação e normalização
		preprocess = Preprocessing()
		preprocess.preprocess()
		ffile = open("actionsR.csv", "r")
		global dataset
		global x2, y2
		dataset = np.loadtxt(ffile, dtype = tuple, delimiter = ';', ndmin = 2)
		self.x2 = []
		self.y2 = []
		for i in range(len(dataset)):
			x = dataset[i]
			xs = x[0]
			self.x2.append(xs[1:])
			self.y2.append(xs[0])
		ffile.close()

	def manhattanDistance(self, xy1, xy2):
		return abs(xy1[0] - xy2[0] + abs(xy1[1] - xy2[1]))

	def dtw_dist(self, s, t):
		DTW = [[0 for x in xrange(len(t))] for x in xrange(len(s))]
		i = 0
		for i in range(len(s)):
			DTW[i][0] = 10000000000000
		for i in range(len(t)):
			DTW[0][i] = 10000000000000
		DTW[0][0] = 0
		i = 0
		j = 0
		for i in range(len(s)):
			for j  in range(len(t)):
				aux = t[j]
				z = 0
				temp2 = []
				tmp = []
				# Transformando o arquivo lido de string para tuple
				while z < len(aux):
					if(aux[z].isdigit() | (aux[z] == '-')):
						temp2.append(aux[z])
						z = z + 1
						while(aux[z].isdigit() | (aux[z] == '.')):
							temp2.append(aux[z])
							z = z + 1
						if(aux[z] == ','):
							str1 = ''.join(temp2)
							tmp.append(float(str1))
							temp2 = []
						elif(aux[z] == ')'):
							str1 = ''.join(temp2)
							tmp.append(float(str1))
							temp2 = []
					z = z + 1
				# Fim da transformaçao
				aux = (tmp[0],tmp[1])
				aux2 = s[i]
				z = 0
				temp2 = []
				tmp = []
				# Transformando o arquivo lido de string para tuple
				while z < len(aux2):
					if(aux2[z].isdigit() | (aux2[z] == '-')):
						temp2.append(aux2[z])
						z = z + 1
						while(aux2[z].isdigit() | (aux2[z] == '.')):
							temp2.append(aux2[z])
							z = z + 1
						if(aux2[z] == ','):
							str1 = ''.join(temp2)
							tmp.append(float(str1))
							temp2 = []
						elif(aux2[z] == ')'):
							str1 = ''.join(temp2)
							tmp.append(float(str1))
							temp2 = []
					z = z + 1
				# Fim da transformaçao
				aux2 = (tmp[0],tmp[1])
				cost = self.manhattanDistance(aux, aux2)
				DTW[i][j] = cost + min(DTW[i-1][j], DTW[i][j-1], DTW[i-1][j-1])
		return DTW[len(s)-1][len(t)-1]


	def sample(self, test, training, y):
		closest = 1000000000
		j = 0
		for i in range(len(training)):
			if(self.dtw_dist(test, training[i]) < closest):
				closest = self.dtw_dist(test, training[i])
				j = i
		return y[j]
	
	def cross_validation(self):
		j = 0
		z = 0
		aux = []
		aux2 = []
		aux3 = []
		y = []
		y2 = []
		y3 = []
		# Distribuiremos os folds respeitando a proporçao entre as classes - 510 exemplos, 170 folds para cada
		while len(aux) < 170:
			aux.append(self.x2[j])
			y.append(self.y2[j])
			if(j < (len(self.x2) - (len(self.x2)/3))):
				j = j + (len(self.x2)/3)
			else:
				z = z + 1
				j = z
		while len(aux2) < 170:
			aux2.append(self.x2[j])
			y2.append(self.y2[j])
			if(j < (len(self.x2) - (len(self.x2)/3))):
				j = j + (len(self.x2)/3)
			else:
				z = z + 1
				j = z
		while len(aux3) < 170:
			aux3.append(self.x2[j])
			y3.append(self.y2[j])
			if(j < (len(self.x2) - (len(self.x2)/3))):
				j = j + (len(self.x2)/3)
			else:
				z = z + 1
				j = z
		# Aplicaremos aqui 3-fold cross validation
		miss_rate = 0
		train = aux2 + aux3
		y_train = y2 + y3
		clss = []
		# Primeiro fold
		for i in range(len(aux)):
			clss.append(self.sample(aux[i], train, y_train))
			if(clss[i] != y[i]):
				miss_rate = miss_rate + 1
		miss_rate = float(miss_rate) / len(aux)
		print "taxa de erro: ", miss_rate
		print "1º fold: ", precision_recall_fscore_support(y, clss, pos_label = None, average = 'macro')

		train = []
		y_train = []
		clss = []
		train = aux + aux2
		y_train = y + y2
		miss_rate2 = 0
		# Segundo fold
		for i in range(len(aux)):
			clss.append(self.sample(aux3[i], train, y_train))
			if(clss[i] != y3[i]):
				miss_rate2 = miss_rate2 + 1
		miss_rate2 = float(miss_rate2) / len(aux)
		print "taxa de erro: ", miss_rate2
		print "2º fold: ", precision_recall_fscore_support(y3, clss, pos_label = None, average = 'macro')

		train = []
		y_train = []
		clss = []
		train = aux + aux3
		y_train = y + y3
		miss_rate3 = 0
		# Terceiro fold
		for i in range(len(aux)):
			clss.append(self.sample(aux2[i], train, y_train))
			if(clss[i] != y2[i]):
				miss_rate3 = miss_rate3 + 1
		miss_rate3 = float(miss_rate3) / len(aux)
		print "taxa de erro: ", miss_rate3
		print "3º fold: ", precision_recall_fscore_support(y2, clss, pos_label = None, average = 'macro')

		print "taxa de erro total: ", int((miss_rate3+miss_rate2+miss_rate)/3*100)
		sys.exit(0)		

if __name__ == "__main__":
	cross = Cross()
	cross.cross_validation()
