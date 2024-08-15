#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int value;
    struct node *left, *right;

}Node;

typedef struct{

    Node *root;

}Tree;

Node* insert(Node *root, int num);
void print_tree(Node *root);

int main(){

    Tree tree;
    tree.root = NULL;
    int num;

    tree.root = insert(tree.root,500);
    tree.root = insert(tree.root,700);
    tree.root = insert(tree.root,200);
    tree.root = insert(tree.root,300);

    print_tree(tree.root);


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
