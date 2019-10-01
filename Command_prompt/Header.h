#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VALID 1
#define INVALID 0
#define OK 0
#define NOT_OK -1
#define MAX_SIZE 1024
struct _tree;
typedef struct _tree* Position;
typedef struct _tree {
	char* name;
	Position FChild;
	Position NBrother;
} Tree;
struct _stack;
typedef struct _stack* position;
typedef struct _stack {
	Position tree;
	position Next;
} Stack;
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
int RemoveDirectory(Position, char*);
#endif
