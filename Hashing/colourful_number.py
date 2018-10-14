class Solution:
    # @param A : integer
    # @return an integer
    def colorful(self, A):
        
        str_A = str(A);
        mul = 1;
        d = {}
        
        for i  in range(len(str_A)):
            mul = 1;
            for j in range(i,len(str_A)):
                mul = mul*int(str_A[j]);
                #check for mul's existence in dict
                if(str(mul) in d):
                    return 0
                else:
                    d[str(mul)] = 1;
        return 1
            
