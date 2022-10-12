#include <iostream>
#include <stack>
using namespace std;

int getPre(char c){
    switch (c){
        case '$' : return -1;
        case '+' : return 1;
        case '-' : return 1;
        case '*' : return 2;
        case '/' : return 2;
        case '%' : return 2;
        case '^' : return 3;
        case '(' : return 0;
        case ')' : return 5;
        
        default : return 99;
    }
}

bool chkPre(char a, char b){
    if(getPre(b) < getPre(a))
        return true;
    else
        return false;
}

stack<char> st;

string infToPofx(string s){
    string po = ""; 
    for(int i=0; i<s.size(); i++){
        int pre =getPre(s[i]);
        if(pre == 99)
            po += s[i];
            else{
                if(chkPre(s[i], st.top()))
                    st.push(s[i]);
            }
    }
    return po;
}

int main(){
    st.push('$');
    string s;
    cout << "Enter the expression : ";
    cin >> s;
    cout << infToPofx(s) << "\n";
    while (!st.empty()) {
        cout << st.top() <<" ";
        st.pop();
    }
}
