#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _tree;
typedef struct _tree* Position;
typedef struct _tree
{
	char* name;
	Position FChild;
	Position NBrother;
}Tree;

struct _stack;
typedef struct _stack* position;
typedef struct _stack
{
	Position tree;
	position Next;
}Stack;

Position AllocationTree();
position AllocationStack();
Position ChangeDirectory(Position, position, char*);
Position popStack(position, Position);
int pushStack(Position, position);
int MakeDirectory(Position, char*);
int ListDirectory(Position);
int GarbageCollector(Position);
int CallHelp();
int PrintDirectory(Position, position);
int PrintDirectoryF(position);