#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node* create(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node *root, int data){
    if(root == NULL){
        return create(data);
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    }
    else if(data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

Node *search(Node* root, int data){
    if(root==NULL){
        printf("Element not found");
        return root;
    }
    if(data < root->data ){
        return search(root->left, data);
    }else if(data > root->data){
        return search(root->right, data);
    }else{
        printf("Element Found");
        return root;
    }
}

int findMin(Node *root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root->data;
}

Node* deleteNode(Node *root, int data){
    if(root == NULL){
        return root;
    }
    if(data < root->data){
        root->left = deleteNode(root->left, data);
    }
    else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }
    else{
        if(root->left == NULL){
            return root->right;
        }else if(root->right == NULL){
            return root->left;
        }
        root->data = findMin(root->right);
        root->right = deleteNode(root->right, root->data);
    }
    return root;
}

Node *copyTree(Node *source)
{
    if (source == NULL)
    {
        return NULL;
    }

    Node *newNode = create(source->data);
    newNode->left = copyTree(source->left);
    newNode->right = copyTree(source->right);

    return newNode;
}

int searchItter(Node *root, int data){
    while(root!=NULL){
        if(root->data == data){
            printf("Element found");
            return 1;
        }
        if(data < root->data ){
            root = root->left;
        }else{
            root = root->right;
        }
    }
    printf("Element not found G.");
    return 0;
}

void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int areEqualTrees(Node *tree1, Node *tree2)
{
    // Base cases: if both trees are empty, they are equal
    if (tree1 == NULL && tree2 == NULL)
    {
        return 1;
    }
    
    // If one of the trees is empty and the other is not, they are not equal
    if (tree1 == NULL || tree2 == NULL)
    {
        return 0;
    }

    // Check if the current nodes are equal and recursively check left and right subtrees
    return (tree1->data == tree2->data) &&
           areEqualTrees(tree1->left, tree2->left) &&
           areEqualTrees(tree1->right, tree2->right);
}

int main(){
    Node *root = create(10);
    insert(root, 20);
    insert(root, 15);
    insert(root, 25);
    insert(root, 18);
    insert(root, 22);
    insert(root, 14);
    search(root, 20);
    inorder(root);
    deleteNode(root,20);
    inorder(root);
}
