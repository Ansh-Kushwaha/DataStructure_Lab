#include <iostream>
using namespace std;

#define MAXSIZE 100
int queue[MAXSIZE];
int front;
int rear;

bool isEmpty(){
    if(front == -1 && rear == -1)
        return true;
    else
        return false;
}

bool isFull(){
    if(rear == (MAXSIZE-1))
        return true;
    else
        return false;
}

void enqueue(int x){
    if(isFull()){
        cout << "Overflow!\n";
        return;
    }
    
    if(isEmpty()){
        front = rear = 0;
        queue[rear] = x;
    }
    else{
        rear++;
        queue[rear] = x;
    }
}

int dequeue(){
    if(isEmpty()){
        cout << "Underflow!\n";
        return -9999;
    }
    if(front == rear){
        int x = queue[front];
        front = rear = -1;
        return x;
    }
    else{
        int x = queue[front];
        front++;
        return x;
    }
}    

void output(){
    if(isEmpty()){
        cout << "Queue is empty.\n";
        return;
    }
    else{
        for(int i = front; i<=rear; i++)
            cout << queue[i] << " ";
        cout << "\n";
    }
}

int first(){
    if(isEmpty())
        return -9999;
    else
        return queue[front];
}

int last(){
    if(isEmpty())
        return -9999;
    else
        return queue[rear];
}

void create(int n){
    if(n<=0 || n > MAXSIZE){
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
    front = rear = -1;
    create(10);
    output();
    cout << "Deleted : " << dequeue() << "\n";
    output();
    return 0;
}
