#include<iostream>
using namespace std;	

void minMax(int a[], int n){
	int min = a[0], max = a[0];
	for(int i=1; i<n; i++){
		if(min > a[i]){ min = a[i]; }
		if(max < a[i]){ max = a[i]; }
	}	
    cout << "Max : " << max << endl;
    cout << "Min : " << min << endl;
    cout << endl;
}

int main(){
	int num[6] = {2, 9, 1, 45, 98, 5};
	minMax(num, 6);
	return 0;
}
