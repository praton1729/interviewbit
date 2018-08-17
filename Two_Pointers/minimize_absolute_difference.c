/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 * @input C : Integer array
 * @input n3 : Integer array's ( C ) length
 * 
 * @Output Integer
 */
 
 #define max(a,b) (a>b?a:b)
 #define min(a,b) (a>b?b:a)
 
 int maximum(int x, int y, int z)
 {
     return max(max(x,y),z);
 }
 
  int minimum(int x, int y, int z)
 {
     return min(min(x,y),z);
 }
int solve(int* A, int n1, int* B, int n2, int* C, int n3) {
    
    int diff = 0;
    int i,j,k = 0;
    
    diff = maximum(*A,*B,*C) - minimum(*A,*B,*C);
    
    while(i < n1 && j < n2 && k < n3)
    {
        int max = maximum(*(A+i), *(B+j), *(C+k));

        int min = minimum(*(A+i), *(B+j), *(C+k));
        
        if (min == *(A+i))
            i++;
        else if (min == *(B+j))
            j++;
        else
            k++;

        if (diff > (max-min))
        {
            diff = max - min;
        }
    }
    return diff;
}
 
