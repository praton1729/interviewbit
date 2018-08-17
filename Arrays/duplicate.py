

def repeated_number(A):
 
    n = len(A)
   
    sample_array  = [False]*n

    for i in A:
        
        if(sample_array[i] == False):
            
            sample_array[i] = True
       
        elif(sample_array[i] == True):
            
            sample_array[i] = 2
            duplicate = i
            break
        else:
            duplicate = -1

    return duplicate


A = [3,1,4,2,1]

print(repeated_number(A))

         
