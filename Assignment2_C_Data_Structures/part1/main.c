// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "myqueue.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.
void unitTest1(){queue_t* test1 = create_queue(4);

    if (queue_full(test1)){
        printf("This is a full queue.\n");}
    printf("Adding %d, status: %d\n", 1, queue_enqueue(test1, 1));
    printf("The size is %d.\n", queue_size(test1));
    
    if (queue_full(test1)){
        printf("This is a full queue.\n");}
    printf("Adding %d, status: %d\n", 2, queue_enqueue(test1, 2));
    printf("The size is %d.\n", queue_size(test1));
    
    if (queue_full(test1)){
        printf("This is a full queue.\n");}
    printf("Adding %d, status: %d\n", 3, queue_enqueue(test1, 3));
    printf("The size is %d.\n", queue_size(test1));
    
    if (queue_full(test1)){
        printf("This is a full queue.\n");}
    printf("Adding %d, status: %d\n" , 4, queue_enqueue(test1, 4));
    printf("The size is %d.\n", queue_size(test1));
    

    
    if (queue_empty(test1)){
        printf("This is an empty queue.\n");}
    
    printf("Removing: %d\n",queue_dequeue(test1));
    printf("The size is %d.\n", queue_size(test1));
    printf("Removing: %d\n",queue_dequeue(test1));
    printf("The size is %d.\n", queue_size(test1));
    printf("Removing: %d\n",queue_dequeue(test1));
    printf("The size is %d.\n", queue_size(test1));
    printf("Removing: %d\n",queue_dequeue(test1));
    printf("The size is %d.\n", queue_size(test1));
    
    free_queue(test1);
    
    
    
}
void unitTest2(){

    queue_t* test2 = create_queue(1);

    if (queue_full(test2)){
        printf("This is a full queue.\n");}
    printf("Adding %d, status: %d\n", 1, queue_enqueue(test2, 1));
    printf("The size is %d.\n", queue_size(test2));
    
    if (queue_full(test2)){
        printf("This is a full queue.\n");}
    printf("Adding %d, status: %d\n", 2, queue_enqueue(test2, 2));
    printf("The size is %d.\n", queue_size(test2));
    
    
    if (queue_empty(test2)){
        printf("This is an empty queue.\n");}
    
    printf("Removing: %d\n",queue_dequeue(test2));
    if (queue_empty(test2)){
        printf("This is an empty queue.\n");}
    printf("The size is %d.\n", queue_size(test2));
    printf("Removing: %d\n",queue_dequeue(test2));
    printf("The size is %d.\n", queue_size(test2));
    
    free_queue(test2);
    

    
    
}
void unitTest3(){
 // test queue_empty and dequeue an empty queue
    queue_t* test3 = create_queue(0);

    if (queue_full(test3)){
        printf("This is a full queue.\n");}
    printf("Adding %d, status: %d\n", 1, queue_enqueue(test3, 1));
    printf("Removing: %d\n", queue_dequeue(test3));
    printf("The size is %d.\n", queue_size(test3));
    
    
    if (queue_empty(test3)){
        printf("This is an empty queue.\n");}

    free_queue(test3);

    
    
}

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
// List of Unit Tests to test your data structure
unitTest1();
    printf("====================================================\n");
    unitTest3();
    printf("====================================================\n");
    unitTest2();
    

    
    return 0;
}

