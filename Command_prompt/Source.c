#include "Header.h"

int main()
{
	Position root=(Position)malloc(sizeof(Tree));
	Position curretDir = root;
	position head = AllocationStack();
	char *name;
	int i = -1;

	name = (char*)malloc(21 * sizeof(char));
	root->FChild = NULL;
	root->NBrother = NULL;
	root->name = (char*)malloc(5 * sizeof(char));
	strcpy(root->name, "root");
	head->Next = AllocationStack();
	head->Next->tree = root;
	head->Next->Next = NULL;

	while (i != 0)
	{
		printf("\n\nYou are in %s directory:\n", curretDir->name);
		printf("Select operation:\n");
		printf("1. md (Make directory)\n");
		printf("2. cd (Change directory)\n");
		printf("3. cd.. (Previous directory)\n");
		printf("4. dir (List directories)\n");
		printf("0. exit\n");
		printf("Your selection: ");
		scanf(" %d", &i);

		switch (i)
		{
		case 1:
			printf("md ");
			scanf(" %s", name);
			MakeDirectory(curretDir, name);
			break;
		case 2:
			printf("cd ");
			scanf(" %s", name);
			curretDir = ChangeDirectory(curretDir, head, name);
			break;
		case 3:
			printf("cd..\n");
			curretDir = popStack(head);
			break;
		case 4:
			printf("dir\n");
			ListDirectory(curretDir, head);
			break;
		case 0:
			break;
		default:
			printf("'%d' is not recognized as an internal or external command, operable program or batch file.\n", i);
			break;
		}
	}

	GarbageCollector(root);
	free(name);
	return 0;
}