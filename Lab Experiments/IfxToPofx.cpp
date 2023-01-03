//Prepared by : Ansh Kushwaha
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int getPrecedence(char ch){
	switch(ch) {
		case '$':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
		case '^':
			return 3;
		default:
			return -1;
	}
}

bool checkPrec(char a, char b){
	if(getPrecedence(a) < getPrecedence(b))
		return true;
	return false;
}

bool checkOp(char c){
	if(c != '(' && c != ')' && c != '+' && c != '-' && c != '*' && c != '/' && c != '%' && c != '^')
		return true;
	return false;
}

string ifxToPofx(stack<char> &st ,string s){
	string pofx = "";
	for(int i=0; i<s.size(); i++){
		if(checkOp(s[i])) {
			pofx += s[i];
			cout << "Put " << s[i] << " in the output string." << endl;
		}
			
		else if(s[i] == '(') {
			st.push(s[i]);
			cout << "Push ( onto the stack." << endl;
		}

		else if(s[i] == ')'){
			cout << "Pop till first ( is encountered, put into the output string." << endl;
			while(st.top() != '('){
				if(st.top() == '$')
					return "Invalid Expression";
				else{
					pofx += st.top();
					st.pop();
				}
			}
			st.pop();
		}
		else{
			if(checkPrec(st.top(), s[i])) {
				st.push(s[i]);
				cout << "Push " << s[i] << " onto the stack." << endl;
			}
			else{
				cout << "Pop ";
				while(!checkPrec(st.top(), s[i])){
					char t = st.top();
					st.pop();
					pofx += t;
					cout << t << ", ";
				}
				cout << "and put into the output string. Push " << s[i] << " onto the stack." << endl;
				st.push(s[i]);
			}
		}
	}
	cout << "Pop everyting in the stack till $." << endl;
	while(st.top() != '$'){
		pofx += st.top();
		st.pop();
	}
	return pofx;
}

int evalPofx(stack<int> &st, string p){
	for(int i=0; i<p.size(); i++){
		if(checkOp(p[i])){
			st.push(int(p[i] - '0'));
		}

		else{
			int t1 = st.top();
			st.pop();
			int t2 = st.top();
			st.pop();
			int tmp = 0;
			switch (p[i]){
				case '+':
					tmp  = t2 + t1;
					break;
				case '-':
					tmp = t2 - t1;
					break;
				case '*':
					tmp = t2 * t1;
					break;
				case '/':
					tmp = t2 / t1;
					break;
				case '%':
					tmp = t2 % t1;
					break;
				case '^':
					tmp = pow(t2, t1);
			}
			st.push(tmp);
		}
	}
	int res = st.top();
	st.pop();
	return res;
}

int main(){
	stack<char> st;
	st.push('$');
	string s;
	cout << "Enter expression : ";
	cin >> s;
	string pofx = ifxToPofx(st, s);
	cout << "Postfix Expression : " << pofx << "\n";
	stack<int> op;
	int res = evalPofx(op, pofx);
	cout << "Result : " << res << "\n";

	return 0;
}
