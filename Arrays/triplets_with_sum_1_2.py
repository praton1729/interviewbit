

def solve(A):

	A = [float(i) for i in A]

    	A = sorted(A)
	
	X = [i for i in A if i < 0.67]
        
	Y = [j for j in A if 0.67 <= j and j <=1]
        
        Z = [k for k in A if 1 < k and k < 2]
        
	#print X
	#print Y
	#print Z

	if(len(X)>=3 and sum(X[-3:]) >= 1):
		
		print("XXX")	
		return 1

	elif(len(X)>=2 and len(Z)>= 1 and X[0]+X[1]+Z[0] <= 2):
		
		print("XXZ")
		return 1

	elif(len(X)>=1 and len(Y)>= 2 and X[0]+Y[0]+Y[1] <= 2):
		
		print("XYY")
		return 1
	
	elif(len(X) >= 1 and len(Y) >= 1 and len(Z) >= 1 and X[0]+Y[0]+Z[0] <= 2):
		
		print("XYZ")
		return 1

	elif(len(X) >= 2 and len(Y) >= 1): #and X[-1] + X[-2] + Y[0] < 2):

                print("XXY")
            	max_sum = X[-1] + X[-2]            

            	for j in Y:

                	if(j > 1 - max_sum and j < 2 - max_sum):
                   		 return 1
                    
            	return 0 
		
#		return 1
#
#	elif(len(X) >= 2 and len(Y) >= 1 and X[0] + X[1] + Y[-1] > 1):
#		
#		return 1

	else:
		print("No case")	
		return 0

#    |X| >= 3 and Xmax(1) + Xmax(2) + Xmax(3) >= 1
#    |X| >= 2, |Z| >= 1, and Xmin(1)+Xmin(2)+Zmin(1) <= 2
#    |X| >= 1, |Y| >= 2, and Xmin(1)+Ymin(1)+Ymin(2) <= 2
#    |X| >= 1, |Y| >= 1, |Z| >= 1, and Xmin(1)+Ymin(1)+Zmin(1) <= 2
#    |X| >= 2, |Y| >= 1, and Xmax(1) + Xmax(2) + Ymin(1) < 2
#    |X| >= 2, |Y| >= 1, and Xmin(1) + Xmin(2) + Ymax(1) > 1)
#
#A = [0.7,0.6,0.8,1.2,0.4]
#A = [ "0.503094", "0.648924", "0.999298" ]
A = [ "2.671613", "1.239175", "2.575260", "0.021242", "1.894100", "0.148016", "0.341571" ]
print(solve(A))
         
