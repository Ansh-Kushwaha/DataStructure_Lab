#include <iostream>
using namespace std;

#define SIZE 100
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

bool isEmpty(int n){
	if(top1 == -1 && top2 == SIZE)
		return true;
	else
		return false;
}

void output(int n){
    if(n==1){
        for(int i=top1; i>=0; i--)
            cout << stack[i] << " ";
        cout << "\n";
    }
    else if(n==2){
        for(int i=top2; i<SIZE; i++)
            cout << stack[i] << " ";
        cout << "\n";
    }
    else{
        cout << "Incorrect stack \n";
    }

}

int top(int n){
    if(n==1){
        return stack[top1];
    }
    else if(n==2){
        return stack[top2];
    }
    else{
        cout << "Incorrect stack \n";
        return -9999;
    }
}
void push(int n, int x){
    if(n==1){
        if(isFull()){
            cout << "Overflow \n";
            return;
        }
        else{
            top1++;
            stack[top1] = x;
        }
    }
    else if(n==2){
        if(isEmpty(n)){
            cout << "Overflow \n";
            return;
        }
        else{
            top2--;
            stack[top2] = x;
        }
    }
    else{
        cout << "Incorrect stack \n";
    }
}

void pop(int n, int &x){
    if(n==1){
        if(isEmpty(n)){
            cout << "Underflow \n";
            return;
        }
        else{
            x = stack[top1];
            top1--;
        }
    }
    else if(n==2){
        if(isEmpty(n)){
            cout << "Underflow \n";
            return;
        }
        else{
            x = stack[top2];
            top2++;
        }
    }
    else{
        cout << "Incorrect stack \n";
    }
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
            	cout << "Enter the Stack no. (1/2) : ";
                cin >> n;
				if(isEmpty(n))
					cout << "Stack is empty.\n";
				else
					cout << "Stack is not empty.\n";
				break;
			case 3:
				if(isFull())
					cout << "Stack Full.\n";
				else
					cout << "Stack not Full.\n";
				break;
			case 4:
				cout << "Enter the Stack no. you want to view (1/2) : ";
                cin >> n;
				output(n);
				break;
			case 5:
				cout << "Enter the Stack no. (1/2) : ";
                cin >> n;
				cout << top(n) << "\n";
				break;                
			case 6:
                cout << "Enter the Stack no. (1/2) : ";
                cin >> n;
				pop(n, x);
                cout << "Popped " << x << endl;
				break;           
			case 7:
                cout << "Enter the Stack no. (1/2) : ";
                cin >> n;
				cout << "Enter element you wan't to push : ";
                cin >> x;
                push(n, x);
				break;           
			case 8:
				c = false;
				break;
			default: cout << "Invalid command.\n\n";
		}
	}
}