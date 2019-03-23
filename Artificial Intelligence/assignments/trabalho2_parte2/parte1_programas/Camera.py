#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import cv2
import cv
import numpy as np

class Camera:
	def __init__(self):
		global cam, x, y
		x = 0
		y = 0
		cam = cv2.VideoCapture(0)

	def startStream(self):
		f = 1
		global stream
		retval, stream = cam.read()
		stream = cv2.flip(stream, 1)
		a = (x-4, y-4)
		b = (x+4, y+4)
		cv2.rectangle(stream, a, b, 3)
		cv2.imshow("Stream", stream)
		key = cv2.waitKey(10)
		if (key == 27):
			f = 0
			cam.release()
			return f 
		return f 

	def getStream(self):
		imageResized = cv.CreateImage((250, 320), 8, 3)
		cv.Resize(cv.fromarray(stream), imageResized)
		nImageResized = np.atleast_2d(np.ravel(np.asarray(imageResized[:,:])))
		return nImageResized

	def mask(self):
		hsv = cv2.cvtColor(stream, cv2.COLOR_BGR2HSV)
		lower_color = np.array([40, 100, 100], dtype=np.uint8)
		upper_color = np.array([80, 255, 255], dtype=np.uint8)
		mask = cv2.inRange(hsv, lower_color, upper_color)
		cv2.imshow("Mask", mask)
		return mask

	def track(self, mask):
		x = mask.argmax() / 640
		y = mask.argmax() % 640
		print "x, y:", y, x
		return x, y

	def release(self):
		cam.release()



