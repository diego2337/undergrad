#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import cv2
import cv
import math
import numpy as np
import os
import webbrowser

class Gestures:
	def lftRgt(self):
		os.system("gedit")
	def rgtLft(self):
		webbrowser.open_new("http://ead.facom.ufms.br")
	def upDwn(self):
		os.system("libreoffice")
	def dwnUp(self):
		os.system("gnome-terminal -e 'bash -c \"exec bash\"'")
	def circle(self):
		os.system("gnome-control-center")

	def choice(self, option):
		if(option == '1'):
			self.lftRgt()
		elif(option == '2'):
			self.rgtLft()
		elif(option == '3'):
			self.upDwn()
		elif(option == '4'):
			self.dwnUp()
		elif(option == '5'):
			self.circle()