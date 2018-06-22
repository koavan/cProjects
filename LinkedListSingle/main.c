
/*
 * Singly Linked List for Demonstration
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
struct node
{
        char data;
        struct node * next;
}*head,*tail;

void createNode(char input)
{
    struct node *temp;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data=input;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        temp->next=NULL;
    }
    else
    {
        temp->data=input;
        temp->next=NULL;
        tail->next=temp;
        tail=temp;
    }
}

void searchNode(char searchinput)
{
    struct node * ptr;
    ptr=head;
    do
    {
        if(ptr->data == searchinput)
        {
            printf("Data present at %x\n",ptr);
            break;
        }
        ptr=ptr->next;
    }while(ptr->next != NULL);
}

void deleteHead()
{
    struct node * ptr;
    ptr=head;
    head = ptr->next;
    free(ptr);
}

void deleteTail()
{
    struct node * ptr, *prev=NULL;
    ptr=head;
    while(ptr->next != NULL)
    {
        prev = ptr;
        ptr=ptr->next;
    }
    tail=prev;
    prev->next=NULL;
    free(ptr);
}

void deleteNode(char input)
{
	struct node * crnt, *prev, *nxt;
	crnt=head;
	while(crnt->next!=NULL)
	{
		prev=crnt;
		nxt=crnt->next;
		if(crnt->data == input)
		{
			prev->next=nxt;
			free(crnt);
		}
		crnt=nxt;
	}
}

int main(int argc, char **argv)
{
    createNode('a');
    createNode('b');
    createNode('c');
    createNode('d');
    searchNode('b');
    searchNode('c');
    deleteHead();
    deleteTail();
    return 0;
}