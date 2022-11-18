// Preapred by : Ansh Kushwaha
#include <iostream>
using namespace std;
typedef struct node {
    int data;
    node *left;
    node *right;
}node;

node *root = NULL;

node* insert(node* root, int x) {
    if(root == NULL){
        node *tmp = new node;
        tmp->data = x;
        tmp->left = tmp->right = NULL;
        return tmp;
    }
    else{
        if(x > root->data){
            return insert(root->right, x);
        }
        else if(x < root->data){
            return insert(root->left, x);
        }
    }
}

node* create(node *root, int n){
    if(n<=0){
        cout << "Can't create tree." << endl;
        return root;
    }
    if(root!=NULL){
        cout << "Tree already exists." << endl;
        return root;
    }
    
    int x;
    for(int i=0; i<n; i++){
        cout << "Enter data of element " << i+1 << " : ";
        root = insert(root, x);
    }
    return root;
}

int main() {
    // Write C++ code here
    std::cout << "Hello world!";

    return 0;
}
