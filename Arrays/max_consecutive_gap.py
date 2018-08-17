

def max_cons_gap(A):

    A = sorted(A)

    max_diff = 0

    if(len(A)<2):

        return 0

    else:

        for i in range(len(A)-1):

            max_diff = max(max_diff,A[i+1]-A[i]) 

        return max_diff


A = [1,10,5]

print(max_cons_gap(A))
