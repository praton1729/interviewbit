
#=================================================
#
#File Name 		: 1.py
#
#Purpose 		: A func() that returns nCr sets
#
#Creation Date  : 22=2=008
#
#Last Modified  : Mon 22 Dec 2008 10:36:49 PM PST
#
#Created By     : Prathu Baronia, 14D070046 
#
#=================================================

class Solution:
    # @param A : integer
    # @param B : integer
    # @return a list of list of integers
    def combine(self, A, B):
        
        def combination_util(array, start,end, index):
            if(index==B):
                # print(temp)
                result.append(list(temp))
                return;
                
            i=start
            while(i<=end and end-i+1 >= B - index):
                temp[index] = array[i]
                combination_util(array,i+1,end,index+1)
                i = i + 1
        
        n = A
        array = range(1,n+1)
        temp = [0]*B
        result = []
        combination_util(array, 0,n-1, 0)

        return result
                

