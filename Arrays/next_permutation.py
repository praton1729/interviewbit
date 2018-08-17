


def next_permutation(A):


    n = len(A)

    i = n-2

    while(i>=0 and A[i] >= A[i+1]):

        i= i - 1

    if(i==-1):
    
        return False # sorted(A)

    j = i+1

    while( j<n and A[j] > A[i] ):

        j = j + 1
    
    j = j - 1

    A[i],A[j] = A[j],A[i]

    left = i+1
    right = n-1

    while( left < right ):

        A[left],A[right] = A[right],A[left]

        left = left + 1
        right = right -1

    return True

A = range(1,5)

print A

while(next_permutation(A)):
    
    print A
        

