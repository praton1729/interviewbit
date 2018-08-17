#from __future__ import division

def repeated_number(number_array):
    
    pair_A_B = []
    
    n = len(number_array)

    for i in number_array:
        if(number_array.count(i)==2):
          pair_A_B.append(i)
          break
  
    sample = range(1,n+1)
    
    diff = list(set(sample)-set(number_array))

    pair_A_B.append(diff[0])

    return pair_A_B


def square_list(A):

    return [i**2 for i in A]


def repeated_number_alternative(number_array):
    
    pair_A_B = []
    
    n = len(number_array)
    
    sum_array = sum(number_array)

    natural_sum = n*(n+1)//2

    diff = sum_array-natural_sum # A-B

    square_sum_array = sum(square_list(number_array))

    natural_square_sum = n*(n+1)*(2*n+1)//6

    square_diff = square_sum_array - natural_square_sum # A^2 - B^2

    A_plus_B = square_diff // diff

    A = (A_plus_B + diff)//2
    B = (A_plus_B - diff)//2

    pair_A_B = [A,B]
    return pair_A_B


sample_input = [3,1,2,3,5]

print(repeated_number_alternative(sample_input))      
