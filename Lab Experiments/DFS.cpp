#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;

void addEdge(int x, int y) {
    adj[x][y] = 1;
    adj[y][x] = 1;
}

void DFS(int start, vector<bool>&visited) {
    cout << start << " ";
    //set current node as visited
    visited[start] = true;
    for(int i=0; i<adj[start].size(); i++) {
        //If some node is adjacent to current node & is unvisited
        if(adj[start][i] == 1 && !visited[i]) {
            DFS(i, visited);
        }
    }
}

int main() {
    int v = 5, e = 4;
    adj = vector<vector<int> >(v, vector<int>(v, 0));
    vector<bool> visited(v, false);
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(0, 4);

    DFS(0, visited);
    cout << endl;
    return 0;
}