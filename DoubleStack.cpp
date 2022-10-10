#include <iostream>
using namespace std;

#define SIZE 10
int stack[SIZE];
int top1 = -1;
int top2 = 10;

void create(int l, int r){
	if(l+r > SIZE){
		cout << "Can't create \n";
		return; 
	}
	
	int x;
	for(int i=0; i<l; i++){
		cout << "Enter " << i+1 << " element of stack 1 : ";
		cin >> x;
		top1++;
		stack[top1] = x;
	}
	cout << "\nStack 1 created \n"; 
	for(int i=0; i<r; i++){
		cout << "Enter " << i+1 << " element of stack 2 : ";
		cin >> x;
		top2--;
		stack[top2] = x;
	}
	cout << "\nStack 2 created \n";
}

bool isFull(){
	if(top1 == (top2-1))
		return true;
	else
		return false;
}

bool isEmpty(){
	if(top1 == -1 && top2 == SIZE)
		return true;
	else
		return false;
}
void insert(){
	
}
int main() {
	int choice, l, r, n, x;
	bool c = true;
	while(c){
		cout << "1 :create\n";
		cout << "2 :isEmpty\n";
		cout << "3 :isFull\n";
		cout << "4 :output\n";
		cout << "5 :top\n";
		cout << "6 :pop\n";
		cout << "7 :push\n";
		cout << "8 : EXIT\n";
		cout << "\nEnter your choice \n";
		cin >> choice;

		switch(choice){
			case 1:
				cout << "Enter size of Stack 1 and 2 (Two integers) : ";
				cin >> l >> r;
				create(l, r);
				break;
			case 2:
				if(isEmpty())
					cout << "Stacks are empty.\n";
				else
					cout << "Stacks are not empty.\n";
				break;
			case 3:
				if(isFull())
					cout << "Stack Full.\n";
				else
					cout << "Stack not Full.\n";
				break;
			case 4:
				cout << "Enter 
				output();
				break;
			//case 5:
			//case 6:
			//case 7:
			case 8:
				c = false;
				break;
			default: cout << "Invalid command.\n\n";
		}
	}
}
