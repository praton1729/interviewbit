
/*=========================================

* File Name : compare_version.c

* Purpose : compares two provided version strings 
			similar to a generic compare function

* Creation Date : 14-09-2018

* Last Modified : Mon 22 Dec 2008 10:36:49 PM PST

* Created By : Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * @input A : String termination by '\0'
 * @input B : String termination by '\0'
 * 
 * @Output Integer
 */

int compareVersion(char* A, char* B) {
    
    long double vnum_1 = 0;
    long double vnum_2 = 0;
    
    int i,j;
    
    for(i=0,j=0; (i < strlen(A) || j < strlen(B));){
        
        while( i < strlen(A) && A[i]!='.'){
            vnum_1 = vnum_1*10 + (A[i]-'0');
            i++;
        }
        
        while( j < strlen(B) && B[j]!='.'){
            vnum_2 = vnum_2*10 + (B[j]-'0');
            j++;
        }
        
        if(vnum_1 > vnum_2){
            return 1;
        }
        if(vnum_1 < vnum_2){
            return -1;
        }
        
        vnum_1 = vnum_2 = 0;
        i++;
        j++;
    }
    
    return 0;
}

int main(int argc, char* argv)
{

	return 0;
}
