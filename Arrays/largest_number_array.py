

def largest_number(A):

    def my_cmp(a,b):

        ab = str(a) + str(b)

        ba = str(b) + str(a)

        return cmp(int(ba),int(ab))


    A_sorted = sorted(A,cmp = my_cmp)

    return ("".join([str(i) for i in A_sorted]))

A = [3,34,30,5,9]

print(largest_number(A))
