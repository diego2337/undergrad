#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import cv2
import cv
import numpy as np

class Camera:
	def __init__(self):
		global cam, diffx, x, y, diffy, series, i, flg
		self.series = []
		self.i = 0
		self.flg = 0
		self.diffx = 700
		self.diffy = 700
		self.x = 0
		self.y = 0
		self.cam = cv2.VideoCapture(0)

	def startStream(self, flag):
		f = 1
		global stream
		retval, self.stream = self.cam.read()
		self.stream = cv2.flip(self.stream, 1)
		a = (self.x-10, self.y-10)
		b = (self.x+10, self.y+10)
		cv2.rectangle(self.stream, a, b, 3)
		if(flag == 1):
			cv2.namedWindow("Stream")
			cv2.moveWindow("Stream", 350, 200)
			cv2.imshow("Stream", self.stream)
		key = cv2.waitKey(10)
		if (key == 27):
			f = 0
			self.cam.release()
			return f 
		return f 

		# Método que define um "thresholding" com base na cor escolhida pelo usuário
	def getStream(self, h, s, v):
		hsv = cv2.cvtColor(self.stream, cv2.COLOR_BGR2HSV)
		lower_color = np.array([h-15, s-15, v-10], dtype=np.uint8)
		upper_color = np.array([h+15, s+15, v+10], dtype=np.uint8)
		mask = cv2.inRange(hsv, lower_color, upper_color)
		return mask

	def track(self, mask):
		#print mask.shape
		self.x = mask.argmax() % 640
		self.y = mask.argmax() / 640
		# Primeira vez
		if self.diffx == 700:
			self.diffx = self.x
			self.diffy = self.y
		elif(self.flg == 1):
			# Movimento detectado, tem de armazena-lo - começo
			if(abs(self.diffx - self.x + abs(self.diffy - self.y)) > 13):
				self.series.append((self.x, self.y))
				self.diffx = self.x
				self.diffy = self.y
			# Aqui é o estado final, onde o movimento ja terminou
			elif(self.i > 13):
				return self.series
			# Vai para um estado onde ele espera algum tempo para saber se o movimento parou ou nao
			elif(abs(self.diffx - self.x + abs(self.diffy - self.y)) < 3):
				self.series.append((self.x, self.y))
				self.diffx = self.x
				self.diffy = self.y
				self.i = self.i + 1
		elif(abs(self.diffx - self.x + abs(self.diffy - self.y)) > 13):
				self.series.append((self.x, self.y))
				self.diffx = self.x
				self.diffy = self.y
				self.flg = 1
		return 0

	def release(self):
		self.cam.release()
