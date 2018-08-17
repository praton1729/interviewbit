

def col2num(A):

    num = 0

    for c in A:

        num = num*26 + ord(c) - ord('A') +1

    return num

def num2col(A):

    n = A

    string = ""
    
    while n > 0:

        n,remainder = divmod(n-1,26)

        string = chr(65+remainder) + string 
    
    return string

print(col2num('AB'))

print(num2col(703))
