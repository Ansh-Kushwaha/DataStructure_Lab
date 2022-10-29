//Prepared by : Ansh Kushwaha
#include<iostream>
using namespace std;
#define MAXSIZE 100

int elements[MAXSIZE];
int SIZE;

void create(int n){
	if(n > 0 && n <=MAXSIZE){
		SIZE = n;
    	for(int i=0; i<n; i++){
			cout << "Enter data of " << i+1 << " element : ";
        	cin >> elements[i];
        }
	}
}
    
bool isEmpty(){
	if(SIZE == 0)
		return true;
	else
		return false;
}
	
bool isFull(){
	if(SIZE == MAXSIZE)
		return true;
	else
		return false;
}
	
int find(int k){
	if(k>=0 && k<SIZE)
		return elements[k];
	else
	return -1;
}
	
int search(int n){
	int i;
	for(i=0; i<SIZE; i++)
		if(elements[i] == n)
			return i;
	return -1;
}

	
void insert(int k, int x){
	if(!isFull()){
		for(int j=SIZE; j>=k-1; j--)
			elements[j] = elements[j-1];
		elements[k-1] = x;
		SIZE++;
	}
	else
		cout << "List is Full." << endl;
}

void del(int k, int &x){
	if(!isEmpty()){
		x = elements[k-1];
		for(int j=k-1; j<SIZE; j++){
			elements[j] = elements[j+1];
		}
		SIZE--;
	}
	else
		cout << "List is already empty." << endl;
}		

void reverse(){
	for(int i=0; i < SIZE/2; i++){
		int temp = elements[i];
		elements[i] = elements[SIZE-1-i];
		elements[SIZE-1-i] = temp;
	}
}

void output(){
	for(int i=0; i<SIZE; i++){
		cout << elements[i] << " ";
	}
	cout << "\n";
}

int main(){
	int n, choice, x, k, t;
	bool cont = true;
	cout << "***************************\n";
	cout << "Prepared by Ansh Kushwaha\n";
	cout << "***************************\n";
	while(cont){
		cout << "1 : Create\n";
		cout << "2 : Insert\n";
		cout << "3 : Delete\n";
		cout << "4 : isFull\n";
		cout << "5 : isEmpty\n";
		cout << "6 : Find\n";
		cout << "7 : Search\n";
		cout << "8 : Reverse\n";
		cout << "9 : Output\n";
		cout << "10 : Exit\n";
		cout << "***************************\n";
		cout << "Enter your choice : ";
		cin >> choice;
		cout << "\n";

		switch(choice){
			case 1:
				cout << "Enter the size of list : ";
				cin >> n;
				create(n);
				break;
			case 2:
				cout << "Enter the position you want to insert at : ";
				cin >> k;
				cout << "Enter the data you want to insert : ";
				cin >> x;
				insert(k, x);
				break;
			case 3:
				cout << "Enter the position of the element you want to delete : ";
				cin >> k;
				del(k, x);
				cout << "Deleted " << x << "\n";
				break;
			case 4:
				if(isFull())
					cout << "List is full.\n";
				else
					cout << "List is not full.\n";
				break;
			case 5:
				if(isEmpty())
					cout << "List is empty.\n";
				else
					cout << "List is not empty.\n";
				break;
			case 6:
				cout << "Enter the index of element you want to find : ";
				cin >> n;
				t = find(n);
				if(t == -1)
					cout << "Not found\n";
				else
					cout << "Element at " << n << " index = " << t << "\n";
				break;
			case 7:
				cout << "Enter the element you want to search : ";
				cin >> x;
				t = search(x);
				if(t == -1)
					cout << "Not found\n";
				else
					cout << "Found at " << t << " index.\n";
				break;
			case 8:
				reverse();
				cout << "List reversed.\n";
				break;
			case 9:
				cout << "\n";
				output();
				break;
			case 10:
				cout << "Exiting...\n";
				cont = false;
				break;
			default: cout << "Incorrect choice.\n"; 
		}
		cout << "\n";
	}
    return 0;
}