#include<iostream>
using namespace std;	

void rev(int a[], int n){
	for(int i=0; i < n/2; i++){
		int temp = a[i];
		a[i] = a[n-1-i];
		a[n-1-i] = temp;
	}
}

int main(){
	int num[5] = {-1, -2, -5, -9, -10};
	cout << "Given array : ";
	for(int i = 0; i<6; i++)
		cout << num[i] << " ";
	cout << endl; 
	rev(num, 6);
	cout << "Reversed array : "; 
	for(int i = 0; i<6; i++)
		cout << num[i] << " ";
	cout << endl; 
	return 0;
}
