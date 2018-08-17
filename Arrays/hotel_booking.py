

def hotel(arrive,depart,K):


    I = []

    for i in range(len(arrive)):

        I.append([arrive[i],depart[i]])

    I = sorted(I)

    for i in range(len(I)):

        arrive[i] = I[i][0]
        depart[i] = I[i][1]
   
     
    def rooms_occupied(arrive,depart,i):

        rooms_occupied = sum( j > arrive[i] for j in depart[0:i]) + 1
            
        return rooms_occupied


    for i in range(1,len(arrive)):
        
        if(K < rooms_occupied(arrive,depart,i)):
    
            return 0
            break
    
    return 1
    #print("%d \n"%rooms_occupied(arrive,depart,i))


arrive = [40,18]

depart = [40,43]

K = 1

print(hotel(arrive,depart,K)) 
