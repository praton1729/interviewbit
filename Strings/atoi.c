#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

//#include<.h>
/**
 * @input A : Read only ( DON'T MODIFY ) String termination by '\0'
 * 
 * @Output Integer
 */

#define ERROR() {printf("ERROR at line : %d\n",__LINE__);}
 
int is_numeric_char(char s){
     return (s<='9' && s>='0') ? 1:0;
 }
 
int atoi_custom(const char* A) {
    
    if(A == NULL){
        return 0;
    }
    
    int ret = 0;
    int i = 0;
    int sign = 1;
    
    while(A[i]==' '){
        i++;
    }
    if(A[i]=='-'){
        sign = -1;
        i++;
    }

   while(is_numeric_char(A[i]))
    {
            if (ret > INT_MAX/10 || (ret == INT_MAX/10 && A[i] - '0' > 7))
            {
                    if (sign == 1) 
                    {
                        return INT_MAX;
                    }
                    else 
                    {
                        return INT_MIN;
                    }
            }
            
        ret = ret*10 + (A[i++] - '0');
    }
  
    return ret*sign;
}

int main(){

	char* sample= "5121478262 8070067M75";

	int ret = atoi_custom(sample);

	system("clear");
	printf("func output : %d\n",ret);
	
//	printf("%d\n",INT_MIN);

return 0;
}
