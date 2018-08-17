


def sieve_of_erastothenes(A):

    isPrime = [True]*(A+1)

    isPrime[0]=isPrime[1]=False

    p = 2

    while(p*p<=A):

        if(isPrime[p]==True):

            i = 2*p

            while(i<=A):

                isPrime[i]=False
                i = i +p
        p = p +1

    return isPrime

def list_of_primes(isPrime):

    B = []

    for i in range(len(isPrime)):
    
        if(isPrime[i]==True):
    
            B.append(i)

    return B

def find_prime_pair(A,isPrime):

    for i in range(len(isPrime)):

        if(isPrime[i] and isPrime[A-i]):

            return [i,A-i]
            break

A = 74

isPrime = sieve_of_erastothenes(A)

print(list_of_primes(isPrime))

print(find_prime_pair(A,isPrime))




    
