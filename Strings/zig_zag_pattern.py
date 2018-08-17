
class Solution:
    # @param A : string
    # @param B : integer
    # @return a strings
    def convert(self, A, B):
        
        if(B == 1):
            return A
            
        n = B
        
        row = 0
        down = 1
        
        string_array = ['']*B
        
        for i in A:
            
            string_array[row] = string_array[row] + i
            
            if(row==n-1):
                
                down = 0
                
            elif(row==0):
                
                down = 1
                
            if(down):
                
                row = row + 1
                
            else:
                
                row = row - 1
                
        concat = ''.join(string_array)
        
        return concat
            
a = Solution()

print a.convert('tatti',2)        

