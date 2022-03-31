#include <stdlib.h>
#include <stdio.h>

#define P printf(

void create();
void display();
void insert_at_start();
void insert_at_end();
void insert_at_pos();
void delete_at_start();
void delete_at_end();
void delete_at_pos();
void reverse();
void sort();
void search();

struct node {
    int data;
    struct node* next;
};

//declaring a global variable
struct node *head_pointer = NULL;

int main(){
    
    int ch;

    while(1) {
        P"\n******************************************************");
        P"\n*** S E L E C T  F R O M  T H E  F O L L O W I N G ***");
        P"\n1.  CREATE");
        P"\n2.  DISPLAY");
        P"\n3.  INSERT Node at the start of the list");
        P"\n4.  INSERT Node at the end of the list");
        P"\n5.  INSERT Node at a specific position in the list");
        P"\n6.  SEARCH data of a Node in the list");
        P"\n7.  SORT the given linked list");
        P"\n8.  REVERSE the given linked list");
        P"\n9.  DELETE Node at the start of the list");
        P"\n10. DELETE Node at the end of the list");
        P"\n11. DELETE Node at a specific position in the list");
        P"\n12. EXIT or QUIT");
        P"\n******************************************************");

        P"\n\nENTER your choice :  ");
        scanf("%d",&ch);
    
        switch (ch)
        {
        case 1 : 
            create();
            break;
        case 2 : 
            display();
            break;
        case 3 : 
            insert_at_start();
            break;
        case 4 : 
            insert_at_end();
            break;
        case 5 : 
            insert_at_pos();
            break;
        case 6 : 
            search();
            break;
        case 7 : 
            sort();
            break;
        case 8 : 
            reverse();
            break;
        case 9 : 
            delete_at_start();
            break;
        case 10 : 
            delete_at_end();
            break;
        case 11 : 
            delete_at_pos();
            break;
        case 12 : 
            exit(0);
            break;

        default:
        P"\nInvalid Choice entered");
            break;
        }
    }
    return 0;
}

void create(){
    struct node *p, *s1;
    p = (struct node *)malloc(sizeof(struct node));
    P"\nEnter data :  ");
    scanf("%d",&p->data);
    p->next=NULL;

    if( head_pointer ==NULL)
        head_pointer = p;
    else{
        s1 = head_pointer;
        while( s1->next != NULL)
            s1 = s1->next;
        s1->next = p;
    }
}

void display(){
    struct node * s1;
    if(head_pointer == NULL){
        P"\nLinked list is EMPTY...");
        return;
    }
    else{
        s1 = head_pointer;
        P"\nELEMENTS in the linked list are : \n");
        while(s1 != NULL){
            P"%d\t",s1->data);
            s1 = s1->next;
        }
    }
    P"\n");
}

void insert_at_start(){
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    P"\nEnter data :  ");
    scanf("%d",&p->data);
    p->next = NULL;

    if( head_pointer == NULL)
        head_pointer = p;
    else{
        p->next = head_pointer;
        head_pointer = p;
    }
}

void insert_at_end(){
    struct node *p, *s1;
    p=(struct node *)malloc(sizeof(struct node));
    P"\nEnter data :  ");
    scanf("%d",&p->data);
    p->next = NULL;

    if( head_pointer == NULL)
        head_pointer = p;
    else{
        s1 = head_pointer;
        while (s1->next != NULL)
        {
            s1 = s1->next;
        }
        s1->next = p;
    }
}

void insert_at_pos(){
    struct node *p, *s1;
    int i, position;
    p=(struct node *)malloc(sizeof(struct node));
    P"\nEnter position :  ");
    scanf("%d",&position);
    P"\nEnter data :  ");
    scanf("%d",&p->data);
    p->next = NULL;

    if( position == 0)
    {
        p->next = head_pointer;
        head_pointer = p;
    }
    else{
        s1 = head_pointer;
        for(i=0; i<position-1; i++)
            s1 = s1->next;
    }
    p->next = s1->next;
    s1->next = p;
}

void search(){
    int data;
    struct node *s1;
    P"\nEnter data you wish to search for :  ");
    scanf("%d",&data);
    s1 = head_pointer;
    while (s1 != NULL)
    {
        if(s1->data == data){
            P"\n...DATA %d is found at position\n",data);
            break;
        }
        else{
            s1 = s1->next;
        }
    }
}

void sort(){
    struct node *s1, *s2=NULL;
    int temp;

    if(head_pointer == NULL)
        P"\n...list is EMPTY !");
    else{
        s1 = head_pointer;
        while(s1 != NULL)
        {
            s2 = s1->next;
            while(s2 != NULL)
            {
                if(s1->data > s2->data){
                    temp = s1->data;
                    s1->data = s2->data;
                    s2->data = temp;
                }
                s2 = s2->next;
            }
            s1 = s1->next;
        }

        P"\n...After sorting the list : \n");
        while (head_pointer != NULL){
            P"%d\t",head_pointer->data);
            head_pointer = head_pointer->next;
        }
    }
    P"\n");
}

void reverse(){
    struct node *s1, *previous = NULL, *next = NULL;
    s1 = head_pointer;
    while (s1 != NULL)
    {
        next = s1->next;
        s1->next = previous;
        previous = s1;
        s1 = next;
    }
    head_pointer = previous;
    P"\n ~ ...Reversed list is : \n");
    while (head_pointer != NULL)
    {
        P" ~ %d\t",head_pointer->data);
        head_pointer = head_pointer->next;
    }
    P"\n");
}

void delete_at_start(){
    struct node *s1;
    if (head_pointer == NULL){
        P"\nLinked list is EMPTY");
        exit(1);
    }
    else{
        s1 = head_pointer;
        head_pointer = head_pointer->next;
        P"\nThe deleted element is : %d",s1->data);
        free(s1);
    }
    P"\n");
}

void delete_at_end(){
    struct node *s1, *temp;
    if (head_pointer == NULL){
        P"\nLinked list is EMPTY");
        exit(0);
    }
    else if(head_pointer->next == NULL){
        s1 = head_pointer;
        s1 = NULL;
        P"\nThe deleted element is : %d",s1->data);
        free(s1);
    }
    else{
        s1 = head_pointer;
        while(s1->next != NULL){
            temp = s1;
            s1 = s1->next;
        }
        temp->next = NULL;
        P"\nThe deleted element is : %d",s1->data);
        free(s1);
    }
    P"\n");
}

void delete_at_pos(){
    int i, position;
    struct node *s1, *temp;
    if(head_pointer == NULL){
        P"\nLinked list is EMPTY");
        exit(0);
    }
    else{
        P"\nENTER the position of the element to delete : ");
        scanf("%d",&position);
        
        if(position == 0){
            s1 = head_pointer;
            head_pointer = head_pointer->next;
            P"\nThe deleted element is : %d",s1->data);
            free(s1);
        }
        else{
            s1 = head_pointer;
            for(i=0; i<position; i++ && s1->next != NULL){
                temp = head_pointer;
                head_pointer = head_pointer->next;
            }
        }
        temp->next = s1->next;
        P"\nThe deleted element is : %d",s1->data);
        free(s1);
    }
    P"\n");
}