

def diagonal(A):


    rows = len(A)

    cols = rows

    B = []


    def give_upper_diagonal(M,x):

        ret_diag = []

        if(x==0):
    
            ret_diag =  M[0][0]

        else:

            row = 0
            col = x

            while(col>-1):

                ret_diag.append(M[row][col])
                row = row +1
                col = col -1

        return ret_diag


    def give_lower_diagonal(M,x):

        ret_diag = []

        if(x==rows-1):

            ret_diag = M[rows-1][cols-1]

        else:

            row = x
            col = cols-1

            while(row<rows):
            
                ret_diag.append(M[row][col])
                row = row+1
                col = col-1

        return ret_diag


    if(rows==1):
        
        return [A]

    else:
        
        for i in range(0,cols):

            B.append(give_upper_diagonal(A,i))

        for j in range(1,rows):

            B.append(give_lower_diagonal(A,j))
            
        return B



A = [[1,2,3],[4,5,6],[7,8,9]]

print(diagonal(A))
