#include <iostream>
using namespace std;

typedef struct node {
	int key;
	node *left, *right;
}node;

node* newNode(int item) {
	node* temp = (node*)malloc(sizeof(node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(node *root) {
	if(!root)
		return;
	else {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

node* insert(node* root, int key) {
	if(root == NULL) {
		return newNode(key);
	}
	if(key < root->key)
		root->left = insert(root->left, key);
	else if(key > root->key)
		root->right = insert(root->right, key);
	return root;
}

node* search(node* root, int key) {
	if (root == NULL || root->key == key)
	   return root;
	
	if (root->key < key)
	   return search(root->right, key);
 
	return search(root->left, key);
}

node* minValueNode(node *root) {
	node *curr = root;
	while(curr && curr->left != NULL)
		curr = curr->left;
	return curr;
}

node* deleteNode(node *root, int key) {
	if(!root)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else {
		if (root->left == NULL) {
			node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL) {
			node* temp = root->left;
			delete root;
			return temp;
		}

		struct node* temp = minValueNode(root->right);
		root->key = temp->key;

		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

int main() {
	node* root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);

	cout << "Inorder traversal of the given tree \n";
	inorder(root);

	cout << "\nDelete 20\n";
	root = deleteNode(root, 20);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nDelete 30\n";
	root = deleteNode(root, 30);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nDelete 50\n";
	root = deleteNode(root, 50);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);
	cout << "\n";

	return 0;
}