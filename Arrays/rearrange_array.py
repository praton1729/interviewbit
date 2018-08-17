

def arrange(A):

    n = len(A)

    for i in range(len(A)):

        A[i] = A[i] + ( A[A[i]] % n )*n
    
    print A

    for i in range(len(A)):

        A[i] = int(A[i]/n)


A = [3,2,0,1]
arrange(A)
print A
        
