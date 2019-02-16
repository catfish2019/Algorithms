// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_graph.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

void unitTest1(){
    graph_t * testGraph = create_graph();
    printf("Empty Status: %d\n", graph_empty(testGraph));
    
    printf("Add 1: %d\n", graph_add_node(testGraph, 1));
    printf("Add 2: %d\n", graph_add_node(testGraph, 2));
    printf("Add 3: %d\n", graph_add_node(testGraph, 3));
    printf("Add 4: %d\n", graph_add_node(testGraph, 4));
    printf("Add 5: %d\n", graph_add_node(testGraph, 5));
    printf("add node 5 again: %d\n",graph_add_node(testGraph, 5));
    printf("Contains node 1: %d\n", contains_node(testGraph, 1));
    printf("Contains node 2: %d\n", contains_node(testGraph, 2));
    printf("Contains node 3: %d\n", contains_node(testGraph, 3));
    printf("Contains node 4: %d\n", contains_node(testGraph, 4));
    printf("Contains node 5: %d\n", contains_node(testGraph, 5));
    printf("number of nodes: %d\n", graph_num_nodes(testGraph));
    
    graph_add_edge(testGraph, 1, 2);
    graph_add_edge(testGraph, 1, 3);
    graph_add_edge(testGraph, 2, 4);
    graph_add_edge(testGraph, 1, 5);
    printf("number of edges: %d\n", graph_num_edges(testGraph));
    printf("Empty Status: %d\n", graph_empty(testGraph));
    int i = 0;
    int* n1 = getNeighbors(testGraph, 1);
    for (i; i < numNeighbors(testGraph, 1); i++){
        printf("%d\n", n1[i]);
    }
    free(n1);
    printf("=================================\n");
    graph_print(testGraph);
    printf("=================================\n");
    printf("Contains edge 1->2: %d\n", contains_edge(testGraph, 1, 2));
    printf("Contains edge 1->3: %d\n", contains_edge(testGraph, 1, 3));
    printf("Contains edge 2->4: %d\n", contains_edge(testGraph, 2, 4));
    printf("Contains edge 1->4: %d\n", contains_edge(testGraph, 1, 5));
    printf("===============remove 1->5==================\n");
    graph_remove_edge(testGraph, 1, 5);
    printf("1's neighbor: %d\n", numNeighbors(testGraph, 1));
    int j = 0;
    int* n2 = getNeighbors(testGraph, 4);
    for (j; j < numNeighbors(testGraph, 4); j++){
        printf("%d\n", n2[j]);
    }
    free(n2);
    printf("number of edges: %d\n", graph_num_edges(testGraph));
    printf("==============remove 2 ===================\n");
    graph_add_node(testGraph, 5);
    graph_add_edge(testGraph, 1, 5);
    graph_remove_node(testGraph, 2);
    printf("Contains edge 1->2: %d\n", contains_edge(testGraph, 1, 2));
    printf("Contains edge 2->4: %d\n", contains_edge(testGraph, 2, 4));
    printf("Contains node 2: %d\n", contains_node(testGraph, 2));
    printf("number of nodes: %d\n", graph_num_nodes(testGraph));
    printf("number of edges: %d\n", graph_num_edges(testGraph));
    printf("has cycle: %d\n", has_cycle(testGraph));
    graph_print(testGraph);
     
    free_graph(testGraph);
}

void unitTest2(){
    graph_t * testGraph = create_graph();
    printf("Empty Status: %d\n", graph_empty(testGraph));
    graph_add_node(testGraph, 1);
    graph_add_node(testGraph, 2);
    graph_add_node(testGraph, 3);
    graph_add_node(testGraph, 4);
    graph_add_node(testGraph, 5);
    graph_add_node(testGraph, 6);
    printf("Contains node 1: %d\n", contains_node(testGraph, 1));
    printf("Contains node 2: %d\n", contains_node(testGraph, 2));
    printf("Contains node 3: %d\n", contains_node(testGraph, 3));
    printf("Contains node 4: %d\n", contains_node(testGraph, 4));
    printf("Contains node 5: %d\n", contains_node(testGraph, 5));
    printf("number of nodes: %d\n", graph_num_nodes(testGraph));
    
    
    graph_add_edge(testGraph, 1, 2);
    graph_add_edge(testGraph, 1, 3);
    graph_add_edge(testGraph, 2, 4);
    graph_add_edge(testGraph, 1, 5);
    
    printf("reachable: 1->4: %d\n", is_reachable(testGraph, 1, 4));
       printf("reachable: 1->4: %d\n", is_reachable(testGraph, 1, 4));
    printf("reachable: 5->4: %d\n", is_reachable(testGraph, 5, 4));
    printf("reachable: 5->5: %d\n", is_reachable(testGraph, 5, 5));
    
    
    free_graph(testGraph);
}

