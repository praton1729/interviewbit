
/*=========================================

* File Name		:	commutable_islands.c

* Purpose		:	Interviewbit's solution to 
					commutable island's problem.	

* Creation Date	:	18-11-2018

* Last Modified	:	Sunday 18 November 2018 08:47:12 PM IST

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

typedef struct node
{
		int x,y;
		int cost;
}node;

node graph[100005];
int parent[100005],rank[100005];

int cmp(const void * a, const void * b)
{

		node *orderA = (node *)a;
		node *orderB = (node *)b;
		return ( orderA->cost - orderB->cost );
}

int find(int x)
{
		if(parent[x]!=x)
				parent[x]=find(parent[x]);
		return parent[x];
}
void union_set(int x,int y)
{
		int xroot=find(x);
		int yroot=find(y);
		//Attach smaller rank tree under higher rank tree
		if(rank[xroot]>rank[yroot])
				parent[yroot]=xroot;
		else if(rank[yroot]>rank[xroot])
				parent[xroot]=yroot;
		else
		{
				parent[xroot]=yroot;
				rank[xroot]++;
		}
}
int kruskal(int R)
{

		int ret = 0;
		qsort(graph,R,sizeof(node),cmp);
		int i;
		for(i=0;i<R;i++)
		{
				int x=find(graph[i].x);
				int y=find(graph[i].y);
				if(x!=y)
				{
						ret += graph[i].cost;
						union_set(x,y);
				} 
		}
		return ret;
}
int solve(int A, int** B, int n21, int n22) {
		int R = n21, C = n22;
		int i;
		for(i=1;i<=A;i++)
		{
				parent[i] = i;
				rank[i] = 0;
		}
		for(i=0;i<R;i++)
		{
				int u = B[i][0], v = B[i][1], cost = B[i][2];
				graph[i].x = u, graph[i].y = v, graph[i].cost = cost;
		}
		return kruskal(R);
}
int main(int argc, char* argv)
{
		return 0;
}
