#include<math.h>
#include<stdio.h>
#include<stdlib.h>

int square_root_int(int A){

  	if(A==0||A==1){
            	printf("Entering here");
		return A;
	}
            
        int start = 1;
        int end = A;
        int mid = 0;
	int ans = 0;

        while(start<=end){
            
           mid = (start+end)/2;
            
            if(mid*mid==A)
		{
               	 return mid;
                }

            if(mid*mid < A){
                
                start = mid +1;
                ans = mid;
            }    
            else{
                
                end = mid-1;
		}
        }
	return ans;

}
int main(){

	int a;

	scanf("%d",&a);

	printf("%d",square_root_int(a));
}

