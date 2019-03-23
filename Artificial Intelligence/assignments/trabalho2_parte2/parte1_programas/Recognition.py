#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import os, time
import numpy as np
from Camera import Camera

class Recognition:
	def save(self):
		camera = Camera()
		print "START"
		i = 0
		global ffile
		ffile = open("actions.csv", "a")
		ffile.write("5;")
		while 1:
			j = camera.startStream()
			if(j == 0):
				break;
			elif(i > 55):
				break
			mask = camera.mask()
			x, y = camera.track(mask)
			ffile.write("({0},{1});" .format(y, x))
			i = i + 1
		ffile.seek(-1, os.SEEK_END)
		ffile.truncate()
		ffile.write("\n")
		ffile.close()
		sys.exit(0)

	def main(self):
		camera = Camera()
		i = 0
		x = 0
		y = 0
		while 1:
			k = camera.startStream()
			mask = camera.mask()
			x, y = camera.track(mask)
			i = i + 1
		camera.release()
		self.save()


if __name__ == '__main__':
	recognition = Recognition()
	recognition.main()