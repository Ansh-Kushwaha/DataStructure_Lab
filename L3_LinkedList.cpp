#include<iostream>
using namespace std;

struct node{
	int data;
	node* link;
};

typedef struct LinkedList{	
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
		if(p == NULL){
			cout << "List doesn't exist." << endl;
			return p;
		}
		return p;
	}
	
	void output(node* p){
	    while(p != NULL){
	        cout << p->data << " ";
	        p = p->link;
	    }
	    cout << endl;
	}
} ll;


int main(){
    node* start = NULL;
	ll l1;
	start = l1.create(start, 5);
	// cout << ll.find(start, 1) << endl;
	// cout << ll.search(start, 5) << endl;
	l1.output(start);
	start = l1.reverse(start);
	l1.output(start);
	return 0;
}
