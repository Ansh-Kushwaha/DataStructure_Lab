//Prepared by : Ansh Kushwaha
#include<iostream>
using namespace std;
#define MAXSIZE 100
int top = -1;
int stack[MAXSIZE];

void create(int n){
	if(top != -1){
		cout << "Stack already exists.\n";
		return;
	}

	if(n<=0 || n>MAXSIZE){
		cout << "Can't create stack. \n";
		return;
	}
	else{
		int x;
		for(int i=1; i<=n; i++){
			cout << "Enter data of " << i << " element : ";
			cin >> x;
			top++;
			stack[top] = x;
		}
	}
}

int isFull(){
	if(top == (MAXSIZE-1))
		return 1;
	else
		return 0;
}

int isEmpty(){
	if(top == -1)
		return 1;
	else
		return 0;
}

void push(int x){
	if(isFull()){
		cout << "Overflow\n";
		return;
	}
	top++;
	stack[top] = x;
}

int pop(){
	if(isEmpty()){
		cout << "Underflow\n";
		return -12345;
	}
	int x = stack[top];
	top--;
	return x;
}

int Top(){
	if(isEmpty()){
		cout << "Stack is empty.\n";
		return -12345;
	}
	return stack[top];
}

void output(){
	if(isEmpty()){
		cout << "Stack is empty.\n";
		return;
	}
	for(int i=top; i>=0; i--)
		cout << stack[i] << "\n";
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