

def setZeroes(A):

    B = [row[:] for row in A]

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
#                print "B is"
#                print B
#                print "\n"
#                print "A is "
#                print A
#                print "\n"
#
                set_row(i,j)
                set_column(i,j)

    return B


#A = [[1,0,1],[1,1,1],[1,1,1]]
A = [[0, 0],[1, 0]]

print(setZeroes(A))
