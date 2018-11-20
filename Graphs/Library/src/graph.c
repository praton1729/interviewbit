
/*=========================================

* File Name		:	graph.c

* Purpose		:	A library C file which
					gives utility functions for 
					graph operations.

* Creation Date	:	21-11-2018

* Last Modified	:	Wednesday 21 November 2018 03:42:03 AM IST

* Created By	: 	Prathu Baronia, 14D070046 

==========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#include "graph.h"

node* create_new_node(int number)
{
		node* new_node = (node*) malloc(sizeof(node));

		new_node->node_number = number;
		new_node->next = NULL;

		return new_node;
}

void add_edge(node** list, int source,int sink)
{
		node* insert_node = create_new_node(sink);

		node* temp = list[source];
		node* prev = NULL;

		while(temp !=NULL && (temp->node_number)<sink)
		{
				prev = temp;
				temp = temp->next;	
		}	

		if(temp==list[source])
		{
				insert_node->next = temp;

				list[source] = insert_node;
		}
		else
		{
				prev->next = insert_node;

				insert_node->next = temp;	
		}

		return;
}

node** make_adjacency_list(int* source, int* sink, int n, int nodes)
{
		int i;

		int source_node, sink_node;

		node** list = (node**) malloc(nodes*sizeof(node*));

		initialize_list(list,nodes);

		for(i=0;i<n;i++)
		{
				source_node = source[i];
				sink_node 	= sink[i];

				if(list[source_node]==NULL)
				{
						list[source_node] = create_new_node(sink_node);

						if(list[sink_node]==NULL)
						{
								list[sink_node] = create_new_node(source_node);
						}
						else
						{
								add_edge(list,sink_node,source_node);
						}
				}
				else
				{

						add_edge(list,source_node,sink_node);

						if(list[sink_node]==NULL)
						{
								list[sink_node] = create_new_node(source_node);
						}
						else
						{
								add_edge(list,sink_node,source_node);
						}
				}		
		}

		return list;
}

void initialize_list(node** sorted_list, int nodes)
{
		int i;

		for(i=0;i<nodes;i++) sorted_list[i] = NULL;

		return;
}

void print_adjacency_list(node** sorted_list, int nodes)
{
		int i;

		node* temp;

		for(i=0;i<nodes;i++)
		{
				temp = sorted_list[i];

				printf("%d ",i);

				while(temp!=NULL)
				{
						printf("%d ",temp->node_number);
						temp = temp->next;
				}

				printf("\n");
		}

		return;
}

void dfs_util(node** sorted_list,int* visited, int dfs_root)
{
		int node_index;

		visited[dfs_root] = 1;

		printf("Visited node : %d\n",dfs_root);

		node* temp = sorted_list[dfs_root];

		while(temp!=NULL)
		{
				node_index = temp->node_number;
				if(visited[node_index]==0) dfs_util(sorted_list,visited,node_index);		
				temp = temp->next;
		}

		return;
}	

void dfs(node** sorted_list,int nodes)
{
		int i;

		int* visited = (int*) malloc(nodes*sizeof(int));

		for(i=0;i<nodes;i++) visited[i] = 0;

		for(i=0;i<nodes;i++)
		{
				if(visited[i]==0) dfs_util(sorted_list,visited,i);	
		}

		return;
}
