#include "Header.h"

Position AllocationTree()
{
	Position q = (Position)malloc(sizeof(Tree));
	
	if (q == NULL)
	{
		printf("Memory not allocated!!\n");
		return NULL;
	}

	q->FChild = NULL;
	q->NBrother = NULL;

	return q;
}

position AllocationStack()
{
	position q = (position)malloc(sizeof(Stack));
	
	if (q == NULL)
	{
		printf("Memory not allocated!!\n");
		return NULL;
	}

	return q;
}

int MakeDirectory(Position Tree, char* name)
{
	Position q = AllocationTree();
	Position x = Tree->FChild;
	q->name = (char*)malloc(strlen(name) + 1);
	strcpy(q->name, name);
	
	printf("\nDirectory %s is created!!", name);
	
	if (Tree->FChild == NULL)
	{
		Tree->FChild = q;
		return 0;
	}

	else if (strcmp(q->name, x->name) < 0)
	{ 
		q->NBrother = x;
		Tree->FChild = q;
		return 0;
	}

	else
	{
		while (x->NBrother != NULL && strcmp(q->name, x->NBrother->name) > 0)
			x = x->NBrother;

		q->NBrother = x->NBrother;
		x->NBrother = q;
	}
	return 0;
}

Position ChangeDirectory(Position curretDir, position stack, char* name)
{
	Position x = curretDir->FChild;

	while (x != NULL && strcmp(x->name, name) != 0)
		x = x->NBrother;

	if (x == NULL)
	{
		printf("\nThe system cannot find the path specified.\n", name);
		return curretDir;
	}

	pushStack(curretDir, stack);

	return x;
}

Position popStack(position stack)
{
	position tmp = stack->Next;

	if (tmp->Next == NULL)
		printf("\nYou are already in root directory!!\n");

	else
		stack->Next = tmp->Next;

	return tmp->tree;
}

int pushStack(Position tree, position stack)
{
	position q = AllocationStack();

	q->tree = tree;
	q->Next = stack->Next;
	stack->Next = q;

	return 0;
}
int ListDirectory(Position tree, position stack)
{
	Position x = tree->FChild;
	int num = 0;

	printf("\nDirectory of %s:\n", tree->name);
	while (x != NULL)
	{
		printf("\t<DIR>\t%s\n", x->name);
		num++;
		x = x->NBrother;
	}
	printf("\t\t%d Dir(s)", num);

	return 0;
}

int GarbageCollector(Position P)
{
	if (P == NULL)
		return -1;

	else if (P->FChild != NULL)
		GarbageCollector(P->FChild);

	else if (P->NBrother != NULL)
		GarbageCollector(P->NBrother);

	free(P->name);
	free(P);

	return 0;
}

int CallHelp()
{
	printf("\nFor more information on a specific command, type HELP command-name\n");
	printf("md\tCreates a directory.\n");
	printf("cd\tDisplays the name of or changes the current directory.\n");
	printf("cd..\tReturn to previous directory\n");
	printf("dir\tDisplays a list of files and subdirectories in a directory.\n\n");

	return 0;
}