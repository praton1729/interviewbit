
def gcd(a,b):
        
        if(b==0):
            
            return a
            
        else:
            
            return gcd(b,a%b)
    

def cpFact(A, B):
    
        for i in range(A,0,-1):
        
        	if(A%i==0 and gcd(i,B)==1):
            
            		return i
           

print(cpFact(30,12)) 
