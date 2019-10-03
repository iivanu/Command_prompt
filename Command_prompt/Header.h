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

//Tree and stack structures
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

// Allocation functions
Position AllocationTree();
position AllocationStack();

// Command functions
Position ChangeDirectory(Position, position, char*);
int MakeDirectory(Position, char*);
int ListDirectory(Position);
int RemoveDirectory(Position, char*);

// Stack functions
Position popStack(position, Position);
int pushStack(Position, position);

// Printing functions
int CallHelp();
int PrintDirectory(Position, position);
int PrintDirectoryF(position);

// Garbage collector fuctions
int GarbageCollector(Position);
int GarbageCollectorStack(position);
#endif
