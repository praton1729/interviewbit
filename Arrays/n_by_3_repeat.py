

def repeated_Number(A):
    
    n = len(A)

    max_count= n//3

    sample_array = {}

    for i in A:

        sample_array[i] = 0

    for i in A:

        sample_array[i] = sample_array[i] + 1
 
        if(sample_array[i] > max_count):
        
            ret = i
            break
        else:
            ret = -1

    return ret

A = [1,2,2,4,0]

print(repeated_Number(A))

    
        
        
                
