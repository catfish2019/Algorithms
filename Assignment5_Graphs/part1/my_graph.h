// =================== Support Code =================
// Graph.
//
//
//
// - Implement each of the functions to create a working graph.
// - Do not change any of the function declarations
//   - (i.e. graph_t* create_graph() should not have additional arguments)
// - You should not have any 'printf' statements in your graph functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYGRAPH_H
#define MYGRAPH_H

// Create a neighbor data structure to server as the neighbor's list.
// In our case, we will stores 'integers' as our neighbors that 
// corresponding to the data that the actual nodes store.
typedef struct neighbor{
	int data;
	struct neighbor * next;
}neighbor_t;

// Create a node data structure to store data within
// our graph. In our case, we will stores 'integers'
// as our data in the nodes
typedef struct node{
	int data;
	struct node *next;
	struct neighbor * neighbor;
	int visited;
}node_t;

// Create a graph data structure
// Our graph keeps track of the number of nodes, the number of edges and an array
// of all the nodes in the graph, and the maximum number of nodes we store in our graph.
typedef struct graph{
	int numNodes;		
        int numEdges;
	node_t* nodes;	 //an array of nodes storing all of our nodes.
}graph_t;

struct queue{
    	unsigned int back;          // The next free position in the queue
    	// (i.e. the end or tail of the line)
    	unsigned int front;         // Current 'head' of the queue
    	// (i.e. the front or head of the line)
    	unsigned int size;          // How many total elements we currently have enqueued.
    	unsigned int capacity;  // Maximum number of items the queue can hold
   	node_t**data;                        // The 'integer' data our queue holds
    	};
   	// Creates a global definition of 'queue_t' so we
    	// do not have to retype 'struct queue' everywhere.
   	typedef struct queue queue_t;

// Create a queue
// Returns a pointer to a newly created queue.
// The queue should be initialized with data on
// the heap.
queue_t* create_queue(unsigned int _capacity){
    	queue_t* myQueue;
    	if (_capacity > 0){
        	myQueue = (queue_t*)malloc(sizeof(queue_t));
        	myQueue->data = (node_t**)malloc(sizeof(node_t*)*_capacity);
        	myQueue->back = 0;
        	myQueue->front = 0;
        	myQueue->size = 0;
        	myQueue->capacity = _capacity + 1;
    	}
    	else {
       	 	myQueue = NULL;
    	}
    	return myQueue;
}

void free_queue(queue_t* q);

// Queue Empty
// Check if the queue is empty
// Returns 1 if true (The queue is completely empty)
// Returns 0 if false (the queue has at least one element enqueued)
int queue_empty(queue_t* q){
    	if (q == NULL){
        	return 1;
    	}
    	else if (q->front == q->back){
        	return 1;
    	}
    	else {
        	return 0;
    	}
}

// Queue Full
// Check if the queue is Full
// Returns 1 if true (The queue is completely full)
// Returns 0 if false (the queue has more space available to enqueue items)
int queue_full(queue_t* q){
    	if (q == NULL){
        	return 1;
    	}
    	else if ((q->back + 1) % q->capacity == q->front){
        	return 1;
    	}
    
    	else{
        	return 0;
    	}
}

// Enqueue a new item
// i.e. push a new item into our data structure
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. if the queue is full that is an error).
int queue_enqueue(queue_t *q, node_t* item){
    	if (queue_full(q)){
        	return -1; // Note: you should have two return statements in this function.
    	}
    	else{
        	q->data[q->back] = item;
        	q->back = (q->back + 1) % q->capacity;
        	q->size ++;
        	return 0;
    	}
}

// Dequeue an item
// Returns the item at the front of the queue and
// removes an item from the queue.
// Removing from an empty queue should crash the program, call exit(1)
node_t* queue_dequeue(queue_t *q){
    	if (queue_empty(q)){
        	free_queue(q);
        	exit(1);
    	}
    	else{
        	node_t* del = q->data[q->front];
        	q->front = (q->front + 1) % q->capacity;
        	q->size --;
        	return del; // Note: This line is a filler so the code compiles.
    	}
}

