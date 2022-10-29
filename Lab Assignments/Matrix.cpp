//Made by : Ansh Kushwaha
#include <iostream>
using namespace std;

void input(int **A, int m, int n){
    for(int i=0; i<m; i++){
        cout << "Enter row " << i+1 << " : \n";
        for(int j=0; j<n; j++){
            cin >> A[i][j];
        }
    }
}

void output(int **A, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << A[0][0] << " ";
        }
        cout << endl;
    } 
    cout << "it did work!" << endl;
}

int main(){
    int m, n;
    cin >> m >> n;
    int **A = new int*[n];
    input(A, m, n);
    cout << "input"<<endl;
    cout << A[0][0] << endl;
    output(A, m, n);
    return 0;
}