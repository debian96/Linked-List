#include <stdio.h>
#include <stdlib.h>


struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
};

void create();
void display_forward();
void display_backward();
void insert_begin();
void insert_end();
void delete_begin();
void delete_end();




struct Node *head=NULL;
struct Node *last=NULL;

int main(){

	int choice;

	while(1){

		printf("\n---------------------------------------\n");
                printf("\n 1.Create     \n");
                printf("\n 2.Display Forward    \n");
                printf("\n 3.Display Backward    \n");
                printf("\n 4.Insert at the beginning    \n");
                printf("\n 5.Insert at the end  \n");
                printf("\n 6.Delete from beginning      \n");
                printf("\n 7.Delete from the end        \n");           
                printf("\n 8.Exit       \n");
        printf("\n---------------------------------------\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		printf("\n---------------------------------------\n");

		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
				display_forward();
				break;
			case 3:
				display_backward();
				break;
			case 4:
				insert_begin();
				break;
			case 5:
				insert_end();
				break;
			case 6:
				delete_begin();
				break;
			case 7:
				delete_end();
				break;
			case 8:
			    exit(0);
                break;          
            default:
                printf("\n Wrong Choice:\n");
                break;
		}
	}
}


void create(){
	struct Node *temp, *ptr;
	temp = (struct Node*)malloc(sizeof(struct Node));

	if (temp==NULL)
	{
		printf("\nOut of Memory Space:\n");
        exit(0);
	}
	printf("\nEnter the data value for the node:\t");
    scanf("%d",&temp->data);
    temp->next = NULL;
    temp->prev = NULL;

    if (head==NULL)
    {
    	head = temp;
    	last = temp;
    }else{
    	ptr = head;
    	while(ptr->next!=NULL){
    		ptr = ptr->next;
    	}
    	ptr->next = temp;
    	last = temp;
    	temp->prev = ptr;
    }
}

void display_forward(){
	struct Node *ptr;

	if (head==NULL)
	{
		printf("\nList is empty:\n");
        return;
	}else{
		ptr=head;
            printf("\nThe List elements are:\n");
            while(ptr!=NULL)
            {
                printf("%d\t",ptr->data );
                ptr=ptr->next ;
            }
	}
}

void display_backward(){
	struct Node *ptr;

	if (last==NULL)
	{
		printf("\nList is empty:\n");
        return;
	}else{
		ptr=last;
            printf("\nThe List elements are:\n");
            while(ptr!=NULL)
            {
                printf("%d\t",ptr->data );
                ptr=ptr->prev ;
            }
	}
}

void insert_begin(){
	struct Node *temp;

	if (head==NULL)
	{
		printf("\nList is Empty:\n");
        return;
	}else{
		temp = (struct Node*)malloc(sizeof(struct Node));

		if (temp==NULL)
		{
			printf("\nOut of Memory Space:\n");
	        exit(0);
		}
		printf("\nEnter the data value for the node:\t");
	    scanf("%d",&temp->data);
	    temp->next = NULL;
	    temp->prev = NULL;

	    if (head==NULL)
	    {
	    	head = temp;
	    }else{
	    	temp->next = head;
	    	last = head;
	    	head = temp;
	    	head->next->prev = head;
	    }
	}
}

void insert_end(){
	struct Node *temp, *ptr;
	if (head==NULL)
	{
		printf("\nList is Empty:\n");
        return;
	}else{
		temp = (struct Node*)malloc(sizeof(struct Node));

		if (temp==NULL)
		{
			printf("\nOut of Memory Space:\n");
	        exit(0);
		}
		printf("\nEnter the data value for the node:\t");
	    scanf("%d",&temp->data);
	    temp->next = NULL;
		temp->prev = NULL;
	    if (head==NULL)
	    {
	    	head = temp;
	    }else{
	    	ptr = head;
	    	while(ptr->next!=NULL){
	    		ptr = ptr->next;
	    	}
	    	ptr->next = temp;
	    	last = temp;
    		temp->prev = ptr;
	    }
	}

	
}



void delete_begin(){
	struct Node *ptr;
        if(head==NULL)
        {
                printf("\nList is Empty:\n");
                return;
        }
        else
        {
        		ptr = head;
                head=head->next ;
                head->prev = NULL;
                printf("\nThe deleted element is :%d\t",ptr->data);
                free(ptr);
        }
}

void delete_end(){
	struct Node *ptr,*temp;
        if(head==NULL)
        {
                printf("\nList is Empty:\n");
                return;
        }else if(head->next==NULL){
        		ptr = head;
        		head = NULL;
        		printf("\nThe deleted element is:%d\t",ptr->data);
        		free(ptr);
        }
        else 
        {
        		ptr = head;
        		while(ptr->next!=NULL){
        			temp=ptr;
        			ptr = ptr->next;
        		}
        		temp->next = NULL;
        		last = temp;
                printf("\nThe deleted element is :%d\t",ptr->data);
                free(ptr);
        }
}


