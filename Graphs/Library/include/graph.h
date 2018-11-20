#ifndef ___graph_h___
#define ___graph_h___

struct Node
{
	int node_number;
	struct Node* next;
};

typedef struct Node node;

node* create_new_node(int number);

void add_edge(node** list, int source,int sink);

node** make_adjacency_list(int* source, int* sink, int n, int nodes);

void initialize_list(node** sorted_list, int nodes);

void print_adjacency_list(node** sorted_list, int nodes);
	
void dfs(node** sorted_list,int nodes);

#endif
