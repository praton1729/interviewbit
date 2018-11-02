
#=================================================
#
#File Name 		: 1.py
#
#Purpose 		:
#
#Creation Date  : 22=2=008
#
#Last Modified  : Mon 22 Dec 2008 10:36:49 PM PST
#
#Created By     : Prathu Baronia, 14D070046 
#
#=================================================

def combination_sum(A,T):
    
    if(T==0):
        return []

    if(T<0 or len(A)==0):
        return None

    n = len(A)
    B = combination_sum(A[0:n-1],T)

    if(B!=None):
        result.append(B)
        #return B

    B = combination_sum(A,T-A[n-1])

    if(B!=None):
        B.append(A[n-1]) 
        result.append(B)

    return None

class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return a list of list of integers
    def combinationSum(self, A, B):
        
        def find_sets(arr,sum,temp,i):
            if(sum<0):
                return ;
            if(sum==0):
                result.append(temp)
                return;
            while(i<len(arr) and sum-arr[i]>=0):
                temp.append(arr[i])
                find_sets(arr,sum-arr[i],list(temp),i)
                i = i+1
                temp.pop()
            
        A = sorted(A)
        ## later remove duplicates
        A = list(set(A))
        result = []
        temp = []
        find_sets(A,B,temp,0)
        # sorted(result)
        return result

result = []
A = [2,3,6,7]
T = 7

print(combination_sum(A,T))
