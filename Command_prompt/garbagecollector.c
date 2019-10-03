#include "Header.h"

// Garbage collector functions for stack and tree implementation
int GarbageCollectorStack(position head) {
	if (head == NULL) {
		return OK;
	}
	else if (head->Next != NULL) {
		GarbageCollectorStack(head->Next);
	}
	free(head);
	return OK;
}

int GarbageCollector(Position P) {
	if (P == NULL)
		return NOT_OK;
	else if (P->FChild != NULL)
		GarbageCollector(P->FChild);
	else if (P->NBrother != NULL)
		GarbageCollector(P->NBrother);
	free(P->name);
	free(P);
	return OK;
}
