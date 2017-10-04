#include <stdio.h>
#include <stdlib.h>


struct Node{
	int data;
	struct Node *next;
};


void printlist(struct Node *temp){
	if (temp!=NULL)
	{
		while(temp!=NULL){
		printf(" %d ",temp->data );
		temp = temp->next;
		}
	}else{
		printf("Lisklist is empty\n");
	}
	
}

int main(){

	int choice;
	printf("Enter choice:-");
	scanf("%d",&choice);
	struct Node *first, *temp, *head;
	first = NULL;

	while(choice>0){
		head = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter Element:-");
		scanf("%d",&head->data);

		if (first!=NULL)
		{
			
			temp->next = head;
			temp = head;
			
		}else{
			first = temp = head;
		}

		--choice;
	}
	temp->next = NULL;


	printlist(first);

	return 0;

}


