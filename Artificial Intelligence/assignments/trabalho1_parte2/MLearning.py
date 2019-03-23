#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import cv2
import cv
import numpy as np
from sklearn import neighbors, tree, linear_model
from sklearn.linear_model import SGDClassifier

class MLearning:
	def __init__(self):
		ffile = open("facesall.csv", "r")
		global dataset
		dataset = np.loadtxt(ffile, dtype = int, delimiter = ';', ndmin = 2)
		global x, y
		x = dataset[:, 0:4096]
		y = dataset[:, 4096]
		ffile.close()

	def KNN(self, imvector):
	# OBSERVAÇAO: Insira os construtores comentados caso esteja em um ambiente fechado (porem, os resultados nao serao precisos)
	#	classification = neighbors.KNeighborsClassifier(n_neighbors = 5, weights = "uniform", radius = 4.5, algorithm = "ball_tree", p = 1)
		classification = neighbors.KNeighborsClassifier(n_neighbors = 3, weights = "uniform", radius = 2.0, algorithm = "ball_tree", p = 2)
		classification.fit(x, y)
		return (classification.predict(imvector))

	def SGD(self, imvector):
	#	classification = SGDClassifier(loss="perceptron", alpha = 0.05, penalty = "l2", shuffle = True)
		classification = SGDClassifier(loss="perceptron", alpha = 0.1, penalty = "l1", shuffle = True)
		classification.fit(x, y)
		return (classification.predict(imvector))

	def decisionTree(self, imvector):
	#	classification = tree.DecisionTreeClassifier(criterion = "entropy", max_depth = 5, min_samples_split = 20)
		classification = tree.DecisionTreeClassifier(criterion = "entropy", max_depth = 3, min_samples_split = 4)
		classification.fit(x, y)
		return (classification.predict(imvector))