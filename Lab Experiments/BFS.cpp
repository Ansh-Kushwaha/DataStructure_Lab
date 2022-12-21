#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adj;

void addEdge(int x, int y) {
    adj[x][y] = 1;
    adj[y][x] = 1;
}

void bfs(int start) {
    vector<bool> visited(adj.size(), false);
    vector<int> q;
    q.push_back(start);
    visited[start] = true;
    int vis;
    while(!q.empty()) {
        vis = q[0];
        cout << vis << " ";
        q.erase(q.begin());
        for(int i=0; i<adj[vis].size(); i++) {
            if(adj[vis][i]==1 && !visited[i]) {
                q.push_back(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    adj = vector<vector<int> >(7, vector<int>(7, 0));
    addEdge(0, 1);
    addEdge(0, 3);
    addEdge(1, 3);
    addEdge(1, 2);
    addEdge(1, 6);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 4);
    addEdge(2, 5);
    addEdge(3, 4);
    addEdge(4, 6);
    cout << "BFS of of the graph : ";
    bfs(0);
    cout << endl;

    return 0;
}