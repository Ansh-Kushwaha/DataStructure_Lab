#include <iostream>
using namespace std;

typedef struct node{
    int data;
    node *next;
}node;

node *front;
node *rear;

bool isEmpty(){
    if(front == NULL && rear == NULL)
        return true;
    else
        return false;
}

bool isFull(){
    node *tmp = new node;
    if(tmp == NULL)
        return true;
    else{
        delete tmp;
        return false;
    }
}

void enqueue(int x){
    if(isFull()){
        cout << "Overflow!\n";
        return;
    }
    
    if(isEmpty()){          //front == rear == NULL
        node *tmp = new node;
        tmp->data = x;
        tmp->next = NULL;
        front = rear = tmp;
        return;
    }
    else{
        node *tmp = new node;
        tmp->data = x;
        tmp->next = rear->next;
        rear->next = tmp;
        rear = tmp;
        return;
    }
}

int dequeue(){
    if(isEmpty()){
        cout << "Underflow!\n";
        return -9999;
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
        front = front->next;
        int x = tmp->data;
        delete tmp;
        return x;
    }
}    

void output(){
    if(isEmpty()){
        cout << "Queue is empty.\n";
        return;
    }
    else{
        node *q = front;
        do{
           cout << q->data << " "; 
           q = q->next;
        }
        while(q != NULL);
        cout << "\n";
    }
}

int length(){
    int l = 0;
    node *q = front;
    while(q!=NULL){
        l++;
        q = q->next;
    }
    return l;
}

int first(){
    if(isEmpty())
        return -9999;
    else
        return front->data;
}

int last(){
    if(isEmpty())
        return -9999;
    else
        return rear->data;
}

void create(int n){
    if(n<=0){
        cout << "Can't create\n";
        return;
    }
    else{
        int x;
        for(int i = 0; i<n; i++){
            cout << "Enter data of " << i+1 << " element : ";
            cin >> x;
            enqueue(x);
        }
    }
}

int main(){
    front = rear = NULL;
    create(5);
    output();
    cout << "Length : " << length() << "\n";
    cout << "Deleted : " << dequeue() << "\n";
    output();
    cout << "Length : " << length() << "\n";
    
    return 0;
}
