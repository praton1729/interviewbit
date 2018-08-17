/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
 #define max(a,b) (a>b?a:b)
 #define min(a,b) (a>b?b:a)
 
int diffPossible(int* A, int n1, int B) 
{
    int left = 0;
    int right = 1;

    while(left< n1 && right < n1)
    {
            if((*(A+right) - *(A+left))==B && left!=right)
            {
                return 1;            
            }
            else if(*(A+right) - *(A+left) > B){
                left++;
            }
            else
            {
                right++;
            }
    }
    return 0;
}

