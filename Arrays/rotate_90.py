

def rotate_90_clock(A):    

    def transpose(A):
    
        rows = len(A)
        cols = len(A[0])

        ret_A = [[A[j][i] for j in range(rows)]for i in range(cols)]

        return ret_A

    def reverse_cols(A):
    
        rows = len(A)
        cols = len(A[0])
        j = 0
        k = cols -1

        for i in range(cols):
            while(j<k):
            
                A[j][i],A[k][i] = A[k][i],A[j][i]
                j = j+1
                k = k -1 

        return A

    return (reverse_cols(A))
    


A = [[1,2],[3,4]]

print(rotate_90_clock(A))
