
def sub_unsort(A):

    n = len(A)

    B = list(A)

    if(A==sorted(B)):

        return [-1]

    left = 0
    right = n-1

    for i in range(n):

        if(A[left] <= min(A[left+1:])):
    
            left = left+1

        if(A[right] >= max(A[:right])):
    
            right = right -1


    return [left,right]

def sub_unsort_alter(A):

    n = len(A)

    B = list(A)

    if(A == sorted(B)):

        return [-1]

    i = n-2

    while( i> -1 and A[i]<=A[i+1] ):

        i = i -1

    right = i+1

    j = 0

    while( j < n-1 and A[j]<=A[j+1]):

        j = j+1

    left = j

    print [left,right]

    max_val = max(A[left:right+1])
    min_val = min(A[left:right+1])

    print [max_val,min_val]

    for i in range(left):

        if(A[i] > min_val):
		
		left = i
		break

    for j in range(len(A)-1,right,-1):
	print A[j]
        if(A[j] < max_val):
		print A[j]	
		right = j
		break
 
    return [left,right]    

A = [ 4, 15, 4, 4, 15, 18, 20 ]
#A = [1,3,2,4,5]
#A = [ 1, 2, 3, 5, 6, 13, 15, 16, 17, 13, 13, 15, 17, 17, 17, 17, 17, 19, 19 ]
print(sub_unsort_alter(A))        
