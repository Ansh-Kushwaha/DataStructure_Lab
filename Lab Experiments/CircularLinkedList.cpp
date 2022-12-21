//Prepared by : Ansh Kushwaha
#include <iostream>
using namespace std;

typedef struct node{
	int data;
	node *link;
}node;

node* create(node *last, int n){
	last = NULL;
	int x;
	if(n<=0){
		cout << "Invalid length" << endl;
		return last;
	}
	else{
		node *tmp = new node;
		cout << "Ente data of 1 element : ";
		cin >> x;
		tmp->data = x;
		tmp->link = tmp;
		last = tmp;

		for(int i = 2; i<=n; i++){
			node *tmp = new node;
			cout << "Enter data of " << i << " element : ";
			cin >> x;
			tmp->data = x;
			tmp->link = last->link;
			last->link = tmp;
			last = tmp;
		}
	}
	return last;
}
	
int isEmpty(node *last){
	if(last == NULL)
		return 1;
	else
		return 0;
}
	
int isFull(node *last){
	node *tmp = new node;
	if(tmp!=NULL){
		delete tmp;
		return 0;
	}
	else
		return 1;
}
	
int length(node *last){
	int l=0;
	if(last == NULL){
		return 0;
	}
	node *q = last->link;
	do{
		l++;
		q = q->link;
	}
	while(q != last->link);
	return l;
}
	
int find(node *last, int pos){
	if(last == NULL){
		cout << "List is empty.\n";
		return -12345;
	}
	else if(pos<1 || pos>length(last)){
		cout << "Invalid position.\n";
		return -12345;
	}
	else{
		node *q = last->link;
		for(int i=1; i<pos; i++){
			q = q->link;
		}
		return q->data;
	}
}
	
int search(node *last, int x){
	if(last == NULL){
		cout << "List is empty.\n";
		return -1;
	}
	else{
		node *q = last->link;
		int pos = 1;
		do{
			if(q->data == x){
				return pos;
			}
			else{
				pos++;
				q = q->link;
			}
		}
		while(q != last->link);
	}
	return -1;
}
	
node* insert(node *last, int pos, int x){
	int l = length(last);
	if(pos<1 || pos>(l+1)){
		cout << "Invalid position\n";
		return last;
	}
	
	if(l == 0 && pos == 1){
		node *tmp = new node;
		tmp->data = x;
		tmp->link = tmp;
		last = tmp;
		return last;
	}
	
	else{
		if(pos==1){
			node *tmp = new node;
			tmp->data = x;
			tmp->link = last->link;
			last->link = tmp;
			return last;
		}
		else if(pos==l+1){
			node *tmp = new node;
			tmp->data = x;
			tmp->link = last->link;
			last->link = tmp;
			last = tmp;
			return last;
		}
		else{
			node *q = last->link;
			node *tmp = new node;
			for(int i=1; i<pos-1; i++)
				q = q->link;
			tmp->data = x;
			tmp->link = q->link;
			q->link = tmp;
			return last;
		}
	}
}


node* del(node *last, int pos, int &x){
	int l = length(last);
	if(pos<1 || pos>l){
		cout << "Invalid Position\n";
		return last;
	}
	else{
		if(pos==1){
			node *q = last->link;
			last->link = q->link;
			x = q->data;
			delete q;
			return last;
		}
		if(pos==l){
			node *q = last;
			x = q->data;
			node *prev = last->link;
			while(prev->link != last){
				prev = prev->link;
			}
			prev->link = last->link;
			last = prev;
			delete q;
			return last;
		}
		else{
			node *prev = last->link;
			while(pos!=2){
				prev = prev->link;
				pos--;
			}
			node *q = prev->link;
			x = q->data;
			prev->link = q->link;
			delete q;
			return last;
		}
	}
}

node* reverse(node *last){
	if(last == NULL){
		cout << "List is empty.\n";
		return last;
	}
	node *curr, *prev, *next, *tmp;
	tmp = last->link;
	curr = last->link;
	prev = last;
	do{
		next = curr->link;
		curr->link = prev;
		prev = curr;
		curr = next;
	}
	while(curr != tmp);
	return tmp;
}

void output(node *last){
	node *q = last->link;
	do{
		cout << q->data << " ";
		q = q->link;
	}
	while(q != last->link);
	cout << endl;
}

int main() {
	node *last = NULL;
	int n, choice, x, k, t;
	bool cont = true;
	cout << "Prepared by Ansh Kushwaha\n";
	while(cont){
		cout << "********** MENU **********\n";
		cout << "1 : Create\n";
		cout << "2 : Insert\n";
		cout << "3 : Delete\n";
		cout << "4 : isFull\n";
		cout << "5 : isEmpty\n";
		cout << "6 : length\n";
		cout << "7 : Find\n";
		cout << "8 : Search\n";
		cout << "9 : Reverse\n";
		cout << "10 : Output\n";
		cout << "11 : Exit\n";
		cout << "***************************\n";
		cout << "Enter your choice : ";
		cin >> choice;
		cout << "\n";

		switch(choice){
			case 1:
				cout << "Enter the size of list : ";
				cin >> n;
				last = create(last, n);
				break;
			case 2:
				cout << "Enter the position you want to insert at : ";
				cin >> k;
				cout << "Enter the data you want to insert : ";
				cin >> x;
				last = insert(last, k, x);
				break;
			case 3:
				cout << "Enter the position of the element you want to delete : ";
				cin >> k;
				last = del(last, k, x);
				cout << "Deleted " << x << "\n";
				break;
			case 4:
				if(isFull(last))
					cout << "List is full.\n";
				else
					cout << "List is not full.\n";
				break;
			case 5:
				if(isEmpty(last))
					cout << "List is empty.\n";
				else
					cout << "List is not empty.\n";
				break;
			case 6 :
				cout << "Length of list = " << length(last) << "\n";
				break;
			case 7:
				cout << "Enter the index of element you want to find : ";
				cin >> n;
				t = find(last, n);
				if(t == -12345)
					break;
				else
					cout << "Element at " << n << " position = " << t << "\n";
				break;
			case 8:
				cout << "Enter the element you want to search : ";
				cin >> x;
				t = search(last, x);
				if(t == -1)
					break;
				else
					cout << "Found at " << t << " position.\n";
				break;
			case 9:
				last = reverse(last);
				cout << "List reversed.\n";
				break;
			case 10:
				cout << "\n";
				output(last);
				break;
			case 11:
				cout << "Exiting...\n";
				cont = false;
				break;
			default: cout << "Incorrect choice.\n"; 
		}
		cout << "\n";
	}
	return 0;
}