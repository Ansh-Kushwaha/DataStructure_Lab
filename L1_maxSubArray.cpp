#include<iostream>
using namespace std;
#define INF -10000

int sum(int a[], int s, int e){
	int sum = -INF;
	for(int i = s; i<e; i++){
		sum += a[i];
	}	
	return sum;
}

void lSum(int a[], int n){
	int lsum = -INF;
	for(int i=0; i<n-1; i++){
		for(int j = i+1; j<n; j++){
			int temp = sum(a, i, j);
			if(temp > lsum)
				lsum = temp;
		}
	}
	cout << "Larsest sum : " << lsum << endl;
}

int main(){
	int num[5] = {4, 6, -2, 41, -23};
	cout << "Given array : ";
	for(int i = 0; i<5; i++)
		cout << num[i] << " ";
	cout << endl; 
	lSum(num, 5);
	return 0;
}
