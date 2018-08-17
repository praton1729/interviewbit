

def power(A):

    x = int(A)

    if(x==1):

	return 0

    if( (x!=0) and (x & (x-1) == 0) ):
        
        return 1
    
    else:
        return 0 


print power(8)   
