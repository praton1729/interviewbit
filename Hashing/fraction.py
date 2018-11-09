
#=================================================
#
#File Name 		: 1.py
#
#Purpose 		: A func() that return a decimal 
#                          string from a fraction
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
    # @return a strings
        
    def fractionToDecimal(self, A, B):
        
        def fractional_part(A,B):
        
            rem = abs_A%abs_B
            d = []
            res = ""
            
            while(rem!=0 & ~(rem in d)):
                d.append(rem)
                rem = rem*10
                res = res + str(rem//B)
                rem = rem%B
            
            if(rem==0):
                return res
            else:
                return ("(" + res + ")")
        
        if(A==0):
            return 0
        
        sign = 1
        
        if((A<0)^(B<0)):
            sign = -1
        
        abs_A = abs(A)
        abs_B = abs(B)
        
        integer_part = abs_A//abs_B
        
        res = ""
        if(sign==-1):
            res = "-" + str(integer_part)
        else:
            res = "" +  str(integer_part)
        
        res = res + fractional_part(abs_A,abs_B)
        
        return res

