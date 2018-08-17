/**
 * @input x : Integer
 * @input n : Integer
 * @input d : Integer
 * 
 * @Output Integer
 */
int powmod(int x, int n, int d) {

    if(x==0)
    {
        return 0;
    }
    
    if(n==0){
        return 1;
    }
    
    long int x_1 = x%d;
    
    if(x_1<0)
    {
        x_1 += d;
    }
    
    long int p = 1;
    
    while(n>0)
    {
        if(n%2!=0)
        {
            p *= x_1;
            p = p%d;
            n = n-1;
        }
        
        n /=2;
        x_1 = (x_1*x_1)%d;
    }
    
    return p;
    
}

