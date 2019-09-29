#include "Header.h"

Position AllocationTree() {
	Position q = (Position)malloc(sizeof(Tree));
	if (q == NULL) {
		printf("Memory not allocated!!\n");
		return NULL;
	}
	q->FChild = NULL;
	q->NBrother = NULL;
	return q;
}

position AllocationStack() {
	position q = (position)malloc(sizeof(Stack));
	if (q == NULL) {
		printf("Memory not allocated!!\n");
		return NULL;
	}
	return q;
}

int MakeDirectory(Position Tree, char* name) {
	Position q = AllocationTree();
	Position x = Tree->FChild;
	q->name = (char*)malloc(strlen(name) + 1);
	strcpy(q->name, name);
	if (Tree->FChild == NULL) {
		Tree->FChild = q;
		return OK;
	}
	else if (strcmp(q->name, x->name) < 0 || strcmp(q->name, x->name) == 0) {
		if (strcmp(q->name, x->name) == 0) {
			printf("A subdirectory or file %s already exists.\n", x->name);
			GarbageCollector(q);
			return OK;
		}
		q->NBrother = x;
		Tree->FChild = q;
		return OK;
	}
	else {
		while (x->NBrother != NULL && strcmp(q->name, x->NBrother->name) > 0)
			x = x->NBrother;
		if (x->NBrother != NULL && strcmp(q->name, x->NBrother->name) == 0) {
			printf("A subdirectory or file %s already exists.\n", x->NBrother->name);
			GarbageCollector(q);
			return OK;
		}
		q->NBrother = x->NBrother;
		x->NBrother = q;
	}
	return OK;
}

Position ChangeDirectory(Position curretDir, position stack, char* name) {
	Position x = curretDir->FChild;
	while (x != NULL && strcmp(x->name, name) != OK)
		x = x->NBrother;
	if (x == NULL) {
		printf("The system cannot find the path specified.\n", name);
		return curretDir;
	}
	pushStack(curretDir, stack);
	return x;
}

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

int ListDirectory(Position tree, position stack) {
	Position x = tree->FChild;
	int num = 0;
	printf("Directory of %s:\n", tree->name);
	while (x != NULL) {
		printf("\t<DIR>\t%s\n", x->name);
		num++;
		x = x->NBrother;
	}
	printf("\t\t%d Dir(s)\n", num);
	return OK;
}

int GarbageCollector(Position P) {
	if (P == NULL)
		return NOT_VALID;
	else if (P->FChild != NULL)
		GarbageCollector(P->FChild);
	else if (P->NBrother != NULL)
		GarbageCollector(P->NBrother);
	free(P->name);
	free(P);
	return OK;
}

int CallHelp() {
	printf("md\tCreates a directory.\n");
	printf("cd\tDisplays the name of or changes the current directory.\n");
	printf("cd..\tReturn to previous directory\n");
	printf("dir\tDisplays a list of files and subdirectories in a directory.\n");
	printf("rd\tRemoves a directory.\n");
	printf("cls\tClears the screen.\n");
	return OK;
}

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

int RemoveDirectory(Position CurrentDirectory, char* name) {
	Position x = CurrentDirectory->FChild;
	Position tmp = NULL;
	if (x != NULL && strcmp(x->name, name) == OK) {
		CurrentDirectory->FChild = x->NBrother;
		x->NBrother = NULL;
		GarbageCollector(x);
		return OK;
	}
	while (x != NULL && x->NBrother != NULL && strcmp(x->NBrother->name, name) != OK)
		x = x->NBrother;
	if (x == NULL || strcmp(x->name, name) != OK) {
		printf("The system cannot find the file specified.\n", name);
		return NOT_VALID;
	}
	else {
		tmp = x->NBrother;
		x->NBrother = tmp->NBrother;
		tmp->NBrother = NULL;
		GarbageCollector(tmp);
	}
	return OK;
}