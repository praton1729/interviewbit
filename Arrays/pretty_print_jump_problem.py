

def pretty_print(A):

    n = A

    rows = 2*n-1

    cols = 2*n-1

    M = [[n]*cols for i in range(rows)]

    startx = 1
    starty = 1
    n = n - 1

    while(n > 0):

        for i in range(startx,startx+2*n-1):

            for j in range(starty,starty+2*n-1):
                M[i][j] = n
        
        startx = startx + 1

        starty = startx

        n = n-1

    return M


print pretty_print(3) 
