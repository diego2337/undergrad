import sys
import cv2
import cv
import numpy as np
import time

if __name__ == '__main__':
	j = 1
	cap = cv2.VideoCapture(0)
	i = 1
	while 1 & i <= 50:
		retval, frame = cap.read()
		frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
		ponto_a = (200,80)
		ponto_b = (450, 400)
		cv2.rectangle(frame, ponto_a, ponto_b, (0,255,0),3)
		crop_frame = frame[80:400, 200:450]
		cv2.imshow("frame", crop_frame)
		key = cv2.waitKey(10)
		if (key == 27):
			break;
		#print j
		j = j + 1
		if (j % 30 == 0):
			cv2.imwrite('face_%i.jpg' %i, crop_frame)
			print "written"
			i = i + 1
	print "done, nice!"