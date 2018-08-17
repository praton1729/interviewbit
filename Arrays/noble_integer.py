

def noble_integer(A):

    for i in A:

        B = [1 for x in A if x > i]

        if(len(B) == i):
            
            ret = 1
            break
        else:
            
            ret = -1

    return ret

def noble_integer_alter(A):

    A = sorted(A)

    for i in range(len(A)-1):
        
        if(A[i] == A[i+1]):
        
            ret = -1
            continue
        else:
            
            if(A[i] ==len(A)-i-1):
                ret = 1 
                break   
    
    return ret

A = [5,6,2]

print(noble_integer_alter(A))
