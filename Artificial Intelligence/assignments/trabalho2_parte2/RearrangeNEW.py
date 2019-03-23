#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import os, time
import numpy as np
class Rearrange:
	def __init__(self):
		global ffile, ffile2
		ffile = open("actions.csv", "r")
		ffile2 = open("actions.csv", "r")
	# Tudo que esse método faz é rearranjar o arquivo original "actions.csv", facilitando sua manipulação posteriormente
	def rearrange(self):
		ffile.seek(1,1)
		ffile2.seek(1,1)
		aux = []
		while ffile2.read(1) != '':
			aux.append(ffile.read(1))
		i = 0
		j = 0
		flg = 0
		ffile.close()
		ffile2.close()
		fwrite = open("result.csv", "w")
		fwrite.write("NOVA TIME SERIE\n")
		while i + 1 < len(aux):
			j = i
			if(aux[i] == '\n'):
				fwrite.write("NOVA TIME SERIE\n")
			elif(aux[i].isdigit() & (aux[i+1] != ';')):
				x = aux[i]
				i = i + 1
				while(aux[i].isdigit()):
					x = x + aux[i]
					i = i + 1
				if(x == '0'):
					j = j + 2
					if(aux[j] == '0'):
						i = i + 1
					elif(flg == 0):
						fwrite.write("%s\t" % x)
						flg = 1
					elif(flg == 1):
						fwrite.write("%s\n" % x)
						flg = 0
				elif(flg == 0):
					fwrite.write("%s\t" % x)
					flg = 1
				elif(flg == 1):
					fwrite.write("%s\n" % x)
					flg = 0
			i = i + 1
		fwrite.write("NF")
		fwrite.close()