// Queue Size
// Queries the current size of a queue
// A queue that has not been previously created will crash the program.
// (i.e. A NULL queue cannot return the size, call exit(1))
int queue_size(queue_t* q){
    	if (q == NULL){
       		exit(1);
    	}
    	else {
        	return q->size;
    	}
}

// Free queue
// Removes a queue and all of its elements from memory.
// This should be called before the proram terminates.
void free_queue(queue_t* q){
    	if (q != NULL){
        	free(q->data);
        	free(q);
    	}
}

// Creates a graph
// Returns a pointer to a newly created graph.
// The graph should be initialized with data on the heap.
// The graph fields should also be initialized to default values.
graph_t* create_graph(){
	// Modify the body of this function as needed.
	graph_t* myGraph = (graph_t*)malloc(sizeof(graph_t));
	myGraph->numNodes = 0;
	myGraph->numEdges = 0;
	myGraph->nodes = NULL;
	return myGraph;
}

// Graph Empty
// Check if the graph is empty
// Returns 0 if true (The graph is completely empty, i.e. numNodes == 0 )
// Returns -1 if false (the graph has at least one node)
int graph_empty(graph_t* g){
	if (g == NULL){
		exit(1);
	}
	else if (g->numNodes == 0){
		return 1;
	}
	else{
	return 0;
	}
}

// Adds a new node withe the correspoding item in the graph.
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the memory allocation for a new node failed).
// Duplicates nodes should not be added. For a duplicate node returns 0.
int contains_node(graph_t* g, int value);

