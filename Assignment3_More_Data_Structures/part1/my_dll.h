// =================== Support Code =================
// Doubly Linked List ( DLL ).
//
//
//
// - Implement each of the functions to create a working DLL.
// - Do not change any of the function declarations
//   - (i.e. dll_t* create_dll() should not have additional arguments)
// - You should not have any 'printf' statements in your DLL functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYDLL_H
#define MYDLL_H

// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node{
	int data;
	struct node* next;
  	struct node* previous;
}node_t;

// Create a DLL data structure
// Our DLL holds a pointer to the first node in our DLL called head,
// and a pointer to the last node in our DLL called tail.
typedef struct DLL{
	int count;		// count keeps track of how many items are in the DLL.
	node_t* head;		// head points to the first node in our DLL.
        node_t * tail;          //tail points to the last node in our DLL.
}dll_t;

// Creates a DLL
// Returns a pointer to a newly created DLL.
// The DLL should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The DLLs fields should also be initialized to default values.
dll_t* create_dll(){
	dll_t* myDLL= (dll_t*)malloc(sizeof(dll_t));
    	myDLL->count = 0;
	myDLL->head = NULL;
	myDLL->tail = NULL;
	return myDLL;
}
void free_dll(dll_t* t);

// DLL Empty
// Check if the DLL is empty
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
int dll_empty(dll_t* l){
	if(l->count == 0){
		return 1;
	}
    	else{
        	return 0;
    	}	
}

// push a new item to the front of the DLL ( before the first node in the list).
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t* l, int item){
    	node_t* temp = (node_t*)malloc(sizeof(node_t));
    	if(temp == NULL){
        	return -1;
    	}	
    	else if (dll_empty(l)){
        	temp->data = item;
        	l->head = temp;
        	l->tail = temp;
        	temp->next = NULL;
        	temp->previous = NULL;
    	}
    	else{
        	temp->data = item;
        	l->head->previous = temp;
        	temp->next = l->head;
        	temp->previous = NULL;
        	l->head = temp;
    	}	
   	l->count ++;	
	return 0; // Note: you should have two return statements in this function.
}

// push a new item to the end of the DLL ( after the last node in the list).
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t* l, int item){
    	node_t* temp = (node_t*)malloc(sizeof(node_t));
    	if(temp == NULL){
        	return -1;
    	}	
    	else if (dll_empty(l)){
        	temp->data = item;
        	l->head = temp;
        	l->tail = temp;
        	temp->next = NULL;
        	temp->previous = NULL;
    	}
    	else{
        	temp->data = item;
        	temp->next = NULL;
        	l->tail->next = temp;
        	temp->previous = l->tail;
        	l->tail = temp;
    	}
    	l->count ++;	
	return 0; // Note: you should have two return statements in this function.
}

// Returns the first item in the DLL. 
// Removes an item from the DLL.
// Removing from an empty DLL should crash the program, call exit(1).
int dll_pop_front(dll_t* t){
	if(dll_empty(t)){
        	free_dll(t);
        	exit(1);
    	}	
    
    	int del = t->head->data;
    	node_t* temp = t->head;
    
    	if (t->count == 1){
        	t->head = NULL;
        	t->tail = NULL;
    	}
    	else{
        	t->head = temp->next;
        	t->head->previous = NULL;
    	}
    	free(temp);
    	t->count --;
	return del; // Note: This line is a 'filler' so the code compiles.
}

// Returns the last item in the DLL. 
// Removes the last item from the DLL.
// Removing from an empty DLL should crash the program, call exit(1).
int dll_pop_back(dll_t* t){
    	if(dll_empty(t)){
        	free_dll(t);
        	exit(1);
    	}	
    	int del = t->tail->data;
    	node_t* temp = t->tail;
    
    	if (t->count == 1){
        	t->head = NULL;
        	t->tail = NULL;
    	}
    	else{
        	t->tail = temp->previous;
        	t->tail->next = NULL;
    	}
        free(temp);
        t->count --;
	return del; // Note: This line is a 'filler' so the code compiles.
}
// Inserts a new node before the node at the specified position.
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the memory allocation for a new node failed or trying to insert at a negative position or at 
//  a position past the size of the DLL ).
int dll_insert(dll_t* l, int pos, int item){
node_t* temp = (node_t*)malloc(sizeof(node_t));
    	if(temp == NULL || pos < 0 || pos > l->count){
        	free(temp);
		return -1;
    	}	
    	if(pos == 0){
        	dll_push_front(l, item);
 		free(temp);   
	}
    	else if (pos == l->count){
        	dll_push_back(l, item);
 		free(temp);   
	}
    	else{
        	node_t* p = l->head;
        	for (int i = 0; i < pos; i++){
        	    	p = p->next;
        	}
        	temp->data = item;
        	temp->previous = p->previous;
        	temp->next = p;
        	p->previous->next = temp;
        	p->previous = temp;
        	l->count ++;
    	}		
	return 0; // Note: you should have two return statements in this function.
}

// Returns the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the position is negative or trying to retrive an item at or past the size,
// or the list is empty.
int dll_get(dll_t* l, int pos){
 	if (pos < 0 || pos >= l->count || dll_empty(l)){
        	return -1;
    	}
    	else{
        	node_t* p = l->head;
        	for (int i = 0; i < pos; i++){
            	p = p->next;
        	}
        	return p->data; // Note: you should have two return statements in this function.
    	}		
}

// Removes the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the position is negative or trying to remove an item at or past the size,
// or if the list is empty
int dll_remove(dll_t* l, int pos){
 	if (pos < 0 || pos >= l->count || dll_empty(l)){
        	return -1;
    	}
    	int del;
    	if(pos == 0){
        	del = dll_pop_front(l);
    	}
    	else if (pos == l->count - 1){
        	del = dll_pop_back(l);
    	}
    	else{
        	node_t* p = l->head;
        	for (int i = 0; i < pos; i++){
        	    	p = p->next;
        	}
        	p->previous->next = p->next;
        	p->next->previous = p->previous;
        	del = p->data;
        	free(p);
        	l->count --;
       }

		return del; // Note: you should have two return statements in this function.
}

// DLL Size
// Queries the current size of a DLL
// A DLL that has not been previously created will crash the program.
// (i.e. A NULL DLL cannot return the size)
unsigned int dll_size(dll_t* t){
    	if(t == NULL){
        	exit(1);
    	}
    	else{
        	return t->count;
    	}
}

// Free DLL
// Removes a DLL and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_dll(dll_t* t){
  	if (t != NULL){
        	node_t* iterator = t->head;
        
        	while(iterator != NULL){
            		node_t* free_node = iterator;
            		iterator = iterator->next;
           	 	free(free_node);
        	}
        	free(t);
    	}
}

// Print DLL
// From head to tail.
void print_dll_head(dll_t* l){
    	node_t* iterator = l->head;
    	while(iterator != NULL){
        	printf("%d\n", iterator->data);
        	iterator = iterator->next;
    	}
}


// Print DLL
// From tail to head.
void print_dll_tail(dll_t* l){
    	node_t* iterator = l->tail;
    	while(iterator != NULL){
        	printf("%d\n", iterator->data);
        	iterator = iterator->previous;
    	}
}
#endif
