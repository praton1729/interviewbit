
def spiral_order_print(A):

    m = len(A)
    n = len(A[0])
    B = []
    
    for i in range(0,n-1):
        B.append(A[0][i])

    for j in range(0,m-1):
        B.append(A[j][n-1])

    for k in range(n-1,0,-1):
        B.append(A[m-1][k])

    for l in range(m-1,0,-1):
        B.append(A[l][0])

    if(len(A) ==1 and len(A[0])==1):
        
        return A
    else:
        M = A[1:-1][1:-1]
        B = B + spiral_order_print(M)
        
    return B

A = [[1,2,3],[4,5,6],[7,8,9]]

print(spiral_order_print(A))
