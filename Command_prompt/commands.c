#include "Header.h"

// md, cd, dir, rd, help funtions implemetation
int MakeDirectory(Position Tree, char* name) {
	Position q = AllocationTree();
	Position x = Tree->FChild;
	if (name == NULL) {
		printf("The syntax of the command is incorrect.\n");
		return NOT_OK;
	}
	q->name = (char*)malloc(strlen(name) + 1);
	strcpy(q->name, name);
	if (Tree->FChild == NULL) {
		Tree->FChild = q;
	}
	else if (strcmp(q->name, x->name) < 0) {
		q->NBrother = x;
		Tree->FChild = q;
	}
	else if (strcmp(q->name, x->name) == 0) {
		printf("A subdirectory or file %s already exists.\n", x->name);
		GarbageCollector(q);
		return NOT_OK;
	}
	else {
		while (x->NBrother != NULL && strcmp(q->name, x->NBrother->name) > 0)
			x = x->NBrother;
		if (x->NBrother != NULL && strcmp(q->name, x->NBrother->name) == 0) {
			printf("A subdirectory or file %s already exists.\n", x->NBrother->name);
			GarbageCollector(q);
			return NOT_OK;
		}
		q->NBrother = x->NBrother;
		x->NBrother = q;
	}
	return OK;
}

Position ChangeDirectory(Position curretDir, position stack, char* name) {
	Position x = curretDir->FChild;
	if (name == NULL) {
		return curretDir;
	}

	while (x != NULL && strcmp(x->name, name) != OK)
		x = x->NBrother;
	if (x == NULL) {
		printf("The system cannot find the path specified.\n", name);
		return curretDir;
	}
	pushStack(curretDir, stack);
	return x;
}

int ListDirectory(Position tree, position stack) {
	Position x = tree->FChild;
	int* num = NULL;
	num = (int*)malloc(sizeof(int));
	*num = 0;
	printf("Directory of %s:\n", tree->name);
	while (x != NULL) {
		printf("\t<DIR>\t%s\n", x->name);
		(*num)++;
		x = x->NBrother;
	}
	printf("\t\t%d Dir(s)\n", *num);
	free(num);
	return OK;
}

int RemoveDirectory(Position CurrentDirectory, char* name) {
	Position x = CurrentDirectory->FChild;
	Position tmp = NULL;
	if (name == NULL) {
		printf("The syntax of the command is incorrect.\n");
		return NOT_OK;
	}
	else if (x != NULL && strcmp(x->name, name) == OK) {
		CurrentDirectory->FChild = x->NBrother;
		x = NULL;
		GarbageCollector(x);
	}
	else {
		while (x != NULL && x->NBrother != NULL && strcmp(x->NBrother->name, name) != OK)
			x = x->NBrother;
		if (x == NULL || x->NBrother == NULL || strcmp(x->NBrother->name, name) != OK) {
			printf("The system cannot find the file specified.\n", name);
			return NOT_OK;
		}
		else {
			tmp = x->NBrother;
			x->NBrother = tmp->NBrother;
			tmp->NBrother = NULL;
			GarbageCollector(tmp);
		}
	}
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
