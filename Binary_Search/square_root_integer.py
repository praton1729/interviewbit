
def sqrt(A):
    
        if(A==0 or A==1):
            return A
            
        start = 1
        end = A
        
        while start<=end:
            
            mid = (start+end)//2
            
            if(mid**2==A):
                return mid
                
            if(mid**2 < A):
                
                start = mid +1
                ans = mid
                
            else:
                
                end = mid-1
        
        return ans

print sqrt(100000)
