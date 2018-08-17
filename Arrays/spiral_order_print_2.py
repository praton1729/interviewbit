

B = []

def spiral(matrix, level):

	m, n = len(matrix), len(matrix[0])  # MxN matrix

	left, right, top, bottom = level, n - 1 - level, level, m - 1 - level

	if level >= m // 2 and level >= n // 2:
	    return  # no more layer to solve
	
	for j in range(left, right):
	    B.append(matrix[top][j])
	
	for i in range(top, bottom):
	    B.append(matrix[i][right])
	
	for j in range(right, left, -1):
	    B.append(matrix[bottom][j])
	
	for i in range(bottom, top, -1):
	    B.append(matrix[i][left])
	
	spiral(matrix, level=level + 1)

A = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]

spiral(A,0)

print(B)
