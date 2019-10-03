#include "Header.h"

// Print functions implementation
int PrintDirectory(Position currentDir, position stack) {
	if (stack->Next == NULL) {
		printf("%s:\\>", currentDir->name);
		return OK;
	}
	PrintDirectoryF(stack->Next);
	printf("%s>", currentDir->name);
}

int PrintDirectoryF(position stack) {
	if (stack->Next != NULL)
		PrintDirectoryF(stack->Next);
	if (strcmp(stack->tree->name, "C") == OK)
		printf("%s:\\", stack->tree->name);
	else
		printf("%s\\", stack->tree->name);
	return OK;
}
