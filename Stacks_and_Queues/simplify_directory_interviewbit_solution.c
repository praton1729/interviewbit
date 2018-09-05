#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * @input A : String termination by '\0'
 * 
 * @Output string. Make sure the string ends with null character
 */

char* simplifyPath(char* A) {

    int t = 0, c = 1, p = 1, op;

    for (;; c++) {

        if (A[c] == 0 || A[c] == '/') {

            op = p;
            p = c + 1;

            if (c - op == 2 && A[op] == '.' && A[op+1] == '.') {
                if (t) t--;
                while (A[t] != '/') t--;
                goto cont;
            } 
	    else if (c - op == 1 && A[op] == '.') {
                goto cont;
            }
            if (op < c) {
                A[t++] = '/';
                while (op < c && A[op] != '/') {
                    A[t++] = A[op++];
                }
            }
        }
        cont:
        if (!A[c]) break;
    }
    A[t ? t : 1] = '\0';
    return A;
}

int main(){

char path[100];

scanf("%s",path);

printf("%s\n",simplifyPath(path));

return 0;
}
