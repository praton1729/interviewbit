
#=========================================
#
# File Name : anagrams.py
#
# Purpose   : Prints out a tuple giving out
#             anagarams together
#
# Creation Date : 18-10-2018
#
# Last Modified : Mon 22 Dec 2008 10:36:49 PM PST
#
# Created By : Prathu Baronia, 14D070046 
#
#==========================================

class Solution:
    # @param A : tuple of strings
    # @return a list of list of integers
    
    def anagrams(self, A):
    
        def check_anagram(x,y):
            
            if(len(x)!=len(y)):
                return 0
            
            x_sorted = sorted(x);
            y_sorted = sorted(y);
                
            if(x_sorted==y_sorted):
                return 1
            else:
                return 0
        d = {}
        
        result = []
        flags = [0]*len(A)
        
        for i in range(len(A)):
            i_sorted = sorted(A[i])
            i_sorted_string = ''.join(i_sorted)
            
            if(i_sorted_string in d):
                d[i_sorted_string].append(i+1)
            else:
                d[i_sorted_string] = [i+1]
        
        for i in d.keys():
            result.append(d[i])
        return result

