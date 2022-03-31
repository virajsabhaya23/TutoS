#include <stdlib.h>
#include <stdio.h>

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
        printf("\n*** S E L E C T  F R O M  T H E  F O L L O W I N G ***");
        printf("\n1.  CREATE");
        printf("\n2.  DISPLAY");
        printf("\n3.  INSERT Node at the start of the list");
        printf("\n4.  INSERT Node at the end of the list");
        printf("\n5.  INSERT Node at a specific position in the list");
        printf("\n6.  SEARCH data of a Node in the list");
        printf("\n7.  SORT the given linked list");
        printf("\n8.  REVERSE the given linked list");
        printf("\n9.  DELETE Node at the start of the list");
        printf("\n10. DELETE Node at the end of the list");
        printf("\n11. DELETE Node at a specific position in the list");
        printf("\n12. EXIT or QUIT");
        printf("\n******************************************************");

        printf("\n\nENTER your choice :  ");
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
        printf("\nInvalid Choice entered");
            break;
        }
    }
    return 0;
}

void create(){
    struct node *p, *s1;
    p = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data :  ");
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
        printf("\nLinked list is EMPTY...");
        return;
    }
    else{
        s1 = head_pointer;
        printf("\nELEMENTS in the linked list are : \n");
        while(s1 != NULL){
            printf("%d\t",s1->data);
            s1 = s1->next;
        }
    }
    printf("\n");
}

void insert_at_start(){
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter data :  ");
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
    printf("\nEnter data :  ");
    scanf("%d",&p->data);
    p->next = NULL;

    if( head_pointer == NULL)
        head_pointer = p;
    else{
        head_pointer = p;
        while (s1->next = NULL)
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
    printf("\nEnter position :  ");
    scanf("%d",&position);
    printf("\nEnter data :  ");
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
    printf("\nEnter data you wish to search for :  ");
    scanf("%d",&data);
    s1 = head_pointer;
    while (s1 != NULL)
    {
        if(s1->data == data){
            printf("\n ...The data %d is found",data);
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
        printf("\n...list is EMPTY !");
    else{
        s1 = head_pointer;
        while(s1 != NULL){
            s2 = s1->next;
            
            while(s2 != NULL){
                if(s1->data > s2->data){
                    temp = s1->data;
                    s1->data = s2->data;
                    s2->data = temp;
                }
                s2 = s2->next;
            }
            
            s1 = s1->next;
        }

        printf("\n...After sorting the list : ");
        while (head_pointer != NULL){
            printf("%d\t",head_pointer->data);
            head_pointer = head_pointer->next;
        }
        
    }
}

void reverse(){
    
}

void delete_at_start(){

}

void delete_at_end(){

}

void delete_at_pos(){

}