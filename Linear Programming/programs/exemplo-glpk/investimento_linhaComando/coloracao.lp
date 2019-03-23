\* Problem: coloracao *\

Minimize
 obj: + y1 + y2 + y3

Subject To
 edge1:  x11 + x21 - y1 <= 0
 edge2:  x12 + x22 - y2 <= 0
 restr3:  x13 + x23 - y3 <= 0
 restr4:  x11 + x31 - y1 <= 0
 restr5:  x12 + x32 - y2 <= 0
 restr6:  x13 + x33 - y3 <= 0
 restr7:  x21 + x31 - y1 <= 0
 restr8:  x22 + x32 - y2 <= 0
 restr9:  x23 + x33 - y3 <= 0
 vert1: x11 + x12 + x13 = 1
 vert2: x21 + x22 + x23 = 1
 vert3: x31 + x32 + x33 = 1
Bounds
 y1 <=1
 y2 <=1
 y3 <=1
