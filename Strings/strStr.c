#include<string.h>

/**
 * @input A : Read only ( DON'T MODIFY ) String termination by '\0'
 * @input B : Read only ( DON'T MODIFY ) String termination by '\0'
 * 
 * @Output Integer
 */
int strStr(const char* A, const char* B) {
    
    if(!B) return -1;
    
    if(!A && !B) return -1;
    
    int len_A = strlen(A);
    int len_B = strlen(B);
    
    if(len_A < len_B) return -1;
    
    int j,k;
    
    if(len_A == len_B){
        
        for(k=0;k<len_B;k++){
                
                if(A[k]!=B[k]){
                    return -1;
                }
        }
        return 0;
    }
    
    int found = 0;
    
    for(j=0;j<len_A-len_B;j++){
        
        if(A[j]==B[0]){
            
            for(k=j+1;k<len_B+j;k++)
            {
                if(A[k]!=B[k-j]){
                  found = 0;
                  break;  
                } 
                found = 1;
            }
            if(found)
            {
                return j;
            }
        }
    }
    
    return -1;
    
}