int graph_add_node(graph_t* g, int item){
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	if (temp == NULL){
		return -1;
	}
	else if (contains_node(g, item)){
		free(temp);
		return 0;
	}
	else{
		temp->data = item;
		temp->next = NULL;
		temp->neighbor = NULL;
		temp->visited = 0;
		node_t* iterator = g->nodes;
		if (iterator == NULL){
			g->nodes = temp;
		}
		else{
			while(iterator->next != NULL){
				iterator = iterator->next;
			}
			iterator->next = temp;
		}
	}
	g->numNodes ++;
	return 0;
}
// Removes the node from the graph and the corresponding edges connected 
// to the node.
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (the node to be removed doesn't exist in the graph).
int contains_edge(graph_t* g, int source, int destination);
int graph_remove_edge(graph_t* g, int source, int destination);

int graph_remove_node(graph_t* g, int item){
	if ( !contains_node(g, item)){
		return -1;
	}
	else{
		// remove the related edges first
		node_t* t = g->nodes;
		while(t != NULL){
			if (contains_edge(g, t->data, item)){
				graph_remove_edge(g, t->data, item);
			}
			t = t->next;
		}

		// remove the head node
		if (g->nodes->data == item){
			node_t* r = g->nodes;
			// remove its neighbors
			neighbor_t* n = r->neighbor;
			while (n != NULL){
				graph_remove_edge(g, r->data, n->data);
				n = n->next;
			}
			g->nodes = g->nodes->next;
			free(r);
			g->numNodes--;
			return 0; 
		}
		// remove the node in the middle
		node_t* iterator = g->nodes;
		while (iterator != NULL){
			if(iterator->next != NULL && iterator->next->data == item){
				node_t* r = iterator->next;
			
				// remove its neighbors first
				neighbor_t* n = r->neighbor;
				while (n != NULL){
					graph_remove_edge(g, r->data, n->data);
					n = n->next;
				}
				iterator->next = r->next;
				free(r);
				g->numNodes --;
				return 0;
			}
			iterator = iterator->next;
		}
		return -1;
	}
}
//Adds an edge from source to destination. 
//If source or desination is not found in the graph returns -1.
//Otherwise it returns 0 ( even for trying to add a duplicate edge )
int graph_add_edge(graph_t * g, int source, int destination){
	if (!contains_node(g, source) && !contains_node(g, destination)){
		return -1;
	}
	else if (!contains_edge(g, source, destination)){
		node_t* temp = g->nodes;
		while (temp != NULL){
			if (temp->data == source){
				break;
			}
			else{
				temp = temp->next;
			}
		}
		neighbor_t* add = (neighbor_t*)malloc(sizeof(neighbor_t));
		if (add == NULL){
			return -1;
		}
		else{
			add->data = destination;
			add->next = NULL;
			neighbor_t* iterator = temp->neighbor;
			if (iterator == NULL){
				temp->neighbor = add;
			}
			else{
				while (iterator->next != NULL){
					iterator = iterator->next;
				}
				iterator->next = add;
			}
			g->numEdges++;
		}
	}
	return 0;
}
	
//Removes an edge from source to destination. 
//If source or desination is not found in the graph returns -1.
//If no such edge exists also returns -1.
//Otherwise it returns 0
int graph_remove_edge(graph_t * g, int source, int destination){
	if (!contains_node(g, source) && !contains_node(g, destination)){
		return -1;
	}
	else if (contains_edge(g, source, destination) == -1){
		return -1;
	}
	else{
		node_t* iterator = g->nodes;
		while (iterator != NULL){
			if (iterator->data == source){
				neighbor_t* temp = iterator->neighbor;

				// remove the first neighbor
				if (temp->data == destination){
					iterator->neighbor = temp->next;
					free(temp);
					g->numEdges--;
					return 0;
				}
				
				// remove the neighbor in the middle
				while (temp != NULL){
					if (temp->next != NULL && temp->next->data == destination){
						neighbor_t* r = temp->next;
						temp->next = r->next;
						free(r);
						g->numEdges--;
						return 0;
					}
					temp = temp->next;
				}
				return -1;
			}
			iterator = iterator->next;
		}
		return -1;
	}
}

//Returns 0 if the node with value is in the graph, otherwise returns -1;
int contains_node( graph_t * g, int value){
	if (g == NULL){
		exit(1);
	}
	node_t* iterator = g->nodes;
	while (iterator != NULL){
		if (iterator->data == value){
			return 1;
		}
		iterator = iterator->next;
	}
   	return 0;
}

//Returns 0 if an edge from source to destination exists, -1 otherwise.
int contains_edge (graph_t * g, int source, int destination){
	if (g == NULL){
		exit(1);
	}

	node_t* iterator = g->nodes;
	while (iterator != NULL){
		if (iterator->data == source ){
			neighbor_t* temp = iterator->neighbor;
			while (temp != NULL){
				if (temp->data == destination){
					return 1;
				}
				else{
					temp = temp->next;
				}
			}
		}
		iterator = iterator->next;
	}
	return 0;
}
//Returns an int array of all the neighbors of the node with data=value.
int numNeighbors(graph_t* g, int value);
int * getNeighbors(graph_t * g, int value){
	if (g == NULL){
		exit(1);
	}
	node_t* iterator = g->nodes;

	int* n = (int*)malloc(sizeof(int));
	while (iterator != NULL){
		if (iterator->data == value){
			int i = 0;
			neighbor_t* temp = iterator->neighbor;
			while (temp != NULL){
				n[i] = temp->data;
				i++;
				temp = temp->next;
			}
			return n;
		}
		iterator = iterator->next;
	}
	free(n);
	return NULL;
}

// Returns the number of neighbors for value.
int numNeighbors( graph_t * g, int value ){
	if (g == NULL){
		exit(1);
	}
	int counter = 0;
	node_t* iterator = g->nodes;
	while(iterator != NULL){
		if (iterator->data == value){
			neighbor_t* temp = iterator->neighbor;
			while (temp != NULL){
				counter++;
				temp = temp->next;
			}
		}
		iterator = iterator->next;
	}
	return counter;
}
unsigned int graph_num_nodes(graph_t* g);
// Find the node with the given data.
node_t* find_node(graph_t* g, int item){
	node_t* temp = g->nodes;
	while(temp != NULL){
		if (temp->data == item){
			return temp;
		}
		else{
			temp = temp->next;
		}
	}
	return NULL;
}
// Turn the nodes' visited into 0 after finishing operations.
void unvisited(graph_t* g){
	if (g != NULL){
		node_t* temp = g->nodes;
		while(temp != NULL){
			temp->visited = 0;
			temp = temp->next;
		}
	}
}
// Prints the a component of the graph using BFS
void component_print(graph_t* g, node_t* start){
	queue_t* q = create_queue(graph_num_nodes(g));
	queue_enqueue(q, start);
	while(!queue_empty(q)){
		node_t* temp = queue_dequeue(q);
		printf("%d\n", temp->data);
		temp->visited = 1;
		
		neighbor_t* iterator = temp->neighbor;
		while(iterator != NULL){
			node_t* t = find_node(g, iterator->data);
			if (t->visited == 0){
				queue_enqueue(q, t);
			}
			iterator = iterator->next;
		}
	}
	free_queue(q);
}	
// Prints the the graph using BFS
// For NULL or empty graph it should print nothing. 
void graph_print(graph_t * g){
	if (g!= NULL){	
		node_t* start = g->nodes;
		while(start != NULL){
			if (start->visited == 0){
				component_print(g, start);
			}
			start = start->next;
		}
		unvisited(g);
	}	
}

// Graph Size
// Returns the number of nodes in the graph
unsigned int graph_num_nodes(graph_t* g){
	if ( g == NULL){
		exit(1);
	}
	
	return g->numNodes;
}

// Graph Size
// Returns the number of edges in the graph
unsigned int graph_num_edges(graph_t* g){
	if (g == NULL){
		exit(1);
	}
	
	return g->numEdges;
}
// is_reachable
// Return 0 if I can reach destination from source; otherwise, return -1.
int is_reachable(graph_t* g, int source, int destination){
	if (!contains_node(g, source) || !contains_node(g, destination)){
		return -1;
	}
	node_t* s = g->nodes;
	// Search for the source node.
	while(s != NULL){
		if (s->data == source){
			break;
		}
		s = s->next;
	}
	
	queue_t* q = create_queue(graph_num_nodes(g));
	queue_enqueue(q, s);
	while(!queue_empty(q)){
		node_t* temp = queue_dequeue(q);
		if (contains_edge(g, temp->data, destination)){
			free_queue(q);
			unvisited(g);
			return 0;
		}
		temp->visited = 1;
	
		neighbor_t* iterator = temp->neighbor;
		while(iterator != NULL){
			node_t* t = find_node(g, iterator->data);
			if (t->visited == 0){
				queue_enqueue(q, t);
			}
			iterator = iterator->next;
		}
	}
	free_queue(q);
	unvisited(g);
	return -1;
}
// has_cycle
// Return 0 if there is a cycle in the graph, -1 otherwise.
int has_cycle(graph_t* g){
	if (g == NULL){
		exit(1);
	}
	node_t* temp = g->nodes;
	while(temp != NULL){
		if (is_reachable(g, temp->data, temp->data) == 0){
			return 0;
		}
		else{
			temp = temp->next;
		}
	}
	return -1;
}

// Print path 
// prints any path form source to destination if there exists one.
void print_path(graph_t* g, int source, int dest){
	if (is_reachable(g, source, dest) == 0){
		printf("%d\n", source);
		if (source != dest){
			node_t* temp = find_node(g, source);
			neighbor_t* n = temp->neighbor;
			while(n != NULL){
				if (n->data == dest){
					printf("%d\n", dest);
				}
				if (is_reachable(g, n->data, dest) == 0){
					break;
				}
				n = n->next;
			}
			if(n != NULL){
				print_path(g, n->data, dest);
			}
		}
	}
}


// Free graph
// Removes a graph and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_graph(graph_t* g){
	if (g != NULL){
		node_t* temp = g->nodes;
		while (temp != NULL){
			neighbor_t* n = temp->neighbor;
			while (n != NULL){
				neighbor_t* f = n;
				n = n->next;
				free(f);
			}
			node_t* fr = temp;
			temp = temp->next;
			free(fr);
		}
		free(g);
	}
}

#endif
