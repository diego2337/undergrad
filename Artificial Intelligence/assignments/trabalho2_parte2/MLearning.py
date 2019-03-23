#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import cv2
import cv
import numpy as np
from sklearn import neighbors, tree, linear_model
from sklearn.neighbors.ball_tree import BallTree
from sklearn.neighbors import NearestNeighbors
from sklearn.linear_model import SGDClassifier


class MLearning:
	def __init__(self):
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

	def KNN(self, imvector):
		closest = 1000000000
		j = 0
		print "Processando, por favor aguarde."
		for i in range(len(self.x2)):
			if(self.dtw_dist(imvector, self.x2[i]) < closest):
				closest = self.dtw_dist(imvector, self.x2[i])
				j = i
		return self.y2[j]

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
				cost = self.manhattanDistance(aux, s[i])
				DTW[i][j] = cost + min(DTW[i-1][j], DTW[i][j-1], DTW[i-1][j-1])
		return DTW[len(s)-1][len(t)-1]