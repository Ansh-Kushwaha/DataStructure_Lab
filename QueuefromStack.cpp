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
};

class Queue {
    Stack s1, s2;
    
    public:
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
    
    void enqueue(){
        
    }
};
int main(){
    Stack s1(5);
}
