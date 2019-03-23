#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import cv2
import cv
import numpy as np

class Camera:
	def __init__(self):
		global cam
		cam = cv2.VideoCapture(0)

	def startStream(self):
		f = 1
		global cam, stream
		retval, stream = cam.read()
		a = (200,80)
		b = (450, 400)
		cv2.rectangle(stream, a, b, (0,255,0),3)
		global crop_stream
		crop_stream = stream[80:400, 200:450]
		cv.Circle(cv.fromarray(stream), (330,248), 4, 3, -1)
		cv2.imshow("Stream", stream)
		stream = cv2.cvtColor(stream, cv2.COLOR_BGR2GRAY)
		key = cv2.waitKey(10)
		if (key == 27):
			f = 0
			cam.release()
			return f # Essa flag indica que se deve voltar para a seleçao de algoritmos de inteligência artificial
		return f # Procedimento padrao, que mantém o algoritmo escolhido

	def getStream(self):
		imageResized = cv.CreateImage((64, 64), 8, 1)
		cv.Resize(cv.fromarray(stream), imageResized)
		nImageResized = np.atleast_2d(np.ravel(np.asarray(imageResized[:,:])))
		return nImageResized