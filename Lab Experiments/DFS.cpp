#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int> > adj;

void addEdge(int x, int y) {
	adj[x][y] = 1;
	adj[y][x] = 1;
}

void DFS(int start, vector<bool>&visited) {
	//set current node as visited
	// for(int i=0; i<adj[start].size(); i++) {
	// 	//If some node is adjacent to current node & is unvisited
	// 	if(adj[start][i] == 1 && !visited[i]) {
	// 		DFS(i, visited);
	// 	}
	// }
	stack<int> st;
	st.push(start);
	while(!st.empty()) {
		int vis = st.top();
		st.pop();
		if(!visited[vis]) {	
			cout << vis << " ";
			visited[vis] = true;
		}
		
		for(int i = 0; i < adj[vis].size(); i++)
			if(adj[vis][i] == 1 && !visited[i])
				st.push(i);
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

	cout << "DFS of the graph : ";
	DFS(0, visited);
	cout << endl;
	return 0;
}