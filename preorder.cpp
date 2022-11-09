#include <iostream>
using namespace std;

typedef struct node{
    int data;
    node* left;
    node* right;
}node;

node* createNode(int val){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void preorder(node *root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

node* insertNode(node* node, int val){
    if(node == NULL)
        return createNode(val);
    if(val < node->data)
        node->left = insertNode(node->left, val);
    else if(val > node->data)
        node->right = insertNode(node->right, val);
    return node;
}

int main() {
    node* root = NULL;
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 2);
    root = insertNode(root, 9);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    cout << "Preorder traversal of Binary Search Tree : ";
    preorder(root);
    cout << "\n";

    return 0;
}
