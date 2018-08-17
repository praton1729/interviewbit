
def firstMissingPositive(A):
    
    max_A = max(A)
    
    if(max_A > 0):
        
        sample_array = [False]*(max_A+1)

    else:
        
        first_missing_number = 0


    for i in A:
        
        if(i >=1):
        
            sample_array[i-1] = True


    for i in range(0,len(sample_array)):

        if(sample_array[i]==False):
            first_missing_number = i+1
            break

    return first_missing_number

A = [3,4,-1,1]

print(firstMissingPositive(A))

    
    
