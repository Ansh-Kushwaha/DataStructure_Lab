#include <iostream>
using namespace std;

class Stack {
    int TOP;
    int stack[100];
    
    public:
    Stack(){
        TOP = -1;
    }
    Stack(int n){
        TOP = -1;
        int x;
        for(int i=0; i<n; i++){
            cout << "Enter data of " << i+1 << " element : ";
            cin >> x;
            push(x);
        }
    }
    bool isFull(){
        if(TOP == 99)
            return true;
        else
            return false;
    }
    
    bool isEmpty(){
        if(TOP == -1)
            return true;
        else
            return false;
    }
    
    void push(int x){
        if(isFull()){
            cout << "Overflow!\n";
            return;
        }
        else{
            TOP++;
            stack[TOP] = x;
        }
    }
    
    int pop(){
        if(isEmpty()){
            cout << "Underflow!\n";
            return -9999;
        }
        else{
            int x = stack[TOP];
            TOP--;
            return x;
        }
    }
    
    int top(){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return -9999;
        }
        else
            return stack[TOP];
    }
    
    void output(){
        for(int i=TOP; i>=0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
};

class Queue {
    Stack s1, s2;
    
    public:
    Queue(){
    }
    Queue(int n){
        int x;
        for(int i=0; i<n; i++){
            cout << "Enter data of " << i+1 << " element : ";
            cin >> x;
            enqueue(x);
        }
    }
    
    bool isFull(){
        if(s1.isFull())
            return true;
        else
            return false;
    }
    
    bool isEmpty(){
        if(s1.isEmpty())
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
            s1.push(x);
        }
        else{
            while(!s1.isEmpty())
                s2.push(s1.pop());
            s1.push(x);
            while(!s2.isEmpty()){
                s1.push(s2.pop());
            }
        }
    }
    
    void output(){
        s1.output();
    }
};

int main(){
    Queue q(5);
    q.output();
    q.enqueue(7);
    q.output();
}
