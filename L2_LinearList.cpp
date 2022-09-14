#include<iostream>
using namespace std;
#define MAXSIZE 100

class LinkedList{
    int size;
    int elements[MAXSIZE];

    public:
    void create(int n){
        if(n > 0 && n < MAXSIZE){
			size = n;
	   		cout << "Enter " << n << " elements :" << endl;
            for(int i=0; i<n; i++)
                cin >> elements[i];
		}
    }
    
    bool isEmpty(){
		if(size == 0)
			return true;
		else
			return false;
	}
	
	bool isFull(){
		if(size == MAXSIZE)
			return true;
		else
			return false;
	}
	
	int find(int k){
		if(k>=0 && k<size)
			return elements[k];
		else
		return -1;
	}
	
	int search(int n){
		int i;
		for(i=0; i<size; i++)
			if(elements[i] == n)
				return i;
		if(i == size)
			return -1;
	}

	
	void insert(int k, int x){
		if(!isFull()){
			for(int j=size; j>=k-1; j--)
				elements[j] = elements[j-1]; //shift elements
			elements[k-1] = x; //insert x at kth position
			size++;
		}
		else
			cout << "List is Full" << endl;
	}

	void del(int k, int &x){
		if(!isEmpty()){
			x = elements[k-1]; //deleted element
			for(int j=k-1; j<size; j++){
				elements[j] = elements[j+1];
			}
			size--;
		}
		else
			cout << "List is already empty" << endl;
	}
	
	
	void output(){
		for(int i=0; i<size; i++){
			cout << elements[i] << " ";
		}
		cout << "\n";
	}
};

int main(){
    LinkedList l1;
    l1.create(5);

    //if(l1.search(5) == -1) cout << "Not Found" << endl;
    //else cout << "Found" << endl;

    //if(l1.isFull()) cout << "List is full" << endl;
    //if(!l1.isEmpty()) cout << "List is empty" << endl;

    l1.output();

    l1.insert(4, 20);
    l1.output();
    int x;

    l1.del(4, x);
    cout << "Deleted " << x << endl;
    l1.output();
}
