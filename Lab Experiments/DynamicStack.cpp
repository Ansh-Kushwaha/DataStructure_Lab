//Prepared by : Ansh Kushwaha
#include<iostream>
using namespace std;

typedef struct node{
	int data;
	node *link;
}node;

node *top = NULL;

int isEmpty(){
	if(top == NULL)
		return 1;
	else
		return 0;
}

int isFull(){
	node *tmp = new node;
	if(tmp != NULL){
		delete tmp;
		return 0;
	}
	else
		return 1;
}

void create(int n){
	if(!(isEmpty())){
		cout << "Stack already exists.\n";
		return;
	}
	if(n<=0){
		cout << "Can't create stack.\n";
		return;
	}
	else{
		int x;
		for(int i=1; i<=n; i++){
			cout << "Enter data of " << i << " element : ";
			cin >> x;
			node *tmp = new node;
			tmp->data = x;
			tmp->link = top;
			top = tmp;
		}
	}
}

void push(int x){
	if(isFull()){
		cout << "Overflow\n";
		return;
	}
	else{
		node *tmp = new node;
		tmp->data = x;
		tmp->link = top;
		top = tmp;
	}
}

int pop(){
	if(isEmpty()){
		cout << "Underflow\n";
		return -12345;
	}
	else{
		node *tmp = top;
		int x = tmp->data;
		top = top->link;
		delete tmp;
		return x;
	}
}

int Top(){
	if(isEmpty()){
		cout << "Stack is empty.\n";
		return -12345;
	}
	else
		return top->data;
}

void output(){
	if(isEmpty()){
		cout << "Stack is empty.\n";
		return;
	}
	else{
		node *tmp = top;
		while(tmp != NULL){
			cout << tmp->data << "\n";
			tmp = tmp->link;
		}
	}
}

int main() {
	int n, choice, x, t;
	bool cont = true;
	cout << "Prepared by Ansh Kushwaha\n";
	while(cont){
	cout << "********** MENU **********\n";
		cout << "1. CREATE\n";
		cout << "2. PUSH\n";
		cout << "3. POP\n";
		cout << "4. ISEMPTY\n";
		cout << "5. ISFULL\n";
		cout << "6. TOP\n";
		cout << "7. OUTPUT\n";
		cout << "8. EXIT\n";
		cout << "***************************\n";
		cout << "Enter your choice : ";
		cin >> choice;
		cout << "\n";

		switch(choice){
			case 1:
				cout << "Enter the size of STACK : ";
				cin >> n;
				create(n);
				break;
			case 2:
				cout << "Enter the element to push : ";
				cin >> x;
				push(x);
				break;
			case 3:
				t = pop();
				if(t == -12345)
					break;
				else
					cout << "POPPED " << t << "\n";
				break;
			case 4:
				if(isEmpty())
					cout << "Stack is empty.\n";
				else
					cout << "Stack is not empty.\n";
				break;
			case 5:
				if(isFull())
					cout << "Stack is full.\n";
				else
					cout << "Stack is not full.\n";
				break;
			case 6:
				t = Top();
				if(t == -12345)
					break;
				else
					cout << "Top element = " << t << "\n";
				break;
			case 7:
				cout << "___________________\n";
				cout << "Elements in Stack : \n";
				output();
				cout << "___________________\n";
				break;
			case 8:
				cout << "Exiting...\n";
				cont = false;
				break;

			default: cout << "Incorrect choice.\n"; 
		}
		cout << "\n";
	}
	return 0;
}