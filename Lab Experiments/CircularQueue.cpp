//Prepared by : Ansh Kushwaha
#include <iostream>
using namespace std;

#define MAXSIZE 5
int queue[MAXSIZE];
int front;
int rear;

int isEmpty(){
	if(front == -1 && rear == -1)
		return 1;
	else
		return 0;
}

int isFull(){
	if((rear+1)%MAXSIZE == front)
		return 1;
	else
		return 0;
}

void enqueue(int x){
	if(isFull()){
		cout << "Overflow\n";
		return;
	}
	
	if(isEmpty()){
		front = rear = 0;
		queue[rear] = x;
	}
	else{
		rear = (rear+1)%MAXSIZE;
		queue[rear] = x;
	}
}

int dequeue(){
	if(isEmpty()){
		cout << "Underflow\n";
		return -12345;
	}
	if(front == rear){
		int x = queue[front];
		front = rear = -1;
		return x;
	}
	else{
		int x = queue[front];
		front = (front+1)%MAXSIZE;
		return x;
	}
}    

int first(){
	if(isEmpty()){
		cout << "Queue empty\n";
		return -12345;
	}
	else
		return queue[front];
}

int last(){
	if(isEmpty()){
		cout << "Queue empty\n";
		return -12345;
	}
	else
		return queue[rear];
}

void create(int n){
	if(rear != -1){
		cout << "Queue already exists.\n";
		return;
	}

	if(n<=0 || n>MAXSIZE){
		cout << "Can't create Queue.\n";
		return;
	}
	else{
		int x;
		for(int i=1; i<=n; i++){
			cout << "Enter data of " << i << " element : ";
			cin >> x;
			enqueue(x);
		}
	}
}

void output(){
	if(isEmpty()){
		cout << "Queue empty.\n";
		return;
	}
	else{
		cout << "Queue display :\n";
		cout << "----------------\n";
		cout << "Front";
		int i = front;
		do{
			cout << "->" << queue[i];
			i = (i+1)%MAXSIZE;
		}
		while(i != (rear+1)%MAXSIZE);
		cout << "<-Rear\n";
	}
}

int main(){
	front = rear = -1;
	int choice, x, n, t;
	bool cont = true;
	cout << "Prepared by Ansh Kushwaha\n";
	while(cont){
	cout << "********** MENU **********\n";
		cout << "1. CREATE\n";
		cout << "2. ENQUEUE\n";
		cout << "3. DEQUEUE\n";
		cout << "4. ISEMPTY\n";
		cout << "5. ISFULL\n";
		cout << "6. FIRST\n";
		cout << "7. LAST\n";
		cout << "8. OUTPUT\n";
		cout << "9. EXIT\n";
		cout << "***************************\n";
		cout << "Enter your choice : ";
		cin >> choice;
		cout << "\n";

		switch(choice){
			case 1:
				cout << "Enter the size of QUEUE : ";
				cin >> n;
				create(n);
				break;
			case 2:
				cout << "Enter the element to insert : ";
				cin >> x;
				enqueue(x);
				break;
			case 3:
				t = dequeue();
				if(t == -12345)
					break;
				else
					cout << "Deleted " << t << "\n";
				break;
			case 4:
				if(isEmpty())
					cout << "Queue is empty.\n";
				else
					cout << "Queue is not empty.\n";
				break;
			case 5:
				if(isFull())
					cout << "Queue is full.\n";
				else
					cout << "Queue is not full.\n";
				break;
			case 6:
				t = first();
				if(t == -12345)
					break;
				else
					cout << "First element : " << t << "\n";
				break;
			case 7:
				t = last();
				if(t == -12345)
					break;
				else
					cout << "Last element : " << t << "\n";
				break;
			case 8:
				output();
				break;
			case 9:
				cout << "Exiting...\n";
				cont = false;
				break;

			default: cout << "Incorrect choice.\n"; 
		}
		cout << "\n";
	}
	return 0;
}