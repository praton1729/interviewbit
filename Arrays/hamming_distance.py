

def hamming_distance_pairwise_sum(A):

    def hamming_distance(x,y):

        return bin(x^y).count('1')

    hamming_sum = sum([hamming_distance(x,y) for x in A for y in A])

    return hamming_sum

def hamming_distance_pairwise_alter(A):

    n = len(A)

    c = 0

    for I in range(32):

        mask = 1 << I

        t = 0

        for a in A:

            if(mask&a):

                t = t+1

        c = c + (t*(n-t))

    return (2*c)%1000000007


A = [2,4,6]
print hamming_distance_pairwise_alter(A)            


        

    



