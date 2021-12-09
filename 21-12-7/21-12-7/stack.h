#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#define ElemType int
typedef struct SeqStack
{
	ElemType *data;
	int top;
	size_t capacity;
}SeqStack;
void SeqStackInit(SeqStack *q)


#endif