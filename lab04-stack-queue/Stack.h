#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode{
	Item elem;
	struct StackNode *next;
} StackNode;

typedef struct Stack{
	StackNode* head;  // Varful stivei
	long size; // Numarul de elemente din stiva
} Stack;

Stack* createStack(void){
	// TODO: Cerinta 1
	return NULL;
}

int isStackEmpty(Stack* stack){
	// TODO: Cerinta 1
}

void push(Stack *stack, Item elem){
	// TODO: Cerinta 1
}

Item top(Stack *stack){	
	// TODO: Cerinta 1
} 

void pop(Stack *stack){
	// TODO: Cerinta 1
}

void destroyStack(Stack *stack){
	// TODO: Cerinta 1
}

#endif 
