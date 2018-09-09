#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* concat(char* x, char* y)
{
	char* result = malloc(strlen(x) + strlen(y)+1);

	strcpy(result,x);
	strcat(result,y);

	return result;

}

char* count_and_say(int A)
{

	if(A==1) return "1";
	if(A==2) return "11";

	char* prev = "11";

	char* dummy = "$";

	int i;	


	for(i=3;i<=A;i++)
	{		

		prev = concat(prev,dummy);
		//printf("prev is %s and len is %zu \n",prev,strlen(prev));

		int len = strlen(prev);

		int count = 1;

		char* tmp = "";
		int j;

		for(j=1;j<len;j++)
		{
			if(prev[j]!=prev[j-1]){
			
				char count_tmp[2];
				count_tmp[0] = count+'0';
				count_tmp[1] = '\0';
				//printf("tmp ke saath count_tmp concat %s \n",count_tmp);
				tmp = concat(tmp,count_tmp);
				
				char prev_tmp[2];
				prev_tmp[0] = prev[j-1];
				prev_tmp[1] = '\0'; 
				//printf("tmp ke saath prev concat %s \n",prev_tmp);
				
				tmp = concat(tmp,prev_tmp);
				count = 1; 			

			}
			else count++;
			
		}
		
		prev = tmp;
		//free(tmp);
	}

	return prev;

}

int main(int argc, char* argv[])
{

//	char* sample_1 = "one";
//	char* sample_2 = "t";
//
//	char* result = concat(sample_1,sample_2);
//
//	printf("String is : %s of length %zu \n",result,strlen(result));
//
//	result[strlen(result)-2] = '\0';
//
//	printf("String is : %s of length %zu \n",result,strlen(result));

	printf("Function ouptut : %s\n",count_and_say(atoi(argv[1])));
}
