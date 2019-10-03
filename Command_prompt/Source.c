#include "Header.h"

// Main function
int main() {
	Position root = (Position)malloc(sizeof(Tree));
	Position curretDir = root;
	position head = NULL;
	char* name;
	char* selection;
	char* token;
	char* buffer;
	int* running = NULL;
	root->FChild = NULL;
	root->NBrother = NULL;
	root->name = (char*)malloc(5 * sizeof(char));
	strcpy(root->name, "C");
	head = (position)malloc(sizeof(Stack));
	head->Next = NULL;
	running = (int*)malloc(sizeof(int));
	*running = VALID;
	while (*running != INVALID) {
		buffer = (char*)malloc(MAX_SIZE * sizeof(char));
		PrintDirectory(curretDir, head);
		scanf(" %[^\n]", buffer);
		token = strtok(buffer, " ");
		selection = token;
		token = strtok(NULL, " ");
		name = token;
		if (strcmp(selection, "md") == OK) {
			MakeDirectory(curretDir, name);
		}
		else if (strcmp(selection, "cd") == OK) {
			curretDir = ChangeDirectory(curretDir, head, name);
		}
		else if (strcmp(selection, "cd..") == OK) {
			curretDir = popStack(head, root);
		}
		else if (strcmp(selection, "dir") == OK) {
			ListDirectory(curretDir, head);
		}
		else if (strcmp(selection, "exit") == OK) {
			*running = INVALID;
		}
		else if (strcmp(selection, "help") == OK) {
			CallHelp();
		}
		else if (strcmp(selection, "rd") == OK) {
			RemoveDirectory(curretDir, name);
		}
		else if (strcmp(selection, "cls") == OK) {
			system("cls");
		}
		else {
			printf(
				"'%s' is not recognized as an internal or external command, operable "
				"program or batch file. Type 'help'.\n",
				selection);
		}
		printf("\n");
		free(buffer);
	}
	GarbageCollector(root);
	GarbageCollectorStack(head);
	free(name);
	free(running);
	return OK;
}
