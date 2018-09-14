
/*=========================================

* File Aame : integer_to_roman.c

* Purpose :	Convert an integer between 1 and 
			3999 to its roman numeral form

* Creation Date : 14-09-2018

* Last Modified : Mon 22 Dec 2008 10:36:49 PM PST

* Created By : Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

int sub_digit(char num_1, char num_2, int i, char* c){

	c[i++] = num_1;
	c[i++] = num_2;

	return i;
}

int digit(char num,int n, int i, char* c){
	
	int j;

	for(j=0;j<n;j++){
		c[i++] = num;
	}

	return i;
}

void print_roman(int A){

		char* c = (char*) malloc(10001*sizeof(char*));
		int i = 0;

		if(A<=0) return ;

		while(A!=0){

				if(A>=1000){

						i = digit('M', A/1000, i, c);
						A = A%1000;
				}
				else if(A>=500){


						if(A<900){

								i = digit('D',A/500,i,c);
								A = A%500;

						}
						else{
								i = sub_digit('C','M',i,c);
								A = A%100;

						}
				}

				else if(A>=100){

						if(A<400){

								i = digit('C',A/100,i,c);
								A = A%100;

						}
						else{

								i = sub_digit('C','D',i,c);
								A = A%100;
						}

				}

				else if(A>=50){

						if (A < 90) 
						{ 
								i = digit('L', A/50,i,c); 
								A = A%50; 
						} 

						else
						{ 
								i = sub_digit('X','C',i,c); 
								A = A%10; 
						} 

				}else if (A >= 10) 
				{ 
						if (A < 40) 
						{ 
								i = digit('X', A/10,i,c); 
								A = A%10; 
						} 

						else
						{ 
								i = sub_digit('X','L',i,c); 
								A = A%10; 
						} 
				} 

				else if (A >= 5) 
				{ 
						if (A < 9) 
						{ 
								i = digit('V', A/5,i,c); 
								A = A%5; 
						} 

						else
						{ 
								i = sub_digit('I','X',i,c); 
								A = 0; 
						} 
				} 

				else if (A >= 1) 
				{ 
						if (A < 4) 
						{ 
								i = digit('I', A,i,c); 
								A = 0; 
						} 

						else
						{ 
								i = sub_digit('I', 'V', i, c); 
								A = 0; 
						} 
				} 


		}
	printf("Roman numeral is: "); 
	int j;
    for (j = 0; j < i; j++) printf("%c", c[j]); 

}

int main(int argc, char* argv)
{
	int sample = 3549;

	print_roman(sample);
	
	return 0;
}