void unitTest3(){
    graph_t * testGraph = create_graph();
    printf("Empty Status: %d\n", graph_empty(testGraph));
    graph_add_node(testGraph, 1);
    graph_add_node(testGraph, 2);
    graph_add_node(testGraph, 3);
    graph_add_node(testGraph, 4);
    graph_add_node(testGraph, 5);
    graph_add_node(testGraph, 6);
    printf("Contains node 1: %d\n", contains_node(testGraph, 1));
    printf("Contains node 2: %d\n", contains_node(testGraph, 2));
    printf("Contains node 3: %d\n", contains_node(testGraph, 3));
    printf("Contains node 4: %d\n", contains_node(testGraph, 4));
    printf("Contains node 5: %d\n", contains_node(testGraph, 5));
    printf("number of nodes: %d\n", graph_num_nodes(testGraph));
    
    
    graph_add_edge(testGraph, 1, 2);
    graph_add_edge(testGraph, 1, 3);
    graph_add_edge(testGraph, 2, 4);
    graph_add_edge(testGraph, 1, 5);
    
    printf("path 1->4:\n");
    print_path(testGraph, 1, 4);
   
    
    free_graph(testGraph);
    
}
void unitTest4(){
    graph_t * testGraph = create_graph();
    printf("Empty Status: %d\n", graph_empty(testGraph));
    graph_add_node(testGraph, 1);
    graph_add_node(testGraph, 2);
    graph_add_node(testGraph, 3);
    graph_add_node(testGraph, 4);
    graph_add_node(testGraph, 5);
    graph_add_node(testGraph, 6);
    printf("Contains node 1: %d\n", contains_node(testGraph, 1));
    printf("Contains node 2: %d\n", contains_node(testGraph, 2));
    printf("Contains node 3: %d\n", contains_node(testGraph, 3));
    printf("Contains node 4: %d\n", contains_node(testGraph, 4));
    printf("Contains node 5: %d\n", contains_node(testGraph, 5));
    printf("number of nodes: %d\n", graph_num_nodes(testGraph));
    
    
    graph_add_edge(testGraph, 1, 2);
    graph_add_edge(testGraph, 1, 3);
    graph_add_edge(testGraph, 2, 4);
    graph_add_edge(testGraph, 1, 5);
    graph_add_edge(testGraph, 4, 3);
    graph_add_edge(testGraph, 3, 1);
    
    graph_print(testGraph);
    
    printf("cycle: %d\n", has_cycle(testGraph));
    
    free_graph(testGraph);
}
void unitTest5(){
    graph_t * testGraph = create_graph();
    graph_add_node(testGraph, 1);
    graph_add_node(testGraph, 2);
    graph_add_node(testGraph, 3);
    graph_add_node(testGraph, 4);
    graph_add_node(testGraph, 5);
    graph_add_node(testGraph, 6);
    graph_add_node(testGraph, 7);
    graph_add_node(testGraph, 8);
    graph_add_node(testGraph, 9);
    graph_add_node(testGraph, 10);
    graph_add_node(testGraph, 11);
    graph_add_node(testGraph, 12);
    graph_add_node(testGraph, 13);
    graph_add_node(testGraph, 14);
    printf("nodes: %d\n", graph_num_nodes(testGraph));
    graph_add_edge(testGraph, 1, 2);
    graph_add_edge(testGraph, 1, 3);
    graph_add_edge(testGraph, 2, 4);
    graph_add_edge(testGraph, 2, 5);
    graph_add_edge(testGraph, 3, 6);
    graph_add_edge(testGraph, 3, 7);
    graph_add_edge(testGraph, 4, 8);
    graph_add_edge(testGraph, 4, 9);
    graph_add_edge(testGraph, 5, 10);
    graph_add_edge(testGraph, 5, 11);
    graph_add_edge(testGraph, 6, 13);
    graph_add_edge(testGraph, 7, 14);
    printf("edges: %d\n", graph_num_edges(testGraph));
    graph_print(testGraph);
    printf("========================\n");
    print_path(testGraph, 2, 10);
    printf("2->13: %d\n", is_reachable(testGraph, 1, 1));
    printf("has cycle: %d\n", has_cycle(testGraph));
    printf("has 0: %d\n",contains_node(testGraph, 0));
    printf("remove 0: %d\n", graph_remove_node(testGraph, 0));
    printf("remove 1->12: %d\n", graph_remove_edge(testGraph, 1, 12));
    graph_print(testGraph);
    
    free_graph(testGraph);
    
}
void unitTest6(){
    graph_t* testGraph = NULL;
    printf("NULL Graph:\n");
    printf("Empty: %d\n", graph_empty(testGraph));
    printf("%d\n", contains_node(testGraph, 1));
    printf("%d\n", contains_edge(testGraph, 1, 2));
    printf("Add node: %d\n", graph_add_node(testGraph, 1));
    printf("Add node: %d\n", graph_add_edge(testGraph, 1, 2));
    printf("%d\n", numNeighbors(testGraph, 1));
    printf("%d\n", *getNeighbors(testGraph, 1));
    printf("reachable 1->2: %d\n", is_reachable(testGraph, 1, 2));
    printf("has cycle: %d\n", has_cycle(testGraph));
    graph_print(testGraph);
    print_path(testGraph, 1, 2);
    free_graph(testGraph);
}

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
    unitTest1();
    unitTest2();
    unitTest3();
    unitTest4();
    unitTest5();
    unitTest6();
    return 0;

}
