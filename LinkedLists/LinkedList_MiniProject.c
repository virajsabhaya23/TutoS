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
    struct Node* next;
};

//declaring a global variable
struct Node *head_pointer = NULL;

int main(){
    
    int ch;


    return 0;
}