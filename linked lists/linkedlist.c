/*This code is a study about linked lists in C language.
It just adds numbers at the top, middle and end of a list, it does not remove*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{

    int value;
    struct node *next;

}Node;

//Puts the number always on top of the list
void insert_at_beginning(Node **list, int number){

    Node *new = malloc(sizeof(Node)); 

    if(new){

        new->value = number;
        new->next = *list;
        *list = new;
    }

    else{

        printf("Error\n");
        exit(0);
    }

}

/*Puts the value in the middle of the list*/
/*the temp variable is used to go through the list to find the previous value
the previous value is the value before the value i want to put on the list
it cannot be the last value (temp->next CANNOT be NULL) because i want to put in the middle and not at the end*/

void insert_at_middle(Node **list, int number, int previous){

    Node *temp, *new = malloc(sizeof(Node));

    if(new){

        new->value = number;

        //checks if the list is empty.
        if(*list==NULL){
            new->next = NULL;
            *list = new;
        }

        else{
            
            temp = *list;
            while(temp->value != previous && temp->next != NULL){
                temp = temp->next; 
            } 

            new->next = temp->next;
            temp->next = new;


        }

    }

    else{

        printf("Error\n");
        exit(0);
    }

}

//Puts the number at the end of the list
/*observation: putting at the end doesn't necessarily mean that the list is full.
It can be empty, and i have to check that*/
void insert_at_end(Node **list, int number){


    //I have to use a temporary variable to go through the list to find the last element
    Node *temp, *new = malloc(sizeof(Node));

    if(new){

        new->value = number;
        new->next = NULL;
        
        //check: it is the first? then:

        if(*list == NULL){
            *list = new;
        }

        //check: it is not the first? then:
        else{

            temp = *list;
            while(temp->next){ //while the next is different from NULL, update temp to the next element
                temp = temp->next;
            }
            temp->next = new;

        }

    }

    else{

        printf("Error\n");
        exit(0);

    }
}

void free_list(Node *list){

    Node *temp;

    while(list != NULL){
        temp = list;
        list = list->next;
        free(temp);
    }
}

void print_list(Node *list){

    while(list){
        printf("%d ", list->value);
        list = list->next;
    }
}

///////////////////////////////////////////////////////////////////////////

int main(){

    Node *list = NULL;

    insert_at_beginning(&list,10);
    insert_at_middle(&list,20,10);
    insert_at_end(&list,30);
    print_list(list);
    free(list);
    
return 0;
}
