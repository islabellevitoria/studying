/*I ADDED THE FUNCTIONS TO SEARCH,COUNT THE SIZE, AND REMOVE ELEMENTS*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int value;
    struct node *left, *right;

}Node;

Node* insert(Node *root, int num);
void print_tree(Node *root);
int size(Node* root);
int search(Node* root, int key);
Node* removeFromTree(Node* root, int key);

int main(){

    Node *root;
    root = NULL;
    int num;

    root = insert(root,500);
    root = insert(root,700);
    root = insert(root,200);
    root = insert(root,300);
    root = insert(root,275);
    root = insert(root,800);
    root = insert(root,690);
    root = insert(root,185);

    print_tree(root);

    printf("\nsize: %d", size(root));

    printf("\nkey found: %d\n", search(root,300));

    removeFromTree(root,300);
    removeFromTree(root,500);

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

int size(Node *root){
    if(root == NULL)
        return 0;
    else
        return 1 + size(root->left) + size(root->right);
}

int search(Node *root, int key){
    if(root==NULL){
        return 0;
    }
    else{
        if(root->value == key){
            return 1;
        }
        else{
            if(key < root->value){
                return search(root->left,key);
            }
            else{
                return search(root->right,key);
            }
        }
    }
}

Node* removeFromTree(Node *root, int key){

    /*if the tree is empty*/
    if(root == NULL){ 

        return NULL;
    }

    /*if there's at least 1 element*/
    else{
        if(root->value == key){

            if(root->left == NULL && root->right == NULL){

                free(root);
                return NULL;

            }

            else if(root->left == NULL || root->right == NULL){
                Node *temp;
                if(root->left)
                    temp = root->left;
                if(root->right)
                    temp = root->right;
                free(root);
                return temp;
            }

            else if(root->left && root->right){
                Node *temp = root->left;
                while(temp->right){
                    temp = temp->right;
                }
                root->value = temp->value;
                temp->value = key;
                root->left = removeFromTree(root->left,key);
                return root;
            }            

            
        }
        else {
            if(key < root->value){
                root->left = removeFromTree(root->left,key);
            }
            else{
                root->right = removeFromTree(root->right,key);
            }

            return root;
        }
    }
}
