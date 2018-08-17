

def max_gap(A):

    arr = []

    for index,I in enumerate(A):

        arr.append((I,index))

    arr.sort()

    current = arr[0][1]

    diff = -1

    for I in arr:

        if I[1]<current:
            
            current = I[1]

        else:
            
            if I[1]-current > diff:
                
                diff = I[1] - current

    print arr
    return diff


A = [3,5,4,2]

print(max_gap(A))
