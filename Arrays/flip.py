
def flip(A):
    
    if(A.count('0')==0):
        return []

    n = len(A)
    max_ones = A.count('1')
    pairs_array = []
    def count_ones(A,i,j):
        
        #Count 1s from 0 to i-1
        #Count 0s from i to j
        #Count 1s from j+1 to n-1
        return (A[0:i].count('1') + A[i:j+1].count('0') + A[j+1:n].count('1'))
        
    for i in range(0,n-1):
        for j in range(i,n):
            ones_count = count_ones(A,i,j)
            max_ones = max(max_ones,ones_count)
            

    for i in range(0,n-1):
        for j in range(i,n):
            ones_count = count_ones(A,i,j)
            if(max_ones == ones_count):
                pairs_array.append([i+1,j+1])       
            print("Ones_count : %d \n" % ones_count)
            
    def lexographically_smaller(a,b):
                if(a[0] < b[0]):
                    return a
                elif(a[0]==b[0] and a[1] < b[1]):
                    return a
                else:
                    return b
    
    lex_pair = pairs_array[0]
    n = len(pairs_array)
    for j in range(1,n):
        
        lex_pair = lexographically_smaller(pairs_array[j],lex_pair)

    return lex_pair

S = "1101"


print(flip(S))
