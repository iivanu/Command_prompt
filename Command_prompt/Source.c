#include "Header.h"

int main()
{
	Position root=(Position)malloc(sizeof(Tree));
	Position curretDir = root;
	Stack head;
	char *name;
	char *selection;
	char *token;
	char *buffer;
	int i = -1;

	buffer = (char*)malloc(21 * sizeof(char));
	root->FChild = NULL;
	root->NBrother = NULL;
	root->name = (char*)malloc(5 * sizeof(char));
	strcpy(root->name, "root");
	head.Next = AllocationStack();
	head.Next->tree = root;	//First on stack
	head.Next->Next = NULL;

	while (i != 0)
	{
		printf("\n\nYou are in %s directory: ", curretDir->name);
		scanf(" %[^\n]", buffer);
		
		token = strtok(buffer, " ");
		selection = token;
		token = strtok(NULL, " ");
		name = token;

		if (strcmp(selection, "md") == 0)
			MakeDirectory(curretDir, name);

		else if (strcmp(selection, "cd") == 0)
			curretDir = ChangeDirectory(curretDir, &head, name);

		else if (strcmp(selection, "cd..") == 0)
			curretDir = popStack(&head);

		else if (strcmp(selection, "dir") == 0)
			ListDirectory(curretDir, &head);

		else if (strcmp(selection, "exit") == 0)
			i = 0;

		else if (strcmp(selection, "help") == 0)
			CallHelp();

		else
			printf("'%s' is not recognized as an internal or external command, operable program or batch file. Type 'help'.\n", selection);	
	}

	GarbageCollector(root);
	free(name);
	return 0;
}