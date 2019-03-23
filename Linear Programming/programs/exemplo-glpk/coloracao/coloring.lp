\* Problem: coloring *\

Minimize
 obj: + y1 + y2 + y3

Subject To
 edge1: - y1 + x2,1 + x1,1 <= 0
 edge2: - y1 + x3,1 + x1,1 <= 0
 edge3: - y2 + x2,2 + x1,2 <= 0
 edge4: - y2 + x3,2 + x1,2 <= 0
 edge5: - y3 + x2,3 + x1,3 <= 0
 edge6: - y3 + x3,3 + x1,3 <= 0
 cover7: + x1,3 + x1,2 + x1,1 = 1
 cover8: + x2,3 + x2,2 + x2,1 = 1
 cover9: + x3,3 + x3,2 + x3,1 = 1

Bounds
 0 <= y1 <= 1
 0 <= y2 <= 1
 0 <= y3 <= 1
 0 <= x1,1 <= 1
 0 <= x2,1 <= 1
 0 <= x3,1 <= 1
 0 <= x1,2 <= 1
 0 <= x2,2 <= 1
 0 <= x3,2 <= 1
 0 <= x1,3 <= 1
 0 <= x2,3 <= 1
 0 <= x3,3 <= 1

Generals
 y1
 y2
 y3
 x1,1
 x2,1
 x3,1
 x1,2
 x2,2
 x3,2
 x1,3
 x2,3
 x3,3

End
