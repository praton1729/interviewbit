

def generate(A):

    init = [1]
    
    init_2=[1,1]

    def give_row(row):

        ret_row = [1]*(len(row)+1)

        for i in range(1,len(row)):

            ret_row[i] = row[i] + row[i-1]

        return ret_row  

    if(A==0):

        return []

    if(A==1):

        return [init]

    elif(A==2):

        return [init,init_2]

    else:

        B = [init,init_2]
        
        row = init_2
        
        for i in range(1,A-1):
            row = give_row(row)
            B.append(row)

        return B 

A = 1

print(generate(A)) 
