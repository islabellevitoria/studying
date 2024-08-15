#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int value;
    struct node *left, *right;

}Node;

Node* insert(Node *root, int num);
void print_tree(Node *root);

int main(){

    Node *root;
    root = NULL;
    int num;

    root = insert(root,500);
    root = insert(root,700);
    root = insert(root,200);
    root = insert(root,300);

    print_tree(root);


return 0;

}


Node* createNode(int num){

    Node *new = (Node*)malloc(sizeof(Node));
    new->value = num;
    new->left = NULL;
    new->right = NULL;

    return new;

}

Node* insert(Node *root, int num){
    if(root == NULL){
        Node *new = createNode(num);
        return new;
    }
    else{
        if(num < root->value){
            root->left = insert(root->left,num);
        }
        if(num > root->value){
            root->right = insert(root->right,num);
        }

        return root;
    }
}

void print_tree(Node *root){

    if(root){
        print_tree(root->left);
        printf("%d ", root->value);
        print_tree(root->right);
    }

}
