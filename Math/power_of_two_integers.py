

def isPower(A):

    if(A<=1):

        return True


    for x in range(2,int(A**0.5)+1):

        p = x

        while(p<=A):

            p = p*x
            
            if(p==A):

                return True

    return False


print(isPower(4))
