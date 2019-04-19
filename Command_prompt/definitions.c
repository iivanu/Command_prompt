#include "Header.h"

Position AllocationTree()
{
	Position q = (Position)malloc(sizeof(Tree));
	
	if (q == NULL)
	{
		printf("Memorija nije alocirana!!\n");
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
		printf("Memorija nije alocirana!!\n");
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
	
	printf("\nDirektorij %s je napravljen!!\n", name);
	
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
		printf("\nNe postoji taj direktorij!!\n");
		return curretDir;
	}

	pushStack(curretDir, stack);

	return x;
}

Position popStack(position stack)
{
	position tmp = stack->Next;
	
	if (tmp->Next == NULL)
		printf("\nVec se nalazite u root direktoriju!!\n");

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
int ListDirectory(Position tree)
{
	Position x = tree->FChild;

	if (x == NULL)
	{
		printf("\nDirektorij je prazan!!\n");
		return -1;
	}

	printf("\nLista direktorija:\n");
	while (x != NULL)
	{
		printf("%s\n", x->name);
		x = x->NBrother;
	}

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