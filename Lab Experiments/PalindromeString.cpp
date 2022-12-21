//Prepared by : Ansh Kushwaha
#include <iostream>
using namespace std;
#define MAXSIZE 100
char stack[MAXSIZE];
int top = -1;

int isEmpty(){
	if(top == -1)
		return 1;
	else
		return 0;
}

int isFull(){
	if(top == (MAXSIZE-1))
		return 1;
	else
		return 0;
}

char Top(){
	if(isEmpty())
		return '$';
	else
		return stack[top];
}

void push(char c){
	if(!isFull())
		top++;
		stack[top] = c;
}

char pop(){
	if(!isEmpty()){
		char ch  = stack[top];
		top--;
		return ch;
	}
	else
		return '$';
}

bool chkPdm(string s){
	bool b = true;
	int l = s.length();
	int mid = l/2;
	for(int i = 0; i<mid; i++)
		push(s[i]);
	if(l%2 == 1)
		mid++;
	for(int j = mid; j<l; j++){
		char c = pop();
		if(!(c == s[j]))
		b = false;
	}     
	return b;   
}

int main(){
	string s;
	char ch;
	while(true){
		cout << "Enter the string you want to check : ";
		cin >> s;
		bool b = chkPdm(s);
		if(b == true)
			cout << s << " is a palindrome.\n\n";
		else
			cout << s << " is not a palindrome.\n\n";
		cout << "Do you want to check another string (Y/N) : ";
		cin >> ch;
		if(ch == 'Y')
			continue;
		else break;
	}
	return 0;
}