#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include<stddef.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void deleteNode(Node **,int);
Node* createList();


#endif