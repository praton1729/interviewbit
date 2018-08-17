

def PrettyPrint(A):

    def give_matrix(M,startx,starty,length,value):
        
       #print("startx and starty are %d %d \n" %( startx, starty))  
       #print("value is : %d \n" % value)
    
        for r in range(startx,startx+length):
            for c in range(starty,starty+length):
                M[r][c] = value
                #print("Corresponding row index is : %d \n" % r)
        return M

    n = 2*A -1
    startx = 0
    starty = 0
    
    M = [[None]*n]*n
    
    value = A
    

    for l in range(n,0,-2):
        
        M = give_matrix(M,startx,starty,l,value)
        startx = startx + 1
        starty = starty + 1
        value = value -1

    return M

print PrettyPrint(3)
