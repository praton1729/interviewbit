


def trail_zeros(A):

    n = A

    i = 5

    count_5 = 0

    while(n/i >= 1):

        count_5 = count_5 + int(n//i)
        i = i*5

    return count_5

print(trail_zeros(9247))
