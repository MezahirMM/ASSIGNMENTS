#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct Node {
char name[256];
struct Node * next;
};

void choosingLucky(struct Node** head, char *path){
	struct Node *temp = (*head), *pre;

	if(temp != NULL && strcmp(temp->name, path)==0){
	*head = temp->next;
	}
	else{
	while (temp != NULL && strcmp(temp->name, path) != 0){
	pre = temp;
	temp = temp->next;
	}
	if(temp == NULL){
	printf("There is no customer with this name.\n");
	return;
	}
	pre->next = temp->next;
	}
	struct Node *node = (struct Node*)malloc(sizeof(struct Node*));
	struct Node *last = *head;
	strcpy(node->name, temp->name);
	node -> next = NULL;
	
	while(last->next != NULL){
	last = last->next;
	}
	last->next = node;
	free(temp);
}

void admit(struct Node **head){
if (*head == NULL){
printf("The queue is empty.\n");
return;
}
struct Node* next_node = (*head)->next;
printf("%s is admitted.\n", (*head)->name);
free(*head);

*head = next_node;
}

void append(struct Node **head, char *path){
	struct Node *node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *head;
	strcpy(node->name, path);
	node -> next = NULL;

	while(last->next != NULL){
	last = last->next;
	}
	last->next = node;
}

void printList(struct Node *head){
	printf("queue: ");
	while (head != NULL){
	printf("%s,", head->name);
	head = head->next;
	}
}

void deleteList(struct Node **head){
	struct Node* now = *head, *next;
	while(now != NULL){
		next = now -> next;
		free(now);
		now = next;
	}

	*head = NULL;
}

int main(){
	char input[256];
	bool quit = 0;
	struct Node* head = (struct Node*) malloc(sizeof(struct Node));
	strcpy(head -> name, "Turgut");
	head -> next = NULL;
	append(&head, "Madina");
	append(&head, "Asmar");
	append(&head, "Nazrin");
	append(&head, "Nigar");
	printList(head);
	while(!quit)
	{
		printf("\n");
		printf("Enter a command: ");
		scanf("%s", input);
		if (strcmp(input,"quit")==0)
		{
		quit = 1;
		}
		else if (strcmp(input,"admit")==0)
		{
			admit(&head);
		}
		else
		{
		choosingLucky(&head, input);
		}
		printList(head);
	}
	free(head);
	head = NULL;

	deleteList(&head);

	return 0;

}
