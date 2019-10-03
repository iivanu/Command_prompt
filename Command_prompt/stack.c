#include "Header.h"

// Stack functions implementation
Position popStack(position stack, Position root) {
	position tmp = stack->Next;
	if (tmp != NULL) {
		stack->Next = tmp->Next;
		return tmp->tree;
	}
	return root;
}

int pushStack(Position tree, position stack) {
	position q = AllocationStack();
	q->tree = tree;
	q->Next = stack->Next;
	stack->Next = q;
	return OK;
}