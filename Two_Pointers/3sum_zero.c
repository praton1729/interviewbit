
/*=========================================

* File Name : 3sum_zero.c

* Purpose 	: Finds the triplets with zero sum
			  in the input integer array.	

* Creation Date : 21-09-2018

* Last Modified : Friday 21 September 2018 04:47:32 AM IST

* Created By : Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row, len2 as columns 
 */
 
int compare(const void* a, const void* b){
        return (*(int*)a - *(int*)b);
}

void append_in_matrix(int** matrix, int row_index, int x, int y, int z){
    matrix[row_index][0] = x;
    matrix[row_index][1] = y;
    matrix[row_index][2] = z;
}

int ** threeSum(int* A, int n1, int *len1, int *len2) {
        
        *len1 = 0; //rows
        *len2 = 3; //cols
        
        int min_input_length = 3;

        if(n1 < min_input_length) return NULL;

        qsort(A, n1, sizeof(int), compare);

        int temp_sum;
        
        /****/ 
        //Memory allocation for 2D array
        int** result_matrix = (int**) malloc(sizeof(int*)*n1);
        int index;
        for(index=0; index<n1; index++) result_matrix[index] = (int*) malloc(sizeof(int)*3);
        /****/
        
        int i,j,k,row_index=0;

        for(i=0;i<n1-1;i++){
                j = i+1;
                k = n1-1;

                while(j<k){
                        temp_sum = A[i]+A[j]+A[k];
                        if(temp_sum==0){ 
                            append_in_matrix(result_matrix, row_index, A[i], A[j], A[k]);
							printf("Found triplet : %d %d %d\n",A[i],A[j],A[k]);
                            (*len1)++;
                            row_index++;  
							j++,k--; 
                        }   
                        else if(temp_sum < 0) j++;
                        else k--;
                }

        }

        return result_matrix;

}

int main(int argc, char* argv)
{
	int* len1 = (int*)malloc(sizeof(int)); 
	int* len2 = (int*)malloc(sizeof(int));

	int A[] = {1, -4, 0, 0, 5, -5, 1, 0, -2, 4, -4, 1, -1, -4, 3, 4, -1, -1, -3};//{-1,0,1,2,-1,-4};

	threeSum(A,6,len1,len2);
	return 0;
}
