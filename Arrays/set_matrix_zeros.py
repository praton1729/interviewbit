

def setZeroes(A):

    B = A

    rows = len(A)

    cols = len(A[0])

    def set_row(i,j):
    
        for x in range(0,cols):
            B[i][x] = 0

    def set_column(i,j):

        for x in range(0,rows):
            B[x][j] = 0


    for i in range(0,rows):

        for j in range(0,cols):

            if(A[i][j]==0):
                set_row(i,j)
                set_column(i,j)

    return B


A = [[1,0,1],[1,1,1],[1,1,1]]

print(setZeroes(A))
