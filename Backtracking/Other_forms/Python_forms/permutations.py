
#=================================================
#
#File Name 		: 1.py
#
#Purpose 		: A func() that returns all possible
#                         permutations of an array of unique integers
#
#Creation Date          : 22=2=008
#
#Last Modified          : Mon 22 Dec 2008 10:36:49 PM PST
#
#Created By             : Prathu Baronia, 14D070046 
#
#=================================================

class Solution:
    # @param A : list of integers
    # @return a list of list of integers
    def permute(self, A):
        
        # C = list(A)
        
        def permute_helper(start,end):
            if(start==end):
                result.append(list(B))
                return;
        
            for i in range(start,end+1):
                B[i],B[start] = B[start],B[i]
                permute_helper(start+1,end);
                B[i],B[start] = B[start],B[i]
                C = list(B)
                
        B = list(A)
        n1 = len(A)
        result = []
        permute_helper(0,n1-1);
        return result;

