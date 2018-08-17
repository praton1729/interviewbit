


def plusOne(A):        
    
    i = 0
    if(A==0 and len(A)==1):
        i = 0
    else:
        while(A[i]==0):
            i = i+1
    B = A[i:]
    B.insert(0,0)
    def get_carry(a,b):
        
        if((a+b)>9):
            return 1
        else:
            return 0
            
    def get_digit(a,b):
        return (a+b)%10
        
    initial_carry = get_carry(B[-1],1)
    last_digit = get_digit(B[-1],1)
    
     
    #print("initial_carry is : %d \n" % initial_carry); 
    
    #print("last_digit is : %d \n" % last_digit);
 
    carry = initial_carry
    B[-1] = last_digit
    n = len(B)
    for i in range(n-2,-1,-1):
        
        digit = get_digit(B[i],carry)
        carry = get_carry(B[i],carry)
        B[i] = digit
    
    if(B[0]==0):
        return B[1:]
    else:
        return B
	            
                
A =[ 0, 3, 7, 6, 4, 0, 5, 5, 5 ] 
print(plusOne(A))            
