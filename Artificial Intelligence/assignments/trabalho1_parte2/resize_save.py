import sys
import cv2
import cv
import numpy as np

if __name__ == '__main__':
	i = 1
	while i <= 50:
		img = cv.LoadImage("face_%i.jpg" %i, 0)
		print "Abrindo face_%i.jpg\n" %i
		# print img
		imageResized = cv.CreateImage((64, 64), 8, 1)
		cv.Resize(img, imageResized)
		vec = np.asarray(imageResized[:,:])
		vector = np.ravel(imageResized)
		cv2.imwrite('faceres_%i.jpg' %i,  vec)
		print type(vec)
		vector = np.ravel(vec)
		print type(vector)
		ffile = file("faces.csv", "a")
		np.savetxt(ffile, np.atleast_2d(vector), fmt = '%d', delimiter = ';', newline = ";1 \n")
		ffile.close()
		# print vector
		i = i + 1
