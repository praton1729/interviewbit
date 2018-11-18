
/*=========================================

* File Name		:	commutable_islands.c

* Purpose		:

* Creation Date	:	18-11-2018

* Last Modified	:	Sunday 18 November 2018 08:11:11 PM IST

* Created By	: 	Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

/**
 * @input A : Integer
 * @input B : 2D integer array 
 * @input n21 : Integer array's ( B ) rows
 * @input n22 : Integer array's ( B ) columns
 * 
 * @Output Integer
 */

void print_matrix(int** A, int rows, int cols)
{
		int i,j;
		printf("{");
		for(i=0;i<rows;i++)
		{
				printf("{");
				for(j=0;j<cols;j++)
				{
						printf("%d,",A[i][j]);
				}
				printf("}");
				printf("\n");
		}
		printf("}");
		printf("\n");
		return;
}

int min_key(int* key, int* mst_set, int number_of_nodes)
{
		int min = INT_MIN;
		int min_index;
		int v;

		for(v=0;v<number_of_nodes;v++)
		{
				if(mst_set[v]==0 && key[v] < min)
				{
						min = key[v];
						min_index = v;
				}
		}
		return min_index;
}

int min_cost_spanning_tree(int** graph, int number_of_nodes)
{
		int* key = (int*) malloc(number_of_nodes*sizeof(int));
		int* mst_set = (int*) malloc(number_of_nodes*sizeof(int));
		int* parent = (int*) malloc(number_of_nodes*sizeof(int));

		int i;

		for(i=0;i<number_of_nodes;i++)
		{
				key[i] = INT_MAX;
				mst_set[i] = 0;
		}
		key[0] = 0;
		parent[0]=-1;

		int count,sum=0;
		int u,v;

		for(count=0;count<number_of_nodes-1;count++)
		{
				u = min_key(key,mst_set,number_of_nodes);
				mst_set[u] = 1;
				for(v=0;v<number_of_nodes;v++)
				{
						if(graph[u][v] && mst_set[v]==0 && graph[u][v]<key[v])
						{
								key[v] = graph[u][v];
								parent[v] = u; 
						}
				}
		}
		for(i=1;i<number_of_nodes;i++)
		{
				sum += graph[i][parent[i]];
				printf("%d-%d\t%d\n",parent[i],i,graph[i][parent[i]]);
		}
		return sum;
}

int** make_adjacency_matrix(int A, int** B, int n21, int n22)
{
		int** adjacency_matrix_B = (int**) malloc(A*sizeof(int*));
		int i,j;

		for(i=0;i<A;i++) adjacency_matrix_B[i] = (int*) malloc(A*sizeof(int));

		for(i=0;i<A;i++)
		{
				for(j=0;j<A;j++)
				{
						adjacency_matrix_B[i][j] = 0;
				}
		}

		int start_node,end_node, edge_weight;

		for(i=0;i<n21;i++)
		{
				start_node = B[i][0] - 1;
				end_node = B[i][1] - 1;
				edge_weight = B[i][2];

				adjacency_matrix_B[start_node][end_node] = edge_weight;
				adjacency_matrix_B[end_node][start_node] = edge_weight;
		}
		return adjacency_matrix_B;
}

int solve(int A, int** B, int n21, int n22)
{
		int** adjacency_matrix_B = (int**) malloc(A*sizeof(int*));
		int i,j;

		for(i=0;i<A;i++) adjacency_matrix_B[i] = (int*) malloc(A*sizeof(int));

		adjacency_matrix_B = make_adjacency_matrix(A, B, n21, n22);
		// print_matrix(adjacency_matrix_B,A,A);

		int min_cost = min_cost_spanning_tree(adjacency_matrix_B, A);

		return min_cost;
}

int main(int argc, char* argv)
{
		return 0;
}
