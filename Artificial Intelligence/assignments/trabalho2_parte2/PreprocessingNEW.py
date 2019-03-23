#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import cv2
import cv
import math
import numpy as np
import os

class Preprocessing:
	def __init__(self):
		pass
	# Esse método será responsável por aplicar a translação e mudança de amplitude nas séries do conjunto de treinamento
	def preprocess(self):
		itens = 0
		mylist = []
		handle = open("actions.csv", "r")
		contents = handle.readlines()
		handle.close()
		for item in contents:
			mylist.append(item[0])		
		ffile = open("result.csv", "r")
		ffile2 = open("result.csv", "r")
		fwrite = open("actionsR.csv", "w")
		ffile2.read(1)
		while ffile2.read(1) != 'F':
			ffile2.seek(-1, os.SEEK_CUR)
			ffile.seek(16,1)
			ffile2.seek(15,1)
			aux = []
			x = []
			x2 = []
			y = []
			y2 = []
			while (ffile2.read(1) != 'N'):
				aux.append(ffile.read(1))
			i = 0
			flg = 0
			# ler o x
			while i + 1 < len(aux):
				if(aux[i] == '\t'):
					flg = 1
				elif(aux[i] == '\n'):
					flg = 0
				elif(aux[i].isdigit() & flg != 1):
					x2.append(aux[i])
					i = i + 1
					while(aux[i].isdigit()):
						x2.append(aux[i])
						i = i + 1
					flg = 1
					x2.append('+')
				i = i + 1
			i = 0
			n = 0
			temp = 0
			temp2 = []
			# Calculo da media
			while i + 1 < len(x2):
				if(x2[i].isdigit()):
					temp2.append(x2[i])
					i = i + 1
					while(x2[i].isdigit()):
						temp2.append(x2[i])
						i = i + 1
					if(x2[i] == '+'):
						str1 = ''.join(temp2)
						x.append(int(str1))
						temp = temp + int(str1)
						if(int(str1) != 0):
							n = n + 1
						temp2 = []
				i = i + 1
			meanx = np.mean(x)
			i = 0
			flg = 1
			# ler o y
			while i + 1 < len(aux):
				if(aux[i] == '\t'):
					flg = 0
				elif(aux[i] == '\n'):
					flg = 1
				elif(aux[i].isdigit() & flg != 1):
					y2.append(aux[i])
					i = i + 1
					while(aux[i].isdigit()):
						y2.append(aux[i])
						i = i + 1
					flg = 1
					y2.append('+')
				i = i + 1
			i = 0
			n = 0
			temp = 0
			temp2 = []
			while i + 1 < len(y2):
				if(y2[i].isdigit()):
					temp2.append(y2[i])
					i = i + 1
					while(y2[i].isdigit()):
						temp2.append(y2[i])
						i = i + 1
					if(y2[i] == '+'):
						str1 = ''.join(temp2)
						y.append(int(str1))
						temp = temp + int(str1)
						if(int(str1) != 0):
							n = n + 1
						temp2 = []
				i = i + 1
			meany = np.mean(y)
			stdvtx = np.std(x)
			stdvty = np.std(y)
			# Aplicando as transformacoes aos pontos originais
			flg = 0
			i = 0
			while i + 1 < len(x):
				if flg == 0:
					fwrite.write("%s; " % mylist[itens])
					itens = itens + 1
					flg = 1
				x[i] = (x[i] - meanx)/stdvtx
				fwrite.write("(%s, " % x[i])
				y[i] = (y[i] - meany)/stdvty
				if(i + 2 == len(x)):
					fwrite.write("%s)" % y[i])
				else:
					fwrite.write("%s); " % y[i])
				i = i + 1
			fwrite.write("\n")
		ffile.close()
		ffile2.close()
		fwrite.close()

		# Esse método realiza as mesmas transformações do de cima, porém para o caso de teste
	def preprocess_test(self, vector):
		mx = 0
		my = 0
		n = 0
		px = []
		py = []
		for i in range(len(vector)):
			if(vector[i] != (0,0)):
				temp = vector[i]
				px.append(temp[0])
				py.append(temp[1])
				n = n + 1
		for i in range(len(px)):
			mx = mx + px[i]
			my = my + py[i]
		mx = mx / n
		my = my / n
		mx = np.mean(px)
		my = np.mean(py)
		stdx = np.std(px)
		stdy = np.std(py)
		for i in range(len(px)):
			px[i] = (px[i] - mx)/stdx
			py[i] = (py[i] - my)/stdy
		listt = []
		for i in range(len(px)):
			listt.append((px[i], py[i]))
		return listt

