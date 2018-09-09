#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char** prettyJSON(char* A, int *len1) {
    
    int len_A = strlen(A);
    int i;
    int indents = 0;
    int not_indented = 1;
				
    char** result = (char**)malloc(sizeof(char)*len_A);

	for(i=0;i<len_A;i++)
	{

		char s = A[i];
	}		
    return result;
    
}


int main(){

	char* A = "[\"foo\", {\"bar\":[\"baz\",null,1.0,2]}]";//"{\"id\":100,\"firstName\":\"Jack\",\"lastName\":\"Jones\",\"age\":12}";

	int* len1;

	system("clear");
	
	prettyJSON(A,len1);
	
	return 0;
}

