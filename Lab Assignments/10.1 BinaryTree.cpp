#include<iostream>
#include<cmath>
using namespace std;
#define SIZE 128

int BT[SIZE];
int last;

void create(int n){
	if(n<=0 || n>SIZE){
		cout << "Can't create a BTree.\n";
		return;
	}
	
	int x;
	for(int i=1; i<=n; i++){
		cout << "Enter data of element " << i << " :";
		cin >> x;
		BT[i] = x;
		last = i;
	}
}

void insert(int key){
    if(last == (SIZE-1)){
        cout << "BTree full\n";
        return;
    }
    last++;
    BT[last] = key;
}

void del(int key){
    int pos;
    for(pos=1; pos<=last; pos++)
        if(BT[pos] == key)
            break;
    if(pos == last+1){
        cout << "Key not found.\n";
        return;
    }
    
    BT[pos] = BT[last];
    last--;
}

void output(){
    int l = 0;
    for(int i=1; i<=last; i++){
        int cl = floor(log2(i));
        if(cl != l){
            l = cl;
            cout << endl;
        }
        cout << BT[i] << " ";
    }
    cout << "\n\n";
}

int main(){
	create(7);
	output();
	insert(98);
	output();
	del(23);
	output();
	
}
