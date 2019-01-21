// Modify this file
// compile with: gcc linkedlist.c -o linkedlist

#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

// Create your node_t type here


// Write your functions here
// There should be 1.) create_list 2.) print_list 3.) free_list
// You may create as many helper functions as you like.

typedef struct node{
	int year;
	int wins;
	struct node* next;
}node_t;

node_t* create_list(){
	node_t* list18 =(node_t*) malloc(sizeof(node_t));
	node_t* list17 =(node_t*) malloc(sizeof(node_t));
	node_t* list16 =(node_t*) malloc(sizeof(node_t));
	node_t* list15 =(node_t*) malloc(sizeof(node_t));
	node_t* list14 =(node_t*) malloc(sizeof(node_t));
	
	list18->year = 2018;
	list18->wins = 108;
	list18->next = list17;

	list17->year = 2017;
	list17->wins = 93;
	list17->next = list16;

	list16->year = 2016;
	list16->wins = 93;
	list16->next = list15;

	list15->year = 2015;
	list15->wins = 78;
	list15->next = list14;

	list14->year = 2014;
	list14->wins = 71;
	list14->next = NULL;

	return list18;
}

void print_list(node_t* list){
	node_t* iterator;
	iterator = list;
	while(iterator != NULL){
		printf("The Red Sox won %d games in %d\n", iterator->wins, iterator->year);
		iterator = iterator->next;
	}
}

void free_list(node_t* list){
	node_t* iterator = list;
	while(iterator != NULL){
		node_t* free_node = iterator;
		iterator = iterator->next;
		free(free_node);
	}	
}


int main(){
	node_t* t = create_list();
	print_list(t);
	free_list(t);  
 	return 0;
}

