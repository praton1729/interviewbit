

# Not time efficient

def diff_bits_sum(A):

    def diff_bits_pair(x,y):

        return bin(x^y).count('1')


    ret = sum([diff_bits_pair(x,y) for x in A for y in A])

    return ret%1000000007


# Time efficient 

def diff_bits_sum_alter(A):

	n = len(A)
	
	ret = 0
        
	for i in range(32):
            
        	count = 0
            
		for j in A:
                
                	if( j & (1<<i) ):
                    
				count = count+1
		ret = ret + 2*count*(n-count)
        
	large_prime = 10**9 + 7

        return ret%large_prime 

A = [1,3,5]
print diff_bits_sum_alter(A)
