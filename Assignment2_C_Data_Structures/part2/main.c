// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "mystack.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.
void unitTest1(){
	
	
	stack_t* test1 = create_stack(3);
	if (stack_empty(test1)){
		printf("This is an empty stack.\n");
   	 }
	printf("Stack size: %d\n", stack_size(test1));
   	printf("Attempting to push 1, pushing status: %d\n",stack_enqueue(test1, 1));
   	printf("Stack size: %d\n", stack_size(test1));
	printf("Attempting to push 2, pushing status: %d\n",stack_enqueue(test1, 2));
   	printf("Stack size: %d\n", stack_size(test1));
	printf("Attempting to push 3, pushing status: %d\n",stack_enqueue(test1, 3));
	printf("Stack size: %d\n", stack_size(test1));
	printf("Attempting to push 4, pushing status: %d\n",stack_enqueue(test1, 4));
	printf("Stack size: %d\n", stack_size(test1));
	if (stack_full(test1)){
        	printf("This is a full stack.\n");
   	 }
	printf("The size is %d\n", stack_size(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
   	printf("The size is %d\n", stack_size(test1));
    	printf("Removing: %d\n",stack_dequeue(test1));
    	printf("The size is %d\n", stack_size(test1));
    	printf("Removing: %d\n",stack_dequeue(test1));
	if (stack_empty(test1)){
     	   printf("This is an empty stack.\n");
    }
	free_stack(test1);
}

void unitTest2(){
	stack_t* test2 = create_stack(35);
	printf("Stack capactity: %d\n", test2->capacity);
	free_stack(test2);
}
void unitTest3(){
	stack_t* test3 = create_stack(2);
	if (stack_empty(test3)){
        printf("This is an empty stack.\n");
    }
	printf("Attempting to push 1, pushing status: %d\n",stack_enqueue(test3, 1));
	printf("Attempting to push 2, pushing status: %d\n",stack_enqueue(test3, 2));
	if (stack_full(test3)){
        printf("This is a full stack.\n");
    }
   	printf("The size is %d\n", stack_size(test3));
    	printf("Removing: %d\n",stack_dequeue(test3));
    	printf("The size is %d\n", stack_size(test3));
    	printf("Removing: %d\n",stack_dequeue(test3));
   	printf("The size is %d\n", stack_size(test3));

	//Dequeue from an empty stack. Exit the program here. 
    	printf("Removing: %d\n",stack_dequeue(test3));
	printf("The program is still on.");	
	free_stack(test3);
}
void unitTest4(){
	stack_t* test4;
	if (test4 == NULL){
	printf("NULL\n");
	}printf("Size: %d\n",stack_size(test4));
}
// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure
	unitTest1();
	printf("=======================================");
	unitTest2();
	printf("=======================================");
	unitTest3();
	printf("=======================================");
	unitTest4();
	return 0;
}
