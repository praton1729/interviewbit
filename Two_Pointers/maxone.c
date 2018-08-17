/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* maxone(int* A, int n1, int B, int *len1) {
    
    int left = 0;
    int right = 0;
    
    int best_window_left = 0;
    int best_window_length = 0;
    
    int zeroCount = 0;
    
    while(right<n1)
    {
        if(zeroCount<=B)
        {
            if(*(A+right)==0)
            {
                right++;
                zeroCount++;
            }
        }
        if(zeroCount>B)
        {
            if(*(A+left)==0)
            {
                left++;
                zeroCount--;
            }
        }
        
        if(right-left > best_window_length)
        {
            best_window_length = right-left;
            best_window_left = left;
        }
    }
    
    len1 = malloc(sizeof(int*)*best_window_length);
    
    int j = 0;
    
    for(j=0;j<best_window_length;j++,*(len1+j) = best_window_left+j);
    
    return len1;
}

