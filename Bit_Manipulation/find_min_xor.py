

def find_min_xor(A):

    B = sorted(A)

    min_xor = B[0]^B[1]

    for i in range(1,len(A)-1):

        min_xor = min(min_xor,B[i]^B[i+1])


    return min_xor


A = [0,2,5,7]

print find_min_xor(A) 
