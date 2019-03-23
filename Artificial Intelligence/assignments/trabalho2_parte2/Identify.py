#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import cv2
import cv
import os
import numpy as np
from CameraNEW import Camera
from Gestures import Gestures
from RearrangeNEW import Rearrange
from MLearning import MLearning
from PreprocessingNEW import Preprocessing
class Identify:
	def __init__(self):
		global camera, rearrange, preprocess, machine, gestures
		global h,s,v,i,im,evente
		# Instanciando a Camera para utilizá-la no método main
		camera = Camera()
		# Essas variáveis são definidas como atributo do identify, pois serão utilizadas para o método mouse_callback
		self.h,self.s,self.v,self.i,self.r,self.g,self.b,self.j,self.evente=0,0,0,0,0,0,0,0,0
		# Com o rearrange iremos arrumar o conjunto de pontos de maneira a manipulá-lo com mais facilidade
		rearrange = Rearrange()
		rearrange.rearrange()
		# Agora iremos aplicar as transformações necessárias sobre as séries - translação e normalização
		preprocess = Preprocessing()
		preprocess.preprocess()
		machine = MLearning()
		gestures = Gestures()

		# Método que reconhece o clique duplo de um mouse
	def mouse_callback(self, event,x,y,flags,param):
	    self.evente=event
	    if event==cv.CV_EVENT_LBUTTONDBLCLK:
	    	imageResized = cv.CreateImage(cv.GetSize(cv.fromarray(camera.stream)), 8, 3)
	    	cv.Resize(cv.fromarray(camera.stream), imageResized)
	    	cv.CvtColor(cv.fromarray(camera.stream),imageResized,cv.CV_BGR2HSV)
	    	(self.h,self.s,self.v,self.i)=cv.Get2D(imageResized,y,x)
	    	(self.r,self.g,self.b,self.j)=cv.Get2D(cv.fromarray(camera.stream),y,x)


	def main(self):
		# Essa flag só é utilizada para impedir com que duas telas sejam mostradas, confundindo o usuário na escolha da cor
		flag = 0
		print "Dê um clique duplo na cor que deseja rastrear."
		while 1:
			j = camera.startStream(flag)
			if(j == 0):
				print "Finalizando o programa..."
				sys.exit(0)
			cv2.namedWindow('color')
			# Aqui, definimos o metodo call_back para o usuario definir a cor que quer rastrear
			cv.SetMouseCallback('color', self.mouse_callback)
			cv2.moveWindow('color', 350, 200)
			cv2.imshow('color', camera.stream)
			# A cor foi selecionada
			if self.h != 0:
				cv.DestroyWindow('color')
				break
		# Método responsável por identificar os gestos feitos pelo usuário
		flag = 1
		while 1:
			j = camera.startStream(flag)
			if(j == 0):
				print "Voltando à seleção de cores. Caso queira parar o programa, tecle q.\n"
				os.execlp("python", "python", "Identify.py")
			mask = camera.getStream(self.h, self.s, self.v)
			k = camera.track(mask)
			if(k != 0):
				vector = preprocess.preprocess_test(k)
				result = machine.KNN(vector)
				gestures.choice(result)
				camera.release()
				print "Voltando à seleção de cores. Caso queira parar o programa, tecle q.\n"
				os.execlp("python", "python", "Identify.py")
		sys.exit(0)


if __name__ == '__main__':
	identify = Identify()
	inp = (raw_input("1 Selecionar cor;\nQ/q - Sair.\n"))
	if(inp == '1'):
		identify.main()
	elif((inp == 'Q') | (inp == 'q')):
		print "Finalizando programa..."
		sys.exit(0)
	else:
		print "Comando incorreto. Finalizando programa.\n"
		sys.exit(0)