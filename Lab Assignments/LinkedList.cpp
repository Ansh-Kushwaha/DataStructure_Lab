//Prepared by : Ansh Kushwaha
#include<iostream>
using namespace std;

typedef struct node{
	int data;
	node* link;
}node;

int isEmpty(node* p){
	if(p == NULL)
		return 1;
	else
		return 0;
}

int isFull(node* p){
	node *tmp = new node();
	if(tmp != NULL){
		delete tmp;
		return 0;
	}
	else
		return 1;
}
	
node* create(node* p, int n){
	int d;
	if(isFull(p)){
		cout << "List can't be created." << endl;
		return p;		
	}

	else{
		if(n>=1){
			node *tmp = new node();
			node *last;
            cout << "Enter data of 1 element : ";
			cin >> d;
			tmp->data = d;
			tmp->link = p;
			p = tmp;
			last = tmp;	
			if(n==1)
				return p;
			else{
				for(int i=2; i<=n; i++){
					node *tmp = new node();
                    cout << "Enter data of " << i << " element : ";
					cin >> d;
					tmp->data = d;
					tmp->link = last->link;
					last->link = tmp;
					last = tmp;
				}
				return p;
			}
		}
	}
	return p;
}

int length(node* p){
	int len = 0;
	while(p != NULL){
		len++;
		p = p->link;
	}
	return len;
}
	
int find(node* p, int pos){
	int len = length(p);
	if(pos < 1 || pos > len){
		cout << "Invaid position" << endl;
		return -9999;
	}
	for(int i = 1; i<=pos-1; i++){
		p = p->link;
	}
	return p->data;
}
	
int search(node* p, int x){
    int pos = 1;
    while(p != NULL){
        if(p->data == x)
            return pos;
       else{
           p = p->link;
           pos++;
       }
    }
    return -1;
}
	
node* insert(node* p, int pos, int x){
    int len = length(p);
    if(pos<1 || pos>len+1){
        cout << "Can't insert at specified position" << endl;
        return p;
    }
    else{
        if(pos == 1){
            node* tmp = new node();
            tmp->link = p;
            tmp->data = x;
            p = tmp;
           return p;
        }
        else{
			node* q = p;
            for(int i=2; i<=pos-1; i++)
				q = q->link;
			node *tmp = new node;
			tmp->data = x;
			tmp->link = q->link;
			q->link = tmp;
			return p;
		}
    }
}

node* del(node* p, int pos, int &x){
	int len = length(p);
	if(isEmpty(p)){
		cout << "Already empty" << endl;
		return p;
	}
	else if(pos <1 || pos>len){
		cout << "Invalid position" << endl;
		return p;
	}
	else if(pos == 1){
		node *q = p;
		x = q->data;
		p = q->link;
		delete q;
		return p;
	}
	else{
		node* tmp = p;
		node* q;
		for(int i=1; i<pos-1; i++)
			p = p->link;
		q = p->link;
		p->link = q->link;
		x = q->data;
		delete q;
		return tmp;
	}
}
	
node* reverse(node *p){
	if(p == NULL){
		cout << "List doesn't exist." << endl;
		return p;
	}
	node *last, *curr, *next;
	curr = p;
	last = NULL;
	while(curr != NULL){
		next = curr->link;
		curr->link = last;
		last = curr;
		curr = next;
	}
	p = last;
	return p;
}
	
void output(node* p){
    while(p != NULL){
        cout << p->data << " ";
        p = p->link;
    }
    cout << endl;
}

int main(){
    node *start = NULL;
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
				start = create(start, n);
				break;
			case 2:
				cout << "Enter the position you want to insert at : ";
				cin >> k;
				cout << "Enter the data you want to insert : ";
				cin >> x;
				start = insert(start, k, x);
				break;
			case 3:
				cout << "Enter the position of the element you want to delete : ";
				cin >> k;
				start = del(start, k, x);
				cout << "Deleted " << x << "\n";
				break;
			case 4:
				if(isFull(start))
					cout << "List is full.\n";
				else
					cout << "List is not full.\n";
				break;
			case 5:
				if(isEmpty(start))
					cout << "List is empty.\n";
				else
					cout << "List is not empty.\n";
				break;
			case 6 :
				cout << "Length of list = " << length(start) << "\n";
				break;
			case 7:
				cout << "Enter the index of element you want to find : ";
				cin >> n;
				t = find(start, n);
				if(t == -9999)
					break;
				else
					cout << "Element at " << n << " position = " << t << "\n";
				break;
			case 8:
				cout << "Enter the element you want to search : ";
				cin >> x;
				t = search(start, x);
				if(t == -9999)
					break;
				else
					cout << "Found at " << t << " position.\n";
				break;
			case 9:
				start = reverse(start);
				cout << "List reversed.\n";
				break;
			case 10:
				cout << "\n";
				output(start);
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