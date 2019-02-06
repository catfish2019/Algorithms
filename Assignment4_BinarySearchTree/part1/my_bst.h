// =================== Support Code =================
// Binary Search Tree ( BST ).
//
//
//
// - Implement each of the functions to create a working BST.
// - Do not change any of the function declarations
//   - (i.e. bst_t* create_bst() should not have additional arguments)
// - You should not have any 'printf' statements in your BST functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYBST_H
#define MYBST_H

// Create a node data structure to store data within
// our BST. In our case, we will stores 'integers'
typedef struct node{
	int data;
	struct node* rightChild;
  	struct node* leftChild;
}node_t;

// Create a BST data structure
// Our BST holds a pointer to the root node in our BST called root.
typedef struct BST{
	int count;		// count keeps track of how many items are in the BST.
	node_t* root;		// root points to the root node in our BST.
}bst_t;

void free_bst(bst_t* t);
// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values.
bst_t* create_bst(){
	// Modify the body of this function as needed.
	bst_t* myBST= (bst_t*)malloc(sizeof(bst_t));
	myBST->root = NULL;
	myBST->count = 0;
	return myBST;
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element enqueued)
int bst_empty(bst_t* t){
	if (t->root == NULL || t == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

// Adds a new node containng item in the correct place of the BST.
// If the data is less then the current node we go right, otherwise we go left.
// Same as described in the README.md file. 
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the memory allocation for a new node failed).
// It should run in O(log(n)) time.
node_t* node_add(node_t* start, int item){
	if (start == NULL){
		start = (node_t*)malloc(sizeof(node_t));
		
		start->data = item;
		start->leftChild = NULL;
		start->rightChild = NULL;
	}
	else if (item > start->data){
		start->leftChild = node_add(start->leftChild, item);
	}
	else if (item < start->data){
		start->rightChild = node_add(start->rightChild, item);
	}
	return start;
}
int bst_add(bst_t* t, int item){
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	if (temp == NULL || t == NULL){
		return -1;
	}
	
	free(temp);
	t->root = node_add(t->root, item);
	t->count ++;
	return 0;	
}

// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree it should print nothing. 
// It should run in O(n) time.
void print_node(node_t* start, int order){
	if (start != NULL){
		if (order == 0){
			if (start->leftChild == NULL && start->rightChild == NULL){
				printf("%d\n", start->data);
			}
			else{
				print_node(start->rightChild, order);
				printf("%d\n", start->data);
				print_node(start->leftChild, order);	
			}
		}
		else if (order == 1){
			if (start->leftChild == NULL && start->rightChild == NULL){
				printf("%d\n", start->data);
			}
			else{
				print_node(start->leftChild, order);
				printf("%d\n", start->data);
				print_node(start->rightChild, order);
			}
		}
	}
}
void bst_print(bst_t*t, int order){
	if (t != NULL){
		print_node(t->root, order);
	}
}

// Returns the sum of all the nodes in the tree. 
// exits the program for a NULL tree. 
// It should run in O(n) time.
int sum_node(node_t* start){
	if (start != NULL){
		if (start->leftChild == NULL && start->rightChild == NULL){
			return start->data;
		}
		else{
			return start->data + sum_node(start->leftChild) + sum_node(start->rightChild);
		}
	}
	return 0;
}
int sum(bst_t *t){
	if (t == NULL){
		exit(1);
	}
	else{
		return sum_node(t->root);
	}
}

// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree it exists the program. 
// It should run in O(log(n)) time.
int find_node(node_t* start, int value){
	if (value == start->data){
		return 1;
	}
	else if (value > start->data && start->leftChild != NULL){
		return find_node(start->leftChild, value);
	}
	else if (value < start->data && start->rightChild != NULL){
		return find_node(start->rightChild, value);
	}
	return 0;
}
int find(bst_t * t, int value){
	if (t == NULL){
		exit(1);
	}
	else{
		return find_node(t->root, value);
	}
}

// BST Size
// Queries the current size of the BST
// A BST that has not been previously created will crash the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(bst_t* t){
	if (t != NULL){
		return t->count;	
	}
	else{
		exit(1);
	}
}


// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_node(node_t* start){
	if (start != NULL){
		if (start->leftChild != NULL){
			free_node(start->leftChild);
		}
		if (start->rightChild != NULL){	
			free_node(start->rightChild);
		}
		free(start);
	}
}
void free_bst(bst_t* t){
	if (t != NULL){
		if (t->root != NULL){
			free_node(t->root);
		}
			free(t);
	}
}
void dfs(node_t* start){
	printf("%d\n", start->data);

	if (start->leftChild != NULL){
		dfs(start->leftChild);
	}
	if (start->rightChild != NULL){
		dfs(start->rightChild);
	}
}



#endif
