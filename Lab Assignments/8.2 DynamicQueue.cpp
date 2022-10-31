//Prepared by : Ansh Kushwaha
#include<iostream>
using namespace std;

typedef struct node{
    int data;
    node *link;
}node;


node *front;
node *rear;

int isEmpty(){
    if(front == NULL && rear == NULL)
        return 1;
    else
        return 0;
}

int isFull(){
    node *tmp = new node;
    if(tmp != NULL){
        delete tmp;
        return 0;
    }
    else
        return 1;
}

void enqueue(int x){
    if(isFull()){
        cout << "Overflow\n";
        return;
    }
    
    if(isEmpty()){
        node *tmp = new node;
        tmp->data = x;
        tmp->link = NULL;
        front = rear = tmp;
        return;
    }
    else{
        node *tmp = new node;
        tmp->data = x;
        tmp->link = rear->link;
        rear->link = tmp;
        rear = tmp;
        return;
    }
}

int dequeue(){
    if(isEmpty()){
        cout << "Underflow\n";
        return -12345;
    }
    if(front == rear){
        node *tmp = front;
        front = rear = NULL;
        int x = tmp->data;
        delete tmp;
        return x;
    }
    else{
        node *tmp = front;
        front = front->link;
        int x = tmp->data;
        delete tmp;
        return x;
    }
}    

void output(){
    if(isEmpty()){
        cout << "Queue empty.\n";
        return;
    }
    else{
        node *q = front;
        cout << "Queue display :\n";
        cout << "----------------\n";
        cout << "Front";
        do{
           cout << "->" << q->data; 
           q = q->link;
        }
        while(q != NULL);
        cout << "<-Rear\n";
    }
}

int length(){
    int l = 0;
    node *q = front;
    while(q!=NULL){
        l++;
        q = q->link;
    }
    return l;
}

int first(){
    if(isEmpty())
        return -12345;
    else
        return front->data;
}

int last(){
    if(isEmpty())
        return -12345;
    else
        return rear->data;
}

void create(int n){
    if(!(isEmpty())){
        cout << "Queue already exists.\n";
        return;
    }
    if(n<=0){
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


int main(){
    front = rear = NULL;
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
        cout << "8. LENGTH\n";
		cout << "9. OUTPUT\n";
		cout << "10. EXIT\n";
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
                t = length();
                cout << "Length of QUEUE =t " << t << "\n";
                break;
            case 9:
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