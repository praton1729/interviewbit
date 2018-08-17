

def findrank(A):

    rank = 0
    
    def chars_less_than(i,A):
        
        less_than = 0

        for j in A[i:]:

            if(j<A[i]):
                
                less_than = less_than+1

        return less_than    

    def repeat_chars_freq(i,A):

        repeat_array = [0]*52

        for j in A[i:]:

            if(j >= 'A' and j <= 'Z'):

                repeat_array[ord(j)-ord('A')] = repeat_array[ord(j)-ord('A')]+1
    
            else:

                repeat_array[ord(j)-ord('a')+26] = repeat_array[ord(j)-ord('a')+26]+1

        product = 1
 
        for e in repeat_array:
            
            product = product*fac(e)

        return product

    def fac(n):

        if(n==0):

            return 1

        else:

            return n*fac(n-1)
   
    n = len(A)
 
    for i in range(len(A)):

        less_than = chars_less_than(i,A)

        product_of_repeated_chars =repeat_chars_freq(i,A)

        product = less_than*fac(n-i-1)//(product_of_repeated_chars)
        
        rank = rank + product                 

    rank = rank + 1
    return rank % 1000003

print(findrank('acB'))
