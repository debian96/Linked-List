#include <stdio.h>
#include <stdlib.h>


struct Node{
	int data;
	struct Node *next;
};

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void count();
void search();
void reverse();



struct Node *head=NULL;

int main(){

	int choice;

	while(1){

		printf("\n---------------------------------------\n");
                printf("\n 1.Create     \n");
                printf("\n 2.Display    \n");
                printf("\n 3.Insert at the beginning    \n");
                printf("\n 4.Insert at the end  \n");
                printf("\n 5.Insert at specified position       \n");
                printf("\n 6.Delete from beginning      \n");
                printf("\n 7.Delete from the end        \n");
                printf("\n 8.Delete from specified position     \n");
                printf("\n 9.Size of list     \n");
                printf("\n 10.Search a element     \n");
                printf("\n 11.Reverse the list     \n");
                printf("\n 12.Exit       \n");
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
				display();
				break;
			case 3:
				insert_begin();
				break;
			case 4:
				insert_end();
				break;
			case 5:
				insert_pos();
				break;
			case 6:
				delete_begin();
				break;
			case 7:
			    delete_end();
                break;
            case 8:
            	delete_pos();
            	break;
            case 9:
            	count();
            	break;
            case 10:
            	search();
            	break;
            case 11:
            	reverse();
            	break;
            case 12:
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

    if (head==NULL)
    {
    	head = temp;
    }else{
    	ptr = head;
    	while(ptr->next!=NULL){
    		ptr = ptr->next;
    	}
    	ptr->next = temp;
    }
}

void display(){
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

	    if (head==NULL)
	    {
	    	head = temp;
	    }else{
	    	temp->next = head;
	    	head = temp;
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

	    if (head==NULL)
	    {
	    	head = temp;
	    }else{
	    	ptr = head;
	    	while(ptr->next!=NULL){
	    		ptr = ptr->next;
	    	}
	    	ptr->next = temp;
	    }
	}

	
}

void insert_pos(){
	struct Node *temp, *ptr;
	int pos,i;
	temp = (struct Node*)malloc(sizeof(struct Node));

		if(head==NULL)
        {
                printf("\nList is Empty:\n");
                return;
        }else{
        	if (temp==NULL)
			{
				printf("\nOut of Memory Space:\n");
        		exit(0);
			}
			printf("\nEnter the position for the new node to be inserted:\t");
    		scanf("%d",&pos);
			printf("\nEnter the data value for the node:\t");
		    scanf("%d",&temp->data);
		    temp->next = NULL;

		    if (pos==0)
		    {
		    	temp->next = head;
		    	head = temp;
		    }else{
		    	ptr = head;
		    	for(i=0;i<pos-1;i++)
		                {
		                        ptr=ptr->next;
		                        if(ptr==NULL)
		                        {
		                                printf("\nPosition not found:[Handle with care]\n");
		                                return;
		                        }
		                }
		                temp->next =ptr->next ;
		                ptr->next=temp;
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
                printf("\nThe deleted element is :%d\t",ptr->data);
                free(ptr);
        }
}

void delete_pos(){
	struct Node *ptr,*temp;
	int pos,i;
        if(head==NULL)
        {
                printf("\nList is Empty:\n");
                return;
        }else{
        	printf("\nEnter the position for the new node to be inserted:\t");
   			scanf("%d",&pos);
   			if (pos==0)
   			{
   				ptr = head;
   				head = head->next;
   				printf("\nThe deleted element is :%d\t",ptr->data);
                free(ptr);
   			}else{
   				ptr=head;
                        for(i=0;i<pos;i++)
                        {
                                temp=ptr;
                                ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition not Found:\n");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("\nThe deleted element is:%d\t",ptr->data );
                        free(ptr);
   			}
        }
}

void count(){
	struct Node *ptr;
	int count=0;
	if (head==NULL)
	{
		printf("\nList is Empty:\n");
        return;
	}else{
		ptr = head;
		while(ptr!=NULL){
			count++;
			ptr = ptr->next;
		}
		printf("\nThe size of list is:\t%d\n",count );
	}
}

void search(){
	struct Node *ptr;
	int pos=0,search,flag=0;
	if (head==NULL)
	{
		printf("\nList is Empty:\n");
        return;
	}else{
		printf("\nEnter the element to search:\t");
		scanf("%d",&search);
		ptr = head;
		while(ptr!=NULL){
			if (ptr->data==search)
			{
				flag = 1;
				break;
			}
			pos++;
			ptr = ptr->next;
		}
		if (flag==0)
		{
			printf("\nSearched element %d not fount \n",search);
		}else{
			printf("\nSearched element %d fount at position %d\n",search,pos);
		}
	}
}

void reverse(){
	struct Node *ptr, *prev=NULL, *nextnode=NULL;
	if (head==NULL)
	{
		printf("\nList is Empty:\n");
        return;
	}else{
		ptr = head;
		while(ptr!=NULL){
			nextnode = ptr->next;
			ptr->next = prev;
			prev = ptr;
			ptr = nextnode;
		}
		printf("\nList is Reversed:\n");
		head = prev;
		
	}
}

