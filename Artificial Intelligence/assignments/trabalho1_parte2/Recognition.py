#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import os
import numpy as np
from Camera import Camera
from MLearning import MLearning

class Recognition:
	def main(self, alg):
		camera = Camera()
		machine =  MLearning()
		i = 0
		flg = -1
		while 1:
			j = camera.startStream()
			if(j == 0):
				break;
			if(i % 30 == 0):
				vector = camera.getStream()
				if(alg == 1):
					result = machine.KNN(vector)
				elif(alg == 2):
					result = machine.SGD(vector)
				elif(alg == 3):
					result = machine.decisionTree(vector)
				print chr(27) + "[2J"
				sys.stderr.write("\x1b[2J\x1b[H")
				if(result.item(0) == 1):
					print "Feliz"
				elif(result.item(0) == 0):
					print "Triste"
				i = 0
			i = i + 1
		print "Para selecionar outro algoritmo, digite o número correspondente ao mesmo; caso queira parar o programa, tecle q.\n"
		os.execlp("python", "python", "Recognition.py")



if __name__ == '__main__':
	recognition = Recognition()
	print "Selecione uma das opções.\n"
	inp = (raw_input("1 - KNN;\n2 - Perceptron;\n3 - Árvore de decisão;\nq - Sair.\n"))
	if(inp == '1'):
		algorithm = 1
	elif(inp == '2'):
		algorithm = 2
	elif(inp == '3'):
		algorithm = 3
	elif(inp == 'q'):
		sys.exit(0)
	elif(inp == 'Q'):
		sys.exit(0)
	else:
		print "Comando incorreto. Finalizando programa.\n"
		sys.exit(0)
	recognition.main(algorithm)