

def wave(A):

    A.sort()

    n = len(A)

    for i in range(1,n,2):
        
        tmp = A[i]
        A[i] = A[i-1]
        A[i-1] = tmp

    
    return A


A = [1,2,3,4]

print(wave(A))        
        
        
    
