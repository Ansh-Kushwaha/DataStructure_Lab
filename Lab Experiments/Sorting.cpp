#include <iostream>
using namespace std;

// Bubble Sort 
void bubbleSort(int arr[], int n) {
	bool swapped;
	for(int i = 0; i < n - 1; i++) {
		swapped = false;
		for(int j = 0; j < n - i - 1; j++) {
			if(arr[j] > arr[j+1]) {
				int t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
				swapped = true;
			}
		}
		if(!swapped)
			break;
	}
}

// Insertion Sort
void insertionSort(int arr[], int n) {
	int i, key, j;
	for(i = 1; i < n; i++) {
		j = i - 1;
		key = arr[i];
		while(j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

// Selection Sort
void selectionSort(int arr[], int n) {
	int minIdx = 0;
	for(int i = 0; i < n-1; i++) {
		minIdx = i;
		for(int j = i; j < n; j++) {
			if(arr[j] < arr[minIdx]) {
				minIdx = j;
			}
		}
		if(minIdx != i)
			swap(arr[i], arr[minIdx]);
	}
}

// Merge Sort
void merge(int arr[], int l, int mid, int r) {
	int i, j, k;
	int n = mid - l + 1;
	int m = r - mid;
	int L[n], R[m];

	for(i = 0; i < n; i++)
		L[i] = arr[l + i];

	for(j = 0; j < m; j++)
		R[j] = arr[mid + j + 1];

	i = 0; j = 0; k = l;

	while(i < n && j < m) {
		if(L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < n) {
		arr[k] = L[i];
		i++; k++;
	}

	while(j < m) {
		arr[k] = R[j];
		j++; k++;
	}
}

void mergeSort(int arr[], int l, int r) {
	if(l < r) {
		int mid = (l + r) / 2;

		mergeSort(arr, l, mid);
		mergeSort(arr, mid+1, r);
		merge(arr, l, mid, r);
	}
}

int main() {
	int arr[] = { 12, 72, 1, 6, 9, 15 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Unsorted array : \n";
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl << endl;

	mergeSort(arr, 0, n-1);

	cout << "Sorted array : \n";
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}