
/*=========================================

* File Name		:	bfs.c

* Purpose		:	A func() that performs
					bfs on a given graph.

* Creation Date	:	21-11-2018

* Last Modified	:	Mon 22 Dec 2008 10:36:49 PM PST

* Created By	: 	Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#include "graph.h"

int main(int argc, char* argv)
{	
	int nodes = 5;
	
	//int* source = (int*) malloc(nodes*sizeof(int));

	//int* sink = (int*) malloc(nodes*sizeof(int));

	node** sorted_list = (node**) malloc(nodes*sizeof(node*));

	int source[7] 	= {0,1,3,1,2,1,0};

	int sink[7] 	= {4,4,4,3,3,2,1};
	
	int n = sizeof(source)/sizeof(source[0]);
	
	sorted_list = make_adjacency_list(source,sink,n, nodes);

	print_adjacency_list(sorted_list, nodes);
	
	bfs(sorted_list,nodes,0);

	return 0;
}
