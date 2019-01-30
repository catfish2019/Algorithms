// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_dll.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

void unitTest1(){
    	dll_t * dll = create_dll();
    	if(dll_empty(dll)){
        	printf("empty.\n");
    	}
    	printf("push front: %d, status: %d\n", 0, dll_push_front(dll, 0));
    	printf("push front: %d, status: %d\n", 1, dll_push_front(dll, 1));
    	printf("push front: %d, status: %d\n", 2, dll_push_front(dll, 2));
    	printf("push front: %d, status: %d\n", 3, dll_push_front(dll, 3));

	print_dll_head(dll);
	printf("================================\n");
	print_dll_tail(dll);

	for(int i = 0; i < dll_size(dll); i++){
		printf("[%d] pos: %d\n", i, dll_get(dll, i));
	}
	    
	printf("Size: %d\n", dll_size(dll));

    	printf("pop back: %d\n", dll_pop_back(dll));
    	printf("pop back: %d\n", dll_pop_back(dll));
    	printf("pop back: %d\n", dll_pop_back(dll));
    	printf("pop back: %d\n", dll_pop_back(dll));
	printf("pop back: %d\n", dll_pop_back(dll));
	printf("Size: %d\n", dll_size(dll));    
    
    	free_dll(dll);
    
	}

void unitTest2(){
    	dll_t * dll = create_dll();
    	if(dll_empty(dll)){
        	printf("empty.\n");
    	}
    	printf("push back: %d, status: %d\n", 0, dll_push_back(dll, 0));
    	printf("push back: %d, status: %d\n", 1, dll_push_back(dll, 1));
    	printf("push back: %d, status: %d\n", 2, dll_push_back(dll, 2));
    	printf("push back: %d, status: %d\n", 3, dll_push_back(dll, 3));
 	
	print_dll_head(dll);
	printf("==============================\n");
	print_dll_tail(dll);
	
	printf("Size: %d\n", dll_size(dll));

	for (int i = 0; i < dll_size(dll); i++){
		printf("[%d] pos: %d\n", i , dll_get(dll, i));
	}
   
    	printf("pop front: %d\n", dll_pop_front(dll));
    	printf("pop front: %d\n", dll_pop_front(dll));
    	printf("pop front: %d\n", dll_pop_front(dll));
    	printf("pop front: %d\n", dll_pop_front(dll));
   	
	printf("pop front: %d\n", dll_pop_front(dll)); 
    
    	free_dll(dll);
}

void unitTest3(){
    	dll_t * dll = create_dll();
    	if(dll_empty(dll)){
        	printf("empty.\n");
    	}
    	printf("Insert: %d, status: %d\n", 0, dll_insert(dll, 1, 0));
    	printf("Insert: %d, status: %d\n", 0, dll_insert(dll, 0, 0));

    	printf("Insert: %d, status: %d\n", 4, dll_insert(dll, 1, 4));
    	printf("Insert: %d, status: %d\n", 3, dll_insert(dll, 1, 3));
    	printf("Insert: %d, status: %d\n", 5, dll_insert(dll, 3, 5));
    	printf("Insert: %d, status: %d\n", 1, dll_insert(dll, 0, 1));
    	printf("Insert: %d, status: %d\n", 3, dll_insert(dll, 6, 3));
    
    	print_dll_head(dll);
   	printf("==============================\n");
    	print_dll_tail(dll);
    
    	printf("size: %d\n", dll_size(dll));
    
    	for(int i = 0; i < dll_size(dll); i++){
        	printf("[%d] pos: %d\n", i, dll_get(dll, i));
    	}
    
    	printf("=============================\n");
    
    	printf("Remove: %d, status: %d\n", 1, dll_remove(dll, 0));
    	printf("Remove: %d, status: %d\n", 5, dll_remove(dll, 3));
    	printf("Remove: %d, status: %d\n", 1, dll_remove(dll, 3));
    	printf("Remove: %d, status: %d\n", 3, dll_remove(dll, 1));
    	printf("Remove: %d, status: %d\n", 0, dll_remove(dll, 0));
    	printf("Remove: %d, status: %d\n", 4, dll_remove(dll, 0));
   	printf("Remove: %d, status: %d\n", 1, dll_remove(dll, 0));
    
    	printf("size: %d\n", dll_size(dll));
    	for(int i = 0; i < dll_size(dll); i++){
        	printf("[%d] pos: %d\n", i, dll_get(dll, i));
    	}
    
    	free_dll(dll);
    
}
void unitTest4(){
    	dll_t * dll;
	
    	printf("%d\n", dll_size(dll));
	
}




// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
   
    	unitTest1();
	unitTest2();
	unitTest3();
	unitTest4();
 	return 0;
}

