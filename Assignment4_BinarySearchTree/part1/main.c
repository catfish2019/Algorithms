// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_bst.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
	bst_t * testBST = create_bst();
	bst_add(testBST, 20);
    	bst_add(testBST, 10);
    	bst_add(testBST, 30);
    	bst_add(testBST, 15);
    	bst_add(testBST, 5);
    	bst_add(testBST, 25);
    	bst_add(testBST, 27);
	printf("=======dfs=======\n");
	dfs(testBST->root);
    	printf("====ascending====\n");
	bst_print(testBST, 0);
	printf("Sum: %d\n", sum(testBST));
    
    	printf("Find 16, status: %d\n", find(testBST, 16));
	printf("Find 15, status: %d\n", find(testBST, 15));
	printf("====descending====\n");
	bst_print(testBST, 1);
	printf("Size: %d\n", bst_size(testBST));

	free_bst(testBST);    
	return 0;
}
