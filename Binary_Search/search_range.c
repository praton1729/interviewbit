
/*=========================================

* File Name : search_range.c

* Purpose :

* Creation Date : 12-09-2018

* Last Modified : Friday 14 September 2018 08:28:33 PM IST

* Created By : Prathu Baronia 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
 
int my_ceil(const int* A, int low, int high, int B){
   
   if(B<=A[low]) return low;  

   int mid = (low+high)/2;
   
   if(A[mid]==B){
     return mid;  
   } 
   else if(A[mid]<B){
       if(mid+1<=high && B<=A[mid+1]) return mid+1;
       else return my_ceil(A, mid+1, high, B);
   }
   else{
       if(mid-1>= low && B>A[mid-1]) return mid;
       else return my_ceil(A, low, mid-1, B);
   }
}

int my_floor(const int* A, int low, int high, int B){
   
   if(B >= A[high]) return high;

   int mid = (low+high)/2;
   
   if(A[mid]==B){
     return mid;  
   } 
   
   if(mid>0 && A[mid-1] <= B && B < A[mid]){
       return mid-1;
   }
   
   if(B < A[mid]) return my_floor(A, low, mid-1, B);
   
   return my_floor(A, mid+1, high, B);
}

int binary(const int *A,int n1,int B,int key)
{
  int low=0,high=n1-1;
  int result=-1;
  while(low<=high)
  {
      int mid=(low+high)/2;
      if(A[mid]==B)
        {
            result=mid;
            if(key)
                low=mid+1;
            else
                high=mid-1;
        }
       else if(A[mid]<B)
            low=mid+1;
       else 
            high=mid-1;
  }
  return result;
}

int* searchRange(const int* A, int n1, int B, int *len1) {
    int *arr=(int *)malloc(sizeof(int)*2);
    int l=binary(A,n1,B,0);
    int r=binary(A,n1,B,1);
    arr[0]=l;
    arr[1]=r;
    *len1=2;
    return arr;
}

int main(int argc, char* argv)
{

	int n1 = 1;
	int* A = malloc(sizeof(int)*n1);
	int* result = (int*)malloc(sizeof(int)*2);
	int* len1;

	A[0] = 1;

	int B = 1;

	printf("ceil of %d in A is : %d \n",B,my_ceil(A,0,n1-1,B));   
	printf("floor of %d in A is : %d \n",B,my_floor(A,0,n1-1,B));

	result = searchRange(A, n1, B, len1);

	printf("result is : [%d,%d]\n",result[0],result[1]);

	free(result);

	return 0;
}
