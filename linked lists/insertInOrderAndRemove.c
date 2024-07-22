#include<stdio.h>
#include<stdlib.h>

typedef struct node{

    int value;
    struct node *next;

}Node;

void insert_in_order(Node **list, int number){

    Node *temp, *new = malloc(sizeof(Node));
    new->value = number;

    if(new){

        if(*list == NULL){
            *list = new;
        }
        else if((*list)->value > new->value){
            new->next = *list;
            *list = new;
            /*or call function insert at beginning with the correct arguments*/
        }
        else{
            
            temp = *list;

            while(temp->next!= NULL && temp->next->value < new->value){ 
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

Node* removing(Node **list, int number){

    Node *removed = NULL, *temp;

    if(*list){

        if((*list)->value == number){
            removed = *list;
            *list = removed->next;
        }
        else{
            temp = *list;
            while(temp->next && temp->next->value != number){
                temp = temp->next;
            }
            //this while loop will break when it finds the value i want to remove
            if(temp->next){ //if temp->next exists, it means it is the value i want to remove
                removed = temp->next;
                temp->next = removed->next;
            }
        }

    }
    else{
        printf("list empty\n");
        exit(0);
    }

    return removed;
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

int main(){

    Node *list = NULL;
    Node *out = NULL;

    insert_in_order(&list, 4);
    insert_in_order(&list, 13);
    insert_in_order(&list, 9);
    insert_in_order(&list, 2);

    out = removing(&list,13);
    if(out){
        free(out);
    }

    print_list(list);
    
    free_list(list);
    
return 0;
}