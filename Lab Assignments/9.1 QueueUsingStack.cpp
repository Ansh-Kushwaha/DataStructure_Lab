//Prepared by : Ansh Kushwaha
#include<iostream>
#define MAXSIZE 100
using namespace std;

template <class T> class Stack{
    int top;
    T stack[MAXSIZE];
    
    public:
    Stack(){
        top = -1;
    }
    Stack(int n){
        top = -1;
        int x;
        for(int i=0; i<n; i++){
            cout << "Enter data of " << i+1 << " element : ";
            cin >> x;
            push(x);
        }
    }
    bool isFull(){
        if(top == (MAXSIZE-1))
            return true;
        else
            return false;
    }
    
    bool isEmpty(){
        if(top == -1)
            return true;
        else
            return false;
    }
    
    void push(T x){
        if(isFull()){
            cout << "Overflow!\n";
            return;
        }
        else{
            top++;
            stack[top] = x;
        }
    }
    
    T pop(){
        if(isEmpty()){
            cout << "Underflow!\n";
            return -9999;
        }
        else{
            T x = stack[top];
            top--;
            return x;
        }
    }
    
    T Top(){
        if(isEmpty()){
            return -1;
        }
        else
            return stack[top];
    }

    void output(){
        for(int i=0; i<=top; i++)
            cout << stack[i] << " ";
        cout << "\n";
    }
};

Stack<int> s1, s2;

int isEmpty(){
    if(s1.isEmpty() && s2.isEmpty())
        return 1;
    else 
        return 0;
}

int isFull(){
    if(s1.isFull())
        return 1;
    else
        return 0;
}
     
void enQueue(int x){
    if(isFull()){
        cout << "Overflow\n";
        return;
    }
    s1.push(x);
}
    
int deQueue(){
    if(s1.isEmpty() && s2.isEmpty()){
        cout << "Queue is empty.\n";
        return -12345;
    }
    if(s2.isEmpty()){
        while(!(s1.isEmpty()))
            s2.push(s1.pop());
    }
    int x = s2.pop();
    return x;
}

void create(int n){
    int x;
    for(int i=1; i<=n; i++){
        cout << "Enter data of " << i << " element : ";
        cin >> x;
        enQueue(x);
    }
}

int last(){
    if(s1.isEmpty() && s2.isEmpty()){
        cout << "Queue is empty.\n";
        return -12345;
    }
    if(s1.isEmpty()){
        while(!s2.isEmpty())
            s1.push(s2.pop());
    }
    return s1.Top();
}

int first(){
    if(s1.isEmpty() && s2.isEmpty()){
        cout << "Queue is empty.\n";
        return -12345;
    }
    if(s2.isEmpty()){
        while(!s1.isEmpty())
            s2.push(s1.pop());
        return s2.Top();
    }
    if(s1.isEmpty())
        return s2.Top();
    else{
        return s1.Top();
    }
}

void output(){
    if(s1.isEmpty()){
        while(!s2.isEmpty())
            s1.push(s2.pop());
        s1.output();
    }
    else{
        while(!s1.isEmpty())
            s2.push(s1.pop());
        while(!s2.isEmpty())
            s1.push(s2.pop());
        s1.output();
    }
}
int main(){
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
		cout << "8. OUTPUT\n";
		cout << "9. EXIT\n";
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
				enQueue(x);
				break;
			case 3:
				t = deQueue();
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
                output();
                break;
			case 9:
				cout << "Exiting...\n";
				cont = false;
                break;

			default: cout << "Incorrect choice.\n"; 
		}
		cout << "\n";
	}
    return 0;
}