#include<iostream>
using namespace std;

struct node{
	int data;
	node* link;
};

class LinkedList{
	int size;
	node* head;	
	public:
	LinkedList(node* h, int s){
	    head = h;
	    size = s;
	}
	
	int isEmpty(node* p){
		if(p == NULL)
			return 1;
		else
			return 0;
	}
	
	int isFull(node* p){
		node *tmp = new node();
		p = tmp->link;
		if(p != NULL){
			delete tmp;
			return 0;
		}
		else
			return 0;
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
	
	//int insert(node* p, int pos){}
	
	void output(node* p){
	    while(p != NULL){
	        cout << p->data << " ";
	        p = p->link;
	    }
	    cout << endl;
	}
};


int main(){
    node* start = NULL;
	LinkedList ll(start, 5);
	start = ll.create(start, 5);
	cout << ll.find(start, 1) << endl;
	cout << ll.search(start, 5) << endl;
	ll.output(start);
	
	return 0;
}
