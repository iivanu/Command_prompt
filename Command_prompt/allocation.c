#include "Header.h"

// Allocation functions for stack and tree implementation
Position AllocationTree() {
	Position q = (Position)malloc(sizeof(Tree));
	if (q == NULL) {
		printf("Memory not allocated!!\n");
		return NULL;
	}
	q->FChild = NULL;
	q->NBrother = NULL;
	q->NBrother = NULL;
	return q;
}

position AllocationStack() {
	position q = (position)malloc(sizeof(Stack));
	if (q == NULL) {
		printf("Memory not allocated!!\n");
		return NULL;
	}
	q->Next = NULL;
	q->tree = NULL;
	return q;
}
