
def maxArr(A):
    
    def diff_func(A,i,j):
        return ( abs(A[i]-A[j]) + abs(i-j))

    n = len(A)

    max_diff = diff_func(A,1,1)

    for i in range(n):
        for j in range(i,n):
            
            max_diff = max(max_diff,diff_func(A,i,j))
    
    
    return max_diff              

def maxArr_alternative(A):
    
    n = len(A)
    B = [None]*n
    C = [None]*n

    for i in range(0,n):
        B[i] = A[i] + i        
        C[i] = A[i] - i

    max_plus = max(B)
    min_plus = min(B)
    max_minus = max(C)
    min_minus = min(C)

    diff_plus = max_plus - min_plus
    diff_minus = max_minus - min_minus

    return max(diff_plus,diff_minus) 

A = [1,3,-1]
print(maxArr_alternative(A));
