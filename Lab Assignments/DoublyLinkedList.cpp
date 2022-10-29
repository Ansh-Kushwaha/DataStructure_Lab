//Prepared by : Ansh Kushwaha
#include <iostream>
using namespace std;

typedef struct node{
    node *prev, *next;
    int data;
}node;

node* create(node *first, int n){
    if(n<=0){
        cout << "Can't create list.\n";
        return first;
    }
    int x;
    node *last;
    node *tmp = new node;
    tmp->prev = tmp->next = NULL;
    cout << "Enter data of 1 element : ";
    cin >> x;
    tmp->data = x;
    first = tmp;
    last = first;
    if(n== 1)
        return first;
        
    for(int i=2; i<=n; i++){
        cout << "Enter data of " << i << " element : ";
        cin >> x;
        node *tmp = new node;
        tmp->prev = last;
        tmp->next = last->next;
        tmp->data = x;
        last->next = tmp;
        last = tmp;
    }
    return first;
}

int isEmpty(node *first){
    if(first == NULL)
        return 1;
    else
        return 0;
}

int isFull(node *first){
    node *tmp = new node;
    if(tmp != NULL){
        delete tmp;
        return 0;
    }
    else
        return 1;
}

int length(node *first){
    int l = 0;
    while(first != NULL){
        l++;
        first = first->next;
    }
    return l;
}

int find(node *first, int pos){
    if(first == NULL){
        cout << "List is empty.\n";
        return -12345;
    }
    
    if(pos<1 || pos>length(first)){
        cout << "Invalid Position\n";
        return -12345;
    }
    
    for(int i=1; i<pos; i++)
        first = first->next;
    return first->data;
}

int search(node *first, int x){
    if(first == NULL){
        cout << "List is empty.\n";
        return -1;
    }
    int pos = 1;
    while(first != NULL){
        if(first->data == x)
            return pos;
        else{
            pos++;
            first = first->next;
        }
    }
    return -1;
}

node* insert(node *first, int pos, int x){
    int l = length(first);
    if(pos<1 || pos >(l+1)){
        cout << "Invalid position\n";
        return first;
    }
    if(l==0 && pos==1){
        node *tmp = new node;
        tmp->prev = tmp->next = NULL;
        tmp->data = x;
        first = tmp;
        return first;
    }
    else if(pos==1){
        node *tmp = new node;
        tmp->prev = NULL;
        tmp->next = first;
        tmp->data = x;
        first->prev = tmp;
        first = tmp;
        return first;
    }
    else if(pos<=l){
        node *q = first, *r;
        for(int i=1; i<pos-1; i++)
            q = q->next;
        node *tmp = new node;
        tmp->prev = q;
        tmp->next = q->next;
        tmp->data = x;
        r = q->next;
        q->next = tmp;
        r->prev = tmp;
        return first;
    }
    else{
        node *q = first;
        do{
            q = q->next;
        }
        while(q->next != NULL);
        node *tmp = new node;
        tmp->next = NULL;
        tmp->prev = q;
        tmp->data = x;
        q->next = tmp;
        return first;
    }
}

node *del(node *first, int pos, int &x){
    if(first == NULL){
        cout << "List is empty.\n";
        return first;
    }
    int l = length(first);
    if(pos<1 || pos>l){
        cout << "Invalid position\n";
        return first;
    }
    else{
        if(pos == 1){
            node *q = first;
            x = q->data;
            first = first->next;
            first->prev = NULL;
            delete q;
            return first;
        }
        else if(pos==l){
            node*q = first;
            for(int i=1; i<pos-1; i++)
                q = q->next;
            node *r = q->next;
            x = r->data;
            r->prev = NULL;
            q->next = NULL;
            delete r;
            return first;
        }
        else{
            node *q = first;
            for(int i=1; i<pos-1; i++)
                q = q->next;
            node *r = q->next;
            x = r->data;
            q->next = r->next;
            node *tmp = r->next;
            tmp->prev = q;
            delete r;
            return first;
        }
    }
}

void output(node *first){
    if(first == NULL){
        cout << "List is empty.\n";
        return;
    }
    while(first != NULL){
        cout << first->data << " ";
        first = first->next;
    }
    cout << "\n";
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
				cout << "Enter the position of element you want to find : ";
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
