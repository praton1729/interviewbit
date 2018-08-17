
def value(r):
        if (r == 'I'):
            return 1
        if (r == 'V'):
            return 5
        if (r == 'X'):
            return 10
        if (r == 'L'):
            return 50
        if (r == 'C'):
            return 100
        if (r == 'D'):
            return 500
        if (r == 'M'):
            return 1000
            
class Solution:
    # @param A : string
    # @return an integer
            
    def romanToInt(self, A):
        
        ret = 0
        last_counted = 0
        i = 0
        while i < len(A)-1:
            
            value_i = value(A[i])
            value_next_i = value(A[i+1])
            
            if(value_i >= value_next_i):
                
                ret = ret + value_i
                last_counted = 0
                i = i + 1
            else:
                
                ret = ret + value_next_i - value_i
                if(i==len(A)-2):
                    last_counted = 1
                else:
                    last_counted = 0
                i = i + 2
               
        if(not last_counted):
            ret = ret + value(A[-1])
                
        return ret
                
a = Solution()

print a.romanToInt('IV')                
