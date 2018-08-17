


def reverse(A):

    str_A = str(A)

    if(str_A[0]=='-'):

        sign = str_A[0]
        str_A = str_A[1:]

    else:

        sign = ''

    left = 0
    right = len(str(A))-1

    str_A = str_A[::-1]
   
    if(int(str_A) > 2**31-1):
    
        return 0

    else: 
    
        return int(sign + str_A) 

A = -1146467285

#A = -123

print(reverse(A))
