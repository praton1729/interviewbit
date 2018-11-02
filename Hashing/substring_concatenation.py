
#=================================================
#
#File Name 		: substring_concatenation.py
#
#Purpose 		: A func() that returns the indices of 
#                         substrings in a string which are formed 
#                         by concatenating a given list of strings
#                         in any order.
#
#Creation Date  : 22=2=008
#
#Last Modified  : Mon 22 Dec 2008 10:36:49 PM PST
#
#Created By     : Prathu Baronia, 14D070046 
#
#=================================================

class Solution:
    # @param A : string
    # @param B : tuple of strings
    # @return a list of integers
    def findSubstring(self, A, B):
        
        def valid_substring(X, Y):
            
            d = {}
            for i in Y:
                d[i] = 0
            
            temp = {}
            for i in Y:
                temp[i] = 0
        
            for i in Y:
                d[i] = d[i] + 1
            
            step = len(Y[0])
            
            for j in range(0,len(X),step):
                word = X[j:j+step]
                if(word in d):
                    temp[word] = temp[word]+1
                else:
                    return 0
            
            for i in d:
                if(d[i] != temp[i]):
                    return 0
                    
            return 1
        
        substring_length = len(B)*len(B[0])
        
        result = []
        
        for i in range(0,len(A)):
            
            if(i+substring_length <= len(A)):
                substring = A[i:i+substring_length];
            
                if(valid_substring(substring,B)):
                    result.append(i)
        
        return result
