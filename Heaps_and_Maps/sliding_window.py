
#=================================================
#
#File Name 	: sliding_window.py
#
#Purpose 	:
#
#Creation Date  : 22=2=008
#
#Last Modified  : Mon 22 Dec 2008 10:36:49 PM PST
#
#Created By     : Prathu Baronia, 14D070046 
#
#=================================================

def sliding_window(A,k):
    
    res = []
    n = len(A)
    final_index = n- k
    
    d = {}
    dist_count = 0

    for i in A[0:k]:
        if(str(i) in d):
            d[str(i)] = d[str(i)] + 1
        else:
            d[str(i)] = 1;
            dist_count = dist_count + 1
    
    res.append(dist_count) 
     
    for i in range(k,n):

        count_i = d[str(A[i-k])] 

        if(count_i==1):
            d[str(A[i-k])] = 0
            dist_count = dist_count - 1 
        else:
            d[str(A[i-k])] = count_i-1
        
        new_element_index = i

        key = str(A[new_element_index]) 

        if(key in d):
            d[key] = d[key] + 1
            if(d[key]==1):
                dist_count = dist_count + 1 
        else:
            d[key] = 1;
            dist_count = dist_count + 1 

        res.append(dist_count) 

    return res


A = [1,2,1,3,4,2,3]
k = 4

print(sliding_window(A,k))
