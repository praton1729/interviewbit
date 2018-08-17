

def find_Perm(A,B):

    # A is the string
    # B is the number 

    n = B
    sample = []

    left = 1
    right = n

    for i in range(0,len(A)):

        if(A[i]=='I'):
            sample.append(left)
            left = left + 1
        else:
            sample.append(right)
            right = right -1
    
    sample.append(left)

    return sample

A = "DIIDI"

B = 6

print(find_Perm(A,B))
